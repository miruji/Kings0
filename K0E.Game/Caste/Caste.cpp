#include "Caste.h"

// Regenerate No entry map
void Caste::RegenerateNoEntryMap(NoEntryMap* NoEntryMap1)
{
    // Create No entry map 
    //cout << Game1->Castes.size() << endl;
    size_t SettlementX = 0, SettlementY = 0;
    size_t Team = 0;

    for (size_t j = 0; j < Settlements.size(); j++)
    {
        Team = Settlements[j].Team+1;

        //cout << Game1->Castes[i]->Settlements[j].GetX()/32 << " : " << Game1->Castes[i]->Settlements[j].GetY()/32 << endl;
        SettlementX = Settlements[j].X / 32;
        SettlementY = Settlements[j].Y / 32;

        if (Settlements[j].GetType() == SettlementTypes::Wall || Settlements[j].GetType() == SettlementTypes::Tower || Settlements[j].GetType() == SettlementTypes::Castle)
        {
            if (NoEntryMap1->MapVector[SettlementX][SettlementY] == "0")
                NoEntryMap1->MapVector[SettlementX][SettlementY] = to_string(Team);
            else 
                NoEntryMap1->MapVector[SettlementX][SettlementY] = NoEntryMap1->MapVector[SettlementX][SettlementY]+to_string(Team);

            if (NoEntryMap1->MapVector[SettlementX-1][SettlementY] == "0")
                NoEntryMap1->MapVector[SettlementX-1][SettlementY] = to_string(Team);
            else
                NoEntryMap1->MapVector[SettlementX-1][SettlementY] = NoEntryMap1->MapVector[SettlementX-1][SettlementY]+to_string(Team);

            if (NoEntryMap1->MapVector[SettlementX+1][SettlementY] == "0")
                NoEntryMap1->MapVector[SettlementX+1][SettlementY] = to_string(Team);
            else
                NoEntryMap1->MapVector[SettlementX+1][SettlementY] = NoEntryMap1->MapVector[SettlementX+1][SettlementY]+to_string(Team);

            if (NoEntryMap1->MapVector[SettlementX][SettlementY-1] == "0")
                NoEntryMap1->MapVector[SettlementX][SettlementY-1] = to_string(Team);
            else
                NoEntryMap1->MapVector[SettlementX][SettlementY-1] = NoEntryMap1->MapVector[SettlementX][SettlementY-1]+to_string(Team);

            if (NoEntryMap1->MapVector[SettlementX][SettlementY+1] == "0")
                NoEntryMap1->MapVector[SettlementX][SettlementY+1] = to_string(Team);
            else
                NoEntryMap1->MapVector[SettlementX][SettlementY+1] = NoEntryMap1->MapVector[SettlementX][SettlementY+1]+to_string(Team);
        }
        else
         if (Settlements[j].GetType() == SettlementTypes::Settlement)
        {
            if (NoEntryMap1->MapVector[SettlementX][SettlementY] == "0")
                NoEntryMap1->MapVector[SettlementX][SettlementY] = to_string(Team);
            else 
                NoEntryMap1->MapVector[SettlementX][SettlementY] = NoEntryMap1->MapVector[SettlementX][SettlementY]+to_string(Team);
        }
    }
	//
}

size_t Caste::NationToInt()
{
	if (Nation == CasteNation::Steppe)
		return 0;
	else
	if (Nation == CasteNation::Water)
		return 1;
	else
	if (Nation == CasteNation::Sedentary)
		return 2;
	else
	if (Nation == CasteNation::Mountain)
		return 3;
}

void Caste::ClearTechnologys()
{
	for (size_t i = 0; i < InitTechnology; i++)
	{
		Technologys[i].Opened = false;
	}
}

void Caste::UpdateNation(size_t BNation)
{
	cout << "T: " << Team << ", BNation: " << BNation << endl;
	if (BNation == 0)
	{
		Nation = CasteNation::Steppe;
		PastureBonus = 4;
		SuburbBonus = 3;
		PopulationBonus = 1;
		// Technology: River 
		Technologys[3].Opened = true;
	}
	else
	if (BNation == 1)
	{
		Nation = CasteNation::Water;
		SawmillBonus = 1;
		FisheriesBonus = 2;
		SuburbBonus = 2;
		// Technology: River and water 
		Technologys[2].Opened = true;
		Technologys[3].Opened = true;
	}
	else
	if (BNation == 2)
	{
		Nation = CasteNation::Sedentary;
		FieldBonus = 2;
		SuburbBonus = 2;
		PopulationBonus = 2;
		// Technology: Forest 
		Technologys[0].Opened = true;
	}
	else
	if (BNation == 3)
	{
		Nation = CasteNation::Mountain;
		FieldBonus = 1;
		SawmillBonus = 2;
		SuburbBonus = 2;
		// Technology: Mountain 
		Technologys[1].Opened = true;
	}

	Technologys[8].Opened = true;
	if (Team != 0)
		Technologys[0].Opened = true;
}

