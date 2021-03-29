#include "Complex.h"
#include "DynamicArray.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	Complex a, b{-5,-2},sum;
	float r, t;
	a.setReal(2);
	a.setImag(0);
	a.toPolar(&r,&t);
	cout << r << " " << t << endl;

	
	ifstream file;
	file.open("complex_numbers.txt");
	
	
	float re, im;
	while (file >> re >> im)
	{
		a.setReal(re);
		a.setImag(im);
		
		sum = sum + a;
	}
	cout << sum;
	
	file.close();

	//cin >> a;

	/*
	cout << b.phase() << endl;
	float r, theta;
	b.toPolar(&r, &theta);
	cout << r << " " << theta;
	*/

	/*
	Complex c = a + b;
	cout << a << endl << b << endl << c << endl;

	
	Complex* e = new Complex;
	cin >> *e;
	cout << *e <<e;
	cout << *e + a;
	cout << (*e).add(a);
	cout << e->add(a);
	cout << a.add(*e) << endl;

	cout << a.getReal() << endl;

	cout << a.equal(b) << endl << endl;
	

	DynamicArray arr;
	arr = arr + a;
	arr + b;
	arr.addLast(Complex{ 100,200 });
	cout << arr;


	DynamicArray arr2 = arr;   //copy constructor
	arr2[0] = Complex{ 111,222 };

	cout << "Arr 1: " << arr << endl;
	cout << "Arr 2: " << arr2 << endl;

	delete e;
	*/

	//DynamicArray arr;
	//arr.addLast(b);
	//cout << arr << " " << arr.getLength();

	/*
	DynamicArray arr;
	arr = arr + a;
	arr + b;
	arr.addLast(Complex{ 100,200 });
	cout << arr;

	arr.removeLast();
	cout << arr;

	//cout << a.division(b);
	*/

	return 0;
}
