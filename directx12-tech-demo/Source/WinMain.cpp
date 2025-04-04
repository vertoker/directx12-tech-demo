/* ---------------------------------------------------------- */
/* Filename: WinMain.cpp                                      */
/* Author: vertoker (Based on OlympusMonsTutorials)           */
/* License: MIT License                                       */
/* ---------------------------------------------------------- */



#include "pch.h"

/* ---------------------------------------------------------- */
/* Global Variables                                           */
/* ---------------------------------------------------------- */
#pragma region Global Variables

// I prefer define const variables, or you can use wcscpy_s and TEXT in runtime
WCHAR ProgramName[MAX_NAME_LENGTH];
WCHAR WindowTitle[MAX_NAME_LENGTH];

// Initial Window size
INT InitialWindowWidth;
INT InitialWindowHeight;

HICON hIcon; // default program icon

#pragma endregion
/* ---------------------------------------------------------- */

/* ---------------------------------------------------------- */
/* Declarations                                               */
/* ---------------------------------------------------------- */
#pragma region Declarations

VOID InitializeGlobalVariables();
VOID InitializeWindowClass();
VOID InitializeWindow();

LRESULT CALLBACK CreateWindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam);

#pragma endregion
/* ---------------------------------------------------------- */

/* ---------------------------------------------------------- */
/* Definitions                                                */
/* ---------------------------------------------------------- */
#pragma region Definitions

VOID InitializeGlobalVariables()
{
	LoadString(HInstance(), IDS_PROGRAMNAME, ProgramName, MAX_NAME_LENGTH);
	LoadString(HInstance(), IDS_WINDOWNAME, WindowTitle, MAX_NAME_LENGTH);

	InitialWindowWidth = 1366; // Default window width in Windows
	InitialWindowHeight = 768; // Default window height in Windows
	hIcon = LoadIcon(HInstance(), MAKEINTRESOURCE(LOGO_ICO));
}

VOID InitializeWindowClass()
{
	WNDCLASSEX wcex{}; // class with information about self window

	// https://learn.microsoft.com/ru-ru/windows/win32/api/winuser/ns-winuser-wndclassexa
	wcex.cbSize = sizeof(WNDCLASSEX);      // size of self, this for C
	wcex.style = CS_HREDRAW | CS_VREDRAW; // styles of class, window must redraw horizontal and vertical window resizing
	wcex.cbClsExtra = 0;                       // extra bytes to allocate after that class allocation (allocate where)
	wcex.cbWndExtra = 0;                       // same but for instance of class (whatever it is)

	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);           // set default cursor to render in window
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH); // set background color for window is white

	// Set icons of program, set later
	wcex.hIcon = hIcon;   // icon from top left corner of window
	wcex.hIconSm = hIcon; // icon for task bar

	wcex.lpszClassName = ProgramName; // add name for window
	wcex.lpszMenuName = nullptr;      // menu name for game is not normally included

	wcex.hInstance = HInstance(); // add self instance for this

	wcex.lpfnWndProc = CreateWindowProcess; // for all behaviour, that I doesn't implement for window

	RegisterClassEx(&wcex);
}

VOID InitializeWindow()
{
	HWND hWnd = CreateWindow(
		ProgramName,         // Program name in Windows
		WindowTitle,         // Window Title itself
		WS_OVERLAPPEDWINDOW, // Window Style, default
		CW_USEDEFAULT,       // Initial X position
		0,                   // Initial Y position
		InitialWindowWidth,  // Initial Width
		InitialWindowHeight, // Initial Height
		nullptr,             // Parent Window, if parent close - this close
		nullptr,             // This is game engine, no menu
		HInstance(),         // Instance of this program
		nullptr              // Specific instructions for Window
	);

	if (!hWnd) // not assert because it's Windows error
	{
		MessageBox(0, TEXT("Failed to Create Window"), 0, 0);
		PostQuitMessage(0);
		return;
	}

	ShowWindow(hWnd, SW_SHOW); // show window with SHOW command (nCmdShow by default)
}

/// <summary>              Create new WindowProc, for this app   </summary>
/// <param name="hWnd">    Copy of window handler                </param>
/// <param name="message"> Message type parameter (clos, resize) </param>
/// <param name="wparam">  Parameter W for message               </param>
/// <param name="lparam">  Parameter L for message               </param>
LRESULT CALLBACK CreateWindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
	case WM_DESTROY: // if message was close window
		PostQuitMessage(0); // shutdown program itself
		break;
	}

	return DefWindowProc(hWnd, message, wparam, lparam);
}

#pragma endregion
/* ---------------------------------------------------------- */
