#include "../Window.h"

// Game: Set new caste attitude
void Window::SetNewCasteAttitude(size_t Caste, char Type, int NewAttitude)
{
	// ... 
	if (Game1->Castes[Game1->Player1->Team]->PreviewDiploPoints-5 < 0)
	{
		NeedResources = "5D";
		return;
	}

	// ... 
	if (Type == '+')
	{
		if (Game1->Castes[Caste]->Attitude[Game1->Player1->Team]+NewAttitude < 55)
		{
			Game1->Castes[Game1->Player1->Team]->Attitude[Caste] += NewAttitude;
			Game1->Castes[Caste]->Attitude[Game1->Player1->Team] += NewAttitude;
			Game1->Castes[Game1->Player1->Team]->PreviewDiploPoints -= 5;
		}
	}
	else
	if (Type == '-')
	{
		if (Game1->Castes[Caste]->Attitude[Game1->Player1->Team]-NewAttitude >= 0 && Game1->Castes[Caste]->Attitude[Game1->Player1->Team]-NewAttitude < 55)
		{
			Game1->Castes[Game1->Player1->Team]->Attitude[Caste] -= NewAttitude;
			Game1->Castes[Caste]->Attitude[Game1->Player1->Team] -= NewAttitude;
			Game1->Castes[Game1->Player1->Team]->PreviewDiploPoints -= 5;
		}
	}
	else
		return;

	// ... 
	UpdateAttitudeStatus();
}