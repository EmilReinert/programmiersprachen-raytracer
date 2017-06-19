#include <iostream>
#include "color.cpp"
#include "vec2.cpp"

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
        Vec2 center;
        float radius;

        std::string m_name;
        Color m_color;           
public:
        Sphere();
        Sphere(Vec2 const&ctr, float const&r);
        Sphere(Vec2 const&ctr, float const&r, Color const&clr, std::string const&name);
        ~Sphere();

        float getRadius() const;
        Vec2 getCenter() const;


        float area() const override;
        float volume() const override;

        std::ostream& print(std::ostream& os) const override;
};


class Box: public Shape {
        Vec2 min;
        Vec2 max;

        std::string m_name;
        Color m_color;
public:
        Box();
        Box(Vec2 const&v1, Vec2 const&v2);
        Box(Vec2 const&v1, Vec2 const&v2, Color const&clr, std::string const&name);

        Vec2 getMin() const;
        Vec2 getMax() const;

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
Sphere::Sphere():center{Vec2()},radius{0},m_color{Color()},m_name{"no_name"}{std::cout << "Constructor - Sphere\n";}
Sphere::Sphere(Vec2 const&ctr, float const&r):Shape{"no_name",Color()},center{ctr},radius{r}{std::cout << "Constructor - Sphere\n";}
Sphere::Sphere(Vec2 const&ctr, float const&r, Color const&clr, std::string const&name):Shape{name,clr},center{ctr},radius{r}{std::cout << "Constructor - Sphere\n";}
Sphere::~Sphere(){std::cout << "Destructor - Sphere\n";}

float Sphere::getRadius() const{return radius;}
Vec2 Sphere::getCenter() const{return center;}

float Sphere::area() const{return 4*3.141*radius*radius;}
float Sphere::volume() const{return (4/3)*3.141*radius*radius*radius;}

std::ostream& Sphere::print(std::ostream& os) const{Shape::print(os);
        os << "Center: ("<<center.x<<" / "<< center.y<< ")\nRadius: "<<radius<<"\n";}



//Box
Box::Box():min{Vec2()},max{Vec2()},m_color{Color()},m_name{"no_name"}{}
Box::Box(Vec2 const&v1, Vec2 const&v2):Shape{"no_name",Color()},min{v1},max{v2}{}
Box::Box(Vec2 const&v1, Vec2 const&v2, Color const&clr, std::string const&name):Shape{name,clr},min{v1},max{v2}{}

Vec2 Box::getMin() const{return min;}
Vec2 Box::getMax() const{return max;}

float Box::area() const{return 0;}
float Box::volume() const{return 0;}

std::ostream& Box::print(std::ostream& os) const{Shape::print(os);
        os << "Minimum: (" << min.x <<" / "<<min.y<< ")\nMaximum: ("<< max.x <<" / "<<max.y<<")\n";}


