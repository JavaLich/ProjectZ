#include "Game.h"

#include <raylib.h>

const std::string Game::TITLE = "Project Z";

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
    InitWindow(WIDTH, HEIGHT, TITLE.c_str());
    SetTargetFPS(TARGET_FPS);
    SetTraceLogLevel(LOG_ALL);

    world = new World();
}

Game::~Game() {
    delete world;

    CloseWindow();
}

void Game::update(double delta) { updateFPSDisplay(); }

void Game::render() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    world->render();

    EndDrawing();
}

void Game::run() {
    while (!WindowShouldClose()) {
        update(GetFrameTime());
        render();
    }
}
