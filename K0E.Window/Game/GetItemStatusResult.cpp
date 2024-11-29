#include "../Window.h"

// Game: Get item status result 
string Window::GetItemStatusResult(Settlement Settlement1, string Type, size_t Count, size_t i)
{
	// Market 
	if (UI1->GetDrawUIBlocks()[i]->GetName() == "GameSettlementMarket")
	{
		if (Settlement1.GetItemsMarket().size() > Count)
		{
			if (Type == "Name")
				return Settlement1.GetItemsMarket()[Count]->GetName();
			else
			if (Type == "Class")
			{
				if (Settlement1.GetItemsMarket()[Count]->GetType() == ItemType::Food)
					return "Food";
				else
				if (Settlement1.GetItemsMarket()[Count]->GetType() == ItemType::Wood)
					return "Wood";
				else
					return "None";
			}
			else
			if (Type == "Cost")
				return to_string( Settlement1.GetItemsMarket()[Count]->GetCash() );
			else
			if (Type == "Size")
				return to_string( Settlement1.GetItemsMarket()[Count]->GetSize() );
			else
			if (Type == "Description")
				return "None";
		}
		else
		{
			return "None";
		}
	}
	// Tavern 
	else
	if (UI1->GetDrawUIBlocks()[i]->GetName() == "GameSettlementTavern")
	{
		if (Settlement1.GetItemsTavern().size() > Count)
		{
			if (Type == "Name")
				return Settlement1.GetItemsTavern()[Count]->GetName();
			else
			if (Type == "Class")
			{
				if (Settlement1.GetItemsTavern()[Count]->GetType() == ItemType::Army)
					return "Army";
				else
					return "None";
			}
			else
			if (Type == "Cost")
				return to_string( Settlement1.GetItemsTavern()[Count]->GetCash() );
			else
			if (Type == "Size")
				return to_string( Settlement1.GetItemsTavern()[Count]->GetSize() );
			else
			if (Type == "Description")
				return "None";
		}
		else
		{
			return "None";
		}
	}
	else
		return "None";
}