// Constructor
Caste::Caste(size_t Team, size_t TeamSize, vector< Settlement > Settlements, vector<Character*>& Characters)
{
	// Technology
	if (true)
	{
	int Cost = 250;
	vector<size_t> EmptyTech;
	for (size_t i = 0; i < InitTechnology; i++)
	{
		if (i == 4)
			EmptyTech.push_back(0);
		else
		if (i == 5)
			EmptyTech.push_back(1);
		else
		if (i == 6)
			EmptyTech.push_back(2);
		else
		if (i == 7)
			EmptyTech.push_back(3);
		else
		//
		if (i == 8)
		{
			Cost = 500;
		}
		else
		if (i == 9)
		{
			Cost = 500;
			EmptyTech.push_back(8);
		}
		else
		if (i == 10)
		{
			Cost = 500;
			EmptyTech.push_back(9);
		}
		else
		if (i == 11)
		{
			Cost = 500;
			EmptyTech.push_back(10);
		}
		else
		if (i == 12)
		{
			Cost = 500;
			EmptyTech.push_back(11);
		}
		//
		Technologys.push_back(Technology(false, Cost, EmptyTech));
		Cost = 250;
		EmptyTech.clear();
	}
	}
	// Nation + bonus 
	this->Team = Team;
	this->Settlements = Settlements;

	size_t BNation = GetRandomNumber(0, 3);
	UpdateNation(BNation);

	//
	for (size_t i = 0; i < TeamSize; i++)
	{
		if (i == Team)
			Attitude.push_back(100);
		else
			Attitude.push_back(25);
	}

	for (size_t i = 0; i < TeamSize; i++)
	{
		if (i == Team)
			Status.push_back(3);
		else
			Status.push_back(1);
	}

	Rune = GetRandomNumber(0, 23);

	// Create new squad AND push back <Leader> 
	Squad1 = new Squad();
	for (size_t i = 0; i < Characters.size(); i++)
	{
		//
		if (Characters[i]->GetName() == "Leader")
			Squad1->GetCharacters().push_back(Characters[i]);
	}
}

