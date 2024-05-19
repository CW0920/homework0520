#include<iostream>
using namespace std;

class Complex {
public:
	Complex(double R, double i) :real(R), imaginary(i) {  }
	Complex() :real(0), imaginary(0) {  }//default constructor
	double realPart(double R) { 
		real = R;
		imaginary = 0;
	}
	friend const Complex operator +(const Complex& x, const Complex& y);
	friend const Complex operator -(const Complex& x, const Complex& y);
	friend const Complex operator *(const Complex& x, const Complex& y);
	friend bool operator==(const Complex& x, const Complex& y);
	friend ostream& operator<< (ostream& outputStream, const Complex& x);
	friend istream& operator>> (istream& inputStream, Complex& x);
private: 
	double real;
	double imaginary;
};

int main(void) {
	Complex i(0, 1);
	Complex a, b;
	cin >> a;
	cin >> b;

	cout << "a + b = " << a + b << endl;
	cout << "a - b = " << a - b << endl;
	cout << "a * b = " << a * b << endl;
	if (a == b) {
		cout << "Same complex" << endl;
	}
	else {
		cout << "Different complex" << endl;
	}
	return 0;
}

const Complex operator +(const Complex& x, const Complex& y) {
	return Complex(x.real + y.real, x.imaginary + y.imaginary);
}
const Complex operator -(const Complex& x, const Complex& y) {
	return Complex(x.real - y.real, x.imaginary - y.imaginary);
}
const Complex operator *(const Complex& x, const Complex& y) {
	//(a + b*i)*(c + d*i) == (a*c - b*d ) + (a*d + b*c)*i
	double realResult = x.real * y.real - x.imaginary * y.imaginary;
	double imaginaryResult = x.real * y.imaginary + x.imaginary * y.real;
	return Complex(realResult,imaginaryResult);
}
bool operator==(const Complex& x, const Complex& y) {
	return x.real == y.real && x.imaginary == y.imaginary;
}
ostream& operator<<(ostream& outputStream, const Complex& x) {
	double absImaginary = abs(x.imaginary);
	outputStream << x.real;
	if (x.imaginary >= 0) {
		outputStream << " + ";
	}
	else {
		outputStream << " - ";
	}
	outputStream << absImaginary << "i";
	return outputStream;
}
istream& operator>> (istream& inputStream, Complex& x) {
	cout << "Enter real part: ";
	inputStream >> x.real;
	cout << "Enter imaginary part: ";
	inputStream >> x.imaginary;
	return inputStream;
}