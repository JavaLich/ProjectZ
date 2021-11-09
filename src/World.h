#pragma once

#include <cstdint>
#include <tuple>
#include <unordered_map>

#include <raylib.h>

#include "Common.h"

#define WORLD_SIZE 128
#define TILE_PIXEL_SIZE 8
#define TILE_SIZE (TILE_PIXEL_SIZE * SCALE)

// TODO: Make world chunked. Only load nearby chunks into memory.

struct Tile {
    int32_t id;
};

class World {
   public:
    World();
    ~World();

    inline Tile getTile(uint32_t x, uint32_t y) { return level[x][y]; }

    void update(float delta);
    void render(Camera2D& cam);

   private:
    Tile level[WORLD_SIZE][WORLD_SIZE]{};
    Tile background[WORLD_SIZE][WORLD_SIZE]{};
    Tile foreground[WORLD_SIZE][WORLD_SIZE]{};

    Texture tileset;
    uint32_t set_width;
    uint32_t set_height;
};
