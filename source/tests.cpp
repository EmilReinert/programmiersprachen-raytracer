#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/vec3.hpp>
#include "vec2.cpp"
#include "swag.cpp"
#include "color.hpp"


TEST_CASE("b","[b]"){
	REQUIRE(Vec2(2,2).x == 2);
}


TEST_CASE("boxconstruct","[boxconstruct]"){
  glm::vec3 v1 =  glm::vec3(1,1,1);
  glm::vec3 v2 =  glm::vec3(2,2,2);

	REQUIRE(Box().getMin()== glm::vec3());
	REQUIRE(Box().getMax()== glm::vec3());

	REQUIRE(Box(v1,v2).getMin()==v1);
	REQUIRE(Box(v1,v2).getMax()==v2);
}
TEST_CASE("sphereconstruct","[sphereconstruct]"){
  glm::vec3 v1 =  glm::vec3(1,1,1);

	REQUIRE(Sphere().getCenter()== glm::vec3());
	REQUIRE(Sphere().getRadius()==0);

	REQUIRE(Sphere(v1,1).getCenter()==v1);
	REQUIRE(Sphere(v1,1).getRadius()==1);

}
TEST_CASE("boxareavolume","[boxareavolume]"){
  glm::vec3 v1 =  glm::vec3(1,1,1);
  glm::vec3 v2 = glm::vec3(2,2,2);
	Box b1 = Box (v1,v2);
	REQUIRE(b1.area()==6.0f);
	REQUIRE(b1.volume()==1.0f);

}
TEST_CASE("sphereareavolume","[sphereareavolume]"){
  glm::vec3 v1 = glm::vec3(1,1,1);
	Sphere s1 = Sphere(v1,1);
	REQUIRE(s1.area()==Approx(4*3.141));
	REQUIRE(s1.volume()==Approx((4/3)*3.141));
}
TEST_CASE("boxnamecolor","[boxnamecolor]"){
  glm::vec3 v1 =  glm::vec3(1,1,1);
  glm::vec3 v2 =  glm::vec3(2,2,2);
	Color c1 = Color(1,1,1);
	std::string n1 = "box";
	Box b1 = Box (v1,v2,c1,"box");
	REQUIRE(b1.getName()==n1);
}
TEST_CASE("spherenamecolor","[spherenamecolor]"){
  glm::vec3 v1 =  glm::vec3(1,1,1);
	Color c1 = Color(1,1,1);
	std::string n1 = "sphere";
	Sphere s1 = Sphere (v1,1,c1,"sphere");
	REQUIRE(s1.getName()==n1);
}
TEST_CASE("boxprint","[boxprint]"){
  glm::vec3 v1 =  glm::vec3(1,1,1);
  glm::vec3 v2 =  glm::vec3(2,2,2);
	Color c1 = Color(1,1,1);
	std::string n1 = "box";
	Box b1 = Box (v1,v2,c1,"box");
	std::cout<<b1;
}
TEST_CASE("spereprint","[spereprint]"){
  glm::vec3 v1 =  glm::vec3(1,1,1);
	Color c1 = Color(1,1,1);
	std::string n1 = "sphere";
	Sphere s1 = Sphere (v1,1,c1,"sphere");
	std::cout<<s1<<"\n---------------------------------------\n";


}
TEST_CASE("Aufgabe58","[Aufgabe58]"){
	Color red (255 , 0 , 0);
	glm::vec3 position =  glm::vec3(0,0 ,0);
	Sphere * s1 = new Sphere ( position , 1.2 , red , " sphere0 " );
	Shape * s2 = new Sphere ( position , 1.2 , red , " sphere1 " );
	s1 -> print ( std :: cout );
	s2 -> print ( std :: cout );
	delete s1 ;
	delete s2 ;
}



int main(int argc, char *argv[])
{
	return Catch::Session().run(argc, argv);
}
