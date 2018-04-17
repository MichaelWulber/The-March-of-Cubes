#include "ImplicitFunc.h"

#ifndef TORUSFUNC_H_
#define TORUSFUNC_H_

class TorusFunc: public ImplicitFunc {
private:
	GLfloat r;
	GLfloat a;
public:
    TorusFunc(GLfloat r, GLfloat a);
    bool isInside(GLfloat x, GLfloat y, GLfloat z);
    GLfloat function(GLfloat x, GLfloat y, GLfloat z);
};

#endif /* TORUSFUNC_H_ */
