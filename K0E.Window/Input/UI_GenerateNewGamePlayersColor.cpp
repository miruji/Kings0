#include "../Window.h"

void Window::UI_GenerateNewGamePlayersColor()
{
	// Color
	vector< vector<size_t> > BackColor;
	vector<size_t> NewColor;
	string EndColor;
	for (size_t i = 0; i < NewGamePlayers.size(); i++)
	if (NewGamePlayers[i].Num != -1)
	{
		//
		size_t errors = 0;
		while (true)
		{
			bool rr = true;
			NewColor = ColorGenerate();

			if (i == 0)
			{
				BackColor.push_back(NewColor);
				break;
			}

			for (size_t p = 0; p < BackColor.size(); p++)
			{
				//cout << "-----------------" << endl;
				if ( (BackColor[p][0] != NewColor[0] && BackColor[p][1] != NewColor[1] && BackColor[p][2] != NewColor[2]) &&
				     ((BackColor[p][0]-15 != NewColor[0] || BackColor[p][0] < NewColor[0]) ||
					  (BackColor[p][1]-15 != NewColor[1] || BackColor[p][1] < NewColor[1]) ||
					  (BackColor[p][2]-15 != NewColor[2] || BackColor[p][2] < NewColor[2])) )
				{
					
				}
				else
				{
					rr = false;
					errors++;
					break;
				}
			}

			if (rr == true || errors == 10)
			{
				BackColor.push_back(NewColor);
				break;
			}
		}
		if (true)
		{
			vector<size_t> Color = BackColor[BackColor.size()-1];
			EndColor = to_string(Color[0])+';'+to_string(Color[1])+';'+to_string(Color[2])+";210";
			NewGamePlayers[i].Color = EndColor;
		}
		//
	}
}