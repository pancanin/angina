#include "TextureRendererComponent.h"

#include "SDL_render.h"
#include "SDL_shape.h"

#include "enginev2/graphics/sdl/window/Window.h"
#include "enginev2/graphics/sdl/primitives/Texture.h"
#include "enginev2/graphics/commons/primitives/Color.h"
#include "enginev2/graphics/commons/primitives/Point.h"
#include "enginev2/graphics/commons/primitives/Pixel.h"
#include "enginev2/graphics/commons/primitives/Line.h"
#include "enginev2/graphics/animation/Sprite.h"
#include "enginev2/graphics/sdl/primitives/Rectangle.h"
#include "enginev2/models/GameObject.h"

void TextureRendererComponent::init(Window& window) {
	// TODO: These hard-coded values should be made easily configurable.
	renderer = SDL_CreateRenderer( window.sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
}

void TextureRendererComponent::clear() {
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
}

void TextureRendererComponent::render(Texture& texture) {
    SDL_Rect dest{0, 0, texture.dim.w, texture.dim.h};
    SDL_RenderCopyEx(renderer, texture.texture, nullptr, &dest, texture.rotation, nullptr, texture.flip);
}

void TextureRendererComponent::render(GameObject& obj) {
    SDL_Rect dest{obj.pos.x, obj.pos.y, obj.tx->dim.w, obj.tx->dim.h};
    //SDL_RenderCopy(renderer, obj.tx->texture, &obj.tx->clip.rect, &dest);
}

void TextureRendererComponent::render(Texture& texture, Rectangle& viewPort) {
	SDL_RenderSetViewport(renderer, &viewPort.rect);
	render(texture);
}

void TextureRendererComponent::render(Rectangle& rect) {
	 SDL_SetRenderDrawColor(renderer, rect.color.red, rect.color.green, rect.color.blue, rect.color.alpha);

	 if (rect.fill) {
		 SDL_RenderFillRect(renderer, &rect.rect);
	 } else {
		 SDL_RenderDrawRect(renderer, &rect.rect);
	 }
}

void TextureRendererComponent::render(Pixel& pixel) {
	SDL_SetRenderDrawColor(renderer, pixel.color.red, pixel.color.green, pixel.color.blue, pixel.color.alpha);
	SDL_RenderDrawPoint(renderer, pixel.position.x, pixel.position.y);
}

void TextureRendererComponent::render(Line& line) {
	SDL_SetRenderDrawColor(renderer, line.color.red, line.color.green, line.color.blue, line.color.alpha);
	SDL_RenderDrawLine(renderer, line.a.x, line.a.y, line.b.x, line.b.y);
}

void TextureRendererComponent::render(Sprite& sprite)
{
	SDL_Rect dest{ 0, 0, sprite.atlas->dim.w, sprite.atlas->dim.h };
	
	SDL_RenderCopyEx(renderer, sprite.atlas->texture, nullptr, &dest, sprite.atlas->texture.rotation, nullptr, sprite.atlas->texture.flip);
}

void TextureRendererComponent::update() {
	SDL_RenderPresent(renderer);
}

SDL_Renderer* TextureRendererComponent::get() const
{
	return renderer;
}

TextureRendererComponent::~TextureRendererComponent() {
	SDL_DestroyRenderer(renderer);
}
