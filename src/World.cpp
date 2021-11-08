#include "World.h"
#include "raylib.h"

World::World() {
    Image img = LoadImage("assets/Tileset.png");
    tileset = LoadTextureFromImage(img);

    for (int y = 0; y < WORLD_SIZE; y++) {
        for (int x = 0; x < WORLD_SIZE; x++) {
            tiles[y][x] = x % 2;
        }
    }
}

World::~World() {}

void World::update(double delta) {}

void World::render() {
    for (int y = 0; y < WORLD_SIZE; y++) {
        for (int x = 0; x < WORLD_SIZE; x++) {
            DrawTextureRec(tileset,
                           Rectangle{(float)tiles[y][x].getID() * TILE_SIZE, 0,
                                     TILE_SIZE, TILE_SIZE},
                           Vector2{(float)x * TILE_SIZE, (float)y * TILE_SIZE},
                           WHITE);
        }
    }
}
