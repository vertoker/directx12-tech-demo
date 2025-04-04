#ifndef __APPLICATION_H
#define __APPLICATION_H

#include "Platform/WIN32/IApplication.h"

class Application : public IApplication
{
public:
	Application();
	~Application();

	VOID Initialize();
	VOID Update();
};

#endif // __APPLICATION_H