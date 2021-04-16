#include "Stiva.h"
#include "ArchitecturalStructure.h"
#include "Castle.h"
#include "Church.h"
#include "Pavilion.h"

#include <iostream>
using namespace std;

int main() {

	bool ok;
	Materials m = Materials(2);
	ArchitecturalStructure arc{ "a","b",3,43,"e" },arc1;
	Pavilion p{ "Luum","andreea",2010,6,"Norway" ,m }, p1;
	Stiva<ArchitecturalStructure> s;
	//cout << arc;
	//cout << p << p1;
	s.push(arc);
	arc1= s.front(ok);
	cout << arc1;

	vector<Pavilion> vect;
	vect.push_back(p);
	vect.push_back(p1);
	//for (int i = 0; i < vect.size(); i++)
		//cout << vect[i];
}

