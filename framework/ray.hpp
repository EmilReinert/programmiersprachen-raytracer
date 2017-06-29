#ifndef RAY_HPP
#define RAY_HPP

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

struct Ray
{	
	Ray():
		origin{0.0, 0.0, 0.0}, direction{0.0, 0.0, 0.0}{}

	Ray(glm::vec3 const& origin, glm::vec3 const& direction):
		origin{origin}, direction{glm::normalize(direction)}{}

	glm::vec3 origin;
	glm::vec3 direction;
};

#endif