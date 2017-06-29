#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <iostream>
#include "shape.hpp"
#include "ray.hpp"
#include <glm/vec3.hpp>
#include <string>

class Sphere: public Shape {
        glm::vec3 center;
        float radius;

        std::string m_name;
        Color m_color;           
public:
        Sphere();
        Sphere(glm::vec3 const&ctr, float const&r);
        Sphere(glm::vec3 const&ctr, float const&r, Color const&clr, std::string const&name);
        ~Sphere();

        float getRadius() const;
         glm::vec3 getCenter() const;


        float area() const override;
        float volume() const override;

        std::ostream& print(std::ostream& os) const override;

};

#endif