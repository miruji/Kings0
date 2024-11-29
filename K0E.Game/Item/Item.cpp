#include "Item.h"

// Constructor 
Item::Item(string Name, string Type, size_t Cash)
{
	// ... 
	this->Name = Name;
	this->Cash = Cash*Size;

	if (Type == "Food")
	{
		this->Type = ItemType::Food;
		Size = 5;
		this->Cash = this->Cash*2;
	}
	else
	if (Type == "Wood")
	{
		this->Type = ItemType::Wood;
		Size = 5;
		this->Cash = this->Cash*4;
	}
	else
	if (Type == "Army")
	{
		this->Type = ItemType::Army;
		Size = 5;
		this->Cash = this->Cash*2;
	}
	else
		this->Type = ItemType::None;

	// Set texture to sprite ... 
	if (this->Type == ItemType::None)
		Texture.loadFromFile("Data\\Textures\\Game\\Items\\"+Name+".png");
	else
		Texture.loadFromFile("Data\\Textures\\Game\\Items\\"+Type+"\\"+Name+".png");

	Sprite.setTexture(Texture);
	Rect = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(64, 64));
	Sprite.setTextureRect(Rect);
}

// Get size (link) 
size_t& Item::GetSize()
{
	// ... 
	return Size;
}

// Get name (link) 
string& Item::GetName()
{
	// ... 
	return Name;
}

// Get sprite (link)
sf::Sprite& Item::GetSprite()
{
	// ... 
	return Sprite;
}

// Get type (link) 
ItemType& Item::GetType()
{
	// ... 
	return Type;
}

// Get cash (link) 
size_t& Item::GetCash()
{
	// ... 
	return Cash;
}

// Draw 
void Item::Draw(sf::RenderWindow& Render)
{
	// ... 
	Render.draw(Sprite);
}