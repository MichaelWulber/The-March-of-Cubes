#include "GenusFunc.h"

GenusFunc::GenusFunc(){
}

GLfloat GenusFunc::function(GLfloat x, GLfloat y, GLfloat z){
	return 2*y*(y*y - 3*x*x)*(1 - z*z) + (x*x + y*y)*(x*x + y*y) - (9*z*z - 1)*(1 - z*z);
}

bool GenusFunc::isInside(GLfloat x, GLfloat y, GLfloat z){
	return function(x, y, z) <= 0;
}

