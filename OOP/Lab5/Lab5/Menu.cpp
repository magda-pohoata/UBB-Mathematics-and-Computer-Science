#include <iostream>
#include "Menu.h"
#include "DynamicArray.h"
#include "Logger.h"
#include "FileLogger.h"
#include "ScreenLogger.h"

using namespace std;

void printOptions()
{
	cout << "Please select an option: " << endl;
	cout << "1 - Display all tasks" << endl;
	cout << "2 - Add a lesson" << endl;
	cout << "3 - Remove a lesson" << endl;
	cout << "4 - Change status of a lesson" << endl;
	cout << "5 - Display all tasks from a given time frame" << endl;
	cout << "6 - Display the amount of money earned in a given time frame" << endl;
	cout << "7 - Exit" << endl;
	cout << endl;
}

void uiAdd(DynamicArray& arr)
{
	Request r;
	cout << "Please introduce a task: " << endl;
	cin >> r;
	cout << endl;
	arr.addLast(r);
}

bool uiDelete(DynamicArray& arr)
{
	int id, position;
	cout << "Please type the id of the task you want to delete: ";
	cin >> id;
	position = arr.search(id);
	if (position != -1)
		return arr.remove(position);
	else
	{
		cout << "Please type a valid id :)" << endl;
		return false;
	}
}

bool uiSetStatus(DynamicArray& arr)
{
	int id, position;
	cout << "Please type the id of the task you want to change the status of: ";
	cin >> id;
	position = arr.search(id);
	if (position != -1)
	{
		int status;
		cout << "Please type the new status:" << endl << endl;
		cout << "0 - UNPAYED" << endl << "1 - PENDING_COMPLETION" << endl << "2 - COMPLETED" << endl;
		cin >> status;

		if (status != 0 and status != 1 and status != 2)
			return false;

		arr.getArray()[position].setStatus(Status(status));
		return true;
	}
	else
	{
		cout << "Please type a valid id :)" << endl;
		return false;
	}
}

void uiDisplay(DynamicArray& arr)
{
	cout << arr;
}

bool verifDates(Date d1, Date d2)
{
	if (d1.year > 2021 or d2.year > 2021 or d1.month > 12 or d2.month > 12 or d1.day > 31 or d2.day > 31)
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

bool uiTaskByDate(DynamicArray& arr)
{
	bool found = false;
	Date dateBegin, dateFinish;
	cout << "Please type the beginning date (day, month, year): ";
	cin >> dateBegin;
	cout << "Please type the finishing date (day, month, year): ";
	cin >> dateFinish;


	//verifies of the input dates are correct
	if (verifDates(dateBegin, dateFinish) == false)
	{
		cout << "Please give valid dates. The first date should be before the second one :)" << endl;
		return false;
	}


	//verifies which tasks are in the tame frame
	for (int i = 0; i < arr.getLength(); i++)
	{
		if (arr.getArray()[i].getDate().year > dateBegin.year and arr.getArray()[i].getDate().year < dateFinish.year)
		{
			cout << arr.getArray()[i];
			found = true;
		}
		else
			if (arr.getArray()[i].getDate().year == dateBegin.year)
			{
				if (arr.getArray()[i].getDate().month > dateBegin.month)
				{
					cout << arr.getArray()[i];
					found = true;
				}
				else
					if (arr.getArray()[i].getDate().month == dateBegin.month)
						if (arr.getArray()[i].getDate().day >= dateBegin.day)
						{
							cout << arr.getArray()[i];
							found = true;
						}
			}
			else
				if (arr.getArray()[i].getDate().year == dateFinish.year)
				{
					if (arr.getArray()[i].getDate().month < dateFinish.month)
					{
						cout << arr.getArray()[i];
						found = true;
					}
					else
						if (arr.getArray()[i].getDate().month == dateFinish.month)
							if (arr.getArray()[i].getDate().day <= dateFinish.day)
							{
								cout << arr.getArray()[i];
								found = true;
							}
				}
	}
	return found;
}

float uiMoneyTimeFrame(DynamicArray& arr)
{
	float sum=0;
	Date dateBegin, dateFinish;
	cout << "Please type the beginning date (day, month, year): ";
	cin >> dateBegin;
	cout << "Please type the finishing date (day, month, year): ";
	cin >> dateFinish;

	//verifies of the input dates are correct
	if (verifDates(dateBegin, dateFinish) == false)
	{
		cout << "Please give valid dates. The first one should be before the second one :)" << endl;
		return false;
	}

	//Computes the amount of money earned in the time frame
	for (int i = 0; i < arr.getLength(); i++)
	{
		if (arr.getArray()[i].getDate().year > dateBegin.year and arr.getArray()[i].getDate().year < dateFinish.year)
		{
			sum = sum + arr.getArray()[i].getPrice();
		}
		else
			if (arr.getArray()[i].getDate().year == dateBegin.year)
			{
				if (arr.getArray()[i].getDate().month > dateBegin.month)
				{
					sum = sum + arr.getArray()[i].getPrice();
				}
				else
					if (arr.getArray()[i].getDate().month == dateBegin.month)
						if (arr.getArray()[i].getDate().day >= dateBegin.day)
						{
							sum = sum + arr.getArray()[i].getPrice();
						}
			}
			else
				if (arr.getArray()[i].getDate().year == dateFinish.year)
				{
					if (arr.getArray()[i].getDate().month < dateFinish.month)
					{
						sum = sum + arr.getArray()[i].getPrice();
					}
					else
						if (arr.getArray()[i].getDate().month == dateFinish.month)
							if (arr.getArray()[i].getDate().day <= dateFinish.day)
							{
								sum = sum + arr.getArray()[i].getPrice();
							}
				}
	}
	return sum;
}

void DisplayMenu(DynamicArray& arr)
{
	string path = "D://VISUAL STUDIO//LOGGER//FileLogger.txt";
	string message;
	//FileLogger fl(path);
	
	char op;
	do {
		printOptions();
		cin >> op;
		switch (op)
		{
		case '1':               //1 - Display all tasks
			uiDisplay(arr);
			break;
		case '2':                //2 - Add a lesson
		{
			uiAdd(arr);
			cout << "Task added :)" << endl << endl;
			message = "You added a task :)";
			//fl.write_message(message);
			break;
		}
		case '3':                  //3 - Remove a lesson
			if (uiDelete(arr) == true)
				cout << "Task deleted :)" << endl << endl;
			else
				cout << "Unable to delete the task :(" << endl << endl;
			break;
		case '4':                   //4 - Change status of a lesson
			if (uiSetStatus(arr) == true)
				cout << "Status updated :)" << endl << endl;
			else
				cout << "Unable to change the status for that id :(" << endl << endl;
			break;
		case '5':                   //5 - Display all tasks from a given time frame 
			if (uiTaskByDate(arr) == false)
				cout << "Sorry, no tasks from the time frame given :(" << endl << endl;
			else
				cout << endl << endl;
			break;
		case '6':                   //6 - Display the amount of money earned in a given time frame
		{
			float sum = uiMoneyTimeFrame(arr);
			if (sum == 0)
				cout << "No money earned in that time frame :(" << endl << endl;
			else
				cout << "There were earned " << sum << " lei in that time frame :)" << endl << endl;
			break;
		}
		case '7':
			cout << "Bye-bye!!!" << endl << endl;
			exit(0);
		default:
			cout << "Unknown option: " << op << endl << "Try again" << endl;
			continue;
		}
	} while (true);
}