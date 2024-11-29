#include "../Window.h"

void Window::UI_GenerateNewGamePlayers()
{
	NewGamePlayers.clear();
	// Name
	for (size_t i = 0; i < CurrentMapTeams; i++)
	{
		// Create
		NewGamePlayers.push_back(NewGameCaste(i));
		if (i == 0)
			NewGamePlayers[NewGamePlayers.size()-1].Name = SteamAPI1->GetUserName1();
		else
			NewGamePlayers[NewGamePlayers.size()-1].Name = "Computer "+to_string(i+1);
	}
	// Color
	UI_GenerateNewGamePlayersColor();

	// Start position
	for (size_t i = 0; i < CurrentMapTeams; i++)
	{
		NewGamePlayers[i].StartPosition = i+1;
	}
}