#include "../Window.h"

string Window::NeedResourcesStr()
{
	vector<string> Resources;
	string Buffer;
	for (size_t i = 0; i < NeedResources.length(); i++)
	{
		if (NeedResources[i] == ';' || i+1 == NeedResources.length())
		{
			if (i+1 == NeedResources.length())
				Buffer += NeedResources[i];
			Resources.push_back(Buffer);
			Buffer = "";
		}
		else
			Buffer += NeedResources[i];
	}
	char Char = ' ';
	string Buffer2 = "";
	for (size_t i = 0; i < Resources.size(); i++)
	{
		Buffer = Resources[i];
		Char = Resources[i][Resources[i].length()-1];
		Buffer.erase(Buffer.end()-1);
		
		if (ThisInt(Buffer[0]))
		{
			Buffer2 += Buffer;
			if (Char == 'G')
				Buffer2 += " "+LanguagePack1->GetLanguageText("T_Gold");
			else
			if (Char == 'F')
				Buffer2 += " "+LanguagePack1->GetLanguageText("T_Food");
			else
			if (Char == 'A')
				Buffer2 += " "+LanguagePack1->GetLanguageText("T_Army");
			else
			if (Char == 'D')
				Buffer2 += " "+LanguagePack1->GetLanguageText("T_Diplomacy");
			else
			if (Char == 'W')
				Buffer2 += " "+LanguagePack1->GetLanguageText("T_Wood");
			else
			if (Char == 'M')
				Buffer2 += " "+LanguagePack1->GetLanguageText("T_Movement");
			else
			if (Char == 'T')
				Buffer2 += " "+LanguagePack1->GetLanguageText("T_Technology");
			else
			if (Char == 'P')
				Buffer2 += " "+LanguagePack1->GetLanguageText("T_Population");
			else
				Buffer2 += " ?";
		}
		else
		{
			if (Buffer[0] == 'L')
				Buffer2 += " " + LanguagePack1->GetLanguageText("T_Land");
			else
			if (Buffer[0] == 'F')
				Buffer2 += " " + LanguagePack1->GetLanguageText("T_Forest");
			else
			if (Buffer[0] == 'R')
				Buffer2 += " " + LanguagePack1->GetLanguageText("T_River");
			else
				Buffer2 += " ?";

			if (Char == 'F')
				Buffer2 += " " + LanguagePack1->GetLanguageText("T_NeedNo");
			else
			if (Char == 'T')
				Buffer2 += " " + LanguagePack1->GetLanguageText("T_NeedYes");
			else
				Buffer2 += " ?";
		}
		Buffer2 += "; ";
	}
	return Buffer2;
}

