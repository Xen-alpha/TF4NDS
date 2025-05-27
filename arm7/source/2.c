/*********************************************************************************
 * Includes
 ********************************************************************************/
#include "mygba.h"
#include "math.h"
#include "timers.h"
#include "dma.h"
#include "keypad.h"
#include "fixed.h"
#include "..\bsp\model.h"
//#include "..\models\model.h"
/*********************************************************************************
 * Defines
 ********************************************************************************/
#define CASE(I) case I: AFFINE(i) ;

#define INNER_LOOP  \
for (; slen >= 16; slen -= 16) { \
  AFFINE( 0) AFFINE( 1) AFFINE( 2) AFFINE( 3) AFFINE( 4) AFFINE( 5) AFFINE( 6) AFFINE( 7) \
  AFFINE( 8) AFFINE( 9) AFFINE(10) AFFINE(11) AFFINE(12) AFFINE(13) AFFINE(14) AFFINE(15) \
} switch (slen) { \
  CASE(16) CASE(15) CASE(14) CASE(13) CASE(12) CASE(11) CASE(10) CASE( 9) \
  CASE( 8) CASE( 7) CASE( 6) CASE( 5) CASE( 4) CASE( 3) CASE( 2) CASE( 1) \
}
#define SPEED_TURN 19                                              // Turning Speed
#define SPEED 12                                                   // Moving Speed
/*********************************************************************************
 * Global Variables
 ********************************************************************************/
texture EWRAM textures[1];             // Textures Buffer
#define BACKBUFFER 0x10                                           //BackBuffer REG
#define BackBuffer (u16*)0x600A000                                //start of back buffer in Mode 5
#define FrontBuffer (u16*)0x6000000                               //
TVector3 degree;                       // Camera Degrees
TVector3 camera;                       // Camera Coordinates
s32 sina[361], cosa[361];              // Trigonometric Look-up tables
int count2 = 0;
int io=0;
char tot1;
/*********************************************************************************
 * Prototypes
 ********************************************************************************/
// Init
void IWRAM Init_3d(void);
inline void IWRAM lookup_tables(void);
inline void IWRAM Fps_Counter(void);
// Mode 3 Functions
inline void IWRAM DMACopy(void *src, void *dest, u32 count, u32 mode);
extern void Fill(void *, s16, s32);
inline void IWRAM Flip(void);
// 3D Clipping
inline IWRAM int polygon_clip(TVector3* , TVector3* , int );
// Camera Translation - rotation - Projection - Rendering
inline void  IWRAM Render_3D(void);
inline void IWRAM Camera_Move(void);
inline void IWRAM Rotate_Poly( obj_type *);
inline void IWRAM Project_2D(TVector3 *, int , int);
// Scan Convertion - Texture Mapper
inline void IWRAM Draw_Polygon(Polygon_2D *, int , int);


int tot;
/*********************************************************************************
 * Program entry point
 ********************************************************************************/
int  main(void)
{
   *(short*)0x4000000 = 0x405;                      //SetBG-Mode 5
   REG_BG2PA = 0;                                   //Rotated & Streched Mode 5
   REG_BG2PB = 256;                                 //Higher for Less HEIGHT, 256 = 160
   REG_BG2PC = 128;
   REG_BG2PD = 0;
   Init_3d();                                       // Initialize 3D
   REG_TM2CNT = TIME_FREQUENCY_256 | TIME_ENABLE;   // start timer for FPS counter
   REG_TM3CNT = TIME_OVERFLOW | TIME_ENABLE;        //

   while(1)
   {
     Camera_Move();                                 // Camera Input
     Render_3D();                                   // Render Frame
   }
}
/*********************************************************************************
 * 
 *FUNCTIONS
 ********************************************************************************/
 int nn=0;
 int df=0;
 char mon;
