#ifndef IMPLICITFUNC_H
#define IMPLICITFUNC_H

class ImplicitFunc {
public:
	virtual bool isInside(const float &point) const = 0;
};

#endif
