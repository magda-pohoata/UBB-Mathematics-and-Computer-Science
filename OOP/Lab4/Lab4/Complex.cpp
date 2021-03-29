#include "Complex.h"

Complex::Complex()
{
	this->m_imag = 0;
	this->m_real = 0;
}

Complex::Complex(float m_real,float m_imag)
{
	this->m_imag = m_imag;
	this->m_real = m_real;
}

Complex Complex::add(Complex a)
{
	//Complex newNumber {
	//  this->m_real + a.m_real,this->m_imag + a.m_imag
	//  }

	Complex newNumber;
	newNumber.m_imag = this->m_imag + a.m_imag;
	newNumber.m_real = this->m_real + a.m_real;
	return newNumber;
}

Complex Complex::add(float s)
{
	Complex newNumber;
	newNumber.m_imag = this->m_imag;
	newNumber.m_real = this->m_real + s;
	return newNumber;
}


Complex Complex::subtract(Complex c1)
{
	Complex c;
	c.m_imag = this->m_imag - c1.m_imag;
	c.m_real = this->m_real - c1.m_real;
	return c;
}

Complex Complex::subtract(float s)
{
	Complex newNumber;
	newNumber.m_imag = this->m_imag;
	newNumber.m_real = this->m_real - s;
	return newNumber;
}

Complex Complex::multiply(Complex c1)
{
	Complex c;
	c.m_real = c1.m_real * this->m_real + (-1) * c1.m_imag * this->m_imag;
	c.m_imag = c1.m_real * this->m_imag + c1.m_imag * this->m_real;
	return c;
}

Complex Complex::multiply(float s)
{
	Complex c;
	c.m_real = this->m_real * s;
	c.m_imag = this->m_imag * s;

	return c;
}

Complex Complex::division(Complex c)
{
	Complex num , denom;
	num = this->multiply(c.conjugate());
	denom = c.multiply(c.conjugate());
	return num.division(denom.m_real);
}


// when s is 0 what do i return?
Complex Complex::division(float s)
{
	if (this->m_real == 0 && this->m_imag == 0)
		return *this;
	else
		if (s != 0)
		{
			Complex c;
			c.m_real = this->m_real / s;
			c.m_imag = this->m_imag / s;

			return c;
		}
}

Complex Complex::conjugate()
{
	if (this->m_real == 0 && this->m_imag == 0)
		return *this;
	else
	{
		Complex conj;
		conj.m_real = this->m_real;
		conj.m_imag = (-1) * this->m_imag;
		return conj;
	}
}

double Complex::magnitude()
{
	if (this->m_real == 0 && this->m_imag == 0)
		return 0;
	else
		return sqrt(this->m_real * this->m_real + this->m_imag * this->m_imag);
}

double Complex::phase()
{
	if (this->m_real == 0 && this->m_imag == 0)
		return 0;
	else
	{
		double mag;
		mag = this->magnitude();
		return asin(this->m_imag / mag);
		//return asin(this->m_imag / mag) * 180 / PI;
	}
}

void Complex::toPolar(float* r, float* theta)
{
	//z= r(cosθ+isinθ)
	//θ= (180 * arctan(y/x)) / PI              C1       x,y>0
	//θ= (180 * (PI - arctan(y/x))) / PI       C2
	//θ= (180 * (-PI + arctan(y/x))) / PI      C3
	//θ= - (180 * arctan(y/x)) / PI            C4
	
	if (this->m_real == 0 && this->m_imag == 0)
		*r = 0, * theta = 0;
	else
	{
		*r = this->magnitude();
		if (this->m_real > 0 && this->m_imag > 0)   //cadran 1
			*theta = 180 * (atan(this->m_imag / this->m_real)) / PI;
		else
			if (this->m_real < 0 && this->m_imag > 0)   //cadran 2
				*theta = 180 * (PI - atan(this->m_imag / this->m_real * -1)) / PI;
			else
				if (this->m_real < 0 && this->m_imag < 0)    //cadran 3
					*theta = 180 * (-1 * PI + atan(this->m_imag * -1 / this->m_real * -1)) / PI;
				else                                          //cadran 4
					*theta = -1 * 180 * atan(this->m_imag / this->m_real * -1) / PI;
	}
}






Complex Complex::operator+(Complex a)
{
	return add(a);
}

Complex Complex::operator+(float s)
{
	return add(s);
}

Complex Complex::operator-(Complex a)
{
	return subtract(a);
}

Complex Complex::operator-(float s)
{
	return subtract(s);
}

Complex Complex::operator*(Complex a)
{
	return multiply(a);
}

Complex Complex::operator*(float s)
{
	return multiply(s);
}

Complex Complex::operator/(Complex a)
{
	return division(a);
}

Complex Complex::operator/(float s)
{
	return division(s);
}

bool Complex::operator==(Complex c)
{
	return equal(c);
}
bool Complex::operator!=(Complex c)
{
	return !(equal(c));
}


ostream& operator<<(ostream& os, const Complex& c)
{
	if(c.m_real==0)
		if (c.m_imag == 0)
			os << c.m_real;
		else
			if (c.m_imag == 1)
				os << "i";
			else
				if (c.m_imag == -1)
					os << "-" << "i";
				else
					os << c.m_imag << "i";
	else
		if (c.m_imag == 0)
			os << c.m_real;
		else
			if (c.m_imag == 1)
				os << c.m_real << "+" << "i";
			else
				if (c.m_imag == -1)
					os << c.m_real << "-" << "i";
				else
					if (c.m_imag > 0)
						os << c.m_real << "+" << c.m_imag << "i";
					else
						os << c.m_real << c.m_imag << "i";
	return os;
}

istream& operator>>(istream& os, Complex& c)
{
	os >> c.m_real >> c.m_imag;
	return os;
}





bool Complex::equal(Complex c)
{
	return (this->m_real == c.m_real) && (this->m_imag == c.m_imag);
}


void Complex::setReal(float a)
{
	this->m_real = a;
}

void Complex::setImag(float a)
{
	this->m_imag = a;
}