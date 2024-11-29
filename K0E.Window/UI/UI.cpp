#include "UI.h"

// Constructor 
UI::UI(size_t WindowWidth, size_t WindowHeight, string Version, LanguagePack* LanguagePack1, Console* Console1)
{
	// Set window W & H 
	this->WindowWidth = WindowWidth;
	this->WindowHeight = WindowHeight;
	ResizeWidth = float(WindowWidth) / 1280.0f;
	ResizeHeight = float(WindowHeight) / 720.0f;
	//cout << "RESIZE: " << ResizeWidth << " | " << ResizeHeight << endl;

	// Set language pack 
	this->LanguagePack1 = LanguagePack1;

	// Set font 
	//Config.MergeMode = true;
	//Font = ImGui::GetIO().Fonts->AddFontFromFileTTF("Data\\Fonts\\Pixels.ttf", FontSize, &Config);
	FontSize = 14 * ResizeWidth;
	ImGui::GetIO().Fonts->Clear();
	ImGui::GetIO().Fonts->AddFontFromFileTTF("Data\\Fonts\\Font.ttf", 14*ResizeWidth, NULL,
		ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
	ImGui::GetIO().FontDefault = ImGui::GetIO().Fonts->Fonts[0];
	ImGui::GetIO().Fonts->AddFontFromFileTTF("Data\\Fonts\\Font.ttf", 26*ResizeWidth, NULL,
		ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());

	//cout << ImGui::GetIO().Fonts->Fonts.size() << endl;
	ImGui::SFML::UpdateFontTexture();
	//cout << Font->IsLoaded() << endl;

	// XML Parser
	cout << "> UI: " << endl;
	cout << "  ";

	XMLParser* XMLParser1 = new XMLParser();
	XMLParser1->LoadDocument("Data\\UI\\UI.xml", Console1);

	// NewGame.xml
	TiXmlElement* UI1 = XMLParser1->GetDataElement();
	ParseUI(UI1, Console1);

	for (size_t i = 0; i < UIBlocks.size(); i++)
	if (UIBlocks[i]->GetName() == "MainMenu0")
		DrawUIBlocks.push_back(UIBlocks[i]);
}

// Parse UI init 
void UI::ParseUI(TiXmlElement* Data, Console* Console1)
{
	// UI block names 
	TiXmlElement* Element = Data->FirstChildElement("Link");
	
	while (Element != NULL)
	{
		BlockNames.push_back( ParseUINames(Element->Attribute("Src")) );

		Element = Element->NextSiblingElement("Link");
	}

	// Parse UI Files 
	ParseUIFiles(Console1);
}

// Parse text 
std::string UI::ParseUINames(string Text)
{
	// ... 
	std::string Result;
	const char Separator = '.';

	for (size_t i = 0; i < Text.length(); i++)
	{
		// ... 
		if (Text[i] == ' ')
			continue;
		else
		if (Text[i] == Separator)
			break;
		else
			Result += Text[i];
	}

	// ... 
	return Result;
}

// Parse UI Files
void UI::ParseUIFiles(Console* Console1)
{
	// ... 
	XMLParser* XMLParser1 = new XMLParser();

	for (size_t i = 0; i < BlockNames.size(); i++)
	{
		cout << "  ";
		
		if ( XMLParser1->LoadDocument("Data\\UI\\"+BlockNames[i]+".xml", Console1) )
		{
			TiXmlElement* El = XMLParser1->GetDataElement()->FirstChildElement("Window");
			
			float Width = 0.0f;
			if ( El->Attribute("Width") )
			{
				if (atoi(El->Attribute("Width")) == 0)
				{
					Width = WindowWidth;
				}
				else
					Width = atof( El->Attribute("Width") )*ResizeWidth;
			}

			float Height = 0.0f;
			if ( El->Attribute("Height") )
			{
				if (atoi(El->Attribute("Height")) == 0)
				{
					Height = WindowHeight;
				}
				else
					Height = atof( El->Attribute("Height") )*ResizeHeight;
			}

			float X = 0.0f; 
			if ( El->Attribute("X")[0] == '|' )
			{
				string Text = El->Attribute("X");
				Text.erase(Text.begin());
				X = WindowWidth-(Width*ResizeWidth)+(atof(Text.c_str())*ResizeWidth);
			}
			else
			if ( El->Attribute("X")[0] >= '0' && El->Attribute("X")[0] <= '9' )
			{ 
				X = atof( El->Attribute("X") )*ResizeWidth;
			}
			else
			{
				if ( string(El->Attribute("X")) == "Center" )
					X = WindowWidth/2 - Width/2;
				else
				if ( string(El->Attribute("X")) == "Maximum" )
					X += WindowWidth - Width;
			}

			float Y = 0.0f; 
			if ( El->Attribute("Y")[0] == '|' )
			{
				string Text = El->Attribute("Y");
				Text.erase(Text.begin());
				Y = WindowHeight-(Height*ResizeHeight)+(atof(Text.c_str())*ResizeWidth);
			}
			else
			if ( El->Attribute("Y")[0] >= '0' && El->Attribute("Y")[0] <= '9' )
			{ 
				Y = atof( El->Attribute("Y") )*ResizeHeight;
			}
			else
			{
				if ( string(El->Attribute("Y")) == "Center" )
					Y = WindowHeight/2 - Height/2;
				else
				if ( string(El->Attribute("Y")) == "Maximum" )
					Y += WindowHeight - Height;
			}

			size_t Layer = 0;
			if ( El->Attribute("Layer") )
			{
				Layer = atoi( El->Attribute("Layer") );
				//cout << BlockNames[i] << " : " << Layer << endl;
			}

			size_t FixedPosition = 0;
			if ( El->Attribute("FixedPosition") )
			{
				FixedPosition = atoi( El->Attribute("FixedPosition") );
			}

			ParseUIFile(BlockNames[i], XMLParser1->GetDataElement(), X, Y, Width, Height, Layer, FixedPosition);
		}
	}
}

// Parse UI File
void UI::ParseUIFile(string Name, TiXmlElement* Data, float X, float Y, float Width, float Height, size_t Layer, bool FixedPosition)
{
	//
	UIBlocks.push_back( new UIBlock(Name, X, Y, Width, Height, Layer, FixedPosition) );

	//
	size_t Num = UIBlocks.size() - 1;

	ParseImage      (Name, Data, Num);
	ParseGif        (Name, Data, Num);
	ParseSlideInt(Name, Data, Num);
	ParseCheckBox   (Name, Data, Num);
	ParseComboBox   (Name, Data, Num);
	ParseInput      (Name, Data, Num);
	ParseTextWrapped(Name, Data, Num);
	ParseButton     (Name, Data, Num);
	ParseText       (Name, Data, Num);
}

//
void UI::ParseImage(string Name, TiXmlElement* Data, size_t Num)
{
	//
	TiXmlElement* El = Data->FirstChildElement("Image");

	// Cycle 
	string Id = "", ImageId = "";
	float X = 0.0f, Y = 0.0f, W = 0.0f, H = 0.0f;

	while ( El != NULL )
	{
		// # Id 
		if ( El->Attribute("Id") )
		{
			Id = El->Attribute("Id");
		}
		// # Image id
		if ( El->Attribute("ImageId") )
		{
			ImageId = El->Attribute("ImageId");

			if (UIBlocks.size() >= Num)
			for (size_t i = 0; i < UIBlocks[Num]->UI_Image.size(); i++)
			if (UIBlocks[Num]->UI_Image[i]->GetBlockName() == Name)
			{
				//
				if (UIBlocks[Num]->UI_Image[i]->GetId() == ImageId)
				{
					X = UIBlocks[Num]->UI_Image[i]->GetXY().x;
					Y = UIBlocks[Num]->UI_Image[i]->GetXY().y;
					break;
				}
			}
			//
		}

		// # W 
		if ( El->Attribute("W")[0] >= '0' && El->Attribute("W")[0] <= '9' )
		{ 
			El->QueryFloatAttribute("W", &W);
			//W = W * ResizeWidth;
		}
		else
		{
			if ( string(El->Attribute("W")) == "Center" )
				W = WindowWidth/2;
			else
			if ( string(El->Attribute("W")) == "Maximum" )
				W = WindowWidth;
		}
		// # H 
		if ( El->Attribute("H")[0] >= '0' && El->Attribute("H")[0] <= '9' )
		{ 
			El->QueryFloatAttribute("H", &H);
			//H = H * ResizeHeight;
		}
		else
		{
			if ( string(El->Attribute("H")) == "Center" )
				H = WindowHeight/2;
			else
			if ( string(El->Attribute("H")) == "Maximum" )
				H = WindowHeight;
		}

		// # X 
		if ( El->Attribute("X")[0] == '|' )
		{
			string Text = El->Attribute("X");
			Text.erase(Text.begin());
			X = WindowWidth-(W*ResizeWidth)+(atof(Text.c_str())*ResizeWidth);
		}
		else
		if ( (El->Attribute("X")[0] >= '0' && El->Attribute("X")[0] <= '9') || El->Attribute("X")[0] == '-' )
		{ 
			X += atof( El->Attribute("X") )*ResizeWidth;
		}
		else
		{
			if ( string(El->Attribute("X")) == "Center" )
				X += (WindowWidth/2) - (W*ResizeWidth/2);
			else
			if ( string(El->Attribute("X")) == "Maximum" )
				X += WindowWidth - W*ResizeWidth;
		}
		// # Y 
		if ( El->Attribute("Y")[0] == '|' )
		{
			string Text = El->Attribute("Y");
			Text.erase(Text.begin());
			Y = WindowHeight-(H*ResizeHeight) + (atof(Text.c_str()) * ResizeWidth);
		}
		else
		if ( (El->Attribute("Y")[0] >= '0' && El->Attribute("Y")[0] <= '9') || El->Attribute("Y")[0] == '-' )
		{ 
			Y += atof( El->Attribute("Y") )*ResizeHeight;
		}
		else
		{
			if ( string(El->Attribute("Y")) == "Center" )
				Y += (WindowHeight/2) - (H*ResizeHeight/2);
			else
			if ( string(El->Attribute("Y")) == "Maximum" )
				Y += WindowHeight - H*ResizeHeight;
		}

		// Next 
		UIBlocks[Num]->UI_Image.push_back( new UIImage(Name, Id, ImageId, El->Attribute("Src"), to_string(X), to_string(Y), to_string(W), to_string(H)) );

		Id = ""; ImageId = "";
		X = 0.0f; Y = 0.0f; W = 0.0f; H = 0.0f;

		El = El->NextSiblingElement("Image");
	}
}

//
void UI::ParseGif(string Name, TiXmlElement* Data, size_t Num)
{
	//
	TiXmlElement* El = Data->FirstChildElement("Gif");

	// Cycle 
	std::string Id = ""; string ImageId = "";
	float X = 0.0f, Y = 0.0f, W = 0.0f, H = 0.0f;
	size_t Delay = 0;

	while ( El != NULL )
	{
		// # Id 
		if ( El->Attribute("Id") )
		{
			Id = El->Attribute("Id");
		}
		// # Image id
		if ( El->Attribute("ImageId") )
		{
			ImageId = El->Attribute("ImageId");

			if (UIBlocks.size() >= Num)
			for (size_t i = 0; i < UIBlocks[Num]->UI_Image.size(); i++)
			if (UIBlocks[Num]->UI_Image[i]->GetBlockName() == Name)
			{
				//
				if (UIBlocks[Num]->UI_Image[i]->GetId() == ImageId)
				{
					X = UIBlocks[Num]->UI_Image[i]->GetXY().x;
					Y = UIBlocks[Num]->UI_Image[i]->GetXY().y;
					break;
				}
			}
			//
		}

		// # W 
		if ( El->Attribute("W")[0] >= '0' && El->Attribute("W")[0] <= '9' )
		{ 
			El->QueryFloatAttribute("W", &W);
		}
		else
		{
			if ( string(El->Attribute("W")) == "Center" )
				W = WindowWidth/2;
			else
			if ( string(El->Attribute("W")) == "Maximum" )
				W = WindowWidth;
		}
		// # H 
		if ( El->Attribute("H")[0] >= '0' && El->Attribute("H")[0] <= '9' )
		{ 
			El->QueryFloatAttribute("H", &H);
		}
		else
		{
			if ( string(El->Attribute("H")) == "Center" )
				H = WindowWidth/2;
			else
			if ( string(El->Attribute("H")) == "Maximum" )
				H = WindowWidth;
		}

		// # X 
		if ( (El->Attribute("X")[0] >= '0' && El->Attribute("X")[0] <= '9') || El->Attribute("X")[0] == '-' )
		{ 
			X += atof( El->Attribute("X") )*ResizeWidth;
		}
		else
		{
			if ( string(El->Attribute("X")) == "Center" )
				X += WindowWidth/2 - W/2;
			else
			if ( string(El->Attribute("X")) == "Maximum" )
				X += WindowWidth - W;
		}
		// # Y 
		if ( (El->Attribute("Y")[0] >= '0' && El->Attribute("Y")[0] <= '9') || El->Attribute("Y")[0] == '-' )
		{ 
			Y += atof( El->Attribute("Y") )*ResizeHeight;
		}
		else
		{
			if ( string(El->Attribute("Y")) == "Center" )
				Y += WindowHeight/2 - H/2;
			else
			if ( string(El->Attribute("Y")) == "Maximum" )
				Y += WindowHeight - H;
		}

		// # Delay 
		if ( El->Attribute("Delay") )
		{
			Delay = atoi(El->Attribute("Delay"))/2;
		}

		// Next 
		UIBlocks[Num]->UI_Gif.push_back( new UIGif(Name, Id, El->Attribute("Src"), Delay, to_string(X), to_string(Y), to_string(W), to_string(H)) );

		Id = ""; ImageId = "";
		X = 0.0f; Y = 0.0f; W = 0.0f; H = 0.0f;
		Delay = 0;

		El = El->NextSiblingElement("Gif");
	}
}

//
void UI::ParseSlideInt(string Name, TiXmlElement* Data, size_t Num)
{
	//
	TiXmlElement* El = Data->FirstChildElement("SlideInt");

	// Cycle 
	string Id = "", ImageId = "";
	float X = 0.0f, Y = 0.0f, W = 0.0f;
	int Min = 0, Max = 1;

	while (El != NULL)
	{
		// # Id 
		if ( El->Attribute("Id") )
		{
			Id = El->Attribute("Id");
		}
		// # Image id
		if ( El->Attribute("ImageId") )
		{
			ImageId = El->Attribute("ImageId");

			if (UIBlocks.size() >= Num)
			for (size_t i = 0; i < UIBlocks[Num]->UI_Image.size(); i++)
			if (UIBlocks[Num]->UI_Image[i]->GetBlockName() == Name)
			{
				//
				if (UIBlocks[Num]->UI_Image[i]->GetId() == ImageId)
				{
					X = UIBlocks[Num]->UI_Image[i]->GetXY().x;
					Y = UIBlocks[Num]->UI_Image[i]->GetXY().y;
					break;
				}
			}
			//
		}

		// # W 
		if ( El->Attribute("W")[0] >= '0' && El->Attribute("W")[0] <= '9' )
		{ 
			El->QueryFloatAttribute("W", &W);
		}
		else
		{
			if ( string(El->Attribute("W")) == "Center" )
				W = WindowWidth/2;
			else
			if ( string(El->Attribute("W")) == "Maximum" )
				W = WindowWidth;
		}

		// # X 
		if ( (El->Attribute("X")[0] >= '0' && El->Attribute("X")[0] <= '9') )
		{ 
			X += atof( El->Attribute("X") )*ResizeWidth;
		}
		// # Y 
		if ( (El->Attribute("Y")[0] >= '0' && El->Attribute("Y")[0] <= '9') )
		{ 
			Y += atof( El->Attribute("Y") )*ResizeHeight;
		}

		// # X 
		if ((El->Attribute("Min")[0] >= '0' && El->Attribute("Min")[0] <= '9'))
		{
			Min = atof(El->Attribute("Min"));
		}
		// # Y 
		if ((El->Attribute("Max")[0] >= '0' && El->Attribute("Max")[0] <= '9'))
		{
			Max = atof(El->Attribute("Max"));
		}

		// Next 
		UIBlocks[Num]->UI_SlideInt.push_back(new UISlideInt(Name, Id, ImageId, Min, Max, to_string(X), to_string(Y), to_string(W)));

		Id = ""; ImageId = "";
		Min = 0; Max = 1;
		X = 0.0f; Y = 0.0f; W = 0.0f;;

		El = El->NextSiblingElement("SlideInt");
	}
}
//
void UI::ParseCheckBox(string Name, TiXmlElement* Data, size_t Num)
{
	//
	TiXmlElement* El = Data->FirstChildElement("CheckBox");

	// Cycle 
	string Spec = "", ImageId = "", Text = "", CheckEvent = "";
	string X = "0.0f", Y = "0.0f";
	float XX = 0.0f, YY = 0.0f;

	while ( El != NULL )
	{
		// # CheckEvent 
		if (El->Attribute("CheckEvent"))
		{
			CheckEvent = El->Attribute("CheckEvent");
		}
		// # Spec 
		if ( El->Attribute("Spec") )
		{ 
			Spec = El->Attribute("Spec");
		}
		// # Image id
		if ( El->Attribute("ImageId") )
		{
			ImageId = El->Attribute("ImageId");

			if (UIBlocks.size() >= Num)
			{
				//
				for (size_t i = 0; i < UIBlocks[Num]->UI_Image.size(); i++)
				if (UIBlocks[Num]->UI_Image[i]->GetBlockName() == Name)
				{
					//
					if (UIBlocks[Num]->UI_Image[i]->GetId() == ImageId)
					{
						XX = UIBlocks[Num]->UI_Image[i]->GetXY().x;
						YY = UIBlocks[Num]->UI_Image[i]->GetXY().y;
						break;
					}
				}
				//
			}
		}

		// # X 
		if ( El->Attribute("X") )
		{ 
			X = to_string(atof(El->Attribute("X"))*ResizeWidth);
		}
		// # Y 
		if ( El->Attribute("Y") )
		{ 
			Y = to_string(atof(El->Attribute("Y"))*ResizeHeight);
		}

		// # Text
		if ( El->GetText() )
		{
			Text = El->GetText();
		}

		// Next 
		UIBlocks[Num]->UI_CheckBox.push_back( new UICheckBox(Name, Spec, Text, LanguagePack1, FontSize, CheckEvent, XX, X, YY, Y) );

		Spec = ""; ImageId = ""; Text = ""; CheckEvent = "";
		X = "0.0f"; Y = "0.0f";
		XX = 0.0f, YY = 0.0f;

		El = El->NextSiblingElement("CheckBox");
	}
}
//
void UI::ParseComboBox(string Name, TiXmlElement* Data, size_t Num)
{
	//
	TiXmlElement* El = Data->FirstChildElement("ComboBox");

	// Cycle 
	string Id = "", ImageId = "";
	float X = 0.0f, Y = 0.0f, Width = 0.0f;

	while ( El != NULL )
	{
		// # Id 
		if (El->Attribute("Id"))
		{
			Id = El->Attribute("Id");
		}
		// # Image id 
		if ( El->Attribute("ImageId") )
		{
			ImageId = El->Attribute("ImageId");

			if (UIBlocks.size() >= Num)
			for (size_t i = 0; i < UIBlocks[Num]->UI_Image.size(); i++)
			if (UIBlocks[Num]->UI_Image[i]->GetBlockName() == Name)
			{
				//
				if (UIBlocks[Num]->UI_Image[i]->GetId() == ImageId)
				{
					X = UIBlocks[Num]->UI_Image[i]->GetXY().x;
					Y = UIBlocks[Num]->UI_Image[i]->GetXY().y;
					break;
				}
			}
			//
		}

		// # X 
		if ( (El->Attribute("Width")[0] >= '0' && El->Attribute("Width")[0] <= '9') || El->Attribute("Width")[0] == '-' )
		{ 
			Width = atof( El->Attribute("Width") )*ResizeWidth;
		}

		// # X 
		if ( (El->Attribute("X")[0] >= '0' && El->Attribute("X")[0] <= '9') || El->Attribute("X")[0] == '-' )
		{ 
			X += atof( El->Attribute("X") )*ResizeWidth;
		}
		else
		{
			if ( string(El->Attribute("X")) == "Center" )
				X += WindowWidth/2;
			else
			if ( string(El->Attribute("X")) == "Maximum" )
				X += WindowWidth;
		}
		// # Y 
		if ( (El->Attribute("Y")[0] >= '0' && El->Attribute("Y")[0] <= '9') || El->Attribute("Y")[0] == '-' )
		{ 
			Y += atof( El->Attribute("Y") )*ResizeHeight;
		}
		else
		{
			if ( string(El->Attribute("Y")) == "Center" )
				Y += WindowHeight/2;
			else
			if ( string(El->Attribute("Y")) == "Maximum" )
				Y += WindowHeight;
		}

		// Next 
		UIBlocks[Num]->UI_ComboBox.push_back( new UIComboBox(Name, Id, ImageId, El->Attribute("Spec"), El->Attribute("Text"), LanguagePack1, to_string(X), to_string(Y), Width) );

		Id = "";  ImageId = "";
		X = 0.0f; Y = 0.0f; Width = 0.0f;

		El = El->NextSiblingElement("ComboBox");
	}
}

//
void UI::ParseInput(string Name, TiXmlElement* Data, size_t Num)
{
	//
	TiXmlElement* El = Data->FirstChildElement("Input");

	// Cycle 
	string ImageId = "", Text = "", Id = "", Type = "", Spec="";
	float X = 0.0f, Y = 0.0f, W = 0.0f, H = 0.0f;

	vector<string> OutputText;
	string Buffer = "";

	while ( El != NULL )
	{
		// # Image id
		if ( El->Attribute("ImageId") )
		{
			ImageId = El->Attribute("ImageId");

			if (UIBlocks.size() >= Num)
			for (size_t i = 0; i < UIBlocks[Num]->UI_Image.size(); i++)
			if (UIBlocks[Num]->UI_Image[i]->GetBlockName() == Name)
			{
				//
				if (UIBlocks[Num]->UI_Image[i]->GetId() == ImageId)
				{
					X = UIBlocks[Num]->UI_Image[i]->GetXY().x;
					Y = UIBlocks[Num]->UI_Image[i]->GetXY().y;
					break;
				}
			}
			//
		}

		// # W 
		if ( El->Attribute("W") )
		{ 
			W = atof(El->Attribute("W"))*ResizeWidth;
		}
		// # H
		if (El->Attribute("H"))
		{
			H = atof(El->Attribute("H"))*ResizeHeight;
		}

		// # X 
		if ( El->Attribute("X") )
		{ 
			X += atof(El->Attribute("X"))*ResizeWidth;
		}
		// # Y 
		if ( El->Attribute("Y") )
		{ 
			Y += atof(El->Attribute("Y"))*ResizeHeight;
		}

		//
		if (El->Attribute("Id"))
		{
			Id = El->Attribute("Id");
		}
		//
		if (El->Attribute("Type"))
		{
			Type = El->Attribute("Type");
		}
		//
		if (El->Attribute("Spec"))
		{
			Spec = El->Attribute("Spec");
		}

		// # Text
		if ( El->GetText() )
		{
			Text = El->GetText();
		}

		// Next 
		for (size_t i = 0; i < Text.length(); i++)
		{
			if (Text[i] == ';' || i+1 == Text.length())
			{
				if (i+1 == Text.length())
					Buffer += Text[i];
				OutputText.push_back(Buffer);
				Buffer = "";
			}
			else
				Buffer += Text[i];
		}

		UIBlocks[Num]->UI_Input.push_back( new UIInput(Name, Id, Type, Spec, OutputText, LanguagePack1, to_string(X), to_string(Y), to_string(W), to_string(H)) );

		ImageId = ""; Text = ""; Id = ""; Type = "", Spec = "";
		X = 0.0f; Y = 0.0f; W = 0.0f; H = 0.0f;
		OutputText.clear();
		Buffer = "";

		El = El->NextSiblingElement("Input");
	}
}
//
void UI::ParseTextWrapped(string Name, TiXmlElement* Data, size_t Num)
{
	//
	TiXmlElement* El = Data->FirstChildElement("TextWrapped");

	// Cycle 
	string ImageId = "", Text = "", Id = "", Type = "", Spec="";
	float X = 0.0f, Y = 0.0f, W = 0.0f, H = 0.0f;

	vector<string> OutputText;
	string Buffer = "";

	while ( El != NULL )
	{
		// # Image id
		if ( El->Attribute("ImageId") )
		{
			ImageId = El->Attribute("ImageId");

			if (UIBlocks.size() >= Num)
			for (size_t i = 0; i < UIBlocks[Num]->UI_Image.size(); i++)
			if (UIBlocks[Num]->UI_Image[i]->GetBlockName() == Name)
			{
				//
				if (UIBlocks[Num]->UI_Image[i]->GetId() == ImageId)
				{
					X = UIBlocks[Num]->UI_Image[i]->GetXY().x;
					Y = UIBlocks[Num]->UI_Image[i]->GetXY().y;
					break;
				}
			}
			//
		}

		// # W 
		if ( El->Attribute("W") )
		{ 
			W = atof(El->Attribute("W"))*ResizeWidth;
		}
		// # H
		if (El->Attribute("H"))
		{
			H = atof(El->Attribute("H"))*ResizeHeight;
		}

		// # X 
		if ( El->Attribute("X") )
		{ 
			X += atof(El->Attribute("X"))*ResizeWidth;
		}
		// # Y 
		if ( El->Attribute("Y") )
		{ 
			Y += atof(El->Attribute("Y"))*ResizeHeight;
		}

		//
		if (El->Attribute("Id"))
		{
			Id = El->Attribute("Id");
		}

		// # Text
		if ( El->GetText() )
		{
			Text = El->GetText();
		}

		// Next 
		for (size_t i = 0; i < Text.length(); i++)
		{
			if (Text[i] == ';' || i+1 == Text.length())
			{
				if (i+1 == Text.length())
					Buffer += Text[i];
				OutputText.push_back(Buffer);
				Buffer = "";
			}
			else
				Buffer += Text[i];
		}

		UIBlocks[Num]->UI_TextWrapped.push_back( new UITextWrapped(Name, Id, OutputText, LanguagePack1, to_string(X), to_string(Y), to_string(W), to_string(H)) );

		ImageId = ""; Text = ""; Id = ""; Type = "", Spec = "";
		X = 0.0f; Y = 0.0f; W = 0.0f; H = 0.0f;
		OutputText.clear();
		Buffer = "";

		El = El->NextSiblingElement("TextWrapped");
	}
}

//
void UI::ParseButton(string Name, TiXmlElement* Data, size_t Num)
{
	//
	TiXmlElement* El = Data->FirstChildElement("Button");

	// Cycle 
	string Event = "", Id = "", ImageId = "";
	float X = 0.0f, Y = 0.0f, W = 0.0f, H = 0.0f;
	bool Message = false;
	size_t Numm = 0;
	bool Resize = false;

	while ( El != NULL )
	{
		// # Num 
		if (El->Attribute("Num"))
		{
			Numm = atoi(El->Attribute("Num"));
		}
		// # Event 
		if ( El->Attribute("Event") )
		{ 
			Event = El->Attribute("Event");
		}
		// # Message 
		if ( El->Attribute("Message") )
		{
			Message = atoi(El->Attribute("Message"));
		}

		// # Id 
		if ( El->Attribute("Id") )
		{
			Id = El->Attribute("Id");
		}
		// # Image id
		if ( El->Attribute("ImageId") )
		{
			ImageId = El->Attribute("ImageId");

			if (UIBlocks.size() >= Num)
			for (size_t i = 0; i < UIBlocks[Num]->UI_Image.size(); i++)
			if (UIBlocks[Num]->UI_Image[i]->GetBlockName() == Name)
			{
				//
				if (UIBlocks[Num]->UI_Image[i]->GetId() == ImageId)
				{
					X = UIBlocks[Num]->UI_Image[i]->GetXY().x;
					Y = UIBlocks[Num]->UI_Image[i]->GetXY().y;
					break;
				}
			}
			//
		}

		// # W 
		if ( El->Attribute("W") )
		{ 
			W = atof(El->Attribute("W"))*ResizeWidth;
		}
		// # H 
		if ( El->Attribute("H") )
		{ 
			H = atof(El->Attribute("H"))*ResizeHeight;
		}

		// # X 
		if ( (El->Attribute("X")[0] >= '0' && El->Attribute("X")[0] <= '9') || El->Attribute("X")[0] == '-' )
		{ 
			X += atof( El->Attribute("X") )*ResizeWidth;
		}
		else
		{
			if ( string(El->Attribute("X")) == "Maximum" )
				X += WindowWidth - W;
		}
		// # Y 
		if ( (El->Attribute("Y")[0] >= '0' && El->Attribute("Y")[0] <= '9') || El->Attribute("Y")[0] == '-' )
		{ 
			Y += atof( El->Attribute("Y") )*ResizeHeight;
		}
		else
		{
			if ( string(El->Attribute("Y")) == "Maximum" )
				Y += WindowHeight - H;
		}

		// # resize
		if (El->Attribute("Resize"))
			Resize = atoi(El->Attribute("Resize"));

		// Next 
		UIBlocks[Num]->UI_Button.push_back( new UIButton(Name, Id, ImageId, Numm, Event, Message, El->Attribute("Src"), to_string(X), to_string(Y), to_string(W), to_string(H), Resize) );

		Event = ""; Id = ""; ImageId = "";
		X = 0.0f; Y = 0.0f; W = 0.0f; H = 0.0f;
		Message = false;
		Numm = 0;
		Resize = false;

		El = El->NextSiblingElement("Button");
	}
}

//
void UI::ParseText(string Name, TiXmlElement* Data, size_t Num)
{
	//
	TiXmlElement* El = Data->FirstChildElement("Text");

	// Cycle 
	string Spec = "", Id = "", ImageId = "",
		   Text = "", Color = "";
	string X = "0.0f", Y = "0.0f";
	float XX = 0.0f, YY = 0.0f;
	//float Size = 0.0f;

	while ( El != NULL )
	{
		// # Id 
		if (El->Attribute("Id"))
		{
			Id = El->Attribute("Id");
		}
		// # Spec 
		if ( El->Attribute("Spec") )
		{ 
			Spec = El->Attribute("Spec");
		}
		// # Image id
		if ( El->Attribute("ImageId") )
		{
			ImageId = El->Attribute("ImageId");

			if (UIBlocks.size() >= Num)
			{
				//
				for (size_t i = 0; i < UIBlocks[Num]->UI_Image.size(); i++)
				if (UIBlocks[Num]->UI_Image[i]->GetBlockName() == Name)
				{
					//
					if (UIBlocks[Num]->UI_Image[i]->GetId() == ImageId)
					{
						XX = UIBlocks[Num]->UI_Image[i]->GetXY().x;
						YY = UIBlocks[Num]->UI_Image[i]->GetXY().y;
						break;
					}
				}
				//
			}
		}

		/*
		// # Size 
		if ( El->Attribute("Size") )
		{
			Size = atof( El->Attribute("Size") );
		}
		*/

		// # Color 
		if ( El->Attribute("Color") )
		{
			Color = El->Attribute("Color");
		}

		// # X 
		if ( El->Attribute("X") )
		{ 
			X = El->Attribute("X");
		}
		// # Y 
		if ( El->Attribute("Y") )
		{ 
			Y = El->Attribute("Y");
		}

		// # Text
		if ( El->GetText() )
		{
			Text = El->GetText();
		}

		// Next 
		UIBlocks[Num]->UI_Text.push_back( new UIText(Name, Id, ImageId, Spec, Text, LanguagePack1, FontSize, Color, XX, X, YY, Y, ResizeWidth, ResizeHeight) );

		Spec = ""; Id = ""; ImageId = "";
		Text = ""; Color = "";
		X = "0.0f"; Y = "0.0f";
		XX = 0.0f, YY = 0.0f;
		//Size = 0.0f;

		El = El->NextSiblingElement("Text");
	}
}

// Get layer (link) 
size_t& UI::GetLayer()
{
	return Layer;
}

// UI Button event split 
vector< string > UI::UIEventSplit(string Event)
{
	vector< string > Result;
	string Result0(1, Event[0]);
	Result.push_back( Result0 );
	string Buffer = "";

	// ... 
	for (size_t i = 1; i < Event.length(); i++)
		Buffer += Event[i];

	Result.push_back(Buffer);
	return Result;
}

// Update IPosition 
void UI::UpdateIPosition(size_t Num)
{
	DrawUIBlocks[Num]->SetIPosition(GetRandomNumber(0, UnsignedIntLength));
}

// Set layer 
void UI::SetLayer(size_t Layer)
{
	this->Layer = Layer;
}


// Get block names (link) 
vector< string >& UI::GetBlockNames()
{
	return BlockNames;
}

// Get UI blocks (link) 
std::vector< UIBlock* >& UI::GetUIBlocks()
{
	return UIBlocks;
}

// Get draw UI blocks (link) 
std::vector< UIBlock* >& UI::GetDrawUIBlocks()
{
	return DrawUIBlocks;
}