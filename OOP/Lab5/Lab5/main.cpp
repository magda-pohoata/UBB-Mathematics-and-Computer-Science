// Request - base
// OnlineLesson - deriva din request
// HomeworkSession - deriva din request


#include <string>
#include <vector>

#include "Request.h"
#include "OnlineLesson.h"
#include "OfflineLesson.h"
#include "Logger.h"
#include "ScreenLogger.h"
#include "FileLogger.h"
#include "Menu.h"
#include "DynamicArray.h"



int main()
{
	/*
	Date date{ 1,2,3 };
	char* z = new char[20];
	char* a = new char[20];
	strcpy(z, "no subject");
	Request r, r1{ z,date,float(2.13) },r2;
	OnlineLesson o;
	
	cout << z << endl << o;
	strcpy(a, z);
	cout << a<<endl;
	cout << date;
	delete[] z;
	delete[] a;
	*/

	//string path = "D://VISUAL STUDIO//LOGGER//FileLogger.txt";
	//string message = "Hei :)";
	//FileLogger fl(path);
	//fl.write_message(message);


	//std::vector<Request*> tasks;

	Date date{ 1,1,2021 }, date1{9,9,2010},date2;

	DynamicArray arr;

	OnlineLesson o;
	OfflineLesson l;
	Request r;
	r.setDate(date);
	o.setDate(date);
	l.setDate(date1);
	r.setPrice(float(2));
	o.setPrice(float(3));
	arr.addLast(o);
	arr.addLast(l);
	arr.addLast(r);
	cout << arr;


	DisplayMenu(arr);
	
	
	return 0;
}


