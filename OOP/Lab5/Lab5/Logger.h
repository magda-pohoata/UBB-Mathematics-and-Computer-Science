#pragma once
#include <string>
#include <fstream>
using namespace std;


class Logger {
public:
	virtual void write_message(std::string message) {} 
private:
	int m_logIndex;
};