int nos,tot2,tot3,m;
void    IWRAM        bsp_visit_visible_leaves(TVector3 * cam_loc, dplane_t * pl);
int     IWRAM        bsp_find_visible_nodes(int node);
void    IWRAM        bsp_explore_node(int node);
void     IWRAM       mark_leaf_faces(int leaf);
int      IWRAM       visit_visible_leaves(TVector3 * cam_loc);
void       IWRAM     bsp_render_world(TVector3 * cam_loc, dplane_t * pl);
void        IWRAM    bsp_render_node(int node);
int      IWRAM       point_plane_test(TVector3 * loc, dplane_t  *plane);
void        IWRAM    render_node_faces(int node, int side);
int        IWRAM     find_leaf(TVector3 * loc);
void        IWRAM    draw_face(int face);
void       IWRAM     render_world(TVector3 * loc);
#define mark_face(x)     (vis_face[(x) >> 3] |=  (1 << ((x) & 7)))
#define is_marked(x)     (vis_face[(x) >> 3] &   (1 << ((x) & 7)))
#define unmark_face(x)   (vis_face[(x) >> 3] &= ~(1 << ((x) & 7)))
int col;
inline void IWRAM    Render_3D(void)
{
  //int l;
   nos=0;nn=0;
   col=1000;
  //Fill(BUFFER,766,8);
//  static int Frame;
//  if (Frame == frames_num-1) Frame=0;
 // obj_type_ptr obj_ptr = &Model[0][0];
  //for(l = 0; l < 400; l++) {count2=l;Rotate_Poly(obj_ptr++);}
  df=0;
  render_world(&camera);
   Fps_Counter();
 printnum(0,40,df);
  printnum(0,60,nn);
 // printnum(0,80,tot3);
//  printnum(0,100,m);
 // printnum(50,60,mo);
  //prints(0,0,&mon);
  //printnum(0,40,mod);
  Flip();
}


extern const int             nummodels;
extern const dmodel_t    dmodels[];

extern const int             visdatasize;
extern const byte            dvisdata[];

extern const int             lightdatasize;
extern const byte            dlightdata[];

extern const int             texdatasize;
extern const byte            dtexdata[];	// (dmiptexlump_t)

extern const int             entdatasize;
extern const char            dentdata[];

extern const int             numleafs;
extern const dleaf_t         dleafs[];

extern const int             numplanes;
extern const dplane_t        dplanes[];

extern const int             numvertexes;
extern const dvertex_t       dvertexes[];

extern const int             numnodes;
extern const dnode_t         dnodes[];

extern const int             numtexinfo;
extern const texinfo_t       texinfo[];

extern const int             numfaces;
extern const dface_t         dfaces[];

extern const int             numclipnodes;
extern const dclipnode_t     dclipnodes[];

extern const int             numedges;
extern const dedge_t         dedges[];

extern const int             nummarksurfaces;
extern const unsigned short   dmarksurfaces[];

extern const int             numsurfedges;
extern const int             dsurfedges[];
 char      EWRAM      vis_face[MAX_MAP_FACES / 8 + 1];//[MAX_MAP_FACES / 8 + 1];
 char      EWRAM      vis_leaf[MAX_MAP_LEAFS / 8 + 1];//[MAX_MAP_LEAFS / 8 + 1];
 char      EWRAM      vis_node[MAX_MAP_NODES];//[MAX_MAP_NODES];

//================================================================
int draw = 1;
TVector3 *loc;
dplane_t       *planes;
point_3d        pts[32], *default_vlist[32];
//vector         *loc;

// during a bsp recursion, draw all of the faces
// stored on this node which are visible (i.e. just
// test their mark flag)
//#define FLOAT_POSITIVE(x)   (* (int *) (x) >= 0)
//#else
#define FLOAT_POSITIVE(x)   ((x) >= 0)
//#endif

/*void            rotate_c2w(vector * dest, vector * src)
{
      vert_tmp[i].x =  (fixmul((obj->vertex[i].x - camera.x),cosa[degree.y]) - fixmul((obj->vertex[i].z - camera.z),sina[degree.y]));
      vert_tmp[i].y =  -(obj->vertex[i].y - camera.y);
      vert_tmp[i].z =  (fixmul((obj->vertex[i].x - camera.x),(sina[degree.y])) + fixmul((obj->vertex[i].z - camera.z),(cosa[degree.y])));
    dest->x = src->x * main_matrix[0][0]
	+ src->y * main_matrix[1][0]
	+ src->z * main_matrix[2][0];
    dest->y = src->x * main_matrix[0][1]
	+ src->y * main_matrix[1][1]
	+ src->z * main_matrix[2][1];
    dest->z = src->x * main_matrix[0][2]
	+ src->y * main_matrix[1][2]
	+ src->z * main_matrix[2][2];
}

void            rotate_vec(vector * item)
{
    vector          temp;
    temp = *item;
    rotate_c2w(item, &temp);
}
*/
void     IWRAM       compute_plane(dplane_t * plane, int x, int y, int z)
{
    vector          temp, temp2;
    temp2.x = x;
    temp2.y = -z;
    temp2.z = y;
   // rotate_c2w(&temp, &temp2);
    temp.x =  (fixmul((temp2.x ),cosa[degree.y]) - fixmul((temp2.z ),sina[degree.y]));
    temp.y =  temp2.y;//(fixmul((x ),(sina[degree.y])) + fixmul((z ),(cosa[degree.y])));
    temp.z =  (fixmul((temp2.x ),(sina[degree.y])) + fixmul((temp2.z ),(cosa[degree.y])));
    nn= temp.z;
    plane->normal[0] = temp.x;
    plane->normal[1] = temp.y;
    plane->normal[2] = temp.z;
    plane->dist =
	temp.x * camera.x + temp.y * camera.y + temp.z * camera.z;
}

