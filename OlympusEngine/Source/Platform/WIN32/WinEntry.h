#include "OlympusEngine.h"

#include "IApplication.h"

extern IApplication* EntryApplication();

/// <summary>                    main(), but for Windows               </summary>
/// <param name="hInstance">     Windows instance of this program      </param>
/// <param name="hPrevInstance"> Previous instance of legacy programs  </param>
/// <param name="lpCmdLine">     C-string of input arguments in launch </param>
/// <param name="nCmdShow">      Command to show window or not         </param>
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow)
{
	IApplication* entryApplication = EntryApplication();

	entryApplication->Initialize();

	MSG msg = { 0 }; // message class for events

	while (msg.message != WM_QUIT) // run program until received message is quit
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) // if any messages are received
		{
			TranslateMessage(&msg); // translate messages
			DispatchMessage(&msg);  // send messages to Windows system
		}
		else
		{
			entryApplication->Update();
		}
	}

	delete entryApplication;

	return 0;
}