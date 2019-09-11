#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	bool isNumeric(char* string) {
		if (string == NULL || *string == '\0') {
			return false;
		}

		if (*string == '+' || *string == '-') {
			++string;
		}
		bool numeric = true;
		scanDigits(&string);
		if (*string != '\0') {
			if (*string == '.') {
				++string;
				scanDigits(&string);
				if (*string == 'e' || *string == 'E') {
					numeric = isExponential(&string);
				}
			}
			else if (*string == 'e' || *string == 'E') {
				numeric = isExponential(&string);
			}
			else {
				numeric = false;
			}
		}
		return numeric && *string == '\0';
	}
private:
	void scanDigits(char** string) {
		while (**string != '\0'&&**string >= '0'&&**string <= '9') {
			++(*string);
		}
	}
	bool isExponential(char** string) {
		++(*string);
		if (**string == '+' || **string == '-') {
			++(*string);
		}
		if (**string == '\0') {
			return false;
		}
		scanDigits(string);
		return (**string == '\0') ? true : false;
	}
};

