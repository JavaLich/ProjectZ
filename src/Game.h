#include <SFML/Graphics.hpp>

class Game {
   public:
    Game();
    ~Game();
    void init();
    void run();
    void update();
    void render();

   private:
    sf::RenderWindow* window;

    double TARGET_FPS = 60.0f;
};
