#ifndef SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_
#define SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_

#include <string>
#include <functional>

#include "renderer/primitives/Point.h"
#include "renderer/shapes/Rect.h"
#include "renderer/primitives/Color.h"


struct Renderer;
struct Object;
struct RectTextButton;
struct Font;
struct Text;

class GraphicsFactory {
public:
	GraphicsFactory(Renderer&);
	virtual ~GraphicsFactory();

	virtual Object* createObject(const std::string& resourcePath, Point, Dimensions);

	virtual Text* createText(std::string text, Font&, Point, Dimensions, Color color = Color::NONE);

	// We will not cache buttons for now as they are static.
	RectTextButton* createButton(Point, Dimensions, Color backgroundColor, Color textColor, std::string text, Font&, std::function<void(void)>);
private:
	Renderer& renderer;
};

#endif /* SDL_ENGINE_FACTORY_GRAPHICSFACTORY_H_ */
