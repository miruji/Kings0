#include "Character.h"

// Constructor 
Character::Character(string Name, string Class, size_t Grade, string Source)
{
	// ... 
	this->Name = Name;
	this->Grade = Grade;

	if (Class == "Leader")
		this->Class = CharacterType::Leader;
	else
	if (Class == "Warrior")
		this->Class = CharacterType::Warrior;
	else
	if (Class == "None")
		this->Class = CharacterType::None;
	else
		this->Class = CharacterType::None;

	// Set texture to sprite ... 
	Texture.loadFromFile("Data\\Textures\\Game\\Characters\\"+Name+".png");

	Sprite.setTexture(Texture);
	Rect = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(64, 64));
	Sprite.setTextureRect(Rect);
}

// Get Name (link)
string& Character::GetName()
{
	// ... 
	return Name;
}

// Get UnitClass (link) 
CharacterType& Character::GetType()
{
	// ... 
	return Class;
}

// Get Grade (link)
size_t& Character::GetGrade()
{
	// ... 
	return Grade;
}

// Get Sprite (link) 
sf::Sprite& Character::GetSprite()
{
	// ... 
	return Sprite;
}

// Add new item
void Character::AddItem(string Name, vector< Item* >& AIItems)
{
	// ... 
	for (size_t i = 0; i < AIItems.size(); i++)
	{
		// ... 
		if (Name == AIItems[i]->GetName())
		{
			Items.push_back(AIItems[i]);
			cout << "!!! New item added to Unit " << endl;
		}
	}
}

// Replace new item 
void Character::ReplaceItem(Item* Item)
{
	// ... 
	Items.push_back(Item);
}

// Get items (link) 
vector< Item* > Character::GetItems()
{
	// ... 
	return Items;
}

// Get item (obj) 
Item* Character::GetItem(size_t Count)
{
	// ... 
	return Items[Count];
}

// Get Attitude (for first Unit) (link) 
size_t& Character::GetAttitude()
{
	// ... 
	return Attitude;
}

// Get Items Count (link) 
size_t& Character::GetItemsCount()
{
	// ... 
	return ItemsCount;
}

// Draw 
void Character::Draw(sf::RenderWindow& Render)
{
	// ... 
	Render.draw(Sprite);
}