#pragma once 
#include "UIObject.h"

//
struct K0E_Window_Api UIInput : public UIObject
{
	vector<string> Text;
	size_t X, Y, W, H;
	size_t MaxChars = 0;
	string Type = "";
	string Spec = "";

	UIInput(string BlockName, string Id, string Type, string Spec, vector<string> Text, LanguagePack* LanguagePack1, string X, string Y, string W, string H);
};