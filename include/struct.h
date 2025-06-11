/*********************************************************************************
 * Structures
 * Originally written by Randy Linden
 * Modified by Xen-alpha
 ********************************************************************************/
#pragma once
#include <nds.h>

//==================================
// Structures for Entities, Polygons, Vectors, etc.
typedef struct TVector3               // 3D Vector
{
   int x, y, z,u, v, d;
   
}TVector3;

typedef struct Polygon_2D{
    TVector3 Point[7];                // Projected 2D Triangle Results
    char pts_num;                      // Number of Points in Object
} Polygon_2D;

typedef struct{
    int Tex;                          // Texture ID
    char dots;                         // Number of Points in Object
    TVector3 vertex[7];               // Object Vertices
    char type;
    //TVector3 Normal;                  // Object Vertices
} obj_type, *obj_type_ptr;

typedef struct{
    int Tex;                          // Texture ID
    char dots;                         // Number of Points in Object
    TVector3 vertex[3];               // Object Vertices
    TVector3 Normal;                  // Object Vertices
} obj_type_MD2;


typedef struct {
    char           *bits;
    int             wid;
    int             ht;

    char	    flag;
    char            *name; // added -�
    long            texture_id; // index of Mip Texture : added -�
} bitmap;

typedef unsigned char byte;

typedef int     fix;

#define fix_int(x)        ((x) >> 16)
#define float_to_fix(x)   ((fix) ((x) * 65536))
#define fix_cint(x)       (((x)+65535) >> 16)
//#define fix_floor(x)      ((x) & 0xffff0000)
//#define fix_ceil(x)       fix_floor((x)+0xffff)
#define fix_make(a,b)     (((a) << 16) + (b))


typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned short fixang;
typedef unsigned short ushort;
//typedef int     bool;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef long    int32;

#define FALSE 0
#define TRUE  1

//#define BIG_NUM     	((float) (1 << 26) * (1 << 26) * 1.5)

#define fatal(s)   	fatal_error(s, __FILE__, __LINE__)


typedef struct {
    int           x, y, z;
} vector;

typedef struct {
    v16          tx, ty, tz;
} angvec;

typedef struct {
    vector          p;
    uchar           ccodes;
    uchar           pad0, pad1, pad2;
    fix             sx, sy;
    float           u, v;
} point_3d;			// 32 bytes

#define CC_OFF_LEFT 	1
#define CC_OFF_RIGHT 	2
#define CC_OFF_TOP 	4
#define CC_OFF_BOT 	8
#define CC_BEHIND 	16


// upper design bounds

#define   MAX_MAP_HULLS      	4
#define   MAX_MAP_MODELS      	256
#define   MAX_MAP_BRUSHES      	4096
#define   MAX_MAP_ENTITIES   	1024
#define   MAX_MAP_ENTSTRING   	65536
#define   MAX_MAP_PLANES      	8192

//
// my values  (<- Sean? -�)
//
// will crash on large levels like E4M? stg - Benny
// but is mandatory for Nintendo DS because of memory constraints and max renderable triangle count in each frame
// (Nintendo DS has only 4MB of RAM, so we need to reduce the size of the BSP file)
// (and the BSP file is not used for rendering, but only for collision detection and visibility culling)
// (the BSP file is used to create a list of polygons that are rendered in the 3D engine)
// (finally, NDS only renders 2048 triangles in each frame, so we need to reduce the size of the BSP file) - Xen-alpha

#define   MAX_MAP_NODES      	10000
#define   MAX_MAP_CLIPNODES  	10000
#define   MAX_MAP_LEAFS      	10001
#define   MAX_MAP_VERTS      	30000
#define   MAX_MAP_FACES      	30000
#define   MAX_MAP_MARKSURFACES 	30000
#define   MAX_MAP_TEXINFO      	4096
#define   MAX_MAP_EDGES      	100000
#define   MAX_MAP_SURFEDGES   	200000
#define   MAX_MAP_MIPTEX      	0x100000	// 1M
#define   MAX_MAP_LIGHTING   	0x100000	// 1M
#define   MAX_MAP_VISIBILITY   	0x100000	// 1M


