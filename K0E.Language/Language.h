#pragma once
#include "Macro.h"
#include "LanguageText.h"

struct K0E_Language_Api Language
{
	string Type = "Eng";

	vector< LanguageText* > Texts;
	vector<string> Names;

	Language(string Type);
	Language(void);
};