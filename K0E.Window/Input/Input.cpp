#include "../Window.h"

// Control: [Main stream] 
void Window::Input()
{
	if (Event.type == sf::Event::MouseWheelScrolled)
	{
		// ! Control only in game !
		if (UI1->MainMenu == false)
		{
			if (Event.mouseWheelScroll.delta < 0)
				Contol_Zoom('-');
			else if (Event.mouseWheelScroll.delta > 0)
				Contol_Zoom('+');
		}
	}
	else
	if (Event.type == sf::Event::GainedFocus)
	{
		if (WindowMode == 1)
			Render.setPosition(sf::Vector2i(-LeftMargin, -TopMargin));
	}
	else
	// Keyboard pressed event 
	if (Event.type == sf::Event::KeyPressed)
	{
		if (InputMode == false)
			return;

		// ! Control only in game !
		if (UI1->MainMenu == false)
		{	
			NeedResources = "";
			UI_SearchMessage();

			//
			if (Event.key.code == sf::Keyboard::Unknown)
				{ /* ... */ }
			else
			// Control: [Arrows] 
			if ( Control_Arrows() )
				{ /* ... */ }
			else
			// Control: [Main menu] 
			if (Control_Esc() )
				{ /* ... */ }
			else
			// Left panel [Tab]
			if ( Contol_Tab(true) )
				{ /* ... */ }
			else
			// Resources cut [Left or right ->> Shift]
			if ( Contol_Shift(true) )
				{ /* ... */ }
			else
			// Zoom [< or >]
			if ( Contol_Zoom(' '))
				{ /* ... */ }
			else
			// Control: [War fog show / hide] 
			if ( Control_F() ) 
				{ /* ... */ }
			else
			// Control: [Grid show / hide] 
			if ( Control_G() )
				{ /* ... */ }
			else
			// Control: [Hud show / hide] 
			if ( Control_H() )
				{ /* ... */ }
			else
			// Control: [Castes show / hide] 
			if ( Control_B() )
				{ /* ... */ }
			else
			// Control: [Enemy units show / hide]
			if ( Control_O(true) )
				{ /* ... */ }
			else
			// Control: [Roads show / hide] 
			if ( Control_R() )
				{ /* ... */ }
			else
			// Control: [Player show / hide] 
			if ( Control_P() )
				{ /* ... */ }
			else
			// Control: [Names show / hide] 
			if ( Control_N() )
				{ /* ... */ }
			else
			// Control: [Marks show / hide] 
			if ( Control_M(true) )
				{ /* ... */ }
			else
			// Control: [Building nums] 
			if ( Control_Tilde(true) )
				{ /* ... */ }
			else
			// ->> Down - UI->Message
			// Control: [Numbers 1] 
			if ( Control_SettlementNumbers() )
				{ /* ... */ }
			else
			// Control: [WASD] 
			if ( Control_WAXD(' ', false) )
				{ /* ... */ }
			else
			// Control: [WASD QEZC] 
			if ( Control_QEZC(' ', false) )
				{ /* ... */ }
			else
			// Control: [Enter or S] 
			if (Event.key.code == sf::Keyboard::Enter || Event.key.code == sf::Keyboard::S)
			{
				if (UI1->Message == 0)
					Control_Progress();
				else
					NeedResources = ";T_Message";
			}
			else
			// Control: [Domain] 
			if ( Control_Ctrl(true) )
				{ /* ... */ }
			else
			// Control: [Numbers 2] 
			if ( Control_Numbers(10) )
				{ /* ... */ }
		}
		else
		{
			// Control: [Main menu] 
			if (Control_Esc() )
				{ /* ... */ }
			else
			// Control: [MainMenu Numbers] 
			if ( Control_MainMenuNumbers() )
				{ /* ... */ }
		}

		// Update spec text 
		UI1->SpecTextUpdate = true;
	}
	else
	// Mouse event 
	if (Event.type == sf::Event::MouseButtonReleased)
	{
		if (Event.key.code == sf::Mouse::Left)
		if (UI1->MainMenu == false)
			NeedResources = "";
		UI_SearchMessage();
		//
		Cursor1->SetCursorInWindow(Render, "Data\\Textures\\Cursors\\Basic.png", CursorType::Basic);
		// Update spec text 
		UI1->SpecTextUpdate = true;
	}
	else
	if (Event.type == sf::Event::MouseButtonPressed)
	{
		if (UI1->MainMenu == false)
			NeedResources = "";
		UI_SearchMessage();
		// Mouse left 
		if (Event.key.code == sf::Mouse::Left)
		{
			// Update cursor 
			Cursor1->SetCursorInWindow(Render, "Data\\Textures\\Cursors\\Fist.png", CursorType::Fist);
			
			// To map pointer 
			for (int i = UI1->GetDrawUIBlocks().size()-1; i >= 0; i--)
			{
				if ((Mouse1->GetUIPosition(Render).x >= UI1->GetDrawUIBlocks()[i]->GetXY().x && Mouse1->GetUIPosition(Render).y >= UI1->GetDrawUIBlocks()[i]->GetXY().y) &&
					(Mouse1->GetUIPosition(Render).x <= UI1->GetDrawUIBlocks()[i]->GetXY().x+UI1->GetDrawUIBlocks()[i]->GetWH().x && Mouse1->GetUIPosition(Render).y <= UI1->GetDrawUIBlocks()[i]->GetXY().y+UI1->GetDrawUIBlocks()[i]->GetWH().y))
				{
					UI1->FocusedBlockName = i;
					//cout << UI1->GetDrawUIBlocks()[i]->GetName() << endl;
					break;
				}
			}

			// Map pointer 
			if (UI1->FocusedBlockName == 0)
			if (UI1->MainMenu == false && MapPointer1->Drawing == true)
			{
				if ( (size_t(Mouse1->GetMapPosition(Render).x/32) >= 0 && size_t(Mouse1->GetMapPosition(Render).x/32) <= LandMap1->BlocksVector[0].size()-1) &&
					 (size_t(Mouse1->GetMapPosition(Render).y/32) >= 0 && size_t(Mouse1->GetMapPosition(Render).y/32) <= LandMap1->BlocksVector.size()-1))
				if (LandMap1->BlocksVector[size_t(Mouse1->GetMapPosition(Render).y/32)][size_t(Mouse1->GetMapPosition(Render).x/32)].WarFog == false)
				{
					MapPointer1->SetXY(size_t(Mouse1->GetMapPosition(Render).x/32)*32, size_t(Mouse1->GetMapPosition(Render).y/32)*32);
				
					UI_UpdateMapPointer(false);
				}
			}
		}
		// Mouse right 
		else
		if (Event.key.code == sf::Mouse::Right)
		{
			if (UI1->MainMenu == false)
				NeedResources = "";
			//
			if (UI1->MainMenu == false)
			{
			if (UI1->Message == 0)
			{
			if ( (Mouse1->GetMapPosition(Render).x >= 0 && Mouse1->GetMapPosition(Render).y >= 0) &&
				 (Mouse1->GetMapPosition(Render).x <= LandMap1->BlocksVector.size()*32 && Mouse1->GetMapPosition(Render).y <= LandMap1->BlocksVector[0].size()*32) ) {
				// Get mouse position 
				size_t MouseX = (Mouse1->GetMapPosition(Render).x/32);
				size_t MouseY = (Mouse1->GetMapPosition(Render).y/32);
				MapBlock& Block = LandMap1->BlocksVector[MouseY][MouseX];

				if (Block.X == Game1->Player1->X-32 && Block.Y == Game1->Player1->Y-32)
					Control_QEZC('Q', false); ///
				else
				if (Block.X == Game1->Player1->X+32 && Block.Y == Game1->Player1->Y-32)
					Control_QEZC('E', false); ///
				else
				if (Block.X == Game1->Player1->X-32 && Block.Y == Game1->Player1->Y+32)
					Control_QEZC('Z', false); ///
				else
				if (Block.X == Game1->Player1->X+32 && Block.Y == Game1->Player1->Y+32)
					Control_QEZC('C', false); ///
				else
				
				if ( (Block.X == Game1->Player1->X && Block.Y <= Game1->Player1->Y-32) ||
					 (Block.X == Game1->Player1->X-32 && Block.Y <= Game1->Player1->Y-32) ||
					 (Block.X == Game1->Player1->X+32 && Block.Y <= Game1->Player1->Y-32) )
					Control_WAXD('W', false); //
				else
				if ( (Block.X <= Game1->Player1->X-32 && Block.Y == Game1->Player1->Y) ||
					 (Block.X <= Game1->Player1->X-32 && Block.Y == Game1->Player1->Y-32) ||
					 (Block.X <= Game1->Player1->X-32 && Block.Y == Game1->Player1->Y+32) )
					Control_WAXD('A', false); //
				else
				if ( (Block.X == Game1->Player1->X && Block.Y >= Game1->Player1->Y+32) ||
					 (Block.X == Game1->Player1->X-32 && Block.Y >= Game1->Player1->Y+32) ||
					 (Block.X == Game1->Player1->X+32 && Block.Y >= Game1->Player1->Y+32) )
					Control_WAXD('X', false); //
				else
				if ( (Block.X >= Game1->Player1->X+32 && Block.Y == Game1->Player1->Y) ||
					 (Block.X >= Game1->Player1->X+32 && Block.Y == Game1->Player1->Y-32) ||
					 (Block.X >= Game1->Player1->X+32 && Block.Y == Game1->Player1->Y+32) )
					Control_WAXD('D', false); //
				else
				if (Block.X <= Game1->Player1->X-32 && Block.Y <= Game1->Player1->Y-32)
					Control_QEZC('Q', false); ///
				else
				if (Block.X >= Game1->Player1->X+32 && Block.Y <= Game1->Player1->Y-32)
					Control_QEZC('E', false); ///
				else
				if (Block.X <= Game1->Player1->X-32 && Block.Y >= Game1->Player1->Y+32)
					Control_QEZC('Z', false); ///
				else
				if (Block.X >= Game1->Player1->X+32 && Block.Y >= Game1->Player1->Y+32)
					Control_QEZC('C', false); ///
			}
			}
			else
				NeedResources = ";T_Message";
			}
		}
		// Mouse middle 
		else
		if (Event.key.code == sf::Mouse::Middle)
		{
			if (UI1->MainMenu == false)
				NeedResources = "";
			UI_SearchMessage();

			//
			//cout << Mouse1->GetMapPosition(Render).x/32 << " | " << Mouse1->GetMapPosition(Render).y/32 << endl;
			//

			if (UI1->MainMenu == false)
			{
				if (UI1->Message == 0)
					Control_Progress();
				else
					NeedResources = ";T_Message";
			}
		}
		// Update spec text 
		UI1->SpecTextUpdate = true;
	}
	//
}