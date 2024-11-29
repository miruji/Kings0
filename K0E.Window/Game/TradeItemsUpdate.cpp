#include "../Window.h"

// Replace AI->Castes->Settlemet Items for now
void Window::TradeItemsUpdate()
{
	//
	for (size_t i = 0; i < Game1->Castes.size(); i++)
	for (size_t j = 0; j < Game1->Castes[i]->Settlements.size(); j++)
	{
		//
		size_t RandomItems = GetRandomNumber(2, 16);
		RandomItems = RandomItems + GetRandomNumber(0, 16-RandomItems);

		Game1->Castes[i]->Settlements[j].ClearItems();

		//
		for (size_t q = 0; q < RandomItems; q++)
		{
			//
			string ItemNameBuffer = "";
			while (true)
			{
				size_t Buffer = GetRandomNumber(0, Game1->Items.size()-1);

				ItemNameBuffer = Game1->Items[Buffer]->GetName();
				if (ItemNameBuffer != "None")
					break;
			}
			// Add new item 
			Game1->Castes[i]->Settlements[j].AddItem(ItemNameBuffer, Game1->Items);
		}
		//
	}
	//
}