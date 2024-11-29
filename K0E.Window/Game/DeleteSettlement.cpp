#include "../Window.h"

// Game: Delete settlement 
void Window::DeleteSettlement(size_t Caste1, size_t Settlement1)
{
	// Save settlement 
	Settlement Buffer = Game1->Castes[Caste1]->Settlements[Settlement1];
	Game1->Castes[Caste1]->Settlements.erase(Game1->Castes[Caste1]->Settlements.begin() + Settlement1);

	// Return resources 
	Caste* CasteBuffer = Game1->Castes[Game1->Player1->Team];
	if (Buffer.GetType() == SettlementTypes::Settlement)
	{
		return;
	}
	else
	if (Buffer.GetType() == SettlementTypes::Wall)
	{
		CasteBuffer->PreviewWood += 20;
		CasteBuffer->PreviewFood += 20;
	}
	else
	if (Buffer.GetType() == SettlementTypes::Tower)
	{
		CasteBuffer->PreviewWood += 20;
		CasteBuffer->PreviewArmy += Buffer.Army;
		CasteBuffer->PreviewFood += 20;
	}
	else
	if (Buffer.GetType() == SettlementTypes::Castle)
	{
		CasteBuffer->PreviewWood += 20;
		CasteBuffer->PreviewArmy += Buffer.Army;
		CasteBuffer->PreviewFood += 20;
	}
	else
	if (Buffer.GetType() == SettlementTypes::Barn ||
		Buffer.GetType() == SettlementTypes::Field || 
		Buffer.GetType() == SettlementTypes::Pasture ||
		Buffer.GetType() == SettlementTypes::Fisheries || 
		Buffer.GetType() == SettlementTypes::Suburb)
	{
		CasteBuffer->PreviewWood += 10;
		CasteBuffer->PreviewPopulation += 5;
		CasteBuffer->PreviewFood += 10;
	}

	// Update blocks 
	LandMap1->BlocksVector[size_t(Buffer.Y/32)][size_t(Buffer.X/32)].Settlement = 0;

	NoEntryMap1->MapVector.clear();
	NoEntryMap1->Generate(LandMap1->BlocksVector);
	RegenerateNoEntryMap();
	
	Game_InSettlement( LandMap1->BlocksVector[size_t(Game1->Player1->Y/32)][size_t(Game1->Player1->X/32)], true );

	// Left block
	UI_LeftBlockUpdate("");

	// Update spec text 
	UI1->SpecTextUpdate = true;
}