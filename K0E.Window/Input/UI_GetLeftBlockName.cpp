#include "../Window.h"

// UI: Get left block name 
size_t Window::UI_GetLeftBlockName()
{
	// Search id 
	size_t Num = 0;
	for (size_t i = 0; i < UI1->GetDrawUIBlocks().size(); i++)
	{
		string BlockName = UI1->GetDrawUIBlocks()[i]->GetName();
		string Buffer = "";

		if (BlockName.length() >= 9)
		for (size_t j = 0; j < 9; j++)
		{
			Buffer += BlockName[j];
		}
		if (Buffer == "LeftBlock")
			Num = i;

	}

	// ... 
	return Num;
}
