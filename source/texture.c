
#include <texture.h>
#include <nds.h>

// texture data
#include <BACKTILE.h>

#include <ANUM_0.h>
#include <ANUM_1.h>
#include <ANUM_2.h>
#include <ANUM_3.h>
#include <ANUM_4.h>
#include <ANUM_5.h>
#include <ANUM_6.h>
#include <ANUM_7.h>
#include <ANUM_8.h>
#include <ANUM_9.h>
#include <ANUM_COLON.h>
#include <ANUM_MINUS.h>
#include <ANUM_SLASH.h>

#include <bigbox.h>
#include <box_bl.h>
#include <box_bm.h>
#include <box_br.h>
#include <box_ml.h>
#include <box_mm.h>
#include <box_mm2.h>
#include <box_mr.h>
#include <box_tl.h>
#include <box_tm.h>
#include <box_tr.h>
#include <colormap.h>
#include <complete.h>
#include <DISC.h>
#include <FACE1.h>
#include <FACE2.h>
#include <FACE3.h>
#include <FACE4.h>
#include <FACE5.h>
#include <FACE_INV2.h>
#include <FACE_INVIS.h>
#include <FACE_INVUL1.h>
#include <FACE_INVUL2.h>
#include <FACE_P1.h>
#include <FACE_P2.h>
#include <FACE_P3.h>
#include <FACE_P4.h>
#include <FACE_P5.h>
#include <FACE_QUAD.h>
#include <finale.h>
#include <help0.h>
#include <help1.h>
#include <help2.h>
#include <help3.h>
#include <help4.h>
#include <help5.h>
#include <IBAR.h>
#include <inter.h>
#include <INV2_LIGHTNG.h>
#include <INV2_NAILGUN.h>
#include <INV2_RLAUNCH.h>
#include <INV2_SHOTGUN.h>
#include <INV2_SNAILGUN.h>
#include <INV2_SRLAUNCH.h>
#include <INV2_SSHOTGUN.h>
#include <INVA1_LIGHTNG.h>
#include <INVA1_NAILGUN.h>
#include <INVA1_RLAUNCH.h>
#include <INVA1_SHOTGUN.h>
#include <INVA1_SNAILGUN.h>
#include <INVA1_SRLAUNCH.h>
#include <INVA1_SSHOTGUN.h>
#include <INVA2_LIGHTNG.h>
#include <INVA2_NAILGUN.h>
#include <INVA2_RLAUNCH.h>
#include <INVA2_SHOTGUN.h>
#include <INVA2_SNAILGUN.h>
#include <INVA2_SRLAUNCH.h>
#include <INVA2_SSHOTGUN.h>
#include <INVA3_LIGHTNG.h>
#include <INVA3_NAILGUN.h>
#include <INVA3_RLAUNCH.h>
#include <INVA3_SHOTGUN.h>
#include <INVA3_SNAILGUN.h>
#include <INVA3_SRLAUNCH.h>
#include <INVA3_SSHOTGUN.h>
#include <INVA4_LIGHTNG.h>
#include <INVA4_NAILGUN.h>
#include <INVA4_RLAUNCH.h>
#include <INVA4_SHOTGUN.h>
#include <INVA4_SNAILGUN.h>
#include <INVA4_SRLAUNCH.h>
#include <INVA4_SSHOTGUN.h>
#include <INVA5_LIGHTNG.h>
#include <INVA5_NAILGUN.h>
#include <INVA5_RLAUNCH.h>
#include <INVA5_SHOTGUN.h>
#include <INVA5_SNAILGUN.h>
#include <INVA5_SRLAUNCH.h>
#include <INVA5_SSHOTGUN.h>
#include <INV_LIGHTNG.h>
#include <INV_NAILGUN.h>
#include <INV_RLAUNCH.h>
#include <INV_SHOTGUN.h>
#include <INV_SNAILGUN.h>
#include <INV_SRLAUNCH.h>
#include <INV_SSHOTGUN.h>
#include <loading.h>
#include <mainmenu.h>
#include <menudot1.h>
#include <menudot2.h>
#include <menudot3.h>
#include <menudot4.h>
#include <menudot5.h>
#include <menudot6.h>
#include <menuplyr.h>
#include <NET.h>
#include <NUM_0.h>
#include <NUM_1.h>
#include <NUM_2.h>
#include <NUM_3.h>
#include <NUM_4.h>
#include <NUM_5.h>
#include <NUM_6.h>
#include <NUM_7.h>
#include <NUM_8.h>
#include <NUM_9.h>
#include <NUM_COLON.h>
#include <NUM_MINUS.h>
#include <NUM_SLASH.h>
#include <pause.h>
#include <p_option.h>
#include <qplaque.h>
#include <RAM.h>
#include <ranking.h>
#include <SBA1_INVIS.h>
#include <SBA1_INVUL.h>
#include <SBA1_KEY1.h>
#include <SBA1_KEY2.h>
#include <SBA1_QUAD.h>
#include <SBA1_SUIT.h>
#include <SBA2_INVIS.h>
#include <SBA2_INVUL.h>
#include <SBA2_KEY1.h>
#include <SBA2_KEY2.h>
#include <SBA2_QUAD.h>
#include <SBA2_SUIT.h>
#include <SBA3_INVIS.h>
#include <SBA3_INVUL.h>
#include <SBA3_KEY1.h>
#include <SBA3_KEY2.h>
#include <SBA3_QUAD.h>
#include <SBA3_SUIT.h>
#include <SBA4_INVIS.h>
#include <SBA4_INVUL.h>
#include <SBA4_KEY1.h>
#include <SBA4_KEY2.h>
#include <SBA4_QUAD.h>
#include <SBA4_SUIT.h>
#include <SBA5_INVIS.h>
#include <SBA5_INVUL.h>
#include <SBA5_KEY1.h>
#include <SBA5_KEY2.h>
#include <SBA5_QUAD.h>
#include <SBA5_SUIT.h>
#include <SBAR.h>
#include <SB_AMMOBASE.h>
#include <SB_ARMOR1.h>
#include <SB_ARMOR2.h>
#include <SB_ARMOR3.h>
#include <SB_ARMORBASE.h>
#include <SB_CELLS.h>
#include <SB_INVIS.h>
#include <SB_INVULN.h>
#include <SB_KEY1.h>
#include <SB_KEY2.h>
#include <SB_NAILS.h>
#include <SB_QUAD.h>
#include <SB_ROCKET.h>
#include <SB_SHELLS.h>
#include <SB_SIGIL1.h>
#include <SB_SIGIL2.h>
#include <SB_SIGIL3.h>
#include <SB_SIGIL4.h>
#include <SB_SUIT.h>
#include <SCOREBAR.h>
#include <sell.h>
#include <ttl_main.h>
#include <TURTLE.h>

