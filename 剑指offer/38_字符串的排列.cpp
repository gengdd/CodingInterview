#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<string> Permutation(string str) {

		if (str.length() == 0)
			return res;

		PermutationCore(str, 0);
		sort(res.begin(), res.end());
		return res;
	}

	void PermutationCore(string str, int begin) {
		if (begin == str.length()) {
			res.push_back(str);
			return;
		}
		for (int i = begin; i < str.length(); i++) {
			if (i != begin && str[i] == str[begin])
				continue;

			swap(str[begin], str[i]);
			PermutationCore(str, begin + 1);
		}
	}
private:
	vector<string> res;
};
