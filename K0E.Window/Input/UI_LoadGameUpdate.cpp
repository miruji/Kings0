#include "../Window.h"

string CutBackDot(string Data)
{
	string Buffer = "";
	for (size_t i = 0; i < Data.length(); i++)
	{
		if (Data[i] == '.')
			break;
		else
			Buffer += Data[i];
	}
	return Buffer;
}

vector<string> GetSaveData(string Path, Console* Console1)
{
    XMLParser* XMLParser1 = new XMLParser();
    XMLParser1->LoadDocument("Data\\Saves\\"+Path+".xml", Console1);

	vector<string> Result;
    if (true)
    {
    TiXmlElement* ElData = XMLParser1->GetDataElement();
    TiXmlElement* ElInit = ElData->FirstChildElement("Init");
    while (ElInit != NULL)
	{
        if (ElInit->Attribute("Date"))
			Result.push_back(ElInit->Attribute("Date"));
		else
		if (ElInit->Attribute("Date") == "")
			Result.push_back("");
        
        if (ElInit->Attribute("PlayerTeam"))
			Result.push_back(ElInit->Attribute("PlayerTeam"));
		else
		if (ElInit->Attribute("PlayerTeam") == "")
			Result.push_back("");
        
        if (ElInit->Attribute("Map"))
			Result.push_back(ElInit->Attribute("Map"));
		else
		if (ElInit->Attribute("Map") == "")
			Result.push_back("");

        ElInit = ElInit->NextSiblingElement("Init");
	}
    }

	cout << "Result: ";
	for (size_t i = 0; i < Result.size(); i++)
		cout << Result[i] << "; ";
	cout << endl;
	return Result;
}

void Window::UI_LoadGameUpdate()
{
	vector< string > Files2;
	if (true)
	{
	// Searh .xml files in Iteam path 
    WIN32_FIND_DATAW wfd;
 
    HANDLE const hFind = FindFirstFileW(L"Data\\Saves\\*", &wfd);
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
	string EndFile = "";
	for (size_t i = 0; i < Files.size(); i++)
	{
		//
		if (Files[i] != "")
		if ( ThisInt( CutBackDot(Files[i])[0] ) )
		if ((Files[i][Files[i].length()-3] == 'x' || Files[i][Files[i].length()-3] == 'X') &&
			(Files[i][Files[i].length()-2] == 'm' || Files[i][Files[i].length()-2] == 'M') &&
			(Files[i][Files[i].length()-1] == 'l' || Files[i][Files[i].length()-1] == 'L') )
		{
			// ... 
			for (short int j = Files[i].length()-4; j > -1; j--)
			{
				// ... 
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
	}
	///cout << "Total: " << Files2.size() << endl;

	// 
	vector< vector<string> > Saves;
	if (true)
	{
		vector<string> Buffer;
		Saves.push_back(Buffer);
		Saves.push_back(Buffer);
		Saves.push_back(Buffer);
		Saves.push_back(Buffer);
		Saves.push_back(Buffer);
	}
	for (size_t j = 0; j < 5; j++)
	{
		//
		if (j < Files2.size())
		{
			if(Files2[j] == "0" || Files2[j] == "1" || Files2[j] == "2" || Files2[j] == "3" || Files2[j] == "4")
			//cout << "Open " << to_string(j) << endl;
				Saves[atoi(Files2[j].c_str())] = ( GetSaveData(Files2[j], Console1) );
		}
		//	cout << "No " << to_string(j) << endl;

		UIImage* UIImage1;
		for (size_t i = 0; i < UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Image.size(); i++)
		{
			UIImage1 = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Image[i];
			if (UIImage1->GetId() == "Icon"+to_string(j))
			{
				//cout << "j: " << to_string(j) << ": " << to_string(Saves[j].size()) << endl;
				if (Saves[j].size() != 0)
				{
					UIImage1->LoadTextureToSprite("Data\\Textures\\UI\\LoadGameIcon"+Saves[j][1]+".png", "62", "62");
				}
				else
					UIImage1->LoadTextureToSprite("Data\\Textures\\UI\\LoadGameIconNone.png", "62", "62");
			}
		}

		UIText* UIText1;
		for (size_t i = 0; i < UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Text.size(); i++)
		{
			UIText1 = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Text[i];
			if (UIText1->GetId() == "Name"+to_string(j))
			{
				if (Saves[j].size() != 0)
				{
					UIText1->SetText( Saves[j][0] );
				}
				else
					UIText1->SetText( LanguagePack1->GetLanguageText("T_None") );
			}
			else
			if (UIText1->GetId() == "Team"+to_string(j))
			{
				if (Saves[j].size() != 0)
				{
					string Buffer = "Silver";

					UIText1->SetText( LanguagePack1->GetLanguageText("T_Team")+": "+LanguagePack1->GetLanguageText( "T_Team"+to_string(atoi(Saves[j][1].c_str())+1) ) );
				}
				else
					UIText1->SetText( LanguagePack1->GetLanguageText("T_Team")+": "+LanguagePack1->GetLanguageText("T_None") );
			}
			else
			if (UIText1->GetId() == "Map"+to_string(j))
			{
				if (Saves[j].size() != 0)
				{
					UIText1->SetText( LanguagePack1->GetLanguageText("T_Map")+": "+Saves[j][2]);
				}
				else
					UIText1->SetText( LanguagePack1->GetLanguageText("T_Map")+": "+ LanguagePack1->GetLanguageText("T_None") );
			}
		}
		//
	}
}