#include "Controller.h"


int Controller::searchById(int id)
{
	return this->repo.searchById(id);
}

bool Controller::add(int choice)
{
	
	OfflineLesson off;
	if (choice == 1)
	{
		cout << endl << "Please introduce a task: " << endl;
		try
		{
			OnlineLesson* on= new OnlineLesson;
			cin >> *on;
			cout << endl;
			Request* r = on;
			this->repo.addTask(*r);
			return true;
		}
		catch (std::runtime_error& e) {
			cout << "Please give correct data :(" << endl;
		}
		catch (int e)
		{
			cout << "Please give correct data :(" << endl;
		}
		return false;
	}
	else
		if (choice == 2)
		{
			cout << endl << endl << "Please introduce a task: " << endl;
			try
			{
				OfflineLesson* off=new OfflineLesson;
				cin >> *off;
				cout << endl;
				Request* r = off;
				this->repo.addTask(*r);
				return true;
			}
			catch (std::runtime_error& e) {
				cout << "Please give correct data :(" << endl;
			}
			catch (int e)
			{
				cout << "Please give correct data :(" << endl;
			}
			return false;
		}
		else
		{
			cout << "Please type a correct type of choice :)" << endl;
			return false;
		}
}

bool Controller::remove(int position)
{
	return this->repo.deleteTask(position);
}

void Controller::setStatus(int position, Status status)
{
	this->repo.setStatus(position, status);
}

bool Controller::tasksByDate(Date dateBegin, Date dateFinish)
{
	return this->repo.tasksByDate(dateBegin, dateFinish);
	
}

float Controller::moneyTimeFrame(Date dateBegin, Date dateFinish)
{
	return this->repo.moneyTimeFrame(dateBegin, dateFinish);
}

bool Controller::verifDates(Date d1, Date d2)
{
	if (d1.year > 2022 or d2.year > 2022 or d1.month > 12 or d2.month > 12 or d1.day > 31 or d2.day > 31)
		return false;

	if (d1.year < d2.year)
		return true;
	else
		if (d1.year == d2.year)
			if (d1.month < d2.month)
				return true;
			else
				if (d1.day <= d2.day)
					return true;

	return false;
}

bool Controller::verifStatus(int status)
{
	if (status != 0 and status != 1 and status != 2)
		return false;
	return true;
}

DynamicArray Controller::display()
{
	return this->repo.display();
}


