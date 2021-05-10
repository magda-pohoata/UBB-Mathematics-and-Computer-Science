#include "UI.h"
#include <iostream>

using namespace std;
UI::UI(Controller& c) : m_controller{ c }
{}


void UI::addUI()
{
	try {
		string type, name, architect, country, year, height;
		cout << "Please give the type of the architectural structure you want to add (1 - Church, 2 - Castle): ";
		cin >> type;
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

		m_controller.addController(type, name, architect, year, height, country);
	}
	catch (exception e) { cout << e.what() << endl << endl; }
}

void UI::deleteUI()
{
	try {
		string id;
		cout << "Please enter the id: ";
		cin >> id;
		m_controller.deleteController(id);
	}
	catch (exception e) { cout << e.what() << endl << endl; }
}

void UI::displayAllUI()
{
	try {
		cout << endl;
		m_controller.displayAll();
		cout << endl << endl;
	}
	catch (exception e) { cout << e.what() << endl << endl; }
}

void UI::displayByCountryUI()
{
	try {
		string country;
		cout << "Please enter the name of the country: ";
		cin >> country;
		m_controller.displayByCountryController(country);
	}
	catch (exception e) { cout << e.what() << endl << endl; }
}

void UI::displayByYearUI()
{
	try {
		string year;
		cout << "Please give a year: ";
		cin >> year;
		m_controller.displayByYearController(year);
	}
	catch (exception e) { cout << e.what() << endl << endl; }
}

void UI::displayByTypeUI()
{
	try {
		string type;
		cout << "Please insert the type of object you want to display (1 or 2)" << endl << endl;
		cout << "1 - all churches" << endl << "2 - all castles" << endl;
		cin >> type;
		m_controller.displayByType(type);
	}
	catch (exception e) { cout << e.what() << endl << endl; }
}

void UI::redoUI()
{
	try {
		m_controller.redoController();
	}
	catch (exception e) { cout << e.what() << endl; }
}

void UI::undoUI()
{
	try {
		m_controller.undoController();
	}
	catch (exception e) { cout << e.what() << endl; }
}

void UI::showUI()
{
	char option;
	do {
		cout << "Please insert your option: " << endl;
		cout << "a - Add" << endl << "r - remove" << endl << "d - display all" << endl << "c - display all architectural structures from a specified country" << endl << "y - display all architectural structures built after a specified year" << endl << "t - display all churches or all castles" << endl << "e - exit" << endl << endl << "z - undo" << endl << "x - redo" << endl << endl;

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
		case 't':
			displayByTypeUI();
			break;
		case 'z':
			undoUI();
			break;
		case 'x':
			redoUI();
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
