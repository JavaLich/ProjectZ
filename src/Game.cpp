#include "Game.h"

#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>
#include <chrono>
#include <iostream>
#include <thread>

Game::Game() { init(); }
Game::~Game() { delete window; }

void Game::init() {
    window = new sf::RenderWindow(sf::VideoMode(1280, 960), "Project Z");
}

void Game::update() {}

void Game::render() {}

void Game::run() {
    auto target_frame_length(sf::seconds(1.0 / TARGET_FPS));

    uint32_t fps = 0;
    sf::Clock fpsTimer;

    sf::Clock clock;
    while (window->isOpen()) {
        auto delta = clock.getElapsedTime();

        sf::sleep(target_frame_length - delta);

        clock.restart();

        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) window->close();
        }

        update();
        render();

        window->clear();
        window->display();

        fps++;
        if (fpsTimer.getElapsedTime() > sf::seconds(1.0)) {
            std::cout << "FPS: " << fps << std::endl;
            sf::String title = "Project Z | FPS: ";
            title += fps;
            window->setTitle(title);

            fps = 0;
            fpsTimer.restart();
        }
    }
}
