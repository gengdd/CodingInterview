#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	string ReverseSentence(string str) {
		string res = str;
		int length = res.size();
		if (length == 0)
			return "";
		res += ' ';
		int mark = 0;
		for (int i = 0; i < length + 1; i++) {
			if (res[i] == ' ') {
				Reverse(res, mark, i - 1);
				mark = i + 1;
			}
		}

		res = res.substr(0, length);
		Reverse(res, 0, length - 1);
		return res;
	}
	void Reverse(string &str, int begin, int end) {
		while (begin < end) {
			swap(str[begin++], str[end--]);
		}
	}
};


 
