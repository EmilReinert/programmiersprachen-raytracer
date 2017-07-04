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

bool Box::intersect(Ray const& ray ,float& t)
{



    float tx1 = (m_min.x-ray.origin.x)/ray.direction.x;
    float tx2 = (m_max.x-ray.origin.x)/ray.direction.x;
 
    float tfarx=std::max(tx1, tx2);
    float tnearx=std::min(tx1, tx2);

    float ty1 = (m_min.y-ray.origin.y)/ray.direction.y;
    float ty2 = (m_max.y-ray.origin.y)/ray.direction.y;
  
    float tfary=std::max(ty1, ty2);
    float tneary=std::min(ty1, ty2);

    float tz1 = (m_min.z-ray.origin.z)/ray.direction.z;
    float tz2 = (m_max.z-ray.origin.z)/ray.direction.z;

    float tfarz=std::max(tz1, tz2);
    float tnearz=std::min(tz1, tz2);

    float tfar=std::max(tfarx, tfary);
    float tnear=std::min(tnearx, tneary);

   if(tfar<tnear)
   {
        return false;
   }
 
   tfar=std::min(tfar, tfarz);
   tnear=std::max(tnear, tnearz);

   if((tfar<0) || (tfar<tnear))
   {
       return false;
   }

   return true;
}
