#pragma once
#include "Macro.h"

// Class 
class K0E_Language_Api LanguageText {
private:
	// Language id & text 
	string Id = "", Text = "";

public:
	// Constructor
	LanguageText(string Id, string Text);

	// Get Text (link) 
	string& GetText();

	// Get LanguageTextId (link) 
	string& GetLanguageTextId();
};