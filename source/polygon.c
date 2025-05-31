#include <stdio.h>
#include <stdlib.h>
#include <nds.h>
#include "polygon.h"

extern Vertex* vertices;
extern Edge* edges;
extern int* surfEdges;   // 음수: 반전된 edge
extern Face* faces;
extern int numFaces;

void renderBSPFaces() {
    for (int i = 0; i < numFaces; i++) {
        Face* f = &faces[i];

        glBegin(GL_TRIANGLES);  // DS는 GL_TRIANGLES 권장, GL_POLYGON도 됨

        for (int e = 0; e < f->num_edges; e++) {
            int surfEdgeIndex = surfEdges[f->first_edge + e];
            int edgeIndex = abs(surfEdgeIndex);
            int vertexIndex;

            if (surfEdgeIndex >= 0)
                vertexIndex = edges[edgeIndex].v[0];
            else
                vertexIndex = edges[edgeIndex].v[1];

            Vertex v = vertices[vertexIndex];
            glVertex3f(v.x, v.y, v.z);
        }

        glEnd();
    }
}
