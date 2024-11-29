#include "../Window.h"

void Window::UpdateDomainPreview(int New, size_t Team, size_t ToTeam)
{
	/*
	cout << "!!!! UpdateDomainPreview " << endl;
	if (Game1->Castes[Team]->Status[ToTeam] == 3)
		return;

	if (Team != ToTeam)
	for (size_t i = 0; i < Game1->Castes[ToTeam]->PreviewMap1General->GetTeamMap().size(); i++)
	{
		for (size_t j = 0; j < Game1->Castes[ToTeam]->PreviewMap1General->GetTeamMap()[i].size(); j++)
		{
			//
			if (Game1->Castes[ToTeam]->PreviewMap1General->GetTeamMap()[i][j])
			{
				if (Game1->Castes[Team]->Status[ToTeam] == 0 || Game1->Castes[Team]->Status[ToTeam] == 2)
					Game1->Castes[Team]->PreviewMap1General->GetTeamMap()[i][j] += New;
				else
				{
					Game1->Castes[Team]->PreviewMap1General->GetTeamMap()[i][j] = 0;
				}
			}
		}
		//
	}

	if (Team != ToTeam)
	for (size_t i = 0; i < Game1->Castes[ToTeam]->PreviewMap1General->GetTeamMap().size(); i++)
	{
		for (size_t j = 0; j < Game1->Castes[ToTeam]->PreviewMap1General->GetTeamMap()[i].size(); j++)
		{
			//
			if (Game1->Castes[ToTeam]->PreviewMap1General->GetTeamMap()[i][j])
			{
				if (Game1->Castes[Team]->Status[ToTeam] == 0 || Game1->Castes[Team]->Status[ToTeam] == 1)
					Game1->Castes[Team]->PreviewMap1General->GetTeamMap()[i][j] = 0;
				else
				{
					if (New == 1)
						Game1->Castes[Team]->PreviewMap1General->GetTeamMap()[i][j] = 1;
					else
					if (New == -1)
						Game1->Castes[Team]->PreviewMap1General->GetTeamMap()[i][j] = -1;
				}
			}
		}
	}
	//
	for (size_t i = 0; i < DomainMap1->GetTeamMap().size(); i++)
	{
	for (size_t j = 0; j < DomainMap1->GetTeamMap()[i].size(); j++)
	{
		if (Game1->Castes[Team]->PreviewMap1General->GetTeamMap()[i][j] >= 0 && DomainMap1->GetTeamMap()[i][j] != 0)
		{
			//
			if (DomainMap1->GetTeamMap()[i][j] != Team +2)
			{
				if (int(DomainMap1->GetTeamMap()[i][j])-2 >= 0)
				{
					if (Game1->Castes[Team]->Status[DomainMap1->GetTeamMap()[i][j]-2] == 0 || 
						Game1->Castes[Team]->Status[DomainMap1->GetTeamMap()[i][j]-2] == 2)
					{
						if (New == 1)
							Game1->Castes[Team]->PreviewMap1General->GetTeamMap()[i][j] = 1;
						else
						if (New == -1)
							Game1->Castes[Team]->PreviewMap1General->GetTeamMap()[i][j] = -1;
					}
					else
						Game1->Castes[Team]->PreviewMap1General->GetTeamMap()[i][j] = 0;
				}
				else
					Game1->Castes[Team]->PreviewMap1General->GetTeamMap()[i][j] = 0;
			}
		}
		//
	}
	//
	}
	*/
	// output
	/*
	for (size_t i = 0; i < Game1->Castes[ToTeam]->PreviewMap1->GetTeamMap().size(); i++)
	{
		for (size_t j = 0; j < Game1->Castes[ToTeam]->PreviewMap1->GetTeamMap()[i].size(); j++)
		{
			cout << Game1->Castes[Team]->PreviewMap1->GetTeamMap()[i][j] << ' ';
		}
		cout << endl;
	}
	*/
}