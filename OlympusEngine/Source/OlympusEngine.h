// pre-compiled header

#ifndef __OLYMPUS_ENGINE_H
#define __OLYMPUS_ENGINE_H

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

//#define HInstance() GetModuleHandle(NULL) // solution for only windows programs, without platform-independent layer
// discussion: https://stackoverflow.com/questions/21718027/getmodulehandlenull-vs-hinstance
//const size_t MAX_NAME_LENGTH = 256;

#endif // __OLYMPUS_ENGINE_H