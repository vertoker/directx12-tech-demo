#ifndef __WIN32_IAPPLICATION_H
#define __WIN32_IAPPLICATION_H

class IApplication
{
public:
	IApplication();
	virtual ~IApplication() = 0;

	virtual VOID Initialize() = 0;
	virtual VOID Update() = 0;
};

#endif // __WIN32_IAPPLICATION_H