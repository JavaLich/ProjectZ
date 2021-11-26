#include "Entity.h"

#include "Common.h"
#include "Renderer.h"

#include <raylib.h>

void Entity::update(float delta) {}

void Entity::render() {
    Renderer::render_entity(
        Rectangle{bbox.x, bbox.y, bbox.width * SCALE, bbox.height * SCALE}, id);
}
