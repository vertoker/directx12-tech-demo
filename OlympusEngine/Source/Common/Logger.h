#ifndef __OLYMPUS_LOGGER_H
#define __OLYMPUS_LOGGER_H

#include "OlympusPCH.h"

class OLYMPUS_API Logger
{
private:
	static Logger* instance;
public:
	static Logger* Instance() { return instance; }

public:
	Logger();
	~Logger();

	//static VOID 
};

#endif // __OLYMPUS_LOGGER_H