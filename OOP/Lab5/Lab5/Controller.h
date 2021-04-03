#pragma once
#include "Repo.h"
class Controller
{
public:
	Controller() = default;
	Controller(Repo repo) { this->repo = repo; }
	
	Repo getRepo() { return this->repo; }


	bool verifDates(Date, Date);
	bool verifStatus(int);
	DynamicArray display();
	int searchById(int);
	bool add(int);
	bool remove(int);
	void setStatus(int, Status);
	bool tasksByDate(Date, Date);
	float moneyTimeFrame(Date, Date);


private:
	Repo repo;
	
};

