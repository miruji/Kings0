#include "../Window.h"

// Update combo boxs current items 
void Window::UI_UpdateComboBoxsCurrentItems(string Block) {

    // Update ComboBoxs current items 
    if (Block == "")
    {
        for (size_t i = 0; i < UI1->GetUIBlocks().size(); i++)
        for (size_t j = 0; j < UI1->GetUIBlocks()[i]->UI_ComboBox.size(); j++)
        {
            UI1->GetUIBlocks()[i]->UI_ComboBox[j]->CurrentItem = UI1->GetUIBlocks()[i]->UI_ComboBox[j]->BasicCurrentItem;
        }
    }
    else
    {
        for (size_t j = 0; j < UI1->GetUIBlocks()[atoi(Block.c_str())]->UI_ComboBox.size(); j++)
        {
            UI1->GetUIBlocks()[atoi(Block.c_str())]->UI_ComboBox[j]->CurrentItem = UI1->GetUIBlocks()[atoi(Block.c_str())]->UI_ComboBox[j]->BasicCurrentItem;
        }
    }
}