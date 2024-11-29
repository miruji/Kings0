#include "../Window.h"

// Control: Numbers events 
void Window::Control_NumbersEvents(sf::Keyboard::Key Key)
{
	// Key to size_t 
	size_t Num = 0;
	if (Key == sf::Keyboard::Num0 || Key == sf::Keyboard::Numpad0)
	{
		Control_Numbers(0);
		return;
	}
	else
	if (Key == sf::Keyboard::Num1 || Key == sf::Keyboard::Numpad1)
		Num = 1;
	else
	if (Key == sf::Keyboard::Num2 || Key == sf::Keyboard::Numpad2)
		Num = 2;
	else
	if (Key == sf::Keyboard::Num3 || Key == sf::Keyboard::Numpad3)
		Num = 3;
	else
	if (Key == sf::Keyboard::Num4 || Key == sf::Keyboard::Numpad4)
		Num = 4;
	else
	if (Key == sf::Keyboard::Num5 || Key == sf::Keyboard::Numpad5)
		Num = 5;
	else
	if (Key == sf::Keyboard::Num6 || Key == sf::Keyboard::Numpad6)
		Num = 6;
	else
	if (Key == sf::Keyboard::Num7 || Key == sf::Keyboard::Numpad7)
		Num = 7;
	else
	if (Key == sf::Keyboard::Num8 || Key == sf::Keyboard::Numpad8)
		Num = 8;
	else
	if (Key == sf::Keyboard::Num9 || Key == sf::Keyboard::Numpad9)
		Num = 9;

	if (NewGame && Num != 0)
	if (MapPointer1->GetX() != Game1->Player1->X || MapPointer1->GetY() != Game1->Player1->Y || Game1->Player1->Die)
		return;

	if (Num == 0)
		return;

	//cout << "Block: " << UI1->FocusedBlockName << ", Pressed: " << Num << endl;
	UIBlock* UIBlock1 = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName];

	UIButton* UIButton1;
	for (size_t j = 0; j < UIBlock1->UI_Button.size(); j++)
	{
		UIButton1 = UIBlock1->UI_Button[j];
		if (UIButton1->GetNum() == Num)
		{
			for (size_t i = 0; i < UI1->GetDrawUIBlocks().size(); i++)
			{
				if (UI1->GetDrawUIBlocks()[i]->GetName() == UI1->UIEventSplit(UIButton1->GetEvent())[1])
				{
					//cout << "Event: " << UI1->UIEventSplit(UIButton1->GetEvent())[1] << ", i: " << i << endl;
					UI1->FocusedBlockName = i;
					UIEvent('!', "Update", false, UI1->FocusedBlockName, false);
					break;
				}
			}

			UIEvent( UI1->UIEventSplit(UIButton1->GetEvent())[0][0], UI1->UIEventSplit(UIButton1->GetEvent())[1], UIButton1->Message, UI1->FocusedBlockName, false );
		}
	}


}