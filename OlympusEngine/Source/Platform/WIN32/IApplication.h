#ifndef __WIN32_IAPPLICATION_H
#define __WIN32_IAPPLICATION_H

#include "OlympusPCH.h"

#define ENTRYAPP(x) IApplication* EntryApplication() { return new x; }

class OLYMPUS_API IApplication
{
public:
	IApplication();
	virtual ~IApplication() { }

	virtual VOID Initialize() = 0;
	virtual VOID Update() = 0;
};

#endif // __WIN32_IAPPLICATION_H