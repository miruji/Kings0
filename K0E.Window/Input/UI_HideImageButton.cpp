#include "../Window.h"

// UI: Hide image button 
void Window::UI_HideImageButton(string BlockName, string ImageId)
{
	// ... 
	size_t BlockNum = 0;
	for (size_t i = 0; i < UI1->GetDrawUIBlocks().size(); i++)
	{
		if (UI1->GetDrawUIBlocks()[i]->GetName() == BlockName)
		{
			BlockNum = i;
			break;
		}
	}

	// ... 
	vector<UIImage*> UIImages = UI1->GetDrawUIBlocks()[BlockNum]->UI_Image;
	for (size_t i = 0; i < UIImages.size(); i++)
	{
		if ( UIImages[i]->GetId() == ImageId )
		{
			UIImages[i]->Show = false;
		}
	}
	vector<UIButton*> UIButtons = UI1->GetDrawUIBlocks()[BlockNum]->UI_Button;
	for (size_t i = 0; i < UIButtons.size(); i++)
	{
		if ( UIButtons[i]->GetImageId() == ImageId )
		{
			UIButtons[i]->Show = false;
		}
	}
}