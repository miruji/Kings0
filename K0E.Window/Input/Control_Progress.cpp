#include "../Window.h"

// Control: [Enter or S or middle mouse] 
void Window::Control_Progress()
{
	// Next progress
	Game1->Progress++;

	// achievements
	if (Game1->Progress == 250) SteamAPI1->SetAchievement("Progress0"); else
	if (Game1->Progress == 750) SteamAPI1->SetAchievement("Progress1"); else
	if (Game1->Progress == 1500) SteamAPI1->SetAchievement("Progress2"); else
	if (Game1->Progress == 2500) SteamAPI1->SetAchievement("Progress3"); else
	if (Game1->Progress == 5000) SteamAPI1->SetAchievement("Progress4"); else
	if (Game1->Progress == 7500) SteamAPI1->SetAchievement("Progress5"); else
	if (Game1->Progress == 10000) SteamAPI1->SetAchievement("Progress6");

	// player staying
	Game1->Player1->Staying++;
	if (Game1->Player1->Staying == 5)
		Game1->Player1->UpdateRect(sf::IntRect(64, 0, 32, 32));
	
	// Update map water
	for (size_t i = 0; i < LandMap1->BlocksVector.size(); i++)
	for (size_t j = 0; j < LandMap1->BlocksVector[i].size(); j++)
	{
		// War Fog 
		if (LandMap1->BlocksVector[i][j].WarFog == false)
		// Optimize 
		if (LandMap1->BlocksVector[i][j].Settlement)
		if ((j >= size_t(Camera1->X/32) || Camera1->X <= 0) && (i >= size_t(Camera1->Y/32) || Camera1->Y <= 0) &&
			 j <= size_t((Camera1->X+ Camera1->W)/32) && i <= size_t((Camera1->Y+Camera1->H)/32))
		{
			//
			if (LandMap1->BlocksVector[i][j].Land == false || LandMap1->BlocksVector[i][j].River == true)
			if (LandMap1->BlocksVector[i][j].Mountain == false)
				LandMap1->BlocksVector[i][j].Update();
		}
	}

	// Update settlements items
	if (NewGame == true && UI1->MainMenu == false)
	if (LandMap1->BlocksVector[size_t(Game1->Player1->Y/32)][size_t(Game1->Player1->X/32)].Settlement)
	{
		UI_InventoryUnitClearUpdate();
		UI_InventoryUpdate();
	}
	
	// Update settlements units 
    for (size_t i = 0; i < Game1->Castes.size(); i++)
    {
		//cout << i << endl;
		// Trade units 
		TradeItemsUpdate();
        // Set preview maps
		/*
		vector<PreviewMap*> PreviewMaps;
		for (size_t j = 0; j < Game1->Castes.size(); j++)
		{
			if (j != i)
				PreviewMaps.push_back(Game1->Castes[j]->PreviewMap1);
			else
			{
				PreviewMaps.push_back(NULL);
			}
		}
		*/
		// Teams progress
		size_t TeamAttitude = 0;
		Game1->Castes[i]->Progress(LandMap1, DomainMap1, NoEntryMap1, /*PreviewMaps,*/ Game1->Player1->Team, Game1->Castes.size(), TeamAttitude);
		if (TeamAttitude != 0)
		{
			Game1->Castes[TeamAttitude-1]->Attitude[i] = Game1->Castes[i]->Attitude[TeamAttitude-1];
			//cout << "	> Attittude to: " << TeamAttitude << endl;
			UpdateAttitudeStatus();
		}
		// Update preview maps
		/*
		for (size_t j = 0; j < Game1->Castes.size(); j++)
		{
			if (j != i)
				Game1->Castes[j]->PreviewMap1 = PreviewMaps[j];
		}
		*/
	}
	//cout << "- - - - - - - - - - - - - - - - - - - - - <" << endl;

	// Update domain border map 
	DomainMap1->UpdateBorderMap();

	// Update spec text 
	NeedResources = "";
	UI1->SpecTextUpdate = true;

	// Left block
	UI_LeftBlockUpdate("");
}