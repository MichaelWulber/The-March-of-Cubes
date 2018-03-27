#include "PolyFunc.h"

PolyFunc::PolyFunc(std::vector<float> xCoeffs, std::vector<float> yCoeffs, std::vector<float> zCoeffs, float constant) {
	this->xCoeffs = xCoeffs;
	this->yCoeffs = xCoeffs;
	this->zCoeffs = xCoeffs;
	this->constant = constant;
}

bool PolyFunc::isInside(const float point[3]) const {
	float xx, yy, zz = 0;
	float value = 0;
	for (int i = 0; i < this->xCoeffs.size(); ++i) {
		xx = xCoeffs[i] * point[0];
		yy = yCoeffs[i] * point[1];
		zz = zCoeffs[i] * point[2];
		for (int exp = 0; exp < i; ++exp) {
			xx *= point[0];
			yy *= point[1];
			zz *= point[2];
		}
		value += xx + yy + zz;
	}

	return value <= this->constant;
}