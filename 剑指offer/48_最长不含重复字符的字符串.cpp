#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int longestSubstringWithoutDuplication(const string& str) {
	int curLength = 0;
	int maxLength = 0;
	int *position = new int[26];
	for (int i = 0; i < str.length(); ++i) {
		position[i] = -1;
	}

	for (int i = 0; i < str.length(); ++i) {
		int preIndex = position[str[i] - 'a'];
		if (preIndex<0 || i - preIndex>curLength)
			++ curLength;
		else {
			if (curLength > maxLength)
				maxLength = curLength;
			curLength = i - preIndex;
		}
		position[str[i] - 'a'] = i;
	}
	if (curLength > maxLength)
		maxLength = curLength;
	delete[] position;
	return maxLength;
}

