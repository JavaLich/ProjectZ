#include "Renderer.h"
#include "raylib.h"

Camera2D Renderer::cam{Vector2{WIDTH / 2.0}, Vector2{HEIGHT / 2.0}, 0.0, 1.0};

void Renderer::init() {
    InitWindow(WIDTH, HEIGHT, TITLE);
    SetWindowState(FLAG_VSYNC_HINT);
    SetTraceLogLevel(LOG_ALL);
}

void Renderer::cleanup() { CloseWindow(); }
