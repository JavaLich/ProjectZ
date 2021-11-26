#include "Player.h"

void Player::update(float delta) {
    if (IsKeyDown(KEY_D)) {
        bbox.x += speed * delta;
    }
    if (IsKeyDown(KEY_A)) {
        bbox.x -= speed * delta;
    }
    if (IsKeyDown(KEY_S)) {
        bbox.y += speed * delta;
    }
    if (IsKeyDown(KEY_W)) {
        bbox.y -= speed * delta;
    }
}
