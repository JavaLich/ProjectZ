#include <raylib.h>

#include "Common.h"
#include "raylib.h"

class Renderer {
   public:
    Renderer();
    ~Renderer();

    void start();
    void end();

    inline void moveCamera(Vector2 offset) {
        cam.target.x += offset.x;
        cam.target.y += offset.y;
    }

   private:
    Camera2D cam{Vector2{WIDTH / 2.0}, Vector2{HEIGHT / 2.0}, 0.0, 1.0};
};