void      IWRAM      compute_view_frustrum(dplane_t * planes)
{
    compute_plane(planes + 0, -1, 0, 1); //LEFT
    compute_plane(planes + 1, 1, 0, 1);  //RIGHT
    compute_plane(planes + 2, 0, 1, 1);  //TOP
    compute_plane(planes + 3, 0, -1, 1); //BUTTOM
    /*
    compute_plane(planes + 0, -1, 0, 1);
    compute_plane(planes + 1, 1, 0, 1);
    compute_plane(planes + 2, 0, 1, 1);
    compute_plane(planes + 3, 0, -1, 1);*/
}

int       IWRAM      bbox_inside_plane(short *mins, short *maxs, dplane_t * plane)
{
    int             i;
    short           pt[3];

    // use quick test from graphics gems
    
    for (i = 0; i < 3; ++i)
	if ((plane->normal[i])>=0)	// fast test assuming IEEE
	
	    pt[i] = maxs[i];
	else
	    pt[i] = mins[i];
    return plane->normal[0] * pt[0] + plane->normal[1] * pt[1]
	+ plane->normal[2] * pt[2] >= plane->dist;
}

int       IWRAM      node_in_frustrum(dnode_t * node, dplane_t * planes)
{
    if (!bbox_inside_plane(node->mins, node->maxs, planes + 0)
	|| !bbox_inside_plane(node->mins, node->maxs, planes + 1)
	|| !bbox_inside_plane(node->mins, node->maxs, planes + 2)
	|| !bbox_inside_plane(node->mins, node->maxs, planes + 3))
	return 0;
    return 1;
}

int       IWRAM      leaf_in_frustrum(dleaf_t * node, dplane_t * planes)
{
    if (!bbox_inside_plane(node->mins, node->maxs, planes + 0)
	|| !bbox_inside_plane(node->mins, node->maxs, planes + 1)
	|| !bbox_inside_plane(node->mins, node->maxs, planes + 2)
	|| !bbox_inside_plane(node->mins, node->maxs, planes + 3))
	return 0;
    return 1;
}

void       IWRAM     render_world(TVector3 * loc)
{
    dplane_t        planes[4];
  //  compute_view_frustrum(planes);

  //  if (!visit_visible_leaves(loc)) {
  //  	memset(vis_leaf, 255, sizeof(vis_leaf));
  //  }
  //  bsp_visit_visible_leaves(loc, planes);
    bsp_render_world(loc, planes);
}

int       IWRAM      visit_visible_leaves(TVector3 * cam_loc)
{
    int             n, v, i;

    memset(vis_leaf, 0, sizeof(vis_leaf));

    n = find_leaf(cam_loc);

    if (n == 0 || dleafs[n].visofs < 0)
	return 0;

    v = dleafs[n].visofs;
    for (i = 1; i < numleafs;) {
	if (dvisdata[v] == 0) {
	    i += dvisdata[v + 1] << 3;	// skip some leaves
	    v += 2;
	} else {
	    int             j;
	    for (j = 0; j < 8; j++, i++)
		if (dvisdata[v] & (1 << j))
		    vis_leaf[i >> 3] |= (1 << (i & 7));
	    ++v;
	}
    }
    return 1;
}

int node2;