// Prewiew progress 
void Caste::PreviewProgress(LandMap* LandMap1)
{
	// Settlement progress 
	PreviewCash = Cash;
	PreviewFood = Food;
	PreviewWood = Wood;
	PreviewPopulation = Population;
	PreviewArmy = Army;
	PreviewTechnologyPoints = TechnologyPoints;
	PreviewDiploPoints = DiploPoints;
	PreviewMovePoints = MovePoints;
	//
	if (Technologys[12].Opened)
		BuildingLimit = 75;
	else
	if (Technologys[11].Opened)
		BuildingLimit = 60;
	else
	if (Technologys[10].Opened)
		BuildingLimit = 45;
	else
	if (Technologys[9].Opened)
		BuildingLimit = 30;
	else
	if (Technologys[8].Opened)
		BuildingLimit = 15;
	//
	size_t BarnBuilds = 0, FoodBuilds = 0, CashBuilds = 0, PopulationBuilds = 0, TechnologyBuild = 0;
	size_t SettlementArmy = 0; // all army in settlements
	
	for (size_t i = 0; i < Settlements.size(); i++)
	{
		if (Settlements[i].GetType() == SettlementTypes::Settlement)
		{
			FoodBuilds++;
			PreviewFood += 45;

			CashBuilds++;
			PreviewCash++;
			
			PopulationBuilds++;

			TechnologyBuild++;

			//SettlementArmy += Settlements[i].Army;
		}
		else
		if (Settlements[i].GetType() == SettlementTypes::Barn)
		{
			BarnBuilds++;
		}
		else
		if (Settlements[i].GetType() == SettlementTypes::Sawmill)
		{
			PreviewFood--;

			int Random = GetRandomNumber(1, 1 + SawmillBonus);
			LandMap1->BlocksVector[size_t(Settlements[i].Y / 32)][size_t(Settlements[i].X / 32)].Wood -= Random;
			LandMap1->ForestSize -= Random;

			PreviewWood += Random;
			
			if (LandMap1->BlocksVector[size_t(Settlements[i].Y/32)][size_t(Settlements[i].X/32)].Wood <= 0)
			{
				LandMap1->BlocksVector[size_t(Settlements[i].Y/32)][size_t(Settlements[i].X/32)].Wood = 0;
				LandMap1->BlocksVector[size_t(Settlements[i].Y/32)][size_t(Settlements[i].X/32)].Forest = false;

				LandMap1->BlocksVector[size_t(Settlements[i].Y/32)][size_t(Settlements[i].X/32)].RectAddY = 0;
				LandMap1->BlocksVector[size_t(Settlements[i].Y/32)][size_t(Settlements[i].X/32)].Update();

				LandMap1->BlocksVector[size_t(Settlements[i].Y/32)][size_t(Settlements[i].X/32)].Settlement = 0;
				
				cout << i << endl;
				Settlements.erase(Settlements.begin()+i);
				i-=2;
			}
		}
		else
		if (Settlements[i].GetType() == SettlementTypes::Suburb)
		{
			PreviewFood--;

			PopulationBuilds++;

			CashBuilds++;
		}
		else
		if (Settlements[i].GetType() == SettlementTypes::Field)
		{
			FoodBuilds++;
		}
		else
		if (Settlements[i].GetType() == SettlementTypes::Pasture)
		{
			FoodBuilds++;
		}
		else
		if (Settlements[i].GetType() == SettlementTypes::Fisheries)
		{
			FoodBuilds++;

			CashBuilds++;
		}
		else
		if (Settlements[i].GetType() == SettlementTypes::Wall)
		{
			PreviewCash--;
		}
		else
		if (Settlements[i].GetType() == SettlementTypes::Tower)
		{
			PreviewFood--;
			PreviewCash--;

			PreviewMovePoints++;

			SettlementArmy += Settlements[i].Army;
		}
		else
		if (Settlements[i].GetType() == SettlementTypes::Castle)
		{
			PreviewFood--;
			PreviewCash--;

			PreviewMovePoints++;

			SettlementArmy += Settlements[i].Army;
		}
	}

	// Food & Cash -- 
	PreviewFood -= PreviewPopulation;

	PreviewFood -= PreviewArmy+SettlementArmy;
	PreviewCash -= PreviewArmy+SettlementArmy;

	// Builds
	ResourcesLimit = BarnBuilds*1000+3000;

	PreviewCash += (float(CashBuilds)/10)*(PreviewPopulation);
	PreviewFood += (float(FoodBuilds)/10)*(PreviewPopulation);

	if (PreviewPopulation < 100)
	{
		if (GetRandomNumber(0, 1))
			PreviewPopulation++;
		else
		if (GetRandomNumber(0, 1))
			PreviewFood++;
	}

	if (PreviewPopulation < 10)
		PreviewPopulation++;
	else
	if (GetRandomNumber(0, PopulationBuilds) != 0 && PreviewFood >= 101)
	{
		size_t Random = (float(PopulationBuilds)/10)*(PreviewPopulation/10);
		if (Random >= PreviewPopulation/10)
			Random = PreviewPopulation/10;
		//
		if (PreviewFood-Random >= 0)
			PreviewPopulation += Random;
		//
	}
	if (true)
	{
		int tech = (float(TechnologyBuild)/10)*(PreviewPopulation/5)+1;
		if (tech >= 10)
			tech = 10;

		PreviewTechnologyPoints += tech;
	}

	// ResourcesLimit
	if (ResourcesLimit > BuildingLimit*1000+2000)
		ResourcesLimit = BuildingLimit*1000+2000;
	else
	if (ResourcesLimit > BarnBuilds*1000+3000)
		ResourcesLimit = BarnBuilds*1000+3000;
	// Food limit
	if (PreviewFood < 10)
	{
		for (size_t i = 0; i < Settlements.size(); i++)
		if (Settlements[i].GetType() == SettlementTypes::Settlement || Settlements[i].GetType() == SettlementTypes::Tower || Settlements[i].GetType() == SettlementTypes::Castle)
		{
			size_t r1 = GetRandomNumber(0, 1+size_t(Settlements[i].Army/GetRandomNumber(4, Settlements[i].Army)));
			if (Settlements[i].Army-r1 >= 0 && Settlements[i].Army-r1 <= Settlements[i].ArmyLimit)
				Settlements[i].Army -= r1;
		}
		//
		PreviewPopulation -= GetRandomNumber(0, 1+size_t(PreviewPopulation/GetRandomNumber(4, PreviewPopulation)));
		PreviewArmy -= GetRandomNumber(0, 1+size_t(PreviewArmy/GetRandomNumber(4, PreviewArmy)));
		PreviewFood = 10;
	}
	if (PreviewFood > ResourcesLimit)
		PreviewFood = ResourcesLimit;
	// Cash limit
	if (PreviewCash < 0)
		PreviewCash = 0;
	if (PreviewCash > ResourcesLimit)
		PreviewCash = ResourcesLimit;
	// Wood limit
	if (PreviewWood < 0)
		PreviewWood = 0;
	if (PreviewWood > ResourcesLimit)
		PreviewWood = ResourcesLimit;
	// Population & army
	if (PreviewPopulation < 0)
		PreviewPopulation = 0;
	if (PreviewArmy < 0)
		PreviewArmy = 0;

	// 
	if (GetRandomNumber(0, 1))
		PreviewMovePoints = GetRandomNumber(3, 5)*2;
	else 
		PreviewMovePoints = GetRandomNumber(3, 7)*2;

		if (Technologys[4].Opened)
		{
			PreviewMovePoints+=3;
		}
		if (Technologys[5].Opened)
		{
			PreviewMovePoints+=3;
		}
		if (Technologys[6].Opened)
		{
			PreviewMovePoints+=3;
		}
		if (Technologys[7].Opened)
		{
			PreviewMovePoints+=3;
		}

	if (PreviewMovePoints < 0)
		PreviewMovePoints = 0;

	//
	if (GetRandomNumber(0, 1))
		PreviewDiploPoints += GetRandomNumber(0, 1);

	if (PreviewDiploPoints < 0)
		PreviewDiploPoints = 0;

	//
	if (PreviewTechnologyPoints < 0)
		PreviewTechnologyPoints = 0;
}

