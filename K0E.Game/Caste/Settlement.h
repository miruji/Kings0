#pragma once
#include "../Macro.h"
#include "../Func/GetRandomNumber.h"
#include "../Func/StringToColor.h"
#include "../Item/Item.h"
#include "SettlementTypes.h"
#include "CasteTypes.h"

// Class settlemt
class K0E_Game_Api Settlement
{
private:
	// Items (string's = id's)
	// 1 item = 1 AI1 item (copy)
	vector< Item* > Items;
	size_t ItemsCount = 0; // For UI sizebar 

	// Type
	SettlementTypes Type;

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

public:
	// X & Y
	float X = 0.0f, Y = 0.0f;

	// Population
	size_t Army = 0;
	size_t ArmyLimit = 0;

	// Team
	size_t Team = 0;

	// Name
	string Name = "Noname";

	// Constructor
	Settlement(string Name, string Type, size_t Population, size_t Team, float X, float Y);
	Settlement();

	// Drawing ? 
	bool Drawing = true;

	// Opened ? 
	bool Opened = true;

	// Draw 
	void Draw(sf::RenderWindow& Render, float CameraX, float CameraY, float CameraW, float CameraH, bool NamesDrawing, string Color, size_t PlayerTeam, CasteNation CasteNation1);

	// Get Type (link)
	SettlementTypes& GetType();
	size_t GetTypeInt();

	// Add new item 
	void AddItem(string Name, vector<Item*>& AIItems);

	// Replace new item 
	void ReplaceItem(Item* Item);

	// Clear items
	void ClearItems();

	// Delete one item 
	void DeleteItem(size_t Cout);

	// Get items (link) 
	vector< Item* >& GetItems();

	// Get items market 
	vector< Item* > GetItemsMarket();

	// Get items tavern 
	vector< Item* > GetItemsTavern();

	// Get item (obj) 
	Item* GetItem(size_t Count);

	// Get item market (obj) 
	Item* GetItemMarket(size_t Count);

	// Get item tavern (obj) 
	Item* GetItemTavern(size_t Count);

	// Get Items Count (link) 
	size_t& GetItemsCount();
};