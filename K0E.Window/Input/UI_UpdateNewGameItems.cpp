#include "../Window.h"

void Window::UI_UpdateNewGameItems()
{
	//
	vector<size_t> NoTeams;
	for (size_t i = 0; i < 10; i++)
	{
		if (NewGamePlayers.size() > i && NewGamePlayers[i].Num == i)
		{
			//cout << "Yes: " << i << endl;
			continue;
		}
		else
		{
			//cout << "No: " <<  i << endl;
			UI_HideByImageId("Item"+to_string(i));
		}
		//
	}
}