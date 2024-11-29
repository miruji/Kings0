#pragma once 
#include "UIObject.h"

// Class 
class K0E_Window_Api UIButton : public UIObject
{
private:
	// Sprite & texture & Rect 
	sf::Texture Texture;
	sf::Sprite  Sprite;
	sf::IntRect Rect;

	// Event 
	string Event;

	// Num 
	size_t Num;

public:
	bool Closed = false;

	// Constructor 
	UIButton(string BlockName, string Id, string ImageId, size_t Num, string Event, bool Message, string Image, string X, string Y, string W, string H, bool Resize);

	// is Message ? 
	bool Message = false;
	// resize ?
	bool Resize = false;

	// Load new texture to sprite 
	void LoadTextureToSprite(string Source, string W, string H);

	// Get sprite (link) 
	sf::Sprite& GetSprite();

	// Set event 
	void SetEvent(string Event);

	// Get event (link) 
	string& GetEvent();

	// Get W & H
	sf::Vector2f GetWH();

	// Get Num (link) 
	size_t& GetNum();

	void SetWH(string W, string H);
};