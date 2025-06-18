// 단순화된 구조체들
// BSP와 엔티티가 공유 예정

typedef struct {
    float x, y, z;  // 정점 좌표
    float u, v;     // 텍스처 좌표
    float nx, ny, nz; // 법선 벡터
} Vertex;

typedef struct {
    int first_edge;   // face에 해당하는 edge 시작 위치
    short num_edges;  // face를 구성하는 edge 수
    short plane_id;   // (생략 가능)
    char side;
    char tex_id;
} Face;
