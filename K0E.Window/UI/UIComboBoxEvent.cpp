#include "../Window.h"

// UI: ComboBox Current item 
string Window::UIComboBoxCurrentItem(string ComboEvent)
{
	//
	if (ComboEvent == "WindowMode")
	{
		if (SaveWindowMode == 0)
			//Buffer = LanguagePack1->GetLanguageText("T_WindowModeWindowed");
			return "W";
		else
		if (SaveWindowMode == 1)
			//Buffer = LanguagePack1->GetLanguageText("T_WindowModeFullscreenWindowed");
			return "FW";
		else
		if (SaveWindowMode == 2)
			//Buffer = LanguagePack1->GetLanguageText("T_WindowModeFullscreen");
			return "F";
	}
	else
	if (ComboEvent == "VideoMode")
	{
		return to_string(Width)+"x"+ to_string(Height);
	}
	else
	if (ComboEvent == "FramerateLimit")
	{
		return to_string(FramerateLimit);
	}
	else
	if (ComboEvent == "Language")
	{
		return LanguagePack1->GetLanguageType();
	}
	else
	if (ComboEvent == "MapName")
	{
		return CurrentMapName;
	}
	else
	if (CutBackNum(ComboEvent) == "PlayerStartPosition")
	{
		if (NewGamePlayers.size())
			return to_string(NewGamePlayers[GetBackEventNumber(ComboEvent)].StartPosition);
		else
			return "";
	}
	else
	{
		return "";
	}
}

// UI: ComboBox event 
void Window::UIComboBoxEvent(string ComboEvent, UIComboBox* UIComboBox1)
{
	//
	if (ComboEvent == "WindowMode")
	{
		vector<string> WindowMode;
		WindowMode.push_back(LanguagePack1->GetLanguageText("T_WindowModeWindowed"));
		WindowMode.push_back(LanguagePack1->GetLanguageText("T_WindowModeFullscreenWindowed"));
		WindowMode.push_back(LanguagePack1->GetLanguageText("T_WindowModeFullscreen"));
		UIComboBox1->SetTexts(WindowMode);
	}
	else
	if (ComboEvent == "VideoMode")
	{
		vector<string> VideoModes1;
		for (size_t i = 0; i < VideoModes.size(); i++)
		if (VideoModes[i].width >= 1280 && VideoModes[i].height >= 720)
		{
			VideoModes1.push_back(to_string(VideoModes[i].width)+"x"+to_string(VideoModes[i].height));
			//cout << VideoModes1[i] << endl;
		}
		UIComboBox1->SetTexts(VideoModes1);
	}
	else
	if (ComboEvent == "FramerateLimit")
	{
		vector<string> FramerateLimit1;
		FramerateLimit1.push_back("0");
		FramerateLimit1.push_back("60");
		FramerateLimit1.push_back("120");
		UIComboBox1->SetTexts(FramerateLimit1);
	}
	else
	if (ComboEvent == "Language")
	{
		vector<string> Languages1;
		for (size_t i = 0; i < LanguagePack1->GetLanguages().size(); i++)
			Languages1.push_back( LanguagePack1->GetLanguages()[i]->Type );
		
		UIComboBox1->SetTexts(Languages1);
	}
	else
	if (ComboEvent == "MapName")
	{
		vector<string> Result;
		for (size_t i = 0; i < Maps.size(); i++)
		{
			if (Maps[i].Name != "Guide")
			Result.push_back(Maps[i].Name);
		}
		
		UIComboBox1->SetTexts(Result);
	}
	else
	if (CutBackNum(ComboEvent) == "PlayerStartPosition")
	{
		vector<string> Result;
		for (size_t i = 0; i < CurrentMapTeams; i++)
			Result.push_back(to_string(i+1));
		UIComboBox1->SetTexts(Result);
	}
	else
	{
		vector<string> Result;
		Result.push_back( LanguagePack1->GetLanguageText("T_None") );

		UIComboBox1->SetTexts(Result);
	}
}

// UI: ComboBox Settings 
void Window::UIComboBoxSettings(string ComboEvent, string NewValue, size_t n)
{
	//
	if (ComboEvent == "WindowMode")
	{
		// New value ->> None 
		WindowMode = n;
	}
	else
	if (ComboEvent == "VideoMode")
	{
		string Buffer = "";
		for (size_t i = 0; i < NewValue.length(); i++)
		{
			if (NewValue[i] == 'x' || i+1 == NewValue.length())
			{
				if (i+1 == NewValue.length())
				{
					Buffer += NewValue[i];
					NewHeight = atoi(Buffer.c_str());
					Buffer = "";
				}
				else
				{
					NewWidth = atoi(Buffer.c_str());
					Buffer = "";
				}
			}
			else
				Buffer += NewValue[i];
		}
	}
	else
	if (ComboEvent == "FramerateLimit")
	{
		SaveFramerateLimit = atoi(NewValue.c_str());
	}
	else
	if (ComboEvent == "Language")
	{
		SaveLanguage = NewValue;
	}
	else
	if (ComboEvent == "MapName")
	{
		ShowAllElements(UI1->FocusedBlockName);

		string save = CurrentMapName;
		CurrentMapName = NewValue;

		for (size_t i = 0; i < Maps.size(); i++)
		if (Maps[i].Name == CurrentMapName)
		{
			CurrentMapSize = Maps[i].Size;
			CurrentMapTeams = Maps[i].Teams;
		}
		//UI_UpdateNewGamePlayerIcon();
		UI_UpdateNewGameMapImage();

		//
		UI_GenerateNewGamePlayers();

		UpdateNewGamePlayer();
		UI_UpdateNewGameItems();

		if (save != NewValue)
		{
			NewGameTeam = 0;
			UI_NewGameFlag(' ');
		}
		//
		UI_LoadGamePointerUpdate(0);
		UIComboBoxTextUpdate();
	}
	else
	if (CutBackNum(ComboEvent) == "PlayerStartPosition")
	{
		size_t num = GetBackEventNumber(ComboEvent);
		NewGamePlayers[num].StartPosition = atoi(NewValue.c_str());
	}
	else
	{

	}
}