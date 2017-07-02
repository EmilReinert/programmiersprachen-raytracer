#include "swag.cpp"
#include <iostream>
#include "color.hpp"


struct Material{
	Material():name{"Noname"}, ka{Color()},kd{Color()},ks{Color()},m{0.0f}{}
	Material(std::string const&names, Color const&kas, Color const&kds, Color const&kss, float const&ms):
		name{names}, ka{kas},kd{kds},ks{kss},m{ms}{}

	friend std::ostream& operator<<(std::ostream & os, Material const& mat){
		os << mat.name << ": (" << mat.ka << ", "<< mat.kd << ", "<< mat.ks << ", " <<mat.m<<")";
	}

	bool operator==(Material const&mat2){
		if(ka==mat2.ka&&kd==mat2.kd&&ks==mat2.ks&&m==mat2.m){return true;}
		else{return false;}
	}

private:
	std::string name;
	Color ka;
	Color kd;
	Color ks;
	float m;

};





int main(){
	return 0;
};