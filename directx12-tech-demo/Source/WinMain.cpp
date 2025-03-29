#include <Windows.h>

// I prefer define const variables, or you can use wcscpy_s and TEXT in runtime
const WCHAR* ProgramName = TEXT("directx12-tech-demo");
const WCHAR* WindowTitle = TEXT("DirectX 12 Tech Demo");

const INT WindowWidth = 1366; // Default window width in Windows
const INT WindowHeight = 768; // Default window height in Windows

#define HInstance() GetModuleHandle(NULL) // solution for only windows programs, without platform-independent layer
// discussion: https://stackoverflow.com/questions/21718027/getmodulehandlenull-vs-hinstance


// declaration for usage
WNDCLASSEX CreateWindowClass();

/// <summary>                main(), but for Windows               </summary>
/// <param name="hInstance">     Windows instance of this program      </param>
/// <param name="hPrevInstance"> Previous instance of legacy programs  </param>
/// <param name="lpCmdLine">     C-string of input arguments in launch </param>
/// <param name="nCmdShow">      Command to show window or not         </param>
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow)
{
	// Create Window Class

	WNDCLASSEX wcex = CreateWindowClass();
	RegisterClassEx(&wcex);

	// Create and Display our Window

	HWND hWnd = CreateWindow(
		ProgramName,         // Program name in Windows
		WindowTitle,         // Window Title itself
		WS_OVERLAPPEDWINDOW, // Window Style, default
		CW_USEDEFAULT,       // Initial X position
		0,                   // Initial Y position
		WindowWidth,         // Initial Width
		WindowHeight,        // Initial Height
		nullptr,             // Parent Window, if parent close - this close
		nullptr,             // This is game engine, no menu
		HInstance(),         // Instance of this program
		nullptr              // Specific instructions for Window
	);

	if (!hWnd) // not assert because it's Windows error
	{
		MessageBox(0, L"Failed to Create Window", 0, 0);
		return 0;
	}

	ShowWindow(hWnd, SW_SHOW); // show window with SHOW command (nCmdShow by default)

	// Listen for Message events

	MSG msg = { 0 }; // message class for events

	while (msg.message != WM_QUIT) // run program until received message is quit
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) // if any messages are received
		{
			TranslateMessage(&msg); // translate messages
			DispatchMessage(&msg);  // send messages to Windows system
		}
	}

	return 0;
}

WNDCLASSEX CreateWindowClass()
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
	wcex.hIcon = LoadIcon(0, IDI_APPLICATION);   // icon from top left corner of window
	wcex.hIconSm = LoadIcon(0, IDI_APPLICATION); // icon for task bar

	wcex.lpszClassName = ProgramName; // add name for window
	wcex.lpszMenuName = nullptr;      // menu name for game is not normally included

	wcex.hInstance = HInstance(); // add self instance for this

	wcex.lpfnWndProc = DefWindowProc; // for all behaviour, that I doesn't implement for window

	return wcex;
}
