#include<iostream>
using namespace std;

class MyInteger {
public:
	MyInteger() :n(0) {  }//default
	int getInt() const { return n; }//get interger
	void setInt();//set interger
	int operator [](int index);
private:
	int n;//integer number
};

int main(void) {
	MyInteger A;
	A.setInt();
	int i = 0;
	while (A[i] != -1) {
		cout << "x[" << i << "] = " << A[i] << endl;
		i++;
	}
}

void MyInteger::setInt() {
	cout << "Enter the integer value:";
	cin >> n;
}
int MyInteger::operator[](int index) {
	int digit;
	int value = getInt() / int(pow(10, index));
	digit = value % 10;
	if (value <= 0 || digit <= 0)
		return -1;
	return digit;
}