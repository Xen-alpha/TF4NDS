import os
import struct
from pathlib import Path
from PIL import Image
import subprocess

# 설정
WAD_FILE = "quake101.wad"
PALETTE_FILE = "quake.pal"
PNG_DIR = Path("output/png")
GRIT_DIR = Path("output/grit")

# 디렉토리 준비
PNG_DIR.mkdir(parents=True, exist_ok=True)
GRIT_DIR.mkdir(parents=True, exist_ok=True)

def load_palette(filename):
    with open(filename, "rb") as f:
        raw = f.read()
    assert len(raw) == 768
    return [(raw[i], raw[i+1], raw[i+2]) for i in range(0, 768, 3)]

def sanitize_name(name):
    # 파일 시스템에 안전한 이름으로 변경
    return name.replace("*", "_").replace("+", "plus_").replace("{", "trans_").replace("!", "bang_").replace("?", "q_")

def parse_wad(filename):
    with open(filename, "rb") as f:
        header = f.read(12)
        ident, num_lumps, info_offset = struct.unpack("<4sii", header)
        assert ident == b"WAD2", "Not a valid WAD2 file"

        f.seek(info_offset)
        lumps = []

        for _ in range(num_lumps):
            lump_data = f.read(32)
            offset, dsize, size, lump_type, comp, _zero, name = struct.unpack("<iiiiiib16s", lump_data[:32])
            name = name.split(b'\x00')[0].decode('ascii')
            lumps.append((name, offset, size))

        return lumps

def extract_lumps(filename, lumps, palette):
    with open(filename, "rb") as f:
        for name, offset, size in lumps:
            f.seek(offset)
            width = struct.unpack("<H", f.read(2))[0]
            height = struct.unpack("<H", f.read(2))[0]
            _ = f.read(4)  # skip origin
            pixel_offset = struct.unpack("<I", f.read(4))[0]
            f.seek(offset + pixel_offset)
            data = f.read(width * height)

            # RGBA 변환
            img = Image.new("RGBA", (width, height))
            for y in range(height):
                for x in range(width):
                    i = y * width + x
                    c = data[i]
                    if name.startswith("{") and c == 255:
                        img.putpixel((x, y), (0, 0, 0, 0))  # 투명
                    else:
                        img.putpixel((x, y), (*palette[c], 255))

            safe_name = sanitize_name(name)
            png_path = PNG_DIR / f"{safe_name}.png"
            img.save(png_path)
            print(f"[+] Saved: {png_path}")

            # GRIT 호출
            grit_path = GRIT_DIR / f"{safe_name}.c"
            subprocess.run([
                "grit", str(png_path),
                "-gB8", "-gT", "255", "-gS", "-ftc", "-o", str(grit_path)
            ])
            print(f"[+] GRIT: {grit_path}")

# 실행
if __name__ == "__main__":
    print("[*] Loading palette...")
    pal = load_palette(PALETTE_FILE)
    print("[*] Parsing WAD...")
    lumps = parse_wad(WAD_FILE)
    print(f"[*] Found {len(lumps)} lumps.")
    extract_lumps(WAD_FILE, lumps, pal)
