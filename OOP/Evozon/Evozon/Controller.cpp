#include "Controller.h"
#include <sstream>
using namespace std;

Controller::Controller(Repository& r)
{
	m_repo = r;
}

void Controller::initialize()
{
	m_repo.loadFromCSV("ZooCatalog.csv");
}

void Controller::displayAll()
{
	try
	{
		m_repo.displayAll();
		
	}
	catch(...){ throw exception("Nothing in the catalog"); }
}

void Controller::addAnimal(string animal,string name)
{
	int a=1, b=1;
	stringstream ss1,ss2;
	ss1 << animal;
	ss1 >> a;
	ss2 << name;
	ss2 >> b;
	if (a != 0 or b != 0)    //we try to convert the strings animal and name to integer to look for errors
	{
		throw exception("The name can't contain integer numbers");
	}
	
	if (animal != "" and name != "")    //we can't have empty strings
	{
		ZooCatalog zoo { animal,name };
		m_repo.addAnimal(zoo);
	}
	else
	{
		throw exception("The animal type and name can't be null");
	}
}


void Controller::updateName(string id, string name)
{
	int ID,name1;       //we try to convert the strings id and name to integer to look for errors
	stringstream ss,ss1;
	ss << id;
	ss >> ID;
	if (ID == 0)          
	{
		throw exception("The ID must be a integer");
	}
	ss1 << name;
	ss1 >> name1;
	if (name1 != 0)
	{
		throw exception("The name can't contain integer numbers");
	}

	if (name == "")    //we can't have empty strings
	{
		throw exception("The name can't be null");
	}

	m_repo.updateName(ID, name);

	
}

void Controller::deleteAnimal(string id)
{
	int ID;                 //we try to convert the strings id to integer to look for errors
	stringstream ss;
	ss << id;
	ss >> ID;
	if (ID == 0)
	{
		throw exception("The ID must be a integer");
	}

	m_repo.deleteAnimal(ID);

}

void Controller::writeToCSV()
{
	m_repo.writeToCSV("ZooCatalog.csv");
}
