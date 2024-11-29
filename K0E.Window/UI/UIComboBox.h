#pragma once 
#include "UIObject.h"

// Class 
class K0E_Window_Api UIComboBox : public UIObject
{
private:
	// Spec 
	vector<string> Specs;

	// Text
	vector<string> Texts;

	// Language pack 
	LanguagePack* LanguagePack1;

public:
	// First draw ? 
	bool FirstDraw = true;

	// Current item 
	const char* BasicCurrentItem = "";
	const char* CurrentItem = "";

	// 
	float Width = 0.0f;

	// Constructor 
	UIComboBox(string BlockName, string Id, string ImageId, string Spec, string Text, LanguagePack* LanguagePack1, string X, string Y, float Width);

	// Set texts 
	void SetTexts(vector<string> Texts);

	// Get texts (Link) 
	vector<string>& GetTexts();
};