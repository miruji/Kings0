#include "../Window.h"

// Set main menu 
void Window::UI_SetMainMenu()
{
	// ... 
	if (UI1->MainMenu == false)
		UI1->MainMenu = true;
	else
		UI1->MainMenu = false;

	// ... 
	UIClearDrawBlocks(false);
}