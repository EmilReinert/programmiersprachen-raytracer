#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <cmath>
#include "color.hpp"
#include "ray.hpp"


class Shape {
protected:
        std::string m_name;
        Color m_color;
public:
        Shape();
        Shape(std::string const&name, Color const&clr);
        virtual ~Shape();

        std::string getName() const;
        Color getColor() const;

        virtual float area() const {};
        virtual float volume() const {}; 

        virtual std::ostream& print(std::ostream& os) const;

        virtual bool intersect(Ray const& ray, float &t)=0;
};


#endif