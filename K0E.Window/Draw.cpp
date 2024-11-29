#include "Window.h"

// Rendering func 
void Window::Draw()
{
    // Clear last frame
    Render.clear();

    // Update 
    if (UI1->Drawing == true)
        ImGui::SFML::Update(Render, Clock1.restart());

    //Time1 = Clock1.getElapsedTime();

    // New frame 
        // Optimizate in main menu 
        if (NewGame == true && UI1->MainMenu == false)
        {
            // Land Map 
            LandMap1->Draw(Render, Camera1->X, Camera1->Y, Camera1->W, Camera1->H, WarFog1->Drawing);

            // Road map 
            if (RoadMap1->Drawing)
                RoadMap1->Draw(Render, Camera1->X, Camera1->Y, Camera1->W, Camera1->H, LandMap1->BlocksVector, WarFog1->Drawing);

            // Grid map 
            if (GridMap1->Drawing)
                GridMap1->Draw(Render, Camera1->X, Camera1->Y, Camera1->W, Camera1->H, LandMap1->BlocksVector, WarFog1->Drawing);

            // Preview map 
            //if (Game1->Castes[Game1->Player1->Team]->PreviewMap1->Drawing)
            //{
            //    Game1->Castes[Game1->Player1->Team]->PreviewMap1->Draw(Render, Camera1->X, Camera1->Y, Camera1->W, Camera1->H, LandMap1->BlocksVector, WarFog1->Drawing);
            //    Game1->Castes[Game1->Player1->Team]->PreviewMap1General->Draw(Render, Camera1->X, Camera1->Y, Camera1->W, Camera1->H, LandMap1->BlocksVector, WarFog1->Drawing);
            //}

            // Domain map 
            if (DomainMap1->Drawing)
            {
                vector<string> Colors;
                for (size_t i = 0; i < Game1->Castes.size(); i++)
                    Colors.push_back(Game1->Castes[i]->Color);
                DomainMap1->Draw(Render, Camera1->X, Camera1->Y, Camera1->W, Camera1->H, LandMap1->BlocksVector, WarFog1->Drawing, Colors);
            }

            // Draw first settlements 
            if (Game1->CastesDrawing == true)
            for (size_t i = 0; i < Game1->Castes.size(); i++)
            if (Game1->Castes[i]->Drawing == true)
            {
                //
                Game1->Castes[i]->DrawFirstSettlements(Render, Camera1->X, Camera1->Y, Camera1->W, Camera1->H, LandMap1->BlocksVector, WarFog1->Drawing, Game1->NamesDrawing, Game1->Player1->Team);
            }

            // No entry map
            if (NoEntryMap1->Drawing)
                NoEntryMap1->Draw(Render, Camera1->X, Camera1->Y, Camera1->W, Camera1->H, LandMap1->BlocksVector, WarFog1->Drawing);

            // Draw player 
            if (Game1->Player1->Drawing && Game1->Player1->Die == false)
            if (Game1->Player1->SettlementType != SettlementTypes::Tower && Game1->Player1->SettlementType != SettlementTypes::Castle && Game1->Player1->SettlementType != SettlementTypes::Settlement)
            {
                //
                Game1->Player1->Draw(Render, Game1->NamesDrawing, Game1->Castes[Game1->Player1->Team]->Color, Game1->Castes[Game1->Player1->Team]->Army);
            }

            // Draw player direction
            if (Game1->Player1->Drawing && Game1->Player1->DirectionDrawing && Game1->Player1->Die == false)
                Game1->Player1->DrawDirection(Render, LandMap1->BlocksVector, /*Game1->Castes[Game1->Player1->Team]->PreviewMap1->GetTeamMap(), Game1->Castes[Game1->Player1->Team]->PreviewMap1General->GetTeamMap(),*/ NoEntryMap1->MapVector, SaveNewGameNation, DomainMap1, Game1->Castes[Game1->Player1->Team]->Status, Game1->Castes[Game1->Player1->Team]->Technologys, Game1->Castes[Game1->Player1->Team]->Color);

            // Draw second settlements and units 
            if (Game1->UnitsDrawing == true)
            for (size_t i = 0; i < Game1->Castes.size(); i++)
            {
                 Game1->Castes[i]->DrawUnits(Render, Camera1->X, Camera1->Y, Camera1->W, Camera1->H, LandMap1->BlocksVector, WarFog1->Drawing, Game1->NamesDrawing);
            }

            // Draw second settlements 
            if (Game1->CastesDrawing == true)
            for (size_t i = 0; i < Game1->Castes.size(); i++)
            if (Game1->Castes[i]->Drawing == true)
            {
                //
                Game1->Castes[i]->DrawSecondSettlements(Render, Camera1->X, Camera1->Y, Camera1->W, Camera1->H, LandMap1->BlocksVector, WarFog1->Drawing, Game1->NamesDrawing, Game1->Player1->Team);
            }

            // Map pointer 
            if (Game1->Player1->Drawing == true && MapPointer1->Drawing == true)
                MapPointer1->Draw(Render, Camera1->X, Camera1->Y, Camera1->W, Camera1->H, LandMap1->BlocksVector, LastTime*2000000);

            // Draw war fog 
            if (WarFog1->Drawing)
                WarFog1->Draw(Render, Camera1->X, Camera1->Y, Camera1->W, Camera1->H, LandMap1->BlocksVector);

            // 
        }

        // UI Window style 
        if (UI1->Drawing == true)
        {
            // UI window begin 
            IO->IniFilename = NULL;

            UIDraw();
        }

    // Reset clock
    //FPS = size_t(1.0f / Time1.asSeconds()) / 1000;
        FPS = size_t(1.0f / (Clock1.restart().asSeconds()-LastTime) /10);
        LastTime = Clock1.restart().asSeconds();

    Clock1.restart().asSeconds();

    // End the current frame and display its contents on screen 
    if (UI1->Drawing == true)
        ImGui::SFML::Render(Render);  // 

    Render.display();                 // 
}