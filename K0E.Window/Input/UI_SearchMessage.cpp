#include "../Window.h"

void Window::UI_SearchMessage()
{
	for (size_t i = UI1->GetDrawUIBlocks().size()-1; i > 0; i--)
	{
		if (UI1->GetDrawUIBlocks()[i]->GetName() == "Message")
		{
			UI1->Message = i;
			break;
		}
	}
}