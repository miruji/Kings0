#pragma once
#include "../Macro.h"
#include "../Func/GetRandomNumber.h"

// ItemType 
enum class K0E_Game_Api ItemType
{
	None, 
	Food,
	Wood,
	Army
};

// Class Player
class K0E_Game_Api Item
{
private:
	// Texture & Image 
	sf::Texture Texture;
	sf::Sprite Sprite;

	sf::IntRect Rect;

	// Name 
	string Name = "";

	// Type 
	ItemType Type = ItemType::None;

	// Cash 
	size_t Cash = 0;

	// Size 
	size_t Size = 5;

public:
	// Constructor 
	Item(string Name, string Type, size_t Cash);

	// Get size (link) 
	size_t& GetSize();

	// Get name (link) 
	string& GetName();

	// Get sprite (link)
	sf::Sprite& GetSprite();

	// Get type (link) 
	ItemType& GetType();

	// Get cash (link) 
	size_t& GetCash();

	// Draw 
	void Draw(sf::RenderWindow& Render);
};