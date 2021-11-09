#include "Renderer.h"

Renderer::Renderer() {
    InitWindow(WIDTH, HEIGHT, TITLE);
#ifdef VSYNC
    SetWindowState(FLAG_VSYNC_HINT);
#endif
    SetTraceLogLevel(LOG_ALL);
}

Renderer::~Renderer() { CloseWindow(); }
