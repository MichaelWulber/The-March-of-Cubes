#include "SphereFunc.h"

SphereFunc::SphereFunc(GLfloat r){
	this->r = r;
}

GLfloat SphereFunc::function(GLfloat x, GLfloat y, GLfloat z){
	return x*x + y*y + z*z - r*r;
}

bool SphereFunc::isInside(GLfloat x, GLfloat y, GLfloat z){
	return function(x, y, z) <= 0;
}

