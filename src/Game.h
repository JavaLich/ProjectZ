#pragma once

#include <cstdint>
#include <memory>
#include <string>

#include "Common.h"
#include "Renderer.h"
#include "World.h"

class Game {
   public:
    Game();
    ~Game();

    static void init();
    static void run();
    static void cleanup();

    inline static std::shared_ptr<Game> get() { return instance; }

   private:
    void update(float delta);
    void render();

    static std::shared_ptr<Game> instance;

    std::shared_ptr<World> world;
};
