#include <iostream>
#include "sphere.hpp"

//Sphere
Sphere::Sphere():center{glm::vec3()},radius{0},m_color{Color()},m_name{"no_name"}{std::cout << "Constructor - Sphere\n";}
Sphere::Sphere( glm::vec3 const&ctr, float const&r):Shape{"no_name",Color()},center{ctr},radius{r}{std::cout << "Constructor - Sphere\n";}
Sphere::Sphere( glm::vec3 const&ctr, float const&r, Color const&clr, std::string const&name):Shape{name,clr},center{ctr},radius{r}{std::cout << "Constructor - Sphere\n";}
Sphere::~Sphere(){std::cout << "Destructor - Sphere\n";}

float Sphere::getRadius() const{return radius;}
 glm::vec3 Sphere::getCenter() const{return center;}

float Sphere::area() const{return 4*3.141*radius*radius;}
float Sphere::volume() const{return (4/3)*3.141*radius*radius*radius;}

std::ostream& Sphere::print(std::ostream& os) const{Shape::print(os);
        os << "Center: ("<<center.x<<" / "<< center.y<< " / "<< center.z<< ")\nRadius: "<<radius<<"\n";}
bool Sphere::intersect(Ray const& ray, float& distance)
{
	auto normal_direction = glm::normalize(ray.m_direction);
	return glm::intersectRaySphere(
		ray.origin, normal_direction,
		center,
		radius * radius,
		distance);
}