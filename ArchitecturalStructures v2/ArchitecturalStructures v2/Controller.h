#pragma once
#include "Repository.h"
#include <stack>
#include <sstream>

enum class ActionType {
	ADD,
	REMOVE
};

using namespace std;
class Controller
{
public:
	Controller(Repository& r);

	void initialize();
	void writeToCSV();

	void addController(string,string,string,string,string,string);
	void deleteController(string id);
	void displayByCountryController(string country);
	void displayByYearController(string year);
	void displayByType(string);

	void displayAll();

private:
	Repository m_repo;
	std::stack<pair<ActionType,ArchitecturalStructure*>> m_undoStack;
	std::stack<pair<ActionType, ArchitecturalStructure*>> m_redoStack;
};