// Progress 
void Caste::Progress(LandMap* LandMap1, DomainMap* DomainMap1, NoEntryMap* NoEntryMap1, /*vector<PreviewMap*>& PreviewMaps,*/ size_t PlayerTeam, size_t GameTeams, size_t& TeamAttitude)
{
	// Resources 
	Cash = PreviewCash;
	Food = PreviewFood;
	Wood = PreviewWood;
	Population = PreviewPopulation;
	Army = PreviewArmy;
	TechnologyPoints = PreviewTechnologyPoints;
	DiploPoints = PreviewDiploPoints;
	MovePoints = PreviewMovePoints;

	//cout << "TEAM: " << Team << ": " << endl;
	//cout << "!> Cash["<<Cash<<"], Food["<<Food<<"], Wood["<<Wood<<"], Population["<<Population<<"], Army["<<Army<<"], DP["<<DiploPoints<<"], MP["<<MovePoints<<"]; "<<endl;
	// 
	if (Team != PlayerTeam)
	{
		Food += GetRandomNumber(0, 2);
		if (GetRandomNumber(0, 2) == 0)
			Wood += GetRandomNumber(0,1);
		DiploPoints += 1;
		if (GetRandomNumber(0, 2) == 0)
			DiploPoints += 1;
		if (GetRandomNumber(0, 2) == 0)
			MovePoints += 1;
		//cout << "NO PLAYER: " << endl;

		size_t R1 = GetRandomNumber(0, 1);
		// technology reseach
		if (R1 == 0)
		{
			//cout << "  > technology;" << endl;

			size_t R2 = 0;
			size_t repeat_error = 0;
			while (true)
			{
				if (repeat_error >= InitTechnology)
					break;

				R2 = GetRandomNumber(0, 7);

				if (TechnologyPoints >= Technologys[R2].Cost)
				{
					if (Technologys[R2].Opened == false)
					{
						Technologys[R2].Opened = true;
						TechnologyPoints -= Technologys[R2].Cost;
						break;
					}
					else
						repeat_error++;
				}
				else
					break;
			}
			//
		}
		// attitude + or -
		else
		if (R1 == 1 && GetRandomNumber(0, 10) == 0)
		{
			//cout << "  > attitude;" << endl;
			if (DiploPoints >= 5)
			{
				size_t R2 = 0;

				int R2_Size = 0;
				if (GetRandomNumber(0, 1))
					R2_Size = 5;
				else
					R2_Size = -5;

				size_t repeat_error = 0;

				//cout << "Team: " << Team << ", chose: " << R2 << ", size: " << R2_Size << endl;
				while (true)
				{
					R2 = GetRandomNumber(0, GameTeams-1);

					if (repeat_error >= GameTeams-1)
						break;
					// double random
					if (Attitude[R2] >= 30)
					{
						if (GetRandomNumber(0, 1))
							R2_Size = 5;
					}
					else
					if (Attitude[R2] <= 20)
					{
						if (GetRandomNumber(0, 1))
							R2_Size = -5;
					}
					//
					if (R2 != Team && Attitude[R2]+R2_Size <= 50 && Attitude[R2]+R2_Size >= 0)
					{
						Attitude[R2] += R2_Size;
						TeamAttitude = R2+1;
						DiploPoints -= 5;
						break;
					}
					else
					{
						if (R2 != Team)
							repeat_error++;
					}
				}
			}
			//
		}
	}
	// Unit progress 
	for (size_t j = 0; j < Units.size(); j++)
	{
		//
		Units[j]->Progress(LandMap1, Settlements, Nation, DomainMap1, /*PreviewMap1, PreviewMaps,*/ Technologys, Status, MovePoints, Wood, DiploPoints, Population, Food, Army, Cash, ResourcesLimit);
	}
	RegenerateNoEntryMap(NoEntryMap1);

	PreviewProgress(LandMap1);
}

