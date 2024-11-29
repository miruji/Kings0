#pragma once 
#include "UIObject.h"

// Class 
class K0E_Window_Api UIImage : public UIObject
{
private:
	// Sprite & texture & Rect 
	sf::Texture Texture;
	sf::Sprite  Sprite;
	sf::IntRect Rect;

	// Id 
	string Id = "";

public:
	sf::Color Color;

	// Constructor 
	UIImage(string BlockName, string Id, string ImageId, string Image, string X, string Y, string W, string H);

	// Load new texture to sprite 
	void LoadTextureToSprite(string Source, string W, string H);

	// Set new rect 
	void SetNewRect(sf::IntRect Rect);

	// Set new sprite 
	void SetNewSprite(sf::Sprite Sprite);

	// Get sprite (link) 
	sf::Sprite& GetSprite();

	// Get W & H
	sf::Vector2f GetWH();
};