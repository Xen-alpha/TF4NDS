typedef struct {
    float x, y, z;
    float pitch, yaw;
} Camera;

void initCamera(Camera* cam); // cameraInit은 이미 blocksds에 정의되어 있으므로, initCamera로 이름 변경
void cameraUpdateView(Camera* cam);
void cameraMove(Camera* cam, float forward, float strafe);
void cameraTurn(Camera* cam, float deltaYaw, float deltaPitch);