#include "../Window.h"

void Window::UI_HideByImageId(string Id)
{
	UIImage* Image1;
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Image.size(); i++)
	{
		Image1 = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Image[i];
		if (Image1->GetId() == Id || Image1->GetImageId() == Id)
			Image1->Show = false;
	}
	//
	UIButton* Button1;
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Button.size(); i++)
	{
		Button1 = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Button[i];
		if (Button1->GetImageId() == Id)
			Button1->Show = false;
	}
	//
	UIComboBox* ComboBox1;
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_ComboBox.size(); i++)
	{
		ComboBox1 = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_ComboBox[i];
		if (ComboBox1->GetImageId() == Id)
			ComboBox1->Show = false;
	}
	//
	UIText* Text1;
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Text.size(); i++)
	{
		Text1 = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Text[i];
		if (Text1->GetImageId() == Id)
			Text1->Show = false;
	}
}