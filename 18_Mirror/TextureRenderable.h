#ifndef __TEXTURE_RENDERABLE_H__
#define __TEXTURE_RENDERABLE_H__

#include <string>
#include <glad/glad.h>
#include "WrapRenderable.h"
#include "Texture.h"
#include "TextureSlots.h"
#include "UniformWrapper.h"

class TextureRenderable : public WrapRenderable
{
private:
	static UniformWrapper _uniform;
	GLuint _texture;
	TextureSlots _slot;
	const std::string _variable;
public:
	TextureRenderable(Renderable* inner, GLuint texture, TextureSlots slot, std::string uniform_variable);

	virtual void render(GLuint program) override;

};





#endif