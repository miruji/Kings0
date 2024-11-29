#include "../Window.h"

// Control X and Y: W A X D
bool Window::Control_WAXD(char Direction, bool Attack)
{
	//
	bool Result = true;

	if (Event.key.code == sf::Keyboard::W || Event.key.code == sf::Keyboard::A ||
		Event.key.code == sf::Keyboard::X || Event.key.code == sf::Keyboard::D || Direction != ' ')
	{
		// Message 
		if (UI1->Message != 0)
		{
			NeedResources = ";T_ActiveMessage";
			return true;
		}

		// Die 
		if (Game1->Player1->Die)
		{
			NeedResources = ";T_GameUnitDestroyed";
			return true;
		}

		// Map points 
		if (Game1->Castes[Game1->Player1->Team]->PreviewMovePoints == 0)
		{
			NeedResources = "1M";
			return true;
		}

		// !!! Free camera for null 
		if (Camera1->AddXY == true)
		{
			Camera1->AddXY = false;
			Camera1->X -= Camera1->AddX;
			Camera1->Y -= Camera1->AddY;
			Camera1->AddX = 0; Camera1->AddY = 0;
		}
		// !!! WAXD controll 
		// MapBlocks 
		MapBlock Block = LandMap1->BlocksVector[size_t(Game1->Player1->Y/32)][size_t(Game1->Player1->X/32)];
		MapBlock NextBlock;

		bool Progress = false;
		float PlayerXAdd = 0.0f, PlayerYAdd = 0.0f,
			  CameraXAdd = 0.0f, CameraYAdd = 0.0f;

		vector<Technology>& Technologys = Game1->Castes[Game1->Player1->Team]->Technologys;
		// Control
		// W
		if ( (Event.key.code == sf::Keyboard::W && Direction == ' ') || Direction == 'W' )
		{
			// Map ends 
			NextBlock = LandMap1->BlocksVector[size_t(Game1->Player1->Y/32)-1][size_t(Game1->Player1->X/32)];
			if (DomainMap1->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32] == 1)
				SteamAPI1->SetAchievement("Boundaries");
			//
			//if (Game1->Castes[Game1->Player1->Team]->PreviewMap1->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32] ||
			//	Game1->Castes[Game1->Player1->Team]->PreviewMap1General->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32])
			//{
			if (SearchBackYourDomain(NextBlock, Game1->Player1->Team))
			{
			if (SearchNextBlockDomain(NextBlock, Game1->Player1->Team))
			{
			if (SearchNextBlockEnemy(NextBlock, Game1->Player1->Team) || Attack)
			{
				//
				if ((Technologys[1].Opened || NextBlock.Mountain == false) && ((Technologys[3].Opened && NextBlock.River == true) || (Technologys[2].Opened && Technologys[3].Opened) || (NextBlock.River == false && NextBlock.Land == true)) && (Technologys[0].Opened || NextBlock.Forest == false))
				{
					// Move
					PlayerYAdd -= 32;
					CameraYAdd -= Camera1->Speed;

					Progress = true;

					// Update player sprite 
					if ((NextBlock.Land == false && NextBlock.Mountain == true && Block.Land == false) ||
						(NextBlock.Land == false && NextBlock.Mountain == false))
						Game1->Player1->UpdateRect(sf::IntRect(sf::Vector2i(96, Game1->Player1->Team * 32), sf::Vector2i(32, 32)));
				
					LandMap1->BlocksVector[size_t(Game1->Player1->Y/32)][size_t(Game1->Player1->X/32)].Enemy = 0;
					LandMap1->BlocksVector[size_t(Game1->Player1->Y/32)-1][size_t(Game1->Player1->X/32)].Enemy = Game1->Player1->Team;
				}
				else
					NeedResources = ";T_ThereNoWay";
			}
			else
				NeedResources = ";T_ThereNoWay";
			}
			else
				NeedResources = ";T_EnemyDomain";
			}
			else
				NeedResources = ";T_TooFarFromTheBoundaries";
		}
		else
		// A
		if ((Event.key.code == sf::Keyboard::A && Direction == ' ') || Direction == 'A')
		{
			// Map ends 
			NextBlock = LandMap1->BlocksVector[size_t(Game1->Player1->Y/32)][size_t(Game1->Player1->X/32)-1];
			if (DomainMap1->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32] == 1)
				SteamAPI1->SetAchievement("Boundaries");
			//
			//if (Game1->Castes[Game1->Player1->Team]->PreviewMap1->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32] ||
			//	Game1->Castes[Game1->Player1->Team]->PreviewMap1General->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32])
			//{
			if (SearchBackYourDomain(NextBlock, Game1->Player1->Team))
			{
			if (SearchNextBlockDomain(NextBlock, Game1->Player1->Team))
			{
			if (SearchNextBlockEnemy(NextBlock, Game1->Player1->Team) || Attack)
			{
				//
				if ((Technologys[1].Opened || NextBlock.Mountain == false) && ((Technologys[3].Opened && NextBlock.River == true) || (Technologys[2].Opened && Technologys[3].Opened) || (NextBlock.River == false && NextBlock.Land == true)) && (Technologys[0].Opened || NextBlock.Forest == false))
				{
					// Move
					PlayerXAdd -= 32;
					CameraXAdd -= Camera1->Speed;

					Progress = true;

					// Update player sprite 
					if ((NextBlock.Land == false && NextBlock.Mountain == true && Block.Land == false) ||
						(NextBlock.Land == false && NextBlock.Mountain == false))
						Game1->Player1->UpdateRect(sf::IntRect(sf::Vector2i(128, Game1->Player1->Team * 32), sf::Vector2i(32, 32)));
				
					LandMap1->BlocksVector[size_t(Game1->Player1->Y/32)][size_t(Game1->Player1->X/32)].Enemy = 0;
					LandMap1->BlocksVector[size_t(Game1->Player1->Y/32)][size_t(Game1->Player1->X/32)-1].Enemy = Game1->Player1->Team;
				}
				else
					NeedResources = ";T_ThereNoWay";
			}
			else
				NeedResources = ";T_ThereNoWay";
			}
			else
				NeedResources = ";T_EnemyDomain";
			}
			else
				NeedResources = ";T_TooFarFromTheBoundaries";
		}
		// X
		else
		if ( (Event.key.code == sf::Keyboard::X && Direction == ' ') || Direction == 'X' )
		{
			// Map ends 
			NextBlock = LandMap1->BlocksVector[size_t(Game1->Player1->Y/32)+1][size_t(Game1->Player1->X/32)];
			if (DomainMap1->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32] == 1)
				SteamAPI1->SetAchievement("Boundaries");
			//
			//if (Game1->Castes[Game1->Player1->Team]->PreviewMap1->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32] ||
			//	Game1->Castes[Game1->Player1->Team]->PreviewMap1General->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32])
			//{
			if (SearchBackYourDomain(NextBlock, Game1->Player1->Team))
			{
			if (SearchNextBlockDomain(NextBlock, Game1->Player1->Team))
			{
			if (SearchNextBlockEnemy(NextBlock, Game1->Player1->Team) || Attack)
			{
				//
				if ((Technologys[1].Opened || NextBlock.Mountain == false) && ((Technologys[3].Opened && NextBlock.River == true) || (Technologys[2].Opened && Technologys[3].Opened) || (NextBlock.River == false && NextBlock.Land == true)) && (Technologys[0].Opened || NextBlock.Forest == false))
				{
					// Move
					PlayerYAdd += 32;
					CameraYAdd += Camera1->Speed;

					Progress = true;

					// Update player sprite 
					if ((NextBlock.Land == false && NextBlock.Mountain == true && Block.Land == false) ||
						(NextBlock.Land == false && NextBlock.Mountain == false))
						Game1->Player1->UpdateRect(sf::IntRect(sf::Vector2i(160, Game1->Player1->Team * 32), sf::Vector2i(32, 32)));
				
					LandMap1->BlocksVector[size_t(Game1->Player1->Y/32)][size_t(Game1->Player1->X/32)].Enemy = 0;
					LandMap1->BlocksVector[size_t(Game1->Player1->Y/32)+1][size_t(Game1->Player1->X/32)].Enemy = Game1->Player1->Team;
				}
				else
					NeedResources = ";T_ThereNoWay";
			}
			else
				NeedResources = ";T_ThereNoWay";
			}
			else
				NeedResources = ";T_EnemyDomain";
			}
			else
				NeedResources = ";T_TooFarFromTheBoundaries";
		}
		// D
		else
		if ( (Event.key.code == sf::Keyboard::D && Direction == ' ') || Direction == 'D' )
		{
			// Map ends 
			NextBlock = LandMap1->BlocksVector[size_t(Game1->Player1->Y/32)][size_t(Game1->Player1->X/32)+1];
			if (DomainMap1->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32] == 1)
				SteamAPI1->SetAchievement("Boundaries");
			//
			//if (Game1->Castes[Game1->Player1->Team]->PreviewMap1->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32] ||
			//	Game1->Castes[Game1->Player1->Team]->PreviewMap1General->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32])
			//{
			if (SearchBackYourDomain(NextBlock, Game1->Player1->Team))
			{
			if (SearchNextBlockEnemy(NextBlock, Game1->Player1->Team) || Attack)
			{
			if (SearchNextBlockDomain(NextBlock, Game1->Player1->Team))
			{
				//
				if ((Technologys[1].Opened || NextBlock.Mountain == false) && ((Technologys[3].Opened && NextBlock.River == true) || (Technologys[2].Opened && Technologys[3].Opened) || (NextBlock.River == false && NextBlock.Land == true)) && (Technologys[0].Opened || NextBlock.Forest == false))
				{
					// Move
					PlayerXAdd += 32;
					CameraXAdd += Camera1->Speed;
					
					Progress = true;

					// Update player sprite 
					if ((NextBlock.Land == false && NextBlock.Mountain == true && Block.Land == false) ||
						(NextBlock.Land == false && NextBlock.Mountain == false))
						Game1->Player1->UpdateRect(sf::IntRect(sf::Vector2i(192, Game1->Player1->Team * 32), sf::Vector2i(32, 32)));
				
					LandMap1->BlocksVector[size_t(Game1->Player1->Y/32)][size_t(Game1->Player1->X/32)].Enemy = 0;
					LandMap1->BlocksVector[size_t(Game1->Player1->Y/32)][size_t(Game1->Player1->X/32)+1].Enemy = Game1->Player1->Team;
				}
				else
					NeedResources = ";T_ThereNoWay";
			}
			else
				NeedResources = ";T_ThereNoWay";
			}
			else
				NeedResources = ";T_EnemyDomain";
			}
			else
				NeedResources = ";T_TooFarFromTheBoundaries";
		}

		// No entry map 
		string NoEntryBuffer = NoEntryMap1->MapVector[size_t(NextBlock.X/32)][size_t(NextBlock.Y/32)];
		if ( SearchChar(NoEntryBuffer, to_string(Game1->Player1->Team+1)[0]) || 
			 NoEntryMap1->MapVector[size_t(NextBlock.X/32)][size_t(NextBlock.Y/32)] == "0" || 
			 Attack )
		{
			// If land == true and ship draw == false 
			if ((NextBlock.Land || NextBlock.River) && !NextBlock.Mountain && !NextBlock.Forest)
				Game1->Player1->UpdateRect(sf::IntRect(sf::Vector2i(0, Game1->Player1->Team * 32), sf::Vector2i(32, 32)));

			// Next progress 
			if (Progress == true)
			{
				// Move points 
				Game1->Castes[Game1->Player1->Team]->PreviewMovePoints--;

				// Move 
				if (PlayerXAdd || PlayerYAdd)
				{
					Game1->Player1->Move(PlayerXAdd, PlayerYAdd);
					Game1->Player1->Staying = 0;
				}
				if (CameraXAdd || CameraYAdd)
					Camera1->Move(CameraXAdd, CameraYAdd);

				// If land == true and ship draw == false (update to basic sprite) 
				if ((NextBlock.Land || NextBlock.River) && !NextBlock.Mountain && !NextBlock.Forest)
					Game1->Player1->UpdateRect(sf::IntRect(sf::Vector2i(0, Game1->Player1->Team*32), sf::Vector2i(32, 32)));

				// War fog open/show 
				Game_PlayerWarFog();
				// In (to) settlement
				Game_InSettlement(NextBlock, Attack);
			}
			// Player update
			Game1->Player1->SetPosition(Game1->Player1->X, Game1->Player1->Y);
			Camera1->GetView().setCenter(Game1->Player1->X+16, Game1->Player1->Y+16);
			// Map pointer update
			MapPointer1->SetXY(Game1->Player1->X, Game1->Player1->Y);
			UI_UpdateMapPointer(Attack);
		}

		// Get new event 
		/*
		bool Yes = RandomEvent();
		//cout << Yes << endl;
		if ( Yes )
		{
			//Game1->Events[ GetRandomNumber(0, Game1->Events.size()-1) ]->Do();
			//cout << "Do!" << endl;
		}
		*/
	}
	else
		Result = false;

	return Result;
}