#ifndef SDL_COMPONENTS_WINDOW_H_
#define SDL_COMPONENTS_WINDOW_H_

#include <string>

#include "renderer/primitives/Point.h"
#include "renderer/primitives/Dimensions.h"

struct SDL_Window;
struct Surface;

/**
 * Wrapper around SDL_Window.
 * Manages initialization and destruction of window and it's surface.
 */
class Window {
public:
	Window(std::string title, Point pos, Dimensions dimensions, int32_t flags);
	~Window();

	Window(const Window& other) = delete;
	Window& operator=(const Window& other) = delete;
	Window(Window&& other) = delete;
	Window& operator=(Window&& other) = delete;

	SDL_Window* getWindow();
	Surface& getSurface();
private:
	SDL_Window* window;
	Surface* surface;
};


#endif /* SDL_COMPONENTS_WINDOW_H_ */