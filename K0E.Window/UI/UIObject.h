#pragma once
#include "../Macro.h"

// Class 
class K0E_Window_Api UIObject
{
protected:
	// Block name
	string BlockName = "None";

	// Id 
	string Id = "";
	string ImageId = "";

	// X & Y, W & H
	string X = "0.0f", Y = "0.0f",
		   W = "0.0f", H = "0.0f";

public:
	bool FirstDraw = true;

	// Show ? 
	bool Show = true;

	// Constructor 
	UIObject(string BlockName, string Id, string ImageId, string X, string Y);

	// Get block name (link) 
	string GetBlockName();

	// Get X & Y
	ImVec2 GetXY();

	// Set X & Y 
	void SetXY(string X, string Y);

	// Get Id (link)
	string& GetId();

	// Get ImageId (link)
	string& GetImageId();
};