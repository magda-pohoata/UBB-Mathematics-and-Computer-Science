#include <iostream>

#include "ScreenLogger.h"

using namespace std;

void ScreenLogger::write_message(std::string message)
{
	string line;
	while (getline(outputFile, line))
	{
		cout << line;
	}
}
