#ifndef POLYFUNC_H
#define POLYFUNC_H

#include <vector>
#include "ImplicitFunc.h"

class PolyFunc: public ImplicitFunc {
private:
	std::vector<float> xCoeffs;
	std::vector<float> yCoeffs;
	std::vector<float> zCoeffs;
	float constant;

public:
	PolyFunc(std::vector<float> xCoeffs, std::vector<float> yCoeffs, std::vector<float> zCoeffs, float constant);
	bool isInside(const float point[3]) const;
};

#endif