void      IWRAM      draw_face(int face)
{
    int             n = dfaces[face].numedges,i;
    int             se = dfaces[face].firstedge;
//    int             i, codes_or = 0, codes_and = 0xff;
//    point_3d      **vlist;
//////////
  obj_type OutPoly;
//  int 		EdgeIdx;
  dvertex_t	vertex;
 /* int Edge;
  for( Edge = 0; Edge<_bspfaces[FaceNr].ledge_num; Edge++)
  {
    EdgeIdx = _bspedgesidx[_bspfaces[FaceNr].ledge_id+Edge];

	if(EdgeIdx>=0)
      Vertex = _bspvertices[_bspedges[EdgeIdx].v[0]];
    else
      Vertex = _bspvertices[_bspedges[-EdgeIdx].v[1]];
	
    OutPoly->vertex[Edge].x = Vertex.x;
    OutPoly->vertex[Edge].y = Vertex.z;
    OutPoly->vertex[Edge].z = Vertex.y;
  }

  OutPoly->dots = _bspfaces[FaceNr].ledge_num;
  OutPoly->Tex = 0;
*///////////
   for (i = 0; i < n; ++i) {
	int             edge = dsurfedges[se + i];
	if (edge < 0){
	    vertex=dvertexes[dedges[-edge].v[1]];
	    //transform_point(&pts[i], (vector *) VERTEX(dedges[-edge].v[1]));
                 }
	else{
	    vertex=dvertexes[dedges[edge].v[0]];
	   // transform_point(&pts[i], (vector *) VERTEX(dedges[edge].v[0]));
        }
    OutPoly.vertex[n-i].x = vertex.point[0];
    OutPoly.vertex[n-i].y = vertex.point[2];
    OutPoly.vertex[n-i].z = vertex.point[1];
    }
    OutPoly.vertex[0].x = vertex.point[0];
    OutPoly.vertex[0].y = vertex.point[2];
    OutPoly.vertex[0].z = vertex.point[1];
  OutPoly.dots = n+1;
  OutPoly.Tex = 0;
  
  int h = OutPoly.vertex[0].z - camera.z;
//  TVector3 V_vector;
//  int v[4];
/*  V_vector.x = OutPoly.vertex[0].x - camera.x;
  V_vector.y = OutPoly.vertex[0].y - camera.y;
  V_vector.z = OutPoly.vertex[0].z - camera.z;

  v[0] = dplanes[dnodes[node2].planenum].normal[0];
  v[1] = dplanes[dnodes[node2].planenum].normal[1];
  v[2] = dplanes[dnodes[node2].planenum].normal[2];
  bool b = ( f2i(V_vector.x*v[0]) +  f2i(-V_vector.y*v[2])+ f2i(V_vector.x*v[1]) )<0;*/
   // if(h<0) h=-h;
//    if((h<200) && (h>-200)){
      Rotate_Poly( &OutPoly);
      df+=1;
//   }
col += 1000;
//    if (codes_and)
//	return;
    // abort if poly outside frustrum

//    if (codes_or) {
	// poly crosses frustrum, so clip it
	//n = clip_poly(n, default_vlist, codes_or, &vlist);
//    } else
//	vlist = default_vlist;

/*    if (n) {
	bitmap          bm;
	float           u, v;
	int             tex;
	int             mip;

	tex = dfaces[face].texinfo;
*/
//	mip = compute_mip_level(face);
//	PlainPixelColor = (255 - tex % 255)&255;//rand() % 10;
//	get_tmap(&bm, face, texinfo[tex].miptex, mip, &u, &v);
//	qmap_set_texture(&bm);
//	compute_texture_gradients(face, tex, mip, u, v);
//	draw_poly(n, vlist);
 //   }
}

void       IWRAM     render_node_faces(int node, int side)
{
    int             i, n, f;
    n = dnodes[node].numfaces;
    f = dnodes[node].firstface;
    for (i = 0; i < n; ++i) {
	if (is_marked(f)) {
	    if (dfaces[f].side == side){	
        node2 = node;
		draw_face(f);
}
	    unmark_face(f);
	}
	++f;
    }
}


void      IWRAM      mark_leaf_faces(int leaf)
{
    int             n = dleafs[leaf].nummarksurfaces;
    int             ms = dleafs[leaf].firstmarksurface;
    int             i;
    for (i = 0; i < n; ++i) {
	int             s = dmarksurfaces[ms + i];
	if (!is_marked(s)) {
	    mark_face(s);
	}
    }
}

int        IWRAM     point_plane_test(TVector3 * loc, dplane_t * plane)
{
    return f2i(plane->normal[0] * loc->x) + f2i(plane->normal[2] * loc->y)
	+ f2i(plane->normal[1] * loc->z) < plane->dist;
}

