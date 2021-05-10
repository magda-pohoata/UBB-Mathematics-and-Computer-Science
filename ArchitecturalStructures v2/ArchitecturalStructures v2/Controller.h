#pragma once
#include "Repository.h"
#include <stack>

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

	void addController(ArchitecturalStructure* a);
	void deleteController(int id);
	void displayByCountryController(string country);
	void displayByYearController(int year);
	void displayByType(string);

	void displayAll();

private:
	Repository m_repo;
	std::stack<pair<ActionType,ArchitecturalStructure*>> m_undoStack;
	std::stack<pair<ActionType, ArchitecturalStructure*>> m_redoStack;
};

