#include "../Window.h"

void Window::UI_UpdateNewGameMapImage()
{
	size_t CurrentWindow = UI1->FocusedBlockName;

	UIImage* UIImage1;
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[CurrentWindow]->UI_Image.size(); i++)
	{
		UIImage1 = UI1->GetDrawUIBlocks()[CurrentWindow]->UI_Image[i];
		string Buffer2 = UIImage1->GetId();
		if (Buffer2 == "Map")
		{
			string Src = "Data\\Maps\\Preview\\"+CurrentMapName+".png";
			ifstream fin(Src);
			if (fin.is_open())
			{
				UIImage1->LoadTextureToSprite(Src, "189", "189");
			}
			else
			{
				UIImage1->LoadTextureToSprite("Data\\Textures\\UI\\None.png", "189", "189");
			}
			
			break;
		}
		//
	}
}