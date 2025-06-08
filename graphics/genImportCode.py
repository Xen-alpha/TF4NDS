import os

includeArr = []
codeArr = []

try:
    f = open("coderesult.c", "w")
except IOError:
    exit(0)
for filename in os.listdir("."):
    if filename.lower().endswith(".png"):
        name = os.path.splitext(filename)[0]
        includeArr.append("#include <" + name +".h>\n")
        codeArr.append('loadTexture("'+name+'", '+ name +'Bitmap, 24, 24);\n');

f.write("".join(includeArr)+"\n\n"+"".join(codeArr))
f.close()
