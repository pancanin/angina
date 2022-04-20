#ifndef ENGINEV2_COMPONENTS_TEXTURECOMPONENT_H_
#define ENGINEV2_COMPONENTS_TEXTURECOMPONENT_H_

#include <string>

#include "enginev2/graphics/sdl/primitives/Texture.h"

#include "enginev2/components/PrimitivesComponent.h"

struct TextureLoaderComponent;

class TextureComponent : public PrimitivesComponent<Texture> {
public:
    friend class TextureLoaderComponent;

	TextureComponent();

	void init(TextureLoaderComponent&);

	void loadTexture(const std::string& resourcePath);
	void loadTexture(const std::string& resourcePath, const Rectangle&);

private:
	TextureLoaderComponent* textureLoader;
};

#endif /* ENGINEV2_COMPONENTS_TEXTURECOMPONENT_H_ */
