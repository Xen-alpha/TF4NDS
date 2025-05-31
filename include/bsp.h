#define BSP_HEADER_ID "IBSP"
#define BSP_VERSION 29

typedef struct {
    int offset;
    int length;
} Lump;

typedef struct {
    char magic[4];
    int version;
    Lump lumps[15];  // 15개 영역: vertices, faces, textures 등
} BSPHeader;

int loadBSP(const char* path);