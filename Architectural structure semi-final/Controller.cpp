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

void Controller::addController(string t,string name,string architect,string y,string h,string country)
{
	int type,year,height;
	stringstream ss,ss1,ss2;
	ss << t;
	ss >> type;
	if (type == 0) {
		throw exception("The type must be integer");
	}
	ss1 << y;
	ss1 >> year;
	if (year == 0) {
		throw exception("The year must be integer");
	}
	ss2 << h;
	ss2 >> height;
	if (height == 0) {
		throw exception("The height must be integer");
	}
	ArchitecturalStructure* a = new ArchitecturalStructure{ type,name,architect,year,height,country };
	m_repo.addRepo(a);
	m_undoStack.push(std::make_pair(ActionType::ADD, a));
}

void Controller::deleteController(string id)
{
	int ID;
	stringstream ss;
	ss << id;
	ss >> ID;
	if (ID == 0) {
		throw exception("The id must be integer");
	}

	ArchitecturalStructure* a = m_repo.deleteRepo(ID);
	if (a)
		m_undoStack.push(std::make_pair(ActionType::REMOVE, a));
}

void Controller::displayByCountryController(string country)            //idk how to do the pointer function if i have to capture something in the lambda function
{
	//m_repo.display(std::cout, [country](ArchitecturalStructure* a)->bool {
		//return a->getCountry() == country;
		//});
}

void Controller::displayByYearController(string y)           //idk how to do the pointer function if i have to capture something in the lambda function
{
	int year;
	stringstream ss;
	ss << y;
	ss >> year;
	if (year == 0) {
		throw exception("The year must be integer");
	}

	m_repo.displayByYear(year);

	/*
	auto funct = [](ArchitecturalStructure* a)->bool {
		return a->getYear() >= 2000;
	};
	m_repo.display(std::cout, funct);
	*/
}

void Controller::displayByType(string type)
{
	if (type != "1" && type != "2")
		throw exception("Incorrect type");
	else
		m_repo.displayByType(type);
}

void Controller::undoController()
{
	if (m_undoStack.size() == 0)
		throw exception("Nothing to undo");


	if (m_undoStack.top().first == ActionType::ADD)      //if the last action was ADD
	{
		m_repo.deleteRepo(m_undoStack.top().second->getId());
		m_redoStack.push(std::make_pair(ActionType::ADD, m_undoStack.top().second));
	}
	else                                              //if the last action was REMOVE
	{
		m_repo.addRepo(m_undoStack.top().second);
		m_redoStack.push(std::make_pair(ActionType::REMOVE, m_undoStack.top().second));
	}

	m_undoStack.pop();
}

void Controller::redoController()
{
	if (m_redoStack.size() == 0)
		throw exception("Nothing to redo");

	if (m_redoStack.top().first == ActionType::ADD)
	{
		m_repo.addRepo(m_redoStack.top().second);
		m_undoStack.push(std::make_pair(ActionType::ADD, m_redoStack.top().second));
	}
	else                                            
	{
		m_repo.deleteRepo(m_redoStack.top().second->getId());
		m_undoStack.push(std::make_pair(ActionType::REMOVE, m_redoStack.top().second));
	}

	m_redoStack.pop();
}

void Controller::displayAll()
{
	//ostream& os, bool(*filterFunction)(ArchitecturalStructure * a)
	m_repo.display(std::cout, [](ArchitecturalStructure* a)->bool {return true; });
}
