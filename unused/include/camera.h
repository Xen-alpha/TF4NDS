typedef struct {
    float x, y, z;
    int velocity; // 카메라 이동 속도
    int turnSpeed; // 카메라 회전 속도
    float pitch, yaw;

    bool onGround; // 카메라가 땅에 닿아 있는지 여부
    bool isMoving; // 카메라가 이동 중인지 여부
} Camera;

void initCamera(Camera* cam); // cameraInit은 이미 blocksds에 정의되어 있으므로, initCamera로 이름 변경
void cameraUpdateView(Camera* cam);
void cameraMove(Camera* cam, float forward, float strafe);
void cameraTurn(Camera* cam, float deltaYaw, float deltaPitch);