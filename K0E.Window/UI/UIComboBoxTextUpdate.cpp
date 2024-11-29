#include "../Window.h"

void Window::UIComboBoxTextUpdate()
{
	UIComboBox* UIComboBox1;
	for (size_t i = 0; i < UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_ComboBox.size(); i++)
	{
		UIComboBox1 = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_ComboBox[i];
		UIComboBox1->FirstDraw = true;
		UIComboBox1->CurrentItem = "";
	}
}