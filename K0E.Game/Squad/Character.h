#pragma once
#include "../Macro.h"
#include "../Item/Item.h"

// UnitClass 
enum class K0E_Game_Api CharacterType
{
	// Basic 
	None,
	Leader,
	// More 
	Warrior
};

// Class Squad
class K0E_Game_Api Character
{
private:
	// Name 
	string Name = "";

	// UnitClass 
	CharacterType Class = CharacterType::None;

	// Size_t 
	size_t Grade = 0;

	// Attitude of first Unit  
	// Max = 100 or Min = 0 
	size_t Attitude = 50;

	// Items (string's = id's)
	// 1 item = 1 AI1 item (copy)
	vector< Item* > Items;
	size_t ItemsCount = 0; // For UI sizebar  

	// UI image & sprite 
	sf::Texture Texture;
	sf::Sprite Sprite;

	sf::IntRect Rect;

public:
	// Constructor 
	Character(string Name, string Class, size_t Grade, string Source);

	// Get Name (link) 
	string& GetName();

	// Get UnitClass (link) 
	CharacterType& GetType();

	// Get Grade (link) 
	size_t& GetGrade();

	// Get Sprite (link) 
	sf::Sprite& GetSprite();

	// Get Attitude (for first Unit) (link) 
	size_t& GetAttitude();

	// Add new item 
	void AddItem(string Name, vector< Item* >& AIItems);

	// Replace new item 
	void ReplaceItem(Item* Item);

	// Get items (link) 
	vector< Item* > GetItems();

	// Get item (obj) 
	Item* GetItem(size_t Count);

	// Get Items Count (link) 
	size_t& GetItemsCount();

	// Draw 
	void Draw(sf::RenderWindow& Render);
};