#ifndef ENGINEV2_GRAPHICS_ANIMATION_SPRITE_H
#define ENGINEV2_GRAPHICS_ANIMATION_SPRITE_H

#include <memory>
#include <vector>
#include <cstdint>

#include "enginev2/graphics/sdl/primitives/Texture.h"
#include "enginev2/graphics/sdl/primitives/Rectangle.h"

class SpriteAnimator;

class Sprite {
public:
	friend class SpriteAnimator;

	Sprite() = default;
	Sprite(std::shared_ptr<Texture>, const std::vector<Rectangle>&, uint64_t animationTime);
private:
	std::shared_ptr<Texture> texturePtr;
	std::vector<Rectangle> frames;
	uint64_t animationTime;
	uint8_t currentFrame;
};

#endif // !ENGINEV2_GRAPHICS_ANIMATION_SPRITE_H
