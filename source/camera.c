#include <camera.h>
#include <nds.h>

void loadCamera() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70, 256.0 / 192.0, 0.1, 100.0);
  gluLookAt(0.0, 0.0, 2.0,  // Position
            0.0, 0.0, 0.0,  // Look at
            0.0, 1.0, 0.0); // Up    
}