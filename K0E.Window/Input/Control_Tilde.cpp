#include "../Window.h"

// Control: [Building nums] 
bool Window::Control_Tilde(bool Keyboard)
{
	// ... 
	bool Result = true;

	if (Event.key.code == sf::Keyboard::Tilde || Keyboard == false)
	{
		// ... 
		if (BuildingNums == false)
		{
			BuildingNums = true;
			// Update build panel 
			for (size_t i = 0; i < UI1->GetDrawUIBlocks().size(); i++)
			if (UI1->GetDrawUIBlocks()[i]->GetName() == "BuildPanelMinimize")
			{
				UIEvent('@', "BuildPanel", false, i, false);
				break;
			}
		}
		else
		{
			BuildingNums = false;
			// Update build panel 
			for (size_t i = 0; i < UI1->GetDrawUIBlocks().size(); i++)
			if (UI1->GetDrawUIBlocks()[i]->GetName() == "BuildPanel")
			{
				UIEvent('@', "BuildPanelMinimize", false, i, false);
				break;
			}
		}
	}
	else
		Result = false;

	return Result;
}