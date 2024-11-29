#pragma once
#include "../K0E.Game/Game.h"
#include "Func/SearchChar.h"
#include "Macro.h"
#include "UI/UI.h"
#include "Mouse/Mouse.h"
#include "Cursor/Cursor.h"
#include "Camera/Camera.h"
#include "../K0E.Map/Map.h"
#include "../K0E.Map/Maps/LandMap/LandMap.h"
#include "../K0E.Map/Maps/LandMap/ForestMap.h"
#include "../K0E.Map/Maps/LandMap/MountainMap.h"
#include "../K0E.Map/Maps/WarFog/WarFog.h"
#include "../K0E.Map/Maps/GridMap/GridMap.h"
#include "../K0E.Map/Maps/DomainMap/DomainMap.h"
#include "../K0E.Map/Maps/PreviewMap/PreviewMap.h"
#include "../K0E.Map/Maps/RoadMap/RoadMap.h"
#include "../K0E.Map/Maps/NoEntryMap/NoEntryMap.h"
#include "../K0E.File/File.h"
#include "../K0E.Language/LanguagePack.h"
#include "MapPointer/MapPointer.h"
#include "Func/StringToWString.h"
#include "Func/NumToKeyCode.h"
#include "Func/CharToInt.h"
#include "Func/DevideOutCharacter.h"
#include "Func/ThisInt.h"
#include "Func/CutBackNum.h"
#include "Func/GetBackEventNumber.h"
#include "../K0E.Audio/Audio.h"
#include "../K0E.SteamAPI/SteamAPI.h"
#include "../K0E.Network/Network.h"
#include "NewGameCaste/NewGameCaste.h"
#include "Func/ColorGenerate.h"
#include "Func/StringToColor.h"

// Class 
class K0E_Window_Api Window
{
private:
	//
	int SaveSoundtrack = 0, SaveSoundEffects = 0;

	string Version = "000000";
	string Title = "Kings0";

	size_t Width, Height;
	size_t NewWidth, NewHeight;

	size_t FramerateLimit = 0;
	size_t SaveFramerateLimit = 0;

	bool VerticalSync = false;

	size_t WindowMode = 0;
	size_t SaveWindowMode = 0;

	int LeftMargin = 0, TopMargin = 0;
	int SaveX, SaveY;

	string SaveLanguage = "Eng";

	bool MainMenu2Restart = false;

	// Time, Clock, FPS 
	//sf::Time Time1;              // Main stream Time
	sf::Clock Clock1;              // Main straem Clock 
	size_t FPS = 0;                // FPS 
	float LastTime;

	// Rendering 
	bool Rendering   = true;       // Rendering ? 
	// Window (Render) and event 
	sf::RenderWindow Render;       // Main stream Render 
	vector< sf::VideoMode > VideoModes;
	ImGuiIO* IO;                   // Main stream IO 
	ImGuiStyle* Style;             // Main stream Style 
	sf::Event Event;               // Main stream Event 
	void CreateNewRender();                       // Create new render 
	void GetWindowPosition(int& x, int& y);       // Get window position 
	void SaveSettings();                          // Save settings 
	void SetWindowFocus();

