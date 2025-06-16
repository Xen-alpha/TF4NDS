
#include <texture.h>
#include <nds.h>
#include <utils.h>

// texture data
#include <adoor01_2.h>
#include <adoor02_2.h>
#include <adoor03_2.h>
#include <adoor03_3.h>
#include <adoor03_4.h>
#include <adoor03_5.h>
#include <adoor03_6.h>
#include <adoor09_1.h>
#include <adoor09_2.h>
#include <afloor1_3.h>
#include <afloor1_4.h>
#include <afloor1_8.h>
#include <afloor3_1.h>
#include <altar1_1.h>
#include <altar1_3.h>
#include <altar1_4.h>
#include <altar1_6.h>
#include <altar1_7.h>
#include <altar1_8.h>
#include <altarb_1.h>
#include <altarb_2.h>
#include <altarc_1.h>
#include <arch7.h>
#include <arrow_m.h>
#include <az1_6.h>
#include <azfloor1_1.h>
#include <azswitch3.h>
#include <azwall1_5.h>
#include <azwall3_1.h>
#include <azwall3_2.h>
#include <basebutn3.h>
#include <batt0sid.h>
#include <batt0top.h>
#include <batt1sid.h>
#include <batt1top.h>
#include <black.h>
#include <bodiesa2_1.h>
#include <bodiesa2_4.h>
#include <bodiesa3_1.h>
#include <bodiesa3_2.h>
#include <bodiesa3_3.h>
#include <bricka2_1.h>
#include <bricka2_2.h>
#include <bricka2_4.h>
#include <bricka2_6.h>
#include <carch02.h>
#include <carch03.h>
#include <carch04_1.h>
#include <carch04_2.h>
#include <ceil1_1.h>
#include <ceiling1_3.h>
#include <ceiling4.h>
#include <ceiling5.h>
#include <church1_2.h>
#include <church7.h>
#include <city1_4.h>
#include <city1_7.h>
#include <city2_1.h>
#include <city2_2.h>
#include <city2_3.h>
#include <city2_5.h>
#include <city2_6.h>
#include <city2_7.h>
#include <city2_8.h>
#include <city3_2.h>
#include <city3_4.h>
#include <city4_1.h>
#include <city4_2.h>
#include <city4_5.h>
#include <city4_6.h>
#include <city4_7.h>
#include <city4_8.h>
#include <city5_1.h>
#include <city5_2.h>
#include <city5_3.h>
#include <city5_4.h>
#include <city5_6.h>
#include <city5_7.h>
#include <city5_8.h>
#include <city6_3.h>
#include <city6_4.h>
#include <city6_7.h>
#include <city6_8.h>
#include <city8_2.h>
#include <citya1_1.h>
#include <clip.h>
#include <column01_3.h>
#include <column01_4.h>
#include <column1_2.h>
#include <column1_4.h>
#include <column1_5.h>
#include <comp1_1.h>
#include <comp1_2.h>
#include <comp1_3.h>
#include <comp1_4.h>
#include <comp1_5.h>
#include <comp1_6.h>
#include <comp1_7.h>
#include <comp1_8.h>
#include <cop1_1.h>
#include <cop1_2.h>
#include <cop1_3.h>
#include <cop1_4.h>
#include <cop1_5.h>
#include <cop1_6.h>
#include <cop1_7.h>
#include <cop1_8.h>
#include <cop2_1.h>
#include <cop2_2.h>
#include <cop2_3.h>
#include <cop2_4.h>
#include <cop2_5.h>
#include <cop2_6.h>
#include <cop3_1.h>
#include <cop3_2.h>
#include <cop3_4.h>
#include <cop4_3.h>
#include <cop4_5.h>
#include <crate0_side.h>
#include <crate0_top.h>
#include <crate1_side.h>
#include <crate1_top.h>
#include <dem4_1.h>
#include <dem4_4.h>
#include <dem5_3.h>
#include <demc4_4.h>
#include <door01_2.h>
#include <door02_1.h>
#include <door02_2.h>
#include <door02_3.h>
#include <door02_7.h>
#include <door03_2.h>
#include <door03_3.h>
#include <door03_4.h>
#include <door03_5.h>
#include <door04_1.h>
#include <door04_2.h>
#include <door05_2.h>
#include <door05_3.h>
#include <dopeback.h>
#include <dopefish.h>
#include <dr01_1.h>
#include <dr01_2.h>
#include <dr02_1.h>
#include <dr02_2.h>
#include <dr03_1.h>
#include <dr05_2.h>
#include <dr07_1.h>
#include <dung01_1.h>
#include <dung01_2.h>
#include <dung01_3.h>
#include <dung01_4.h>
#include <dung01_5.h>
#include <dung02_1.h>
#include <dung02_5.h>
#include <ecop1_1.h>
#include <ecop1_4.h>
#include <ecop1_6.h>
#include <ecop1_7.h>
#include <ecop1_8.h>
#include <edoor01_1.h>
#include <elwall1_1.h>
#include <elwall2_4.h>
#include <emetal1_3.h>
#include <enter01.h>
#include <exit01.h>
#include <exit02_2.h>
#include <exit02_3.h>
#include <floor01_5.h>
#include <grave01_1.h>
#include <grave01_3.h>
#include <grave02_1.h>
#include <grave02_2.h>
#include <grave02_3.h>
#include <grave02_4.h>
#include <grave02_5.h>
#include <grave02_6.h>
#include <grave02_7.h>
#include <grave03_1.h>
#include <grave03_2.h>
#include <grave03_3.h>
#include <grave03_4.h>
#include <grave03_5.h>
#include <grave03_6.h>
#include <grave03_7.h>
#include <ground1_1.h>
#include <ground1_2.h>
#include <ground1_5.h>
#include <ground1_6.h>
#include <ground1_7.h>
#include <ground1_8.h>
#include <key01_1.h>
#include <key01_2.h>
#include <key01_3.h>
#include <key02_1.h>
#include <key02_2.h>
#include <key03_1.h>
#include <key03_2.h>
#include <key03_3.h>
#include <lgmetal.h>
#include <lgmetal2.h>
#include <lgmetal3.h>
#include <lgmetal4.h>
#include <light1_1.h>
#include <light1_2.h>
#include <light1_3.h>
#include <light1_4.h>
#include <light1_5.h>
#include <light1_7.h>
#include <light1_8.h>
#include <light3_3.h>
#include <light3_5.h>
#include <light3_6.h>
#include <light3_7.h>
#include <light3_8.h>
#include <m5_3.h>
#include <m5_5.h>
#include <m5_8.h>
#include <med100.h>
#include <med3_0.h>
#include <med3_1.h>
#include <met5_1.h>
#include <met5_2.h>
#include <met5_3.h>
#include <metal1_1.h>
#include <metal1_2.h>
#include <metal1_3.h>
#include <metal1_4.h>
#include <metal1_5.h>
#include <metal1_6.h>
#include <metal1_7.h>
#include <metal2_1.h>
#include <metal2_2.h>
#include <metal2_3.h>
#include <metal2_4.h>
#include <metal2_5.h>
#include <metal2_6.h>
#include <metal2_7.h>
#include <metal2_8.h>
#include <metal3_2.h>
#include <metal4_2.h>
#include <metal4_3.h>
#include <metal4_4.h>
#include <metal4_5.h>
#include <metal4_6.h>
#include <metal4_7.h>
#include <metal4_8.h>
#include <metal5_1.h>
#include <metal5_2.h>
#include <metal5_3.h>
#include <metal5_4.h>
#include <metal5_5.h>
#include <metal5_6.h>
#include <metal5_8.h>
#include <metal6_1.h>
#include <metal6_2.h>
#include <metal6_3.h>
#include <metal6_4.h>
#include <metalt1_1.h>
#include <metalt1_2.h>
#include <metalt1_7.h>
#include <metalt2_1.h>
#include <metalt2_2.h>
#include <metalt2_3.h>
#include <metalt2_4.h>
#include <metalt2_5.h>
#include <metalt2_6.h>
#include <metalt2_7.h>
#include <metalt2_8.h>
#include <metflor2_1.h>
#include <mmetal1_1.h>
#include <mmetal1_2.h>
#include <mmetal1_3.h>
#include <mmetal1_5.h>
#include <mmetal1_6.h>
#include <mmetal1_7.h>
#include <mmetal1_8.h>
#include <mswtch_2.h>
#include <mswtch_3.h>
#include <mswtch_4.h>
#include <muh_bad.h>
#include <nail0sid.h>
#include <nail0top.h>
#include <nail1sid.h>
#include <nail1top.h>
#include <nmetal2_1.h>
#include <nmetal2_6.h>
#include <plat_side1.h>
#include <plat_stem.h>
#include <plat_top1.h>
#include <plat_top2.h>
#include <quake.h>
#include <raven.h>
#include <rock0sid.h>
#include <rock1sid.h>
#include <rock1_2.h>
#include <rock3_2.h>
#include <rock3_7.h>
#include <rock3_8.h>
#include <rock4_1.h>
#include <rock4_2.h>
#include <rock5_2.h>
#include <rockettop.h>
#include <rune1_1.h>
#include <rune1_4.h>
#include <rune1_5.h>
#include <rune1_6.h>
#include <rune1_7.h>
#include <rune2_1.h>
#include <rune2_2.h>
#include <rune2_3.h>
#include <rune2_4.h>
#include <rune2_5.h>
#include <rune_a.h>
#include <sfloor1_2.h>
#include <sfloor3_2.h>
#include <sfloor4_1.h>
#include <sfloor4_2.h>
#include <sfloor4_4.h>
#include <sfloor4_5.h>
#include <sfloor4_6.h>
#include <sfloor4_7.h>
#include <sfloor4_8.h>
#include <shot0sid.h>
#include <shot0top.h>
#include <shot1sid.h>
#include <shot1top.h>
#include <skill0.h>
#include <skill1.h>
#include <skill2.h>
#include <skill3.h>
#include <sky1.h>
#include <sky4.h>
#include <slip1.h>
#include <slip2.h>
#include <slipbotsd.h>
#include <sliplite.h>
#include <slipside.h>
#include <sliptopsd.h>
#include <stone1_3.h>
#include <stone1_5.h>
#include <stone1_7.h>
#include <switch_1.h>
#include <swtch1_1.h>
#include <tech01_1.h>
#include <tech01_2.h>
#include <tech01_3.h>
#include <tech01_5.h>
#include <tech01_6.h>
#include <tech01_7.h>
#include <tech01_9.h>
#include <tech02_1.h>
#include <tech02_2.h>
#include <tech02_3.h>
#include <tech02_5.h>
#include <tech02_6.h>
#include <tech02_7.h>
#include <tech03_1.h>
#include <tech03_2.h>
#include <tech04_1.h>
#include <tech04_2.h>
#include <tech04_3.h>
#include <tech04_4.h>
#include <tech04_5.h>
#include <tech04_6.h>
#include <tech04_7.h>
#include <tech04_8.h>
#include <tech05_1.h>
#include <tech05_2.h>
#include <tech06_1.h>
#include <tech06_2.h>
#include <tech07_1.h>
#include <tech07_2.h>
#include <tech08_1.h>
#include <tech08_2.h>
#include <tech09_3.h>
#include <tech09_4.h>
#include <tech10_1.h>
#include <tech10_3.h>
#include <tech11_1.h>
#include <tech11_2.h>
#include <tech12_1.h>
#include <tech13_2.h>
#include <tech14_1.h>
#include <tech14_2.h>
#include <tele_top.h>
#include <tlight01.h>
#include <tlight01_2.h>
#include <tlight02.h>
#include <tlight03.h>
#include <tlight05.h>
#include <tlight07.h>
#include <tlight08.h>
#include <tlight09.h>
#include <tlight10.h>
#include <tlight11.h>
#include <trigger.h>
#include <twall1_1.h>
#include <twall1_2.h>
#include <twall1_4.h>
#include <twall2_1.h>
#include <twall2_2.h>
#include <twall2_3.h>
#include <twall2_5.h>
#include <twall2_6.h>
#include <twall3_1.h>
#include <twall5_1.h>
#include <twall5_2.h>
#include <twall5_3.h>
#include <unwall1_8.h>
#include <uwall1_2.h>
#include <uwall1_3.h>
#include <uwall1_4.h>
#include <vine1_2.h>
#include <wall11_2.h>
#include <wall11_6.h>
#include <wall14_5.h>
#include <wall14_6.h>
#include <wall16_7.h>
#include <wall3_4.h>
#include <wall5_4.h>
#include <wall9_3.h>
#include <wall9_8.h>
#include <warch05.h>
#include <wbrick1_4.h>
#include <wbrick1_5.h>
#include <wceiling4.h>
#include <wceiling5.h>
#include <wenter01.h>
#include <wexit01.h>
#include <wgrass1_1.h>
#include <wgrnd1_5.h>
#include <wgrnd1_6.h>
#include <wgrnd1_8.h>
#include <window01_1.h>
#include <window01_2.h>
#include <window01_3.h>
#include <window01_4.h>
#include <window02_1.h>
#include <window03.h>
#include <window1_2.h>
#include <window1_3.h>
#include <window1_4.h>
#include <wiz1_1.h>
#include <wiz1_4.h>
#include <wizmet1_1.h>
#include <wizmet1_2.h>
#include <wizmet1_3.h>
#include <wizmet1_4.h>
#include <wizmet1_5.h>
#include <wizmet1_6.h>
#include <wizmet1_7.h>
#include <wizmet1_8.h>
#include <wizwin1_2.h>
#include <wizwin1_8.h>
#include <wizwood1_2.h>
#include <wizwood1_3.h>
#include <wizwood1_4.h>
#include <wizwood1_5.h>
#include <wizwood1_6.h>
#include <wizwood1_7.h>
#include <wizwood1_8.h>
#include <wkey02_1.h>
#include <wkey02_2.h>
#include <wkey02_3.h>
#include <wmet1_1.h>
#include <wmet2_1.h>
#include <wmet2_2.h>
#include <wmet2_3.h>
#include <wmet2_4.h>
#include <wmet2_6.h>
#include <wmet3_1.h>
#include <wmet3_3.h>
#include <wmet3_4.h>
#include <wmet4_2.h>
#include <wmet4_3.h>
#include <wmet4_4.h>
#include <wmet4_5.h>
#include <wmet4_6.h>
#include <wmet4_7.h>
#include <wmet4_8.h>
#include <wood1_1.h>
#include <wood1_5.h>
#include <wood1_7.h>
#include <wood1_8.h>
#include <woodflr1_2.h>
#include <woodflr1_4.h>
#include <woodflr1_5.h>
#include <wswamp1_2.h>
#include <wswamp1_4.h>
#include <wswamp2_1.h>
#include <wswamp2_2.h>
#include <wswitch1.h>
#include <wwall1_1.h>
#include <wwood1_5.h>
#include <wwood1_7.h>
#include <z_exit.h>

