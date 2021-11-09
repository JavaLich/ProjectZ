#include "Renderer.h"
#include "raylib.h"

Renderer::Renderer() {
    InitWindow(WIDTH, HEIGHT, TITLE);
    SetWindowState(FLAG_VSYNC_HINT);
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
