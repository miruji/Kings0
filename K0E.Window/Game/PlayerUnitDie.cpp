#include "../Window.h"

void Window::PlayerUnitDie()
{
	cout << "!!! PLAYER UNIT DIE: X: " << Game1->Player1->StartX << ", Y: " << Game1->Player1->StartY << endl;
	MapPointer1->SetXY(Game1->Player1->X, Game1->Player1->Y);
	UI_UpdateMapPointer(true);

	Game1->Player1->Die = true;
	Game1->Player1->SetPosition(Game1->Player1->StartX, Game1->Player1->StartY);

	if (GetRandomNumber(0,1))
		Audio1->PlaySound1("UnitDie0");
	else
		Audio1->PlaySound1("UnitDie1");
}