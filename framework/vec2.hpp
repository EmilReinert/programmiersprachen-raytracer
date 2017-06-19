# ifndef VEC2_HPP
# define VEC2_HPP


struct Vec2
{
float x ;
float y ;
Vec2():x{0},
	y{0}{}
Vec2( float x, float y):
	x{x},
	y{y}{}
};

bool equals(Vec2 vec, Vec2 vecc){
	if(vec.x==vecc.x&&vec.y==vecc.y){return true;}else{return false;}}


# endif // VEC2_HPP
