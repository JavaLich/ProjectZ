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

    if (IsKeyDown(KEY_D)) {
        renderer->move_camera(Vector2{100.0f * delta, 0.0});
    }
    if (IsKeyDown(KEY_A)) {
        renderer->move_camera(Vector2{-100.0f * delta, 0.0});
    }
    if (IsKeyDown(KEY_S)) {
        renderer->move_camera(Vector2{0.0, 100.0f * delta});
    }
    if (IsKeyDown(KEY_W)) {
        renderer->move_camera(Vector2{0.0, -100.0f * delta});
    }
}

void Game::render() {
    renderer->start();

    // GUI stuff goes here

    renderer->begin_camera_mode();

    world->render(renderer->get_camera());

    renderer->end_camera_mode();

    renderer->end();
}

void Game::run() {
    while (!WindowShouldClose()) {
        update(GetFrameTime());
        render();
    }
}
