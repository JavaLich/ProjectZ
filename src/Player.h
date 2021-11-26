#pragma once

#include "Entity.h"

class Player : Entity {
   public:
    Player() : Entity(0, 0, 8, 8, 0) {}
    ~Player() {}

    void update(float delta);

   private:
    float speed = 100.0;
};
