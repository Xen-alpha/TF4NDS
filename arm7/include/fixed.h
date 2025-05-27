#include "struct.h"
#define FIXED_BITS 16                                             //16 Bits for Fixed-Integers
#define f2i(A) ((A) >> FIXED_BITS)                                //Fixed to Integer
#define i2f(A) ((A) << FIXED_BITS)                                //Integer to Fixed
#define fixdiv(A,B) (i2f(A)/(B))                                  //Divide Fixed-Point
#define fixmul(A,B) f2i((A)*(B))                                  //Multiplication Fixed-Point
#define fixmul2(A,B) (((A))*((B)))                                  //Multiplication Fixed-Point
#define fixmul3(A,B) F2I_Ceil((A)*(B))                               //Multiplication Fixed-Point
#define FIXED_ONE (1<<FIXED_BITS)                                 //Fixed One
#define F2I_Ceil(x) (((x) + FIXED_ONE - 1) >> FIXED_BITS)
#define fixup(A) f2i((A) + FIXCEIL)
#define FIXCEIL 0xFF
#define FIXED_MASK (0xFFFFFFFF >> (32-FIXED_BITS))
#define pi 3.1415926535897932385                                  // Pi
#define ABS(a) (((a)<0)?(-(a)):(a))
#define SGN(x) ((!(x))?(0):(((x)<0)?(-1):(1)))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a>b)?(a):(b))
#define FIX_Ceil(x) (((x) + FIXED_ONE - 1) )
#define fixup(A) f2i((A) + FIXCEIL)

/*
** Name: isqrt
** Desc: Integer square root. Take the square root of an integer.
*/
inline IWRAM int isqrt(int value)
{
  int root = 0;

#define STEP(shift) \
    if((0x40000000 >> shift) + root <= value)          \
    {                                                   \
        value -= (0x40000000 >> shift) + root;          \
        root = (root >> 1) | (0x40000000 >> shift);     \
    }                                                   \
    else                                                \
    {                                                   \
        root >>= 1;                                     \
    }

  STEP( 0); STEP( 2); STEP( 4); STEP( 6);
  STEP( 8); STEP(10); STEP(12); STEP(14);
  STEP(16); STEP(18); STEP(20); STEP(22);
  STEP(24); STEP(26); STEP(28); STEP(30);

  // round to the nearest integer, cuts max error in half

  if (root < value) root++;

  return root;
}



//ProtoTypes
inline int IWRAM dot(TVector3 , TVector3 );
inline IWRAM void cross(TVector3 *, TVector3 , TVector3 );
inline IWRAM void normalize(TVector3 *);
void IWRAM get_normal(TVector3 *, TVector3 , TVector3 , TVector3 );

//Functions

inline int IWRAM dot(TVector3 v1, TVector3 v2)
{
    return (f2i(v1.x * v2.x) + f2i(v1.y * v2.y) + f2i(v1.z * v2.z));
}

inline IWRAM void cross(TVector3 *v, TVector3 v1, TVector3 v2)
{
   v->x = (v1.y * v2.z) - (v2.y * v1.z);
   v->y = (v1.z * v2.x) - (v2.z * v1.x);
   v->z = (v1.x * v2.y) - (v2.x * v1.y);
}

inline IWRAM void normalize2(TVector3 *n)
{
   float length=sqrt(n->x*n->x + n->y*n->y + n->z*n->z);
   float x,y, z;
   if(length==0) return;
   x = (float)n->x/length;
   y = (float)n->y/length;
   z = (float)n->z/length;
   n->x = x*(FIXED_ONE);
   n->y = y*(FIXED_ONE);
   n->z = z*(FIXED_ONE);
}

inline IWRAM void normalize(TVector3 *n)
{
   int length=reciprocal[isqrt(ABS(n->x*n->x) + ABS(n->y*n->y) + ABS(n->z*n->z))];
   int x,y, z;
   if(length==0) return;
   x = n->x*length;
   y = n->y*length;
   z = n->z*length;
   n->x = x;
   n->y = y;
   n->z = z;
 //  n->d = (float)length*(1<<16);
}


void IWRAM get_normal(TVector3 *n, TVector3 p1, TVector3 p2, TVector3 p3)
{
   TVector3 v1, v2;

   v1.x=p1.x-p2.x; v1.y=p1.y-p2.y; v1.z=p1.z-p2.z;
   v2.x=p3.x-p2.x; v2.y=p3.y-p2.y; v2.z=p3.z-p2.z;

   cross(n, v2, v1);

   //normalize(n);
}


/*
Subject 5.05: How do I find the intersection of a line and a plane?

    If the plane is defined as:

        a*x + b*y + c*z + d = 0

    and the line is defined as:

        x = x1 + (x2 - x1)*t = x1 + i*t
        y = y1 + (y2 - y1)*t = y1 + j*t
        z = z1 + (z2 - z1)*t = z1 + k*t

    Then just substitute these into the plane equation. You end up
    with:

        t = - (a*x1 + b*y1 + c*z1 + d)/(a*i + b*j + c*k)

    When the denominator is zero, the line is contained in the plane
    if the numerator is also zero (the point at t=0 satisfies the
    plane equation), otherwise the line is parallel to the plane.


----------------------------------------------------------------------
Subject 5.06: How do I determine the intersection between a ray and a triangle?

    First find the intersection between the ray and the plane in which
    the triangle is situated. Then see if the point of intersection is
    inside the triangle.
    Details may be found in [O'Rourke (C)] pp.226-238, whose code is at
       http://cs.smith.edu/~orourke/ .
    Efficient code complete with statistical tests is described in the Mo:ller-
    Trumbore paper in J. Graphics Tools (C code downloadable from there):
       http://www.acm.org/jgt/papers/MollerTrumbore97/
    See also the full paper:
       http://www.Graphics.Cornell.EDU/pubs/1997/MT97.html
    See also the "3D Object Intersection" page, described in Subject 0.05.


----------------------------------------------------------------------
*/
