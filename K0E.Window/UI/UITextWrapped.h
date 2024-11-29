#pragma once 
#include "UIObject.h"

//
struct K0E_Window_Api UITextWrapped : public UIObject
{
	string Text;
	size_t X, Y, W, H;
	string Id = "";

	UITextWrapped(string BlockName, string Id, vector<string> Text, LanguagePack* LanguagePack1, string X, string Y, string W, string H);
};