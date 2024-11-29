#include "LanguagePack.h"

// Constructor
LanguagePack::LanguagePack()
{
	// ... 
}

// Get Type (link) 
string& LanguagePack::GetLanguageType()
{
	// ... 
	return Type;
}

// Get Languages (link) 
vector< Language* >& LanguagePack::GetLanguages()
{
	// ... 
	return Languages;
}

// Get this language text of id 
string LanguagePack::GetLanguageText(string Id)
{
	// ... 
	for (size_t i = 0; i < Languages.size(); i++)
	if (Languages[i]->Type == Type)
	{
		// ... 
		for (size_t j = 0; j < Languages[i]->Texts.size(); j++)
		if (Languages[i]->Texts[j]->GetLanguageTextId() == Id)
		{
			// ... 
			return Languages[i]->Texts[j]->GetText();
		}
	}

	// Load error (warning) 
	cout << "> Unable to load text with Id : \"" + Id + "\"" << endl;

	return "";
}

// Set language type 
void LanguagePack::SetLanguageType(string Type)
{
	// ... 
	this->Type = Type;
}