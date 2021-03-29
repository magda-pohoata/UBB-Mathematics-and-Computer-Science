#pragma once

#include "Logger.h"

class FileLogger : public Logger {
public:

	FileLogger(std::string filepath) {
		//open file
		
		outputFile.open(filepath);
	}

	void write_message(std::string message) override;

	~FileLogger() {
		//close file
		outputFile.close();
	}

private:
	ofstream outputFile;
};