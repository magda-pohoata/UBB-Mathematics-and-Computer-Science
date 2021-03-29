#pragma once
#include "Logger.h"

class ScreenLogger : public Logger {

public:
	ScreenLogger() {
		outputFile.open("FileLogger.txt");
	}
	void write_message(std::string message) override; //cout.....

	~ScreenLogger() {
		outputFile.close();
	}

private:
	ifstream outputFile;
};