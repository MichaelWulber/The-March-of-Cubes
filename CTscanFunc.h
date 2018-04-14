//#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#ifndef CTSCANFUNC_H_
#define CTSCANFUNC_H_

GLfloat CTinterpolate(GLfloat a, GLfloat aVal, GLfloat b, GLfloat bVal){
	return (a + b) / 2;
}



#endif /* CTSCANFUNC_H_ */

