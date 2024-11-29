#include "Player.h"

bool SearchBackYourDomain(DomainMap* DomainMap1, MapBlock NextBlock, size_t BasicTeam)
{
	//
	BasicTeam = BasicTeam + 2;
	if (DomainMap1->GetTeamMap()[NextBlock.Y/32-1][NextBlock.X/32-1] == BasicTeam ||
		DomainMap1->GetTeamMap()[NextBlock.Y/32-1][NextBlock.X/32] == BasicTeam ||
		DomainMap1->GetTeamMap()[NextBlock.Y/32-1][NextBlock.X/32+1] == BasicTeam ||
		DomainMap1->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32-1] == BasicTeam || 
		DomainMap1->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32+1] == BasicTeam ||
		DomainMap1->GetTeamMap()[NextBlock.Y/32+1][NextBlock.X/32-1] == BasicTeam ||
		DomainMap1->GetTeamMap()[NextBlock.Y/32+1][NextBlock.X/32] == BasicTeam ||
		DomainMap1->GetTeamMap()[NextBlock.Y/32+1][NextBlock.X/32+1] == BasicTeam)
		return true;
	else
		return false;
}

// Consturctor 
Player::Player(string Name)
{
	// Load image to sprite 
	BracketTexture.loadFromFile("Data\\Textures\\Game\\Bracket1.png");
	BasicTexture.loadFromFile("Data\\Textures\\Game\\Unit.png");

	// Load shadow texture 
	ShadowTexture.loadFromFile("Data\\Textures\\Game\\Shadow.png");
	// Load team shadow texture 
	TeamShadowTexture.loadFromFile("Data\\Textures\\Game\\TeamShadow.png");

	// Load direction texture 
	DirectionTexture.loadFromFile("Data\\Textures\\Game\\Direction.png");

	// Set font and player name
	Font.loadFromFile("Data\\Fonts\\Font.ttf");
	this->Name = Name;
}

// Update sprite 
void Player::UpdateRect(sf::IntRect Rect)
{
	this->Rect = Rect;
}

// Set position 
void Player::SetPosition(float X, float Y)
{
	this->X = X; this->Y = Y;
}

// Set X & Y
void Player::Move(float X, float Y)
{
	this->X = this->X + X;
	this->Y = this->Y + Y;
}

// Search next block domain 
bool Player::SearchNextBlockDomain(MapBlock NextBlock, size_t BasicTeam, DomainMap* DomainMap1, vector< int >& Status)
{
	//
	if (DomainMap1->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32] == BasicTeam+2 || 
		DomainMap1->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32] == 0 )
		return true;
	else
	{
		size_t Team = DomainMap1->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32];
		//cout << Team << " | " << Game1->Player1->Team << " | " << Game1->Castes[Game1->Player1->Team]->Status[Team] << endl;
		if (Status[Team-2] == 0 || 
			Status[Team-2] == 2)
			return true;
		else
			return false;
	}
}

