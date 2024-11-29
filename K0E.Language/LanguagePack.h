#pragma once
#include "Macro.h"
#include "Language.h"

// Class 
class K0E_Language_Api LanguagePack
{
private:
	// Language type [Choosed link]
	string Type = "Eng";

	// Languages vector 
	vector< Language* > Languages;

public:
	// Constructor
	LanguagePack();

	// Get Type (link) 
	string& GetLanguageType();

	// Get Languages (link) 
	vector< Language* >& GetLanguages();

	// Get this language text of id 
	string GetLanguageText(string Id);

	// Set language type 
	void SetLanguageType(string Type);
};