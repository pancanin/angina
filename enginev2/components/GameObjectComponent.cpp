#include "GameObjectComponent.h"

#include "enginev2/graphics/sdl/renderer/TextureLoaderComponent.h"

GameObjectComponent::GameObjectComponent(): PrimitivesComponent(1000), txLoader(nullptr) {}

void GameObjectComponent::init(TextureLoaderComponent& txLoader) {
    this->txLoader = &txLoader;
}

void GameObjectComponent::loadGameObject(const std::string& textureResourcePath, const Point& point) {
    SDL_Texture* tx = txLoader->loadTexture(textureResourcePath);
    data.emplace_back(point, *tx);
}
