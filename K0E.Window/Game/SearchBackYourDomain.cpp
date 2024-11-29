#include "../Window.h"

bool Window::SearchBackYourDomain(MapBlock NextBlock, size_t BasicTeam)
{
	//
	BasicTeam = BasicTeam + 2;

	if (DomainMap1->GetTeamMap()[NextBlock.Y/32-1][NextBlock.X/32-1] == BasicTeam ||
		DomainMap1->GetTeamMap()[NextBlock.Y/32-1][NextBlock.X/32] == BasicTeam ||
		DomainMap1->GetTeamMap()[NextBlock.Y/32-1][NextBlock.X/32+1] == BasicTeam ||
		DomainMap1->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32-1] == BasicTeam || 
		DomainMap1->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32+1] == BasicTeam ||
		DomainMap1->GetTeamMap()[NextBlock.Y/32+1][NextBlock.X/32-1] == BasicTeam ||
		DomainMap1->GetTeamMap()[NextBlock.Y/32+1][NextBlock.X/32] == BasicTeam ||
		DomainMap1->GetTeamMap()[NextBlock.Y/32+1][NextBlock.X/32+1] == BasicTeam)
		return true;
	else
		return false;
}