#include "../Window.h"

void Window::ConnectToIpAndPort()
{
	if (UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->GetName() == "MainMenuMultiplayer0")
	{
		//Network1->New('c');

		UIInput* Input1;
		string Ip = "", Port = "";
		for (size_t i = 0; i < UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Input.size(); i++)
		{
			Input1 = UI1->GetDrawUIBlocks()[UI1->FocusedBlockName]->UI_Input[i];
			if (Input1->Type == "Connect")
			{
				if (Input1->GetId() == "Ip")
					Ip = Input1->Text[0];
				else
				if (Input1->GetId() == "Port")
					Port = Input1->Text[0];
			}

			if (Ip != "" && Port != "")
				break;
		}

		cout << "Connect to: [" << Ip << ":" << Port << "]" << endl;
	}
}