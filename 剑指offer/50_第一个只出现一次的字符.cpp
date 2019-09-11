#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		int length = str.size();
		if (length == 0)
			return -1;
		map<char, int> item;
		for (int i = 0; i < length; i++) {
			item[str[i]]++;
		}
		for (int i = 0; i < length; i++) {
			if (item[str[i]] == 1)
				return i;
		}
		return -1;
	}
};