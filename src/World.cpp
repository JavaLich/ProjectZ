#include "World.h"

World::World() {
    tileset = LoadTexture("assets/Tileset.png");
    set_width = tileset.width / TILE_PIXEL_SIZE;
    set_height = tileset.height / TILE_PIXEL_SIZE;

    for (int y = 0; y < WORLD_SIZE; y++) {
        for (int x = 0; x < WORLD_SIZE; x++) {
            level[y][x] = {x % 10};
        }
    }
}

World::~World() { UnloadTexture(tileset); }

void World::update(float delta) {}

void World::render(Camera2D& cam) {
    for (int y = 0; y < WORLD_SIZE; y++) {
        for (int x = 0; x < WORLD_SIZE; x++) {
            Vector2 worldPos{(float)x * TILE_SIZE, (float)y * TILE_SIZE};

            if (worldPos.x - cam.target.x + cam.offset.x < -TILE_SIZE ||
                worldPos.x - cam.target.x + cam.offset.x > WIDTH ||
                worldPos.y - cam.target.y + cam.offset.y < -TILE_SIZE ||
                worldPos.y - cam.target.y + cam.offset.y > HEIGHT)
                continue;

            int32_t id = level[y][x].id;

            uint32_t sheetX{id % set_width};
            uint32_t sheetY{id / set_width};

            Color tint{WHITE};

            /* DrawTextureRec(
                tileset,
                Rectangle{(float)sheetX * TILE_SIZE, (float)sheetY * TILE_SIZE,
                          TILE_SIZE, TILE_SIZE},
                worldPos, tint); */

            DrawTexturePro(
                tileset,
                Rectangle{(float)sheetX * TILE_SIZE, (float)sheetY * TILE_SIZE,
                          TILE_PIXEL_SIZE, TILE_PIXEL_SIZE},
                Rectangle{worldPos.x, worldPos.y, TILE_SIZE, TILE_SIZE},
                Vector2{}, 0, tint);
        }
    }
}
