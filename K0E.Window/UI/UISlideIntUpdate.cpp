#include "../Window.h"

void Window::UISlideIntUpdate(string Name)
{
	UISlideInt* UISlideInt1;
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_SlideInt.size(); i++)
	{
		UISlideInt1 = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_SlideInt[i];
		if (Name == "Soundtrack")
		{
			UISlideInt1->Slider = Audio1->Soundtrack;
		}
		if (Name == "SoundEffects")
		{
			UISlideInt1->Slider = Audio1->SoundEffects;
		}
	}
}