#include "../Window.h"

void Window::EnemyUnitDie(size_t EnemyTeam)
{
	cout << "!!! ENEMY UNIT DIE" << endl;
	if (Game1->Castes[EnemyTeam]->Units.size() != 0)
	{
		LandMap1->BlocksVector[(Game1->Castes[EnemyTeam]->Units[0]->Y)][(Game1->Castes[EnemyTeam]->Units[0]->X)].Enemy = 0;
		Game1->Castes[EnemyTeam]->Units.erase(Game1->Castes[EnemyTeam]->Units.begin());
	}
}