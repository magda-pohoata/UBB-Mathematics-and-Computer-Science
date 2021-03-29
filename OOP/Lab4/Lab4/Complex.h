#pragma once

#include <ostream>
#include<istream>
#include <cmath>

#define PI 3.14159265

using namespace std;

class Complex
{
public:
	Complex();
	Complex(float real, float imag);
	Complex add(Complex);
	Complex add(float s);
	Complex subtract(Complex);
	Complex subtract(float);
	Complex multiply(Complex);
	Complex multiply(float);
	Complex division(Complex);
	Complex division(float);
	Complex conjugate();

	double magnitude();
	double phase();
	void toPolar(float* r, float* theta);

	Complex operator+(Complex);
	Complex operator+(float);
	Complex operator-(Complex);
	Complex operator-(float);
	Complex operator*(Complex);
	Complex operator*(float);
	Complex operator/(Complex);
	Complex operator/(float);
	bool operator==(Complex);
	bool operator!=(Complex);

	bool equal(Complex);
		
	friend ostream& operator<<(ostream& os, const Complex& c);
	friend istream& operator>>(istream& os, Complex& c);

	float getReal() const{ return m_real; }
	float getImag() const { return m_imag; }
	void setReal(float);
	void setImag(float);


private:
	float m_real, m_imag;
};
