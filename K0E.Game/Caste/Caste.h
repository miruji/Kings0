#pragma once
#include "../Macro.h"
#include "Settlement.h"
#include "Unit.h"
#include "../Technology/Technology.h"
#include "../K0E.Map/Maps/MapBlock/MapBlock.h"
#include "../K0E.Map/Maps/PreviewMap/PreviewMap.h"
#include "../K0E.Map/Maps/NoEntryMap/NoEntryMap.h"

// Class caste
struct K0E_Game_Api Caste
{
	string Name = "No name";
	string Color = "255;255;255;210";

	// Map: Preview map 
	//PreviewMap* PreviewMap1;
	//PreviewMap* PreviewMap1General;

	// Regenerate No entry map
	void RegenerateNoEntryMap(NoEntryMap* NoEntryMap1);

	// Type and nation 
	CasteNation Nation;
	size_t NationToInt();

	// Bonus 
	size_t FieldBonus = 0;
	size_t FisheriesBonus = 0;
	size_t PastureBonus = 0;
	size_t SuburbBonus = 0;
	size_t PopulationBonus = 0;
	size_t SawmillBonus = 0;

	// Rune 
	size_t Rune = 0;

	// Team
	size_t Team = 0;

	// Building limit
	size_t BuildingLimit = 15;

	size_t ResourcesLimit = 3000;

	// Cash
	int Cash = 250; // !> 999999 (please not ;) 
	int PreviewCash = 0;

	// Food 
	int Food = 10;
	int PreviewFood = 0;

	// Wood 
	int Wood = 0;
	int PreviewWood = 0;

	// Population 
	int Population = 20;
	int PreviewPopulation = 0;

	// Population 
	int Army = 0;
	int PreviewArmy = 0;
	int SettlementArmyLimit = 15;
	int CastleArmyLimit = 25;

	// Technology points 
	int TechnologyPoints = 250;
	int PreviewTechnologyPoints = 0;

	// Diplo points 
	int DiploPoints = 5;
	int PreviewDiploPoints = 0;

	// Move points 
	int MovePoints = 0;
	int PreviewMovePoints = 0;

	// Attitude 
	vector< size_t > Attitude;
		// A < 25 -> enemy 
	    // A +- 25 -> normal 
	    // A > 25 -> friend 
	// Status 
	vector< int > Status;
		// 0 = at war 
		// 1 = piece 
		// 2 = allied 
		// 3 = relatives 

	// Settlemnts
	vector< Settlement > Settlements;

	// Units 
	vector< Unit* > Units;

	// Squad 
	Squad* Squad1;

	// Technology 
	void ClearTechnologys();
	vector< Technology > Technologys;
	size_t InitTechnology = 13; // +1(0)
	// 0 - 3
	// forest / mountain / water / river 
	// 4 - 7
	// + 1 movement point 
	// 8 - 12
	// Building limit

	void UpdateNation(size_t BNation);

	// Constructor
	Caste(size_t Team, size_t TeamSize, vector< Settlement > XMLSettlements, vector<Character*>& Characters);

	// Drawing 
	bool Drawing = true;

	// Progress 
	void Progress(LandMap* LandMap1, DomainMap* DomainMap1, NoEntryMap* NoEntryMap1, /*vector<PreviewMap*>& PreviewMaps,*/ size_t PlayerTeam, size_t GameTeams, size_t& TeamAttitude);
	void PreviewProgress(LandMap* LandMap1);

	// Draw units 
	void DrawUnits(sf::RenderWindow& Render, float& CameraX, float& CameraY, float& CameraW, float& CameraH, std::vector< std::vector<MapBlock> >& BlocksVector, bool& DrawingWarFog, bool& NamesDrawing);
	// Draw first settlements
	void DrawFirstSettlements(sf::RenderWindow& Render, float& CameraX, float& CameraY, float& CameraW, float& CameraH, std::vector< std::vector<MapBlock> >& BlocksVector, bool& DrawingWarFog, bool& NamesDrawing, size_t PlayerTeam);
	// Draw second settlements
	void DrawSecondSettlements(sf::RenderWindow& Render, float& CameraX, float& CameraY, float& CameraW, float& CameraH, std::vector< std::vector<MapBlock> >& BlocksVector, bool& DrawingWarFog, bool& NamesDrawing, size_t PlayerTeam);
};