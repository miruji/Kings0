#include "../Window.h"

vector< size_t > DevideToTwo(string Two)
{
	vector< size_t > Result;
	string Buffer = "";
	for (size_t i = 0; i < Two.size(); i++)
	{
		if (Two[i] == ';' || i+1 == Two.size())
		{
			if (i+1 == Two.size())
				Buffer += Two[i];

			Result.push_back(atoi(Buffer.c_str()));
			Buffer = "";
		}
		else
			Buffer += Two[i];
	}
	return Result;
}

vector< size_t > ParseAttitude(string AttitudeStr)
{
	// "0;25|1;25|2;25|3;25|4;100|5;25|"
	vector< size_t > Result;
	string Buffer = "";
	for (size_t i = 0; i < AttitudeStr.size(); i++)
	{
		if (AttitudeStr[i] == '|' || i+1 == AttitudeStr.size())
		{
			if (i+1 == AttitudeStr.size())
				Buffer += AttitudeStr[i];

			Result.push_back(DevideToTwo(Buffer)[1]);
			Buffer = "";
		}
		else
			Buffer += AttitudeStr[i];
	}
	return Result;
}

vector< int > ParseStatus(string StatusStr)
{
	// "0;1|1;1|2;1|3;1|4;3|5;1|"
	vector< int > Result;
	string Buffer = "";
	for (size_t i = 0; i < StatusStr.size(); i++)
	{
		if (StatusStr[i] == '|' || i+1 == StatusStr.size())
		{
			if (i+1 == StatusStr.size())
				Buffer += StatusStr[i];

			Result.push_back(DevideToTwo(Buffer)[1]);
			Buffer = "";
		}
		else
			Buffer += StatusStr[i];
	}

	return Result;
}

