#include "../Window.h"

const string CurrentDateTime()
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}

// Game: Save game 
void Window::SaveGame()
{
	cout << "Save game: unit " + to_string(SaveGameUnit) + "!" << endl;

	// ... 
	XMLParser* XMLParser1 = new XMLParser();
	// Create data 
	string Name = to_string(SaveGameUnit);
	string Path = "Data\\Saves\\"+Name;
	remove(("Data\\Saves\\"+Name+".xml").c_str());

	vector<string> Data;
	Data.push_back("<?xml version=\"1.0\" encoding=\"utf-8\"?>");
	Data.push_back("<Data>");
		Data.push_back("	<!-- Main -->");
		Data.push_back("	<Init Date=\""+CurrentDateTime()+"\"/>");
		Data.push_back("	<Init PlayerTeam=\""+to_string(Game1->Player1->Team)+"\"/>");
		Data.push_back("	<Init PlayerPosition=\""+to_string(size_t(Game1->Player1->X))+";"+to_string(size_t(Game1->Player1->Y))+"\"/>");
		Data.push_back("	<Init Progress=\""+to_string(Game1->Progress)+"\"/>");
		Data.push_back("	<Init Map=\""+CurrentMapName+"\"/>");

		Data.push_back("	<!-- Land map -->");
		Data.push_back("	<Land>");
		string Buffer = "";
		for (size_t i = 0; i < LandMap1->BlocksVector.size(); i++)
		{
			for (size_t j = 0; j < LandMap1->BlocksVector[i].size(); j++)
			{
				if (LandMap1->BlocksVector[i][j].Land)
					Buffer += "0 ";
				else
					Buffer += "- ";

				if (j+1 == LandMap1->BlocksVector[i].size())
					Buffer += ";";
			}
			Data.push_back("		"+Buffer);
			Buffer = "";
		}
		Data.push_back("	</Land>");
		Data.push_back("	<!-- Forest map -->");
		Data.push_back("	<Forest>");
		for (size_t i = 0; i < LandMap1->BlocksVector.size(); i++)
		{
			for (size_t j = 0; j < LandMap1->BlocksVector[i].size(); j++)
			{
				if (LandMap1->BlocksVector[i][j].Forest)
					Buffer += "| ";
				else
				{
					if (LandMap1->BlocksVector[i][j].Land)
						Buffer += "0 ";
					else
						Buffer += "- ";
				}

				if (j+1 == LandMap1->BlocksVector[i].size())
					Buffer += ";";
			}
			Data.push_back("		"+Buffer);
			Buffer = "";
		}
		Data.push_back("	</Forest>");
		Data.push_back("	<!-- Wood map -->");
		Data.push_back("	<Wood>");
		Buffer = "";
		for (size_t i = 0; i < LandMap1->BlocksVector.size(); i++)
		{
			for (size_t j = 0; j < LandMap1->BlocksVector[i].size(); j++)
			{
				Buffer += to_string(LandMap1->BlocksVector[i][j].Wood)+" ";
			}
			Data.push_back("		"+Buffer+";");
			Buffer = "";
		}
		Data.push_back("	</Wood>");
		Data.push_back("	<!-- Mountain map -->");
		Data.push_back("	<Mountain>");
		for (size_t i = 0; i < LandMap1->BlocksVector.size(); i++)
		{
			for (size_t j = 0; j < LandMap1->BlocksVector[i].size(); j++)
			{
				if (LandMap1->BlocksVector[i][j].Mountain)
					Buffer += "# ";
				else
				{
					if (LandMap1->BlocksVector[i][j].Land)
						Buffer += "0 ";
					else
						Buffer += "- ";
				}

				if (j+1 == LandMap1->BlocksVector[i].size())
					Buffer += ";";
			}
			Data.push_back("		"+Buffer);
			Buffer = "";
		}
		Data.push_back("	</Mountain>");
		Data.push_back("	<!-- Road map -->");
		Data.push_back("	<Road>");
		Data.push_back("		;"); // TO:DO !
		Data.push_back("	</Road>");
		Data.push_back("	<!-- Domain map -->");
		Data.push_back("	<Domain>");
		Buffer = "";
		for (size_t i = 0; i < DomainMap1->GetTeamMap().size(); i++)
		{
			for (size_t j = 0; j < DomainMap1->GetTeamMap()[i].size(); j++)
			{
				Buffer += to_string(DomainMap1->GetTeamMap()[i][j])+" ";
			}
			Data.push_back("		"+Buffer+";");
			Buffer = "";
		}
		Data.push_back("	</Domain>");
		Data.push_back("	<!-- WarFog map -->");
		Data.push_back("	<WarFog>");
		Buffer = "";
		for (size_t i = 0; i < LandMap1->BlocksVector.size(); i++)
		{
			for (size_t j = 0; j < LandMap1->BlocksVector[i].size(); j++)
			{
				Buffer += to_string(LandMap1->BlocksVector[i][j].WarFog)+" ";
			}
			Data.push_back("		"+Buffer+";");
			Buffer = "";
		}
		Data.push_back("	</WarFog>");
		Data.push_back("	<!-- AI map -->");
		Data.push_back("	<Game>");
		Settlement Settlement1; string Type = "";
		for (size_t i = 0; i < Game1->Castes.size(); i++)
		{
			Data.push_back("		<!-- "+to_string(i)+" -->");
			Data.push_back("		<Caste Team=\""+to_string(i)+"\">");

			// Inits 
			Data.push_back("			<Init Nation=\""+to_string(Game1->Castes[i]->NationToInt())+"\"/>");
			Data.push_back("			<Init Rune=\""+to_string(Game1->Castes[i]->Rune)+"\"/>");
			Data.push_back("			<Init Cash=\""+to_string(Game1->Castes[i]->Cash)+"\"/>");
			Data.push_back("			<Init PreviewCash=\""+to_string(Game1->Castes[i]->PreviewCash)+"\"/>");
			Data.push_back("			<Init Food=\""+to_string(Game1->Castes[i]->Food)+"\"/>");
			Data.push_back("			<Init PreviewFood=\""+to_string(Game1->Castes[i]->PreviewFood)+"\"/>");
			Data.push_back("			<Init Wood=\""+to_string(Game1->Castes[i]->Wood)+"\"/>");
			Data.push_back("			<Init PreviewWood=\""+to_string(Game1->Castes[i]->PreviewWood)+"\"/>");
			Data.push_back("			<Init Population=\""+to_string(Game1->Castes[i]->Population)+"\"/>");
			Data.push_back("			<Init PreviewPopulation=\""+to_string(Game1->Castes[i]->PreviewPopulation)+"\"/>");
			Data.push_back("			<Init Army=\""+to_string(Game1->Castes[i]->Army)+"\"/>");
			Data.push_back("			<Init PreviewArmy=\""+to_string(Game1->Castes[i]->PreviewArmy)+"\"/>");
			Data.push_back("			<Init TechnologyPoints=\""+to_string(Game1->Castes[i]->TechnologyPoints)+"\"/>");
			Data.push_back("			<Init PreviewTechnologyPoints=\""+to_string(Game1->Castes[i]->PreviewTechnologyPoints)+"\"/>");
			Data.push_back("			<Init DiploPoints=\""+to_string(Game1->Castes[i]->DiploPoints)+"\"/>");
			Data.push_back("			<Init PreviewDiploPoints=\""+to_string(Game1->Castes[i]->PreviewDiploPoints)+"\"/>");
			Data.push_back("			<Init MovePoints=\""+to_string(Game1->Castes[i]->MovePoints)+"\"/>");
			Data.push_back("			<Init PreviewMovePoints=\""+to_string(Game1->Castes[i]->PreviewMovePoints)+"\"/>");
			Data.push_back("			");

			Buffer = "";
			for (size_t j = 0; j < Game1->Castes[i]->Attitude.size(); j++)
				Buffer += to_string(j)+";"+to_string(Game1->Castes[i]->Attitude[j])+"|";
			Data.push_back("			<Init Attitude=\""+Buffer+"\"/>");
			Data.push_back("			");

			Buffer = "";
			for (size_t j = 0; j < Game1->Castes[i]->Status.size(); j++)
				Buffer += to_string(j)+";"+to_string(Game1->Castes[i]->Status[j])+"|";
			Data.push_back("			<Init Status=\""+Buffer+"\"/>");
			Data.push_back("			");
			// TO:DO ->> TO NEW VERSION
			/*
			Buffer = "";
			for (size_t j = 0; j < Game1->Castes[i]->Technologys.size(); j++)
				Buffer += to_string(Game1->Castes[i]->Technologys[j])+";";
			Data.push_back("			<Init Technologys=\""+Buffer+"\"/>");
			Data.push_back("			");
			*/
			Buffer = "";
			if (Game1->Castes[i]->Units.size() != 0)
			{
				Data.push_back("			<Init RememberAddX=\""+to_string(Game1->Castes[i]->Units[0]->RememberAddX)+"\"/>");
				Data.push_back("			<Init RememberAddY=\""+to_string(Game1->Castes[i]->Units[0]->RememberAddY)+"\"/>");

				Data.push_back("			<Init StartX=\""+to_string(size_t(Game1->Castes[i]->Units[0]->StartX))+"\"/>");
				Data.push_back("			<Init StartY=\""+to_string(size_t(Game1->Castes[i]->Units[0]->StartY))+"\"/>");
				Data.push_back("			<Init X=\""+to_string(size_t(Game1->Castes[i]->Units[0]->X))+"\"/>");
				Data.push_back("			<Init Y=\""+to_string(size_t(Game1->Castes[i]->Units[0]->Y))+"\"/>");
			}
			Data.push_back("			");

			// Settlements 
			for (size_t j = 0; j < Game1->Castes[i]->Settlements.size(); j++)
			{
				Settlement1 = Game1->Castes[i]->Settlements[j];
				if (Settlement1.GetTypeInt() == 1)
					Type = "Settlement";
				else
				if (Settlement1.GetTypeInt() == 2)
					Type = "Castle";
				else
				if (Settlement1.GetTypeInt() == 3)
					Type = "Field";
				else
				if (Settlement1.GetTypeInt() == 4)
					Type = "Pasture";
				else
				if (Settlement1.GetTypeInt() == 5)
					Type = "Fisheries";
				else
				if (Settlement1.GetTypeInt() == 6)
					Type = "Suburb";
				else
				if (Settlement1.GetTypeInt() == 7)
					Type = "Sawmill";
				Data.push_back("			<Settlement Name=\""+Settlement1.Name+"\" Type=\""+Type+"\" Army=\"" + to_string(Settlement1.Army) + "\" Team=\""+to_string(Settlement1.Team)+"\" X=\""+to_string(size_t(Settlement1.X/32))+"\" Y=\""+to_string(size_t(Settlement1.Y/32))+"\" />");
			}
			Data.push_back("			");
			Data.push_back("		</Caste>");
		}
		Data.push_back("	</Game>");
		Data.push_back("	");
	Data.push_back("</Data>");

	// Save 
	XMLParser1->SaveFile(Path, Data);
}