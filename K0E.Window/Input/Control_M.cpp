#include "../Window.h"

// Control: [Marks show / hide] 
bool Window::Control_M(bool Keyboard)
{
	// ... 
	bool Result = true;

	if (Event.key.code == sf::Keyboard::M || Keyboard == false)
	{
		// ... 
		if (NoEntryMap1->Drawing == false)
		{
			NoEntryMap1->Drawing = true;
		}
		else
		{
			NoEntryMap1->Drawing = false;
		}
	}
	else
		Result = false;

	return Result;
}