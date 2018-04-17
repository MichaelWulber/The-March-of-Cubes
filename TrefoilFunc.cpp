#include "TrefoilFunc.h"

TrefoilFunc::TrefoilFunc(GLfloat a, GLfloat b){
	this->b = b;
	if (a <= b)
		this->a = b + 2.0f;
	else
		this->a = a;
}

GLfloat TrefoilFunc::function(GLfloat x, GLfloat y, GLfloat z){
	return (-8*(x*x + y*y)*(x*x + y*y)*(x*x + y*y + 1 + z*z + a*a - b*b) + 4*a*a*(2*(x*x + y*y)*(x*x + y*y)
			- (x*x*x - 3*x*y*y)*(x*x + y*y + 1)) + 8*a*a*(3*x*x*y - y*y*y)*z + 4*a*a*(x*x*x - 3*x*y*y)*z*z)
			* (-8*(x*x + y*y)*(x*x + y*y)*(x*x + y*y + 1 + z*z + a*a - b*b) + 4*a*a*(2*(x*x + y*y)*(x*x + y*y)
					- (x*x*x - 3*x*y*y)*(x*x + y*y + 1)) + 8*a*a*(3*x*x*y - y*y*y)*z + 4*a*a*(x*x*x - 3*x*y*y)*z*z)
			- (x*x + y*y)*(2*(x*x + y*y)*(x*x + y*y + 1 + z*z + a*a - b*b)*(x*x + y*y + 1 + z*z + a*a - b*b) + 8*(x*x + y*y)*(x*x + y*y)
					+ 4*a*a*(2*(x*x*x - 3*x*y*y) - (x*x + y*y)*(x*x + y*y + 1)) - 8*a*a*(3*x*x*y - y*y*y)*z - 4*(x*x + y*y)*a*a*z*z)
					* (2*(x*x + y*y)*(x*x + y*y + 1 + z*z + a*a - b*b)*(x*x + y*y + 1 + z*z + a*a - b*b) + 8*(x*x + y*y)*(x*x + y*y)
							+ 4*a*a*(2*(x*x*x - 3*x*y*y) - (x*x + y*y)*(x*x + y*y + 1)) - 8*a*a*(3*x*x*y - y*y*y)*z - 4*(x*x + y*y)*a*a*z*z);
}

bool TrefoilFunc::isInside(GLfloat x, GLfloat y, GLfloat z){
	return function(x, y, z) <= 0;
}
