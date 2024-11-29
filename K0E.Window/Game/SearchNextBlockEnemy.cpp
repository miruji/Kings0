#include "../Window.h"

// Game: Search next block enemy 
bool Window::SearchNextBlockEnemy(MapBlock NextBlock, size_t BasicTeam)
{
	if (NextBlock.Enemy != 10 && Game1->Castes[Game1->Player1->Team]->Status[NextBlock.Enemy] != 3)
	{
		/*
		//cout << Game1->Castes[Game1->Player1->Team]->Status[NextBlock.Enemy] << endl;
		if (Game1->Castes[Game1->Player1->Team]->Status[NextBlock.Enemy] != 0 && Game1->Castes[Game1->Player1->Team]->Attitude[NextBlock.Enemy] != 15)
			UIEvent('!', "NewWar"+to_string(NextBlock.Enemy), true, 1, false);
		else
		{
			string PlayerNext = "_"+to_string(size_t(NextBlock.X))+"_"+to_string(size_t(NextBlock.Y));
			UIEvent('!', "EnemyAttack"+to_string(NextBlock.Enemy)+PlayerNext, true, 1, false);
		}
		*/
		return false;
	}
	else
		return true;

	return true;
}