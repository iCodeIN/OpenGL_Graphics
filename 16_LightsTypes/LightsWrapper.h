#ifndef __LIGHTS_WRAPPER_H__
#define __LIGHTS_WRAPPER_H__

#include <vector>
#include <glad/glad.h>
#include "LightObject.h"
#include "BaseCamera.h"


class LightsWrapper
{
private:
	std::vector<LightObject*> _lights;
	GLuint _ssbo;
public:
	LightsWrapper();
	void clear();
	void addLight(LightObject &light);

	void updateRendering(GLuint program, BaseCamera &camera, bool verbose=true);
};

#endif