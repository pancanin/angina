#ifndef SDL_GRAPHICS_TEXTURE_H_
#define SDL_GRAPHICS_TEXTURE_H_

#include <memory>

#include "SDL_render.h"
#include "SDL_image.h"

#include "enginev2/graphics/commons/primitives/Dimensions.h"
#include "enginev2/graphics/sdl/primitives/Rectangle.h"

struct SDL_Point;
struct TextureRendererComponent;

class Texture {
public:
	friend class TextureRendererComponent;

	Texture(std::shared_ptr<SDL_Texture>);
	Texture(std::shared_ptr<SDL_Texture>, Rectangle);
	~Texture();

	void setClip(const Rectangle&);
	void modulateColor(const Color&) const;
	void activateBlend() const;
	void setAlpha(uint8_t value) const;
	void rotateClockwise(double angle);
	void rotateCounterClockwise(double angle);
	void activateHFlip();
	void activateVFlip();
private:
	std::shared_ptr<SDL_Texture> texture;
	Dimensions dim;
	Rectangle clip;
	SDL_Point* center;
	double rotation;
	SDL_RendererFlip flip;
};

#endif /* SDL_GRAPHICS_TEXTURE_H_ */