	// UI 
	UI* UI1;                       // Window: Interface 
	bool UIDrawingSave = true;
	void UIDraw();                                                          // UI: draw
	void UIClearDrawBlocks(bool ClearAll);                                  // UI: clear DrawUIBlocks 
	void UIClearLayer(size_t Layer);
	void UIEvent(char Type, string Event, bool Message, size_t Num, bool Closed); // UI: event 
	void UIEventSound(string Event);
	void UISpec(UIText* Text1, size_t i);                                   // UI: Spec (for text) 
	void UICheckBoxEvent(string CheckEvent, size_t Value);                  // UI: CheckBox event 
	void UICheckBoxFirstDraw(UICheckBox* UICheckBox1);                      // UI: CheckBox First draw 
	void UIComboBoxEvent(string ComboEvent, UIComboBox* UIComboBox1);       // UI: ComboBox event 
	string UIComboBoxCurrentItem(string ComboEvent);                        // UI: ComboBox Current item 
	void UIComboBoxSettings(string ComboEvent, string NewValue, size_t n);  // UI: ComboBox Settings 
	void ShowAllElements(size_t Num);                                       // UI: Show all elements 
	void UIComboBoxTextUpdate();
	void UISlideIntUpdate(string Name);
	void UI_InventoryUnitUpdate(size_t UnitCount, size_t Num);              // UI: Set unit pointer position 
	void UI_InventoryUnitClearUpdate();                                     // UI: Clear unit pointer position 
	void UI_InventoryUpdate();                                              // UI: Inventory update 
	void UI_SetMainMenu();                                                  // UI: Set main menu 
	void UI_UpdateMapPointer(bool Attack);
	void UI_LeftBlockUpdate(string NextBlockName);                          // UI: Left block update 
	bool FirstMainMenuBack = false;                                         // To left block 
	bool LeftBlockMinimize = false;                                         // To left block mini 
	void UI_HideImageButton(string BlockName, string ImageId);              // UI: Hide image button 
	size_t UI_GetLeftBlockName();                                           // UI: Get left block name 
	bool BuildingNums = false;
	void UI_BuyUnit();                                                      // Buy unit 
	void UI_SellUnit();                                                     // Sell unit 
	void UI_LogDiplomacyUpdate();                                           // UI: Log diplomacy update 
	void UI_LogDiplomacyBigUpdate(size_t CasteNum);                         // UI: Log diplomacy big update 
	void UI_NewGameFlag(char Type);                                         // UI: New game flag 
	void UI_UpdateGameBasicFlag();                                          // UI: Update game basci flag 
	void UI_NewGameNation(char Type);                                       // UI: New game nation 
	void UI_UpdateComboBoxsCurrentItems(string Block);                      // Update combo boxs current items 
	void UI_LeftBlockHideButtons();
	void UI_UpdateNewGamePlayerIcon();
	void UI_UpdateNewGameMapImage();
	void UI_UpdateTechnologyButtons();
	void UI_UpdateTechnologyBack();
	void UI_LoadGamePointerUpdate(size_t UnitCount);
	void UI_LoadGameUpdate();
	size_t NewGameUnit = 0;
	size_t LoadGameUnit = 0;
	size_t SaveGameUnit = 0;
	void UI_SearchMessage();
	void UI_HideByImageId(string Id);
	void UI_UpdateNewGameItems();
	void UI_GenerateNewGamePlayers();
	void UI_GenerateNewGamePlayersColor();

	// Map pointer 
	MapPointer* MapPointer1;       // Window: Map pointer 

	// Mouse 
	Mouse* Mouse1;                 // Window: Mouse 

	// Cursor 
	Cursor* Cursor1;               // Window: cursor

	// Window camera 
	Camera* Camera1;               // Window: Camera
	float MapZoom = 0.6f;          // Camera: Zoom

	// Maps 
	LandMap* LandMap1;             // Map: Main stream 
	WarFog*  WarFog1;              // Map: War fog 
	GridMap* GridMap1;             // Map: Grid map 
	DomainMap* DomainMap1;         // Map: Domain map 
	RoadMap* RoadMap1;             // Map: Road map 
	NoEntryMap* NoEntryMap1;       // Map: No entry map 
	void CreateMaps(vector < vector<string> > Map, vector< Caste* > Castes);
	vector< vector<size_t> > CreateTeamMap(vector< vector<MapBlock> >& BlocksVector, vector< Caste* >& Castes);
	void RegenerateNoEntryMap();                // Regenerate No entry map 

	// Language Pack 
	LanguagePack* LanguagePack1;   // Language: All 
	LanguagePack* LoadLanguages(); // Load languages pack 

