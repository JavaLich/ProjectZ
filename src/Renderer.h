#include <raylib.h>

class Renderer {
   public:
    Renderer();
    ~Renderer();

    void start();
    void end();

    inline void moveCamera(Vector2 offset) {
        cam.offset.x += offset.x;
        cam.offset.y += offset.y;
    }

   private:
    Camera2D cam{Vector2{}, Vector2{}, 0.0, 1.0};
};
