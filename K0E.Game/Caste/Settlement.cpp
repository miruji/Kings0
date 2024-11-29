#include "Settlement.h"

// Constructor
Settlement::Settlement(string Name, string Type, size_t Population, size_t Team, float X, float Y)
{
	// Set type
		//
		if (Type == "Settlement")
		{
			ArmyLimit = 15; Army = ArmyLimit;
			this->Type = SettlementTypes::Settlement;
		}
		else
		if (Type == "Barn")
			this->Type = SettlementTypes::Barn;
		else
		//
		if (Type == "Wall")
			this->Type = SettlementTypes::Wall;
		else
		if (Type == "Tower")
		{
			ArmyLimit = 15; Army = ArmyLimit;
			this->Type = SettlementTypes::Tower;
		}
		else
		if (Type == "Castle")
		{
			ArmyLimit = 25; Army = ArmyLimit;
			this->Type = SettlementTypes::Castle;
		}
		else
		//
		if (Type == "Field")
			this->Type = SettlementTypes::Field;
		else
		if (Type == "Pasture")
			this->Type = SettlementTypes::Pasture;
		else
		if (Type == "Fisheries")
			this->Type = SettlementTypes::Fisheries;
		else
		//
		if (Type == "Suburb")
			this->Type = SettlementTypes::Suburb;
		else
		if (Type == "Sawmill")
			this->Type = SettlementTypes::Sawmill;
		else
			this->Type = SettlementTypes::None;

	// Set team
	this->Team = Team;

	// Set font and settlement name 
	Font.loadFromFile("Data\\Fonts\\Font.ttf");
	this->Name = Name;

	// Load texture to sprite
	BracketTexture.loadFromFile("Data\\Textures\\Game\\Bracket1.png");
		//
		if (this->Type == SettlementTypes::Settlement)
			BasicTexture.loadFromFile("Data\\Textures\\Game\\Settlement.png");
		else
		if (this->Type == SettlementTypes::Barn)
			BasicTexture.loadFromFile("Data\\Textures\\Game\\Barn.png");
		else
		//
		if (this->Type == SettlementTypes::Wall)
			BasicTexture.loadFromFile("Data\\Textures\\Game\\Wall.png");
		else
		if (this->Type == SettlementTypes::Tower)
			BasicTexture.loadFromFile("Data\\Textures\\Game\\Tower.png");
		else
		if (this->Type == SettlementTypes::Castle)
			BasicTexture.loadFromFile("Data\\Textures\\Game\\Castle.png");
		else
		//
		if (this->Type == SettlementTypes::Field)
			BasicTexture.loadFromFile("Data\\Textures\\Game\\Field.png");
		else
		if (this->Type == SettlementTypes::Pasture)
			BasicTexture.loadFromFile("Data\\Textures\\Game\\Pasture.png");
		else
		if (this->Type == SettlementTypes::Fisheries)
			BasicTexture.loadFromFile("Data\\Textures\\Game\\Fisheries.png");
		else
		//
		if (this->Type == SettlementTypes::Suburb)
			BasicTexture.loadFromFile("Data\\Textures\\Game\\Suburb.png");
		else
		if (this->Type == SettlementTypes::Sawmill)
			BasicTexture.loadFromFile("Data\\Textures\\Game\\Sawmill.png");


	// Load shadow texture 
	ShadowTexture.loadFromFile("Data\\Textures\\Game\\Shadow.png");
	// Load team shadow texture 
	TeamShadowTexture.loadFromFile("Data\\Textures\\Game\\TeamShadow.png");

	// Set X & Y
	this->X = X; this->Y = Y;
}
Settlement::Settlement()
{
	//
}

