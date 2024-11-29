#include "../Window.h"

// UI: Show all elements 
void Window::ShowAllElements(size_t Num)
{
	// UI_Image 
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[Num]->UI_Image.size(); i++)
		UI1->GetDrawUIBlocks()[Num]->UI_Image[i]->Show = true;
	// UI_Gif 
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[Num]->UI_Gif.size(); i++)
		UI1->GetDrawUIBlocks()[Num]->UI_Gif[i]->Show = true;
	// UI_ListBox 
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[Num]->UI_SlideInt.size(); i++)
		UI1->GetDrawUIBlocks()[Num]->UI_SlideInt[i]->Show = true;
	// UI_CheckBox 
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[Num]->UI_CheckBox.size(); i++)
		UI1->GetDrawUIBlocks()[Num]->UI_CheckBox[i]->Show = true;
	// UI_ComboBox 
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[Num]->UI_ComboBox.size(); i++)
		UI1->GetDrawUIBlocks()[Num]->UI_ComboBox[i]->Show = true;
	// UI_Input 
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[Num]->UI_Input.size(); i++)
		UI1->GetDrawUIBlocks()[Num]->UI_Input[i]->Show = true;
	// UI_TextWrapped 
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[Num]->UI_TextWrapped.size(); i++)
		UI1->GetDrawUIBlocks()[Num]->UI_TextWrapped[i]->Show = true;
	// UI_Button 
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[Num]->UI_Button.size(); i++)
		UI1->GetDrawUIBlocks()[Num]->UI_Button[i]->Show = true;
	// UI_Text 
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[Num]->UI_Text.size(); i++)
		UI1->GetDrawUIBlocks()[Num]->UI_Text[i]->Show = true;
}