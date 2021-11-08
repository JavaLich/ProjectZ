#pragma once

#include <cstdint>
#include <string>

#include "World.h"

class Game {
   public:
    Game();
    ~Game();

    void run();

    static const uint16_t WIDTH{800};
    static const uint16_t HEIGHT{600};
    static const uint16_t TARGET_FPS{60};
    static const std::string TITLE;

   private:
    void update(double delta);
    void render();

    World* world;
};
