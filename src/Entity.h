#pragma once

#include <cstdint>

#include <raylib.h>

#define ENTITY_BASE 8

class Entity {
   public:
    Entity();
    Entity(float x, float y, float width, float height, int32_t id)
        : bbox(Rectangle{x, y, width, height}), id(id) {}
    ~Entity() {}

    virtual void update(float delta);
    virtual void render();

    inline Rectangle get_bbox() { return bbox; }
    inline int32_t get_id() { return id; }

   protected:
    Rectangle bbox;

    int32_t id;
};
