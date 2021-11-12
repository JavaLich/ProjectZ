#include "Game.h"

#include <raylib.h>

std::shared_ptr<Game> Game::instance;

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
    Renderer::init();
    world = std::make_unique<World>();
}

Game::~Game() {}

void Game::init() { instance = std::make_shared<Game>(); }
void Game::cleanup() {
    TraceLog(LOG_DEBUG, "Cleaning up...");
    Renderer::cleanup();
}

void Game::update(float delta) {
    updateFPSDisplay();

    if (IsKeyDown(KEY_D)) {
        Renderer::move_camera(Vector2{100.0f * delta, 0.0});
    }
    if (IsKeyDown(KEY_A)) {
        Renderer::move_camera(Vector2{-100.0f * delta, 0.0});
    }
    if (IsKeyDown(KEY_S)) {
        Renderer::move_camera(Vector2{0.0, 100.0f * delta});
    }
    if (IsKeyDown(KEY_W)) {
        Renderer::move_camera(Vector2{0.0, -100.0f * delta});
    }
}

void Game::render() {
    Renderer::start();

    // GUI stuff goes here

    Renderer::begin_camera_mode();

    world->render();

    Renderer::end_camera_mode();

    Renderer::end();
}

void Game::run() {
    while (!WindowShouldClose()) {
        instance->update(GetFrameTime());
        instance->render();
    }
}
