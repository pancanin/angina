#include "SurfaceRepository.h"

#include "platform/sdl/primitives/Surface.h"

#include "platform/sdl/resource-loader/ResourceLoader.h"

Surface& SurfaceRepository::get(const std::string& resourcePath) {
    Surface* surface = nullptr;

    if (surfaceCache.exists(resourcePath)) {
        surface = &surfaceCache.get(resourcePath);
    } else {
        surfaceCache.add(resourcePath, *new Surface(ResourceLoader::loadImage(resourcePath)));
    }

    return *surface;
}
