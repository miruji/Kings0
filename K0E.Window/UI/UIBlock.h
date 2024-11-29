#pragma once
#include "../Macro.h"

// Class 
class K0E_Window_Api UIBlock
{
private:
	// Window X & Y and W & H 
	float X = 0.0f, Y = 0.0f,
		  Width = 0.0f, Height = 0.0f;

	// Block name 
	string Name     = "";
	// Back block name 
	string BackName = "";

	// Layer 
	size_t Layer = 0;

	// Individual id 
	size_t IndividualId = 0;

	// i Position 
	size_t IPosition = 0;

	// Main stream Font & Config 
	ImFontConfig Config;
	ImFont* Font;

public:
	// Constructor
	UIBlock(string Name, float X, float Y, float Width, float Height, size_t Layer, bool FixedPostion);
	UIBlock(void);

	// Vector of UI objects 
	vector<UIImage*>       UI_Image;
	vector<UIGif*>         UI_Gif;
	vector<UISlideInt*>    UI_SlideInt;
	vector<UICheckBox*>    UI_CheckBox;
	vector<UIComboBox*>    UI_ComboBox;
	vector<UIInput*>       UI_Input;
	vector<UITextWrapped*> UI_TextWrapped;
	vector<UIButton*>      UI_Button;
	vector<UIText*>        UI_Text;

	bool FixedPosition = false; // Fixed position ? 
	bool FirstDraw = false;     // First draw ? 

	// Get name (link) 
	string& GetName();

	// Get back name (link) 
	string& GetBackName();

	// Set new name 
	void SetName(string NewName);

	// Set new back name 
	void SetBackName(string NewBackName);

	// Get X & Y 
	ImVec2 GetXY();

	// Get W & H 
	ImVec2 GetWH();
	void SetWH(float Width, float Height);

	// Get layer (link) 
	size_t& GetLayer();

	// Set layer 
	void SetLayer(size_t Layer);

	// Set i Position 
	void SetIPosition(size_t I);

	// Get i Position (link) 
	size_t& GetIPosition();

	// Set Position 
	void SetPosition(float X, float Y);
};