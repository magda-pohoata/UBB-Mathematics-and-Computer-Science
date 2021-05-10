#include "UI.h"
#include <iostream>

using namespace std;
UI::UI(Controller& c) : m_controller{ c }
{}


void UI::addUI()
{
	string name, architect,country;
	int year, height;
	cout << "Please give the name of the architectural structure: ";
	cin >> name;
	cout << "Please give the name of the architect: ";
	cin >> architect;
	cout << "Please give the year of the construction: ";
	cin >> year;
	cout << "Please give the height of the building: ";
	cin >> height;
	cout << "Please give the name of the country: ";
	cin >> country;
	ArchitecturalStructure* a = new ArchitecturalStructure{ name,architect,year,height,country };
	m_controller.addController(a);
}

void UI::deleteUI()
{
	int id;
	cout << "Please enter the id: ";
	cin >> id;
	m_controller.deleteController(id);
}

void UI::displayAllUI()
{
	cout << endl;
	m_controller.displayAll();
	cout << endl << endl;
}

void UI::displayByCountryUI()
{
	string country;
	cout << "Please enter the name of the country: ";
	cin >> country;
	m_controller.displayByCountryController(country);
}

void UI::displayByYearUI()
{
	int year;
	cout << "Please give a year: ";
	cin >> year;
	m_controller.displayByYearController(year);
}

void UI::showUI()
{
	char option;
	do {
		cout << "Please insert your option: " << endl;
		cout << "a - Add" << endl << "r - remove" << endl << "d - display all" << endl << "c - display all architectural structures from a specified country" << endl << "y - display all architectural structures built after a specified year" << endl << "e - exit" << endl << endl << "z - undo" << endl << "x - redo" << endl << endl;

		cin >> option;
		switch (option)
		{
		default:
			break;
		case 'a':
			addUI();
			break;
		case 'r':
			deleteUI();
			break;
		case 'd':
			displayAllUI();
			break;
		case 'c':
			displayByCountryUI();
			break;
		case 'y':
			displayByYearUI();
			break;
		case 'z':
			break;
		case 'x':
			break;
		case 'e':
			m_controller.writeToCSV();
			exit(0);
			break;
		}
	} while (true);
}

void UI::initialize()
{
	m_controller.initialize();
	showUI();
}
