#include "Macro.h"

// K0E Steam API
class K0E_SteamAP_Api SteamAPI
{
public:
	// Constructor 
	SteamAPI();

	// Init 
	bool Init(Console* Console1);

	// Set achievement
	void SetAchievement(string Name);
	// Clear achievement
	void ClearAchievement(string Name);

	// Get user name (link)
	string GetUserName1();

	// Shutdown 
	void Shutdown();
};