#include "../Window.h"

// Create team map 
vector< vector<size_t> > Window::CreateTeamMap(vector< vector<MapBlock> >& BlocksVector, vector< Caste* >& Castes)
{
    //
    vector< vector<size_t> > Result;
	vector< size_t > MapLine;
	for (size_t i = 0; i < BlocksVector.size(); i++)
	{
		//
		for (size_t j = 0; j < BlocksVector[i].size(); j++)
		{
			//
			MapLine.push_back(0);
		}

        Result.push_back(MapLine);
		MapLine.clear();
	}
    //
    for (size_t i = 0; i < Castes.size(); i++)
    for (size_t j = 0; j < Castes[i]->Settlements.size(); j++)
    {
        Result[Castes[i]->Settlements[j].Y/32][Castes[i]->Settlements[j].X/32] = Castes[i]->Settlements[j].Team+2;
    }
	//
	return Result;
}

// Create all maps
void Window::CreateMaps(vector< vector<string> > Map, vector< Caste* > Castes)
{
	// Open game map.xml
		// Land map
		LandMap1 = new LandMap();
		LandMap1->StringsVector = Map[0];
		LandMap1->Generate(); // World map Width & Height
		// Forest map
		ForestMap* Forest = new ForestMap();
		Forest->StringsVector = Map[1];
		Forest->Generate(LandMap1->BlocksVector);
		// Mountain map
		MountainMap* Mountain = new MountainMap();
		Mountain->StringsVector = Map[2];
		Mountain->Generate(LandMap1->BlocksVector);
		// Update land map
		for (size_t i = 0; i < LandMap1->BlocksVector.size(); i++)
		for (size_t j = 0; j < LandMap1->BlocksVector[i].size(); j++)
			LandMap1->BlocksVector[i][j].Update();
	// forest size
		for (size_t i = 0; i < LandMap1->BlocksVector.size(); i++)
		for (size_t j = 0; j < LandMap1->BlocksVector[i].size(); j++)
		{
			if (LandMap1->BlocksVector[i][j].Forest)
			{
				LandMap1->BlocksVector[i][j].Wood = GetRandomNumber(10, 20);
				LandMap1->ForestSize++;
			}
		}
	// End - generate cout 
	cout << "    > Land map forest size: " << LandMap1->ForestSize << endl;
	cout << ("    > Land map genereted: ~"+ std::to_string( LandMap1->BlocksVector.size()*(LandMap1->BlocksVector[0].size()/2) ) + " blocks.") << endl;

    // Set Grid map 
    GridMap1 = new GridMap(LandMap1->BlocksVector);

	// Set Domain map 
	DomainMap1 = new DomainMap();
	DomainMap1->StringsVector = Map[4];
	DomainMap1->Generate(LandMap1->BlocksVector, CreateTeamMap(LandMap1->BlocksVector, Castes));

    // Set War fog 
    WarFog1 = new WarFog(LandMap1->BlocksVector);

    // Set Road map
    RoadMap1 = new RoadMap();
    RoadMap1->StringsVector = Map[3];
    RoadMap1->Generate(LandMap1->BlocksVector);

    // Set No entry map 
    NoEntryMap1 = new NoEntryMap();
    NoEntryMap1->Generate(LandMap1->BlocksVector);
}