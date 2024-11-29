#pragma once
#define _CRT_SECURE_NO_WARNINGS
__pragma(warning(push, 0))

#pragma optimize( "g", on )
#pragma optimize( "t", on )

#include "../K0E.Window/Window.h"
using namespace std;
#include "../K0E.Console/Console.h"
#include "../K0E.Console/Error/Error.h"

// Main stream function of Kings0 Engine
int main(size_t argc, char* argv[])
{
	// Console 
	Console* Console1 = new Console();
	Console1->SetIndent(0);
	Console1->IPrintln("# Kingso Engine:");

	// Steam App Id - 1385180
	SteamAPI* SteamAPI1 = new SteamAPI();
	if (!SteamAPI1->Init(Console1))
		return 0;

	// Open k0dct achievement 
	SteamAPI1->SetAchievement("k0basic");

	// First initialization 
	XMLParser* XMLParser1 = new XMLParser();

	size_t Width = 0, Height = 0, FramerateLimit = 60, WindowMode = 0;
	bool VerticalSync =false;
	string LanguageType = "Eng", Version = "000000", Title = "K0Engine";
	int Soundtrack = 0 , SoundEffects = 0;

	Console1->IPrintln("!> Kingso Engine Settings load:");
	Console1->SetIndent(1);
		bool Basic = XMLParser1->LoadDocument("Data\\Settings\\Basic.xml", Console1);
		if (Basic == true)
		{
			XMLParser1->SearchSettings(true, Version, Title, Width, Height, FramerateLimit, WindowMode, VerticalSync, LanguageType, Soundtrack, SoundEffects);

			bool Custom = XMLParser1->LoadDocument("Data\\Settings\\Custom.xml", Console1);
			if (Custom == true)
			{
				XMLParser1->SearchSettings(false, Version, Title, Width, Height, FramerateLimit, WindowMode, VerticalSync, LanguageType, Soundtrack, SoundEffects);
			}
		}
		else
		{
			bool Custom = XMLParser1->LoadDocument("Data\\Settings\\Custom.xml", Console1);
			if (Custom == true)
			{
				XMLParser1->SearchSettings(false, Version, Title, Width, Height, FramerateLimit, WindowMode, VerticalSync, LanguageType, Soundtrack, SoundEffects);
			}
			else
				Error Error1(Console1, ErrorType::FatalError, {"Setting file not loaded"}, {"Exit K0E"}, true);
		}
	delete XMLParser1;

	// Get parameters 
	Console1->SetIndent(0);
	Console1->IPrintln("!> Kingso Param check:");
	Console1->SetIndent(1);

	vector< string > Parameters;
	for (size_t i = 1; i < argc; i++)
	{
		//
		Parameters.push_back( string(argv[i]) );
	}

	// Second initialization 
	for (size_t i = 0; i < Parameters.size(); i++)
	{
		//
		if (Parameters[i] == "-Width")
		{
			Width = atoi( Parameters[i+1].c_str() );
			Console1->IPrintln("> Width: " + to_string(Width));
		}
		else
		if (Parameters[i] == "-Height")
		{
			Height = atoi( Parameters[i+1].c_str() );
			Console1->IPrintln("> Height: " + to_string(Height));
		}
		else
		if (Parameters[i] == "-FramerateLimit")
		{
			FramerateLimit = atoi( Parameters[i+1].c_str() );
			Console1->IPrintln("> FramerateLimit: " + to_string(FramerateLimit));
		}
		else
		if (Parameters[i] == "-WindowMode")
		{
			if ( atoi(Parameters[i+1].c_str()) == 0 )
				WindowMode = false;
			else
			if ( atoi(Parameters[i+1].c_str()) == 1 )
				WindowMode = true;

			Console1->IPrintln("> WindowMode: " + to_string(WindowMode));
		}
		else
		if (Parameters[i] == "-VerticalSync")
		{
			if ( atoi(Parameters[i+1].c_str()) == 0 )
				VerticalSync = false;
			else
			if ( atoi(Parameters[i+1].c_str()) == 1 )
				VerticalSync = true;

			Console1->IPrintln("> VerticalSync: " + to_string(VerticalSync));
		}
		else
		if (Parameters[i] == "-Language")
		{
			LanguageType = Parameters[i+1];
			Console1->IPrintln("> Language: " + LanguageType);
		}
		else
		if (Parameters[i] == "-Soundtrack")
		{
			Soundtrack = atoi(Parameters[i+1].c_str());
			Console1->IPrintln("> Soundtrack: " + to_string(Soundtrack));
		}
		else
		if (Parameters[i] == "-SoundEffects")
		{
			SoundEffects = atoi(Parameters[i+1].c_str());
			Console1->IPrintln("> SoundEffects: " + to_string(SoundEffects));
		}
	}

	// Window 
	if (Width < 1280 || Height < 720)
		Error Error1(Console1, ErrorType::FatalError, { "Settings not loaded" }, { "Exit K0E" }, true);
	else
	{
		Console1->SetIndent(0);
		Console1->IPrintln("!> Kingso Engine SFML window start:");
		Console1->SetIndent(1);
		Console1->IPrintln("> Width: " + to_string(Width));
		Console1->IPrintln("> Height: " + to_string(Height));
		Console1->IPrintln("> FramerateLimit: " + to_string(FramerateLimit));
		Console1->IPrintln("> WindowMode: " + to_string(WindowMode));
		Console1->IPrintln("> VerticalSync: " + to_string(VerticalSync));
		Console1->IPrintln("> Language: " + LanguageType);
		Console1->IPrintln("> Soundtrack: " + to_string(Soundtrack));
		Console1->IPrintln("> Language: " + to_string(SoundEffects));

		// Create main stream window 
		//ShowWindow(GetConsoleWindow(), SW_HIDE);
		Window* Window1 = new Window(Version, LanguageType, Title, Width, Height, FramerateLimit, WindowMode, VerticalSync, Console1, SteamAPI1, Soundtrack, SoundEffects);
		SteamAPI1->Shutdown();
		//delete Window1;
	}

	// End 
	Console1->SetIndent(0);
	Console1->IPrintln("# Kingso Engine Exit");
	return 0;
}