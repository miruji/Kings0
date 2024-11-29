#include "../Window.h"

// Game: Update attitude status 
void Window::UpdateAttitudeStatus()
{
	for (size_t i = 0; i < Game1->Castes.size(); i++)
	for (size_t j = 0; j < Game1->Castes[i]->Attitude.size(); j++)
	if (i != j)
	{
		//
		if (Game1->Castes[i]->Attitude[j] >= 35)
		{
			Game1->Castes[i]->Status[j] = 2;
			Game1->Castes[j]->Status[i] = 2;
			Game1->Castes[j]->Attitude[i] == Game1->Castes[i]->Attitude[j];
		}
		else
		if (Game1->Castes[i]->Attitude[j] >= 20)
		{
			Game1->Castes[i]->Status[j] = 1;
			Game1->Castes[j]->Status[i] = 1;
			Game1->Castes[j]->Attitude[i] == Game1->Castes[i]->Attitude[j];
		}
		else
		{
			Game1->Castes[i]->Status[j] = 0;
			Game1->Castes[j]->Status[i] = 0;
			Game1->Castes[j]->Attitude[i] == Game1->Castes[i]->Attitude[j];
		}
	}
	//
}