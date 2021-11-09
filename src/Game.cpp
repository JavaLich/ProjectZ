#include "Game.h"

#include <raylib.h>

void updateFPSDisplay() {
#ifndef NDEBUG
    static double timer = 0.0f;
    timer += GetFrameTime();
    if (timer >= 1.0f) {
        timer = 0;

        std::string title = "Project Z | FPS: ";
        title += GetFPS();

        SetWindowTitle(title.c_str());

        TraceLog(LOG_INFO, "Frametime: %f", GetFrameTime());
    }
#endif
}

Game::Game() {
    renderer = new Renderer();
    world = new World();
}

Game::~Game() {
    delete world;
    delete renderer;
}

void Game::update(float delta) {
    updateFPSDisplay();

    renderer->moveCamera(Vector2{100.0f * delta, 0.0});
}

void Game::render() {
    renderer->start();

    world->render();

    renderer->end();
}

void Game::run() {
    while (!WindowShouldClose()) {
        update(GetFrameTime());
        render();
    }
}
