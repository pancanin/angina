/*
 * Transformer.h
 *
 *  Created on: Oct 22, 2021
 *      Author: ubuntu
 */

#ifndef SDL_COMPONENTS_TRANSFORMER_H_
#define SDL_COMPONENTS_TRANSFORMER_H_

#include <vector>

struct Texture;
struct Renderer;
struct Surface;

namespace Transformer {
	Texture* transformSurfaceToTexture(Renderer& renderer, Surface& surface);
	std::vector<Texture*> transformSurfacesToTextures(Renderer* renderer, const std::vector<Surface*>& surfaces);
}


#endif /* SDL_COMPONENTS_TRANSFORMER_H_ */