// key / value pair sizes

#define   MAX_KEY      32
#define   MAX_VALUE   1024

//=================================
// BSP file format definitions
//=================================


#define BSPVERSION   29
// #define MAX_TEXTURES 256 // libnds.h가 이미 정의하고 있음

typedef struct {
    int            offset, length;
} lump_t;

// lump types
// these are the lumps that are stored in the BSP file
// lumps are the basic building blocks of the BSP file
// each lump is a collection of data that is used by the BSP file like entities,
// planes, textures, vertexes, visibility, nodes, texinfo, faces, lighting,
// clipnodes, leafs, marksurfaces, edges, surfedges and models
#define   LUMP_ENTITIES   	0
#define   LUMP_PLANES      	1
#define   LUMP_TEXTURES   	2
#define   LUMP_VERTEXES   	3
#define   LUMP_VISIBILITY   	4
#define   LUMP_NODES      	5
#define   LUMP_TEXINFO   	6
#define   LUMP_FACES      	7
#define   LUMP_LIGHTING   	8
#define   LUMP_CLIPNODES   	9
#define   LUMP_LEAFS      	10
#define   LUMP_MARKSURFACES 	11
#define   LUMP_EDGES      	12
#define   LUMP_SURFEDGES   	13
#define   LUMP_MODELS      	14

#define   HEADER_LUMPS   15

typedef struct {
    float           mins[3], maxs[3];
    float           origin[3];
    int             headNode[MAX_MAP_HULLS];
    int             visleafs;	// not including the solid leaf 0

    int             firstface, numfaces;
} dmodel_t;

typedef struct {
    int             version;
    lump_t          lumps[HEADER_LUMPS];
} dheader_t;

typedef struct {
    int             nummiptex;
    int             dataofs[4];	// [nummiptex]
} dmiptexlump_t;

#define   MIPLEVELS   4
typedef struct {
  long numtextures;	// number of textures in the lump
  long dataofs[4];	// offsets to the miptex data for each mip level
} miptexheader_t;

typedef struct miptex_s {
    char            name[16];
    unsigned int        width, height;
    unsigned int        offsets[MIPLEVELS];		// four mip maps stored
} miptex_t;

typedef struct {
    float           x;
    float           y;
    float           z;
} dvertex_t;


// 0-2 are axial planes
#define   PLANE_X         0
#define   PLANE_Y         1
#define   PLANE_Z         2

// 3-5 are non-axial planes snapped to the nearest
#define   PLANE_ANYX      3
#define   PLANE_ANYY      4
#define   PLANE_ANYZ      5

typedef struct {
    float           normal[3]; //float
    float           dist;      //float
    int             type;// PLANE_X - PLANE_ANYZ ?remove? trivial to regenerate

} dplane_t;


// !!! if this is changed, it must be changed in asm_i386.h too !!!
typedef struct {
    int             planeIndex;	// The plane in which the node lies
    short           children[2];// negative numbers are -(leafs+1), not nodes
    // unsigned short?
    short           mins[3];	// for sphere culling
    // unsigned short?
    short           maxs[3];
    unsigned short  firstface; // unsigned short?
    unsigned short  numfaces;	// counting both sides, unsigned short?
} dnode_t;

typedef struct {
    int             planenum;
    short           children[2];	// negative numbers are contents
} dclipnode_t;


typedef struct texinfo_s {
    float           vecs[2][4];	// [s/t][xyz offset]
    int             miptex;// Index of Mip Texture
    int             flags; //animated: 0 for ordinary textures, 1 for water
} texinfo_t;

#define TEX_SPECIAL   1		// sky or slime, no lightmap or 256 subdivision

// note that edge 0 is never used, because negative edge nums are used for
// counterclockwise use of the edge in a face
typedef struct {
    unsigned short  v[2];	// vertex numbers
} dedge_t;

