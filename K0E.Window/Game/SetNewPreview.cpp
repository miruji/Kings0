#include "../Window.h"

void Window::SetNewPreview(size_t Team, int New, size_t i, size_t j)
{
	/*
	size_t MapW = Game1->Castes[Team]->PreviewMap1->GetTeamMap().size()-1;

	// center
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i][j]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i][j]+=New;
	// 1 block
	if (i-1 >= 0 && j-1 >= 0)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i-1][j-1]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i-1][j-1]+=New;

	if (i-1 >= 0)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i-1][j]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i-1][j]+=New;

	if (i-1 >= 0 && j+1 <= MapW)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i-1][j+1]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i-1][j+1]+=New;

	if (j-1 >= 0)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i][j-1]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i][j-1]+=New;

	if (i+1 <= MapW && j-1 >= 0)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i+1][j-1]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i+1][j-1]+=New;

	if (i+1 <= MapW)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i+1][j]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i+1][j]+=New;

	if (i+1 <= MapW && j+1 <= MapW)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i+1][j+1]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i+1][j+1]+=New;

	if (j+1 <= MapW)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i][j+1]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i][j+1]+=New;
	// 2 block (+1)
	MapW = MapW-1;

	if (i-2 >= 1 && j-2 >= 1)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i-2][j-2]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i-2][j-2]+=New;

	if (i-2 >= 1 && j-1 >= 1)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i-2][j-1]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i-2][j-1]+=New;

	if (i-2 >= 1)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i-2][j]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i-2][j]+=New;

	if (i-2 >= 1 && j+1 <= MapW)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i-2][j+1]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i-2][j+1]+=New;

	if (i-2 >= 1 && j+2 <= MapW)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i-2][j+2]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i-2][j+2]+=New;


	if (i-1 >= 1 && j-2 >= 1)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i-1][j-2]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i-1][j-2]+=New;

	if (j-2 >= 1)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i][j-2]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i][j-2]+=New;

	if (i+1 <= MapW && j-2 >= 1)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i+1][j-2]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i+1][j-2]+=New;

	if (i+2 <= MapW && j-2 >= 1)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i+2][j-2]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i+2][j-2]+=New;


	if (i+2 <= MapW && j-1 >= 1)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i+2][j-1]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i+2][j-1]+=New;

	if (i+2 <= MapW)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i+2][j]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i+2][j]+=New;

	if (i+2 <= MapW && j+1 <= MapW)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i+2][j+1]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i+2][j+1]+=New;

	if (i+2 <= MapW && j+2 <= MapW)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i+2][j+2]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i+2][j+2]+=New;


	if (i-1 >= 1 && j+2 <= MapW)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i-1][j+2]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i-1][j+2]+=New;

	if (j+2 <= MapW)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i][j+2]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i][j+2]+=New;

	if (i+1 <= MapW && j+2 <= MapW)
	if (Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i+1][j+2]+New >= 0)
		Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i+1][j+2]+=New;

	//
	Game1->Castes[Team]->PreviewMap1->UpdateBorderMap();
	*/
	//
//	Game1->Castes[Team]->PreviewMap1->UpdateBorderMap();
	/*
	for (size_t i = 0; i < PreviewMap1->GetTeamMap().size(); i++)
	{
		for (size_t j = 0; j < PreviewMap1->GetTeamMap()[i].size(); j++)
		{
			cout << PreviewMap1->GetTeamMap()[i][j] << " ";
		}
		cout << endl;
	}
	*/
}