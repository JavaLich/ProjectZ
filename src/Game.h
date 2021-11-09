#pragma once

#include <cstdint>
#include <string>

#include "Common.h"
#include "Renderer.h"
#include "World.h"

class Game {
   public:
    Game();
    ~Game();

    void run();

   private:
    void update(float delta);
    void render();

    World* world;
    Renderer* renderer;
};
