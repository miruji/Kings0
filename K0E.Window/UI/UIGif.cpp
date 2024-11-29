#include "UIGif.h"

// Constructor 
UIGif::UIGif(string BlockName, string Id, string Image, size_t Delay, string X, string Y, string W, string H) : UIObject(BlockName, Id, "", X, Y)
{
	// W & H 
	this->W = W;
	this->H = H;

	// Set delay 
	this->Delay = Delay;

	// Load UI textures (Strings) 
	vector<string> Images;
	string Buffer = "";
	for (size_t i = 0; i < Image.size(); i++)
	{
		if (Image[i] == ';')
		{
			Images.push_back(Buffer);
			Buffer = "";
			i++;
		}
		if (i >= Image.size())
			break;

		Buffer += Image[i];
	}

	// Sets vector 
	sf::Texture Texture;
	for (size_t i = 0; i < Images.size(); i++)
	{
		Texture.loadFromFile( Images[i] );
		Textures.push_back( Texture );
	}

	// Set rect 
	Rect = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i( atoi(W.c_str()), atoi(H.c_str()) ));
	
	// Set first image 
	Sprite.setTexture(Textures[Cycle]);
	Sprite.setTextureRect(Rect);
}

// Get sprite (link) 
sf::Sprite& UIGif::GetSprite(size_t NewDelay)
{
	//
	if (CycleBuffer >= Delay)
	{
		if (Cycle < Textures.size()-1)
			Cycle++;
		else
		if (Cycle+1 == Textures.size())
			Cycle = 0;

		// Convert new texture to sprite
		if (Cycle < Textures.size())
		Sprite.setTexture(Textures[Cycle]);
		Sprite.setTextureRect(Rect);

		CycleBuffer = 0;
	}
	else
		CycleBuffer += NewDelay;

	// 
	return Sprite;
}

// Get W & H
sf::Vector2f UIGif::GetWH()
{
	return sf::Vector2f( atof(W.c_str()), atof(H.c_str()) );
}