#pragma once 
#include "UIObject.h"
#include "../Func/ThisSymbol.h"

// Class 
class K0E_Window_Api UIText : public UIObject
{
private:
	// Text
	string Text = "";
	size_t TextLength = 0;

	string Spec = "";

	// For XML
	vector<float> XBuffer;
	bool XToX = false;
	float FirstX = 0.0f, SecondX = 0.0f;

	vector<float> YBuffer;
	bool YToY = false;
	float FirstY = 0.0f, SecondY = 0.0f;

	float ResizeWidth = 1.0f,
		  ResizeHeight = 1.0f;

	// Set XML XY
	void SetXMLXY();

	// Color 
	string Color = "";

	// Language pack 
	LanguagePack* LanguagePack1;

public:
	float Size = 0.0f;
	float XX = 0.0f, YY = 0.0f;

	// Constructor 
	UIText(string BlockName, string Id, string ImageId, string Spec, string Text, LanguagePack* LanguagePack1, float Size, string Color, float XX, string X, float YY, string Y, float ResizeWidth, float ResizeHeight);

	// Set text 
	void SetText(string Text);

	// Get text (link) 
	string& GetText();

	// Get size (link) 
	float& GetSize();

	// Set color 
	void SetColor(string Color);

	// Get color 
	ImVec4 GetColor();

	// Set spec 
	void SetSpec(string Spec);

	// Get spec (link) 
	string& GetSpec();
};