#include "Logger.h"

Logger* Logger::instance;

Logger::Logger()
{
	instance = this;
}
Logger::~Logger()
{
	instance = nullptr;
}
