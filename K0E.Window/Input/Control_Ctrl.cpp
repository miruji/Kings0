#include "../Window.h"

// Control: [Domain] 
bool Window::Control_Ctrl(bool Keyboard)
{
	//
	bool Result = true;

	// Message 
	if (UI1->Message != 0)
	{
		NeedResources = ";T_Message";
		return true;
	}

	if ((Event.key.code == sf::Keyboard::LControl || Event.key.code == sf::Keyboard::RControl) || Keyboard == false)
	{
		// Duplomacy 
		vector< vector< size_t > >& TeamMap = DomainMap1->GetTeamMap();
		size_t TeamBlock = TeamMap[Game1->Player1->Y/32][Game1->Player1->X/32];
		if (TeamBlock != Game1->Player1->Team+2)
		{
		if (Game1->Castes[Game1->Player1->Team]->PreviewDiploPoints-5 >= 0)
		{
		if (DomainMap1->SearchTeamDomain(Game1->Player1->X, Game1->Player1->Y, Game1->Player1->Team))
		{
			//
			if (TeamBlock != 0)
			{
				//
				if (Game1->Castes[TeamBlock-2]->Status[Game1->Player1->Team] == 0)
					NeedResources = ";T_EnemyTerritoryCaptured";
				else
				if (Game1->Castes[TeamBlock-2]->Status[Game1->Player1->Team] == 1)
					NeedResources = ";T_NeutralTerritoryCaptured";
				else
				if (Game1->Castes[TeamBlock-2]->Status[Game1->Player1->Team] == 2)
					NeedResources = ";T_AllyTerritoryCaptured";
				//
				if (Game1->Castes[TeamBlock-2]->Attitude[Game1->Player1->Team]-5 >= 0 && Game1->Castes[TeamBlock-2]->Attitude[Game1->Player1->Team]-5 <= 50)
					Game1->Castes[TeamBlock-2]->Attitude[Game1->Player1->Team] -= 5;
				if (Game1->Castes[Game1->Player1->Team]->Attitude[TeamBlock-2]-5 >= 0 && Game1->Castes[Game1->Player1->Team]->Attitude[TeamBlock-2]-5 <= 50)
					Game1->Castes[Game1->Player1->Team]->Attitude[TeamBlock-2] -= 5;
				UpdateAttitudeStatus();
			}
			else
				NeedResources = ";T_TerritoryOccupied";

			// Add to map 
			TeamMap[Game1->Player1->Y/32][Game1->Player1->X/32] = Game1->Player1->Team+2;
			// Diplomacy 
			Game1->Castes[Game1->Player1->Team]->PreviewDiploPoints -= 5;
			// Update border 
			DomainMap1->UpdateBorderMap();

			// settlement
			for (size_t i = 0; i < Game1->Castes.size(); i++)
			for (size_t j = 0; j < Game1->Castes[i]->Settlements.size(); j++)
			{
				if (Game1->Castes[i]->Settlements[j].X == Game1->Player1->X && Game1->Castes[i]->Settlements[j].Y == Game1->Player1->Y)
				{
					Game1->Castes[Game1->Player1->Team]->Settlements.push_back(Game1->Castes[i]->Settlements[j]);
					Game1->Castes[i]->Settlements.erase(Game1->Castes[i]->Settlements.begin() + j);
					i = Game1->Castes.size();
					break;
				}
			}
		}
		else
			NeedResources = ";T_TooFarFromTheDomain";
		}
		else
			NeedResources = "5D";
		}
		else
			NeedResources = ";T_ThisTerritoryIsAlreadyOurs";
		//
	}
	else
		Result = false;

	// Update spec text 
	UI1->SpecTextUpdate = true;

	return Result;
}