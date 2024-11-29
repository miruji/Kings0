#include "../Window.h"

void Window::KickNewGamePlayer()
{
	if (NewGamePlayers[NewGameUnit].Num > 0)
		NewGamePlayers[NewGameUnit].Num = -1;

	UpdateNewGamePlayer();
}