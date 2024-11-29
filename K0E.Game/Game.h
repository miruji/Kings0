#pragma once
#include "Macro.h"

#include "Event/Event.h"
#include "Event/RandomEvent.h"
#include "Caste/Caste.h"
#include "Player/Player.h"

class K0E_Game_Api Game {
private:
	// Parse 
	XMLParser* XMLParser1; // XML parser
	TiXmlElement* Data;    // Data element 
	TiXmlElement* Element; // "Item name".xml

	void ParseItems(TiXmlElement* MainBlock, Console* Console1);
	void ParseEvents(TiXmlElement* MainBlock, Console* Console1);
	void ParseCharacters(TiXmlElement* MainBlock, Console* Console1);

public:
	// Progress
	size_t Progress = 0;

	// Game started ? 
	bool GameStarted = false;

	// Items 
	vector< Item* > Items;

	// Events 
	vector < Event* > Events;

	// Units  
	vector< Character* > Characters;

	// Castes
	vector< Caste* > Castes;
	bool CastesDrawing = true;
	bool UnitsDrawing = true;
	bool NamesDrawing = true; // Debug mode 

	// Player
	Player* Player1;

	// Constructor
	Game(vector<int> NewGamePlayers);
	vector<int> NewGamePlayers;
	vector<XMLCaste*> XMLCastes;

	// Creae game 
	void CreateGame(string CurrentMapName, string Name, size_t Team, size_t Nation, size_t NewGameFlag, Console* Console1);

	// Get game castes 
	vector< Caste* > GetGameCastes(string CurrentMapName, Console* Console1);
};
