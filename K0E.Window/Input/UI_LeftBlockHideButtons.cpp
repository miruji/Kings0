#include "../Window.h"

void Window::UI_LeftBlockHideButtons()
{
	size_t BlockNum = 0;
	for (size_t i = 0; i < UI1->GetDrawUIBlocks().size(); i++)
	{
		string Name = UI1->GetDrawUIBlocks()[i]->GetName();
		Name.erase(Name.begin()+9, Name.end());
		if (Name == "LeftBlock")
		{
			BlockNum = i;
			break;
		}
	}
	if (LeftBlockMinimize == false)
		UI1->GetDrawUIBlocks()[BlockNum]->SetWH(192*UI1->ResizeWidth, UI1->GetDrawUIBlocks()[BlockNum]->GetWH().y);
	else
		UI1->GetDrawUIBlocks()[BlockNum]->SetWH(54*UI1->ResizeWidth, UI1->GetDrawUIBlocks()[BlockNum]->GetWH().y);
	vector<UIText*> UITexts = UI1->GetDrawUIBlocks()[BlockNum]->UI_Text;
	for (size_t i = 0; i < UITexts.size(); i++)
	{
		if (UITexts[i]->GetId() == "MapPointer")
		{
			UITexts[i]->Show = false;
			//break;
		}
	}
	vector<UIImage*> UIImages = UI1->GetDrawUIBlocks()[BlockNum]->UI_Image;
	for (size_t i = 0; i < UIImages.size(); i++)
	{
		if (UIImages[i]->GetId() == "Window")
		{
			string Name = "Data\\Textures\\UI\\"+UI1->GetDrawUIBlocks()[BlockNum]->GetName()+"1.png";
			UIImages[i]->LoadTextureToSprite(Name, to_string(UIImages[i]->GetWH().x), to_string(UIImages[i]->GetWH().y));
			break;
		}
	}
	vector<UIButton*> UIButtons = UI1->GetDrawUIBlocks()[BlockNum]->UI_Button;
	for (size_t i = 0; i < UIButtons.size(); i++)
	{
		if (UIButtons[i]->GetNum() != 0)
			UIButtons[i]->Show = false;
	}
}