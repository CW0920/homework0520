#include<iostream>
#include<string>
using namespace std;

bool fourLetter(string str) {
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		if (isalpha(str[i])) {
			count++;
		}
	}
	return count == 4;
}

int main(void) {
	string str[10];
	cout << "Enter text(up to 10 words)(enter \"quit\" to exit): ";
	int i = 0;

	while (cin >> str[i]) {
		if (str[i] == "quit")
			break;
		if (fourLetter(str[i])) {
			if (isupper(str[i][1]))
				str[i].replace(0, 4, "Love");
			else
				str[i].replace(0, 4, "love");
		}
		cout << str[i] << " ";
		i++;
	}
	
	
	return 0;
}