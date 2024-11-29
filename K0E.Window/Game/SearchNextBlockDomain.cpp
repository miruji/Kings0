#include "../Window.h"

// Game: Search next block domain 
bool Window::SearchNextBlockDomain(MapBlock NextBlock, size_t BasicTeam)
{
	//
	size_t Team = DomainMap1->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32];
	//
	if (Team == Game1->Player1->Team+2 || Team == 0)
		return true;

	if (Game1->Castes[Game1->Player1->Team]->Status[Team-2] == 0 ||
		Game1->Castes[Game1->Player1->Team]->Status[Team-2] == 2)
		return true;
	else
		return false;
}