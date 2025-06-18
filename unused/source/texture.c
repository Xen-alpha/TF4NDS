
#include <texture.h>
#include <nds.h>
#include <fat.h>
#include <filesystem.h>
#include <utils.h>

LinkedTrie *textureIDList = NULL;
int textureIDs[MAX_TEX_DATA];
u8* paletteData;

void initTexture() {
    glGenTextures(MAX_TEX_DATA, textureIDs);
    // 공통 맵 팔레트 로드
    char filePath[40] = {0};
    snprintf(filePath, sizeof(filePath), "quake.pal.bin");
    FILE *file = fopen(filePath, "rb");
    if (!file) {
      printf("Failed to open pallete file");
      return;
    }
    fseek(file, 0, SEEK_END);
    size_t fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    paletteData = (u8 *)malloc(fileSize);
    if (!paletteData) {
      printf("Out of memory for palette data");
      fclose(file);
      return;
    }
    fread(paletteData, 1, fileSize, file);

    glColorTableEXT(0, 0, 256, 0, 0, paletteData);
    fclose(file);

    // trie 초기화
    textureIDList = (LinkedTrie *) malloc(sizeof(LinkedTrie));
    textureIDList->next = NULL;
    textureIDList->index = ' ';
    textureIDList->value = -1; // -1 indicates not found
    textureIDList->children = NULL;
    
}

// Note that this function does not check if the texture already exists.
// use getTextureId() to check if the texture is already loaded.
int loadTexture(int texId, const char* name, int texSizeX, int texSizeY) {
  // read texture data from file
  char filePath[32] = {0};
  snprintf(filePath, 32, "%s.img.bin", name);
  FILE *file = fopen(filePath, "rb");
  if (!file) {
    printf("Failed to open texture file: %s\n", name);
    return -1;
  }
  fseek(file, 0, SEEK_END);
  size_t fileSize = ftell(file);
  fseek(file, 0, SEEK_SET);
  u8 *data = (u8 *)malloc(fileSize);
  if (!data) {
    printf("Out of memory for texture data: %s\n", name);
    fclose(file);
    return -1;
  }
  fread(data, 1, fileSize, file);
  
  glBindTexture(0, textureIDs[texId]);
  glTexImage2D(0, 0, GL_RGB256, texSizeX, texSizeY, 0,
                0, (u8*)data);
  insertGLID(textureIDList, name, texId);
  free(data);
  fclose(file);
  return texId;
}

int getTextureId(const char * name) {
  return findGLID(textureIDList, name);
}

int deleteTextureId(const char * name) {
  int glID = findGLID(textureIDList, name);
  if (glID < 0) return -1; // not found
  glBindTexture(0, textureIDs[glID]);
  deleteGLID(textureIDList, name);
  glDeleteTextures(1, &textureIDs[glID]);
  return 0;
}

void clearAllMapTextures() {
  glDeleteTextures(MAX_TEX_DATA, textureIDs);
  for (int i = 0; i < MAX_TEX_DATA; i++) {
    textureIDs[i] = -1;
  }
}

