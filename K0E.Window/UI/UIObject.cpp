#include "UIObject.h"

// Constructor 
UIObject::UIObject(string BlockName, string Id, string ImageId, string X, string Y)
{
	//
	this->BlockName = BlockName;
	this->Id = Id;
	this->ImageId = ImageId;

	// X & Y 
	SetXY(X, Y);
}

// Get block name (link) 
string UIObject::GetBlockName()
{
	return BlockName;
}

// Get X & Y
ImVec2 UIObject::GetXY()
{
	return ImVec2( atof(X.c_str()), atof(Y.c_str()) );
}

// Set X & Y 
void UIObject::SetXY(string X, string Y)
{
	this->X = X;
	this->Y = Y;
}

// Get Id (link)
string& UIObject::GetId()
{
	return Id;
}

// Get ImageId (link)
string& UIObject::GetImageId()
{
	return ImageId;
}