LinkedTrie *textureIDList = NULL;
int textureIDs[MAX_TEX_DATA];
u16* paletteData[MAX_TEX_DATA];

void initTexture() {
    glGenTextures(MAX_TEX_DATA, textureIDs);

    loadTexture(0, "adoor01_2", adoor01_2Bitmap, 128, 192, adoor01_2Pal); 
    loadTexture(1, "adoor02_2", adoor02_2Bitmap, 128, 192, adoor02_2Pal); 
    loadTexture(2, "adoor03_2", adoor03_2Bitmap, 128, 192, adoor03_2Pal); 
    loadTexture(3, "adoor03_3", adoor03_3Bitmap, 32, 32, adoor03_3Pal);
    loadTexture(4, "adoor03_4", adoor03_4Bitmap, 32, 32, adoor03_4Pal);
    loadTexture(5, "adoor03_5", adoor03_5Bitmap, 32, 32, adoor03_5Pal);
    loadTexture(6, "adoor03_6", adoor03_6Bitmap, 16, 16, adoor03_6Pal);
    loadTexture(7, "adoor09_1", adoor09_1Bitmap, 128, 192, adoor09_1Pal); 
    loadTexture(8, "adoor09_2", adoor09_2Bitmap, 128, 192, adoor09_2Pal); 
    loadTexture(9, "afloor1_3", afloor1_3Bitmap, 64, 64, afloor1_3Pal);
    loadTexture(10, "afloor1_4", afloor1_4Bitmap, 64, 64, afloor1_4Pal);
    loadTexture(11, "afloor1_8", afloor1_8Bitmap, 64, 64, afloor1_8Pal);
    loadTexture(12, "afloor3_1", afloor3_1Bitmap, 64, 64, afloor3_1Pal);
    loadTexture(13, "altar1_1", altar1_1Bitmap, 64, 64, altar1_1Pal);
    loadTexture(14, "altar1_3", altar1_3Bitmap, 64, 64, altar1_3Pal);
    loadTexture(15, "altar1_4", altar1_4Bitmap, 64, 64, altar1_4Pal);
    loadTexture(16, "altar1_6", altar1_6Bitmap, 64, 64, altar1_6Pal);
    loadTexture(17, "altar1_7", altar1_7Bitmap, 64, 64, altar1_7Pal);
    loadTexture(18, "altar1_8", altar1_8Bitmap, 64, 64, altar1_8Pal);
    loadTexture(19, "altarb_1", altarb_1Bitmap, 64, 128, altarb_1Pal); 
    loadTexture(20, "altarb_2", altarb_2Bitmap, 64, 128, altarb_2Pal); 
    loadTexture(21, "altarc_1", altarc_1Bitmap, 64, 64, altarc_1Pal);
    loadTexture(22, "arch7", arch7Bitmap, 256, 192, arch7Pal);
    loadTexture(23, "arrow_m", arrow_mBitmap, 32, 32, arrow_mPal);
    loadTexture(24, "az1_6", az1_6Bitmap, 32, 64, az1_6Pal);
    loadTexture(25, "azfloor1_1", azfloor1_1Bitmap, 64, 64, azfloor1_1Pal);
    loadTexture(26, "azswitch3", azswitch3Bitmap, 16, 32, azswitch3Pal);
    loadTexture(27, "azwall1_5", azwall1_5Bitmap, 64, 64, azwall1_5Pal);
    loadTexture(28, "azwall3_1", azwall3_1Bitmap, 64, 64, azwall3_1Pal);
    loadTexture(29, "azwall3_2", azwall3_2Bitmap, 64, 64, azwall3_2Pal);
    loadTexture(30, "basebutn3", basebutn3Bitmap, 32, 32, basebutn3Pal);
    loadTexture(31, "batt0sid", batt0sidBitmap, 32, 32, batt0sidPal);
    loadTexture(32, "batt0top", batt0topBitmap, 32, 32, batt0topPal);
    loadTexture(33, "batt1sid", batt1sidBitmap, 32, 32, batt1sidPal);
    loadTexture(34, "batt1top", batt1topBitmap, 32, 32, batt1topPal);
    loadTexture(35, "black", blackBitmap, 16, 16, blackPal);
    loadTexture(36, "bodiesa2_1", bodiesa2_1Bitmap, 64, 128, bodiesa2_1Pal);
    loadTexture(37, "bodiesa2_4", bodiesa2_4Bitmap, 64, 128, bodiesa2_4Pal);
    loadTexture(38, "bodiesa3_1", bodiesa3_1Bitmap, 64, 128, bodiesa3_1Pal);
    loadTexture(39, "bodiesa3_2", bodiesa3_2Bitmap, 64, 128, bodiesa3_2Pal);
    loadTexture(40, "bodiesa3_3", bodiesa3_3Bitmap, 64, 128, bodiesa3_3Pal);
    loadTexture(41, "bricka2_1", bricka2_1Bitmap, 64, 64, bricka2_1Pal);
    loadTexture(42, "bricka2_2", bricka2_2Bitmap, 64, 64, bricka2_2Pal);
    loadTexture(43, "bricka2_4", bricka2_4Bitmap, 64, 64, bricka2_4Pal);
    loadTexture(44, "bricka2_6", bricka2_6Bitmap, 64, 64, bricka2_6Pal);
    loadTexture(45, "carch02", carch02Bitmap, 128, 128, carch02Pal);
    loadTexture(46, "carch03", carch03Bitmap, 256, 192, carch03Pal);
    loadTexture(47, "carch04_1", carch04_1Bitmap, 128, 64, carch04_1Pal);
    loadTexture(48, "carch04_2", carch04_2Bitmap, 128, 64, carch04_2Pal);
    loadTexture(49, "ceil1_1", ceil1_1Bitmap, 16, 16, ceil1_1Pal);
    loadTexture(50, "ceiling1_3", ceiling1_3Bitmap, 64, 64, ceiling1_3Pal);
    loadTexture(51, "ceiling4", ceiling4Bitmap, 192, 192, ceiling4Pal);
    loadTexture(52, "ceiling5", ceiling5Bitmap, 64, 64, ceiling5Pal);
    loadTexture(53, "church1_2", church1_2Bitmap, 64, 64, church1_2Pal);
    loadTexture(54, "church7", church7Bitmap, 192, 192, church7Pal);
    loadTexture(55, "city1_4", city1_4Bitmap, 64, 64, city1_4Pal);
    loadTexture(56, "city1_7", city1_7Bitmap, 64, 64, city1_7Pal);
    loadTexture(57, "city2_1", city2_1Bitmap, 64, 64, city2_1Pal);
    loadTexture(58, "city2_2", city2_2Bitmap, 64, 64, city2_2Pal);
    loadTexture(59, "city2_3", city2_3Bitmap, 64, 64, city2_3Pal);
    loadTexture(60, "city2_5", city2_5Bitmap, 64, 64, city2_5Pal);
    loadTexture(61, "city2_6", city2_6Bitmap, 64, 64, city2_6Pal);
    loadTexture(62, "city2_7", city2_7Bitmap, 64, 64, city2_7Pal);
    loadTexture(63, "city2_8", city2_8Bitmap, 64, 64, city2_8Pal);
    loadTexture(64, "city3_2", city3_2Bitmap, 64, 64, city3_2Pal);
    loadTexture(65, "city3_4", city3_4Bitmap, 64, 64, city3_4Pal);
    loadTexture(66, "city4_1", city4_1Bitmap, 64, 64, city4_1Pal);
    loadTexture(67, "city4_2", city4_2Bitmap, 64, 64, city4_2Pal);
    loadTexture(68, "city4_5", city4_5Bitmap, 64, 64, city4_5Pal);
    loadTexture(69, "city4_6", city4_6Bitmap, 64, 64, city4_6Pal);
    loadTexture(70, "city4_7", city4_7Bitmap, 64, 64, city4_7Pal);
    loadTexture(71, "city4_8", city4_8Bitmap, 64, 64, city4_8Pal);
    loadTexture(72, "city5_1", city5_1Bitmap, 64, 64, city5_1Pal);
    loadTexture(73, "city5_2", city5_2Bitmap, 64, 64, city5_2Pal);
    loadTexture(74, "city5_3", city5_3Bitmap, 64, 64, city5_3Pal);
    loadTexture(75, "city5_4", city5_4Bitmap, 64, 64, city5_4Pal);
    loadTexture(76, "city5_6", city5_6Bitmap, 64, 64, city5_6Pal);
    loadTexture(77, "city5_7", city5_7Bitmap, 64, 64, city5_7Pal);
    loadTexture(78, "city5_8", city5_8Bitmap, 64, 64, city5_8Pal);
    loadTexture(79, "city6_3", city6_3Bitmap, 64, 64, city6_3Pal);
    loadTexture(80, "city6_4", city6_4Bitmap, 64, 64, city6_4Pal);
    loadTexture(81, "city6_7", city6_7Bitmap, 64, 64, city6_7Pal);
    loadTexture(82, "city6_8", city6_8Bitmap, 64, 64, city6_8Pal);
    loadTexture(83, "city8_2", city8_2Bitmap, 64, 64, city8_2Pal);
    loadTexture(84, "citya1_1", citya1_1Bitmap, 64, 64, citya1_1Pal);
    loadTexture(85, "clip", clipBitmap, 64, 64, clipPal);
    loadTexture(86, "column01_3", column01_3Bitmap, 64, 64, column01_3Pal);
    loadTexture(87, "column01_4", column01_4Bitmap, 64, 64, column01_4Pal);
    loadTexture(88, "column1_2", column1_2Bitmap, 64, 64, column1_2Pal);
    loadTexture(89, "column1_4", column1_4Bitmap, 64, 64, column1_4Pal);
    loadTexture(90, "column1_5", column1_5Bitmap, 64, 64, column1_5Pal);
    loadTexture(91, "comp1_1", comp1_1Bitmap, 64, 64, comp1_1Pal);
    loadTexture(92, "comp1_2", comp1_2Bitmap, 64, 64, comp1_2Pal);
    loadTexture(93, "comp1_3", comp1_3Bitmap, 64, 64, comp1_3Pal);
    loadTexture(94, "comp1_4", comp1_4Bitmap, 64, 64, comp1_4Pal);
    loadTexture(95, "comp1_5", comp1_5Bitmap, 64, 64, comp1_5Pal);
    loadTexture(96, "comp1_6", comp1_6Bitmap, 64, 64, comp1_6Pal);
    loadTexture(97, "comp1_7", comp1_7Bitmap, 64, 64, comp1_7Pal);
    loadTexture(98, "comp1_8", comp1_8Bitmap, 64, 64, comp1_8Pal);
    loadTexture(99, "cop1_1", cop1_1Bitmap, 64, 64, cop1_1Pal);
    loadTexture(100, "cop1_2", cop1_2Bitmap, 64, 64, cop1_2Pal);
    loadTexture(101, "cop1_3", cop1_3Bitmap, 64, 64, cop1_3Pal);
    loadTexture(102, "cop1_4", cop1_4Bitmap, 64, 64, cop1_4Pal);
    loadTexture(103, "cop1_5", cop1_5Bitmap, 64, 64, cop1_5Pal);
    loadTexture(104, "cop1_6", cop1_6Bitmap, 64, 64, cop1_6Pal);
    loadTexture(105, "cop1_7", cop1_7Bitmap, 64, 64, cop1_7Pal);
    loadTexture(106, "cop1_8", cop1_8Bitmap, 64, 64, cop1_8Pal);
    loadTexture(107, "cop2_1", cop2_1Bitmap, 64, 64, cop2_1Pal);
    loadTexture(108, "cop2_2", cop2_2Bitmap, 64, 64, cop2_2Pal);
    loadTexture(109, "cop2_3", cop2_3Bitmap, 64, 64, cop2_3Pal);
    loadTexture(110, "cop2_4", cop2_4Bitmap, 64, 64, cop2_4Pal);
    loadTexture(111, "cop2_5", cop2_5Bitmap, 64, 64, cop2_5Pal);
    loadTexture(112, "cop2_6", cop2_6Bitmap, 64, 64, cop2_6Pal);
    loadTexture(113, "cop3_1", cop3_1Bitmap, 64, 64, cop3_1Pal);
    loadTexture(114, "cop3_2", cop3_2Bitmap, 64, 64, cop3_2Pal);
    loadTexture(115, "cop3_4", cop3_4Bitmap, 64, 64, cop3_4Pal);
    loadTexture(116, "cop4_3", cop4_3Bitmap, 64, 64, cop4_3Pal);
    loadTexture(117, "cop4_5", cop4_5Bitmap, 64, 64, cop4_5Pal);
    loadTexture(118, "crate0_side", crate0_sideBitmap, 64, 64, crate0_sidePal);
    loadTexture(119, "crate0_top", crate0_topBitmap, 64, 64, crate0_topPal);
    loadTexture(120, "crate1_side", crate1_sideBitmap, 64, 64, crate1_sidePal);
    loadTexture(121, "crate1_top", crate1_topBitmap, 64, 64, crate1_topPal);
    loadTexture(122, "dem4_1", dem4_1Bitmap, 64, 128, dem4_1Pal);
    loadTexture(123, "dem4_4", dem4_4Bitmap, 64, 128, dem4_4Pal);
    loadTexture(124, "dem5_3", dem5_3Bitmap, 64, 128, dem5_3Pal);
    loadTexture(125, "demc4_4", demc4_4Bitmap, 64, 128, demc4_4Pal);
    loadTexture(126, "door01_2", door01_2Bitmap, 128, 192, door01_2Pal);
    loadTexture(127, "door02_1", door02_1Bitmap, 16, 192, door02_1Pal);
    loadTexture(64, "door02_2", door02_2Bitmap, 128, 192, door02_2Pal);
    loadTexture(129, "door02_3", door02_3Bitmap, 32, 32, door02_3Pal);
    loadTexture(130, "door02_7", door02_7Bitmap, 32, 32, door02_7Pal);
    loadTexture(131, "door03_2", door03_2Bitmap, 128, 192, door03_2Pal);
    loadTexture(132, "door03_3", door03_3Bitmap, 32, 32, door03_3Pal);
    loadTexture(133, "door03_4", door03_4Bitmap, 32, 32, door03_4Pal);
    loadTexture(134, "door03_5", door03_5Bitmap, 32, 32, door03_5Pal);
    loadTexture(135, "door04_1", door04_1Bitmap, 128, 192, door04_1Pal);
    loadTexture(136, "door04_2", door04_2Bitmap, 64, 64, door04_2Pal);
    loadTexture(137, "door05_2", door05_2Bitmap, 64, 64, door05_2Pal);
    loadTexture(138, "door05_3", door05_3Bitmap, 16, 16, door05_3Pal);
    loadTexture(139, "dopeback", dopebackBitmap, 64, 64, dopebackPal);
    loadTexture(140, "dopefish", dopefishBitmap, 112, 80, dopefishPal);
    loadTexture(141, "dr01_1", dr01_1Bitmap, 64, 128, dr01_1Pal);
    loadTexture(142, "dr01_2", dr01_2Bitmap, 64, 128, dr01_2Pal);
    loadTexture(143, "dr02_1", dr02_1Bitmap, 64, 128, dr02_1Pal);
    loadTexture(144, "dr02_2", dr02_2Bitmap, 64, 128, dr02_2Pal);
    loadTexture(145, "dr03_1", dr03_1Bitmap, 64, 128, dr03_1Pal);
    loadTexture(146, "dr05_2", dr05_2Bitmap, 64, 128, dr05_2Pal);
    loadTexture(147, "dr07_1", dr07_1Bitmap, 160, 176, dr07_1Pal);
    loadTexture(148, "dung01_1", dung01_1Bitmap, 128, 128, dung01_1Pal);
    loadTexture(149, "dung01_2", dung01_2Bitmap, 64, 64, dung01_2Pal);
    loadTexture(150, "dung01_3", dung01_3Bitmap, 64, 64, dung01_3Pal);
    loadTexture(151, "dung01_4", dung01_4Bitmap, 64, 64, dung01_4Pal);
    loadTexture(152, "dung01_5", dung01_5Bitmap, 64, 64, dung01_5Pal);
    loadTexture(153, "dung02_1", dung02_1Bitmap, 64, 64, dung02_1Pal);
    loadTexture(154, "dung02_5", dung02_5Bitmap, 64, 64, dung02_5Pal);
    loadTexture(155, "ecop1_1", ecop1_1Bitmap, 64, 64, ecop1_1Pal);
    loadTexture(156, "ecop1_4", ecop1_4Bitmap, 64, 64, ecop1_4Pal);
    loadTexture(157, "ecop1_6", ecop1_6Bitmap, 64, 64, ecop1_6Pal);
    loadTexture(158, "ecop1_7", ecop1_7Bitmap, 64, 64, ecop1_7Pal);
    loadTexture(159, "ecop1_8", ecop1_8Bitmap, 64, 64, ecop1_8Pal);
    loadTexture(160, "edoor01_1", edoor01_1Bitmap, 128, 128, edoor01_1Pal);
    loadTexture(161, "elwall1_1", elwall1_1Bitmap, 64, 64, elwall1_1Pal);
    loadTexture(162, "elwall2_4", elwall2_4Bitmap, 64, 64, elwall2_4Pal);
    loadTexture(163, "emetal1_3", emetal1_3Bitmap, 64, 64, emetal1_3Pal);
    loadTexture(164, "enter01", enter01Bitmap, 240, 192, enter01Pal);
    loadTexture(165, "exit01", exit01Bitmap, 240, 192, exit01Pal);
    loadTexture(166, "exit02_2", exit02_2Bitmap, 64, 64, exit02_2Pal);
    loadTexture(167, "exit02_3", exit02_3Bitmap, 64, 64, exit02_3Pal);
    loadTexture(168, "floor01_5", floor01_5Bitmap, 64, 64, floor01_5Pal);
    loadTexture(169, "grave01_1", grave01_1Bitmap, 64, 64, grave01_1Pal);
    loadTexture(170, "grave01_3", grave01_3Bitmap, 64, 64, grave01_3Pal);
    loadTexture(171, "grave02_1", grave02_1Bitmap, 64, 64, grave02_1Pal);
    loadTexture(172, "grave02_2", grave02_2Bitmap, 64, 64, grave02_2Pal);
    loadTexture(173, "grave02_3", grave02_3Bitmap, 64, 64, grave02_3Pal);
    loadTexture(174, "grave02_4", grave02_4Bitmap, 64, 64, grave02_4Pal);
    loadTexture(175, "grave02_5", grave02_5Bitmap, 64, 64, grave02_5Pal);
    loadTexture(176, "grave02_6", grave02_6Bitmap, 64, 64, grave02_6Pal);
    loadTexture(177, "grave02_7", grave02_7Bitmap, 64, 64, grave02_7Pal);
    loadTexture(178, "grave03_1", grave03_1Bitmap, 64, 64, grave03_1Pal);
    loadTexture(179, "grave03_2", grave03_2Bitmap, 64, 64, grave03_2Pal);
    loadTexture(180, "grave03_3", grave03_3Bitmap, 64, 64, grave03_3Pal);
    loadTexture(181, "grave03_4", grave03_4Bitmap, 64, 64, grave03_4Pal);
    loadTexture(182, "grave03_5", grave03_5Bitmap, 64, 64, grave03_5Pal);
    loadTexture(183, "grave03_6", grave03_6Bitmap, 64, 64, grave03_6Pal);
    loadTexture(184, "grave03_7", grave03_7Bitmap, 64, 64, grave03_7Pal);
    loadTexture(185, "ground1_1", ground1_1Bitmap, 64, 64, ground1_1Pal);
    loadTexture(186, "ground1_2", ground1_2Bitmap, 64, 64, ground1_2Pal);
    loadTexture(187, "ground1_5", ground1_5Bitmap, 64, 64, ground1_5Pal);
    loadTexture(188, "ground1_6", ground1_6Bitmap, 64, 64, ground1_6Pal);
    loadTexture(189, "ground1_7", ground1_7Bitmap, 64, 64, ground1_7Pal);
    loadTexture(190, "ground1_8", ground1_8Bitmap, 64, 64, ground1_8Pal);
    loadTexture(191, "key01_1", key01_1Bitmap, 32, 32, key01_1Pal);
    loadTexture(192, "key01_2", key01_2Bitmap, 32, 32, key01_2Pal);
    loadTexture(193, "key01_3", key01_3Bitmap, 64, 64, key01_3Pal);
    loadTexture(194, "key02_1", key02_1Bitmap, 32, 32, key02_1Pal);
    loadTexture(195, "key02_2", key02_2Bitmap, 32, 32, key02_2Pal);
    loadTexture(196, "key03_1", key03_1Bitmap, 32, 32, key03_1Pal);
    loadTexture(197, "key03_2", key03_2Bitmap, 32, 32, key03_2Pal);
    loadTexture(198, "key03_3", key03_3Bitmap, 64, 64, key03_3Pal);
    loadTexture(199, "lgmetal", lgmetalBitmap, 320, 192, lgmetalPal);
    loadTexture(200, "lgmetal2", lgmetal2Bitmap, 320, 192, lgmetal2Pal);
    loadTexture(201, "lgmetal3", lgmetal3Bitmap, 320, 192, lgmetal3Pal);
    loadTexture(202, "lgmetal4", lgmetal4Bitmap, 64, 64, lgmetal4Pal);
    loadTexture(203, "light1_1", light1_1Bitmap, 64, 64, light1_1Pal);
    loadTexture(204, "light1_2", light1_2Bitmap, 64, 64, light1_2Pal);
    loadTexture(205, "light1_3", light1_3Bitmap, 64, 64, light1_3Pal);
    loadTexture(206, "light1_4", light1_4Bitmap, 64, 64, light1_4Pal);
    loadTexture(207, "light1_5", light1_5Bitmap, 64, 64, light1_5Pal);
    loadTexture(208, "light1_7", light1_7Bitmap, 64, 64, light1_7Pal);
    loadTexture(209, "light1_8", light1_8Bitmap, 64, 64, light1_8Pal);
    loadTexture(210, "light3_3", light3_3Bitmap, 64, 64, light3_3Pal);
    loadTexture(211, "light3_5", light3_5Bitmap, 32, 64, light3_5Pal);
    loadTexture(212, "light3_6", light3_6Bitmap, 32, 64, light3_6Pal);
    loadTexture(213, "light3_7", light3_7Bitmap, 32, 32, light3_7Pal);
    loadTexture(214, "light3_8", light3_8Bitmap, 32, 32, light3_8Pal);
    loadTexture(215, "m5_3", m5_3Bitmap, 64, 64, m5_3Pal);
    loadTexture(216, "m5_5", m5_5Bitmap, 64, 64, m5_5Pal);
    loadTexture(217, "m5_8", m5_8Bitmap, 64, 64, m5_8Pal);
    loadTexture(218, "med100", med100Bitmap, 32, 32, med100Pal);
    loadTexture(219, "med3_0", med3_0Bitmap, 32, 32, med3_0Pal);
    loadTexture(220, "med3_1", med3_1Bitmap, 32, 16, med3_1Pal);
    loadTexture(221, "met5_1", met5_1Bitmap, 64, 64, met5_1Pal);
    loadTexture(222, "met5_2", met5_2Bitmap, 64, 64, met5_2Pal);
    loadTexture(223, "met5_3", met5_3Bitmap, 64, 64, met5_3Pal);
    loadTexture(224, "metal1_1", metal1_1Bitmap, 64, 64, metal1_1Pal);
    loadTexture(225, "metal1_2", metal1_2Bitmap, 64, 64, metal1_2Pal);
    loadTexture(226, "metal1_3", metal1_3Bitmap, 64, 64, metal1_3Pal);
    loadTexture(227, "metal1_4", metal1_4Bitmap, 64, 64, metal1_4Pal);
    loadTexture(228, "metal1_5", metal1_5Bitmap, 64, 64, metal1_5Pal);
    loadTexture(229, "metal1_6", metal1_6Bitmap, 64, 64, metal1_6Pal);
    loadTexture(230, "metal1_7", metal1_7Bitmap, 64, 64, metal1_7Pal);
    loadTexture(231, "metal2_1", metal2_1Bitmap, 64, 64, metal2_1Pal);
    loadTexture(232, "metal2_2", metal2_2Bitmap, 64, 64, metal2_2Pal);
    loadTexture(233, "metal2_3", metal2_3Bitmap, 64, 64, metal2_3Pal);
    loadTexture(234, "metal2_4", metal2_4Bitmap, 64, 64, metal2_4Pal);
    loadTexture(235, "metal2_5", metal2_5Bitmap, 64, 64, metal2_5Pal);
    loadTexture(236, "metal2_6", metal2_6Bitmap, 64, 64, metal2_6Pal);
    loadTexture(237, "metal2_7", metal2_7Bitmap, 64, 64, metal2_7Pal);
    loadTexture(238, "metal2_8", metal2_8Bitmap, 64, 64, metal2_8Pal);
    loadTexture(239, "metal3_2", metal3_2Bitmap, 64, 64, metal3_2Pal);
    loadTexture(240, "metal4_2", metal4_2Bitmap, 64, 64, metal4_2Pal);
    loadTexture(241, "metal4_3", metal4_3Bitmap, 64, 64, metal4_3Pal);
    loadTexture(242, "metal4_4", metal4_4Bitmap, 64, 64, metal4_4Pal);
    loadTexture(243, "metal4_5", metal4_5Bitmap, 64, 64, metal4_5Pal);
    loadTexture(244, "metal4_6", metal4_6Bitmap, 64, 64, metal4_6Pal);
    loadTexture(245, "metal4_7", metal4_7Bitmap, 64, 64, metal4_7Pal);
    loadTexture(246, "metal4_8", metal4_8Bitmap, 64, 64, metal4_8Pal);
    loadTexture(247, "metal5_1", metal5_1Bitmap, 64, 64, metal5_1Pal);
    loadTexture(248, "metal5_2", metal5_2Bitmap, 64, 64, metal5_2Pal);
    loadTexture(249, "metal5_3", metal5_3Bitmap, 64, 64, metal5_3Pal);
    loadTexture(250, "metal5_4", metal5_4Bitmap, 64, 64, metal5_4Pal);
    loadTexture(251, "metal5_5", metal5_5Bitmap, 64, 64, metal5_5Pal);
    loadTexture(252, "metal5_6", metal5_6Bitmap, 64, 64, metal5_6Pal);
    loadTexture(253, "metal5_8", metal5_8Bitmap, 64, 64, metal5_8Pal);
    loadTexture(254, "metal6_1", metal6_1Bitmap, 32, 64, metal6_1Pal);
    loadTexture(255, "metal6_2", metal6_2Bitmap, 32, 64, metal6_2Pal);
    loadTexture(256, "metal6_3", metal6_3Bitmap, 32, 32, metal6_3Pal);
    loadTexture(257, "metal6_4", metal6_4Bitmap, 32, 32, metal6_4Pal);
    loadTexture(258, "metalt1_1", metalt1_1Bitmap, 64, 64, metalt1_1Pal);
    loadTexture(259, "metalt1_2", metalt1_2Bitmap, 64, 64, metalt1_2Pal);
    loadTexture(260, "metalt1_7", metalt1_7Bitmap, 64, 64, metalt1_7Pal);
    loadTexture(261, "metalt2_1", metalt2_1Bitmap, 64, 64, metalt2_1Pal);
    loadTexture(262, "metalt2_2", metalt2_2Bitmap, 64, 64, metalt2_2Pal);
    loadTexture(263, "metalt2_3", metalt2_3Bitmap, 64, 64, metalt2_3Pal);
    loadTexture(264, "metalt2_4", metalt2_4Bitmap, 64, 64, metalt2_4Pal);
    loadTexture(265, "metalt2_5", metalt2_5Bitmap, 64, 64, metalt2_5Pal);
    loadTexture(266, "metalt2_6", metalt2_6Bitmap, 64, 64, metalt2_6Pal);
    loadTexture(267, "metalt2_7", metalt2_7Bitmap, 64, 64, metalt2_7Pal);
    loadTexture(268, "metalt2_8", metalt2_8Bitmap, 64, 64, metalt2_8Pal);
    loadTexture(269, "metflor2_1", metflor2_1Bitmap, 64, 64, metflor2_1Pal);
    loadTexture(270, "mmetal1_1", mmetal1_1Bitmap, 64, 64, mmetal1_1Pal);
    loadTexture(271, "mmetal1_2", mmetal1_2Bitmap, 64, 64, mmetal1_2Pal);
    loadTexture(272, "mmetal1_3", mmetal1_3Bitmap, 64, 64, mmetal1_3Pal);
    loadTexture(273, "mmetal1_5", mmetal1_5Bitmap, 64, 64, mmetal1_5Pal);
    loadTexture(274, "mmetal1_6", mmetal1_6Bitmap, 64, 64, mmetal1_6Pal);
    loadTexture(275, "mmetal1_7", mmetal1_7Bitmap, 64, 64, mmetal1_7Pal);
    loadTexture(276, "mmetal1_8", mmetal1_8Bitmap, 64, 64, mmetal1_8Pal);
    loadTexture(277, "mswtch_2", mswtch_2Bitmap, 64, 64, mswtch_2Pal);
    loadTexture(278, "mswtch_3", mswtch_3Bitmap, 64, 64, mswtch_3Pal);
    loadTexture(279, "mswtch_4", mswtch_4Bitmap, 64, 64, mswtch_4Pal);
    loadTexture(280, "muh_bad", muh_badBitmap, 320, 192, muh_badPal);
    loadTexture(281, "nail0sid", nail0sidBitmap, 32, 32, nail0sidPal);
    loadTexture(282, "nail0top", nail0topBitmap, 32, 32, nail0topPal);
    loadTexture(283, "nail1sid", nail1sidBitmap, 32, 32, nail1sidPal);
    loadTexture(284, "nail1top", nail1topBitmap, 32, 32, nail1topPal);
    loadTexture(285, "nmetal2_1", nmetal2_1Bitmap, 64, 64, nmetal2_1Pal);
    loadTexture(286, "nmetal2_6", nmetal2_6Bitmap, 64, 64, nmetal2_6Pal);
    loadTexture(287, "plat_side1", plat_side1Bitmap, 64, 16, plat_side1Pal);
    loadTexture(288, "plat_stem", plat_stemBitmap, 16, 64, plat_stemPal);
    loadTexture(289, "plat_top1", plat_top1Bitmap, 64, 64, plat_top1Pal);
    loadTexture(290, "plat_top2", plat_top2Bitmap, 64, 64, plat_top2Pal);
    loadTexture(291, "quake", quakeBitmap, 288, 64, quakePal);
    loadTexture(292, "raven", ravenBitmap, 128, 144, ravenPal);
    loadTexture(293, "rock0sid", rock0sidBitmap, 32, 16, rock0sidPal);
    loadTexture(294, "rock1sid", rock1sidBitmap, 32, 16, rock1sidPal);
    loadTexture(295, "rock1_2", rock1_2Bitmap, 128, 128, rock1_2Pal);
    loadTexture(296, "rock3_2", rock3_2Bitmap, 64, 64, rock3_2Pal);
    loadTexture(297, "rock3_7", rock3_7Bitmap, 64, 64, rock3_7Pal);
    loadTexture(298, "rock3_8", rock3_8Bitmap, 64, 64, rock3_8Pal);
    loadTexture(299, "rock4_1", rock4_1Bitmap, 128, 128, rock4_1Pal);
    loadTexture(300, "rock4_2", rock4_2Bitmap, 128, 128, rock4_2Pal);
    loadTexture(301, "rock5_2", rock5_2Bitmap, 128, 128, rock5_2Pal);
    loadTexture(302, "rockettop", rockettopBitmap, 16, 16, rockettopPal);
    loadTexture(303, "rune1_1", rune1_1Bitmap, 32, 32, rune1_1Pal);
    loadTexture(304, "rune1_4", rune1_4Bitmap, 32, 32, rune1_4Pal);
    loadTexture(305, "rune1_5", rune1_5Bitmap, 32, 32, rune1_5Pal);
    loadTexture(306, "rune1_6", rune1_6Bitmap, 32, 32, rune1_6Pal);
    loadTexture(307, "rune1_7", rune1_7Bitmap, 32, 32, rune1_7Pal);
    loadTexture(308, "rune2_1", rune2_1Bitmap, 32, 32, rune2_1Pal);
    loadTexture(309, "rune2_2", rune2_2Bitmap, 32, 32, rune2_2Pal);
    loadTexture(310, "rune2_3", rune2_3Bitmap, 32, 32, rune2_3Pal);
    loadTexture(311, "rune2_4", rune2_4Bitmap, 32, 32, rune2_4Pal);
    loadTexture(312, "rune2_5", rune2_5Bitmap, 32, 32, rune2_5Pal);
    loadTexture(313, "rune_a", rune_aBitmap, 32, 32, rune_aPal);
    loadTexture(314, "sfloor1_2", sfloor1_2Bitmap, 64, 64, sfloor1_2Pal);
    loadTexture(315, "sfloor3_2", sfloor3_2Bitmap, 64, 64, sfloor3_2Pal);
    loadTexture(316, "sfloor4_1", sfloor4_1Bitmap, 64, 64, sfloor4_1Pal);
    loadTexture(317, "sfloor4_2", sfloor4_2Bitmap, 64, 64, sfloor4_2Pal);
    loadTexture(318, "sfloor4_4", sfloor4_4Bitmap, 64, 64, sfloor4_4Pal);
    loadTexture(319, "sfloor4_5", sfloor4_5Bitmap, 64, 64, sfloor4_5Pal);
    loadTexture(320, "sfloor4_6", sfloor4_6Bitmap, 64, 64, sfloor4_6Pal);
    loadTexture(321, "sfloor4_7", sfloor4_7Bitmap, 64, 64, sfloor4_7Pal);
    loadTexture(322, "sfloor4_8", sfloor4_8Bitmap, 64, 64, sfloor4_8Pal);
    loadTexture(323, "shot0sid", shot0sidBitmap, 32, 32, shot0sidPal);
    loadTexture(324, "shot0top", shot0topBitmap, 32, 32, shot0topPal);
    loadTexture(325, "shot1sid", shot1sidBitmap, 32, 32, shot1sidPal);
    loadTexture(326, "shot1top", shot1topBitmap, 32, 32, shot1topPal);
    loadTexture(327, "skill0", skill0Bitmap, 32, 96, skill0Pal);
    loadTexture(328, "skill1", skill1Bitmap, 32, 96, skill1Pal);
    loadTexture(329, "skill2", skill2Bitmap, 32, 96, skill2Pal);
    loadTexture(330, "skill3", skill3Bitmap, 32, 96, skill3Pal);
    loadTexture(331, "sky1", sky1Bitmap, 256, 128, sky1Pal);
    loadTexture(332, "sky4", sky4Bitmap, 256, 128, sky4Pal);
    loadTexture(333, "slip1", slip1Bitmap, 128, 192, slip1Pal);
    loadTexture(334, "slip2", slip2Bitmap, 64, 64, slip2Pal);
    loadTexture(335, "slipbotsd", slipbotsdBitmap, 16, 64, slipbotsdPal);
    loadTexture(336, "sliplite", slipliteBitmap, 16, 16, sliplitePal);
    loadTexture(337, "slipside", slipsideBitmap, 16, 16, slipsidePal);
    loadTexture(338, "sliptopsd", sliptopsdBitmap, 16, 64, sliptopsdPal);
    loadTexture(339, "stone1_3", stone1_3Bitmap, 64, 64, stone1_3Pal);
    loadTexture(340, "stone1_5", stone1_5Bitmap, 64, 64, stone1_5Pal);
    loadTexture(341, "stone1_7", stone1_7Bitmap, 64, 64, stone1_7Pal);
    loadTexture(342, "switch_1", switch_1Bitmap, 32, 32, switch_1Pal);
    loadTexture(343, "swtch1_1", swtch1_1Bitmap, 64, 64, swtch1_1Pal);
    loadTexture(344, "tech01_1", tech01_1Bitmap, 64, 64, tech01_1Pal);
    loadTexture(345, "tech01_2", tech01_2Bitmap, 64, 64, tech01_2Pal);
    loadTexture(346, "tech01_3", tech01_3Bitmap, 64, 64, tech01_3Pal);
    loadTexture(347, "tech01_5", tech01_5Bitmap, 64, 64, tech01_5Pal);
    loadTexture(348, "tech01_6", tech01_6Bitmap, 64, 64, tech01_6Pal);
    loadTexture(349, "tech01_7", tech01_7Bitmap, 64, 64, tech01_7Pal);
    loadTexture(350, "tech01_9", tech01_9Bitmap, 16, 64, tech01_9Pal);
    loadTexture(351, "tech02_1", tech02_1Bitmap, 64, 64, tech02_1Pal);
    loadTexture(352, "tech02_2", tech02_2Bitmap, 16, 64, tech02_2Pal);
    loadTexture(353, "tech02_3", tech02_3Bitmap, 16, 64, tech02_3Pal);
    loadTexture(354, "tech02_5", tech02_5Bitmap, 16, 64, tech02_5Pal);
    loadTexture(355, "tech02_6", tech02_6Bitmap, 16, 64, tech02_6Pal);
    loadTexture(356, "tech02_7", tech02_7Bitmap, 16, 64, tech02_7Pal);
    loadTexture(357, "tech03_1", tech03_1Bitmap, 128, 128, tech03_1Pal);
    loadTexture(358, "tech03_2", tech03_2Bitmap, 128, 128, tech03_2Pal);
    loadTexture(359, "tech04_1", tech04_1Bitmap, 128, 16, tech04_1Pal);
    loadTexture(360, "tech04_2", tech04_2Bitmap, 128, 16, tech04_2Pal);
    loadTexture(361, "tech04_3", tech04_3Bitmap, 16, 128, tech04_3Pal);
    loadTexture(362, "tech04_4", tech04_4Bitmap, 16, 128, tech04_4Pal);
    loadTexture(363, "tech04_5", tech04_5Bitmap, 128, 16, tech04_5Pal);
    loadTexture(364, "tech04_6", tech04_6Bitmap, 128, 16, tech04_6Pal);
    loadTexture(365, "tech04_7", tech04_7Bitmap, 16, 128, tech04_7Pal);
    loadTexture(366, "tech04_8", tech04_8Bitmap, 16, 128, tech04_8Pal);
    loadTexture(367, "tech05_1", tech05_1Bitmap, 128, 128, tech05_1Pal);
    loadTexture(368, "tech05_2", tech05_2Bitmap, 128, 128, tech05_2Pal);
    loadTexture(369, "tech06_1", tech06_1Bitmap, 128, 128, tech06_1Pal);
    loadTexture(370, "tech06_2", tech06_2Bitmap, 128, 128, tech06_2Pal);
    loadTexture(371, "tech07_1", tech07_1Bitmap, 128, 128, tech07_1Pal);
    loadTexture(372, "tech07_2", tech07_2Bitmap, 128, 128, tech07_2Pal);
    loadTexture(373, "tech08_1", tech08_1Bitmap, 128, 128, tech08_1Pal);
    loadTexture(374, "tech08_2", tech08_2Bitmap, 128, 128, tech08_2Pal);
    loadTexture(375, "tech09_3", tech09_3Bitmap, 128, 128, tech09_3Pal);
    loadTexture(376, "tech09_4", tech09_4Bitmap, 128, 128, tech09_4Pal);
    loadTexture(377, "tech10_1", tech10_1Bitmap, 128, 128, tech10_1Pal);
    loadTexture(378, "tech10_3", tech10_3Bitmap, 32, 128, tech10_3Pal);
    loadTexture(379, "tech11_1", tech11_1Bitmap, 128, 128, tech11_1Pal);
    loadTexture(380, "tech11_2", tech11_2Bitmap, 128, 128, tech11_2Pal);
    loadTexture(381, "tech12_1", tech12_1Bitmap, 128, 128, tech12_1Pal);
    loadTexture(382, "tech13_2", tech13_2Bitmap, 128, 128, tech13_2Pal);
    loadTexture(383, "tech14_1", tech14_1Bitmap, 128, 128, tech14_1Pal);
    loadTexture(384, "tech14_2", tech14_2Bitmap, 128, 128, tech14_2Pal);
    loadTexture(385, "tele_top", tele_topBitmap, 64, 64, tele_topPal);
    loadTexture(386, "tlight01", tlight01Bitmap, 32, 32, tlight01Pal);
    loadTexture(387, "tlight01_2", tlight01_2Bitmap, 32, 32, tlight01_2Pal);
    loadTexture(388, "tlight02", tlight02Bitmap, 64, 64, tlight02Pal);
    loadTexture(389, "tlight03", tlight03Bitmap, 32, 64, tlight03Pal);
    loadTexture(390, "tlight05", tlight05Bitmap, 32, 64, tlight05Pal);
    loadTexture(391, "tlight07", tlight07Bitmap, 32, 128, tlight07Pal);
    loadTexture(392, "tlight08", tlight08Bitmap, 32, 128, tlight08Pal);
    loadTexture(393, "tlight09", tlight09Bitmap, 32, 128, tlight09Pal);
    loadTexture(394, "tlight10", tlight10Bitmap, 64, 64, tlight10Pal);
    loadTexture(395, "tlight11", tlight11Bitmap, 16, 64, tlight11Pal);
    loadTexture(396, "trigger", triggerBitmap, 64, 64, triggerPal);
    loadTexture(397, "twall1_1", twall1_1Bitmap, 64, 128, twall1_1Pal);
    loadTexture(398, "twall1_2", twall1_2Bitmap, 64, 128, twall1_2Pal);
    loadTexture(399, "twall1_4", twall1_4Bitmap, 64, 64, twall1_4Pal);
    loadTexture(400, "twall2_1", twall2_1Bitmap, 64, 128, twall2_1Pal);
    loadTexture(401, "twall2_2", twall2_2Bitmap, 64, 128, twall2_2Pal);
    loadTexture(402, "twall2_3", twall2_3Bitmap, 64, 64, twall2_3Pal);
    loadTexture(403, "twall2_5", twall2_5Bitmap, 64, 64, twall2_5Pal);
    loadTexture(404, "twall2_6", twall2_6Bitmap, 64, 64, twall2_6Pal);
    loadTexture(405, "twall3_1", twall3_1Bitmap, 64, 128, twall3_1Pal);
    loadTexture(406, "twall5_1", twall5_1Bitmap, 128, 128, twall5_1Pal);
    loadTexture(407, "twall5_2", twall5_2Bitmap, 64, 64, twall5_2Pal);
    loadTexture(408, "twall5_3", twall5_3Bitmap, 64, 64, twall5_3Pal);
    loadTexture(409, "unwall1_8", unwall1_8Bitmap, 64, 64, unwall1_8Pal);
    loadTexture(410, "uwall1_2", uwall1_2Bitmap, 64, 64, uwall1_2Pal);
    loadTexture(411, "uwall1_3", uwall1_3Bitmap, 64, 64, uwall1_3Pal);
    loadTexture(412, "uwall1_4", uwall1_4Bitmap, 64, 64, uwall1_4Pal);
    loadTexture(413, "vine1_2", vine1_2Bitmap, 64, 64, vine1_2Pal);
    loadTexture(414, "wall11_2", wall11_2Bitmap, 64, 64, wall11_2Pal);
    loadTexture(415, "wall11_6", wall11_6Bitmap, 64, 64, wall11_6Pal);
    loadTexture(416, "wall14_5", wall14_5Bitmap, 64, 64, wall14_5Pal);
    loadTexture(417, "wall14_6", wall14_6Bitmap, 64, 64, wall14_6Pal);
    loadTexture(418, "wall16_7", wall16_7Bitmap, 64, 64, wall16_7Pal);
    loadTexture(419, "wall3_4", wall3_4Bitmap, 64, 64, wall3_4Pal);
    loadTexture(420, "wall5_4", wall5_4Bitmap, 64, 64, wall5_4Pal);
    loadTexture(421, "wall9_3", wall9_3Bitmap, 64, 64, wall9_3Pal);
    loadTexture(422, "wall9_8", wall9_8Bitmap, 64, 64, wall9_8Pal);
    loadTexture(423, "warch05", warch05Bitmap, 256, 128, warch05Pal);
    loadTexture(424, "wbrick1_4", wbrick1_4Bitmap, 64, 64, wbrick1_4Pal);
    loadTexture(425, "wbrick1_5", wbrick1_5Bitmap, 64, 64, wbrick1_5Pal);
    loadTexture(426, "wceiling4", wceiling4Bitmap, 64, 64, wceiling4Pal);
    loadTexture(427, "wceiling5", wceiling5Bitmap, 64, 64, wceiling5Pal);
    loadTexture(428, "wenter01", wenter01Bitmap, 240, 192, wenter01Pal);
    loadTexture(429, "wexit01", wexit01Bitmap, 240, 192, wexit01Pal);
    loadTexture(430, "wgrass1_1", wgrass1_1Bitmap, 64, 64, wgrass1_1Pal);
    loadTexture(431, "wgrnd1_5", wgrnd1_5Bitmap, 64, 64, wgrnd1_5Pal);
    loadTexture(432, "wgrnd1_6", wgrnd1_6Bitmap, 64, 64, wgrnd1_6Pal);
    loadTexture(433, "wgrnd1_8", wgrnd1_8Bitmap, 64, 64, wgrnd1_8Pal);
    loadTexture(434, "window01_1", window01_1Bitmap, 64, 192, window01_1Pal);
    loadTexture(435, "window01_2", window01_2Bitmap, 64, 192, window01_2Pal);
    loadTexture(436, "window01_3", window01_3Bitmap, 64, 192, window01_3Pal);
    loadTexture(437, "window01_4", window01_4Bitmap, 64, 192, window01_4Pal);
    loadTexture(438, "window02_1", window02_1Bitmap, 64, 192, window02_1Pal);
    loadTexture(439, "window03", window03Bitmap, 256, 192, window03Pal);
    loadTexture(440, "window1_2", window1_2Bitmap, 64, 64, window1_2Pal);
    loadTexture(441, "window1_3", window1_3Bitmap, 64, 64, window1_3Pal);
    loadTexture(442, "window1_4", window1_4Bitmap, 64, 64, window1_4Pal);
    loadTexture(443, "wiz1_1", wiz1_1Bitmap, 64, 64, wiz1_1Pal);
    loadTexture(444, "wiz1_4", wiz1_4Bitmap, 64, 64, wiz1_4Pal);
    loadTexture(445, "wizmet1_1", wizmet1_1Bitmap, 64, 64, wizmet1_1Pal);
    loadTexture(446, "wizmet1_2", wizmet1_2Bitmap, 64, 64, wizmet1_2Pal);
    loadTexture(447, "wizmet1_3", wizmet1_3Bitmap, 64, 64, wizmet1_3Pal);
    loadTexture(448, "wizmet1_4", wizmet1_4Bitmap, 64, 64, wizmet1_4Pal);
    loadTexture(449, "wizmet1_5", wizmet1_5Bitmap, 64, 64, wizmet1_5Pal);
    loadTexture(450, "wizmet1_6", wizmet1_6Bitmap, 64, 64, wizmet1_6Pal);
    loadTexture(451, "wizmet1_7", wizmet1_7Bitmap, 64, 64, wizmet1_7Pal);
    loadTexture(452, "wizmet1_8", wizmet1_8Bitmap, 64, 64, wizmet1_8Pal);
    loadTexture(453, "wizwin1_2", wizwin1_2Bitmap, 64, 64, wizwin1_2Pal);
    loadTexture(454, "wizwin1_8", wizwin1_8Bitmap, 64, 64, wizwin1_8Pal);
    loadTexture(455, "wizwood1_2", wizwood1_2Bitmap, 64, 64, wizwood1_2Pal);
    loadTexture(456, "wizwood1_3", wizwood1_3Bitmap, 64, 64, wizwood1_3Pal);
    loadTexture(457, "wizwood1_4", wizwood1_4Bitmap, 64, 64, wizwood1_4Pal);
    loadTexture(458, "wizwood1_5", wizwood1_5Bitmap, 64, 64, wizwood1_5Pal);
    loadTexture(459, "wizwood1_6", wizwood1_6Bitmap, 64, 64, wizwood1_6Pal);
    loadTexture(460, "wizwood1_7", wizwood1_7Bitmap, 64, 64, wizwood1_7Pal);
    loadTexture(461, "wizwood1_8", wizwood1_8Bitmap, 64, 64, wizwood1_8Pal);
    loadTexture(462, "wkey02_1", wkey02_1Bitmap, 32, 32, wkey02_1Pal);
    loadTexture(463, "wkey02_2", wkey02_2Bitmap, 32, 32, wkey02_2Pal);
    loadTexture(464, "wkey02_3", wkey02_3Bitmap, 64, 64, wkey02_3Pal);
    loadTexture(465, "wmet1_1", wmet1_1Bitmap, 64, 64, wmet1_1Pal);
    loadTexture(466, "wmet2_1", wmet2_1Bitmap, 64, 64, wmet2_1Pal);
    loadTexture(467, "wmet2_2", wmet2_2Bitmap, 64, 64, wmet2_2Pal);
    loadTexture(468, "wmet2_3", wmet2_3Bitmap, 64, 64, wmet2_3Pal);
    loadTexture(469, "wmet2_4", wmet2_4Bitmap, 64, 64, wmet2_4Pal);
    loadTexture(470, "wmet2_6", wmet2_6Bitmap, 64, 64, wmet2_6Pal);
    loadTexture(471, "wmet3_1", wmet3_1Bitmap, 64, 64, wmet3_1Pal);
    loadTexture(472, "wmet3_3", wmet3_3Bitmap, 64, 64, wmet3_3Pal);
    loadTexture(473, "wmet3_4", wmet3_4Bitmap, 64, 64, wmet3_4Pal);
    loadTexture(474, "wmet4_2", wmet4_2Bitmap, 64, 64, wmet4_2Pal);
    loadTexture(475, "wmet4_3", wmet4_3Bitmap, 64, 64, wmet4_3Pal);
    loadTexture(476, "wmet4_4", wmet4_4Bitmap, 64, 64, wmet4_4Pal);
    loadTexture(477, "wmet4_5", wmet4_5Bitmap, 64, 64, wmet4_5Pal);
    loadTexture(478, "wmet4_6", wmet4_6Bitmap, 64, 64, wmet4_6Pal);
    loadTexture(479, "wmet4_7", wmet4_7Bitmap, 64, 64, wmet4_7Pal);
    loadTexture(480, "wmet4_8", wmet4_8Bitmap, 64, 64, wmet4_8Pal);
    loadTexture(481, "wood1_1", wood1_1Bitmap, 64, 64, wood1_1Pal);
    loadTexture(482, "wood1_5", wood1_5Bitmap, 64, 64, wood1_5Pal);
    loadTexture(483, "wood1_7", wood1_7Bitmap, 64, 64, wood1_7Pal);
    loadTexture(484, "wood1_8", wood1_8Bitmap, 64, 64, wood1_8Pal);
    loadTexture(485, "woodflr1_2", woodflr1_2Bitmap, 64, 64, woodflr1_2Pal);
    loadTexture(486, "woodflr1_4", woodflr1_4Bitmap, 64, 64, woodflr1_4Pal);
    loadTexture(487, "woodflr1_5", woodflr1_5Bitmap, 64, 64, woodflr1_5Pal);
    loadTexture(488, "wswamp1_2", wswamp1_2Bitmap, 64, 64, wswamp1_2Pal);
    loadTexture(489, "wswamp1_4", wswamp1_4Bitmap, 64, 64, wswamp1_4Pal);
    loadTexture(490, "wswamp2_1", wswamp2_1Bitmap, 64, 64, wswamp2_1Pal);
    loadTexture(491, "wswamp2_2", wswamp2_2Bitmap, 64, 64, wswamp2_2Pal);
    loadTexture(492, "wswitch1", wswitch1Bitmap, 48, 48, wswitch1Pal);
    loadTexture(493, "wwall1_1", wwall1_1Bitmap, 64, 64, wwall1_1Pal);
    loadTexture(494, "wwood1_5", wwood1_5Bitmap, 64, 64, wwood1_5Pal);
    loadTexture(495, "wwood1_7", wwood1_7Bitmap, 64, 64, wwood1_7Pal);
    loadTexture(496, "z_exit", z_exitBitmap, 32, 32, z_exitPal);
}

// TODO: read texture pallete from palette data
// Note that texture memory must be set to VRAM_F_LCD/VRAM_G_LCD befor copying texture data
// and the bank must be reverted
void loadTexture(int texId, const char* name, const u8* data, int texSizeX, int texSizeY, const u16* palette) {
    glBindTexture(0, texId);

    paletteData[texId] = (u16*)palette;
    glColorTableEXT(0, 0, 256, 0, 0, palette);
    
    glTexImage2D(0, 0, GL_RGB256, texSizeX, texSizeY, 0,
                 0, (u8*)data);
    insertGLID(textureIDList, name, texId, 1);
}

int getTextureId(char * name) {
  return findGLID(textureIDList, name, 1);
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