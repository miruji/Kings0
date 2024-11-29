#include "../Window.h"

// Create new settlement 
void Window::CreateNewSettlement(sf::Keyboard::Key Key)
{
	bool Created = false;
	if (Key != sf::Keyboard::Num0 && Key != sf::Keyboard::Numpad0)
	if (Game1->Castes[Game1->Player1->Team]->Settlements.size()+1 > Game1->Castes[Game1->Player1->Team]->BuildingLimit)
	{
		NeedResources = ";T_BuildingsLimitExceeded";
		return;
	}

	Caste* CasteBuffer = Game1->Castes[Game1->Player1->Team];
	MapBlock MapBlock1 = LandMap1->BlocksVector[Game1->Player1->Y/32][Game1->Player1->X/32];
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	// plunder
	if (Key == sf::Keyboard::Num0 || Key == sf::Keyboard::Numpad0)
	{
		if (!LandMap1->BlocksVector[Game1->Player1->Y/32][Game1->Player1->X/32].Settlement)
		{
			NeedResources = ";T_NothingToDestroy";
			return;
		}
		//
		Settlement Settlement1;
		//
		bool Create = false;
		for (size_t i = 0; i < Game1->Castes.size(); i++)
		{
			if (Create == true)
				break;

			for (size_t j = 0; j < Game1->Castes[i]->Settlements.size(); j++)
			{
				Settlement1 = Game1->Castes[i]->Settlements[j];
				if (Settlement1.GetType() != SettlementTypes::Settlement)
				{
					if (Game1->Player1->X/32 == Settlement1.X/32 && Game1->Player1->Y/32 == Settlement1.Y/32)
					{
						Create = true;
						break;
					}
				}
				else
				{
					if (Game1->Player1->X/32 == Settlement1.X/32 && Game1->Player1->Y/32 == Settlement1.Y/32)
					{
						NeedResources = ";T_ImpossibleToDestroy";
						Create = false;
						break;
					}
				}
			}
			//
		}
		//
		if (Create == true)
			UIEvent('!', "SettlementPlunder", true, 1, false);
	}
	else
	// barn
	if (Key == sf::Keyboard::Num1 || Key == sf::Keyboard::Numpad1)
	{
		if (MapBlock1.Land || MapBlock1.River)
		{
		if (Game1->Castes[Game1->Player1->Team]->PreviewWood >= 10 && Game1->Castes[Game1->Player1->Team]->PreviewPopulation >= 5 && Game1->Castes[Game1->Player1->Team]->PreviewFood >= 10)
		{
			// Resources 
			CasteBuffer->PreviewWood -= 10;
			CasteBuffer->PreviewPopulation -= 5;
			CasteBuffer->PreviewFood -= 10;
			// Create new 
			Game1->Castes[Game1->Player1->Team]->Settlements.push_back( Settlement("", "Barn", 1, Game1->Player1->Team, Game1->Player1->X, Game1->Player1->Y) );
			//
			if (true)
			{
				size_t BarnBuilds = 0;
				for (size_t i = 0; i < Game1->Castes[Game1->Player1->Team]->Settlements.size(); i++)
				{
					if (Game1->Castes[Game1->Player1->Team]->Settlements[i].GetType() == SettlementTypes::Barn)
					{
						BarnBuilds++;

					}
				}
				Game1->Castes[Game1->Player1->Team]->ResourcesLimit = BarnBuilds*1000+3000;
			}
			Created = true;
		}
		else
			NeedResources = "10W;5P;10F";
		}
		else
			NeedResources = ";T_CanBeBuiltOnLandOrRiver";
	}
	else
	// sawmill
	if (Key == sf::Keyboard::Num2 || Key == sf::Keyboard::Numpad2)
	{
		if ((MapBlock1.Land || MapBlock1.River) && MapBlock1.Forest)
		{
		if (Game1->Castes[Game1->Player1->Team]->PreviewWood >= 10 && Game1->Castes[Game1->Player1->Team]->PreviewPopulation >= 5 && Game1->Castes[Game1->Player1->Team]->PreviewFood >= 10)
		{
			// Resources 
			CasteBuffer->PreviewWood -= 10;
			CasteBuffer->PreviewPopulation -= 5;
			CasteBuffer->PreviewFood -= 10;
			// Create new 
			Game1->Castes[Game1->Player1->Team]->Settlements.push_back( Settlement("", "Sawmill", 1, Game1->Player1->Team, Game1->Player1->X, Game1->Player1->Y) );
				// Forest = Forest * 6 
				LandMap1->BlocksVector[size_t(Game1->Player1->Y/32)][size_t(Game1->Player1->X/32)].Wood = LandMap1->BlocksVector[size_t(Game1->Player1->Y/32)][size_t(Game1->Player1->X/32)].Wood*6;
			Created = true;
		}
		else
			NeedResources = "10W;5P;10F";
		}
		else
			NeedResources = ";T_CanBeBuiltOnLandOrRiver2";
	}
	else
	// saburb
	if (Key == sf::Keyboard::Num3 || Key == sf::Keyboard::Numpad3)
	{
		if (MapBlock1.Land || MapBlock1.River)
		{
		if (Game1->Castes[Game1->Player1->Team]->PreviewWood >= 10 && Game1->Castes[Game1->Player1->Team]->PreviewPopulation >= 5 && Game1->Castes[Game1->Player1->Team]->PreviewFood >= 10)
		{
			// Resources 
			CasteBuffer->PreviewWood -= 10;
			CasteBuffer->PreviewPopulation -= 5;
			CasteBuffer->PreviewFood -= 10;
			// Create new 
			Game1->Castes[Game1->Player1->Team]->Settlements.push_back( Settlement("", "Suburb", 1, Game1->Player1->Team, Game1->Player1->X, Game1->Player1->Y) );
			Created = true;
		}
		else
			NeedResources = "10W;5P;10F";
		}
		else
			NeedResources = ";T_CanBeBuiltOnLandOrRiver";
	}
	else
	// field
	if (Key == sf::Keyboard::Num4 || Key == sf::Keyboard::Numpad4)
	{
		if (MapBlock1.Land || MapBlock1.River)
		{
		if (Game1->Castes[Game1->Player1->Team]->PreviewWood >= 10 && Game1->Castes[Game1->Player1->Team]->PreviewPopulation >= 5 && Game1->Castes[Game1->Player1->Team]->PreviewFood >= 10)
		{
			// Resources 
			CasteBuffer->PreviewWood -= 10;
			CasteBuffer->PreviewPopulation -= 5;
			CasteBuffer->PreviewFood -= 10;
			// Create new 
			Game1->Castes[Game1->Player1->Team]->Settlements.push_back( Settlement("", "Field", 1, Game1->Player1->Team, Game1->Player1->X, Game1->Player1->Y) );
			Created = true;
		}
		else
			NeedResources = "10W;5P;10F";
		}
		else
			NeedResources = ";T_CanBeBuiltOnLandOrRiver";
	}
	else
	// pasture
	if (Key == sf::Keyboard::Num5 || Key == sf::Keyboard::Numpad5)
	{
		if (MapBlock1.Land || MapBlock1.River)
		{
		if (Game1->Castes[Game1->Player1->Team]->PreviewWood >= 10 && Game1->Castes[Game1->Player1->Team]->PreviewPopulation >= 5 && Game1->Castes[Game1->Player1->Team]->PreviewFood >= 10)
		{
			// Resources 
			CasteBuffer->PreviewWood -= 10;
			CasteBuffer->PreviewPopulation -= 5;
			CasteBuffer->PreviewFood -= 10;
			// Create new 
			Game1->Castes[Game1->Player1->Team]->Settlements.push_back( Settlement("", "Pasture", 1, Game1->Player1->Team, Game1->Player1->X, Game1->Player1->Y) );
			Created = true;
		}
		else
			NeedResources = "10W;5P;10F";
		}
		else
			NeedResources = ";T_CanBeBuiltOnLandOrRiver";
	}
	else
	// fisheries
	if (Key == sf::Keyboard::Num6 || Key == sf::Keyboard::Numpad6)
	{
		if (!MapBlock1.Land && !MapBlock1.River)
		{
		if (Game1->Castes[Game1->Player1->Team]->PreviewWood >= 10 && Game1->Castes[Game1->Player1->Team]->PreviewPopulation >= 5 && Game1->Castes[Game1->Player1->Team]->PreviewFood >= 10)
		{
			// Resources 
			CasteBuffer->PreviewWood -= 10;
			CasteBuffer->PreviewPopulation -= 5;
			CasteBuffer->PreviewFood -= 10;
			// Create new 
			Game1->Castes[Game1->Player1->Team]->Settlements.push_back( Settlement("", "Fisheries", 1, Game1->Player1->Team, Game1->Player1->X, Game1->Player1->Y) );
			Created = true;
		}
		else
			NeedResources = "10W;5P;10F";
		}
		else
			NeedResources = ";T_CanOnlyBeBuiltOnWater";
	}
	else
	// wall
	if (Key == sf::Keyboard::Num7 || Key == sf::Keyboard::Numpad7)
	{
		if (MapBlock1.Land || MapBlock1.River)
		{
		if (Game1->Castes[Game1->Player1->Team]->PreviewWood >= 20 && Game1->Castes[Game1->Player1->Team]->PreviewFood >= 20)
		{
			// Resources 
			CasteBuffer->PreviewWood -= 20;
			CasteBuffer->PreviewFood -= 20;

			// Create new 
			Game1->Castes[Game1->Player1->Team]->Settlements.push_back( Settlement("", "Wall", 1, Game1->Player1->Team, Game1->Player1->X, Game1->Player1->Y) );
			Created = true;
		}
		else
			NeedResources = "20W;20F";
		}
		else
			NeedResources = ";T_CanBeBuiltOnLandOrRiver";
	}
	else
	// tower
	if (Key == sf::Keyboard::Num8 || Key == sf::Keyboard::Numpad8)
	{
		if (MapBlock1.Land || MapBlock1.River)
		{
		if (Game1->Castes[Game1->Player1->Team]->PreviewWood >= 20 && Game1->Castes[Game1->Player1->Team]->PreviewPopulation >= 15 && Game1->Castes[Game1->Player1->Team]->PreviewFood >= 20)
		{
			// Resources 
			CasteBuffer->PreviewWood -= 20;
			CasteBuffer->PreviewPopulation -= 15;
			CasteBuffer->PreviewFood -= 20;

			// Create new 
			Game1->Castes[Game1->Player1->Team]->Settlements.push_back( Settlement("", "Tower", 1, Game1->Player1->Team, Game1->Player1->X, Game1->Player1->Y) );
			Created = true;
		}
		else
			NeedResources = "20W;15P;20F";
		}
		else
			NeedResources = ";T_CanBeBuiltOnLandOrRiver";
	}
	else
	// castle
	if (Key == sf::Keyboard::Num9 || Key == sf::Keyboard::Numpad9)
	{
		if (MapBlock1.Land || MapBlock1.River)
		{
		if (Game1->Castes[Game1->Player1->Team]->PreviewWood >= 20 && Game1->Castes[Game1->Player1->Team]->PreviewPopulation >= 25 && Game1->Castes[Game1->Player1->Team]->PreviewFood >= 20)
		{
			// Resources 
			CasteBuffer->PreviewWood -= 20;
			CasteBuffer->PreviewPopulation -= 25;
			CasteBuffer->PreviewFood -= 20;

			// Create new 
			Game1->Castes[Game1->Player1->Team]->Settlements.push_back( Settlement("", "Castle", 1, Game1->Player1->Team, Game1->Player1->X, Game1->Player1->Y) );
			Created = true;
		}
		else
			NeedResources = "20W;25P;20F";
		}
		else
			NeedResources = ";T_CanBeBuiltOnLandOrRiver";
	}
	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
	// Update blocks 
	if (Created == true)
	{
		Game1->Castes[Game1->Player1->Team]->PreviewMovePoints--;

		if (Key != sf::Keyboard::Num0 && Key != sf::Keyboard::Numpad0)
		SetNewPreview( Game1->Player1->Team, 1, size_t(Game1->Player1->Y/32), size_t(Game1->Player1->X/32) );

		LandMap1->BlocksVector[size_t(Game1->Player1->Y/32)][size_t(Game1->Player1->X/32)].Settlement = Game1->Castes[Game1->Player1->Team]->Settlements.size()+2;
		RegenerateNoEntryMap();

		Game_InSettlement( LandMap1->BlocksVector[size_t(Game1->Player1->Y/32)][size_t(Game1->Player1->X/32)], false );
		// 
		if (Game1->Castes[Game1->Player1->Team]->ResourcesLimit > Game1->Castes[Game1->Player1->Team]->BuildingLimit*1000+2000)
			Game1->Castes[Game1->Player1->Team]->ResourcesLimit = Game1->Castes[Game1->Player1->Team]->BuildingLimit*1000+2000;
		// Left block
		UI_LeftBlockUpdate("");
		// Update spec text 
		UI1->SpecTextUpdate = true;

		// play sound
		size_t Random = GetRandomNumber(0, 2);
		if (Random == 0)
			Audio1->PlaySound1("Build0");
		else
		if (Random == 1)
			Audio1->PlaySound1("Build1");
		else
		if (Random == 2)
			Audio1->PlaySound1("Build2");
	}
}