#ifndef ENGINEV2_GRAPHICS_COMMONS_PRIMITIVES_PIXEL_H_
#define ENGINEV2_GRAPHICS_COMMONS_PRIMITIVES_PIXEL_H_

#include "enginev2/graphics/commons/primitives/Point.h"
#include "enginev2/graphics/commons/primitives/Color.h"

struct TextureRendererComponent;

class Pixel {
public:
	friend class TextureRendererComponent;

	Pixel(const Point&, const Color&);
private:
	Point position;
	Color color;
};

#endif /* ENGINEV2_GRAPHICS_COMMONS_PRIMITIVES_PIXEL_H_ */