#define   MAXLIGHTMAPS   4
typedef struct {
    short           planenum;   // The plane in which the face lies
    short           side;	// 0 if in front of the plane, 1 if behind the plane

    long             firstEdge;  // first edge in the List of edges

    short           numEdges;   // number of edges in the List of edges
    short           texInfo;    // index of the Texture info the face is part of
    // lighting info
//    byte            styles[MAXLIGHTMAPS];
    unsigned char typelight;            // type of lighting, for the face
    unsigned char baselight;            // from 0xFF (dark) to 0 (bright)
    unsigned char light[2];             // two additional light models
    long             lightofs;
	       // Pointer inside the general lightmap, or -1
	       // defines the start of the face lightmap
    // start of [numstyles*surfsize] samples
} dface_t;


// contents;	// type of leaf
#define   CONTENTS_EMPTY      	-1
#define   CONTENTS_SOLID      	-2
#define   CONTENTS_WATER      	-3
#define   CONTENTS_SLIME      	-4
#define   CONTENTS_LAVA      	-5
#define   CONTENTS_SKY      	-6

// ambient_level[NUM_AMBIENTS]; // level of the four ambient sounds
#define   AMBIENT_WATER   	0
#define   AMBIENT_SKY      	1
#define   AMBIENT_SLIME   	2
#define   AMBIENT_LAVA   	3

#define   NUM_AMBIENTS          4	// automatic ambient sounds

// The BSP tree leaves are children of BSP tree Nodes and
// indicate which faces are contained inside a BSP tree leaf.

// leaf 0 is the generic CONTENTS_SOLID leaf, used for all solid areas
// all other leafs need visibility info
typedef struct {
    unsigned short  firstMarkSurface; // First item of the list of faces
    unsigned short  numMarkSurfaces;  // Number of faces in the leaf

    int             contents;	// type of leaf
    int             visofs;	// -1 = no visibility info

    short           mins[3];	// Bounding box of the leaf.
    short           maxs[3];	// for frustum culling

    

    byte            ambient_level[NUM_AMBIENTS];
    // level of the four ambient sounds
} dleaf_t;

/*
The first leaf (index 0) is always totally solid, so that in the BSP tree
nodes, a value of zero points to a solid leaf (i.e. a leaf that need not be
rendered).

The BSP tree leaf contains a reference to a set of consecutive entries in
the list of faces.

The bounding box must contain all the faces in the leaf.

The leaf contains an index to the Visibility Lists that describe which
other leaves are visible from that leaf.
If this index is -1, then all the other leaves are visible.

The tree leaves are the Quake equivalent of the sectors in DOOM. You can
imagine them as rooms, or part of rooms, where the monsters, players and
object will be placed.

Actually the tree leaves are the equivalent of the Sub Sectors: each sector
in DOOM is decomposed by the BSP into smaller and simpler convex sub
sectors, that contain only part of the sector lines.

Technically, each tree leaf, made of some faces and bound by the BSP node
split lines, appears in 3-D space as a convex polytope.*/

//==============================

typedef struct {
    float minU, minV;
    int w, h;
} lightmap_info_t;

//==============================

// bsp information structure
typedef struct {
    dplane_t* planes;
    int numPlanes;

    dmodel_t* models;
    int numModels;

    dnode_t* nodes;
    int numNodes;

    dleaf_t* leafs;
    int numLeafs;

    int numVertices;
    dvertex_t* vertices;

    int numEdges;
    dedge_t* edges;

    int numSurfEdges;
    int* surfEdges;

    int32_t* markSurfaces;
    int numMarkSurfaces;

    int numFaces;
    dface_t* faces;

    int numTexInfos;
    texinfo_t* texinfos;

    // Texture storage(preset: MAX_TEXTURES = 256)
    int texDataLength;
    unsigned char* textureData;     // DS VRAM 주소
    
    int numTextures;
    miptex_t **textures;

    byte* lightData;
    int lightDataSize;
} dmap_t;