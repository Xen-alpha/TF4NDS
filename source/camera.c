#include <nds.h>
#include <camera.h>
#include <math.h>

void initCamera(Camera* cam) {
    cam->x = 0; cam->y = 1.5; cam->z = 0;
    cam->pitch = 0;
    cam->yaw = 0;
}

void cameraUpdateView(Camera* cam) {
    float cosPitch = cosf(cam->pitch);
    float sinPitch = sinf(cam->pitch);
    float cosYaw = cosf(cam->yaw);
    float sinYaw = sinf(cam->yaw);

    float dx = cosYaw * cosPitch;
    float dy = sinPitch;
    float dz = -sinYaw * cosPitch;

    gluLookAt(
        cam->x, cam->y, cam->z,
        cam->x + dx, cam->y + dy, cam->z + dz,
        0.0f, 1.0f, 0.0f
    );
}

void cameraMove(Camera* cam, float forward, float strafe) {
    cam->x += forward * cosf(cam->yaw) + strafe * sinf(cam->yaw);
    cam->z += forward * -sinf(cam->yaw) + strafe * cosf(cam->yaw);
}

void cameraTurn(Camera* cam, float deltaYaw, float deltaPitch) {
    cam->yaw += deltaYaw;
    cam->pitch += deltaPitch;

    if (cam->pitch > 1.5f) cam->pitch = 1.5f;
    if (cam->pitch < -1.5f) cam->pitch = -1.5f;
}