	// Game 
	Game* Game1;                                                           // Game: Main stream 
	bool NewGame = false;
	size_t NewGameTeam = 0, SaveNewGameTeam = 0;
	size_t NewGameFlag = 0, SaveNewGameFlag = 0;
	size_t NewGameNation = 0, SaveNewGameNation = 0;
	vector<NewGameCaste> NewGamePlayers;
	void AddNewGamePlayer();
	void UpdateNewGamePlayer();
	void KickNewGamePlayer();
	void Game_InSettlement(MapBlock& Block, bool Attack);
	void Game_PlayerWarFog();                                                      // Game: new player war fog 
	void CreateNewGame(bool LoadGame);                                    
	void CreateNewSettlement(sf::Keyboard::Key Key);                               // Game: Create new settlement 
	void DeleteSettlement(size_t Caste1, size_t Settlement1);                      // Game: Delete settlement 
	void UpdateLandMapSettlements(bool NewStatus);                                 // Game: Update land map settlements 
	void SetNewCasteAttitude(size_t Caste, char Type, int NewAttitude);            // Game: Set new caste attitude 
	void UpdateAttitudeStatus();
	string GetItemStatus(string Type, size_t i);                                   // Game: Get item status 
	string GetItemStatusResult(Settlement Settlement1, string Type, size_t Count, size_t i); // Game: Get item status result 
	void DeleteItem(string Type, size_t i);                                        // Game: Delete item 
	void TechnologyEvent(string Technology);                                       // Game: Technology event 
	void SaveGame();
	void LoadGame();
	void DeleteGame(size_t DeleteUnit);
	bool SearchNextBlockDomain(MapBlock NextBlock, size_t BasicTeam);              // Game: Search next block domain 
	bool SearchNextBlockEnemy(MapBlock NextBlock, size_t BasicTeam);               // Game: Search next block enemy 
	bool SearchBackYourDomain(MapBlock NextBlock, size_t BasicTeam);
	string NeedResources = "";
	string NeedResourcesStr();
	void CreateNewWindowCamera();
	void EnemyUnitDie(size_t EnemyTeam);
	void PlayerUnitDie();
	void SetNewPreview(size_t Team, int New, size_t i, size_t j);
	void SetNewDomain(size_t Team, size_t i, size_t j);
	void UpdateDomainPreview(int New, size_t Team, size_t ToTeam);
	void TradeItemsUpdate();

	vector<Map> LoadMaps();
	vector<Map> Maps;
	string CurrentMapName = "None";
	string CurrentMapSize = "0x0";
	size_t CurrentMapTeams = 1;

	// Audio 
	Audio* Audio1;                             // Audio: Main stream 
	bool FirstMusic = true;

	// Input 
	bool InputMode = true;
	void Input();                              // Control: [Main stream] 
	bool Control_Arrows();                     // Control: [Arrows] 
	bool Control_WAXD(char Direction, bool Attack);
	bool Control_QEZC(char Direction, bool Attack);
		// Numbers 
		bool Control_Numbers(size_t BuildingNum);          // Control: [Building numbers] 
		bool Control_SettlementNumbers();                  // Control: [Settlement numbers] 
		bool Control_MainMenuNumbers();                    // Control: [MainMenu numbers] 
		void Control_NumbersEvents(sf::Keyboard::Key Key); // Control: Numbers events 
		bool Control_Tilde(bool Keyboard);                 // Control: [Building nums] 
	void Control_Progress();		           // Control: [Enter or S] 
	bool Control_F();                          // Control: [War fog show / hide] 
	bool Control_G();                          // Control: [Grid show / hide] 
	bool Control_H();                          // Control: [Hud show / hide] 
	bool Control_B();                          // Control: [Castes show / hide] 
	bool Control_O(bool Keyboard);             // Control: [Enemy units show / hide]
	bool Control_R();                          // Control: [Roads show / hide] 
	bool Control_P();                          // Control: [Player show / hide] 
	bool Control_N();                          // Control: [Names show / hide] 
	bool Control_M(bool Keyboard);             // Control: [Marks show / hide] 
	bool Control_Ctrl(bool Keyboard);          // Control: [Domain] 
	bool Control_Esc();                        // Control: [Main menu] 
	bool Contol_Tab(bool Keyboard);
	bool Contol_Shift(bool Keyboard);
	bool Contol_Zoom(char Type);

	// Rendering func 
	void Draw();
	size_t SpecTextUpdateI = 0;

	// Console 
	Console* Console1;

	// Steam API
	SteamAPI* SteamAPI1;

	// Network 
	Network* Network1;
	void CreateServer();
	void ConnectToIpAndPort();

public:
	// Constructor 
	Window(string Version, string Language, string Title, size_t Width, size_t Height, size_t FramerateLimit, size_t WindowMode, bool VerticalSync, Console* Console2, SteamAPI* SteamAPI1, int Soundtrack, int SoundEffects);
};
