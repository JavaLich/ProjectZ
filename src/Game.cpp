#include "Game.h"

#include <raylib.h>

const uint16_t Game::WIDTH = 1280;
const uint16_t Game::HEIGHT = 720;
const std::string Game::TITLE = "Project Z";

Game::Game() {
    InitWindow(WIDTH, HEIGHT, TITLE.c_str());
    SetTargetFPS(60);
}

Game::~Game() { CloseWindow(); }

void Game::update(double delta) {}

void Game::render() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Congrats! You created your first window!", 190, 200, 20,
             LIGHTGRAY);
    EndDrawing();
}

void Game::run() {
    while (!WindowShouldClose()) {
        update(GetFrameTime());
        render();
    }
}
