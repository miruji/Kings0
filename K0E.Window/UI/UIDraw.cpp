#include "../Window.h"

// Message window ? 
bool MessageWindow(string BlockName)
{
	// MESSAGE
	if (BlockName == "0")
		return true;
	else
		return false;
}

// Rendering UI
void Window::UIDraw()
{
	//
	vector< UIBlock* >& DrawUIBlocks = UI1->GetDrawUIBlocks();
	
	//
	for (size_t i = 0; i < DrawUIBlocks.size(); i++)
	if (DrawUIBlocks[i]->GetLayer() == UI1->GetLayer())
	{
		// First draw 
		if (i == 0)
			ImGui::SetNextWindowSize( ImVec2(Width, Height) );
		else
			ImGui::SetNextWindowSize( DrawUIBlocks[i]->GetWH() );

		if (DrawUIBlocks[i]->FixedPosition || UI1->MainMenu || DrawUIBlocks[i]->FirstDraw == false)
		{
			ImGui::SetNextWindowPos ( DrawUIBlocks[i]->GetXY() );

			if (DrawUIBlocks[i]->FirstDraw == false)
			{
				DrawUIBlocks[i]->SetIPosition(GetRandomNumber(0, UI1->UnsignedIntLength));
				DrawUIBlocks[i]->FirstDraw = true;
			}
		}

		if (i == 0)
			ImGui::Begin(to_string(0).c_str(), 0, UI1->BackgroundFlags);
		else
			ImGui::Begin(to_string(DrawUIBlocks[i]->GetIPosition()).c_str(), 0, UI1->Flags | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoFocusOnAppearing);

		// Draw Image
		UIImage*  UIImage1;

		for (size_t j = 0; j < DrawUIBlocks[i]->UI_Image.size(); j++)
		if (DrawUIBlocks[i]->GetName() == DrawUIBlocks[i]->UI_Image[j]->GetBlockName())
		{
			UIImage1 = DrawUIBlocks[i]->UI_Image[j];
			if (UIImage1->Show == true)
			{
				ImGui::SetCursorPos(UIImage1->GetXY());
				ImGui::Image(UIImage1->GetSprite(), sf::Vector2f(UIImage1->GetWH().x*UI1->ResizeWidth, UIImage1->GetWH().y*UI1->ResizeHeight), UIImage1->Color);
			}
		}

		// Draw Gif
		UIGif* UIGif1;

		for (size_t j = 0; j < DrawUIBlocks[i]->UI_Gif.size(); j++)
		if (DrawUIBlocks[i]->GetName() == DrawUIBlocks[i]->UI_Gif[j]->GetBlockName())
		{
			UIGif1 = DrawUIBlocks[i]->UI_Gif[j];
			if (UIGif1->Show == true)
			{
				ImGui::SetCursorPos(UIGif1->GetXY());
				ImGui::Image(UIGif1->GetSprite(LastTime*2000000), sf::Vector2f(UIGif1->GetWH().x*UI1->ResizeWidth, UIGif1->GetWH().y*UI1->ResizeHeight));
			}
		}

		// Draw Input 
		if (true)
		{
		UIInput* Input1;
		ImGuiInputTextFlags TextAreaFlags = ImGuiInputTextFlags_None;

		Style->Colors[ImGuiCol_FrameBg]        = ImVec4(RGBA_TO_FLOAT(0, 0, 0, 255));
		Style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(RGBA_TO_FLOAT(0, 0, 0, 255));
		Style->Colors[ImGuiCol_FrameBgActive]  = ImVec4(RGBA_TO_FLOAT(0, 0, 0, 255));

		for (size_t j = 0; j < DrawUIBlocks[i]->UI_Input.size(); j++)
		if (DrawUIBlocks[i]->GetName() == DrawUIBlocks[i]->UI_Input[j]->GetBlockName())
		{
			Input1 = DrawUIBlocks[i]->UI_Input[j];

			ImGui::SetCursorPos(Input1->GetXY() );

			string Text1;
			if (Input1->Type == "Connect0" || Input1->Type == "Connect1")
			{
				Text1 = Input1->Text[0];
			}
			else
			if (Input1->Type == "Read")
			{
				for (size_t p = 0; p < Input1->Text.size(); p++)
					Text1 += Input1->Text[p] + "\n";
			}
			// Flags
			size_t Text2Size = 0;
			if (Input1->Type == "Connect0")
			{
				TextAreaFlags += ImGuiInputTextFlags_NoMultiline | ImGuiInputTextFlags_AutoSelectAll;
			}
			else
			if (Input1->Type == "Connect1")
			{
				Text2Size = Input1->MaxChars+1;
				TextAreaFlags += ImGuiInputTextFlags_OnlyNumbers | ImGuiInputTextFlags_NoMultiline | ImGuiInputTextFlags_AutoSelectAll;
			}
			else
			if (Input1->Type == "Read")
			{
				TextAreaFlags += ImGuiInputTextFlags_ReadOnly;
			}
			// Text2
			char* Text2 = new char[Text2Size];
			if (Input1->Type == "Connect0")
			{
				if (Input1->Spec == "Ip")
				{
					string BBB = "000.000.000.000";
					Text2Size = BBB.length()+1;
					Text2 = new char[Text2Size];
					strcpy_s(Text2, Text2Size, BBB.c_str());
				}
				else
				if (Input1->Spec == "Port")
				{
					string BBB = "0000";
					Text2Size = BBB.length()+1;
					Text2 = new char[Text2Size];
					strcpy_s(Text2, Text2Size, BBB.c_str());
				}
			}
			else
			{
				Text2Size = Text1.length()+1;
				Text2 = new char[Text2Size];
				strcpy_s(Text2, Text2Size, Text1.c_str());
			}
			// Drawing
			ImGui::SetCursorPos(Input1->GetXY());
			string Name = "##Input"+to_string(i)+'_'+to_string(j);
			//
			ImGui::InputTextMultiline(Name.c_str(), Text2, Text2Size, ImVec2(Input1->W, Input1->H), TextAreaFlags);
		}

		Style->Colors[ImGuiCol_FrameBg]        = ImVec4(0.5f, 0.5f, 0.5f, 1.0f);
		Style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
		Style->Colors[ImGuiCol_FrameBgActive]  = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
		}

		// Draw TextWrapped
		UITextWrapped* UITextWrapped1;

		Style->FramePadding = ImVec2(2, 14);
		Style->ScrollbarSize = 10.0f;
		Style->Colors[ImGuiCol_FrameBg]        = ImVec4(RGBA_TO_FLOAT(0, 0, 0, 0));
		Style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(RGBA_TO_FLOAT(0, 0, 0, 0));
		Style->Colors[ImGuiCol_FrameBgActive]  = ImVec4(RGBA_TO_FLOAT(0, 0, 0, 0));

		for (size_t j = 0; j < DrawUIBlocks[i]->UI_TextWrapped.size(); j++)
		if (DrawUIBlocks[i]->GetName() == DrawUIBlocks[i]->UI_TextWrapped[j]->GetBlockName())
		{
			UITextWrapped1 = DrawUIBlocks[i]->UI_TextWrapped[j];
			if (UITextWrapped1->Show == true)
			{
				ImGui::SetCursorPos(UITextWrapped1->GetXY());
				string Name = "##TextWrapped"+to_string(i)+'_'+to_string(j);
				ImGui::BeginChildFrame(ImGui::GetID(Name.c_str()), ImVec2(UITextWrapped1->W, UITextWrapped1->H));

				ImGui::PushTextWrapPos(UITextWrapped1->W);
				ImGui::TextWrapped(UITextWrapped1->Text.c_str());

				ImGui::EndChild();
			}
		}

		Style->ScrollbarSize = 0.0f;

		// Draw CheckBox
		UICheckBox* UICheckBox1;

			Style->FrameRounding = 12;
			Style->FrameBorderSize = 1;
			Style->FramePadding = ImVec2(4, 4);
			Style->DisplaySafeAreaPadding = ImVec2(4, 4);
			Style->ItemInnerSpacing = ImVec2(12, 12);
			Style->Colors[ImGuiCol_FrameBg]        = ImVec4(RGBA_TO_FLOAT(75, 50, 15, 255));
			Style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(RGBA_TO_FLOAT(84, 55, 15, 255));
			Style->Colors[ImGuiCol_FrameBgActive]  = ImVec4(RGBA_TO_FLOAT(70, 44, 7, 255));

		for (size_t j = 0; j < DrawUIBlocks[i]->UI_CheckBox.size(); j++)
		if (DrawUIBlocks[i]->GetName() == DrawUIBlocks[i]->UI_CheckBox[j]->GetBlockName())
		{
			UICheckBox1 = DrawUIBlocks[i]->UI_CheckBox[j];
			if (UICheckBox1->Show == true)
			{
				ImGui::SetCursorPos( UICheckBox1->GetXY() );

				//UISpec(UICheckBox1);
				UICheckBoxFirstDraw(UICheckBox1);
				if ( ImGui::Checkbox(UICheckBox1->GetText().c_str(), &UICheckBox1->GetValue()) )
				{
					// Play sound 
					Audio1->PlaySound1("ButtonClick0");
					//
					UICheckBoxEvent(UICheckBox1->GetCheckEvent(), UICheckBox1->GetValue());
				}
			}
		}

			Style->FrameBorderSize = 0;
			Style->FrameRounding = 0;
			Style->FramePadding = ImVec2(0, 0);
			Style->DisplaySafeAreaPadding = ImVec2(0, 0);
			Style->ItemInnerSpacing = ImVec2(0, 0);
			Style->Colors[ImGuiCol_FrameBg]        = ImVec4(0.5f, 0.5f, 0.5f, 1.0f);
			Style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
			Style->Colors[ImGuiCol_FrameBgActive]  = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);

		// Draw ComboBox
		UIComboBox* UIComboBox1;

			Style->Alpha = 1.0f;
			Style->WindowMinSize = ImVec2(32, 32);
			Style->WindowRounding = 0.5f;
			Style->WindowTitleAlign = ImVec2(0.5f, 0.5f);
			Style->FramePadding = ImVec2(4, 1);
			Style->TouchExtraPadding = ImVec2(0, 0);
			Style->ColumnsMinSpacing = 3.0f;
			Style->ScrollbarRounding = 0.0f;
			Style->GrabMinSize = 0.1f;
			Style->GrabRounding = 0.0f;
			Style->CurveTessellationTol = 1.25f;

			Style->Colors[ImGuiCol_Header]        = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
			Style->Colors[ImGuiCol_HeaderHovered] = ImVec4(1.0f, 1.0f, 1.0f, 0.15f);
			Style->Colors[ImGuiCol_HeaderActive]  = ImVec4(1.0f, 1.0f, 1.0f, 0.30f);

			Style->Colors[ImGuiCol_FrameBg]        = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
			Style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(1.0f, 1.0f, 1.0f, 0.30f);
			Style->Colors[ImGuiCol_FrameBgActive]  = ImVec4(1.0f, 1.0f, 1.0f, 0.60f);
			Style->Colors[ImGuiCol_Button]         = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
			Style->Colors[ImGuiCol_ButtonHovered]  = ImVec4(1.0f, 1.0f, 1.0f, 0.30f);
			Style->Colors[ImGuiCol_ButtonActive]   = ImVec4(1.0f, 1.0f, 1.0f, 0.30f);

		for (size_t j = 0; j < DrawUIBlocks[i]->UI_ComboBox.size(); j++)
		if (DrawUIBlocks[i]->GetName() == DrawUIBlocks[i]->UI_ComboBox[j]->GetBlockName())
		{
			UIComboBox1 = DrawUIBlocks[i]->UI_ComboBox[j];

			if (UIComboBox1->Show == true)
			{
			ImGui::SetCursorPos( UIComboBox1->GetXY() );

			const char* buffer = "";

			string Buffer2 = UIComboBoxCurrentItem(UIComboBox1->GetId());
			UIComboBox1->BasicCurrentItem = Buffer2.c_str();

			bool is_selected = false;
		
			if (UIComboBox1->FirstDraw == true)
			{
				UIComboBoxEvent(UIComboBox1->GetId(), DrawUIBlocks[i]->UI_ComboBox[j]);
				UIComboBox1->FirstDraw = false;
			}

			if (UIComboBox1->CurrentItem == "")
				UIComboBox1->CurrentItem = UIComboBox1->BasicCurrentItem;

			ImGui::PushItemWidth(UIComboBox1->Width);
			if (ImGui::BeginCombo(("##Combo_"+to_string(i)+"_"+to_string(j)).c_str(), UIComboBox1->CurrentItem, ImGuiComboFlags_HeightSmall))
			{
				for (size_t n = 0; n < UIComboBox1->GetTexts().size(); n++)
				{
					buffer = UIComboBox1->GetTexts()[n].c_str();
					if (ImGui::Selectable(buffer, is_selected))
					{
						// Play sound 
						Audio1->PlaySound1("ButtonClick0");
						//
						UIComboBox1->CurrentItem = buffer;
						UIComboBoxSettings(UIComboBox1->GetId(), buffer, n);
						is_selected = (UIComboBox1->CurrentItem == buffer);
						//cout << "Selectable" << endl;
					}
					if (is_selected)
					{
						ImGui::SetItemDefaultFocus();
						break;
						//cout << ">>Selected!" << endl;
					}
					//
				}
				ImGui::EndCombo();
			}
			ImGui::PopItemWidth();
			//
			}
		}
		ImGui::PushTextWrapPos( Width );

		Style->Alpha = 1.0f;
		Style->WindowPadding = ImVec2(0, 0);
		Style->ItemSpacing = ImVec2(0, 0);
		Style->WindowMinSize = ImVec2(0, 0);
		Style->WindowRounding = 0.0f;
		Style->WindowTitleAlign = ImVec2(0, 0);
		Style->FramePadding = ImVec2(0, 0);
		Style->FrameRounding = 0.0f;
		Style->ItemInnerSpacing = ImVec2(0, 0);
		Style->TouchExtraPadding = ImVec2(0, 0);
		Style->IndentSpacing = 0.0f;
		Style->ColumnsMinSpacing = 0.0f;
		Style->ScrollbarSize = 0.0f;
		Style->ScrollbarRounding = 0.0f;
		Style->GrabMinSize = 0.0f;
		Style->GrabRounding = 0.0f;
		Style->ButtonTextAlign = ImVec2(0, 0);
		Style->DisplayWindowPadding = ImVec2(0, 0);
		Style->DisplaySafeAreaPadding = ImVec2(0, 0);
		Style->CurveTessellationTol = 0.0f;

		Style->Colors[ImGuiCol_Header]        = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
		Style->Colors[ImGuiCol_HeaderHovered] = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
		Style->Colors[ImGuiCol_HeaderActive]  = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);

		Style->Colors[ImGuiCol_FrameBg]        = ImVec4(0.5f, 0.5f, 0.5f, 1.0f);
		Style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
		Style->Colors[ImGuiCol_FrameBgActive]  = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
		Style->Colors[ImGuiCol_Button]         = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
		Style->Colors[ImGuiCol_ButtonHovered]  = ImVec4(1.0f, 1.0f, 1.0f, 0.23f);
		Style->Colors[ImGuiCol_ButtonActive]   = ImVec4(1.0f, 1.0f, 1.0f, 0.33f);

		// Draw Button
		UIButton* UIButton1;

		for (size_t j = 0; j < DrawUIBlocks[i]->UI_Button.size(); j++)
		if (DrawUIBlocks[i]->GetName() == DrawUIBlocks[i]->UI_Button[j]->GetBlockName())
		{
			UIButton1 = DrawUIBlocks[i]->UI_Button[j];
			if (UIButton1->Show == true)
			{
				// Draw 
				ImGui::SetCursorPos( UIButton1->GetXY() );
				sf::Vector2f Size;
				if (UIButton1->Resize)
					Size = sf::Vector2f(UIButton1->GetWH().x*UI1->ResizeWidth, UIButton1->GetWH().y*UI1->ResizeHeight);
				else
					Size = UIButton1->GetWH();

				if (ImGui::ImageButton(UIButton1->GetSprite(), Size) )
				{
					// Play sound 
					if (MessageWindow(UI1->GetDrawUIBlocks()[0]->GetName()))
						Audio1->PlaySound1("ButtonClick1");
					else
						Audio1->PlaySound1("ButtonClick0");
					// Update spec text 
					UI1->SpecTextUpdate = true;
					// Button event 
					UIEvent( UI1->UIEventSplit(UIButton1->GetEvent())[0][0], UI1->UIEventSplit(UIButton1->GetEvent())[1], UIButton1->Message, i, UIButton1->Closed );
				}
			}
		}

		// Draw Text
		UIText* UIText1;

		for (size_t j = 0; j < DrawUIBlocks[i]->UI_Text.size(); j++)
		if (DrawUIBlocks[i]->GetName() == DrawUIBlocks[i]->UI_Text[j]->GetBlockName())
		{
			UIText1 = DrawUIBlocks[i]->UI_Text[j];
			if (UIText1->Show == true)
			{
				ImGui::SetCursorPos(UIText1->GetXY() );

				if (UI1->SpecTextUpdate == true || UIText1->GetSpec() == "FPS" || i == 0)
				{
					UISpec(UIText1, i);
				}
				ImGui::TextColored(UIText1->GetColor(), UIText1->GetText().c_str() );
				ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[0]);
			}
		}

		if (ImGui::IsWindowFocused() || ImGui::IsAnyItemFocused() && DrawUIBlocks[i]->FirstDraw == false)
		{
			//UI1->FocusedBlockName2 = DrawUIBlocks[i]->GetName();
			UI1->FocusedBlockName = i;

			if (DrawUIBlocks[i]->FixedPosition == false)
				DrawUIBlocks[i]->SetPosition(ImGui::GetWindowPos().x, ImGui::GetWindowPos().y);
		}

		// Draw SlideInt
		UISlideInt* UISlideInt1;

		for (size_t j = 0; j < DrawUIBlocks[i]->UI_SlideInt.size(); j++)
		{
			UISlideInt1 = DrawUIBlocks[i]->UI_SlideInt[j];
			if (UISlideInt1->FirstDraw)
			{
				UISlideIntUpdate(UISlideInt1->GetId());
				UISlideInt1->FirstDraw = false;
			}

			ImGui::SetCursorPos( UISlideInt1->GetXY() );
			ImGui::SetNextItemWidth( UISlideInt1->GetH() );
			ImGui::SliderInt(("##SlideInt_"+to_string(i)+"_"+to_string(j)).c_str(), &UISlideInt1->Slider, UISlideInt1->Min, UISlideInt1->Max);
			
			if (UISlideInt1->GetId() == "Soundtrack")
			{
				Audio1->Soundtrack = UISlideInt1->Slider;
				Audio1->Musics[Audio1->MusicCount]->GetMusic()->setVolume(float(Audio1->Soundtrack));
			}
			else
			if (UISlideInt1->GetId() == "SoundEffects")
				Audio1->SoundEffects = UISlideInt1->Slider;
		}

		//ImGui::ShowDemoWindow();
		ImGui::End();
	//
	}
	//
	if (UI1->SpecTextUpdate == true)
	{
		if (SpecTextUpdateI == 2)
		{
			UI1->SpecTextUpdate = false;
			SpecTextUpdateI = 0;
		}
		else
			SpecTextUpdateI++;
	}
}

