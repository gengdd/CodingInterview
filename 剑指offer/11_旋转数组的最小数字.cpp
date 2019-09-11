#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int left = 0, right = rotateArray.size() - 1;
		int mid = 0;
		while (rotateArray[left] >= rotateArray[right]) {
			if (right - left == 1) {
				mid = right;
				break;
			}
			mid = (left + right) / 2;
			if (rotateArray[mid] >= rotateArray[left])
				left = mid;
			if (rotateArray[mid] <= rotateArray[right])
				right = mid;
		}
		return rotateArray[mid];
	}
};