int      IWRAM       find_leaf(TVector3 * loc)
{
    int             n = dmodels[0].headnode[0];
    while (n >= 0) {
	dnode_t        *node = &dnodes[n];
	n = node->children[point_plane_test(loc, &dplanes[node->planenum])];
    }
    return ~n;
}




void    IWRAM           bsp_render_node(int node)
{
	   // df+=1;
//	if(df<100){
 //   if (node >= 0 && vis_node[node]) {
    if (node >= 0) {
	if (point_plane_test(loc, &dplanes[dnodes[node].planenum])) {
	    bsp_render_node(dnodes[node].children[0]);
	    render_node_faces(node, 1);
	    bsp_render_node(dnodes[node].children[1]);
	} else {
	    bsp_render_node(dnodes[node].children[1]);
//	    df+=1;
	    render_node_faces(node, 0);
	    bsp_render_node(dnodes[node].children[0]);
	}
    }
// }
}

void      IWRAM      bsp_render_world(TVector3 * cam_loc, dplane_t * pl)
{
    planes = pl;
    loc = cam_loc;
    bsp_render_node((int) dmodels[0].headnode[0]);
}

// recursively determine which nodes need exploring (so we
// don't look for polygons on _every_ node in the level)
int      IWRAM       bsp_find_visible_nodes(int node)
{
    if (node >= 0) {
	vis_node[node] = !!(bsp_find_visible_nodes(dnodes[node].children[0])
			| bsp_find_visible_nodes(dnodes[node].children[1]));
	return vis_node[node];
    } else {
	node = ~node;
	return (vis_leaf[node >> 3] & (1 << (node & 7)));
    }
}



void       IWRAM     bsp_explore_node(int node)
{
    int k;
  //  df+=1;
    if (node < 0) {
      node = ~node;
	  if (vis_leaf[node >> 3] & (1 << (node & 7)))
	  {
	      if (leaf_in_frustrum(&dleafs[node], planes)) mark_leaf_faces(node);	
	      //mark_leaf_faces(node);

      }
	  return;
    }
    
    if (vis_node[node]) {
	  if (!node_in_frustrum(&dnodes[node], planes)) vis_node[node] = 0;
  // if(0>1) k=0;
	  else {
	    bsp_explore_node(dnodes[node].children[0]);
	    bsp_explore_node(dnodes[node].children[1]);
	  }
    }
}

void       IWRAM     bsp_visit_visible_leaves(TVector3 * cam_loc, dplane_t * pl)
{
    planes = pl;
    loc = cam_loc;
    bsp_find_visible_nodes((int) dmodels[0].headnode[0]);
    bsp_explore_node((int) dmodels[0].headnode[0]);
   // int i;
  //  for(i=0;i<4000;i++){
   //   df+=vis_leaf[i];
   // }
}









inline void IWRAM DMACopy(void *src, void *dest, u32 count, u32 mode)
{
  REG_DM3SAD = (u32)src;
  REG_DM3DAD = (u32)dest;
  REG_DM3CNT = count | mode;

  while(REG_DM3CNT_H & 0x8000);
}
int u=0;
inline void IWRAM Draw_Polygon(Polygon_2D *coord, int points, int color)
{
    int            i, miny = 999999<<16, maxy = -999999<<16, slen;
    int            lx, rx, ldx, rdx, lcount = 0, rcount = 0, srx, slx;
    int            top_index = 0, bottom_index = 0, ledge, redge;
    int            rep;
//    int        lt_zz,lt_z, rt_zz ,rt_z, z,zz;
    // Find top and bottom points
    for (i = 0; i < points; i++) {
       if ((coord->Point[i].y) < miny) {miny = (coord->Point[i].y); top_index = i;}
       if ((coord->Point[i].y) > maxy) {maxy = (coord->Point[i].y); bottom_index = i;}
    }
    if (maxy == miny) return;
    miny = F2I_Ceil(miny);
    maxy = F2I_Ceil(maxy);
    ledge = redge = top_index;
    for (; miny < maxy; miny++){
        // New left edge?
        if (--lcount <= 0) {
            if (ledge == bottom_index) return;
            if ((i = ledge + 1) >= points) i = 0;
            while ((lcount = F2I_Ceil(coord->Point[i].y) - F2I_Ceil(coord->Point[ledge].y)) <= 0) {
                if (i == bottom_index) return;
                ledge = i++;
                if (i == points) i = 0;

            }
            // Calculate edge gradients
            rep   = reciprocal[lcount];
            ldx   = (f2i(coord->Point[i].x - (lx   = coord->Point[ledge].x))*rep);
            ledge = i;
        }

        // New right edge?
        if (--rcount <= 0) {

            if (redge == bottom_index) return;
            if ((i = redge-1) < 0) i = points - 1;
            while ((rcount = F2I_Ceil(coord->Point[i].y) - F2I_Ceil(coord->Point[redge].y)) <= 0) {
                if (i == bottom_index) return;
                redge = i--;
                if (i < 0) i = points - 1;
            }
            // Calculate edge gradients
            rep   = reciprocal[rcount];
            rdx   = (f2i(coord->Point[i].x - (rx   = coord->Point[redge].x))*rep);
            redge = i;
        }
        slx = (F2I_Ceil(lx));
        srx = (F2I_Ceil(rx));
        u=0;
        if ((slen = (1 + (srx) - (slx))) > 0) {
           u16 *fb = &VideoBuffer[slx*160+ miny];
#define AFFINE(i) *fb = col; fb+=160; //skin[u];u++;
           INNER_LOOP;
#undef  AFFINE

        }
        lx += ldx; rx += rdx;
    }
}



