#include"CAMERA.h"
#include"PLANE.h"
void gmain() {
    window(1920, 1080, full);
    hideCursor();
    CAMERA camera;//view
    MODEL::proj.pers(0.5f, width / height, 1, 100);
    MODEL::lightPos.set(0.0f, 0.0f, 1.0f);

    while (notQuit) {
        camera.update();
        clear(60);
    }
}
