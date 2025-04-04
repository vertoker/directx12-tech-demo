#include "pch.h"
#include "Application.h"
#include "Platform/WIN32/WinEntry.h"

ENTRYAPP(Application)

Application::Application()
{

}
Application::~Application()
{

}

VOID Application::Initialize()
{
	//MessageBox(0, L"Initialize", L"Message", 0); // annoying and block thread
	//OutputDebugString(L"Initialize Debug String"); // works only in debug console
}
VOID Application::Update()
{
	//MessageBox(0, L"Update", L"Message", 0);
}
