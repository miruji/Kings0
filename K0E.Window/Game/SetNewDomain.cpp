#include "../Window.h"

void Window::SetNewDomain(size_t Team, size_t i, size_t j)
{
	// center
	DomainMap1->GetTeamMap()[i][j] = Team;
	// 1 block
	DomainMap1->GetTeamMap()[i-1][j-1] = Team;
	DomainMap1->GetTeamMap()[i-1][j] = Team;
	DomainMap1->GetTeamMap()[i-1][j+1] = Team;
	DomainMap1->GetTeamMap()[i][j-1] = Team;
	DomainMap1->GetTeamMap()[i+1][j-1] = Team;
	DomainMap1->GetTeamMap()[i+1][j] = Team;
	DomainMap1->GetTeamMap()[i+1][j+1] = Team;
	DomainMap1->GetTeamMap()[i][j+1] = Team;
	//
	DomainMap1->UpdateBorderMap();
}