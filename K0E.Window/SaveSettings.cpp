#include "Window.h"

// Save settings 
void Window::SaveSettings() 
{
	//
	XMLParser* XMLParser1 = new XMLParser();
	// Create data 
	string Path = "Data\\Settings\\Custom";
	remove("Data\\Settings\\Custom.xml");

	vector<string> Data;
	Data.push_back("<?xml version=\"1.0\" encoding=\"utf-8\"?>");
	Data.push_back("<Data>");
	if (WindowMode == 1)
		Data.push_back("	<Setting Name=\"Size\">"+to_string(VideoModes[0].width)+"x"+to_string(VideoModes[0].height)+"</Setting>");
	else
	{
		if (NewWidth && NewHeight)
			Data.push_back("	<Setting Name=\"Size\">"+to_string(NewWidth)+"x"+to_string(NewHeight)+"</Setting>");
		else
			Data.push_back("	<Setting Name=\"Size\">"+to_string(Width)+"x"+to_string(Height)+"</Setting>");
	}
	Data.push_back("	<Setting Name=\"WindowMode\">"+to_string(WindowMode)+"</Setting>");
	Data.push_back("	<Setting Name=\"VerticalSyns\">"+to_string(size_t(VerticalSync))+"</Setting>");
	Data.push_back("	<Setting Name=\"FramerateLimit\">"+to_string(FramerateLimit)+"</Setting>");
	Data.push_back("");
	Data.push_back("	<Setting Name=\"Soundtrack\">"+to_string(Audio1->Soundtrack)+"</Setting>");
	Data.push_back("	<Setting Name=\"SoundEffects\">"+to_string(Audio1->SoundEffects)+"</Setting>");
	Data.push_back("");
	Data.push_back("	<Setting Name=\"Language\">"+LanguagePack1->GetLanguageType()+"</Setting>");
	Data.push_back("</Data>");

	// Save 
	XMLParser1->SaveFile(Path, Data);
}