void Window::LoadGame()
{
	cout << "Load game: unit "+to_string(LoadGameUnit)+"!" << endl;
	XMLParser* XMLParser1 = new XMLParser();
	XMLParser1->LoadDocument("Data\\Saves\\"+to_string(LoadGameUnit)+".xml", Console1);
	
	size_t Progress = 0;
	TiXmlElement* ElData = XMLParser1->GetDataElement();
		// Team & Progress
		TiXmlElement* ElElement = ElData->FirstChildElement("Init");
		while (ElElement != NULL)
		{
			if (ElElement->Attribute("PlayerTeam"))
			{
				NewGameTeam = atoi(ElElement->Attribute("PlayerTeam"));
				SaveNewGameTeam = NewGameTeam;
			}
			if (ElElement->Attribute("Progress"))
			{
				Progress = atoi(ElElement->Attribute("Progress"));
				cout << "Progress:: " << Progress << endl;
			}

			ElElement = ElElement->NextSiblingElement("Init");
		}
	cout << 222 << endl;
		// Maps
		vector< string > Land;
		vector< string > Forest;
		vector< string > Wood;
		vector< string > Mountain;
		vector< string > Road;
		vector< string > Domain;
		vector< string > WarFogMap;

		string Buffer = "";
		ElElement = ElData->FirstChildElement("Land");
		for (size_t i = 0; i < string(ElElement->GetText()).length(); i++)
		{
			if (ThisInt(ElElement->GetText()[i]) || ThisSymbol(ElElement->GetText()[i]) || ElElement->GetText()[i] == ' ')
				Buffer += ElElement->GetText()[i];

			if (ElElement->GetText()[i] == ';')
			{
				Land.push_back(Buffer);
				Buffer = "";
				i++;
			}
		}

		Buffer = "";
		ElElement = ElData->FirstChildElement("Forest");
		for (size_t i = 0; i < string(ElElement->GetText()).length(); i++)
		{
			if (ThisInt(ElElement->GetText()[i]) || ThisSymbol(ElElement->GetText()[i]) || ElElement->GetText()[i] == ' ')
				Buffer += ElElement->GetText()[i];

			if (ElElement->GetText()[i] == ';')
			{
				Forest.push_back(Buffer);
				Buffer = "";
				i++;
			}
		}

		Buffer = "";
		ElElement = ElData->FirstChildElement("Wood");
		for (size_t i = 0; i < string(ElElement->GetText()).length(); i++)
		{
			if (ThisInt(ElElement->GetText()[i]) || ThisSymbol(ElElement->GetText()[i]) || ElElement->GetText()[i] == ' ')
				Buffer += ElElement->GetText()[i];

			if (ElElement->GetText()[i] == ';')
			{
				Wood.push_back(Buffer);
				Buffer = "";
				i++;
			}
		}

		Buffer = "";
		ElElement = ElData->FirstChildElement("Mountain");
		for (size_t i = 0; i < string(ElElement->GetText()).length(); i++)
		{
			if (ThisInt(ElElement->GetText()[i]) || ThisSymbol(ElElement->GetText()[i]) || ElElement->GetText()[i] == ' ')
				Buffer += ElElement->GetText()[i];

			if (ElElement->GetText()[i] == ';')
			{
				Mountain.push_back(Buffer);
				Buffer = "";
				i++;
			}
		}

		Buffer = "";
		ElElement = ElData->FirstChildElement("Road");
		for (size_t i = 0; i < string(ElElement->GetText()).length(); i++)
		{
			if (ThisInt(ElElement->GetText()[i]) || ThisSymbol(ElElement->GetText()[i]) || ElElement->GetText()[i] == ' ')
				Buffer += ElElement->GetText()[i];

			if (ElElement->GetText()[i] == ';')
			{
				Road.push_back(Buffer);
				Buffer = "";
				i++;
			}
		}

		Buffer = "";
		ElElement = ElData->FirstChildElement("Domain");
		for (size_t i = 0; i < string(ElElement->GetText()).length(); i++)
		{
			if (ThisInt(ElElement->GetText()[i]) || ThisSymbol(ElElement->GetText()[i]) || ElElement->GetText()[i] == ' ')
				Buffer += ElElement->GetText()[i];

			if (ElElement->GetText()[i] == ';')
			{
				Domain.push_back(Buffer);
				Buffer = "";
				i++;
			}
		}

		Buffer = "";
		ElElement = ElData->FirstChildElement("WarFog");
		for (size_t i = 0; i < string(ElElement->GetText()).length(); i++)
		{
			if (ThisInt(ElElement->GetText()[i]) || ThisSymbol(ElElement->GetText()[i]) || ElElement->GetText()[i] == ' ')
				Buffer += ElElement->GetText()[i];

			if (ElElement->GetText()[i] == ';')
			{
				WarFogMap.push_back(Buffer);
				Buffer = "";
				i++;
			}
		}
		vector< Caste* > Castes;
		cout << 111 << endl;
		// Land map
		LandMap1 = new LandMap();
		LandMap1->StringsVector = Land;
		LandMap1->Generate(); // World map Width & Height
		// Forest map
		ForestMap* ForestMap1 = new ForestMap();
		ForestMap1->StringsVector = Forest;
		ForestMap1->Generate(LandMap1->BlocksVector);
		if (true)
		{
			Buffer = "";
			vector< vector<int> > Wood2;
			vector<int> Line;
			for (size_t i = 0; i < Wood.size(); i++)
			{
			for (size_t j = 0; j < Wood[i].length(); j++)
			{
				if (Wood[i][j] == ';')
					break;
				if (Wood[i][j] == ' ')
				{
					Line.push_back(atoi(Buffer.c_str()));
					Buffer = "";
				}
				else
					Buffer += Wood[i][j];
			}
			Wood2.push_back(Line);
			Line.clear();
			}
			for (size_t i = 0; i < Wood2.size(); i++)
			for (size_t j = 0; j < Wood2[i].size(); j++)
			{
				LandMap1->BlocksVector[i][j].Wood = Wood2[i][j];
			}
		}
		// Mountain map
		MountainMap* MountainMap1 = new MountainMap();
		MountainMap1->StringsVector = Mountain;
		MountainMap1->Generate(LandMap1->BlocksVector);
		// Update land map
		for (size_t i = 0; i < LandMap1->BlocksVector.size(); i++)
		for (size_t j = 0; j < LandMap1->BlocksVector[i].size(); j++)
			LandMap1->BlocksVector[i][j].Update();

		// Set Grid map 
		GridMap1 = new GridMap(LandMap1->BlocksVector);

		// Set Domain map 
		DomainMap1 = new DomainMap();
		DomainMap1->StringsVector = Domain;
		DomainMap1->Generate(LandMap1->BlocksVector, CreateTeamMap(LandMap1->BlocksVector, Castes));
		// Set War fog 
		if (true)
		{
			Buffer = "";
			vector< vector<bool> > WarFogMap2;
			vector<bool> Line;
			for (size_t i = 0; i < WarFogMap.size(); i++)
			{
			for (size_t j = 0; j < WarFogMap[i].length(); j++)
			{
				if (WarFogMap[i][j] == ';')
					break;
				if (WarFogMap[i][j] == ' ')
				{
					Line.push_back(atoi(Buffer.c_str()));
					Buffer = "";
				}
				else
					Buffer += WarFogMap[i][j];
			}
			WarFogMap2.push_back(Line);
			Line.clear();
			}
			for (size_t i = 0; i < WarFogMap2.size(); i++)
			for (size_t j = 0; j < WarFogMap2[i].size(); j++)
			{
				LandMap1->BlocksVector[i][j].WarFog = WarFogMap2[i][j];
			}
		}
		WarFog1 = new WarFog(LandMap1->BlocksVector);

		// Set Road map
		RoadMap1 = new RoadMap();
		RoadMap1->StringsVector = Road;
		RoadMap1->Generate(LandMap1->BlocksVector);

		// Set No entry map 
		NoEntryMap1 = new NoEntryMap();
		NoEntryMap1->Generate(LandMap1->BlocksVector);

		// Flag
		TiXmlElement* ElElement2 = ElData->FirstChildElement("Game");
		TiXmlElement* ElElement3 = ElElement2->FirstChildElement("Caste");

		while (ElElement3 != NULL)
		{
			if (atoi(ElElement3->Attribute("Team")) == NewGameTeam)
				break;

			ElElement3 = ElElement3->NextSiblingElement("Caste");
		}
		
		ElElement = ElElement3->FirstChildElement("Init");
		while (ElElement != NULL)
		{
			if (ElElement->Attribute("Nation"))
				SaveNewGameNation = atoi(ElElement->Attribute("Nation"));

			if (ElElement->Attribute("Rune"))
				SaveNewGameFlag = atoi(ElElement->Attribute("Rune"));

			ElElement = ElElement->NextSiblingElement("Init");
		}
		cout << 666 << endl;

		// For game AI
		CreateNewGame(true);
		NewGameTeam = 0;
		NewGameFlag = 0;
		NewGameNation = 0;
		
		// Map name
		ElElement = ElData->FirstChildElement("Init");
		while (ElElement != NULL)
		{
			if (ElElement->Attribute("Map"))
			{
				CurrentMapName = ElElement->Attribute("Map");
				break;
			}

			ElElement = ElElement->NextSiblingElement("Init");
		}

		// Set player X & Y
		ElElement = ElData->FirstChildElement("Init");
		if (true)
		{
		string PlayerPosition = "";
		while (ElElement != NULL)
		{
			if (ElElement->Attribute("PlayerPosition"))
			{
				PlayerPosition = ElElement->Attribute("PlayerPosition");
				break;
			}

			ElElement = ElElement->NextSiblingElement("Init");
		}
		//cout << PlayerPosition << ": " << to_string(DevideToTwo(PlayerPosition)[0]) << " - " << to_string(DevideToTwo(PlayerPosition)[1]) << endl;
		Game1->Player1->SetPosition(DevideToTwo(PlayerPosition)[0], DevideToTwo(PlayerPosition)[1]);
		Game1->Progress = Progress;
		
		CreateNewWindowCamera();
		MapPointer1 = new MapPointer(Game1->Player1->X, Game1->Player1->Y);
		}
		// Set new AI (from save)
		string AttitudeStr = "", StatusStr = "", TechnologysStr = "";

		ElElement2 = ElData->FirstChildElement("Game");
		ElElement3 = ElElement2->FirstChildElement("Caste");

		size_t p = 0;
		while (ElElement3 != NULL)
		{
		ElElement = ElElement3->FirstChildElement("Init");
		while (ElElement != NULL)
		{
			if (ElElement->Attribute("Nation"))
			{
				size_t Nation = atoi(ElElement->Attribute("Nation"));
				if (Nation == 0)
					Game1->Castes[p]->Nation = CasteNation::Steppe;
				else
				if (Nation == 1)
					Game1->Castes[p]->Nation = CasteNation::Water;
				else
				if (Nation == 2)
					Game1->Castes[p]->Nation = CasteNation::Sedentary;
				else
				if (Nation == 3)
					Game1->Castes[p]->Nation = CasteNation::Mountain;
			}
			else
			if (ElElement->Attribute("Rune"))
				Game1->Castes[p]->Rune = atoi(ElElement->Attribute("Rune"));
			else
			if (ElElement->Attribute("Cash"))
				Game1->Castes[p]->Cash = atoi(ElElement->Attribute("Cash"));
			else
			if (ElElement->Attribute("PreviewCash"))
				Game1->Castes[p]->PreviewCash = atoi(ElElement->Attribute("PreviewCash"));
			else
			if (ElElement->Attribute("Food"))
				Game1->Castes[p]->Food = atoi(ElElement->Attribute("Food"));
			else
			if (ElElement->Attribute("PreviewFood"))
				Game1->Castes[p]->PreviewFood = atoi(ElElement->Attribute("PreviewFood"));
			else
			if (ElElement->Attribute("Wood"))
				Game1->Castes[p]->Wood = atoi(ElElement->Attribute("Wood"));
			else
			if (ElElement->Attribute("PreviewWood"))
				Game1->Castes[p]->PreviewWood = atoi(ElElement->Attribute("PreviewWood"));
			else
			if (ElElement->Attribute("Population"))
				Game1->Castes[p]->Population = atoi(ElElement->Attribute("Population"));
			else
			if (ElElement->Attribute("PreviewPopulation"))
				Game1->Castes[p]->PreviewPopulation = atoi(ElElement->Attribute("PreviewPopulation"));
			else
			if (ElElement->Attribute("Army"))
				Game1->Castes[p]->Army = atoi(ElElement->Attribute("Army"));
			else
			if (ElElement->Attribute("PreviewArmy"))
				Game1->Castes[p]->PreviewArmy = atoi(ElElement->Attribute("PreviewArmy"));
			else
			if (ElElement->Attribute("TechnologyPoints"))
				Game1->Castes[p]->TechnologyPoints = atoi(ElElement->Attribute("TechnologyPoints"));
			else
			if (ElElement->Attribute("PreviewTechnologyPoints"))
				Game1->Castes[p]->PreviewTechnologyPoints = atoi(ElElement->Attribute("PreviewTechnologyPoints"));
			else
			if (ElElement->Attribute("DiploPoints"))
				Game1->Castes[p]->DiploPoints = atoi(ElElement->Attribute("DiploPoints"));
			else
			if (ElElement->Attribute("PreviewDiploPoints"))
				Game1->Castes[p]->PreviewDiploPoints = atoi(ElElement->Attribute("PreviewDiploPoints"));
			else
			if (ElElement->Attribute("MovePoints"))
				Game1->Castes[p]->MovePoints = atoi(ElElement->Attribute("MovePoints"));
			else
			if (ElElement->Attribute("PreviewMovePoints"))
				Game1->Castes[p]->PreviewMovePoints = atoi(ElElement->Attribute("PreviewMovePoints"));
			else
			if (ElElement->Attribute("Attitude"))
			{
				AttitudeStr = ElElement->Attribute("Attitude");
				Game1->Castes[p]->Attitude = ParseAttitude(AttitudeStr);
			}
			else
			if (ElElement->Attribute("Status"))
			{
				StatusStr = ElElement->Attribute("Status");
				Game1->Castes[p]->Status = ParseStatus(StatusStr);
			}
			else
			if (ElElement->Attribute("Technologys"))
			{
				// TO:DO ->> To new version
				/*
				TechnologysStr = ElElement->Attribute("Technologys");
				vector<size_t> Technologys = DevideToTwo(TechnologysStr);
				Game1->Castes[p]->Technologys.clear();
				for (size_t uu = 0; uu < Technologys.size(); uu++)
					Game1->Castes[p]->Technologys.push_back(Technologys[uu]);
				*/
			}
			
			if (Game1->Castes[p]->Units.size() != 0)
			{
			if (ElElement->Attribute("RememberAddX"))
				Game1->Castes[p]->Units[0]->RememberAddX = atoi(ElElement->Attribute("RememberAddX"));
			else
			if (ElElement->Attribute("RememberAddY"))
				Game1->Castes[p]->Units[0]->RememberAddY = atoi(ElElement->Attribute("RememberAddY"));
			else
			if (ElElement->Attribute("StartX"))
				Game1->Castes[p]->Units[0]->StartX = atoi(ElElement->Attribute("StartX"));
			else
			if (ElElement->Attribute("StartY"))
				Game1->Castes[p]->Units[0]->StartY = atoi(ElElement->Attribute("StartY"));
			else
			if (ElElement->Attribute("X"))
				Game1->Castes[p]->Units[0]->X = atoi(ElElement->Attribute("X"));
			else
			if (ElElement->Attribute("Y"))
				Game1->Castes[p]->Units[0]->Y = atoi(ElElement->Attribute("Y"));
			}
			ElElement = ElElement->NextSiblingElement("Init");
		}

		p++;
		ElElement3 = ElElement3->NextSiblingElement("Caste");
		}
}