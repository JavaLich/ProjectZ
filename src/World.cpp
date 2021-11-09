#include "World.h"
#include "external/jar_mod.h"
#include "raylib.h"

World::World() {
    tileset = LoadTexture("assets/Tileset.png");
    set_width = tileset.width / TILE_SIZE;
    set_height = tileset.height / TILE_SIZE;

    for (int y = 0; y < WORLD_SIZE; y++) {
        for (int x = 0; x < WORLD_SIZE; x++) {
            tiles[y][x] = x % 10;
        }
    }
}

World::~World() { UnloadTexture(tileset); }

void World::update(float delta) {}

void World::render() {
    for (int y = 0; y < WORLD_SIZE; y++) {
        for (int x = 0; x < WORLD_SIZE; x++) {
            Vector2 worldPos{(float)x * TILE_SIZE, (float)y * TILE_SIZE};

            int32_t id = tiles[y][x].getID();

            uint32_t sheetX{id % set_width};
            uint32_t sheetY{id / set_width};

            Color tint{WHITE};

            DrawTextureRec(
                tileset,
                Rectangle{(float)sheetX * TILE_SIZE, (float)sheetY * TILE_SIZE,
                          TILE_SIZE, TILE_SIZE},
                worldPos, tint);
        }
    }
}
