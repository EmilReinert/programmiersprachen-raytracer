#include <iostream>
#include "box.hpp"

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