#define MAX_TEXTURES 256
int textureID[MAX_TEXTURES];
int textureNameTable[MAX_TEXTURES][16];

void initTexture() {
    glGenTextures(256, textureID);
    
    
    loadTexture(0,"ANUM_0", ANUM_0Bitmap, 24, 24, ANUM_0Pal);
    loadTexture(1,"ANUM_1", ANUM_1Bitmap, 24, 24, ANUM_1Pal);
    loadTexture(2,"ANUM_2", ANUM_2Bitmap, 24, 24, ANUM_2Pal);
    loadTexture(3,"ANUM_3", ANUM_3Bitmap, 24, 24, ANUM_3Pal);
    loadTexture(4,"ANUM_4", ANUM_4Bitmap, 24, 24, ANUM_4Pal);
    loadTexture(5,"ANUM_5", ANUM_5Bitmap, 24, 24, ANUM_5Pal);
    loadTexture(6,"ANUM_6", ANUM_6Bitmap, 24, 24, ANUM_6Pal);
    loadTexture(7,"ANUM_7", ANUM_7Bitmap, 24, 24, ANUM_7Pal);
    loadTexture(8,"ANUM_8", ANUM_8Bitmap, 24, 24, ANUM_8Pal);
    loadTexture(9,"ANUM_9", ANUM_9Bitmap, 24, 24, ANUM_9Pal);
    loadTexture(10,"ANUM_COLON", ANUM_COLONBitmap, 24, 24, ANUM_COLONPal);
    loadTexture(11,"ANUM_MINUS", ANUM_MINUSBitmap, 24, 24, ANUM_MINUSPal);
    loadTexture(12,"ANUM_SLASH", ANUM_SLASHBitmap, 24, 24, ANUM_SLASHPal);
    loadTexture(13, "BACKTILE", BACKTILEBitmap, 128, 128, BACKTILEPal);
    loadTexture(14,"bigbox", bigboxBitmap, 72, 72, bigboxPal);
    loadTexture(15,"box_bl", box_blBitmap, 8, 8, box_blPal);
    loadTexture(16,"box_bm", box_bmBitmap, 16, 8, box_bmPal);
    loadTexture(17,"box_br", box_brBitmap, 8, 8, box_brPal);
    loadTexture(18,"box_ml", box_mlBitmap, 8, 8, box_mlPal);
    loadTexture(19,"box_mm", box_mmBitmap, 16, 8, box_mmPal);
    loadTexture(20,"box_mm2", box_mm2Bitmap, 16, 8, box_mm2Pal);
    loadTexture(21,"box_mr", box_mrBitmap, 8, 8, box_blPal);
    loadTexture(22,"box_tl", box_tlBitmap, 8, 8, box_tlPal);
    loadTexture(23,"box_tm", box_tmBitmap, 16, 8, box_tmPal);
    loadTexture(24,"box_tr", box_trBitmap, 8, 8, box_trPal);
    // loadTexture(,"colormap", colormapBitmap, 128, 128);
    loadTexture(26,"complete", completeBitmap, 142, 28, completePal);
    loadTexture(27,"DISC", DISCBitmap, 24, 24, DISCPal);
    loadTexture(28,"FACE1", FACE1Bitmap, 24, 24, FACE1Pal);
    loadTexture(29,"FACE2", FACE2Bitmap, 24, 24, FACE2Pal);
    loadTexture(30,"FACE3", FACE3Bitmap, 24, 24, FACE3Pal);
    loadTexture(31,"FACE4", FACE4Bitmap, 24, 24, FACE4Pal);
    loadTexture(32,"FACE5", FACE5Bitmap, 24, 24, FACE5Pal);
    loadTexture(33,"FACE_INV2", FACE_INV2Bitmap, 24, 24, FACE_INV2Pal);
    loadTexture(34,"FACE_INVIS", FACE_INVISBitmap, 24, 24, FACE_INVISPal);
    loadTexture(35,"FACE_INVUL1", FACE_INVUL1Bitmap, 24, 24, FACE_INVUL1Pal);
    loadTexture(36,"FACE_INVUL2", FACE_INVUL2Bitmap, 24, 24, FACE_INVUL2Pal);
    loadTexture(37,"FACE_P1", FACE_P1Bitmap, 24, 24, FACE_P1Pal);
    loadTexture(38,"FACE_P2", FACE_P2Bitmap, 24, 24, FACE_P2Pal);
    loadTexture(39,"FACE_P3", FACE_P3Bitmap, 24, 24, FACE_P3Pal);
    loadTexture(40,"FACE_P4", FACE_P4Bitmap, 24, 24, FACE_P4Pal);
    loadTexture(41,"FACE_P5", FACE_P5Bitmap, 24, 24, FACE_P5Pal);
    loadTexture(42,"FACE_QUAD", FACE_QUADBitmap, 24, 24, FACE_QUADPal);
    loadTexture(43,"finale", finaleBitmap, 112, 28, finalePal);
    loadTexture(44,"help0", help0Bitmap, 320, 200, help0Pal);
    loadTexture(45,"help1", help1Bitmap, 320, 200, help1Pal);
    loadTexture(46,"help2", help2Bitmap, 320, 200, help2Pal);
    loadTexture(47,"help3", help3Bitmap, 320, 200, help3Pal);
    loadTexture(48,"help4", help4Bitmap, 320, 200, help4Pal);
    loadTexture(49,"help5", help5Bitmap, 320, 200, help5Pal);
    loadTexture(50,"IBAR", IBARBitmap, 320, 24, IBARPal);
    loadTexture(51,"inter", interBitmap, 160, 144, interPal);
    loadTexture(52,"INV2_LIGHTNG", INV2_LIGHTNGBitmap, 48, 16, INV2_LIGHTNGPal);
    loadTexture(53,"INV2_NAILGUN", INV2_NAILGUNBitmap, 24, 16, INV2_NAILGUNPal);
    loadTexture(54,"INV2_RLAUNCH", INV2_RLAUNCHBitmap, 24, 16, INV2_RLAUNCHPal);
    loadTexture(55,"INV2_SHOTGUN", INV2_SHOTGUNBitmap, 24, 16, INV2_SHOTGUNPal);
    loadTexture(56,"INV2_SNAILGUN", INV2_SNAILGUNBitmap, 24, 16, INV2_SNAILGUNPal);
    loadTexture(57,"INV2_SRLAUNCH", INV2_SRLAUNCHBitmap, 24, 16, INV2_SRLAUNCHPal);
    loadTexture(58,"INV2_SSHOTGUN", INV2_SSHOTGUNBitmap, 24, 16, INV2_SSHOTGUNPal);
    loadTexture(59,"INVA1_LIGHTNG", INVA1_LIGHTNGBitmap, 48, 16, INVA1_LIGHTNGPal);
    loadTexture(60,"INVA1_NAILGUN", INVA1_NAILGUNBitmap, 24, 16, INVA1_NAILGUNPal);
    loadTexture(61,"INVA1_RLAUNCH", INVA1_RLAUNCHBitmap, 24, 16, INVA1_RLAUNCHPal);
    loadTexture(62,"INVA1_SHOTGUN", INVA1_SHOTGUNBitmap, 24, 16, INVA1_SHOTGUNPal);
    loadTexture(63,"INVA1_SNAILGUN", INVA1_SNAILGUNBitmap, 24, 16, INVA1_SNAILGUNPal);
    loadTexture(64,"INVA1_SRLAUNCH", INVA1_SRLAUNCHBitmap, 24, 16, INVA1_SRLAUNCHPal);
    loadTexture(65,"INVA1_SSHOTGUN", INVA1_SSHOTGUNBitmap, 24, 16, INVA1_SSHOTGUNPal);
    loadTexture(66,"INVA2_LIGHTNG", INVA2_LIGHTNGBitmap, 48, 16, INVA2_LIGHTNGPal);
    loadTexture(67,"INVA2_NAILGUN", INVA2_NAILGUNBitmap, 24, 16, INVA2_NAILGUNPal);
    loadTexture(68,"INVA2_RLAUNCH", INVA2_RLAUNCHBitmap, 24, 16, INVA2_RLAUNCHPal);
    loadTexture(69,"INVA2_SHOTGUN", INVA2_SHOTGUNBitmap, 24, 16, INVA2_SHOTGUNPal);
    loadTexture(70,"INVA2_SNAILGUN", INVA2_SNAILGUNBitmap, 24, 16, INVA2_SNAILGUNPal);
    loadTexture(71,"INVA2_SRLAUNCH", INVA2_SRLAUNCHBitmap, 24, 16, INVA2_SRLAUNCHPal);
    loadTexture(72,"INVA2_SSHOTGUN", INVA2_SSHOTGUNBitmap, 24, 16, INVA2_SSHOTGUNPal);
    loadTexture(73,"INVA3_LIGHTNG", INVA3_LIGHTNGBitmap, 48, 16, INVA3_LIGHTNGPal);
    loadTexture(74,"INVA3_NAILGUN", INVA3_NAILGUNBitmap, 24, 16, INVA3_NAILGUNPal);
    loadTexture(75,"INVA3_RLAUNCH", INVA3_RLAUNCHBitmap, 24, 16, INVA3_RLAUNCHPal);
    loadTexture(76,"INVA3_SHOTGUN", INVA3_SHOTGUNBitmap, 24, 16, INVA3_SHOTGUNPal);
    loadTexture(77,"INVA3_SNAILGUN", INVA3_SNAILGUNBitmap, 24, 16, INVA3_SNAILGUNPal);
    loadTexture(78,"INVA3_SRLAUNCH", INVA3_SRLAUNCHBitmap, 24, 16, INVA3_SRLAUNCHPal);
    loadTexture(79,"INVA3_SSHOTGUN", INVA3_SSHOTGUNBitmap, 24, 16, INVA3_SSHOTGUNPal);
    loadTexture(80,"INVA4_LIGHTNG", INVA4_LIGHTNGBitmap, 48, 16, INVA4_LIGHTNGPal);
    loadTexture(81,"INVA4_NAILGUN", INVA4_NAILGUNBitmap, 24, 16, INVA4_NAILGUNPal);
    loadTexture(82,"INVA4_RLAUNCH", INVA4_RLAUNCHBitmap, 48, 16, INVA4_RLAUNCHPal);
    loadTexture(83,"INVA4_SHOTGUN", INVA4_SHOTGUNBitmap, 24, 16, INVA4_SHOTGUNPal);
    loadTexture(84,"INVA4_SNAILGUN", INVA4_SNAILGUNBitmap, 48, 16, INVA4_SNAILGUNPal);
    loadTexture(85,"INVA4_SRLAUNCH", INVA4_SRLAUNCHBitmap, 24, 16, INVA4_SRLAUNCHPal);
    loadTexture(86,"INVA4_SSHOTGUN", INVA4_SSHOTGUNBitmap, 24, 16, INVA4_SSHOTGUNPal);
    loadTexture(87,"INVA5_LIGHTNG", INVA5_LIGHTNGBitmap, 48, 16, INVA5_LIGHTNGPal);
    loadTexture(88,"INVA5_NAILGUN", INVA5_NAILGUNBitmap, 24, 16, INVA5_NAILGUNPal);
    loadTexture(89,"INVA5_RLAUNCH", INVA5_RLAUNCHBitmap, 24, 16, INVA5_RLAUNCHPal);
    loadTexture(90,"INVA5_SHOTGUN", INVA5_SHOTGUNBitmap, 24, 16, INVA5_SHOTGUNPal);
    loadTexture(91,"INVA5_SNAILGUN", INVA5_SNAILGUNBitmap, 24, 16, INVA5_SNAILGUNPal);
    loadTexture(92,"INVA5_SRLAUNCH", INVA5_SRLAUNCHBitmap, 24, 16, INVA5_SRLAUNCHPal);
    loadTexture(93,"INVA5_SSHOTGUN", INVA5_SSHOTGUNBitmap, 24, 16, INVA5_SSHOTGUNPal);
    loadTexture(94,"INV_LIGHTNG", INV_LIGHTNGBitmap, 48, 16, INV_LIGHTNGPal);
    loadTexture(95,"INV_NAILGUN", INV_NAILGUNBitmap, 24, 16, INV_NAILGUNPal);
    loadTexture(96,"INV_RLAUNCH", INV_RLAUNCHBitmap, 24, 16, INV_RLAUNCHPal);
    loadTexture(97,"INV_SHOTGUN", INV_SHOTGUNBitmap, 24, 16, INV_SHOTGUNPal);
    loadTexture(98,"INV_SNAILGUN", INV_SNAILGUNBitmap, 24, 16, INV_SNAILGUNPal);
    loadTexture(99,"INV_SRLAUNCH", INV_SRLAUNCHBitmap, 24, 16, INV_SRLAUNCHPal);
    loadTexture(100,"INV_SSHOTGUN", INV_SSHOTGUNBitmap, 24, 16, INV_SSHOTGUNPal);
    loadTexture(101,"loading", loadingBitmap, 114, 28, loadingPal);
    loadTexture(102,"mainmenu", mainmenuBitmap, 240, 112, mainmenuPal);
    loadTexture(103,"menudot1", menudot1Bitmap, 256, 32, menudot1Pal);
    loadTexture(104,"menudot2", menudot2Bitmap, 256, 32, menudot2Pal);
    loadTexture(105,"menudot3", menudot3Bitmap, 256, 32, menudot3Pal);
    loadTexture(106,"menudot4", menudot4Bitmap, 256, 32, menudot4Pal);
    loadTexture(107,"menudot5", menudot5Bitmap, 256, 32, menudot5Pal);
    loadTexture(108,"menudot6", menudot6Bitmap, 256, 32, menudot6Pal);
    loadTexture(109,"menuplyr", menuplyrBitmap, 48, 56, menuplyrPal);
    loadTexture(110,"NET", NETBitmap, 32, 32, NETPal);
    loadTexture(111,"NUM_0", NUM_0Bitmap, 24, 24, NUM_0Pal);
    loadTexture(112,"NUM_1", NUM_1Bitmap, 24, 24, NUM_1Pal);
    loadTexture(113,"NUM_2", NUM_2Bitmap, 24, 24, NUM_2Pal);
    loadTexture(114,"NUM_3", NUM_3Bitmap, 24, 24, NUM_3Pal);
    loadTexture(115,"NUM_4", NUM_4Bitmap, 24, 24, NUM_4Pal);
    loadTexture(116",NUM_5", NUM_5Bitmap, 24, 24, NUM_5Pal);
    loadTexture(117,"NUM_6", NUM_6Bitmap, 24, 24, NUM_6Pal);
    loadTexture(118,"NUM_7", NUM_7Bitmap, 24, 24, NUM_7Pal);
    loadTexture(119,"NUM_8", NUM_8Bitmap, 24, 24, NUM_8Pal);
    loadTexture(120,"NUM_9", NUM_9Bitmap, 24, 24, NUM_9Pal);
    loadTexture(121,"NUM_COLON", NUM_COLONBitmap, 24, 24, NUM_COLONPal);
    loadTexture(122,"NUM_MINUS", NUM_MINUSBitmap, 24, 24, NUM_MINUSPal);
    loadTexture(123,"NUM_SLASH", NUM_SLASHBitmap, 24, 24, NUM_SLASHPal);
    loadTexture(124,"pause", pauseBitmap, 86, 28, pausePal);
    loadTexture(125,"p_option", p_optionBitmap, 114, 28, p_optionPal);
    loadTexture(126,"qplaque", qplaqueBitmap, 32, 128, qplaquePal);
    loadTexture(127,"RAM", RAMBitmap, 86, 28, RAMPal);
    loadTexture(128,"ranking", rankingBitmap, 86, 28, rankingPal); // checkpoint
    loadTexture(129,"SBA1_INVIS", SBA1_INVISBitmap, 16, 16, SBA1_INVISPal);
    loadTexture(130,"SBA1_INVUL", SBA1_INVULBitmap, 16, 16, SBA1_INVULPal);
    loadTexture(131,"SBA1_KEY1", SBA1_KEY1Bitmap, 16, 16, SBA1_KEY1Pal);
    loadTexture(132,"SBA1_KEY2", SBA1_KEY2Bitmap, 16, 16, SBA1_KEY2Pal);
    loadTexture(133,"SBA1_QUAD", SBA1_QUADBitmap, 16, 16, SBA1_QUADPal);
    loadTexture(134,"SBA1_SUIT", SBA1_SUITBitmap, 16, 16, SBA1_SUITPal);
    loadTexture(135,"SBA2_INVIS", SBA2_INVISBitmap, 16, 16, SBA2_INVISPal);
    loadTexture(136,"SBA2_INVUL", SBA2_INVULBitmap, 16, 16, SBA2_INVULPal);
    loadTexture(137,"SBA2_KEY1", SBA2_KEY1Bitmap, 16, 16, SBA2_KEY1Pal);
    loadTexture(138,"SBA2_KEY2", SBA2_KEY2Bitmap, 16, 16, SBA2_KEY2Pal);
    loadTexture(139,"SBA2_QUAD", SBA2_QUADBitmap, 16, 16, SBA2_QUADPal);
    loadTexture(140,"SBA2_SUIT", SBA2_SUITBitmap, 16, 16, SBA2_SUITPal);
    loadTexture(141,"SBA3_INVIS", SBA3_INVISBitmap, 16, 16, SBA3_INVISPal);
    loadTexture(142,"SBA3_INVUL", SBA3_INVULBitmap, 16, 16, SBA3_INVULPal);
    loadTexture(143,"SBA3_KEY1", SBA3_KEY1Bitmap, 16, 16, SBA3_KEY1Pal);
    loadTexture(144,"SBA3_KEY2", SBA3_KEY2Bitmap, 16, 16, SBA3_KEY2Pal);
    loadTexture(145,"SBA3_QUAD", SBA3_QUADBitmap, 16, 16, SBA3_QUADPal);
    loadTexture(146,"SBA3_SUIT", SBA3_SUITBitmap, 16, 16, SBA3_SUITPal);
    loadTexture(147,"SBA4_INVIS", SBA4_INVISBitmap, 16, 16, SBA4_INVISPal);
    loadTexture(148,"SBA4_INVUL", SBA4_INVULBitmap, 16, 16, SBA4_INVULPal);
    loadTexture(149,"SBA4_KEY1", SBA4_KEY1Bitmap, 16, 16, SBA4_KEY1Pal);
    loadTexture(150,"SBA4_KEY2", SBA4_KEY2Bitmap, 16, 16, SBA4_KEY2Pal);
    loadTexture(151,"SBA4_QUAD", SBA4_QUADBitmap, 16, 16, SBA4_QUADPal);
    loadTexture(152,"SBA4_SUIT", SBA4_SUITBitmap, 16, 16, SBA4_SUITPal);
    loadTexture(153,"SBA5_INVIS", SBA5_INVISBitmap, 16, 16, SBA5_INVISPal);
    loadTexture(154,"SBA5_INVUL", SBA5_INVULBitmap, 16, 16, SBA5_INVULPal);
    loadTexture(155,"SBA5_KEY1", SBA5_KEY1Bitmap, 16, 16, SBA5_KEY1Pal);
    loadTexture(156,"SBA5_KEY2", SBA5_KEY2Bitmap, 16, 16, SBA5_KEY2Pal);
    loadTexture(157,"SBA5_QUAD", SBA5_QUADBitmap, 16, 16, SBA5_QUADPal);
    loadTexture(158,"SBA5_SUIT", SBA5_SUITBitmap, 16, 16, SBA5_SUITPal);
    loadTexture(159,"SBAR", SBARBitmap, 320, 24, SBARPal);
    loadTexture(160,"SB_AMMOBASE", SB_AMMOBASEBitmap, 24, 24, SB_AMMOBASEPal);
    loadTexture(161,"SB_ARMOR1", SB_ARMOR1Bitmap, 24, 24, SB_ARMOR1Pal);
    loadTexture(162,"SB_ARMOR2", SB_ARMOR2Bitmap, 24, 24, SB_ARMOR2Pal);
    loadTexture(163,"SB_ARMOR3", SB_ARMOR3Bitmap, 24, 24, SB_ARMOR3Pal);
    loadTexture(164,"SB_ARMORBASE", SB_ARMORBASEBitmap, 24, 24, SB_ARMORBASEPal);
    loadTexture(165,"SB_CELLS", SB_CELLSBitmap, 24, 24, SB_CELLSPal);
    loadTexture(166,"SB_INVIS", SB_INVISBitmap, 16, 16, SB_INVISPal);
    loadTexture(167,"SB_INVULN", SB_INVULNBitmap, 16, 16, SB_INVULNPal);
    loadTexture(168,"SB_KEY1", SB_KEY1Bitmap, 16, 16, SB_KEY1Pal);
    loadTexture(169,"SB_KEY2", SB_KEY2Bitmap, 16, 16, SB_KEY2Pal);
    loadTexture(170,"SB_NAILS", SB_NAILSBitmap, 24, 24, SB_NAILSPal);
    loadTexture(171,"SB_QUAD", SB_QUADBitmap, 16, 16, SB_QUADPal);
    loadTexture(172,"SB_ROCKET", SB_ROCKETBitmap, 24, 24, SB_ROCKETPal);
    loadTexture(173,"SB_SHELLS", SB_SHELLSBitmap, 24, 24, SB_SHELLSPal);
    loadTexture(174,"SB_SIGIL1", SB_SIGIL1Bitmap, 8, 16, SB_SIGIL1Pal);
    loadTexture(175,"SB_SIGIL2", SB_SIGIL2Bitmap, 8, 16, SB_SIGIL2Pal);
    loadTexture(176,"SB_SIGIL3", SB_SIGIL3Bitmap, 8, 16, SB_SIGIL3Pal);
    loadTexture(177,"SB_SIGIL4", SB_SIGIL4Bitmap, 8, 16, SB_SIGIL4Pal);
    loadTexture(178,"SB_SUIT", SB_SUITBitmap, 16, 16, SB_SUITPal);
    loadTexture(179,"SCOREBAR", SCOREBARBitmap, 320, 24, SCOREBARPal);
    loadTexture(180,"sell", sellBitmap, 320, 200, sellPal);
    loadTexture(181,"ttl_main", ttl_mainBitmap, 214, 24, ttl_mainPal);
    loadTexture(182,"TURTLE", TURTLEBitmap, 32, 32, TURTLEPal);
    
    // read pcx player textures

}

// TODO: read texture pallete from palette data
// Note that texture memory must be set to VRAM_F_LCD/VRAM_G_LCD befor copying texture data
// and the bank must be reverted
void loadTexture(int texId, const char* name, const u8* data, int texSizeX, int texSizeY, const u16* palette) {
    glBindTexture(0, texId);

    memcpy(textureNameTable[texId], name, 16);

    glColorTableEXT(0, 0, 256, 0, 0, palette);
    
    glTexImage2D(0, 0, GL_RGB256, texSizeX, texSizeY, 0,
                 0, (u8*)data);
}

char * GetTextureStringName(int texID) {
  
}

/*
void bindFaceTexture(const dmap_t* map, const dface_t* face) {
    const texinfo_t* texinfo = &map->texinfos[face->texInfo];
    const miptex_t* texture = &map->textures[texinfo->miptex];

    const char* texName = texture->name;

    for (int i = 0; i < numTextures; i++) {
        if (strncmp(textureNames[i], texName, 16) == 0) {
            glBindTexture(0, textureGLIDs[i]);
            return;
        }
    }
}
*/