#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include <raylib.h>

#include "Common.h"
#include "Entity.h"
#include "Player.h"

#define CHUNK_SIZE 8
#define WORLD_SIZE 16
#define TILE_PIXEL_SIZE 8
#define TILE_SIZE (TILE_PIXEL_SIZE * SCALE)

// TODO: Make world chunked. Only load nearby chunks into memory.

enum TileProperties { FOREGROUND, BACKGROUND, SOLID };

class Tile {
   public:
    Tile(uint32_t id, TileProperties properties)
        : id(id), properties(properties) {}
    Tile() : id(0), properties(FOREGROUND) {}

    uint32_t id;
    TileProperties properties;
};

class World {
   public:
    World();
    World(std::string tileset_file);
    ~World();

    inline Tile getTile(uint32_t x, uint32_t y) { return level[x][y]; }

    void update(float delta);
    void render();

    void load_level(std::string filename);

   private:
    Tile level[WORLD_SIZE][WORLD_SIZE]{};

    Player player;

    Texture tileset;
    uint32_t set_width;
    uint32_t set_height;
};
