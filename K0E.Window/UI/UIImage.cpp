#include "UIImage.h"

// Constructor 
UIImage::UIImage(string BlockName, string Id, string ImageId, string Image, string X, string Y, string W, string H) : UIObject(BlockName, Id, ImageId, X, Y)
{
	Color = sf::Color(255, 255, 255, 255);

	// W & H 
	this->W = W;
	this->H = H;

	// Load UI texture 
	LoadTextureToSprite(Image, W, H);
}

// Load new texture to sprite 
void UIImage::LoadTextureToSprite(string Source, string W, string H)
{
	// Load UI texture 
	Texture.loadFromFile(Source);

	// Set sprite rect 
	Rect = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i( atoi(W.c_str()), atoi(H.c_str()) ));

	// Convert texture to sprite 
	Sprite.setTexture(Texture);
	Sprite.setTextureRect(Rect);
}

// Set new rect 
void UIImage::SetNewRect(sf::IntRect Rect)
{
	this->Rect = Rect;
	Sprite.setTextureRect(Rect);
}

// Set new sprite 
void UIImage::SetNewSprite(sf::Sprite Sprite)
{
	this->Sprite = Sprite;
}

// Get sprite (link) 
sf::Sprite& UIImage::GetSprite()
{
	return Sprite;
}

// Get W & H
sf::Vector2f UIImage::GetWH()
{
	return sf::Vector2f( atof(W.c_str()), atof(H.c_str()) );
}