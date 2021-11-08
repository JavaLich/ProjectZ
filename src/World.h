#pragma once

#include <cstdint>

#include <raylib.h>

#define WORLD_SIZE 32
#define TILE_SIZE 32

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

    void update(double delta);
    void render();

   private:
    Tile tiles[WORLD_SIZE][WORLD_SIZE]{};

    Texture tileset;
    uint32_t set_width;
    uint32_t set_height;
};