// Draw direction 
void Player::DrawDirection(sf::RenderWindow& Render, vector< vector<MapBlock> >& BlocksVector, /*vector< vector< size_t > >& PreviewMap1, vector< vector< size_t > >& PreviewMap1General,*/ vector< vector<string> >& NoEntryVector, size_t& SaveNewGameNation, DomainMap* DomainMap1, vector< int >& Status, vector< Technology > Technologys, string Color)
{
	// Direction lines 
	Sprite.setTexture(DirectionTexture);

	if (true)
	{
		size_t Ends = 0;
		string Buffer = "";
		for (size_t i = 0; i < Color.length(); i++)
		{
			if (Ends == 3)
			{
				Sprite.setColor(StringToColor(Buffer+"255"));
				break;
			}
			else
				Buffer += Color[i];
			//
			if (Color[i] == ';')
				Ends++;
		}
	}

	MapBlock NextBlock;

	// q
	NextBlock = BlocksVector[(Y/32)-1][(X/32)-1];
	//if (PreviewMap1[(Y/32)-1][(X/32)-1] || PreviewMap1General[(Y/32)-1][(X/32)-1])
	if ( SearchBackYourDomain(DomainMap1, NextBlock, Team) )
	if (SearchNextBlockDomain(NextBlock, Team, DomainMap1, Status))
	if (NoEntryVector[(X/32)-1][(Y/32)-1] == "0" || SearchChar(NoEntryVector[(X/32)-1][(Y/32)-1], to_string(Team+1)[0]))
	if ((Technologys[1].Opened || NextBlock.Mountain == false) && ((Technologys[3].Opened && NextBlock.River == true) || (Technologys[2].Opened && Technologys[3].Opened) || (NextBlock.River == false && NextBlock.Land == true)) && (Technologys[0].Opened || NextBlock.Forest == false))
	{
		Sprite.setTextureRect(sf::IntRect(0,0,32,32));
		Sprite.setPosition(sf::Vector2f(X-32, Y-32));
		Render.draw(Sprite);
	}
	// w
	NextBlock = BlocksVector[(Y/32)-1][(X/32)];
	//if (PreviewMap1[(Y/32)-1][(X/32)] || PreviewMap1General[(Y/32)-1][(X/32)])
	if ( SearchBackYourDomain(DomainMap1, NextBlock, Team) )
	if (SearchNextBlockDomain(NextBlock, Team, DomainMap1, Status))
	if (NoEntryVector[(X/32)][(Y/32)-1] == "0" || SearchChar(NoEntryVector[(X/32)][(Y/32)-1], to_string(Team+1)[0]))
	if ((Technologys[1].Opened || NextBlock.Mountain == false) && ((Technologys[3].Opened && NextBlock.River == true) || (Technologys[2].Opened && Technologys[3].Opened) || (NextBlock.River == false && NextBlock.Land == true)) && (Technologys[0].Opened || NextBlock.Forest == false))
	{
		Sprite.setTextureRect(sf::IntRect(32,0,32,32));
		Sprite.setPosition(sf::Vector2f(X, Y-32));
		Render.draw(Sprite);
	}
	// e
	NextBlock = BlocksVector[(Y/32)-1][(X/32)+1];
	//if (PreviewMap1[(Y/32)-1][(X/32)+1] || PreviewMap1General[(Y/32)-1][(X/32)+1])
	if ( SearchBackYourDomain(DomainMap1, NextBlock, Team) )
	if (SearchNextBlockDomain(NextBlock, Team, DomainMap1, Status))
	if (NoEntryVector[(X/32)+1][(Y/32)-1] == "0" || SearchChar(NoEntryVector[(X/32)+1][(Y/32)-1], to_string(Team+1)[0]))
	if ((Technologys[1].Opened || NextBlock.Mountain == false) && ((Technologys[3].Opened && NextBlock.River == true) || (Technologys[2].Opened && Technologys[3].Opened) || (NextBlock.River == false && NextBlock.Land == true)) && (Technologys[0].Opened || NextBlock.Forest == false))
	{
		Sprite.setTextureRect(sf::IntRect(64,0,32,32));
		Sprite.setPosition(sf::Vector2f(X+32, Y-32));
		Render.draw(Sprite);
	}
	// a
	NextBlock = BlocksVector[(Y/32)][(X/32)-1];
	//if (PreviewMap1[(Y/32)][(X/32)-1] || PreviewMap1General[(Y/32)][(X/32)-1])
	if ( SearchBackYourDomain(DomainMap1, NextBlock, Team) )
	if (SearchNextBlockDomain(NextBlock, Team, DomainMap1, Status))
	if (NoEntryVector[(X/32)-1][(Y/32)] == "0" || SearchChar(NoEntryVector[(X/32)-1][(Y/32)], to_string(Team+1)[0]))
	if ((Technologys[1].Opened || NextBlock.Mountain == false) && ((Technologys[3].Opened && NextBlock.River == true) || (Technologys[2].Opened && Technologys[3].Opened) || (NextBlock.River == false && NextBlock.Land == true)) && (Technologys[0].Opened || NextBlock.Forest == false))
	{
		Sprite.setTextureRect(sf::IntRect(96,0,32,32));
		Sprite.setPosition(sf::Vector2f(X-32, Y));
		Render.draw(Sprite);
	}
	// z
	NextBlock = BlocksVector[(Y/32)+1][(X/32)-1];
	//if (PreviewMap1[(Y/32)+1][(X/32)-1] || PreviewMap1General[(Y/32)+1][(X/32)-1])
	if ( SearchBackYourDomain(DomainMap1, NextBlock, Team) )
	if (SearchNextBlockDomain(NextBlock, Team, DomainMap1, Status))
	if (NoEntryVector[(X/32)-1][(Y/32)+1] == "0" || SearchChar(NoEntryVector[(X/32)-1][(Y/32)+1], to_string(Team+1)[0]))
	if ((Technologys[1].Opened || NextBlock.Mountain == false) && ((Technologys[3].Opened && NextBlock.River == true) || (Technologys[2].Opened && Technologys[3].Opened) || (NextBlock.River == false && NextBlock.Land == true)) && (Technologys[0].Opened || NextBlock.Forest == false))
	{
		Sprite.setTextureRect(sf::IntRect(128,0,32,32));
		Sprite.setPosition(sf::Vector2f(X-32, Y+32));
		Render.draw(Sprite);
	}
	// x
	NextBlock = BlocksVector[(Y/32)+1][(X/32)];
	//if (PreviewMap1[(Y/32)+1][(X/32)] || PreviewMap1General[(Y/32)+1][(X/32)])
	if ( SearchBackYourDomain(DomainMap1, NextBlock, Team) )
	if (SearchNextBlockDomain(NextBlock, Team, DomainMap1, Status))
	if (NoEntryVector[(X/32)][(Y/32)+1] == "0" || SearchChar(NoEntryVector[(X/32)][(Y/32)+1], to_string(Team+1)[0]))
	if ((Technologys[1].Opened || NextBlock.Mountain == false) && ((Technologys[3].Opened && NextBlock.River == true) || (Technologys[2].Opened && Technologys[3].Opened) || (NextBlock.River == false && NextBlock.Land == true)) && (Technologys[0].Opened || NextBlock.Forest == false))
	{
		Sprite.setTextureRect(sf::IntRect(160,0,32,32));
		Sprite.setPosition(sf::Vector2f(X, Y+32));
		Render.draw(Sprite);
	}
	// c
	NextBlock = BlocksVector[(Y/32)+1][(X/32)+1];
	//if (PreviewMap1[(Y/32)+1][(X/32)+1] || PreviewMap1General[(Y/32)+1][(X/32)+1])
	if ( SearchBackYourDomain(DomainMap1, NextBlock, Team) )
	if (SearchNextBlockDomain(NextBlock, Team, DomainMap1, Status))
	if (NoEntryVector[(X/32)+1][(Y/32)+1] == "0" || SearchChar(NoEntryVector[(X/32)+1][(Y/32)+1], to_string(Team+1)[0]))
	if ((Technologys[1].Opened || NextBlock.Mountain == false) && ((Technologys[3].Opened && NextBlock.River == true) || (Technologys[2].Opened && Technologys[3].Opened) || (NextBlock.River == false && NextBlock.Land == true)) && (Technologys[0].Opened || NextBlock.Forest == false))
	{
		Sprite.setTextureRect(sf::IntRect(192,0,32,32));
		Sprite.setPosition(sf::Vector2f(X+32, Y+32));
		Render.draw(Sprite);
	}
	// d
	NextBlock = BlocksVector[(Y/32)][(X/32)+1];
	//if (PreviewMap1[(Y/32)][(X/32)+1] || PreviewMap1General[(Y/32)][(X/32)+1])
	if ( SearchBackYourDomain(DomainMap1, NextBlock, Team) )
	if ( SearchNextBlockDomain(NextBlock, Team, DomainMap1, Status) )
	if (NoEntryVector[(X/32)+1][(Y/32)] == "0" || SearchChar(NoEntryVector[(X/32)+1][(Y/32)], to_string(Team+1)[0]))
	if ((Technologys[1].Opened || NextBlock.Mountain == false) && ((Technologys[3].Opened && NextBlock.River == true) || (Technologys[2].Opened && Technologys[3].Opened) || (NextBlock.River == false && NextBlock.Land == true)) && (Technologys[0].Opened || NextBlock.Forest == false))
	{
		Sprite.setTextureRect(sf::IntRect(224,0,32,32));
		Sprite.setPosition(sf::Vector2f(X+32, Y));
		Render.draw(Sprite);
	}
}

// Draw
void Player::Draw(sf::RenderWindow& Render, bool NamesDrawing, string Color, size_t Army)
{
	// Shadow 
	if (true) {
		sf::IntRect Rect;
		/*
		// Team shadow 
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
		Sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(48, 48)));

		Sprite.setPosition(sf::Vector2f(X-8, Y-8));
		Render.draw(Sprite);
	}

	// Basic 
	Sprite.setTextureRect(this->Rect);
	Sprite.setPosition(sf::Vector2f(X, Y));

	Sprite.setTexture(BasicTexture);
	Sprite.setColor(StringToColor("255;255;255"));
	Render.draw(Sprite);

	// Bracket
	Sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	Sprite.setTexture(BracketTexture);
	Sprite.setColor(StringToColor(Color));
	Render.draw(Sprite);

	// Text 
	if (NamesDrawing == true)
	{
		//
		Name = '['+to_string(Army)+']';
		Text = sf::Text(Name, Font, this->FontSize);

		//
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