#include "XMLParser.h"

XMLParser::XMLParser(void)
{
}

// Load new XML file
bool XMLParser::LoadDocument(string Path, Console* Console1)
{
	//
	bool Result = false;
	Document = new TiXmlDocument(Path.c_str());
	if (Document->LoadFile())
	{
		Console1->IPrintln("> File \"" + Path + "\" is open");
		Result = true;
	}
	else
	{
		Error Error1(Console1, ErrorType::XMLError, { "Unable to open file \""+Path+"\"" }, { "Continue K0E" }, false);
	}
	//
	return Result;
}

// Get XML document (link) 
TiXmlDocument* XMLParser::GetDocument()
{
	// ... 
	return Document;
}

// Get document data element (link) 
TiXmlElement* XMLParser::GetDataElement()
{
	return GetDocument()->FirstChildElement("Data");
}

// Land map 
vector< vector<string> > XMLParser::LandMap()
{
	// Result vector
	vector< vector<string> > Result;
	vector< string > Land;
	vector< string > Forest;
	vector< string > Mountain;
	vector< string > Road;
	vector< string > Domain;

	//
	TiXmlElement* ElMap = GetDataElement();
	// Loading land map data
	TiXmlElement* ElLand     = ElMap->FirstChildElement("Land");
	TiXmlElement* ElForest   = ElMap->FirstChildElement("Forest");
	TiXmlElement* ElMountain = ElMap->FirstChildElement("Mountain");
	TiXmlElement* ElRoad     = ElMap->FirstChildElement("Road");
	TiXmlElement* ElDomain   = ElMap->FirstChildElement("Domain");

		// Buffer
		string Buffer = "";
		// Land map 
		for (size_t i = 0; i < string(ElLand->GetText()).length(); i++)
		{
			if (ThisInt(ElLand->GetText()[i]) || ThisSymbol(ElLand->GetText()[i]) || ElLand->GetText()[i] == ' ')
				Buffer += ElLand->GetText()[i];

			if (ElLand->GetText()[i] == ';')
			{
				Land.push_back(Buffer);
				Buffer = "";
				i++;
			}
		}

		Result.push_back(Land);
		Buffer = "";
		// Forest map 
		for (size_t i = 0; i < string(ElForest->GetText()).length(); i++)
		{
			Buffer += ElForest->GetText()[i];

			if (ElForest->GetText()[i] == ' ')
				continue;
			else
			if (ElForest->GetText()[i] == ';')
			{
				Forest.push_back(Buffer);
				Buffer = "";
				i++;
			}
		}

		Result.push_back(Forest);
		Buffer = "";

		// Mountain map 
		for (size_t i = 0; i < string(ElMountain->GetText()).length(); i++)
		{
			Buffer += ElMountain->GetText()[i];

			if (ElMountain->GetText()[i] == ' ')
				continue;
			else
				if (ElMountain->GetText()[i] == ';')
				{
					Mountain.push_back(Buffer);
					Buffer = "";
					i++;
				}
		}

		Result.push_back(Mountain);
		Buffer = "";

		// Road map 
		for (size_t i = 0; i < string(ElRoad->GetText()).length(); i++)
		{
			Buffer += ElRoad->GetText()[i];

			if (ElRoad->GetText()[i] == ' ')
				continue;
			else
				if (ElRoad->GetText()[i] == ';')
				{
					Road.push_back(Buffer);
					Buffer = "";
					i++;
				}
		}

		Result.push_back(Road);
		Buffer = "";

		// Domain map 
		for (size_t i = 0; i < string(ElDomain->GetText()).length(); i++)
		{
			Buffer += ElDomain->GetText()[i];

			if (ElDomain->GetText()[i] == ' ')
				continue;
			else
				if (ElDomain->GetText()[i] == ';')
				{
					Domain.push_back(Buffer);
					Buffer = "";
					i++;
				}
		}

		Result.push_back(Domain);
		Buffer = "";

	return Result;
}

