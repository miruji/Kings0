#pragma once
#include "Macro.h"
#include "Game/XMLCaste.h"
#include "../K0E.File/File.h"
#include "../K0E.Language/LanguagePack.h"
#include "../K0E.Console/Console.h"
#include "../K0E.Console/Error/Error.h"

#include "Func/ThisInt.h"
#include "Func/ThisSymbol.h"

class K0E_XMLParser_Api XMLParser
{
private:
	TiXmlDocument* Document;

public:
	XMLParser(void);

	// Load new XML document 
	bool LoadDocument(string Path, Console* Console1);

	// Get XML document (link) 
	TiXmlDocument* GetDocument();

	// Get document data element (link) 
	TiXmlElement* GetDataElement();
	// Map.xml 
	vector< vector<string> > LandMap(); // Land map 
	vector< XMLCaste* >      MapAI();   // AI data

	// Data\Language
	Language* LoadLanguage(string Type);

	// Search settings 
	void SearchSettings(bool Main, string& Version, string& Title, size_t& Width, size_t& Height, size_t& FramerateLimit, size_t& WindowMode, bool& VerticalSync, string& LanguageType, int& Soundtrack, int& SoundEffects);

	// Save file 
	void SaveFile(string Path, vector<string> Data);
};
