#include "Renderer.h"
#include "Common.h"
#include "raylib.h"

Renderer::Renderer() {
    InitWindow(WIDTH, HEIGHT, TITLE);
    SetTargetFPS(TARGET_FPS);
    SetTraceLogLevel(LOG_ALL);
}

Renderer::~Renderer() { CloseWindow(); }

void Renderer::start() {
    BeginDrawing();
    BeginMode2D(cam);
    ClearBackground(BLACK);
}

void Renderer::end() {
    EndMode2D();
    EndDrawing();
}