inline IWRAM int polygon_clip(TVector3* dst, TVector3* src, int n)
{
    TVector3* start = dst;
    TVector3* pre;
    // Interate over all the vertices.
    for (pre = &src[n - 1]; n--; pre = src++)
    {
      // Include vertex if inside clipping plane.
      if (pre->d >= 0) *dst++ = *pre;
      // Clip polygon edge if split over clipping plane.
      if ((pre->d ^ src->d) < 0)
      {
        // Calculate the clipping reciprocal interpolation scale.
        int d = pre->d - src->d;
        int r = (d < 0 ? reciprocal[-d] * -pre->d : reciprocal[d] * pre->d);
        // Clip each of the edge vertex data.
        dst->x = pre->x + fixmul(src->x - pre->x, r);
        dst->y = pre->y + fixmul(src->y - pre->y, r);
        dst->z = pre->z + fixmul(src->z - pre->z, r);
//        dst->u = pre->u + fixmul(src->u - pre->u, r);
//       dst->v = pre->v + fixmul(src->v - pre->v, r);
        dst++;
      }
    }

  // Return the number of vertices in the clipped polygon.
  return dst - start;
}


inline void IWRAM Rotate_Poly(obj_type *obj)
{
    int i, n;
    TVector3 vert_tmp[(obj->dots) + 5];

    //Rotation

    for(i = 0; i < (n = obj->dots); i++)
    {

      vert_tmp[i].x =  (fixmul((obj->vertex[i].x - camera.x),cosa[degree.y]) - fixmul((obj->vertex[i].z - camera.z),sina[degree.y]));
      vert_tmp[i].y =  -(obj->vertex[i].y - camera.y);
      vert_tmp[i].z =  (fixmul((obj->vertex[i].x - camera.x),(sina[degree.y])) + fixmul((obj->vertex[i].z - camera.z),(cosa[degree.y])));
//      vert_tmp[i].u = obj->vertex[i].u+ add;
//      vert_tmp[i].v = obj->vertex[i].v ;
    }
   // Clip the polygon to the 4 frustum planes (View pyramid).
    TVector3 tm1[42], tm2[42];
    for (i = n; i--; vert_tmp[i].d = vert_tmp[i].x  + vert_tmp[i].z); n = polygon_clip(tm1, vert_tmp, n); // Left
    for (i = n; i--; tm1[i].d = tm1[i].z  - tm1[i].x); n = polygon_clip(tm2, tm1, n); // Right
    for (i = n; i--; tm2[i].d = tm2[i].y  + tm2[i].z); n = polygon_clip(tm1, tm2, n); // Top
    for (i = n; i--; tm1[i].d = tm1[i].z  - tm1[i].y); n = polygon_clip(tm2, tm1, n); // Bottom

    //Projection
    if (n > 2) Project_2D(tm2 , n, obj->Tex);
}

