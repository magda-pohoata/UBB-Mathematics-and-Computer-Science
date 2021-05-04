#pragma once
#include "Repository.h"


class Controller
{
public:
	Controller(Repository& r);

	void initialize();
	void displayAll();
	void addAnimal(string,string);
	void updateName(string, string);
	void deleteAnimal(string);
	void writeToCSV();

private:
	Repository m_repo;
};

