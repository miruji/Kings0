#pragma once 
#include "UIObject.h"
#include "../Func/ThisSymbol.h"

// Class 
class K0E_Window_Api UICheckBox : public UIObject
{
private:
	// Checked ? 
	bool Value = false;

	// Text
	string Text = "";
	size_t TextLength = 0;

	string Spec = "";
	float Size = 0.0f;

	string CheckEvent = "";

	// For XML
	vector<float> XBuffer;
	bool XToX = false;
	float XX = 0.0f, FirstX = 0.0f, SecondX = 0.0f;

	vector<float> YBuffer;
	bool YToY = false;
	float YY = 0.0f, FirstY = 0.0f, SecondY = 0.0f;

	// Language pack 
	LanguagePack* LanguagePack1;

public:
	// Constructor 
	UICheckBox(string BlockName, string Spec, string Text, LanguagePack* LanguagePack1, float Size, string CheckEvent, float XX, string X, float YY, string Y);

	// Set XML XY
	void SetXMLXY();

	// Set text 
	void SetText(string Text);

	// Set value 
	void SetValue(bool Value);

	// Get value (link) 
	bool& GetValue();

	// Get text (link) 
	string& GetText();

	// Get size (link) 
	float& GetSize();

	// Get spec (link) 
	string& GetSpec();

	// Get checkbox event
	string& GetCheckEvent();
};