// Draw 
void Settlement::Draw(sf::RenderWindow& Render, float CameraX, float CameraY, float CameraW, float CameraH, bool NamesDrawing, string Color, size_t PlayerTeam, CasteNation CasteNation1)
{
	if (Drawing == false)
		return;

	// Optimize 
	if ((X/32 >= size_t(CameraX/32) || CameraX <= 0) && (Y/32 >= size_t(CameraY/32) || CameraY <= 0) &&
		 X/32 <= size_t((CameraX+CameraW)/32) && Y/32 <= size_t((CameraY+CameraH)/32))
	{
		// Shadow 
		if (Type != SettlementTypes::Barn &&
			Type != SettlementTypes::Wall &&
			Type != SettlementTypes::Field &&
			Type != SettlementTypes::Pasture &&
			Type != SettlementTypes::Fisheries &&
			Type != SettlementTypes::Suburb &&
			Type != SettlementTypes::Sawmill)
		{
			// Team shadow 
			/*
			Sprite.setTexture(TeamShadowTexture);

			if (Team == 0)
				Rect = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(48, 48));
			else
			if (Team == 1)
				Rect = sf::IntRect(sf::Vector2i(0, 48), sf::Vector2i(48, 48));
			else
			if (Team == 2)
				Rect = sf::IntRect(sf::Vector2i(0, 96), sf::Vector2i(48, 48));
			else
			if (Team == 3)
				Rect = sf::IntRect(sf::Vector2i(0, 144), sf::Vector2i(48, 48));
			else
			if (Team == 4)
				Rect = sf::IntRect(sf::Vector2i(0, 192), sf::Vector2i(48, 48));
			else
			if (Team == 5)
				Rect = sf::IntRect(sf::Vector2i(0, 240), sf::Vector2i(48, 48));
			else
				Rect = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(48, 48));
			
			Sprite.setTextureRect(Rect);

			Sprite.setPosition(sf::Vector2f(X-8, Y-8));
			Render.draw(Sprite);
			*/

			// Basic shadow 
			Sprite.setTexture(ShadowTexture);

			Rect = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(48, 48));
			Sprite.setTextureRect(Rect);

			Sprite.setPosition(sf::Vector2f(X-8, Y-8));
			Render.draw(Sprite);
		}
		
		// Basic 
		Rect = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32));
		
		Sprite.setTextureRect(Rect);
		Sprite.setPosition(sf::Vector2f(X, Y));

		Sprite.setTexture(BasicTexture);
		Sprite.setColor(StringToColor("255;255;255"));
		Render.draw(Sprite);

		// Bracket
		Sprite.setTexture(BracketTexture);
		Sprite.setColor(StringToColor(Color));
		Render.draw(Sprite);
	}

	if (Type == SettlementTypes::Barn ||
		Type == SettlementTypes::Wall ||
		Type == SettlementTypes::Field ||
		Type == SettlementTypes::Pasture || 
		Type == SettlementTypes::Fisheries || 
		Type == SettlementTypes::Suburb || 
		Type == SettlementTypes::Sawmill)
		return;
	else
	// Optimize 
	if (NamesDrawing == true)
	if ((X/32 >= size_t(CameraX/32) || CameraX <= 0) && (Y/32+1 >= size_t(CameraY/32) || CameraY <= 0) &&
		 X/32 <= size_t((CameraX+CameraW)/32) && Y/32+1 <= size_t((CameraY+CameraH)/32))
	{
		//
		Name = '['+to_string(Army)+']';
		//
		if (Opened == false && PlayerTeam != Team)
		{
			string Buffer = "";
			for (size_t i = 0; i < Name.length(); i++)
				Buffer += '?';
			Text = sf::Text(Buffer, Font, this->FontSize);
		}
		else
			Text = sf::Text(Name, Font, this->FontSize);

		// Set style 
		Text.setStyle(sf::Text::Bold);
		Text.setOrigin(sf::Vector2f((-16)+(Text.getGlobalBounds().width/2), 0));
		Text.setPosition(X, Y+32);

		// Background text 
		sf::Vector2f PositionBuffer = Text.getPosition();
		Text.setFillColor(sf::Color(0, 0, 0, 255));
		Text.setPosition(PositionBuffer.x - 2, PositionBuffer.y); Render.draw(Text);
		Text.setPosition(PositionBuffer.x + 2, PositionBuffer.y); Render.draw(Text);
		Text.setPosition(PositionBuffer.x, PositionBuffer.y - 2); Render.draw(Text);
		Text.setPosition(PositionBuffer.x, PositionBuffer.y + 2); Render.draw(Text);
		Text.setPosition(PositionBuffer);

		//
		Text.setFillColor(StringToColor(Color));

		Render.draw(Text);
	}
}

// Get Type (link)
SettlementTypes& Settlement::GetType()
{
	//
	return Type;
}
size_t Settlement::GetTypeInt()
{
	//
	if (Type == SettlementTypes::None)
		return 0;
	else
	//
	if (Type == SettlementTypes::Settlement)
		return 1;
	else
	if (Type == SettlementTypes::Barn)
		return 2;
	else
	//
	if (Type == SettlementTypes::Wall)
		return 3;
	else
	if (Type == SettlementTypes::Tower)
		return 4;
	else
	if (Type == SettlementTypes::Castle)
		return 5;
	else
	//
	if (Type == SettlementTypes::Field)
		return 6;
	else
	if (Type == SettlementTypes::Pasture)
		return 7;
	else
	if (Type == SettlementTypes::Fisheries)
		return 8;
	else
	//
	if (Type == SettlementTypes::Suburb)
		return 9;
	else
	if (Type == SettlementTypes::Sawmill)
		return 10;
}

// Add new item
void Settlement::AddItem(string Name, vector<Item*>& AIItems)
{
	//
	for (size_t i = 0; i < AIItems.size(); i++)
	{
		//
		if (Name == AIItems[i]->GetName())
		{
			Items.push_back(AIItems[i]);
		}
	}
}

// Replace new item 
void Settlement::ReplaceItem(Item* Item)
{
	Items.push_back(Item);
}

// Clear items
void Settlement::ClearItems()
{
	Items.clear();
	Items.resize(0);
}

// Delete one item 
void Settlement::DeleteItem(size_t Cout)
{
	vector< Item* > ItemsBuffer = Items;

	// Create now new vector 
	ClearItems();
	for (size_t i = 0; i < ItemsBuffer.size(); i++)
	{
		//
		if (i == Cout) continue;
		else
		{
			ReplaceItem(ItemsBuffer[i]);
		}
	}
}

// Get items (link) 
vector< Item* >& Settlement::GetItems()
{
	return Items;
}

// Get items market 
vector< Item* > Settlement::GetItemsMarket()
{
	vector< Item* > Result;

	for (size_t i = 0; i < Items.size(); i++)
	if (Items[i]->GetType() == ItemType::Food || Items[i]->GetType() == ItemType::Wood)
		Result.push_back(Items[i]);

	return Result;
}

// Get items tavern 
vector< Item* > Settlement::GetItemsTavern()
{
	vector< Item* > Result;

	for (size_t i = 0; i < Items.size(); i++)
	if (Items[i]->GetType() == ItemType::Army)
		Result.push_back(Items[i]);

	return Result;
}

// Get item (obj) 
Item* Settlement::GetItem(size_t Count)
{
	return Items[Count];
}

// Get item market (obj)
Item* Settlement::GetItemMarket(size_t Count)
{
	return GetItemsMarket()[Count];
}

// Get item tavern (obj)
Item* Settlement::GetItemTavern(size_t Count)
{
	return GetItemsTavern()[Count];
}

// Get Items Count (link) 
size_t& Settlement::GetItemsCount()
{
	return ItemsCount;
}