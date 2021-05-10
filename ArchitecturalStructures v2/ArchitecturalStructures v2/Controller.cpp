#include "Controller.h"
#include <iostream>

Controller::Controller(Repository& r)
{
	m_repo = r;
}

void Controller::initialize()
{
	std::string CSVfile = "ArchitecturalStructure.csv";
	m_repo.loadFromCSV(CSVfile);
}

void Controller::writeToCSV()
{
	string CSVfile = "ArchitecturalStructure.csv";
	m_repo.writeToCSV(CSVfile);
}

void Controller::addController(ArchitecturalStructure* a)
{
	m_repo.addRepo(a);
	m_undoStack.push(std::make_pair(ActionType::ADD, a));
}

void Controller::deleteController(int id)
{
	ArchitecturalStructure* a = m_repo.deleteRepo(id);
	if (a)
		m_undoStack.push(std::make_pair(ActionType::REMOVE, a));
}

void Controller::displayByCountryController(string country)            //idk how to do the pointer function if i have to capture something in the lambda function
{
	m_repo.display(std::cout, [](ArchitecturalStructure* a)->bool {
		return a->getCountry() == "Spain";
		});
}

void Controller::displayByYearController(int year)           //idk how to do the pointer function if i have to capture something in the lambda function
{
	auto funct = [](ArchitecturalStructure* a)->bool {
		return a->getYear() >= 2000;
	};
	m_repo.display(std::cout, funct);
}

void Controller::displayByType(string type)
{
	if (type != "1" && type != "2")
		throw exception("Incorrect type");
	else
		m_repo.displayByType(type);
}

void Controller::displayAll()
{
	//ostream& os, bool(*filterFunction)(ArchitecturalStructure * a)
	m_repo.display(std::cout, [](ArchitecturalStructure* a)->bool {return true; });
}
