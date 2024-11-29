#include "../Window.h"

// Control: [Building numbers] 
bool Window::Control_Numbers(size_t BuildingNum)
{
	//
	bool Result = false;

	// Message 
	if (UI1->Message != 0)
	{
		NeedResources = ";T_Message";
		return true;
	}

	if (  (LandMap1->BlocksVector[Game1->Player1->Y/32][Game1->Player1->X/32].Settlement && Event.key.code != sf::Keyboard::Num0 && Event.key.code != sf::Keyboard::Numpad0 && BuildingNum != 0)
		 && !Game1->Player1->Die )
	{
		NeedResources = ";T_ThereIsNoPlace";
	}
	else
	if (  (!LandMap1->BlocksVector[Game1->Player1->Y/32][Game1->Player1->X/32].Settlement || (Event.key.code == sf::Keyboard::Num0 || Event.key.code == sf::Keyboard::Numpad0 || BuildingNum == 0))
		 && !Game1->Player1->Die )
	if ( (Event.key.code == sf::Keyboard::Num0 || Event.key.code == sf::Keyboard::Numpad0 || BuildingNum == 0) ||
		 (Event.key.code == sf::Keyboard::Num1 || Event.key.code == sf::Keyboard::Numpad1) || 
		 (Event.key.code == sf::Keyboard::Num2 || Event.key.code == sf::Keyboard::Numpad2) || 
		 (Event.key.code == sf::Keyboard::Num3 || Event.key.code == sf::Keyboard::Numpad3) || 
		 (Event.key.code == sf::Keyboard::Num4 || Event.key.code == sf::Keyboard::Numpad4) || 
		 (Event.key.code == sf::Keyboard::Num5 || Event.key.code == sf::Keyboard::Numpad5) || 
		 (Event.key.code == sf::Keyboard::Num6 || Event.key.code == sf::Keyboard::Numpad6) || 
		 (Event.key.code == sf::Keyboard::Num7 || Event.key.code == sf::Keyboard::Numpad7) || 
		 (Event.key.code == sf::Keyboard::Num8 || Event.key.code == sf::Keyboard::Numpad8) || 
		 (Event.key.code == sf::Keyboard::Num9 || Event.key.code == sf::Keyboard::Numpad9) || BuildingNum)
	{
		if (Game1->Castes[Game1->Player1->Team]->PreviewMovePoints <= 1)
		{
			NeedResources = "1M";
			return true;
		}
		if (Event.key.code == sf::Keyboard::Num0 || Event.key.code == sf::Keyboard::Numpad0 || BuildingNum == 0)
		{
			//cout << "!>>>>>> PLUNDER!" << endl;
			CreateNewSettlement(sf::Keyboard::Num0);
			return true;
		}
		/*
		else
		if (Event.key.code != sf::Keyboard::Num0 && Event.key.code != sf::Keyboard::Numpad0 && BuildingNum != 0)
		{
			if (LandMap1->BlocksVector[Game1->Player1->Y/32][Game1->Player1->X/32].Forest == true || SaveNewGameNation == 2)
				return Result;
		}
		*/
		Result = true;
		//
		//if (Game1->Player1->Food >= 1 &&  Game1->Player1->Cash >= 5 && Game1->Player1->Wood >= 5)
		//{
			bool NoBuild = false;
			//cout << "Player: " << Game1->Player1->X << " : " << Game1->Player1->Y << endl;
			//cout << "Size: " << Game1->Castes.size() << endl;
			for (size_t i = 0; i < Game1->Castes.size(); i++)
			{ 
				//cout << i << endl;
				if (NoBuild == true)
				{
					break;
				}
				else
				for (size_t j = 0; j < Game1->Castes[i]->Settlements.size(); j++)
				{
					//cout << Game1->Castes[i]->Settlements[j].GetX() << " : " << Game1->Castes[i]->Settlements[j].GetY() << endl;
					if (Game1->Castes[i]->Settlements[j].X == Game1->Player1->X && Game1->Castes[i]->Settlements[j].Y == Game1->Player1->Y)
					{
						//cout << "NoBuid!" << endl;
						if (Event.key.code != sf::Keyboard::Num0 && Event.key.code != sf::Keyboard::Numpad0 && BuildingNum != 0)
							NeedResources = ";T_ThereIsNoPlace";
						NoBuild = true;
						break;
					}
				}
			}
			// Domain map 
			if (DomainMap1->GetTeamMap()[Game1->Player1->Y/32][Game1->Player1->X/32] != Game1->Player1->Team+2)
			{
				NeedResources = ";T_NotOurLand";
				NoBuild = true;
			}

			if ( NoBuild == false || 
				 ((Event.key.code == sf::Keyboard::Num0 || Event.key.code == sf::Keyboard::Numpad0 || BuildingNum == 0) && NoBuild == true)
			   ) {
				//cout << NumToKeyCode(BuildingNum) << endl;
				if (BuildingNum == 10)
					CreateNewSettlement(Event.key.code);
				else
					CreateNewSettlement( NumToKeyCode(BuildingNum) );
			}
		//}
	}

	return Result;
}