#include "LightObject.h"

LightObject::LightObject(const BaseLight& light, glm::vec3 translate, glm::vec3 scale, glm::mat3 rotate)
	: BaseObject(translate, scale, rotate), _light(light)
{}