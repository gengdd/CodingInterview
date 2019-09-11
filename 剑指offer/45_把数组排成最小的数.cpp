#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		int length = numbers.size();
		if (length == 0) {
			return "";
		}
		sort(numbers.begin(), numbers.end(), cmp);
		string res;
		for (int i = 0; i < length; ++i) {
			res += to_string(numbers[i]);
		}
		return res;
	}
	static bool cmp(int a, int b) {
		string A = to_string(a) + to_string(b);
		string B = to_string(b) + to_string(a);
		return A < B;
	}
};