#pragma once
#include "../Macro.h"
#include "../Squad/Squad.h"
#include "../Caste/Settlement.h"
#include "../Technology/Technology.h"
#include "../K0E.Map/Maps/MapBlock/MapBlock.h"
#include "../Func/SearchChar.h"
#include "../Func/StringToColor.h"
#include "../K0E.Map/Maps/DomainMap/DomainMap.h"

// Class Player
class K0E_Game_Api Player
{
private:
	// Texture & Sprite 
	sf::Texture BracketTexture;
	sf::Texture BasicTexture;
	sf::Texture ShadowTexture;
	sf::Texture TeamShadowTexture;
	sf::Texture DirectionTexture;
	sf::Sprite Sprite;

	// Sprite rect 
	sf::IntRect Rect;

	// Text 
	sf::Font Font;
	sf::Text Text;
	size_t FontSize = 10;

	// Search next block domain 
	bool SearchNextBlockDomain(MapBlock NextBlock, size_t BasicTeam, DomainMap* DomainMap1, vector< int >& Status);

public:
	size_t Staying = 0;

	// Team 
	size_t Team = 0;

	bool Die = false;
	float StartX = 0.0f, StartY = 0.0f;

	// X & Y
	float X = 0.0f, Y = 0.0f;

	// In settlement?
	SettlementTypes SettlementType = SettlementTypes::None;
	string SettlementName = "";

	// Drawing ? 
	bool Drawing = true;

	// Direction drawing ? 
	bool DirectionDrawing = true;

	// Global name 
	string Name = "Player";

	// Constructor
	Player(string Name);

	// Update sprite 
	void UpdateRect(sf::IntRect Rect);

	// Set position
	void SetPosition(float X, float Y);

	// Set X & Y
	void Move(float X, float Y);

	// Draw direction 
	void DrawDirection(sf::RenderWindow& Render, vector< vector<MapBlock> >& BlocksVector, /*vector< vector< size_t > >& PreviewMap1, vector< vector< size_t > >& PreviewMap1General,*/ vector< vector<string> >& NoEntryVector, size_t& SaveNewGameNation, DomainMap* DomainMap1, vector< int >& Status, vector< Technology > Technologys, string Color);

	// Draw
	void Draw(sf::RenderWindow& Render, bool NamesDrawing, string Color, size_t Army);
};