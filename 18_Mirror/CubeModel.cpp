#include "CubeModel.h"


static const float vertices[] = {
	// positions			// normals				// textures coords
	//front
	-1.0f, -1.0f,  1.0f,	 0.0f,  0.0f,  1.0f,	0.0f, 0.0f,
	 1.0f, -1.0f,  1.0f,	 0.0f,  0.0f,  1.0f,	1.0f, 0.0f,
	 1.0f,  1.0f,  1.0f,	 0.0f,  0.0f,  1.0f,	1.0f, 1.0f,
	-1.0f,  1.0f,  1.0f,	 0.0f,  0.0f,  1.0f,    0.0f, 1.0f,
	//bottom
	-1.0f, -1.0f,  1.0f,	 0.0f, -1.0f,  0.0f,	0.0f, 0.0f,
	-1.0f, -1.0f, -1.0f,	 0.0f, -1.0f,  0.0f,	1.0f, 0.0f,
	 1.0f, -1.0f, -1.0f,	 0.0f, -1.0f,  0.0f,	1.0f, 1.0f,
	 1.0f, -1.0f,  1.0f,	 0.0f, -1.0f,  0.0f,    0.0f, 1.0f,
	//left
	-1.0f, -1.0f,  1.0f,	-1.0f,  0.0f,  0.0f,	0.0f, 0.0f,
	-1.0f,  1.0f,  1.0f,	-1.0f,  0.0f,  0.0f,	1.0f, 0.0f,
	-1.0f,  1.0f, -1.0f,	-1.0f,  0.0f,  0.0f,	1.0f, 1.0f,
	-1.0f, -1.0f, -1.0f,	-1.0f,  0.0f,  0.0f,    0.0f, 1.0f,
	//right
	 1.0f, -1.0f,  1.0f,	 1.0f,  0.0f,  0.0f,	0.0f, 0.0f,
	 1.0f, -1.0f, -1.0f,	 1.0f,  0.0f,  0.0f,	1.0f, 0.0f,
	 1.0f,  1.0f, -1.0f,	 1.0f,  0.0f,  0.0f,	1.0f, 1.0f,
	 1.0f,  1.0f,  1.0f,	 1.0f,  0.0f,  0.0f,    0.0f, 1.0f,
	//back
	 1.0f, -1.0f, -1.0f,	 0.0f,  0.0f, -1.0f,	0.0f, 0.0f,
	-1.0f, -1.0f, -1.0f,	 0.0f,  0.0f, -1.0f,	1.0f, 0.0f,
	-1.0f,  1.0f, -1.0f,	 0.0f,  0.0f, -1.0f,	1.0f, 1.0f,
	 1.0f,  1.0f, -1.0f,	 0.0f,  0.0f, -1.0f,    0.0f, 1.0f,
	//top
	-1.0f,  1.0f,  1.0f,	 0.0f,  1.0f,  0.0f,	0.0f, 0.0f,
	 1.0f,  1.0f,  1.0f,	 0.0f,  1.0f,  0.0f,	1.0f, 0.0f,
	 1.0f,  1.0f, -1.0f,	 0.0f,  1.0f,  0.0f,	1.0f, 1.0f,
	-1.0f,  1.0f, -1.0f,	 0.0f,  1.0f,  0.0f,    0.0f, 1.0f,
};

static const unsigned int indices[] = {
	0,   1,  2,  2,  3,  0,
	4,   5,  6,  6,  7,  4,
	8,   9, 10, 10, 11,  8,
	12, 13, 14, 14, 15, 12,
	16, 17, 18, 18, 19, 16,
	20, 21, 22, 22, 23, 20,
};


CubeModel::CubeModel() :
	ElementBufferModel()
{
	// bind
	glBindVertexArray(_vertexArray);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _elementBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
	// fill data
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// setup position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), reinterpret_cast<void*>(0));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), reinterpret_cast<void*>(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), reinterpret_cast<void*>(6 * sizeof(float)));
	glEnableVertexAttribArray(3);

	// unbind
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void CubeModel::render(GLuint program)
{
	this->_render(
		program,
		[]() {
			glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(unsigned int), GL_UNSIGNED_INT, nullptr);
		}
	);
}