// Clear DrawUIBlocks 
void Window::UIClearDrawBlocks(bool ClearAll)
{
	//
	string BB = "";
	for (size_t i = UI1->GetDrawUIBlocks().size()-1; i > 0; i--)
	{
		BB = UI1->GetDrawUIBlocks()[i]->GetName();
		if (BB != "MainMenu0" && BB != "MainMenu1" && BB != "GameBasic")
		{
		//cout << BB << endl;
		if (ClearAll == false)
		{
			// No statistics 
			if (BB != "Statistics" &&
				BB != "BuildPanel" &&
				BB != "BuildPanelMinimize" &&
				BB != "LeftDownButtons" &&
				BB != "Music")
			{
				// No left block
				bool Clear = false;
				string BlockName = BB;
				string Buffer = "";

				if (BlockName.length() >= 9)
				for (size_t j = 0; j < 9; j++)
				{
					Buffer += BlockName[j];
				}
				if (Buffer != "LeftBlock")
					Clear = true;

				// Else 
				if (Clear == true)
					UIEvent('!', "Close", false, i, false);
			}
		}
		else
			UIEvent('!', "Close", false, i, false);
		}
	}
}
// Clear Layer
void Window::UIClearLayer(size_t Layer)
{
	//
	UIBlock* BB;
	for (size_t i = UI1->GetDrawUIBlocks().size()-1; i > 0; i--)
	{
		BB = UI1->GetDrawUIBlocks()[i];
		if (BB->GetLayer() == Layer)
			UIEvent('!', "Close", false, i, false);
	}
}