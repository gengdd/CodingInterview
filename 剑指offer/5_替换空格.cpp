#include<iostream>
#include<string>
using namespace std;

//class Solution {
//public:
//	void replaceSpace(char *str, int length) {
//		if (str == nullptr || length <= 0)
//			return;
//		int num = 0, len = 0;
//		for (int i = 0;; i++) {
//			if (str[i] != '\0') {
//				len = len + 1;
//				if (str[i] == ' ')
//					num = num + 1;
//			}
//			else {
//				break;
//			}
//		}
//		int newlen = len + num * 2;
//		if (newlen > length)
//			return;
//		while (len >= 0 && len < newlen) {
//			if (str[len] == ' ') {
//				str[newlen--] = '0';
//				str[newlen--] = '2';
//				str[newlen--] = '%';
//			}
//			else {
//				str[newlen--] = str[len];
//			}
//			--len;
//		}
//	}
//};

class Solution {
public:
	void replaceSpace(char *str, int length) {
		int i = 0;
		int numSpace = 0;
		while (str[i] != '\0') {
			if (str[i] == ' ')
				numSpace++;
			++i;
		}
		int newLen = i + numSpace * 2;
		if (newLen > length)
			return;
		for (int j = i; i >= 0, newLen >= 0;) {
			if (str[j] == ' ') {
				str[newLen--] = '0';
				str[newLen--] = '2';
				str[newLen--] = '%';
			}
			else {
				str[newLen--] = str[j];
			}
			j--;
		}
	}
};