#include <iostream>
#include "color.cpp"
#include <glm/vec3.hpp>

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
};


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

std::ostream& operator<<(std::ostream& os, Shape const& s){
        return s.print(os);
}

//Shape   //I'm in love with the .............  of you
Shape::Shape():m_name{"no_name"},m_color{Color()}{std::cout << "Constructor - Shape\n";}
Shape::Shape(std::string const&name, Color const&clr):m_name{name},m_color{clr}{std::cout << "Constructor - Shape\n";}
Shape::~Shape(){std::cout << "Destructor - Shape\n";}

std::string Shape::getName() const{return m_name;}
Color Shape::getColor() const{return m_color;}

std::ostream& Shape::print(std::ostream& os) const{os <<"/// Name: "<< m_name << " - Color: ("<<m_color.r<<" / "<<m_color.g<<" / "<<m_color.b <<") ///\n";return os;}



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



//Box
Box::Box():min{ glm::vec3()},max{ glm::vec3()},m_color{Color()},m_name{"no_name"}{}
Box::Box( glm::vec3 const&v1, glm::vec3 const&v2):Shape{"no_name",Color()},min{v1},max{v2}{}
Box::Box( glm::vec3 const&v1,  glm::vec3 const&v2, Color const&clr, std::string const&name):Shape{name,clr},min{v1},max{v2}{}

 glm::vec3 Box::getMin() const{return min;}
 glm::vec3 Box::getMax() const{return max;}

float Box::area() const{auto holder=max-min; return holder.x*holder.y*2+holder.x*holder.z*2+holder.y*holder.z*2;}
float Box::volume() const{auto holder=max-min; return holder.x *holder.y*holder.z;}

std::ostream& Box::print(std::ostream& os) const{Shape::print(os);
  os << "Minimum: (" << min.x <<" / "<<min.y<<" / "<<min.z<<")\nMaximum: ("<< max.x <<" / "<<max.y <<" / "<<max.y<<")\n";}


