#include "SteamAPI.h"
#include <windows.h>

// Constructor 
SteamAPI::SteamAPI()
{
}

// Init 
bool SteamAPI::Init(Console* Console1)
{
	// Init steam API 
	if (!SteamAPI_Init())
	{
		HWND hWnd = GetForegroundWindow();
		MessageBox(hWnd, L"Steam must be running to play this game", L"Shutdown K0E", MB_ICONERROR);

		Error* Error1 = new Error(Console1, ErrorType::SteamLoadError, 
			{ "Steam must be running to play this game (SteamAPI_Init() failed)." },
			{ "Shutdown K0E." },
			true);
	}
	else
	{
		return 1;
	}
	//
}

// Set achievement
void SteamAPI::SetAchievement(string Name)
{
	// If login == true
	if (SteamUserStats()->RequestCurrentStats())
	{
		bool test1 = false;
		SteamUserStats()->GetAchievement(Name.c_str(), &test1);

		if (!test1)
		{
			SteamUserStats()->SetAchievement(Name.c_str());
			SteamUserStats()->StoreStats(); // Save in steam
		}
		else
			return;
	}
}

// Clear achievement
void SteamAPI::ClearAchievement(string Name)
{
	// If login == true 
	if (SteamUserStats()->RequestCurrentStats())
	{
		bool test1 = false;
		SteamUserStats()->GetAchievement(Name.c_str(), &test1);

		if (!test1)
		{
			SteamUserStats()->ClearAchievement(Name.c_str());
			SteamUserStats()->StoreStats(); // Save in steam
		}
		else
			return;
	}
}

// Get user name (link)
string SteamAPI::GetUserName1()
{
	string Name = SteamFriends()->GetPersonaName();
	return Name;
}

// Shutdown 
void SteamAPI::Shutdown()
{
	printf("! SteamAPI is shutdown ... \r\n");
	SteamAPI_Shutdown();
}