// Map.xml (AI)
std::vector< XMLCaste* > XMLParser::MapAI()
{
	//
	TiXmlElement* ElMap = GetDataElement();
	// Loading AI block data 
	TiXmlElement* ElAI = ElMap->FirstChildElement("Game");
	TiXmlElement* ElCaste = ElAI->FirstChildElement("Caste");
	TiXmlElement* ElSettlement;

	vector< XMLCaste* > Castes;            // = Result ..
	vector< XMLSettlement* > Settlements;  // to result obj

	while (ElCaste != NULL)
	{
		// Load castes 
		unsigned int Team = 0;
		if (ElCaste->QueryUnsignedAttribute("Team", &Team) != 0)
		{
			continue;
		}
		// Load settlements 
		ElSettlement = ElCaste->FirstChildElement("Settlement");
		while (ElSettlement != NULL)
		{
			Settlements.push_back( new
				XMLSettlement(
					string(ElSettlement->Attribute("Name")),
					string(ElSettlement->Attribute("Type")),
					atol(ElSettlement->Attribute("Population")),
					atol(ElSettlement->Attribute("Team")),
					atof(ElSettlement->Attribute("X")),
					atof(ElSettlement->Attribute("Y"))
				) 
			);
			// Next 
			ElSettlement = ElSettlement->NextSiblingElement("Settlement");
		}

		// Next 
		Castes.push_back( new XMLCaste(Team, Settlements));
		Settlements.clear();
		ElCaste = ElCaste->NextSiblingElement("Caste");
	}
	return Castes;
}

// Data\Language
Language* XMLParser::LoadLanguage(string Type)
{
	//
	setlocale(LC_ALL, "");

	TiXmlElement* ElLanguage = GetDataElement();
	Language* Language1 = new Language(Type);
	TiXmlElement* ElText = ElLanguage->FirstChildElement("Text");

	string Id = "", Text = "";
	while (ElText != NULL)
	{
		// Load ElText 
		if (ElText->Attribute("Id"))
			Id = ElText->Attribute("Id");

		if ( ElText->GetText() )
		{
			Text = ElText->GetText();
		}

		// Next 
		Language1->Texts.push_back(new LanguageText(Id, Text));
		Id = ""; Text = "";
		ElText = ElText->NextSiblingElement("Text");
	}

	return Language1;
}

// Search settings 
void XMLParser::SearchSettings(bool Main, string& Version, string& Title, size_t& Width, size_t& Height, size_t& FramerateLimit, size_t& WindowMode, bool& VerticalSync, string& LanguageType, int &Soundtrack, int &SoundEffects)
{
	//
	TiXmlElement* Data = GetDataElement();
	TiXmlElement* El = Data->FirstChildElement("Setting");

	while (El != NULL)
	{
		string Name = El->Attribute("Name");

		if (Name == "Version" && Main == true)
			Version = El->GetText();
		if (Name == "Title" && Main == true)
			Title = El->GetText();

		if (Name == "Size")
		{
			//
			string Buffer = "";
			for (size_t i = 0; i < string(El->GetText()).length(); i++)
			{
				if (string(El->GetText())[i] == 'x' || i+1 == string(El->GetText()).length())
				{
					if (i+1 == string(El->GetText()).length())
					{
						Buffer += string(El->GetText())[i];
						Height = atoi(Buffer.c_str());
						Buffer = "";
					}
					else
					{
						Width = atoi(Buffer.c_str());
						Buffer = "";
					}
				}
				else
					Buffer += string(El->GetText())[i];
			}
			//
		}
		if (Name == "FramerateLimit")
			FramerateLimit = atoi(El->GetText());
		if (Name == "WindowMode")
			WindowMode = atoi(El->GetText());
		if (Name == "VerticalSync")
			VerticalSync = atoi(El->GetText());

		if (Name == "Language")
			LanguageType = El->GetText();

		if (Name == "Soundtrack")
			Soundtrack = atoi(El->GetText());
		if (Name == "SoundEffects")
			SoundEffects = atoi(El->GetText());

		El = El->NextSiblingElement("Setting");
	}
}

// Save file 
void XMLParser::SaveFile(string Path, vector<string> Data)
{
	File* File1 = new File(Path);
	File1->DataToXMLFile(Data);
}