#include "../Window.h"

// Regenerate No entry map
void Window::RegenerateNoEntryMap()
{
    // Create No entry map 
    //cout << Game1->Castes.size() << endl;
    size_t SettlementX = 0, SettlementY = 0;
    size_t Team = 0;

    for (size_t i = 0; i < Game1->Castes.size(); i++)
    for (size_t j = 0; j < Game1->Castes[i]->Settlements.size(); j++)
    {
        Team = Game1->Castes[i]->Settlements[j].Team+1;

        //cout << Game1->Castes[i]->Settlements[j].GetX()/32 << " : " << Game1->Castes[i]->Settlements[j].GetY()/32 << endl;
        SettlementX = Game1->Castes[i]->Settlements[j].X / 32;
        SettlementY = Game1->Castes[i]->Settlements[j].Y / 32;

        if (Game1->Castes[i]->Settlements[j].GetType() == SettlementTypes::Wall || Game1->Castes[i]->Settlements[j].GetType() == SettlementTypes::Tower || Game1->Castes[i]->Settlements[j].GetType() == SettlementTypes::Castle)
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
         if (Game1->Castes[i]->Settlements[j].GetType() == SettlementTypes::Settlement)
        {
            if (NoEntryMap1->MapVector[SettlementX][SettlementY] == "0")
                NoEntryMap1->MapVector[SettlementX][SettlementY] = to_string(Team);
            else 
                NoEntryMap1->MapVector[SettlementX][SettlementY] = NoEntryMap1->MapVector[SettlementX][SettlementY]+to_string(Team);
        }
    }

    // Output 
    //NoEntryMap1->Output();
}