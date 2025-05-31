// BSP에서 추출한 단순화된 구조체들

typedef struct {
    fixed12d3 x, y, z;
} Vertex;

typedef struct {
    unsigned short v[2];  // 2개의 정점 인덱스 (edge용)
} Edge;

typedef struct {
    int edge_id;  // edge 배열의 인덱스
} FaceEdge;

typedef struct {
    int first_edge;   // face에 해당하는 edge 시작 위치
    short num_edges;  // face를 구성하는 edge 수
    short plane_id;   // (생략 가능)
    char side;
    char tex_id;
} Face;

void renderBSPFaces();