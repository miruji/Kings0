#include "../Window.h"

void Window::UIEventSound(string Event)
{
	if (Event == "GameSettlementMarket")
		Audio1->PlaySound1("Market0");
	else
	if (Event == "GameSettlementTavern")
	{
		size_t Random = GetRandomNumber(0, 2);
		if (Random == 0)
			Audio1->PlaySound1("Tavern0");
		else
		if (Random == 1)
			Audio1->PlaySound1("Tavern1");
		else
		if (Random == 2)
			Audio1->PlaySound1("Tavern2");
	}
	else
	if (Event == "GameSettlementElder")
	{
		size_t Random = GetRandomNumber(0, 2);
		if (Random == 0)
			Audio1->PlaySound1("Elder0");
		else
		if (Random == 1)
			Audio1->PlaySound1("Elder1");
		else
		if (Random == 2)
			Audio1->PlaySound1("Elder2");
	}
}