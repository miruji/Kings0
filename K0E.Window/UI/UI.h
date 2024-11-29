#pragma once
#include "../K0E.Game/Game.h"

#include "../Macro.h"
#include "UIObject.h"
#include "UIImage.h"
#include "UIGif.h"
#include "UIInput.h"
#include "UITextWrapped.h"
#include "UIButton.h"
#include "UIText.h"
#include "UICheckBox.h"
#include "UIComboBox.h"
#include "UISlideInt.h"
#include "UIBlock.h"

// Class 
class K0E_Window_Api UI
{
private:
	// Window W & H 
	size_t WindowWidth  = 0,
		   WindowHeight = 0;

	// Version 
	string Version = "000000";

	// Path & File list 
	string UIPath = "Data\\UI\\"; // Path to UI files 
	vector< string > FileList;    // UI files list 

	// Vector of UI blocks 
	vector< UIBlock* > UIBlocks;     // Blocks 
	vector< UIBlock* > DrawUIBlocks; // Draw blocks 
	size_t Layer = 0;

	// Parse UI init 
	void ParseUI(TiXmlElement* Data, Console* Console1);  // Parse UI.xml 
	string ParseUINames(string Text);                     // Parse text 
	vector< string > BlockNames;                          // Block names 

	void ParseUIFiles(Console* Console1);                                                                                                              // Parse UI Files 
	void ParseUIFile(string Name, TiXmlElement* Data, float X, float Y, float Width, float Height, size_t Layer, bool FixedPosition); // Parse UI File 
		// UI Objects
		void ParseImage(string Name, TiXmlElement* Data, size_t Num);
		void ParseGif        (string Name, TiXmlElement* Data, size_t Num);
		void ParseSlideInt   (string Name, TiXmlElement* Data, size_t Num);
		void ParseCheckBox   (string Name, TiXmlElement* Data, size_t Num);
		void ParseComboBox   (string Name, TiXmlElement* Data, size_t Num);
		void ParseInput      (string Name, TiXmlElement* Data, size_t Num);
		void ParseTextWrapped(string Name, TiXmlElement* Data, size_t Num);
		void ParseButton     (string Name, TiXmlElement* Data, size_t Num);
		void ParseText       (string Name, TiXmlElement* Data, size_t Num);

	// Main stream Font & Config 
	ImFontConfig Config;
	ImFont* Font;

	// Font size 
	float FontSize = 24.0f;

	// Language pack 
	LanguagePack* LanguagePack1;

public:
	float ResizeWidth = 1,
		  ResizeHeight = 1;

	// Spec text update ? 
	bool SpecTextUpdate = true;

	// Flags 
	ImGuiBackendFlags Flags =
		ImGuiWindowFlags_NoResize +             // No window resize 
		ImGuiWindowFlags_NoTitleBar +           // No window title bar 
		ImGuiWindowFlags_NoCollapse +           // No minimize window 
		ImGuiWindowFlags_NoScrollbar +          // No scroll bar 
		ImGuiWindowFlags_NoScrollWithMouse +    // No scroll with mouse 
		ImGuiWindowFlags_NoBackground +         // No background
		ImGuiWindowFlags_AlwaysVerticalScrollbar;

	ImGuiBackendFlags BackgroundFlags =
		ImGuiWindowFlags_NoResize +             // No window resize 
		ImGuiWindowFlags_NoMove +               // No window move 
		ImGuiWindowFlags_NoTitleBar +           // No window title bar 
		ImGuiWindowFlags_NoCollapse +           // No minimize window 
		ImGuiWindowFlags_NoScrollbar +          // No scroll bar 
		ImGuiWindowFlags_NoScrollWithMouse +    // No scroll with mouse 
		ImGuiWindowFlags_NoBackground +         // No background
		ImGuiWindowFlags_NoBringToFrontOnFocus; // Background focus 

	// Lenght 
	size_t UnsignedIntLength = 65535;

	// Constructor
	UI(size_t WindowWidth, size_t WindowHeight, string Version, LanguagePack* LanguagePack1, Console* Console1);

	// UI Button event split
	vector< string > UIEventSplit(string Event);

	// Set layer 
	void SetLayer(size_t Layer);

	// Update IPosition 
	void UpdateIPosition(size_t Num);

	// Get block names (link) 
	vector< string >& GetBlockNames();

	// Get UI blocks (link) 
	vector< UIBlock* >& GetUIBlocks();

	// Get draw UI blocks (link) 
	vector< UIBlock* >& GetDrawUIBlocks();

	// Get layer (link) 
	size_t& GetLayer();

	// Focused block name 
	size_t FocusedBlockName = 0;

	// MainMenu ? 
	bool MainMenu = true;

	// Message ? 
	size_t Message = 0;

	// Drawing ? 
	bool Drawing = true;
};