#ifndef __TEXTURE_RENDERABLE_H__
#define __TEXTURE_RENDERABLE_H__

#include <string>
#include <glad/glad.h>
#include "ComposeRenderable.h"
#include "Texture.h"
#include "TextureSlots.h"

class TextureRenderable : public ComposeRenderable
{
private:
	GLuint _texture;
	TextureSlots _slot;
	std::string _variable;
public:
	TextureRenderable(const Renderable& inner, GLuint texture, TextureSlots slot, std::string uniform_variable);

	virtual void render(GLuint program) const override;

};

#endif