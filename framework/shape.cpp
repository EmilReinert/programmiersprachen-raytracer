#include <iostream>
#include "shape.hpp"

//Shape   //I'm in love with the .............  of you
Shape::Shape():m_name{"no_name"},m_color{Color()}{std::cout << "Constructor - Shape\n";}
Shape::Shape(std::string const&name, Color const&clr):m_name{name},m_color{clr}{std::cout << "Constructor - Shape\n";}
Shape::~Shape(){std::cout << "Destructor - Shape\n";}

std::string Shape::getName() const{return m_name;}
Color Shape::getColor() const{return m_color;}

std::ostream& Shape::print(std::ostream& os) const{os <<"/// Name: "<< m_name << " - Color: ("<<m_color.r<<" / "<<m_color.g<<" / "<<m_color.b <<") ///\n";return os;}


	std::ostream& operator<<(std::ostream& os, Shape const& s)
	{
		return s.print(os);
	}