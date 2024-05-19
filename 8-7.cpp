#include<iostream>
using namespace std;

class PrimeNumber {
public:
	PrimeNumber();
	PrimeNumber(int n);
	int getPrime()const;
	bool isPrime(int n);
	PrimeNumber operator++();//prefix
	PrimeNumber operator++(int);//postfix
	PrimeNumber operator--();//prefix
	PrimeNumber operator--(int);//postfix
private:
	int Num;
};

int main(void) {
	PrimeNumber Test1(13);
	cout << "Test = " << Test1.getPrime() << endl;
	cout << "Test++ : " << endl;
	PrimeNumber Result1 = Test1++;
	cout << "Value return: " << Result1.getPrime() << endl;//value return
	cout << "Changed object: " << Test1.getPrime() << endl;//changed object

	PrimeNumber Test2(13);
	cout << "Test = " << Test2.getPrime() << endl;
	cout << "++Test : " << endl;
	PrimeNumber Result2 = ++Test2;
	cout << "Value return: " << Result2.getPrime() << endl;//value return
	cout << "Changed object: " << Test2.getPrime() << endl;//changed object
	
	PrimeNumber Test3(13);
	cout << "Test = " << Test3.getPrime() << endl;
	cout << "Test-- : " << endl;
	PrimeNumber Result3 = Test3--;
	cout << "Value return: " << Result3.getPrime() << endl;//value return
	cout << "Changed object: " << Test3.getPrime() << endl;//changed object

	PrimeNumber Test4(13);
	cout << "Test = " << Test4.getPrime() << endl;
	cout << "--Test : " << endl;
	PrimeNumber Result4 = --Test4;
	cout << "Value return: " << Result4.getPrime() << endl;//value return
	cout << "Changed object: " << Test4.getPrime() << endl;//changed object

	return 0;
}

PrimeNumber::PrimeNumber() :Num(1) {  }
PrimeNumber::PrimeNumber(int n) {
	if (isPrime(n))
		Num = n;
	else {
		cout << "n is not a prime." << endl;
		Num = -1;
	}
}
int PrimeNumber::getPrime()const {
	return Num;
}
bool PrimeNumber::isPrime(int n) {
	if (n <= 1)
		return false;
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
PrimeNumber PrimeNumber::operator++() {
	Num++;
	while (!isPrime(Num)) {
		Num++;
	}
	return PrimeNumber(Num);
}
PrimeNumber PrimeNumber::operator++(int) {
	int valueP = Num + 1;
	int temp = Num;
	while (!isPrime(valueP)) {
		valueP++;
	}
	Num = valueP;
	return PrimeNumber(temp);
}
PrimeNumber PrimeNumber::operator--() {
	Num--;
	while (!isPrime(Num)) {
		Num--;
	}
	return PrimeNumber(Num);
}
PrimeNumber PrimeNumber::operator--(int) {
	int valueP = Num - 1;
	int temp = Num;
	while (!isPrime(valueP)) {
		valueP--;
	}
	Num = valueP;
	return PrimeNumber(temp);
}