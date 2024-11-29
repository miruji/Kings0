#include "../Window.h"

// Game: create a new game 
void Window::CreateNewGame(bool LoadGame)
{
    // achievement [equally player colors]
    if (true)
    {
        bool open = true;
        if (NewGamePlayers.size() >= 2)
        for (size_t i = 1; i < NewGamePlayers.size(); i++)
        {
            if (NewGamePlayers[0].Color != NewGamePlayers[1].Color)
                open = false;
        }
        if (open)
            SteamAPI1->SetAchievement("OhMyEyes");
    }

    //
    if (true)
    {
        vector<int> NewGamePlayers2;
        for (size_t i = 0; i < NewGamePlayers.size(); i++)
            NewGamePlayers2.push_back(NewGamePlayers[i].Num);
        Game1 = new Game(NewGamePlayers2);
    }

    vector< vector<string> > Map;
    vector< Caste* > Castes;
    if (LoadGame == false)
    {
        cout << "> K0E.Map generating: " << endl;
        cout << "  ";
        // Open game map.xml
        XMLParser* XMLParser1 = new XMLParser();
        XMLParser1->LoadDocument("Data\\Maps\\Map\\"+CurrentMapName+".xml", Console1);
        Map = XMLParser1->LandMap();

        // other: create map
        Castes = Game1->GetGameCastes("Data\\Maps\\Map\\"+CurrentMapName+".xml", Console1);
        CreateMaps(Map, Castes);
    }

    //
    cout << "> K0E.Game generating: " << endl;
    cout << "  ";

    //cout << "Basic: " << NewGameTeam << ", Save: " << SaveNewGameTeam << endl;
    if (LoadGame == false)
        Game1->CreateGame("Data\\Maps\\Map\\"+CurrentMapName+".xml", "Player", NewGameTeam, NewGameNation, NewGameFlag, Console1);
    else
        Game1->CreateGame("Data\\Saves\\"+to_string(LoadGameUnit)+".xml", "Player", NewGameTeam, NewGameNation, NewGameFlag, Console1);
    Game1->Player1->UpdateRect(sf::IntRect(sf::Vector2i(0, Game1->Player1->Team*32), sf::Vector2i(32, 32)));

    // team colors
    if (LoadGame == false)
    {
        if (NewGamePlayers.size() >= 1)
        {
        vector<size_t> delete_castes;
        for (size_t i = 0; i < Game1->Castes.size(); i++)
        if (NewGamePlayers[i].Num == -1)
        {
            delete_castes.push_back(i);
        }
        for (size_t i = delete_castes.size(); i > 0; i--)
        {
            Game1->Castes.erase(Game1->Castes.begin()+delete_castes[i-1]);
            NewGamePlayers.erase(NewGamePlayers.begin()+delete_castes[i-1]);
        }
        for (size_t i = 0; i < Game1->Castes.size(); i++)
        //if (NewGamePlayers[i].Num != -1)
        {
            Game1->Castes[i]->Color = NewGamePlayers[i].Color;
            Game1->Castes[i]->Name = NewGamePlayers[i].Name;
            //
            Game1->Castes[i]->Settlements[0].X = Game1->XMLCastes[NewGamePlayers[i].StartPosition-1]->XMLSettlements[0]->X*32;
            Game1->Castes[i]->Settlements[0].Y = Game1->XMLCastes[NewGamePlayers[i].StartPosition-1]->XMLSettlements[0]->Y*32;
        }
    } }

	// Set Preview map 
	for (size_t i = 0; i < Map[0].size(); i++)
	for (size_t j = 0; j < Map[0][i].length(); j++)
	{
		Map[0][i][j] = '0';
	}
    /*
	for (size_t i = 0; i < Game1->Castes.size(); i++)
	{
        Game1->Castes[i]->PreviewMap1 = new PreviewMap();
        Game1->Castes[i]->PreviewMap1General = new PreviewMap();
		Game1->Castes[i]->PreviewMap1->StringsVector = Map[0];
        Game1->Castes[i]->PreviewMap1General->StringsVector = Map[0];
		Game1->Castes[i]->PreviewMap1->Generate(LandMap1->BlocksVector, CreateTeamMap(LandMap1->BlocksVector, Castes));
        Game1->Castes[i]->PreviewMap1General->Generate(LandMap1->BlocksVector, CreateTeamMap(LandMap1->BlocksVector, Castes));
    }
    */
        // Create preview & domain map
        if (true)
        {
        Settlement Settlement1;
        for (size_t i = 0; i < Game1->Castes.size(); i++)
        {
            for (size_t j = 0; j < Game1->Castes[i]->Settlements.size(); j++)
            {
                Settlement1 = Game1->Castes[i]->Settlements[j];
                //if (Settlement1.Team == Game1->Player1->Team)
                if (Settlement1.Team == Game1->Castes[i]->Team)
                {
                    SetNewPreview(i, 1, Settlement1.Y/32, Settlement1.X/32);
                    SetNewDomain(i+2, Settlement1.Y/32, Settlement1.X/32);
                }
            }
            //
        }
        //
        }
        // Create settlements units 
        for (size_t i = 0; i < Game1->Castes.size(); i++)
        {
            // To preview 
            Game1->Castes[i]->PreviewProgress(LandMap1);
            //
            if (i == Game1->Player1->Team)
            {
                for (size_t j = 0; j < Game1->Castes[i]->Settlements.size(); j++)
                {
                    Settlement& Settlement1 = Game1->Castes[i]->Settlements[j];

                    if (Settlement1.GetType() == SettlementTypes::Settlement)
                    {
                        Game1->Player1->StartX = Settlement1.X;
                        Game1->Player1->StartY = Settlement1.Y;
                    }
                }
                continue;
            }
            for (size_t j = 0; j < Game1->Castes[i]->Settlements.size(); j++)
            {
                Settlement& Settlement1 = Game1->Castes[i]->Settlements[j];
                vector< Unit* >& Units = Game1->Castes[i]->Units;

	            if (Settlement1.GetType() == SettlementTypes::Settlement)
	            {
                    Units.push_back( new Unit(Settlement1.Name, Game1->Characters) );
		            Units[Units.size()-1]->SetPosition(Settlement1.X+32, Settlement1.Y);

                    Units[Units.size()-1]->StartX = Units[Units.size()-1]->X-32; Units[Units.size()-1]->StartY = Units[Units.size()-1]->Y;

                    Units[Units.size()-1]->Team = Settlement1.Team;
	            }
            }
        }
    // Set AI1
    for (size_t i = 0; i < Game1->Castes.size(); i++)
    for (size_t j = 0; j < Game1->Castes[i]->Settlements.size(); j++)
    {
        LandMap1->BlocksVector[
            size_t(Game1->Castes[i]->Settlements[j].Y/32)
        ][
            size_t(Game1->Castes[i]->Settlements[j].X/32)
        ].Settlement = j+1;
    }
        // Set player spawn pos
        if (true)
        {
            //
            size_t PlayerX = 0;
            size_t PlayerY = 0;
            MapBlock MapBlockBuffer;

                for (size_t i = Game1->Player1->Team; i < Game1->Castes.size(); i++)
                { 
                for (size_t j = 0; j < Game1->Castes[i]->Settlements.size(); j++)
                {
                    Settlement& Settlement1 = Game1->Castes[i]->Settlements[j];

                    if (Settlement1.GetType() == SettlementTypes::Settlement)
                    {
                        PlayerX = Settlement1.X / 32;
                        PlayerY = Settlement1.Y / 32;
                        break;
                    }
                }
                    break;
                }

            // Update player position 
            Game1->Player1->SetPosition(PlayerX*32+32, PlayerY*32);
            
            // Open settlement 
            for (size_t i = 0; i < Game1->Castes.size(); i++)
            for (size_t j = 0; j < Game1->Castes[i]->Settlements.size(); j++)
            {
                if (PlayerX == Game1->Castes[i]->Settlements[j].X/32 && PlayerY == Game1->Castes[i]->Settlements[j].Y/32)
                    Game1->Castes[i]->Settlements[j].Opened = true;
            }
       
            // Update player WarFog 
            Game_PlayerWarFog();
        }
    // Create window camera 
    if (LoadGame == false)
        CreateNewWindowCamera();

    RegenerateNoEntryMap();

    // Create new map pointer 
    if (LoadGame == false)
        MapPointer1 = new MapPointer(Game1->Player1->X, Game1->Player1->Y);

    // To left block 
    FirstMainMenuBack = false;
    LeftBlockMinimize = false;
}