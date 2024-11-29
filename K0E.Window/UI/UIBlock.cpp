#include "UI.h"

// Constructor 
UIBlock::UIBlock(string Name, float X, float Y, float Width, float Height, size_t Layer, bool FixedPosition)
{
	// Set name 
	this->Name = Name;
	this->BackName = Name;

	// Set X & Y 
	this->X = X;
	this->Y = Y;
	
	// Set W & H 
	this->Width = Width;
	this->Height = Height;

	// Set layer 
	this->Layer = Layer;

	// Set fixed position 
	this->FixedPosition = FixedPosition;
}
UIBlock::UIBlock(void)
{
}

// Get name (link) 
string& UIBlock::GetName()
{
	return Name;
}

// Get back name (link) 
string& UIBlock::GetBackName()
{
	return BackName;
}

// Set new name 
void UIBlock::SetName(string NewName)
{
	// Save back block name 
	SetBackName(Name);

	// Set new block name 
	Name = NewName;
}

// Set new back name 
void UIBlock::SetBackName(string NewBackName)
{ 
	BackName = NewBackName;
}

// Get X & Y 
ImVec2 UIBlock::GetXY()
{
	return ImVec2(X, Y);
}

// Get W & H 
ImVec2 UIBlock::GetWH()
{
	return ImVec2(Width, Height);
}
void UIBlock::SetWH(float Width, float Height)
{
	this->Width = Width;
	this->Height = Height;
}

// Get layer (link) 
size_t& UIBlock::GetLayer()
{
	return Layer;
}

// Set layer 
void UIBlock::SetLayer(size_t Layer)
{
	this->Layer = Layer;
}

// Set i Position 
void UIBlock::SetIPosition(size_t I)
{
	IPosition = I;
}

// Get i Position (link) 
size_t& UIBlock::GetIPosition()
{
	return IPosition;
}

// Set Position 
void UIBlock::SetPosition(float X, float Y)
{
	this->X = X;
	this->Y = Y;
}