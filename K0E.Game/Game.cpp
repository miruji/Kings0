#include "Game.h"

// Constructor
Game::Game(vector<int> NewGamePlayers)
{
	//
	XMLParser1 = new XMLParser();
	this->NewGamePlayers = NewGamePlayers;
}

// Creae game 
void Game::CreateGame(string CurrentMapName, string Name, size_t Team, size_t Nation, size_t Flag, Console* Console1)
{
	// Parse Items
	ParseItems(Element, Console1);
	//ParseEvents(Element);
	//ParseCharacters(Element);

	// Castes 
	Castes = GetGameCastes(CurrentMapName, Console1);

	// Player 
	Player1 = new Player(Name);
	Player1->Team = Team;

	Castes[Player1->Team]->ClearTechnologys();

	if (Nation == 0)
		Castes[Player1->Team]->Nation = CasteNation::Steppe;
	else
	if (Nation == 1)
		Castes[Player1->Team]->Nation = CasteNation::Water;
	else
	if (Nation == 2)
		Castes[Player1->Team]->Nation = CasteNation::Sedentary;
	else
	if (Nation == 3)
		Castes[Player1->Team]->Nation = CasteNation::Mountain;

	Castes[Player1->Team]->Rune = Flag+1;
	Castes[Player1->Team]->UpdateNation(Nation);
}

// Parse Items 
void Game::ParseItems(TiXmlElement* MainBlock, Console* Console1)
{
	// Searh .xml files in Iteam path 
    WIN32_FIND_DATAW wfd;
 
    HANDLE const hFind = FindFirstFileW(L"Data\\Game\\Items\\*", &wfd);
	setlocale(LC_ALL, "");
 
	vector< string > Files;
    if (INVALID_HANDLE_VALUE != hFind)
    {
        do
        {
			//
			wchar_t* FileName = &wfd.cFileName[0];
			wstring ws(FileName);
			// New str 
			string FileNameString(ws.begin(), ws.end());
			// To vector 
			Files.push_back(FileNameString);
			
		} 
		while (NULL != FindNextFileW(hFind, &wfd));
 
        FindClose(hFind);
    }
	// Search .xml files 
	string Revers = "";
	vector< string > Files2;
	string EndFile = "";
	for (size_t i = 0; i < Files.size(); i++)
	{
		//
		if ((Files[i][Files[i].length()-3] == 'x' || Files[i][Files[i].length()-3] == 'X') &&
			(Files[i][Files[i].length()-2] == 'm' || Files[i][Files[i].length()-2] == 'M') &&
			(Files[i][Files[i].length()-1] == 'l' || Files[i][Files[i].length()-1] == 'L') )
		{
			//
			for (short int j = Files[i].length()-4; j > -1; j--)
			{
				//
				Revers += Files[i][j];
			}
			// un-revers
			for (size_t j = Revers.size()-1; j > 0; j--)
			{
				EndFile += Revers[j];
			}
			Files2.push_back( EndFile );
			Revers = "";
			EndFile = "";
		}
	}
	// Open files 
	string Name = "";
	string Type = "";
	size_t Cash = 0;
	for (size_t i = 0; i < Files2.size(); i++)
	{
		// XML Parser
		if (i != 0)
			cout << "  ";
		XMLParser1->LoadDocument("Data\\Game\\Items\\"+Files2[i]+".xml", Console1);
		Data = XMLParser1->GetDataElement();
		Element = Data->FirstChildElement("Item");

		// Search attribute and save to var
		if (Element->Attribute("Name"))
			Name = Element->Attribute("Name");
		else
			return;

		if (Element->Attribute("Type"))
			Type = Element->Attribute("Type");
		else
			return;

		if (Element->Attribute("Cash"))
		{
			Cash = atoi(Element->Attribute("Cash"));
		}
		else
			return;

		Items.push_back( new Item(Name, Type, Cash) );
		Name = ""; Type = ""; Cash = 0;
	}
}

// Parse Events 
void Game::ParseEvents(TiXmlElement* MainBlock, Console* Console1)
{
	// Searh .xml files in Iteam path 
    WIN32_FIND_DATAW wfd;
 
    HANDLE const hFind = FindFirstFileW(L"Data\\Events\\*", &wfd);
	setlocale(LC_ALL, "");
 
	vector< string > Files;
    if (INVALID_HANDLE_VALUE != hFind)
    {
        do
        {
			//
			wchar_t* FileName = &wfd.cFileName[0];
			wstring ws(FileName);
			// New str 
			string FileNameString(ws.begin(), ws.end());
			// To vector 
			Files.push_back(FileNameString);
			
		} 
		while (NULL != FindNextFileW(hFind, &wfd));
 
        FindClose(hFind);
    }
	// Search .xml files 
	string Revers = "";
	vector< string > Files2;
	string EndFile = "";
	for (size_t i = 0; i < Files.size(); i++)
	{
		//
		if ((Files[i][Files[i].length()-3] == 'x' || Files[i][Files[i].length()-3] == 'X') &&
			(Files[i][Files[i].length()-2] == 'm' || Files[i][Files[i].length()-2] == 'M') &&
			(Files[i][Files[i].length()-1] == 'l' || Files[i][Files[i].length()-1] == 'L') )
		{
			//
			for (short int j = Files[i].length()-4; j > -1; j--)
			{
				//
				Revers += Files[i][j];
			}
			// un-revers
			for (size_t j = Revers.size()-1; j > 0; j--)
			{
				EndFile += Revers[j];
			}
			Files2.push_back( EndFile );
			Revers = "";
			EndFile = "";
		}
	}
	// Open files 
	string Type = "";
	string Yes = "";
	string No = "";
	for (size_t i = 0; i < Files2.size(); i++)
	{
		// XML Parser
		XMLParser1->LoadDocument("Data\\Events\\"+ Files2[i]+".xml", Console1);
		Element = XMLParser1->GetDataElement();

		// Search attribute and save to var
		if (Element->Attribute("Type"))
			Type = Element->Attribute("Type");
		else
			return;

		if (Element->Attribute("Yes"))
			Yes = Element->Attribute("Yes");
		else
			return;

		if (Element->Attribute("No"))
			No = Element->Attribute("No");
		else
			return;

		Events.push_back( new Event(i, Type, Yes, No) );
		Type = ""; Yes = ""; No = "";
	}
}

