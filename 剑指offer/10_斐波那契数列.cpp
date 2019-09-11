#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	int Fibonacci(int n) {
		int res[2] = { 0,1 };
		if (n < 2)
			return res[n];
		int fn1 = 0;
		int fn2 = 1;
		int ress = 0;
		for (int i = 2; i <= n; i++) {
			ress = fn1 + fn2;
			fn1 = fn2;
			fn2 = ress;
		}
		return ress;
	}
};

class Solution {
public:
	int jumpFloor(int number) {
		if (number <= 0)
			return 0;
		if (number <= 2&&number > 0)
			return number;
		int fn1 = 1;
		int fn2 = 2;
		int ress = 0;
		for (int i = 3; i <= number; i++) {
			ress = fn1 + fn2;
			fn1 = fn2;
			fn2 = ress;
		}
		return ress;
	}
};