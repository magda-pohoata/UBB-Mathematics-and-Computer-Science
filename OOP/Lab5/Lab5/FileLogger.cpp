#include "FileLogger.h"

void FileLogger::write_message(std::string message)
{
	outputFile << message;
}
