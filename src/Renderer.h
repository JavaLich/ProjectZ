#include <raylib.h>

#include "Common.h"
#include "raylib.h"

class Renderer {
   public:
    Renderer();
    ~Renderer();

    inline void start() {
        BeginDrawing();
        ClearBackground(BLACK);
    }
    inline void end() { EndDrawing(); }

    inline void begin_camera_mode() { BeginMode2D(cam); }
    inline void end_camera_mode() { EndMode2D(); }
    inline void move_camera(Vector2 offset) {
        cam.target.x += offset.x;
        cam.target.y += offset.y;
    }

    inline Camera2D& get_camera() { return cam; }

   private:
    Camera2D cam{Vector2{WIDTH / 2.0}, Vector2{HEIGHT / 2.0}, 0.0, 1.0};
};
