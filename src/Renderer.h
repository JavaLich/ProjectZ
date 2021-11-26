#pragma once

#include <cstdint>

#include <raylib.h>

#include "Common.h"
#include "Entity.h"

class Renderer {
   public:
    Renderer();
    ~Renderer();

    static void init();
    static void cleanup();

    static inline void start() {
        BeginDrawing();
        ClearBackground(BLACK);
    }
    static inline void end() { EndDrawing(); }

    static inline void begin_camera_mode() { BeginMode2D(cam); }
    static inline void end_camera_mode() { EndMode2D(); }
    static inline void move_camera(Vector2 offset) {
        cam.target.x += offset.x;
        cam.target.y += offset.y;
    }
    static inline void set_camera_pos(Vector2 pos) { cam.target = pos; }

    static void render_entity(Rectangle bbox, int32_t id);
    static void render_tile(Rectangle bbox, int32_t id);

    static inline bool is_in_screen(const Rectangle& rect) {
        return rect.x - cam.target.x + cam.offset.x < -rect.width ||
               rect.x - cam.target.x + cam.offset.x > WIDTH ||
               rect.y - cam.target.y + cam.offset.y < -rect.height ||
               rect.y - cam.target.y + cam.offset.y > HEIGHT;
    }

    static inline Camera2D& get_camera() { return cam; }

   private:
    static Camera2D cam;

    static Texture2D entity_sheet;
    static Texture2D tile_sheet;
};
