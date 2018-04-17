#include "ImplicitFunc.h"

#ifndef TREFOILFUNC_H_
#define TREFOILFUNC_H_

class TrefoilFunc: public ImplicitFunc {
private:
	GLfloat a;
	GLfloat b;
public:
	TrefoilFunc(GLfloat a, GLfloat b);
    bool isInside(GLfloat x, GLfloat y, GLfloat z);
    GLfloat function(GLfloat x, GLfloat y, GLfloat z);
};



#endif /* TREFOILFUNC_H_ */
