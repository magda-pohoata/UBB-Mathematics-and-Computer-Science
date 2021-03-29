#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab4/Complex.h"
#include "../Lab4/DynamicArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestLab4
{
	TEST_CLASS(TestLab4)
	{
	public:
		
		TEST_METHOD(Complex_Constructor)
		{
			Complex a, b{ 10,5 };
			float zero = 0;
			Assert::AreEqual(a.getReal(), zero);
			Assert::AreEqual(a.getImag(), zero);
			Assert::AreEqual(b.getReal(), float(10));
			Assert::AreEqual(b.getImag(), float(5));
			a = b;
			Assert::AreEqual(a.getReal(), float(10));
			Assert::AreEqual(a.getImag(), float(5));
		}

		TEST_METHOD(Complex_Add)
		{
			Complex a, b{ 10,5 };
			float s;
			s = 0;
			a.add(s);
			Assert::AreEqual(a.getReal(), float(0));
			Assert::AreEqual(a.getImag(), float(0));

			a = a.add(b);
			Assert::AreEqual(a.getReal(), float(10));
			Assert::AreEqual(a.getImag(), float(5));
			a = a.add(b);
			Assert::AreEqual(a.getReal(), float(20));
			Assert::AreEqual(a.getImag(), float(10));
			Complex c{ -30,-20 };
			a = a.add(c);
			Assert::AreEqual(a.getReal(), float(-10));
			Assert::AreEqual(a.getImag(), float(-10));


			s = 10;
			a = a.add(s);
			Assert::AreEqual(a.getReal(), float(0));
			Assert::AreEqual(a.getImag(), float(-10));
			s = -11;
			a = a.add(s);
			Assert::AreEqual(a.getReal(), float(-11));
			Assert::AreEqual(a.getImag(), float(-10));
		}

		TEST_METHOD(Complex_Subtraction)
		{
			Complex a, b{ 10,5 }, c{ -10,-5 };
			float s;
			s = 0;
			a = a.subtract(s);
			Assert::AreEqual(a.getReal(), float(0));
			Assert::AreEqual(a.getImag(), float(0));

			a = a.subtract(b);
			Assert::AreEqual(a.getReal(), float(-10));
			Assert::AreEqual(a.getImag(), float(-5));

			a = a.subtract(c);
			Assert::AreEqual(a.getReal(), float(0));
			Assert::AreEqual(a.getImag(), float(0));

			s = -2;
			a = a.subtract(s);
			Assert::AreEqual(a.getReal(), float(2));
			Assert::AreEqual(a.getImag(), float(0));

			s = 4;
			a = a.subtract(s);
			Assert::AreEqual(a.getReal(), float(-2));
			Assert::AreEqual(a.getImag(), float(0));
		}

		TEST_METHOD(Complex_Multiplication)
		{
			Complex a{ 1,-1 }, b{ 1,1 }, c, m{ 2,1 }, n{ 3,2 };
			float s;

			c = a.multiply(b);
			Assert::AreEqual(c.getReal(), float(2));
			Assert::AreEqual(c.getImag(), float(0));

			c = a.multiply(a);
			Assert::AreEqual(c.getReal(), float(0));
			Assert::AreEqual(c.getImag(), float(-2));

			c = m.multiply(n);
			Assert::AreEqual(c.getReal(), float(4));
			Assert::AreEqual(c.getImag(), float(7));

			s = -2;
			c = c.multiply(s);
			Assert::AreEqual(c.getReal(), float(-8));
			Assert::AreEqual(c.getImag(), float(-14));

			c = c.multiply(n);
			Assert::AreEqual(c.getReal(), float(4));
			Assert::AreEqual(c.getImag(), float(-58));

			s = 0;
			c = m.multiply(s);
			Assert::AreEqual(c.getReal(), float(0));
			Assert::AreEqual(c.getImag(), float(0));
		}

		TEST_METHOD(Complex_Division)
		{
			Complex a{ 1,-1 }, b{ 1,1 }, c, m{ 2,1 }, n{ 0,1 }, p{ 12,-8 };
			float s;
			c = a.division(b);
			Assert::AreEqual(c.getReal(), float(0));
			Assert::AreEqual(c.getImag(), float(-1));

			c = m.division(n);
			Assert::AreEqual(c.getReal(), float(1));
			Assert::AreEqual(c.getImag(), float(-2));

			s = -1;
			c = n.division(s);
			Assert::AreEqual(c.getReal(), float(0));
			Assert::AreEqual(c.getImag(), float(-1));

			s = -4;
			c = p.division(s);
			Assert::AreEqual(c.getReal(), float(-3));
			Assert::AreEqual(c.getImag(), float(2));
		}

		TEST_METHOD(Complex_Conjugate)
		{
			Complex a{ 1,-1 }, b{ -1,1 }, c, m{ 2,0 }, n{ 0,1 }, p{ 12,-8 },x;

			x = a.conjugate();
			Assert::AreEqual(x.getReal(), float(1));
			Assert::AreEqual(x.getImag(), float(1));

			x = b.conjugate();
			Assert::AreEqual(x.getReal(), float(-1));
			Assert::AreEqual(x.getImag(), float(-1));

			x = c.conjugate();
			Assert::AreEqual(x.getReal(), float(0));
			Assert::AreEqual(x.getImag(), float(0));
			
			x = m.conjugate();
			Assert::AreEqual(x.getReal(), float(2));
			Assert::AreEqual(x.getImag(), float(0));

			x = n.conjugate();
			Assert::AreEqual(x.getReal(), float(0));
			Assert::AreEqual(x.getImag(), float(-1));

			x = p.conjugate();
			Assert::AreEqual(x.getReal(), float(12));
			Assert::AreEqual(x.getImag(), float(8));
		}

		TEST_METHOD(Complex_Magnitude)
		{
			Complex a{ 1,-1 }, b{ -1,1 }, c, m{ 2,0 }, n{ 0,1 }, p{ 12,-8 };
			double x,value;
			x = a.magnitude();
			x = round(x * 1000.0) / 1000.0;
			value = round(sqrt(2) * 1000.0) / 1000.0;
			Assert::AreEqual(x, value);

			x = b.magnitude();
			x = round(x * 1000.0) / 1000.0;
			value = round(sqrt(2) * 1000.0) / 1000.0;
			Assert::AreEqual(x, value);

			x = c.magnitude();
			Assert::AreEqual(x, 0.0);

			x = m.magnitude();
			Assert::AreEqual(x, 2.0);

			x = n.magnitude();
			Assert::AreEqual(x, 1.0);
			
			x = p.magnitude();
			x = round(x * 1000.0) / 1000.0;
			value = round(sqrt(208) * 1000.0) / 1000.0;
			Assert::AreEqual(x, value);
			
		}
		
		TEST_METHOD(Complex_Phase)
		{
			Complex a{ 1,-1 }, b{ -1,1 }, c, m{ 2,0 }, n{ 0,1 }, p{ 12,-8 };
			double x, value;

			x = a.phase();
			x = round(x * 1000.0) / 1000.0;
			value = round(asin(-1.0 / sqrt(2)) * 1000.0) / 1000.0;
			Assert::AreEqual(x, value);
			
			x = b.phase();
			x = round(x * 1000.0) / 1000.0;
			value = round(asin(1.0 / sqrt(2)) * 1000.0) / 1000.0;
			Assert::AreEqual(x, value);

			x = c.phase();
			Assert::AreEqual(x, 0.0);

			x = m.phase();
			Assert::AreEqual(x, 0.0);

			x = n.phase();
			Assert::AreEqual(x, asin(1.0));

			x = p.phase();
			x = round(x * 1000.0) / 1000.0;
			value = round(asin(-8.0 / sqrt(208)) * 1000.0) / 1000.0;
			Assert::AreEqual(x, value);
		}

		TEST_METHOD(Complex_ToPolar)
		{
			Complex a{ 1,1 }, b{ -1,1 }, c, m{ -2,-1 }, n{ 2,-1 }, p{ 0,-8 }, q{ 2,0 };
			float r, theta;

			a.toPolar(&r, &theta);
			r = round(r * 1000.0) / 1000.0;
			theta = round(theta * 1000.0) / 1000.0;
			Assert::AreEqual(r, float(1.414));
			Assert::AreEqual(theta, float(45));

			b.toPolar(&r, &theta);
			r = round(r * 1000.0) / 1000.0;
			theta = round(theta * 1000.0) / 1000.0;
			Assert::AreEqual(r, float(1.414));
			Assert::AreEqual(theta, float(135));

			c.toPolar(&r, &theta);
			r = round(r * 1000.0) / 1000.0;
			theta = round(theta * 1000.0) / 1000.0;
			Assert::AreEqual(r, float(0));
			Assert::AreEqual(theta, float(0));

			m.toPolar(&r, &theta);
			r = round(r * 1000.0) / 1000.0;
			theta = round(theta * 1000.0) / 1000.0;
			Assert::AreEqual(r, float(2.236));
			Assert::AreEqual(theta, float(-153.435));

			n.toPolar(&r, &theta);
			r = round(r * 1000.0) / 1000.0;
			theta = round(theta * 1000.0) / 1000.0;
			Assert::AreEqual(r, float(2.236));
			Assert::AreEqual(theta, float(-26.565));

			p.toPolar(&r, &theta);
			r = round(r * 1000.0) / 1000.0;
			theta = round(theta * 1000.0) / 1000.0;
			Assert::AreEqual(r, float(8.0));
			Assert::AreEqual(theta, float(-90));

			q.toPolar(&r, &theta);
			r = round(r * 1000.0) / 1000.0;
			theta = round(theta * 1000.0) / 1000.0;
			Assert::AreEqual(r, float(2.0));
			Assert::AreEqual(theta, float(0));
		}





		TEST_METHOD(DynamicArray_Constructor)
		{
			DynamicArray arr,arr2;
			Assert::AreEqual(arr.getLength(), 0);
			Assert::AreEqual(arr.getCapacity(), 100);
			
			arr = arr + Complex{ 100,100 };
			Assert::AreEqual(arr.getLength(), 1);
			Assert::AreEqual(arr2.getCapacity(), 100);

			arr2 = arr;                       //copy constructor
			Assert::AreEqual(arr2.getLength(), 1);
			Assert::AreEqual(arr2.getCapacity(), 100);
		}

		TEST_METHOD(DynamicArray_AddLast)
		{
			DynamicArray arr;
			for (int i = 1; i <= 110; i++)
				arr.addLast(Complex{ 100,100 });
			Assert::AreEqual(arr.getLength(), 110);
			Assert::AreEqual(arr.getCapacity(), 200);

			arr = arr + Complex{ 100,100 };
			Assert::AreEqual(arr.getLength(), 111);
			Assert::AreEqual(arr.getCapacity(), 200);
		}

		TEST_METHOD(DynamicArray_RemoveLast)
		{
			DynamicArray arr;
			for (int i = 1; i <= 110; i++)
				arr.addLast(Complex{ 100,100 });
			Assert::AreEqual(arr.getLength(), 110);


			for (int i = 1; i <= 10; i++)
				arr.removeLast();
			Assert::AreEqual(arr.getLength(), 100);
		}
	};
}
