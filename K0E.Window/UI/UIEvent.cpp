#include "../Window.h"

bool AttackEvent(string Event) 
{
	string Buffer = "";
	for (size_t i = 0; i < Event.size(); i++)
	{
		if (Buffer == "EnemyAttack")
			return true;
		Buffer += Event[i];
	}
	return false;
}

bool FileIsExist(std::string filePath)
{
	bool isExist = false;
	std::ifstream fin(filePath.c_str());

	if (fin.is_open())
		isExist = true;

	fin.close();
	return isExist;
}

// UI event (spec) 
void Window::UIEvent(char Type, string Event, bool Message, size_t Num, bool Closed)
{
	// Message ? 
	if (Event == "MessageClose")
		Message = false;

	//
	std::vector< UIBlock* >& DrawUIBlocks = UI1->GetDrawUIBlocks();
	std::vector< UIBlock* >& UIBlocks     = UI1->GetUIBlocks();
	vector< string >&        BlockNames   = UI1->GetBlockNames();

	if (Message == true)
	{
		UIEvent('$', "Message", false, Num, Closed);

		//
		vector< UIText* > Texts = DrawUIBlocks[DrawUIBlocks.size()-1]->UI_Text;
		for (size_t i = 0; i < Texts.size(); i++)
		{
			if (Texts[i]->GetSpec() == "Message")
			{
				if (AttackEvent(Event))
					Texts[i]->SetText("~T_MessageAttack");
				else
				if (CutBackNum(Event) == "NewWar")
					Texts[i]->SetText("~T_MessageNewWar");
				else
				if (CutBackNum(Event) == "TechnologyLearn")
					Texts[i]->SetText("~T_MessageTechnologyLearn");
				else
					Texts[i]->SetText("~T_Message"+Event);
				break;
			}
		}
		//
		vector< UIButton* > Buttons = DrawUIBlocks[DrawUIBlocks.size()-1]->UI_Button;
		for (size_t i = 0; i < Buttons.size(); i++)
		{
			if (Buttons[i]->GetId() == "ContinueButton")
			{
				//if (Event == "EnemyAttack0" || Event == "EnemyAttack1" || Event == "EnemyAttack2" ||
				//	Event == "EnemyAttack3" || Event == "EnemyAttack4" || Event == "EnemyAttack5" ||
				//	Event == "EnemyAttack6")
				//{
				//	cout << "Attack to team: " << Event[0] << endl;
				//}
				//else
				Buttons[i]->SetEvent(Type+Event);

				Buttons[i]->Closed = true;
				break;
			}
		}

		// Set ui message num 
		UI1->Message = UI1->GetDrawUIBlocks().size()-1;
	}
	else
	//
	if (Event != "" && Type != ' ')
	{
		// Message ? 
		if (Num != UI1->Message && UI1->Message != 0 && Event != "MessageClose" && UI1->MainMenu)
			return;

		// !
		if (Type == '~')
		{
			LPCWSTR Url = StringToWString( Event ).c_str();
			ShellExecute(NULL, L"open", Url, 0, 0, SW_SHOWNORMAL);
		}
		else
		if (Type == '!')
		{
			if (Event == "Halt")
				exit(0);
			else
			if (Event == "MessageClose")
			{
				UIEvent('!', "Close", false, Num, false);
			}
			else
			if (Event == "Close")
			{
				// Show all elements (update to now) 
				ShowAllElements(Num);
				// Close 
				DrawUIBlocks[Num]->FirstDraw = false;
				UI1->UpdateIPosition( Num );
				DrawUIBlocks.erase(DrawUIBlocks.begin()+Num);
				// Update ComboBoxs current items 
				UI_UpdateComboBoxsCurrentItems( to_string(Num) );
			}
			else
			if (Event == "Update")
			{
				// Show all elements (update to now) 
				ShowAllElements(Num);

				// Close 
				DrawUIBlocks[Num]->FirstDraw = false;

				// Update ComboBoxs current items 
				UI_UpdateComboBoxsCurrentItems( to_string(Num) );
			}
			else
			if (Event == "CreateNewGame")
			{
				bool create = true;
				for (size_t i = 0; i < NewGamePlayers.size(); i++)
				for (size_t j = 0; j < NewGamePlayers.size(); j++)
				{
					if (i != j)
					if (NewGamePlayers[i].StartPosition == NewGamePlayers[j].StartPosition)
						create = false;
				}
				//
				if (create)
				{
					CreateNewGame(false);
					NewGame = true;

					UIClearDrawBlocks(true);
					UIEvent('!', "MainMenuBack", false, 0, Closed);
					UI1->MainMenu = false;
					UI1->SetLayer(1);

					// Update flag in GameBasic 
					SaveNewGameTeam = NewGameTeam;
					SaveNewGameFlag = NewGameFlag;
					SaveNewGameNation = NewGameNation;
					UI_UpdateGameBasicFlag();
					NewGameTeam = 0;
					NewGameFlag = 0;
					NewGameNation = 0;
					// Building nums 
					Control_Tilde(false);

					UI_UpdateMapPointer(false);
				}
			}
			else
			//
			if (Event == "NewGameBackNation")
			{
				UI_NewGameNation('-');
			}
			else
			if (Event == "NewGameNextNation")
			{
				UI_NewGameNation('+');
			}
			else
			//
			if (Event == "NewGameBackFlag")
			{
				UI_NewGameFlag('-');
			}
			else
			if (Event == "NewGameNextFlag")
			{
				UI_NewGameFlag('+');
			}
			else
			//
			if (Event == "MainMenuNewGame0")
			{
				UIEvent('$', Event, false, Num, false);
			}
			else
			if (Event == "MainMenuNewGame1")
			{
				UIEvent('@', Event, false, Num, false);
				ShowAllElements(UI1->FocusedBlockName);

				for (size_t i = 0; i < Maps.size(); i++)
				if (Maps[i].Name == CurrentMapName)
				{
					CurrentMapSize = Maps[i].Size;
					CurrentMapTeams = Maps[i].Teams;
					break;
				}
				//UI_UpdateNewGamePlayerIcon();
				UI_UpdateNewGameMapImage();

				//
				UI_GenerateNewGamePlayers();

				UpdateNewGamePlayer();
				UI_UpdateNewGameItems();

				UI_NewGameFlag(' ');
				//
				UI_LoadGamePointerUpdate(0);
			}
			else
			//
			if (Event == "ToMainMenu")
			{
				UIClearDrawBlocks(false);
				//
				UIEvent('@', "MainMenu0", false, 0, Closed);
				NewGame = false;
			}
			else
			if (Event == "MainMenuBack2")
			{
				UIEvent('!', "MainMenuBack", false, 0, Closed);
			}
			else
			if (Event == "MainMenuBack")
			{
				if (NewGame == true)
				{
					if (UI1->MainMenu == true)
					{
						UIEvent('@', "GameBasic", false, Num, Closed);
					}
					else
						UIEvent('@', "MainMenu1", false, Num, Closed);

					UI_SetMainMenu();
				}
				//
				if (FirstMainMenuBack == false)
				{
					// Left block 
					UIEvent('$', "LeftBlockNone", false, 1, Closed);
					UI_LeftBlockUpdate("");

					// Build panel 
					BuildingNums = false;
					UIEvent('$', "BuildPanelMinimize", false, 1, Closed);

					// Left down buttons 
					UIEvent('$', "LeftDownButtons", false, 1, Closed);

					//
					FirstMainMenuBack = true;
					//
					UI_UpdateGameBasicFlag();
				}
			}
			else
			if (Event == "MainMenuLoadGame0")
			{
				UIEvent('$', Event, false, Num, false);
				UI_LoadGameUpdate();

				UI_LoadGamePointerUpdate(0);
			}
			else
			if (Event == "MainMenuSaveGame0")
			{
				UIEvent('$', Event, false, Num, false);
				UI_LoadGameUpdate();

				UI_LoadGamePointerUpdate(0);
			}
			else
			if (Event == "MainMenuLoadGame1") 
			{
				if (FileIsExist("Data\\Saves\\"+to_string(LoadGameUnit)+".xml"))
				{
					LoadGame();

					NewGame = true;
					UIClearDrawBlocks(true);
					UIEvent('!', "MainMenuBack", false, 0, Closed);

					UI1->MainMenu = false;
					UI1->SetLayer(1);

					UI_UpdateGameBasicFlag();

					BuildingNums = true;
					Control_Tilde(false);

					UI_UpdateMapPointer(false);
				}
			}
			else
			if (CutBackNum(Event) == "MainMenuMultiplayer")
			{
				if (CutBackNum(UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->GetName()) == "MainMenuMultiplayer")
					UIEvent('@', Event, false, Num, false);
				else
					UIEvent('$', Event, false, Num, false);

				if (Event == "MainMenuMultiplayer1")
					UIEvent('!', "CreateServer", false, Num, false);
				//
				UI_NewGameFlag(' ');

				UI_UpdateNewGamePlayerIcon();
				UI_UpdateNewGameMapImage();

				//
				NewGamePlayers.clear();
				NewGamePlayers.push_back(NewGameTeam);
				UpdateNewGamePlayer();
				//
				UI_LoadGamePointerUpdate(0);
			}
			else
			if (Event == "CreateServer")
			{
				CreateServer();
			}
			if (Event == "ConnectToIpAndPort")
			{
				ConnectToIpAndPort();
			}
			if (Event == "MainMenuSaveGame1") 
			{
				SaveGame();
				UI_LoadGameUpdate();
			}
			else
			if (Event == "MainMenuDeleteGame")
			{
				size_t Unit = 0;
				string BlockName = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->GetName();
				if (BlockName == "MainMenuLoadGame0")
					Unit = LoadGameUnit;
				else
				if (BlockName == "MainMenuSaveGame0")
					Unit = SaveGameUnit;
				//
				if (FileIsExist("Data\\Saves\\"+to_string(Unit)+".xml"))
				{
					DeleteGame(Unit);
					UI_LoadGameUpdate();
				}
			}
			else
			if (CutBackNum(Event) == "LoadGamePointerUpdate")
				UI_LoadGamePointerUpdate( CharToInt(GetBackEventNumber(Event)) );
			else
			if (Event == "MainMenuSettingsReset")
			{
				// Load basic settings 
				XMLParser* XMLParser1 = new XMLParser();
				XMLParser1->LoadDocument("Data\\Settings\\Basic.xml", Console1);
				string LanguageType = "";

				SaveSoundtrack = Audio1->Soundtrack;
				SaveSoundEffects = Audio1->SoundEffects;
				XMLParser1->SearchSettings(true, Version, Title, Width, Height, FramerateLimit, WindowMode, VerticalSync, LanguageType, Audio1->Soundtrack, Audio1->SoundEffects);
				NewWidth = Width; NewHeight = Height;
				SaveFramerateLimit = FramerateLimit;

				Audio1->Soundtrack = SaveSoundtrack;
				Audio1->SoundEffects = SaveSoundEffects;
				//cout << "Search syns: " << VerticalSync << endl;
				LanguagePack1->SetLanguageType(LanguageType);
				// Create new render 
				UIEvent('!', "MainMenuSettingsApply2", false, Num, Closed);

				// Update ComboBoxs current items 
				UI_UpdateComboBoxsCurrentItems(to_string(Num));
			}
			else
			if (Event == "MainMenuSettingsApply")
			{
				// If New Width and Height == 0 
				if (SaveWindowMode == 1)
				{
					//if (NewWidth == 0)
						NewWidth = Width;
					//if (NewHeight == 0)
						NewHeight = Height;
				}
				SaveWindowMode = WindowMode;
				FramerateLimit = SaveFramerateLimit;
				//
				LanguagePack1->SetLanguageType(SaveLanguage);
				// MainMenu2 restart 
				if (UI1->GetDrawUIBlocks()[0]->GetName() == "MainMenu1")
					MainMenu2Restart = true;
				// Save new setting in file 
				SaveSettings();
				// Update window 
				GetWindowPosition(SaveY, SaveX);
				Render.close();
				CreateNewRender();
			}
			else
			if (Event == "MainMenuSettingsApply2")
			{
				// If New Width and Height == 0 
				if (SaveWindowMode == 1)
				{
					//if (NewWidth == 0)
						NewWidth = Width;
					//if (NewHeight == 0)
						NewHeight = Height;
				}
				SaveWindowMode = WindowMode;
				FramerateLimit = SaveFramerateLimit;
				//
				LanguagePack1->SetLanguageType(SaveLanguage);
				// MainMenu2 restart 
				if (UI1->GetDrawUIBlocks()[0]->GetName() == "MainMenu1")
					MainMenu2Restart = true;
				// Delete setting file 
				remove("Data\\Settings\\Custom.xml");
				// Update window 
				GetWindowPosition(SaveY, SaveX);
				Render.close();
				CreateNewRender();
			}
			else
			if (Event == "Back")
			{
				UIEvent('@', DrawUIBlocks[Num]->GetBackName(), false, Num, Closed);
			}
			else
			if (Event == "Progress")
			{
				if (UI1->Message == 0)
					Control_Progress();
				else
					NeedResources = ";T_Message";
			}
			else
			//
			if (CutBackNum(Event) == "TradeUnit")
				UI_InventoryUnitUpdate( CharToInt(GetBackEventNumber(Event)), Num );
			else
			//
			if (Event == "SettlementPlunder")
			{
				Settlement Settlement1;
				for (size_t i = 0; i < Game1->Castes.size(); i++)
				for (size_t j = 0; j < Game1->Castes[i]->Settlements.size(); j++)
				{
					Settlement1 = Game1->Castes[i]->Settlements[j];
					if (Game1->Player1->X/32 == Settlement1.X/32 && Game1->Player1->Y/32 == Settlement1.Y/32)
					{
						DeleteSettlement(i, j);

						i = Game1->Castes.size();
						SetNewPreview(Game1->Player1->Team, -1, size_t(Game1->Player1->Y/32), size_t(Game1->Player1->X/32) );
						break;
					}
				}
			}
			else
			/*
			if (Event == "Statistics")
			{
				bool Create = true;
				size_t Buffer = 0;
				for (size_t i = UI1->GetDrawUIBlocks().size() - 1; i > 0; i--)
				{
					if (UI1->GetDrawUIBlocks()[i]->GetName() == "Statistics")
					{
						Buffer = i;
						Create = false;
					}
				}
				if (Create == false)
					UIEvent('!', "Close", false, Buffer, Closed);
				else
				{
					UIEvent('$', "Statistics", false, Num, Closed);
					// Hide player caste ->> plus and minus buttons 
					UI_HideImageButton("Statistics", "StatisticsPlusButton"+to_string(Game1->Player1->Team+1));
					UI_HideImageButton("Statistics", "StatisticsMinusButton"+to_string(Game1->Player1->Team+1));
					for (size_t i = Game1->Castes.size(); i < 7; i++)
					{
						UI_HideImageButton("Statistics", "StatisticsPlusButton"+to_string(i+1));
						UI_HideImageButton("Statistics", "StatisticsMinusButton"+to_string(i+1));
					}
				}
			}
			else
			*/
			//
			if (Event == "NextMusic")
			{
				Audio1->NextMusic();
			}
			else
			if (Event == "BackMusic")
			{
				Audio1->BackMusic();
			}
			else
			if (Event == "NoEntryMapDrawing")
			{
				Control_M(false);
			}
			else
			if (Event == "BuildMode")
			{
				Control_Tilde(false);
			}
			else
			if (Event == "PlayerDrawing")
			{
				if (Game1->Player1->Drawing)
					Game1->Player1->Drawing = false;
				else
					Game1->Player1->Drawing = true;
			}
			else
			if (Event == "EnemyDrawing")
			{
				Control_O(false);
			}
			else
			if (Event == "PlayerDirectionDrawing")
			{
				if (Game1->Player1->DirectionDrawing)
					Game1->Player1->DirectionDrawing = false;
				else
					Game1->Player1->DirectionDrawing = true;
			}
			else
			if (Event == "SettlementsDrawing")
			{
				if (Game1->CastesDrawing)
				{
					Game1->CastesDrawing = false;
					//UpdateLandMapSettlements(false);
				}
				else
				{
					Game1->CastesDrawing = true;
					//UpdateLandMapSettlements(true);
				}
			}
			else
			if (Event == "GridMapDrawing")
			{
				if (GridMap1->Drawing)
					GridMap1->Drawing = false;
				else
					GridMap1->Drawing = true;
			}
			else
			if (Event == "DomainMapDrawing")
			{
				if (DomainMap1->Drawing)
					DomainMap1->Drawing = false;
				else
					DomainMap1->Drawing = true;
			}
			else
			if (Event == "PreviewMapDrawing")
			{
				/*
				if (Game1->Castes[Game1->Player1->Team]->PreviewMap1->Drawing)
					Game1->Castes[Game1->Player1->Team]->PreviewMap1->Drawing = false;
				else
					Game1->Castes[Game1->Player1->Team]->PreviewMap1->Drawing = true;
				*/
			}
			else
			//
			if (CutBackNum(Event) == "TeamDiplomacyButton")
			{
				UIEvent('@', "GameLog", false, Num, false);
				UI_LogDiplomacyBigUpdate( CharToInt(GetBackEventNumber(Event)) );
				ShowAllElements(Num);
			}
			else
			//
			if (CutBackNum(Event) == "TeamPlusButton")
			{
				if (UI1->Message == 0)
					SetNewCasteAttitude(CharToInt(GetBackEventNumber(Event)), '+', 5);
				else
					NeedResources = ";T_ActiveMessage";
			}
			else
			if (CutBackNum(Event) == "TeamMinusButton")
			{
				if (UI1->Message == 0)
					SetNewCasteAttitude(CharToInt(GetBackEventNumber(Event)), '-', 5);
				else
					NeedResources = ";T_ActiveMessage";
			}
			else
			//
			if (CutBackNum(Event) == "StatisticPlus")
			{
				if (UI1->Message == 0)
					SetNewCasteAttitude(CharToInt(GetBackEventNumber(Event))-1, '+', 5);
				else
					NeedResources = ";T_ActiveMessage";
			}
			else
			if (CutBackNum(Event) == "StatisticMinus")
			{
				if (UI1->Message == 0)
					SetNewCasteAttitude(CharToInt(GetBackEventNumber(Event))-1, '-', 5);
				else
					NeedResources = ";T_ActiveMessage";
			}
			else
			//
			if (Event == "ForestCut")
			{
				if (MapPointer1->GetX() == Game1->Player1->X && MapPointer1->GetY() == Game1->Player1->Y)
				{
				bool cut = false;
				MapBlock& MapBlock1 = LandMap1->BlocksVector[Game1->Player1->Y/32][Game1->Player1->X/32];
				if (MapBlock1.Wood > 0 && MapBlock1.Forest)
				{
					if (Game1->Castes[Game1->Player1->Team]->PreviewMovePoints-1 >= 0)
					{
						Game1->Castes[Game1->Player1->Team]->PreviewMovePoints--;

						MapBlock1.Wood--;
						Game1->Castes[Game1->Player1->Team]->PreviewWood++;

						cut = true;
					}
					else
						NeedResources = "1M";
				}
				if (cut == true)
				{
					// For block delete 
					if (MapBlock1.Wood == 0)
					{
						MapBlock1.Forest = false;
						MapBlock1.RectAddY = 0;
						MapBlock1.Update();
						// Left block
						UI_LeftBlockUpdate("");
					// play sound
						size_t Random = GetRandomNumber(0, 1);
						if (Random == 0)
							Audio1->PlaySound1("ForestCutEnd0");
						else
						if (Random == 1)
							Audio1->PlaySound1("ForestCutEnd1");
						//
						LandMap1->ForestSize--;
						if (LandMap1->ForestSize == 0)
							SteamAPI1->SetAchievement("Lumberjack");
					}
					else
					{
						size_t Random = GetRandomNumber(0, 2);
						if (Random == 0)
							Audio1->PlaySound1("ForestCut0");
						else
						if (Random == 1)
							Audio1->PlaySound1("ForestCut1");
						else
						if (Random == 2)
							Audio1->PlaySound1("ForestCut2");
					}
				}
				}
				//
			}
			else
			//
			if (Event == "BarnBuild")
			{
				Control_Numbers(1);
			}
			else
			if (Event == "SawmillBuild")
			{
				Control_Numbers(2);
			}
			else
			if (Event == "SuburbBuild")
			{
				Control_Numbers(3);
			}
			else
			if (Event == "FieldBuild")
			{
				Control_Numbers(4);
			}
			else
			if (Event == "PastureBuild")
			{
				Control_Numbers(5);
			}
			else
			if (Event == "FisheriesBuild")
			{
				Control_Numbers(6);
			}
			else
			if (Event == "WallBuild")
			{
				Control_Numbers(7);
			}
			else
			if (Event == "TowerBuild")
			{
				Control_Numbers(8);
			}
			else
			if (Event == "CastleBuild")
			{
				Control_Numbers(9);
			}
			else
			if (Event == "DomainBuild")
			{
				if (Game1->Castes[Game1->Player1->Team]->PreviewMovePoints <= 1)
				{
					NeedResources = "1M";
				}
				else
					Control_Ctrl(false);
			}
			else
			if (Event == "PlunderBuild")
			{
				Control_Numbers(0);
			}
			else
			//
			if (Event == "BuyUnit" || Event == "SellUnit")
			{
				if (Event == "BuyUnit")
					UI_BuyUnit();
				else
					UI_SellUnit();
				//
			}
			if (Event == "GameLogDiplomacy")
			{
				UIEvent('@', Event, false, Num, Closed);
				UI_LogDiplomacyUpdate();
				UI1->SpecTextUpdate = true;
			}
			else
			if (Event == "GameSettlementMarket")
			{
				UIEvent('$', Event, false, Num, Closed);
				UI_InventoryUpdate();
				UI_InventoryUnitUpdate(0, UI1->GetDrawUIBlocks().size()-1);
				UI1->SpecTextUpdate = true;
			}
			else
			if (Event == "GameSettlementTavern")
			{
				UIEvent('$', Event, false, Num, Closed);
				UI_InventoryUpdate();
				UI_InventoryUnitUpdate(0, UI1->GetDrawUIBlocks().size()-1);
				UI1->SpecTextUpdate = true;
			}
			else
			if (AttackEvent(Event))
			{
				/*
				// Cut
				string Buffer = "";
				for (size_t i = 0; i < Event.length(); i++)
				{
					if (Buffer == "EnemyAttack")
					{
						Buffer = "";
					}
					Buffer += Event[i];
				}
				
				vector<size_t> Buffer2;
				string Buffer22;
				for (size_t i = 0; i < Buffer.length(); i++)
				{
					if (Buffer[i] == '_' || i+1 == Buffer.length())
					{
						if (i+1 == Buffer.length())
							Buffer22 += Buffer[i];
						
						//cout << "Buffer22: " << Buffer22 << endl;
						Buffer2.push_back(atoi(Buffer22.c_str()));
						Buffer22 = "";
					}
					else
						Buffer22 += Buffer[i];
				}

				// Player move 
				int XX = int(Buffer2[1]-Game1->Player1->X);
				int YY = int(Buffer2[2]-Game1->Player1->Y);
				
				if (XX != 0 && YY != 0)
				{
					if (XX < 0 && YY < 0)
						Control_QEZC('Q', true);
					else
					if (XX > 0 && YY < 0)
						Control_QEZC('E', true);
					else
					if (XX < 0 && YY > 0)
						Control_QEZC('Z', true);
					else
					if (XX > 0 && YY > 0)
						Control_QEZC('C', true);
				}
				else
				{
					if (XX == 0 && YY < 0)
						Control_WAXD('W', true);
					else
					if (XX < 0 && YY == 0)
						Control_WAXD('A', true);
					else
					if (XX == 0 && YY > 0)
						Control_WAXD('X', true);
					if (XX > 0 && YY == 0)
						Control_WAXD('D', true);
				}

				// Strategy 
				if (Game1->Castes[Buffer2[0]]->Army == Game1->Castes[Game1->Player1->Team]->Army)
				{
					if (GetRandomNumber(0, 1))
					{
						EnemyUnitDie(Buffer2[0]);
					}
					else
					{
						PlayerUnitDie();
					}
				}
				else
				if (Game1->Castes[Buffer2[0]]->Army < Game1->Castes[Game1->Player1->Team]->Army)
				{
					EnemyUnitDie(Buffer2[0]);
				}
				else
				{
					PlayerUnitDie();
				}

				UI1->SpecTextUpdate = true;
				*/
			}
			else
			if (CutBackNum(Event) == "NewWar")
			{
				size_t Enemy = CharToInt(GetBackEventNumber(Event));
				//cout << "Player team: " << Game1->Player1->Team << ", Enemy: " << Enemy << endl;
				Game1->Castes[Game1->Player1->Team]->Attitude[Enemy] = 15;
				Game1->Castes[Game1->Player1->Team]->Status[Enemy] = 0;
				Game1->Castes[Enemy]->Attitude[Game1->Player1->Team] = 15;
				Game1->Castes[Enemy]->Status[Game1->Player1->Team] = 0;

				// Update spec text 
				UI1->SpecTextUpdate = true;
			}
			else
			if (Event == "GameLogNew")
			{
				if (UI1->Message == 0)
				{
					UIEvent('$', "GameLog", false, Num, false);
					UI_LogDiplomacyBigUpdate( Game1->Player1->Team);
				}
				else
					NeedResources = ";T_Message";
			}
			else
			if (Event == "GameLog")
			{
				UIEvent('@', "GameLog", false, Num, false);
				UI_LogDiplomacyBigUpdate(Game1->Player1->Team);
			}
			else
			if (Event == "PlayGuide")
			{
				string SaveCurrentMapName = CurrentMapName;
				size_t SaveCurrentMapTeams = CurrentMapTeams;
				NewGameTeam = 0;
				NewGameFlag = 0;
				NewGameNation = 0;

				for (size_t i = 0; i < Maps.size(); i++)
				if (Maps[i].Name == "Guide")
				{
					CurrentMapName = Maps[i].Name;
					break;
				}
				//
				CurrentMapTeams = 2;
				UI_GenerateNewGamePlayers();

				UIEvent('!', "CreateNewGame", false, Num, false);
				CurrentMapName = SaveCurrentMapName;
				CurrentMapTeams = SaveCurrentMapTeams;
			}
			else
			// Technology 
			if (CutBackNum(Event) == "GameLogTechnology")
			{
				UIEvent('@', Event, false, Num, false);
				UI_UpdateTechnologyBack();
			}
			else
			// Technology learned 
			if (CutBackNum(Event) == "TechnologyLearn")
			{
				string Buffer = "";
				for (size_t i = 0; i < Event.length(); i++)
					if (ThisInt(Event[i]))
					{
						Buffer += Event[i];
					}
				size_t TechnologyNum = atoi(Buffer.c_str());
				size_t TechnologyCost = Game1->Castes[Game1->Player1->Team]->Technologys[TechnologyNum].Cost;
				//
				if (Game1->Castes[Game1->Player1->Team]->PreviewTechnologyPoints >= TechnologyCost)
				{
					Game1->Castes[Game1->Player1->Team]->Technologys[TechnologyNum].Opened = true;
					Game1->Castes[Game1->Player1->Team]->PreviewTechnologyPoints -= TechnologyCost;

					UI_UpdateTechnologyBack();
				}
				else
					NeedResources = to_string(TechnologyCost)+"T";
			}
			// Settlement army + and - 
			else
			if (CutBackNum(Event) == "SettlementArmyPlus")
			{
				size_t Value = CharToInt(GetBackEventNumber(Event));
				for (size_t i = 0; i < Game1->Castes[Game1->Player1->Team]->Settlements.size(); i++)
				if (Game1->Castes[Game1->Player1->Team]->Settlements[i].X == Game1->Player1->X && Game1->Castes[Game1->Player1->Team]->Settlements[i].Y == Game1->Player1->Y)
				{
					if (Game1->Castes[Game1->Player1->Team]->Settlements[i].GetType() == SettlementTypes::Settlement)
					{
						if (Game1->Castes[Game1->Player1->Team]->Settlements[i].Army+Value <= Game1->Castes[Game1->Player1->Team]->SettlementArmyLimit)
						{
							Game1->Castes[Game1->Player1->Team]->Settlements[i].Army += Value;
							
							Game1->Castes[Game1->Player1->Team]->PreviewArmy -= Value;
							Game1->Castes[Game1->Player1->Team]->Army -= Value;
							UI1->SpecTextUpdate = true;
							break;
						}
					}
					else
					if (Game1->Castes[Game1->Player1->Team]->Settlements[i].GetType() == SettlementTypes::Castle)
					{
						if (Game1->Castes[Game1->Player1->Team]->Settlements[i].Army+Value <= Game1->Castes[Game1->Player1->Team]->CastleArmyLimit)
						{
							Game1->Castes[Game1->Player1->Team]->Settlements[i].Army += Value;

							Game1->Castes[Game1->Player1->Team]->PreviewArmy -= Value;
							Game1->Castes[Game1->Player1->Team]->Army -= Value;
							UI1->SpecTextUpdate = true;
							break;
						}
					}
				}
			}
			else
			if (CutBackNum(Event) == "SettlementArmyMinus")
			{
				size_t Value = CharToInt(GetBackEventNumber(Event));
				for (size_t i = 0; i < Game1->Castes[Game1->Player1->Team]->Settlements.size(); i++)
				if (Game1->Castes[Game1->Player1->Team]->Settlements[i].X == Game1->Player1->X && Game1->Castes[Game1->Player1->Team]->Settlements[i].Y == Game1->Player1->Y)
				{
					if (Game1->Castes[Game1->Player1->Team]->Settlements[i].GetType() == SettlementTypes::Settlement)
					{
						if (Game1->Castes[Game1->Player1->Team]->Settlements[i].Army-Value >= 0 && Game1->Castes[Game1->Player1->Team]->Settlements[i].Army-Value <= Game1->Castes[Game1->Player1->Team]->SettlementArmyLimit)
						{
							Game1->Castes[Game1->Player1->Team]->Settlements[i].Army -= Value;

							Game1->Castes[Game1->Player1->Team]->PreviewArmy += Value;
							Game1->Castes[Game1->Player1->Team]->Army += Value;
							UI1->SpecTextUpdate = true;
							break;
						}
					}
					else
					if (Game1->Castes[Game1->Player1->Team]->Settlements[i].GetType() == SettlementTypes::Castle)
					{
						if (Game1->Castes[Game1->Player1->Team]->Settlements[i].Army-Value >= 0 && Game1->Castes[Game1->Player1->Team]->Settlements[i].Army-Value <= Game1->Castes[Game1->Player1->Team]->CastleArmyLimit)
						{
							Game1->Castes[Game1->Player1->Team]->Settlements[i].Army -= Value;

							Game1->Castes[Game1->Player1->Team]->PreviewArmy += Value;
							Game1->Castes[Game1->Player1->Team]->Army += Value;
							UI1->SpecTextUpdate = true;
							break;
						}
					}
				}
			}
			// 
			else
			if (Event == "AddPlayer")
				AddNewGamePlayer();
			else
			if (Event == "KickPlayer")
				KickNewGamePlayer();
			//
			else
			if (Event == "Tab")
				Contol_Tab(false);
			else
			if (Event == "Shift")
				Contol_Shift(false);
			//
			else
			if (Event == "Zoom_Plus")
				Contol_Zoom('+');
			else
			if (Event == "Zoom_Minus")
				Contol_Zoom('-');
			//
			else
			if (CutBackNum(Event) == "ColorMinus")
			{
				size_t rgb = 0;
				for (size_t i = 0; i < Event.length(); i++)
				if (ThisInt(Event[i]))
				{
					rgb = CharToInt(Event[i]);
					break;
				}
				//
				size_t Team = CharToInt(GetBackEventNumber(Event));
				NewGamePlayers[Team].NewColor(rgb, '-');
				UpdateNewGamePlayer();
				//
				if (Team == 0)
					UI_NewGameFlag(' ');
			}
			else
			if (CutBackNum(Event) == "ColorPlus")
			{
				//
				size_t rgb = 0;
				for (size_t i = 0; i < Event.length(); i++)
				if (ThisInt(Event[i]))
				{
					rgb = CharToInt(Event[i]);
					break;
				}
				//
				size_t Team = CharToInt(GetBackEventNumber(Event));
				NewGamePlayers[Team].NewColor(rgb, '+');
				UpdateNewGamePlayer();
				//
				if (Team == 0)
					UI_NewGameFlag(' ');
			}
			//
			else
			if (Event == "NewGameRandomColor")
			{
				UI_GenerateNewGamePlayersColor();
				UpdateNewGamePlayer();

				UI_NewGameFlag(' ');
			}
			else
			if (Event == "NewGameRandomPosition")
			{
				vector<size_t> no;
				size_t Gen;
				for (size_t i = 0; i < CurrentMapTeams; i++)
				{
					while (true)
					{
						Gen = GetRandomNumber(0, CurrentMapTeams-1) + 1;
						bool end = true;
						for (size_t j = 0; j < no.size(); j++)
						{
							if (no[j] == Gen)
								end = false;
						}
						//
						if (end)
						{
							NewGamePlayers[i].StartPosition = Gen;
							no.push_back(Gen);
							break;
						}
					}
				}
				//
			}
			//
		}
		// More 
		else
		{
			// @ and $ 
			bool EventSucces = false;
			for (size_t i = 0; i < BlockNames.size(); i++)
				if (BlockNames[i] == Event)
				{
					EventSucces = true;
					break;
				}

			if (EventSucces)
			{
				//cout << " : Succes " << endl;
				if (Type == '|')
				{
					// Minimize left block 
					UIEvent('@', Event, Message, Num, Closed);

					if (LeftBlockMinimize == true)
						LeftBlockMinimize = false;
					else
						LeftBlockMinimize = true;

					UI_UpdateMapPointer(false);
				}
				else
				if (Type == '@')
				{
					// 
					for (size_t i = 0; i < UIBlocks.size(); i++)
					{
						if (UIBlocks[i]->GetName() == Event)
						{
							size_t IPosition = DrawUIBlocks[Num]->GetIPosition();
							UIBlocks[i]->SetBackName( DrawUIBlocks[Num]->GetName() );
							DrawUIBlocks[Num] = UIBlocks[i];
							DrawUIBlocks[Num]->SetIPosition(IPosition);

							UI1->SetLayer(UIBlocks[i]->GetLayer());
							//
							DrawUIBlocks[Num]->FirstDraw = true;
							UI1->FocusedBlockName = Num;
							UI1->SpecTextUpdate = true;
							//
							UIComboBoxTextUpdate();
							//
							UIEventSound(Event);
							break;
						}
					}
					//
				}
				else
				if (Type == '$')
				{
					if (UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->GetName() == "MainMenu0" ||
						UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->GetName() == "MainMenu1")
					if (UI1->MainMenu == true && Message == false && Event != "Message")
						UIClearLayer(0);
					//
					for (size_t i = 0; i < UIBlocks.size(); i++)
					{
						if (UIBlocks[i]->GetName() == Event)
						{
							// one open fix 
							//cout << "- E - > " << UIBlocks[i]->GetName() << endl;
							bool Overlap = false;
							for (size_t j = 0; j < DrawUIBlocks.size(); j++)
							{
								//cout << "- - - > " << DrawUIBlocks[j]->GetName() << endl;
								if( DrawUIBlocks[j]->GetName() == UIBlocks[i]->GetName() )
									Overlap = true;
							}
							if (Overlap == true)
							{
								break;
							}
							//
							DrawUIBlocks.push_back( UIBlocks[i] );
							DrawUIBlocks[DrawUIBlocks.size()-1]->FirstDraw = false;
							DrawUIBlocks[DrawUIBlocks.size()-1]->SetLayer(UI1->GetLayer());
							UI1->UpdateIPosition( DrawUIBlocks.size()-1 );
							UI1->FocusedBlockName = DrawUIBlocks.size()-1;
							UI1->SpecTextUpdate = true;
							//
							UIComboBoxTextUpdate();
							//
							UIEventSound(Event);
							break;
						}
					}
					UI_SearchMessage();
					//
				}

				// Update inventory points 
				if (NewGame == true && UI1->MainMenu == false)
				if (LandMap1->BlocksVector[size_t(Game1->Player1->Y/32)][size_t(Game1->Player1->X/32)].Settlement)
				{
					UI_InventoryUpdate();
				}
			}
			//else
			//	return;
				//cout << " : Unsucces " << endl;
		}

		// Message 
		if (UI1->Message != 0)
			UI1->Message = 0;

		if (Closed == true)
		{
			UIEvent('!', "MessageClose", false, UI1->GetDrawUIBlocks().size()-1, false);
			InputMode = true;
		}
	}
}