inline void IWRAM Project_2D(TVector3 *Clipped, int pts, int tex)
{
    int i;
    Polygon_2D Poly2D;
    for(i = 0 ; i < pts; i++)
    {
          int z = reciprocal[Clipped[i].z];
          Poly2D.Point[i].x = (((60 * Clipped[i].x*z)) + i2f(60));
          Poly2D.Point[i].y = (((80 * Clipped[i].y*z)) + i2f(80));
    }
   nos=pts;
     if (draw == 1) Draw_Polygon(&Poly2D, pts, 0);
}


void IWRAM Camera_Move(void)
{

	if(!((*KEYS) & KEY_UP))
	{
	  camera.x += f2i(SPEED * (sina[degree.y]));
	  camera.z += f2i(SPEED * (cosa[degree.y]));		
	  (*KEYS) |= KEY_UP;      
	}
	
	if(!((*KEYS) & KEY_DOWN))
	{
	  camera.x -= f2i(SPEED * (sina[degree.y]));
	  camera.z -= f2i(SPEED * (cosa[degree.y]));		
	  (*KEYS) |= KEY_DOWN;
	}
	
	if(!((*KEYS) & KEY_LEFT))
	{
      degree.y -= SPEED_TURN;
      if (degree.y > 359) degree.y = 0;
      if (degree.y < 0) degree.y = 360;
	  (*KEYS) |= KEY_LEFT;
	}
	
	if(!((*KEYS) & KEY_RIGHT))
	{
      degree.y += SPEED_TURN;
      if (degree.y > 359) degree.y = 0;
      if (degree.y < 0) degree.y = 360;
	  (*KEYS) |= KEY_RIGHT;
	}
	
	if(!((*KEYS) & KEY_A))
	{
	  camera.y -= 15;
	  (*KEYS) |= KEY_A;
	}
	
	if(!((*KEYS) & KEY_B))
	{
	  camera.y += 15;
	  (*KEYS) |= KEY_B;
	}
	
	if(!((*KEYS) & KEY_R))
	{
	    draw=1;
      degree.x -= 3;
      if (degree.x > 359) degree.x = 0;
      if (degree.x < 0) degree.x = 360;
	  (*KEYS) |= KEY_R;
	}
	
	if(!((*KEYS) & KEY_L))
	{
	    draw=0;
      degree.x += 3;
      if (degree.x > 359) degree.x = 0;
      if (degree.x < 0) degree.x = 360;
	  (*KEYS) |= KEY_L;
	}
}

inline void IWRAM Flip(void)
{
        if(REG_DISPCNT & BACKBUFFER)        //back buffer is the current buffer so we need to switch it to the front buffer
        {
                REG_DISPCNT &= ~BACKBUFFER; //flip active buffer to front buffer by clearing back buffer bit
                VideoBuffer = BackBuffer;   //now we point our drawing buffer to the back buffer
                Fill(BackBuffer,900,4);     //Asm Clear-Screen Function
        }

        else                                //front buffer is active so switch it to backbuffer
        {
                REG_DISPCNT |= BACKBUFFER;  //flip active buffer to back buffer by setting back buffer bit
                VideoBuffer = FrontBuffer;  //now we point our drawing buffer to the front buffer
                Fill(FrontBuffer,900,4);    //Asm Clear-Screen Function
        }
}


void IWRAM Init_3d(void)
{
   //Camera Coordinates
   camera.x = 0;
   camera.y = 0;
   camera.z = 0;

   //Camera Degrees
   degree.x = 0;
   degree.y = 180;
   degree.z = 0;
   
   //Textures Setup
   int xx,yy;
   for(yy=0;yy<256;yy++){
       for(xx=0;xx<256;xx++){
           textures[0][xx][yy] = skin[256*yy+xx];}} //tech

   //Init LookUp Tables
   lookup_tables();
}

void IWRAM build_normals(void)
{
//  int i;
//  TVector3 temp;
/*  for(i=0; i < 400; i++)
  {
   // get_normal(&temp, Model[0][i].vertex[2], Model[0][i].vertex[1], Model[0][i].vertex[0] );
    normals[i] = temp;
  }*/
}

inline IWRAM void lookup_tables(void)
{
    int i;
    //Trigonometric Tables
    for(i=0; i < 362 ; i++)
      {
        sina[i]=(int)(sin(i*pi/180)*(FIXED_ONE));
        cosa[i]=(int)(cos(i*pi/180)*(FIXED_ONE));
      }
    //Init Normals
    build_normals();
}