// UI spec (for text) 
void Window::UISpec(UIText* Text1, size_t i)
{
	//
	if (Text1->GetSpec() == "Version")
	{
		Text1->SetText("Ver. "+Version);
	}
	else
	if (Text1->GetSpec() == "FPS")
	{
        if (FPS >= 70)
			Text1->SetColor("rgba(17, 220, 36, 255)");
        else
        if (FPS >= 60)
			Text1->SetColor("rgba(103, 220, 17, 255)");
        else
        if (FPS >= 50)
			Text1->SetColor("rgba(179, 220, 20, 255)");
        else
        if (FPS >= 40)
			Text1->SetColor("rgba(208, 220, 20, 255)");
        else
        if (FPS >= 30)
			Text1->SetColor("rgba(220, 179, 17, 255)");
        else
        if (FPS >= 20)
			Text1->SetColor("rgba(220, 141, 17, 255)");
        else
        if (FPS >= 10)
			Text1->SetColor("rgba(220, 70, 17, 255)");
        else
        if (FPS >= 0)
			Text1->SetColor("rgba(220, 17, 17, 255)");

		
		Text1->SetText("FPS: "+to_string(FPS));
	}
	else
	if (Text1->GetSpec() == "Progress")
	{
		Text1->SetText(to_string(Game1->Progress));
	}
	else
	if (Text1->GetSpec() == "BuildingLimit")
	{
		Text1->SetText(to_string(Game1->Castes[Game1->Player1->Team]->Settlements.size())+"/"+to_string(Game1->Castes[Game1->Player1->Team]->BuildingLimit));
	}
	else
	if (Text1->GetSpec() == "Cash")
	{
		int Basic = Game1->Castes[Game1->Player1->Team]->Cash;
		int Preview = Game1->Castes[Game1->Player1->Team]->PreviewCash;
		if (Preview-Basic >= 0)
			Text1->SetText(to_string(Basic)+"/"+to_string(Game1->Castes[Game1->Player1->Team]->ResourcesLimit)+" (+"+to_string(Preview-Basic)+")");
		else
			Text1->SetText(to_string(Basic)+"/"+to_string(Game1->Castes[Game1->Player1->Team]->ResourcesLimit)+" ("+to_string(Preview-Basic)+")");
	}
	else
	if (Text1->GetSpec() == "Food")
	{
		int Basic = Game1->Castes[Game1->Player1->Team]->Food;
		int Preview = Game1->Castes[Game1->Player1->Team]->PreviewFood;
		if (Preview-Basic >= 0)
			Text1->SetText(to_string(Basic)+"/"+to_string(Game1->Castes[Game1->Player1->Team]->ResourcesLimit)+" (+"+to_string(Preview-Basic)+")");
		else
			Text1->SetText(to_string(Basic)+"/"+to_string(Game1->Castes[Game1->Player1->Team]->ResourcesLimit)+" ("+to_string(Preview-Basic)+")");
	}
	else
	if (Text1->GetSpec() == "Wood")
	{
		int Basic = Game1->Castes[Game1->Player1->Team]->Wood;
		int Preview = Game1->Castes[Game1->Player1->Team]->PreviewWood;
		if (Preview-Basic >= 0)
			Text1->SetText(to_string(Basic)+"/"+to_string(Game1->Castes[Game1->Player1->Team]->ResourcesLimit)+" (+"+to_string(Preview-Basic)+")");
		else
			Text1->SetText(to_string(Basic)+"/"+to_string(Game1->Castes[Game1->Player1->Team]->ResourcesLimit)+" ("+to_string(Preview-Basic)+")");
	}
	else
	if (Text1->GetSpec() == "Population")
	{
		int Basic = Game1->Castes[Game1->Player1->Team]->Population;
		int Preview = Game1->Castes[Game1->Player1->Team]->PreviewPopulation;
		if (Preview-Basic >= 0)
			Text1->SetText(to_string(Basic)+" (+"+to_string(Preview-Basic)+")");
		else
			Text1->SetText(to_string(Basic)+" ("+to_string(Preview-Basic)+")");
	}
	else
	if (Text1->GetSpec() == "TechnologyPoints")
	{
		int Basic = Game1->Castes[Game1->Player1->Team]->TechnologyPoints;
		int Preview = Game1->Castes[Game1->Player1->Team]->PreviewTechnologyPoints;
		if (Preview-Basic >= 0)
			Text1->SetText(to_string(Basic)+" (+"+to_string(Preview-Basic)+")");
		else
			Text1->SetText(to_string(Basic)+" ("+to_string(Preview-Basic)+")");
	}
	else
	if (Text1->GetSpec() == "DiploPoints")
	{
		int Basic = Game1->Castes[Game1->Player1->Team]->DiploPoints;
		int Preview = Game1->Castes[Game1->Player1->Team]->PreviewDiploPoints;
		if (Preview-Basic >= 0)
			Text1->SetText(to_string(Basic)+" (+"+to_string(Preview-Basic)+")");
		else
			Text1->SetText(to_string(Basic)+" ("+to_string(Preview-Basic)+")");
	}
	else
	if (Text1->GetSpec() == "MovePoints")
	{
		int Basic = Game1->Castes[Game1->Player1->Team]->MovePoints;
		int Preview = Game1->Castes[Game1->Player1->Team]->PreviewMovePoints;
		if (Preview-Basic >= 0)
			Text1->SetText(to_string(Basic)+" (+"+to_string(Preview-Basic)+")");
		else
			Text1->SetText(to_string(Basic)+" ("+to_string(Preview-Basic)+")");
	}
	else
	if (Text1->GetSpec() == "SquadCondition")
	{
		//Text1->SetText(to_string(Game1->Player1->Squad1->GetCondition())+"%");
		int Basic = Game1->Castes[Game1->Player1->Team]->Army;
		int Preview = Game1->Castes[Game1->Player1->Team]->PreviewArmy;
		if (Preview-Basic >= 0)
			Text1->SetText(to_string(Basic)+" (+"+to_string(Preview-Basic)+")");
		else
			Text1->SetText(to_string(Basic)+" ("+to_string(Preview-Basic)+")");
	}
	else
	/*
	if (Text1->GetSpec() == "NewGameTeam")
	{
		Text1->SetText("~T_NewGameTeam"+to_string(NewGameTeam+1));

		if (NewGameTeam == 0)
			Text1->SetColor("rgba(194, 188, 189, 255)");
		else
		if (NewGameTeam == 1)
			Text1->SetColor("rgba(249, 17, 82, 255)");
		else
		if (NewGameTeam == 2)
			Text1->SetColor("rgba(249, 102, 92, 255)");
		else
		if (NewGameTeam == 3)
			Text1->SetColor("rgba(215, 216, 71, 255)");
		else
		if (NewGameTeam == 4)
			Text1->SetColor("rgba(86, 190, 103, 255)");
		else
		if (NewGameTeam == 5)
			Text1->SetColor("rgba(96, 210, 174, 255)");
		else
		if (NewGameTeam == 6)
			Text1->SetColor("rgba(81, 196, 240, 255)");
		else
		if (NewGameTeam == 7)
			Text1->SetColor("rgba(102, 102, 102, 255)");
		else
			Text1->SetColor("rgba(255, 255, 255, 255)");
	}
	else
	*/
	if (CutBackNum(Text1->GetSpec()) == "NewGamePlayerName")
	{
		size_t num = GetBackEventNumber(Text1->GetSpec());
		if (num <= NewGamePlayers.size())
			Text1->SetText(NewGamePlayers[num].Name);
	}
	else
	if (CutBackNum(Text1->GetImageId()) == "Item" && CutBackNum(Text1->GetSpec()) == "Color")
	{
		size_t num = GetBackEventNumber(Text1->GetImageId());
		if (num <= NewGamePlayers.size())
		{
			sf::Color Color = StringToColor( NewGamePlayers[num].Color );

			string Spec = Text1->GetSpec();
			if (Spec[Spec.length()-1] == '0')
				Text1->SetText(to_string(Color.r));
			else
			if (Spec[Spec.length()-1] == '1')
				Text1->SetText(to_string(Color.g));
			else
			if (Spec[Spec.length()-1] == '2')
				Text1->SetText(to_string(Color.b));
			else // if error
				Text1->SetText(to_string(255));
		}
	}
	else
	if (CutBackNum(Text1->GetSpec()) == "TeamName")
	{
		size_t Team = GetBackEventNumber(Text1->GetSpec());
		if (Team <= Game1->Castes.size())
		{
			Text1->SetText( Game1->Castes[Team]->Name );
			string buffer = "";
			for (size_t i = 0; i < Game1->Castes[Team]->Color.length(); i++)
			if (Game1->Castes[Team]->Color[i] == ';')
				buffer += ',';
			else
				buffer += Game1->Castes[Team]->Color[i];
			Text1->SetColor("rgba("+buffer+")");
		}
	}
	else
	if (CutBackNum(Text1->GetSpec()) == "TeamNation")
	{
		size_t Team = GetBackEventNumber(Text1->GetSpec());
		Text1->SetText(LanguagePack1->GetLanguageText("T_NewGameNation")+": "+LanguagePack1->GetLanguageText("T_NewGameNation" + to_string(Game1->Castes[Team]->NationToInt())));
	}
	else
	if (CutBackNum(Text1->GetSpec()) == "TeamAttitude")
	{
		string Buffer = "";
		size_t Attitude = GetBackEventNumber(Text1->GetSpec());
		// Attitude 
		if (Attitude <= Game1->Castes.size())
		{
			Attitude = Game1->Castes[ Attitude ]->Attitude[Game1->Player1->Team];
			Text1->SetText( to_string(Attitude) );
		
			if (Attitude >= 0 && Attitude <= 15)
				Text1->SetColor("rgba(196, 90, 90, 255)");
			else
			if (Attitude >= 20 && Attitude <= 30)
				Text1->SetColor("rgba(196, 174, 90, 174)");
			else
				Text1->SetColor("rgba(116, 182, 95, 255)");
		}
	}
	else
	if (CutBackNum(Text1->GetSpec()) == "TeamStatus")
	{
		string Buffer = "";
		size_t Attitude = GetBackEventNumber(Text1->GetSpec());

		if (Attitude <= Game1->Castes.size())
		{
			// Status 
			size_t Status = Game1->Castes[Attitude]->Status[Game1->Player1->Team];
			if (Game1->Castes[Attitude]->Team == Game1->Player1->Team)
			{
				Text1->SetColor("rgba(116, 182, 95, 255)");
				Buffer += "T_Relatives";
			}
			else
			{
				if (Status == 0)
				{
					Text1->SetColor("rgba(196, 90, 90, 255)");
					Buffer += "T_AtWar";
				}
				else
				if (Status == 1)
				{
					Text1->SetColor("rgba(196, 174, 90, 174)");
					Buffer += "T_Peace";
				}
				else
				{
					Text1->SetColor("rgba(116, 182, 95, 255)");
					Buffer += "T_Ally";
				}
			}
			// Status 
			Text1->SetText( LanguagePack1->GetLanguageText(Buffer) );
		}
		else
			Text1->SetText("- - - - - ");
	}
	else
	if (CutBackNum(Text1->GetSpec()) == "StatisticsTeam")
	{
		string Buffer = "";
		size_t Attitude = GetBackEventNumber(Text1->GetSpec());

		if (Attitude <= Game1->Castes.size())
		{
			bool Relatives = false;
			// Status 
			size_t Status = Game1->Castes[Attitude-1]->Status[Game1->Player1->Team];
			if (Game1->Castes[Attitude-1]->Team == Game1->Player1->Team)
			{
				Text1->SetColor("rgba(116, 182, 95, 255)");
				Buffer += "T_Relatives";
				Relatives = true;
			}
			else
			{
				if (Status == 0)
				{
					Text1->SetColor("rgba(196, 90, 90, 255)");
					Buffer += "T_AtWar";
				}
				else
				if (Status == 1)
				{
					Text1->SetColor("rgba(196, 174, 90, 174)");
					Buffer += "T_Peace";
				}
				else
				{
					Text1->SetColor("rgba(116, 182, 95, 255)");
					Buffer += "T_Ally";
				}
			}
			// Attitude 
			Attitude = Game1->Castes[ Attitude-1 ]->Attitude[Game1->Player1->Team];

			if (Relatives == false)
				Text1->SetText(LanguagePack1->GetLanguageText(Buffer)+" ("+to_string(Attitude)+")");
			else
				Text1->SetText(LanguagePack1->GetLanguageText(Buffer));
		}
		else
			Text1->SetText( "- - - - - " );
	}
	else
	if (Text1->GetSpec() == "SettlementName")
	{
		string TypeStr = "";
		SettlementTypes Type = SettlementTypes::None;
		if (Game1->Player1->SettlementType == SettlementTypes::None)
		{
			for (size_t i = 0; i < Game1->Castes.size(); i++)
			for (size_t j = 0; j < Game1->Castes[i]->Settlements.size(); j++)
			if (Game1->Castes[i]->Settlements[j].X == MapPointer1->GetX() && Game1->Castes[i]->Settlements[j].Y == MapPointer1->GetY())
			{
				Type = Game1->Castes[i]->Settlements[j].GetType();
			}
		}
		else
		{
			Type = Game1->Player1->SettlementType;
		}

		//
		if (Type == SettlementTypes::Settlement)
			TypeStr = "Settlement";
		else
		if (Type == SettlementTypes::Barn)
			TypeStr = "Barn";
		else
		//
		if (Type == SettlementTypes::Wall)
			TypeStr = "Wall";
		else
		if (Type == SettlementTypes::Tower)
			TypeStr = "Tower";
		else
		if (Type == SettlementTypes::Castle)
			TypeStr = "Castle";
		else
		//
		if (Type == SettlementTypes::Field)
			TypeStr = "Field";
		else
		if (Type == SettlementTypes::Pasture)
			TypeStr = "Pasture";
		else
		if (Type == SettlementTypes::Fisheries)
			TypeStr = "Fisheries";
		else
		//
		if (Type == SettlementTypes::Suburb)
			TypeStr = "Suburb";
		else
		if (Type == SettlementTypes::Sawmill)
			TypeStr = "Sawmill";
		//

		Text1->SetText("~T_" + TypeStr);
	}
	else
	if (Text1->GetSpec() == "TradeName")
	{
		Text1->SetText("~T_" + GetItemStatus("Name", i));
	}
	else
	if (Text1->GetSpec() == "TradeClass")
	{
		Text1->SetText("~T_" + GetItemStatus("Class", i));
	}
	else
	if (Text1->GetSpec() == "TradeCost")
	{
		string Buffer = GetItemStatus("Cost", i);
		if (Buffer == "None")
			Text1->SetText("~T_None");
		else
			Text1->SetText( GetItemStatus("Cost", i) );
	}
	else
	if (Text1->GetSpec() == "TradeSize")
	{
		Text1->SetText( GetItemStatus("Size", i) );
	}
	else
	if (Text1->GetSpec() == "TradeDescription")
	{
		Text1->SetText( "~T_"+GetItemStatus("Description", i) );
	}
	else
	if (Text1->GetSpec() == "SettlementDescription1")
	{
		MapBlock MapBlock1 = LandMap1->BlocksVector[MapPointer1->GetY()/32][MapPointer1->GetX()/32];
		if (DomainMap1->GetTeamMap()[MapPointer1->GetY()/32][MapPointer1->GetX()/32]-2 != Game1->Player1->Team)
			Text1->SetText("~T_SettlementDescription1_4");
		else
		if (MapBlock1.Settlement)
			Text1->SetText("~T_SettlementDescription1_1");
		else
		if ( (MapBlock1.Forest == false || SaveNewGameNation == 2) && 
			 (MapBlock1.Mountain == false || SaveNewGameNation == 3) && 
			 (MapBlock1.River == false || SaveNewGameNation == 0 || SaveNewGameNation == 1) && 
			 (MapBlock1.Land == true || (MapBlock1.Land == false || SaveNewGameNation == 1)) && 
			  !MapBlock1.Settlement )
			Text1->SetText("~T_SettlementDescription1_2");
		else
			Text1->SetText("~T_SettlementDescription1_3");
	}
	else
	if (Text1->GetSpec() == "SettlementDescription2")
	{
		Text1->SetText("~T_SettlementDescription2_1");
	}
	else
	if (Text1->GetSpec() == "SettlementDescription3")
	{
		MapBlock MapBlock1 = LandMap1->BlocksVector[MapPointer1->GetY()/32][MapPointer1->GetX()/32];
		if ( MapBlock1.Forest == true )
			Text1->SetText(LanguagePack1->GetLanguageText("T_SettlementDescription3_1")+" "+to_string(MapBlock1.Wood));
		else
			Text1->SetText(LanguagePack1->GetLanguageText("T_SettlementDescription3_2"));
	}
	else
	if (Text1->GetSpec() == "SettlementDescription4")
	{
		size_t DomainTeam1 = DomainMap1->GetTeamMap()[MapPointer1->GetY()/32][MapPointer1->GetX()/32];
		if (DomainTeam1 == 0 || DomainTeam1 == 1)
			Text1->SetText( LanguagePack1->GetLanguageText("T_SettlementDescription4_1")+" "+LanguagePack1->GetLanguageText("T_Team"+to_string(DomainTeam1)) );
		else
			Text1->SetText( LanguagePack1->GetLanguageText("T_SettlementDescription4_1")+" "+Game1->Castes[DomainTeam1-2]->Name );
	}
	else
	if (Text1->GetSpec() == "SettlementDescription5")
	{
		Settlement Settlement1;
		size_t Type = 0;
		for (size_t i = 0; i < Game1->Castes.size(); i++)
		{
		for (size_t j = 0; j < Game1->Castes[i]->Settlements.size(); j++)
		{
			Settlement1 = Game1->Castes[i]->Settlements[j];
			if (Settlement1.X == Game1->Player1->X && Settlement1.Y == Game1->Player1->Y)
			{
				Type = Settlement1.GetTypeInt();
				break;
			}
		}
		if (Type != 0)
			break;
		}
		//
		if (Type == 1)
			Text1->SetText("+Food; +Cash; +Technologys;");
		else
		if (Type == 2)
			Text1->SetText("-Food; -Cash;");
		else
		if (Type == 3)
			Text1->SetText("+Food;");
		else
		if (Type == 4)
			Text1->SetText("+Food;");
		else
		if (Type == 5)
			Text1->SetText("+Food; +Cash;");
		else
		if (Type == 6)
			Text1->SetText("-Food; +Cash; +Population;");
		else
		if (Type == 7)
			Text1->SetText("-Food; +Wood;");
	}
	else
	if (Text1->GetSpec() == "NewGameNation")
	{
		Text1->SetText(LanguagePack1->GetLanguageText("T_NewGameNation"+to_string(NewGameNation)));
	}
	else
	if (Text1->GetSpec() == "NewGameNationBonus")
	{
		Text1->SetText(LanguagePack1->GetLanguageText("T_NewGameNationBonus"+to_string(NewGameNation)));
	}
	else
	if (Text1->GetSpec() == "MusicCount")
	{
		Text1->SetText(LanguagePack1->GetLanguageText("T_NowPlaying")+" "+to_string(Audio1->MusicCount));
	}
	else
	if (Text1->GetSpec() == "NeedResources")
	{
		if (NeedResources != "")
		{
			ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[1]);
			Text1->SetXY(to_string(Width/2), to_string(160));
			Text1->XX = Width/2;
			Text1->YY = 140;

			Text1->Size = 36*UI1->ResizeWidth;

			if (NeedResources[0] == ';')
			{
				string Buffer = NeedResources;
				Buffer.erase(Buffer.begin());
				Text1->SetText(LanguagePack1->GetLanguageText(Buffer));
			}
			else
				Text1->SetText( LanguagePack1->GetLanguageText("T_NeedResources")+" "+NeedResourcesStr());
		}
		else
			Text1->SetText("");
	}
	else
	if (CutBackNum(Text1->GetSpec()) == "NeedResources")
	{
		if (NeedResources != "")
		{
			ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[1]);
			Text1->SetXY(to_string(Width/2), to_string(160));
			Text1->XX = Width/2;
			Text1->YY = 140;

			Text1->Size = 36*UI1->ResizeWidth;

			if (NeedResources[0] == ';')
			{
				string Buffer = NeedResources;
				Buffer.erase(Buffer.begin());
				Text1->SetText( LanguagePack1->GetLanguageText(Buffer) );
			}
			else
				Text1->SetText( LanguagePack1->GetLanguageText("T_NeedResources")+" "+NeedResourcesStr());
		}
		else
			Text1->SetText("");

		if (Text1->GetSpec() == "NeedResources1")
			Text1->SetXY(to_string(Text1->GetXY().x-2), to_string(Text1->GetXY().y));
		else
		if (Text1->GetSpec() == "NeedResources2")
			Text1->SetXY(to_string(Text1->GetXY().x+2), to_string(Text1->GetXY().y));
		else
		if (Text1->GetSpec() == "NeedResources3")
			Text1->SetXY(to_string(Text1->GetXY().x), to_string(Text1->GetXY().y-2));
		else
		if (Text1->GetSpec() == "NeedResources4")
			Text1->SetXY(to_string(Text1->GetXY().x), to_string(Text1->GetXY().y+2));
		else
		if (Text1->GetSpec() == "NeedResources5")
			Text1->SetXY(to_string(Text1->GetXY().x-3), to_string(Text1->GetXY().y));
		else
		if (Text1->GetSpec() == "NeedResources6")
			Text1->SetXY(to_string(Text1->GetXY().x+3), to_string(Text1->GetXY().y));
		else
		if (Text1->GetSpec() == "NeedResources7")
			Text1->SetXY(to_string(Text1->GetXY().x), to_string(Text1->GetXY().y-3));
		else
		if (Text1->GetSpec() == "NeedResources8")
			Text1->SetXY(to_string(Text1->GetXY().x), to_string(Text1->GetXY().y+3));
	}
	else
	if (Text1->GetSpec() == "MapName")
	{
		Text1->SetText( LanguagePack1->GetLanguageText("T_MapName")+": "+CurrentMapName );
	}
	else
	if (Text1->GetSpec() == "MapSize")
	{
		Text1->SetText( LanguagePack1->GetLanguageText("T_MapSize")+": "+CurrentMapSize );
	}
	else
	if (Text1->GetSpec() == "MapTeams")
	{
		Text1->SetText( LanguagePack1->GetLanguageText("T_MapTeams")+": "+to_string(CurrentMapTeams) );
	}
	else
	if (Text1->GetSpec() == "SettlementArmy")
	{
		Settlement Settlement1;
		for (size_t i = 0; i < Game1->Castes[Game1->Player1->Team]->Settlements.size(); i++)
		{
			Settlement1 = Game1->Castes[Game1->Player1->Team]->Settlements[i];
			if (Settlement1.X == Game1->Player1->X && Settlement1.Y == Game1->Player1->Y)
			{
				if (Settlement1.GetType() == SettlementTypes::Settlement)
					Text1->SetText( to_string(Settlement1.Army)+" / "+to_string(Game1->Castes[Game1->Player1->Team]->SettlementArmyLimit) );
				else
				if (Settlement1.GetType() == SettlementTypes::Castle)
					Text1->SetText( to_string(Settlement1.Army)+" / "+to_string(Game1->Castes[Game1->Player1->Team]->CastleArmyLimit) );
				break;
			}
		}
	}
	else
	if (Text1->GetSpec() == "NewGamePlayersList")
	{
		size_t NewGamePlayersSize = 0;
		for (size_t i = 0; i < NewGamePlayers.size(); i++)
		{
			if (NewGamePlayers[i].Num != -1)
				NewGamePlayersSize++;
		}

		Text1->SetText( LanguagePack1->GetLanguageText("T_Players")+" ("+to_string(NewGamePlayersSize)+"/"+to_string(CurrentMapTeams)+")" );
	}
	//
}