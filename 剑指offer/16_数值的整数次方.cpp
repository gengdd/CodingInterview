#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	double Power(double base, int exponent) {
		if (equal(base, 0.0)) {
			return 0.0;
		}
		unsigned int absexponent = 0;
		if (exponent > 0) {
			absexponent = (unsigned int)(exponent);
		}
		else {
			absexponent = (unsigned int)(-exponent);
		}
		double res = PowerWithUnsignedExponent(base, absexponent);
		if (exponent < 0) {
			res = 1.0 / res;
		}
		return res;
	}
private:
	bool equal(double num1, double num2) {
		if (num1 - num2 > -0.0000001 && (num1 - num2) < 0.0000001) {
			return true;
		}
		else {
			return false;
		}
	}

	double PowerWithUnsignedExponent(double base, unsigned int exponent) {
		if (exponent == 0) {
			return 1;
		}
		if (exponent == 1) {
			return base;
		}
		double res = PowerWithUnsignedExponent(base, exponent >> 1);
		res *= res;
		if (exponent & 0x1 == 1) {
			res *= base;
		}
		return res;
	}
};