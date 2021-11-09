#pragma once

#include <cstdint>

#include <raylib.h>

#include "Common.h"

#define WORLD_SIZE 256
#define TILE_PIXEL_SIZE 8
#define TILE_SIZE (TILE_PIXEL_SIZE * SCALE)

class Tile {
   public:
    Tile(int32_t id) : id(id) {}
    Tile() : id(0) {}
    ~Tile() {}

    inline int32_t getID() { return id; }

   private:
    int32_t id{};
};

class World {
   public:
    World();
    ~World();

    inline Tile getTile(uint32_t x, uint32_t y) { return tiles[x][y]; }

    void update(float delta);
    void render(Camera2D& cam);

   private:
    Tile tiles[WORLD_SIZE][WORLD_SIZE]{};

    Texture tileset;
    uint32_t set_width;
    uint32_t set_height;
};
