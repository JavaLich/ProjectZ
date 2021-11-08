#pragma once

#include <cstdint>
#include <string>

class Game {
   public:
    Game();
    ~Game();

    void run();

    void update(double delta);
    void render();

   private:
    static const uint16_t WIDTH;
    static const uint16_t HEIGHT;
    static const std::string TITLE;
};
