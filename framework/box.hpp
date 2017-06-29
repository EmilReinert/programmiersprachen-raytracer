#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <string>

class Box: public Shape {
         glm::vec3 min;
         glm::vec3 max;

        std::string m_name;
        Color m_color;
public:
        Box();
        Box( glm::vec3 const&v1,  glm::vec3 const&v2);
        Box( glm::vec3 const&v1,  glm::vec3 const&v2, Color const&clr, std::string const&name);

         glm::vec3 getMin() const;
         glm::vec3 getMax() const;

        float area() const override;
        float volume() const override;

        std::ostream& print(std::ostream& os) const override;
};

#endif