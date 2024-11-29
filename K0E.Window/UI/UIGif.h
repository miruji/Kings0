#pragma once 
#include "UIObject.h"

// Class 
class K0E_Window_Api UIGif : public UIObject
{
private:
	// Sprite & texture & Rect 
	vector< sf::Texture > Textures;
	sf::Sprite  Sprite;
	sf::IntRect Rect;
	size_t Cycle = 0, Delay = 100, CycleBuffer = 0;

public:
	// Constructor 
	UIGif(string BlockName, string Id, string Image, size_t Delay, string X, string Y, string W, string H);

	// Get sprite (link) 
	sf::Sprite& GetSprite(size_t NewDelay);

	// Get W & H
	sf::Vector2f GetWH();
};