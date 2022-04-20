#include "GameObject.h"

#include "enginev2/graphics/sdl/primitives/Texture.h"

GameObject::GameObject(const Point& position, SDL_Texture& texture): pos(position), tx(new Texture(&texture)) {}

GameObject::~GameObject() {
    if (tx != nullptr) {
        delete tx;
        tx = nullptr;
    }
}