// Draw units 
void Caste::DrawUnits(sf::RenderWindow& Render, float& CameraX, float& CameraY, float& CameraW, float& CameraH, std::vector< std::vector<MapBlock> >& BlocksVector, bool& DrawingWarFog, bool& NamesDrawing)
{
	//
	for (size_t i = 0; i < Settlements.size(); i++)
	if (Settlements[i].GetType() != SettlementTypes::Settlement ||
		Settlements[i].GetType() != SettlementTypes::Tower      ||
		Settlements[i].GetType() != SettlementTypes::Castle)
	{
		for (size_t j = 0; j < Units.size(); j++)
		{
			//
			if (BlocksVector[Units[j]->Y/32][Units[j]->X/32].WarFog == false || DrawingWarFog == false)
			if ((Units[j]->X >= CameraX || CameraX <= 0) && (Units[j]->Y >= CameraY || CameraY <= 0) &&
				Units[j]->X <= CameraX+CameraW && Units[j]->Y <= CameraY+CameraH)
				Units[j]->Draw(Render, NamesDrawing, Color, Army);
		}
	}
}

// Draw first settlements 
void Caste::DrawFirstSettlements(sf::RenderWindow& Render, float& CameraX, float& CameraY, float& CameraW, float& CameraH, vector< vector<MapBlock> >& BlocksVector, bool& DrawingWarFog, bool& NamesDrawing, size_t PlayerTeam)
{
	//
	for (size_t i = 0; i < Settlements.size(); i++)
	{
		//
		if (Settlements[i].GetType() == SettlementTypes::Barn      ||
			Settlements[i].GetType() == SettlementTypes::Wall      ||
			Settlements[i].GetType() == SettlementTypes::Field     || 
			Settlements[i].GetType() == SettlementTypes::Pasture   ||
			Settlements[i].GetType() == SettlementTypes::Fisheries ||
			Settlements[i].GetType() == SettlementTypes::Suburb    || 
			Settlements[i].GetType() == SettlementTypes::Sawmill)
		if (BlocksVector[Settlements[i].Y/32][Settlements[i].X/32].WarFog == false || DrawingWarFog == false)
			Settlements[i].Draw(Render, CameraX, CameraY, CameraW, CameraH, NamesDrawing, Color, PlayerTeam, Nation);
	}
}

// Draw second settlements 
void Caste::DrawSecondSettlements(sf::RenderWindow& Render, float& CameraX, float& CameraY, float& CameraW, float& CameraH, vector< vector<MapBlock> >& BlocksVector, bool& DrawingWarFog, bool& NamesDrawing, size_t PlayerTeam)
{
	//
	for (size_t i = 0; i < Settlements.size(); i++)
	{
		//
		if (Settlements[i].GetType() == SettlementTypes::Settlement ||
			Settlements[i].GetType() == SettlementTypes::Tower      ||
			Settlements[i].GetType() == SettlementTypes::Castle)
		if (BlocksVector[Settlements[i].Y/32][Settlements[i].X/32].WarFog == false || DrawingWarFog == false)
			Settlements[i].Draw(Render, CameraX, CameraY, CameraW, CameraH, NamesDrawing, Color, PlayerTeam, Nation);
	}
}