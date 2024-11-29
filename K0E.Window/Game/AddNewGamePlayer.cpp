#include "../Window.h"

void Window::AddNewGamePlayer()
{
	if (NewGamePlayers[NewGameUnit].Num == -1)
		NewGamePlayers[NewGameUnit].Num = NewGameUnit;

	UpdateNewGamePlayer();
} 