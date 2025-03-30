#ifndef __PCH_H
#define __PCH_H

#include <Windows.h>

#include "../resource.h"

#define HInstance() GetModuleHandle(NULL) // solution for only windows programs, without platform-independent layer
// discussion: https://stackoverflow.com/questions/21718027/getmodulehandlenull-vs-hinstance

#endif // _PCH_H