// Parse Characters  
void Game::ParseCharacters(TiXmlElement* MainBlock, Console* Console1)
{
	// Searh .xml files in Iteam path 
    WIN32_FIND_DATAW wfd;
 
    HANDLE const hFind = FindFirstFileW(L"Data\\Characters\\*", &wfd);
	setlocale(LC_ALL, "");
 
	vector< string > Files;
    if (INVALID_HANDLE_VALUE != hFind)
    {
        do
        {
			// ... 
			wchar_t* FileName = &wfd.cFileName[0];
			std::wstring ws(FileName);
			// New str 
			std::string FileNameString(ws.begin(), ws.end());
			// To vector 
			Files.push_back(FileNameString);
			
		} 
		while (NULL != FindNextFileW(hFind, &wfd));
 
        FindClose(hFind);
    }
	// Search .xml files 
	string Revers = "";
	vector< string > Files2;
	string EndFile = "";
	for (size_t i = 0; i < Files.size(); i++)
	{
		//
		if ((Files[i][Files[i].length()-3] == 'x' || Files[i][Files[i].length()-3] == 'X') &&
			(Files[i][Files[i].length()-2] == 'm' || Files[i][Files[i].length()-2] == 'M') &&
			(Files[i][Files[i].length()-1] == 'l' || Files[i][Files[i].length()-1] == 'L') )
		{
			//
			for (short int j = Files[i].length()-4; j > -1; j--)
			{
				//
				Revers += Files[i][j];
			}
			// un-revers
			for (size_t j = Revers.size()-1; j > 0; j--)
			{
				EndFile += Revers[j];
			}
			Files2.push_back( EndFile );
			Revers = "";
			EndFile = "";
		}
	}
	// Open files 
	string Name = "";
	string Class = "";
	string Source = "";
	size_t Grade = 0;
	for (size_t i = 0; i < Files2.size(); i++)
	{
		// XML Parser
		XMLParser1->LoadDocument("Data\\Characters\\"+ Files2[i]+".xml", Console1);
		Element = XMLParser1->GetDataElement();

		// Search attribute and save to var
		if (Element->Attribute("Name"))
			Name = Element->Attribute("Name");
		else
			return;

		if (Element->Attribute("Class"))
			Class = Element->Attribute("Class");
		else
			return;

		if (Element->Attribute("Grade"))
			Grade = atoi(Element->Attribute("Grade"));
		else
			return;

		if (Element->Attribute("Source"))
			Source = Element->Attribute("Source");
		else
			return;

		Characters.push_back( new Character(Name, Class, Grade, Source) );
		Name = ""; Class = ""; Source = ""; Grade = 0;
	}
}

// Get game castes 
vector< Caste* > Game::GetGameCastes(string CurrentMapName, Console* Console1)
{
	// AI data of map
	XMLParser1->LoadDocument(CurrentMapName, Console1);
	XMLCastes = XMLParser1->MapAI();
	vector<Caste*> Result;
	XMLSettlement* XMLSettlement1;
	vector<Settlement> Settlements;

	for (size_t i = 0; i < XMLCastes.size(); i++)
	//if (NewGamePlayers[i] >= 0)
	{
		//
		Console1->IPrintln("> Caste " + std::to_string(i) + ": ");

		//
		for (size_t j = 0; j < XMLCastes[i]->XMLSettlements.size(); j++)
		{
			//
			XMLSettlement1 = XMLCastes[i]->XMLSettlements[j];
				
			Settlements.push_back( 
				Settlement(
					XMLSettlement1->Name,
					XMLSettlement1->Type,
					XMLSettlement1->Population,
					XMLSettlement1->Team,
					XMLSettlement1->X*32,
					XMLSettlement1->Y*32
				)
			);
				
		}

		Console1->SetIndent(Console1->GetIndent()+1);
		Console1->IPrintln("Created " + std::to_string(XMLCastes[i]->XMLSettlements.size()) + " settlements. ");
		Console1->SetIndent(Console1->GetIndent()-1);


		//
		Result.push_back( new Caste(XMLCastes[i]->Team, XMLCastes.size(), Settlements, Characters));
		Settlements.clear();
	}

	return Result;
}