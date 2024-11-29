#include "../Window.h"

string CutMinimizeEnd(string Data)
{
	string Result = "";
	for (size_t i = Data.length(); i > Data.length()-9; i--)
		Data[i] = ' ';
	for (size_t i = 0; i < Data.length(); i++)
	{
		if (Data[i] != ' ')
			Result += Data[i];
	}
	return Result;
}

bool Window::Contol_Tab(bool Keyboard)
{
	bool Result = true;

	if (Event.key.code == sf::Keyboard::Tab || !Keyboard)
	{
		string Name = "";
		size_t Num = 0;
		for (size_t i = 0; i < UI1->GetDrawUIBlocks().size(); i++)
		{
			Name = UI1->GetDrawUIBlocks()[i]->GetName();
			Name.erase(Name.begin()+9, Name.end());
			if (Name == "LeftBlock")
			{
				Num = i;
				break;
			}
		}
		//
		if (Num)
		{
			Name = UI1->GetDrawUIBlocks()[Num]->GetName();
			if (LeftBlockMinimize)
			{
				UIEvent('|', CutMinimizeEnd(Name), false, Num, false);
			}
			else
			{
				UIEvent('|', Name+"Minimize", false, Num, false);
			}
		}
	}
	else
		Result = false;

	return Result;
}