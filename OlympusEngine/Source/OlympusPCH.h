#ifndef __OLYMPUS_PCH_H
#define __OLYMPUS_PCH_H

#ifdef WIN32
#include <Windows.h>
#endif

#ifdef BUILD_DLL
// build as dll if engine macro
#define OLYMPUS_API __declspec(dllexport)
#else
// otherwise import it
#define OLYMPUS_API __declspec(dllimport)
#endif

#endif // __OLYMPUS_PCH_H