#include "LanguageText.h"

// Constructor
LanguageText::LanguageText(string Id, string Text)
{
	// Set Text 
	this->Text = Text;

	// Set Id 
	this->Id = Id;
}

// Get Text (link) 
string& LanguageText::GetText()
{
	// ... 
	return Text;
}

// Get LanguageTextType (link) 
string& LanguageText::GetLanguageTextId()
{
	// ... 
	return Id;
}