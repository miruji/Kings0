#pragma once
#define _CRT_SECURE_NO_WARNINGS
	__pragma(warning(push, 0))

#pragma optimize( "g", on )
#pragma optimize( "t", on )

#include <iostream>
#include <windows.h>
using namespace std;

// Main stream function of Kings0 
int main(size_t argc, char* argv[])
{
	ShowWindow(GetConsoleWindow(), SW_HIDE); // hide console

	// Disclaimer
	cout << "# Kingso, Copyright by Sergeev Anatoly (UncleSergy)" << endl;

	// Start Kings0 Launcher 
		// Console title 
		SetConsoleTitleW(L"Kingso");

		// Console position 
		HWND WindowHeader = GetConsoleWindow();
		SetWindowPos(WindowHeader, HWND_TOP, -8, 0, 800, 600, NULL);

	// Start Kings0 Engine 
		// Get start parameters 
		string ParamBuffer = "";
		if (1 < argc) {
			//cout << "> K0 Engine Parameters: " << endl;
			for (size_t i = 1; i < argc; i++)
			{
				// ... 
				ParamBuffer += string(argv[i]) + ' ';
				//if (string(argv[i])[0] == '-')
				//	cout << "  " << string(argv[i]) << ' ' << string(argv[i+1]) << endl;
			}
		}

		cout << "  > argc: " << argc << endl;
		system( string("\"Bin\\Kingso Engine.exe " + ParamBuffer+"\"").c_str());

	// End 
		cout << "# Kingso Exit" << endl;
		//system("pause");
		return 0;
}