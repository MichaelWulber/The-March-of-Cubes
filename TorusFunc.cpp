#include "TorusFunc.h"

TorusFunc::TorusFunc(GLfloat r, GLfloat a){
	this->r = r;
	this->a = a;
}

GLfloat TorusFunc::function(GLfloat x, GLfloat y, GLfloat z){
	return (x*x + y*y + z*z + r*r - a*a)
			* (x*x + y*y + z*z + r*r - a*a)
			- 4 * r*r*(x*x + y*y);
}

bool TorusFunc::isInside(GLfloat x, GLfloat y, GLfloat z){
	return function(x, y, z) <= 0;
}

