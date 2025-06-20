import os

includeArr = []
codeArr = []
number = 0

try:
    f = open("coderesult.c", "w")
except IOError:
    exit(0)
for filename in os.listdir("."):
    if filename.lower().endswith(".png"):
        name = os.path.splitext(filename)[0]
        includeArr.append("#include <" + name +".h>\n")
        codeArr.append('loadTexture('+ str(number) +', "'+name+'", '+ name +'Bitmap, 128, 128, '+name+'Pal);\n');
        number += 1

f.write("".join(includeArr)+"\n\n"+"".join(codeArr))
f.close()
print("END!")
