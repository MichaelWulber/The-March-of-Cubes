#include "ImplicitFunc.h"

#ifndef GENUSFUNC_H_
#define GENUSFUNC_H_

class GenusFunc: public ImplicitFunc {
public:
	GenusFunc();
    bool isInside(GLfloat x, GLfloat y, GLfloat z);
    GLfloat function(GLfloat x, GLfloat y, GLfloat z);
};




#endif /* GENUSFUNC_H_ */
