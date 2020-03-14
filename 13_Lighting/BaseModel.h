#ifndef __BASE_MODEL_H__
#define __BASE_MODEL_H__

#include <functional>
#include <glad/glad.h>
#include <glm.hpp>
#include "Renderable.h"
#include "RAII.h"


class BaseModel : public Renderable
{
protected:
	RAIIArray<> _vertexBuffer;
	RAIIArray<> _vertexArray;
	void _render(
		GLuint program,
		std::function<void()> render,
		glm::mat4* model = nullptr,
		glm::mat4* view = nullptr, 
		glm::mat4* projection = nullptr
	);
public:
	BaseModel();
	virtual ~BaseModel() = default;

	static void transformations(GLuint program, glm::mat4* model = nullptr, glm::mat4* view = nullptr, glm::mat4* projection = nullptr);
};

#endif