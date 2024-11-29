#include "UIButton.h"

// Constructor 
UIButton::UIButton(string BlockName, string Id, string ImageId, size_t Num, string Event, bool Message, string Image, string X, string Y, string W, string H, bool Resize) : UIObject(BlockName, Id, ImageId, X, Y)
{
	// Set num 
	this->Num = Num;

	// Set event 
	this->Event = Event;

	// Set message & resize
	this->Message = Message;
	this->Resize = Resize;

	// W & H 
	this->W = W;
	this->H = H;

	// Load UI texture 
	LoadTextureToSprite(Image, W, H);
}

// Load new texture to sprite 
void UIButton::LoadTextureToSprite(string Source, string W, string H)
{
	// Load UI texture 
	Texture.loadFromFile(Source);

	// Set sprite rect 
	Rect = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i( atoi(W.c_str()), atoi(H.c_str()) ));

	// Convert texture to sprite 
	Sprite.setTexture(Texture);
	Sprite.setTextureRect(Rect);
}

// Get sprite (link) 
sf::Sprite& UIButton::GetSprite()
{
	return Sprite;
}

// Set event 
void UIButton::SetEvent(string Event)
{
	this->Event = Event;
}

// Get event (link) 
string& UIButton::GetEvent()
{
	return Event;
}

// Get W & H
sf::Vector2f UIButton::GetWH()
{
	return sf::Vector2f( atof(W.c_str()), atof(H.c_str()) );
}

// Get Num (link) 
size_t& UIButton::GetNum()
{
	return Num;
}

void UIButton::SetWH(string W, string H)
{
	this->W = W;
	this->H = H;
}