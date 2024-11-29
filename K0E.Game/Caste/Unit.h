#include "../Macro.h"
#include "../Squad/Squad.h"
#include "SettlementTypes.h"
#include "../K0E.Map/Maps/MapBlock/MapBlock.h"
#include "Settlement.h"
#include "../Technology/Technology.h"
#include "../Func/GetRandomNumber.h"
#include "../Func/StringToColor.h"
#include "../K0E.Map/Maps/DomainMap/DomainMap.h"
#include "../K0E.Map/Maps/PreviewMap/PreviewMap.h"

// Class Squad
class K0E_Game_Api Unit
{
private:
	// Texture & Sprite 
	sf::Texture BracketTexture;
	sf::Texture BasicTexture;
	sf::Texture ShadowTexture;
	sf::Texture TeamShadowTexture;
	sf::Sprite Sprite;

	// Sprite rect 
	sf::IntRect Rect;

	// Text 
	sf::Font Font;
	sf::Text Text;
	size_t FontSize = 10;

	// Game: Search next block enemy 
	bool SearchNextBlockEnemy(MapBlock NextBlock, DomainMap* DomainMap1, vector< int >& Status);

public:
	// Team 
	size_t Team = 1;
	int ArmyBuildLimit = 0;

	// X & Y
	float X = 0.0f, Y = 0.0f;

	float StartX = 0.0f, StartY = 0.0f;
	int RememberAddX = 0, RememberAddY = 0;

	// In settlement?
	SettlementTypes SettlementType = SettlementTypes::None;

	// Global name 
	string Name = "Unit";

	// Opened ? 
	bool Opened = true;

	// Constructor 
	Unit(string Name, vector<Character*>& Characters);

	// Update sprite 
	void UpdateSprite(sf::IntRect Rect);

	// Set position
	void SetPosition(float X, float Y);

	// New domain 
	void NewDomain(DomainMap* DomainMap1, /*vector<PreviewMap*>& PreviewMaps,*/ int& DiploPoints);
	bool SearchBackYourDomain(DomainMap* DomainMap1, MapBlock NextBlock);

	// Set X & Y
	void Move(float X, float Y, vector< vector<MapBlock> >& BlocksVector, vector< Settlement >& Settlements, DomainMap* DomainMap1, /*PreviewMap* PreviewMap1,*/ vector< Technology > Technologys, vector< int >& Status);

	// Progress 
	void Progress(LandMap* LandMap1, vector< Settlement >& Settlements, CasteNation Nation, DomainMap* DomainMap1, /*PreviewMap* PreviewMap1, vector<PreviewMap*>&PreviewMaps,*/ vector< Technology > Technologys, vector< int >& Status, int& MovePoints, int& Wood, int& DiploPoints, int& Population, int& Food, int& Army, int& Cash, size_t& ResourcesLimit);

	// Draw
	void Draw(sf::RenderWindow& Render, bool& NamesDrawing, string Color, size_t Army);
};