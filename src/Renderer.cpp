#include "Renderer.h"

Camera2D Renderer::cam{Vector2{WIDTH / 2.0}, Vector2{HEIGHT / 2.0}, 0.0, 1.0};

Texture2D Renderer::entity_sheet;
Texture2D Renderer::tile_sheet;

void Renderer::init() {
    InitWindow(WIDTH, HEIGHT, TITLE);
    SetWindowState(FLAG_VSYNC_HINT);
    SetTraceLogLevel(LOG_ALL);

    // Load assets
    entity_sheet = LoadTexture("assets/entity_sheet.png");
    tile_sheet = LoadTexture("assets/Tileset.png");
}

void Renderer::render_entity(Rectangle bbox, int32_t id) {
    int32_t spritex = id % (entity_sheet.width / ENTITY_BASE);
    int32_t spritey = id / (entity_sheet.width / ENTITY_BASE);
    DrawTexturePro(
        entity_sheet,
        Rectangle{(float)spritex, (float)spritey, ENTITY_BASE, ENTITY_BASE},
        Rectangle{bbox.x, bbox.y, bbox.width * SCALE, bbox.height * SCALE},
        Vector2{}, 0, WHITE);
}

void Renderer::render_tile(Rectangle bbox, int32_t id) {
    int32_t spritex = id % (tile_sheet.width / ENTITY_BASE);
    int32_t spritey = id / (tile_sheet.width / ENTITY_BASE);
    DrawTexturePro(
        tile_sheet,
        Rectangle{(float)spritex, (float)spritey, ENTITY_BASE, ENTITY_BASE},
        bbox, Vector2{}, 0, WHITE);
}

void Renderer::cleanup() { CloseWindow(); }