void loadUITexture() {
  /*
    load2DTexture(0,"ANUM_0", ANUM_0Bitmap, 24, 24, ANUM_0Pal);
    load2DTexture(1,"ANUM_1", ANUM_1Bitmap, 24, 24, ANUM_1Pal);
    load2DTexture(2,"ANUM_2", ANUM_2Bitmap, 24, 24, ANUM_2Pal);
    load2DTexture(3,"ANUM_3", ANUM_3Bitmap, 24, 24, ANUM_3Pal);
    load2DTexture(4,"ANUM_4", ANUM_4Bitmap, 24, 24, ANUM_4Pal);
    load2DTexture(5,"ANUM_5", ANUM_5Bitmap, 24, 24, ANUM_5Pal);
    load2DTexture(6,"ANUM_6", ANUM_6Bitmap, 24, 24, ANUM_6Pal);
    load2DTexture(7,"ANUM_7", ANUM_7Bitmap, 24, 24, ANUM_7Pal);
    load2DTexture(8,"ANUM_8", ANUM_8Bitmap, 24, 24, ANUM_8Pal);
    load2DTexture(9,"ANUM_9", ANUM_9Bitmap, 24, 24, ANUM_9Pal);
    load2DTexture(10,"ANUM_COLON", ANUM_COLONBitmap, 24, 24, ANUM_COLONPal);
    load2DTexture(11,"ANUM_MINUS", ANUM_MINUSBitmap, 24, 24, ANUM_MINUSPal);
    load2DTexture(12,"ANUM_SLASH", ANUM_SLASHBitmap, 24, 24, ANUM_SLASHPal);
    load2DTexture(13, "BACKTILE", BACKTILEBitmap, 64, 64, BACKTILEPal);
    load2DTexture(14,"bigbox", bigboxBitmap, 72, 72, bigboxPal);
    load2DTexture(15,"box_bl", box_blBitmap, 8, 8, box_blPal);
    load2DTexture(16,"box_bm", box_bmBitmap, 16, 8, box_bmPal);
    load2DTexture(17,"box_br", box_brBitmap, 8, 8, box_brPal);
    load2DTexture(18,"box_ml", box_mlBitmap, 8, 8, box_mlPal);
    load2DTexture(19,"box_mm", box_mmBitmap, 16, 8, box_mmPal);
    load2DTexture(20,"box_mm2", box_mm2Bitmap, 16, 8, box_mm2Pal);
    load2DTexture(21,"box_mr", box_mrBitmap, 8, 8, box_blPal);
    load2DTexture(22,"box_tl", box_tlBitmap, 8, 8, box_tlPal);
    load2DTexture(23,"box_tm", box_tmBitmap, 16, 8, box_tmPal);
    load2DTexture(24,"box_tr", box_trBitmap, 8, 8, box_trPal);
    // load2DTexture(,"colormap", colormapBitmap, 64, 64);
    load2DTexture(26,"complete", completeBitmap, 142, 28, completePal);
    load2DTexture(27,"DISC", DISCBitmap, 24, 24, DISCPal);
    load2DTexture(28,"FACE1", FACE1Bitmap, 24, 24, FACE1Pal);
    load2DTexture(29,"FACE2", FACE2Bitmap, 24, 24, FACE2Pal);
    load2DTexture(30,"FACE3", FACE3Bitmap, 24, 24, FACE3Pal);
    load2DTexture(31,"FACE4", FACE4Bitmap, 24, 24, FACE4Pal);
    load2DTexture(32,"FACE5", FACE5Bitmap, 24, 24, FACE5Pal);
    load2DTexture(33,"FACE_INV2", FACE_INV2Bitmap, 24, 24, FACE_INV2Pal);
    load2DTexture(34,"FACE_INVIS", FACE_INVISBitmap, 24, 24, FACE_INVISPal);
    load2DTexture(35,"FACE_INVUL1", FACE_INVUL1Bitmap, 24, 24, FACE_INVUL1Pal);
    load2DTexture(36,"FACE_INVUL2", FACE_INVUL2Bitmap, 24, 24, FACE_INVUL2Pal);
    load2DTexture(37,"FACE_P1", FACE_P1Bitmap, 24, 24, FACE_P1Pal);
    load2DTexture(38,"FACE_P2", FACE_P2Bitmap, 24, 24, FACE_P2Pal);
    load2DTexture(39,"FACE_P3", FACE_P3Bitmap, 24, 24, FACE_P3Pal);
    load2DTexture(40,"FACE_P4", FACE_P4Bitmap, 24, 24, FACE_P4Pal);
    load2DTexture(41,"FACE_P5", FACE_P5Bitmap, 24, 24, FACE_P5Pal);
    load2DTexture(42,"FACE_QUAD", FACE_QUADBitmap, 24, 24, FACE_QUADPal);
    load2DTexture(43,"finale", finaleBitmap, 112, 28, finalePal);
    load2DTexture(44,"help0", help0Bitmap, 320, 200, help0Pal);
    load2DTexture(45,"help1", help1Bitmap, 320, 200, help1Pal);
    load2DTexture(46,"help2", help2Bitmap, 320, 200, help2Pal);
    load2DTexture(47,"help3", help3Bitmap, 320, 200, help3Pal);
    load2DTexture(48,"help4", help4Bitmap, 320, 200, help4Pal);
    load2DTexture(49,"help5", help5Bitmap, 320, 200, help5Pal);
    load2DTexture(50,"IBAR", IBARBitmap, 320, 24, IBARPal);
    load2DTexture(51,"inter", interBitmap, 160, 144, interPal);
    load2DTexture(52,"INV2_LIGHTNG", INV2_LIGHTNGBitmap, 48, 16, INV2_LIGHTNGPal);
    load2DTexture(53,"INV2_NAILGUN", INV2_NAILGUNBitmap, 24, 16, INV2_NAILGUNPal);
    load2DTexture(54,"INV2_RLAUNCH", INV2_RLAUNCHBitmap, 24, 16, INV2_RLAUNCHPal);
    load2DTexture(55,"INV2_SHOTGUN", INV2_SHOTGUNBitmap, 24, 16, INV2_SHOTGUNPal);
    load2DTexture(56,"INV2_SNAILGUN", INV2_SNAILGUNBitmap, 24, 16, INV2_SNAILGUNPal);
    load2DTexture(57,"INV2_SRLAUNCH", INV2_SRLAUNCHBitmap, 24, 16, INV2_SRLAUNCHPal);
    load2DTexture(58,"INV2_SSHOTGUN", INV2_SSHOTGUNBitmap, 24, 16, INV2_SSHOTGUNPal);
    load2DTexture(59,"INVA1_LIGHTNG", INVA1_LIGHTNGBitmap, 48, 16, INVA1_LIGHTNGPal);
    load2DTexture(60,"INVA1_NAILGUN", INVA1_NAILGUNBitmap, 24, 16, INVA1_NAILGUNPal);
    load2DTexture(61,"INVA1_RLAUNCH", INVA1_RLAUNCHBitmap, 24, 16, INVA1_RLAUNCHPal);
    load2DTexture(62,"INVA1_SHOTGUN", INVA1_SHOTGUNBitmap, 24, 16, INVA1_SHOTGUNPal);
    load2DTexture(63,"INVA1_SNAILGUN", INVA1_SNAILGUNBitmap, 24, 16, INVA1_SNAILGUNPal);
    load2DTexture(64,"INVA1_SRLAUNCH", INVA1_SRLAUNCHBitmap, 24, 16, INVA1_SRLAUNCHPal);
    load2DTexture(65,"INVA1_SSHOTGUN", INVA1_SSHOTGUNBitmap, 24, 16, INVA1_SSHOTGUNPal);
    load2DTexture(66,"INVA2_LIGHTNG", INVA2_LIGHTNGBitmap, 48, 16, INVA2_LIGHTNGPal);
    load2DTexture(67,"INVA2_NAILGUN", INVA2_NAILGUNBitmap, 24, 16, INVA2_NAILGUNPal);
    load2DTexture(68,"INVA2_RLAUNCH", INVA2_RLAUNCHBitmap, 24, 16, INVA2_RLAUNCHPal);
    load2DTexture(69,"INVA2_SHOTGUN", INVA2_SHOTGUNBitmap, 24, 16, INVA2_SHOTGUNPal);
    load2DTexture(70,"INVA2_SNAILGUN", INVA2_SNAILGUNBitmap, 24, 16, INVA2_SNAILGUNPal);
    load2DTexture(71,"INVA2_SRLAUNCH", INVA2_SRLAUNCHBitmap, 24, 16, INVA2_SRLAUNCHPal);
    load2DTexture(72,"INVA2_SSHOTGUN", INVA2_SSHOTGUNBitmap, 24, 16, INVA2_SSHOTGUNPal);
    load2DTexture(73,"INVA3_LIGHTNG", INVA3_LIGHTNGBitmap, 48, 16, INVA3_LIGHTNGPal);
    load2DTexture(74,"INVA3_NAILGUN", INVA3_NAILGUNBitmap, 24, 16, INVA3_NAILGUNPal);
    load2DTexture(75,"INVA3_RLAUNCH", INVA3_RLAUNCHBitmap, 24, 16, INVA3_RLAUNCHPal);
    load2DTexture(76,"INVA3_SHOTGUN", INVA3_SHOTGUNBitmap, 24, 16, INVA3_SHOTGUNPal);
    load2DTexture(77,"INVA3_SNAILGUN", INVA3_SNAILGUNBitmap, 24, 16, INVA3_SNAILGUNPal);
    load2DTexture(78,"INVA3_SRLAUNCH", INVA3_SRLAUNCHBitmap, 24, 16, INVA3_SRLAUNCHPal);
    load2DTexture(79,"INVA3_SSHOTGUN", INVA3_SSHOTGUNBitmap, 24, 16, INVA3_SSHOTGUNPal);
    load2DTexture(80,"INVA4_LIGHTNG", INVA4_LIGHTNGBitmap, 48, 16, INVA4_LIGHTNGPal);
    load2DTexture(81,"INVA4_NAILGUN", INVA4_NAILGUNBitmap, 24, 16, INVA4_NAILGUNPal);
    load2DTexture(82,"INVA4_RLAUNCH", INVA4_RLAUNCHBitmap, 48, 16, INVA4_RLAUNCHPal);
    load2DTexture(83,"INVA4_SHOTGUN", INVA4_SHOTGUNBitmap, 24, 16, INVA4_SHOTGUNPal);
    load2DTexture(84,"INVA4_SNAILGUN", INVA4_SNAILGUNBitmap, 48, 16, INVA4_SNAILGUNPal);
    load2DTexture(85,"INVA4_SRLAUNCH", INVA4_SRLAUNCHBitmap, 24, 16, INVA4_SRLAUNCHPal);
    load2DTexture(86,"INVA4_SSHOTGUN", INVA4_SSHOTGUNBitmap, 24, 16, INVA4_SSHOTGUNPal);
    load2DTexture(87,"INVA5_LIGHTNG", INVA5_LIGHTNGBitmap, 48, 16, INVA5_LIGHTNGPal);
    load2DTexture(88,"INVA5_NAILGUN", INVA5_NAILGUNBitmap, 24, 16, INVA5_NAILGUNPal);
    load2DTexture(89,"INVA5_RLAUNCH", INVA5_RLAUNCHBitmap, 24, 16, INVA5_RLAUNCHPal);
    load2DTexture(90,"INVA5_SHOTGUN", INVA5_SHOTGUNBitmap, 24, 16, INVA5_SHOTGUNPal);
    load2DTexture(91,"INVA5_SNAILGUN", INVA5_SNAILGUNBitmap, 24, 16, INVA5_SNAILGUNPal);
    load2DTexture(92,"INVA5_SRLAUNCH", INVA5_SRLAUNCHBitmap, 24, 16, INVA5_SRLAUNCHPal);
    load2DTexture(93,"INVA5_SSHOTGUN", INVA5_SSHOTGUNBitmap, 24, 16, INVA5_SSHOTGUNPal);
    load2DTexture(94,"INV_LIGHTNG", INV_LIGHTNGBitmap, 48, 16, INV_LIGHTNGPal);
    load2DTexture(95,"INV_NAILGUN", INV_NAILGUNBitmap, 24, 16, INV_NAILGUNPal);
    load2DTexture(96,"INV_RLAUNCH", INV_RLAUNCHBitmap, 24, 16, INV_RLAUNCHPal);
    load2DTexture(97,"INV_SHOTGUN", INV_SHOTGUNBitmap, 24, 16, INV_SHOTGUNPal);
    load2DTexture(98,"INV_SNAILGUN", INV_SNAILGUNBitmap, 24, 16, INV_SNAILGUNPal);
    load2DTexture(99,"INV_SRLAUNCH", INV_SRLAUNCHBitmap, 24, 16, INV_SRLAUNCHPal);
    load2DTexture(100,"INV_SSHOTGUN", INV_SSHOTGUNBitmap, 24, 16, INV_SSHOTGUNPal);
    load2DTexture(101,"loading", loadingBitmap, 114, 28, loadingPal);
    load2DTexture(102,"mainmenu", mainmenuBitmap, 240, 112, mainmenuPal);
    load2DTexture(103,"menudot1", menudot1Bitmap, 256, 32, menudot1Pal);
    load2DTexture(104,"menudot2", menudot2Bitmap, 256, 32, menudot2Pal);
    load2DTexture(105,"menudot3", menudot3Bitmap, 256, 32, menudot3Pal);
    load2DTexture(106,"menudot4", menudot4Bitmap, 256, 32, menudot4Pal);
    load2DTexture(107,"menudot5", menudot5Bitmap, 256, 32, menudot5Pal);
    load2DTexture(108,"menudot6", menudot6Bitmap, 256, 32, menudot6Pal);
    load2DTexture(109,"menuplyr", menuplyrBitmap, 48, 56, menuplyrPal);
    load2DTexture(110,"NET", NETBitmap, 32, 32, NETPal);
    load2DTexture(111,"NUM_0", NUM_0Bitmap, 24, 24, NUM_0Pal);
    load2DTexture(112,"NUM_1", NUM_1Bitmap, 24, 24, NUM_1Pal);
    load2DTexture(113,"NUM_2", NUM_2Bitmap, 24, 24, NUM_2Pal);
    load2DTexture(114,"NUM_3", NUM_3Bitmap, 24, 24, NUM_3Pal);
    load2DTexture(115,"NUM_4", NUM_4Bitmap, 24, 24, NUM_4Pal);
    load2DTexture(116,"NUM_5", NUM_5Bitmap, 24, 24, NUM_5Pal);
    load2DTexture(117,"NUM_6", NUM_6Bitmap, 24, 24, NUM_6Pal);
    load2DTexture(118,"NUM_7", NUM_7Bitmap, 24, 24, NUM_7Pal);
    load2DTexture(119,"NUM_8", NUM_8Bitmap, 24, 24, NUM_8Pal);
    load2DTexture(120,"NUM_9", NUM_9Bitmap, 24, 24, NUM_9Pal);
    load2DTexture(121,"NUM_COLON", NUM_COLONBitmap, 24, 24, NUM_COLONPal);
    load2DTexture(122,"NUM_MINUS", NUM_MINUSBitmap, 24, 24, NUM_MINUSPal);
    load2DTexture(123,"NUM_SLASH", NUM_SLASHBitmap, 24, 24, NUM_SLASHPal);
    load2DTexture(124,"pause", pauseBitmap, 86, 28, pausePal);
    load2DTexture(125,"p_option", p_optionBitmap, 114, 28, p_optionPal);
    load2DTexture(126,"qplaque", qplaqueBitmap, 32, 64, qplaquePal);
    load2DTexture(127,"RAM", RAMBitmap, 86, 28, RAMPal);
    load2DTexture(64,"ranking", rankingBitmap, 86, 28, rankingPal); // checkpoint
    load2DTexture(129,"SBA1_INVIS", SBA1_INVISBitmap, 16, 16, SBA1_INVISPal);
    load2DTexture(130,"SBA1_INVUL", SBA1_INVULBitmap, 16, 16, SBA1_INVULPal);
    load2DTexture(131,"SBA1_KEY1", SBA1_KEY1Bitmap, 16, 16, SBA1_KEY1Pal);
    load2DTexture(132,"SBA1_KEY2", SBA1_KEY2Bitmap, 16, 16, SBA1_KEY2Pal);
    load2DTexture(133,"SBA1_QUAD", SBA1_QUADBitmap, 16, 16, SBA1_QUADPal);
    load2DTexture(134,"SBA1_SUIT", SBA1_SUITBitmap, 16, 16, SBA1_SUITPal);
    load2DTexture(135,"SBA2_INVIS", SBA2_INVISBitmap, 16, 16, SBA2_INVISPal);
    load2DTexture(136,"SBA2_INVUL", SBA2_INVULBitmap, 16, 16, SBA2_INVULPal);
    load2DTexture(137,"SBA2_KEY1", SBA2_KEY1Bitmap, 16, 16, SBA2_KEY1Pal);
    load2DTexture(138,"SBA2_KEY2", SBA2_KEY2Bitmap, 16, 16, SBA2_KEY2Pal);
    load2DTexture(139,"SBA2_QUAD", SBA2_QUADBitmap, 16, 16, SBA2_QUADPal);
    load2DTexture(140,"SBA2_SUIT", SBA2_SUITBitmap, 16, 16, SBA2_SUITPal);
    load2DTexture(141,"SBA3_INVIS", SBA3_INVISBitmap, 16, 16, SBA3_INVISPal);
    load2DTexture(142,"SBA3_INVUL", SBA3_INVULBitmap, 16, 16, SBA3_INVULPal);
    load2DTexture(143,"SBA3_KEY1", SBA3_KEY1Bitmap, 16, 16, SBA3_KEY1Pal);
    load2DTexture(144,"SBA3_KEY2", SBA3_KEY2Bitmap, 16, 16, SBA3_KEY2Pal);
    load2DTexture(145,"SBA3_QUAD", SBA3_QUADBitmap, 16, 16, SBA3_QUADPal);
    load2DTexture(146,"SBA3_SUIT", SBA3_SUITBitmap, 16, 16, SBA3_SUITPal);
    load2DTexture(147,"SBA4_INVIS", SBA4_INVISBitmap, 16, 16, SBA4_INVISPal);
    load2DTexture(148,"SBA4_INVUL", SBA4_INVULBitmap, 16, 16, SBA4_INVULPal);
    load2DTexture(149,"SBA4_KEY1", SBA4_KEY1Bitmap, 16, 16, SBA4_KEY1Pal);
    load2DTexture(150,"SBA4_KEY2", SBA4_KEY2Bitmap, 16, 16, SBA4_KEY2Pal);
    load2DTexture(151,"SBA4_QUAD", SBA4_QUADBitmap, 16, 16, SBA4_QUADPal);
    load2DTexture(152,"SBA4_SUIT", SBA4_SUITBitmap, 16, 16, SBA4_SUITPal);
    load2DTexture(153,"SBA5_INVIS", SBA5_INVISBitmap, 16, 16, SBA5_INVISPal);
    load2DTexture(154,"SBA5_INVUL", SBA5_INVULBitmap, 16, 16, SBA5_INVULPal);
    load2DTexture(155,"SBA5_KEY1", SBA5_KEY1Bitmap, 16, 16, SBA5_KEY1Pal);
    load2DTexture(156,"SBA5_KEY2", SBA5_KEY2Bitmap, 16, 16, SBA5_KEY2Pal);
    load2DTexture(157,"SBA5_QUAD", SBA5_QUADBitmap, 16, 16, SBA5_QUADPal);
    load2DTexture(158,"SBA5_SUIT", SBA5_SUITBitmap, 16, 16, SBA5_SUITPal);
    load2DTexture(159,"SBAR", SBARBitmap, 320, 24, SBARPal);
    load2DTexture(160,"SB_AMMOBASE", SB_AMMOBASEBitmap, 24, 24, SB_AMMOBASEPal);
    load2DTexture(161,"SB_ARMOR1", SB_ARMOR1Bitmap, 24, 24, SB_ARMOR1Pal);
    load2DTexture(162,"SB_ARMOR2", SB_ARMOR2Bitmap, 24, 24, SB_ARMOR2Pal);
    load2DTexture(163,"SB_ARMOR3", SB_ARMOR3Bitmap, 24, 24, SB_ARMOR3Pal);
    load2DTexture(164,"SB_ARMORBASE", SB_ARMORBASEBitmap, 24, 24, SB_ARMORBASEPal);
    load2DTexture(165,"SB_CELLS", SB_CELLSBitmap, 24, 24, SB_CELLSPal);
    load2DTexture(166,"SB_INVIS", SB_INVISBitmap, 16, 16, SB_INVISPal);
    load2DTexture(167,"SB_INVULN", SB_INVULNBitmap, 16, 16, SB_INVULNPal);
    load2DTexture(168,"SB_KEY1", SB_KEY1Bitmap, 16, 16, SB_KEY1Pal);
    load2DTexture(169,"SB_KEY2", SB_KEY2Bitmap, 16, 16, SB_KEY2Pal);
    load2DTexture(170,"SB_NAILS", SB_NAILSBitmap, 24, 24, SB_NAILSPal);
    load2DTexture(171,"SB_QUAD", SB_QUADBitmap, 16, 16, SB_QUADPal);
    load2DTexture(172,"SB_ROCKET", SB_ROCKETBitmap, 24, 24, SB_ROCKETPal);
    load2DTexture(173,"SB_SHELLS", SB_SHELLSBitmap, 24, 24, SB_SHELLSPal);
    load2DTexture(174,"SB_SIGIL1", SB_SIGIL1Bitmap, 8, 16, SB_SIGIL1Pal);
    load2DTexture(175,"SB_SIGIL2", SB_SIGIL2Bitmap, 8, 16, SB_SIGIL2Pal);
    load2DTexture(176,"SB_SIGIL3", SB_SIGIL3Bitmap, 8, 16, SB_SIGIL3Pal);
    load2DTexture(177,"SB_SIGIL4", SB_SIGIL4Bitmap, 8, 16, SB_SIGIL4Pal);
    load2DTexture(178,"SB_SUIT", SB_SUITBitmap, 16, 16, SB_SUITPal);
    load2DTexture(179,"SCOREBAR", SCOREBARBitmap, 320, 24, SCOREBARPal);
    load2DTexture(180,"sell", sellBitmap, 320, 200, sellPal);
    load2DTexture(181,"ttl_main", ttl_mainBitmap, 214, 24, ttl_mainPal);
    load2DTexture(182,"TURTLE", TURTLEBitmap, 32, 32, TURTLEPal);
    */
    // read pcx player textures
}