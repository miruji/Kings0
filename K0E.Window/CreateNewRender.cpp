#include "Window.h"

// Create new render 
void Window::CreateNewRender()
{
    Width = NewWidth;
    Height = NewHeight;

    Console1->SetIndent(0);
    Console1->IPrintln("> New render window:");
    Console1->SetIndent(1);
        // VideoMode
        VideoModes = sf::VideoMode::getFullscreenModes();
        if (true)
        {
            bool VideoModeInit1 = true;
            bool VideoModeInit2 = true;
            for (size_t i = 0; i < VideoModes.size(); i++)
            if (VideoModes[i].width == Width && VideoModes[i].height == Height)
            {
                if (Width <= sf::VideoMode::getDesktopMode().width && Height <= sf::VideoMode::getDesktopMode().height)
                {

                    VideoModeInit2 = false;
                    VideoModeInit1 = false;
                }
                else
                if (Width >= 1280 && Height >= 720)
                {
                    VideoModeInit1 = false;
                }
            }
            if (VideoModeInit1 == true)
            {
                Console1->IPrintln("!> Video mode was not detected:");
                Width = 1280;
                Height = 720;
            }
            else
            if (VideoModeInit2 == true)
            {
                Console1->IPrintln("!> Video mode was not detected:");
                Width = sf::VideoMode::getDesktopMode().width;
                Height = sf::VideoMode::getDesktopMode().height;
            }
        }

    Console1->IPrintln("> Size: "+to_string(Width)+"x"+to_string(Height));

    // Window mode and create window 
    Console1->IPrintln("> Window mode: " + to_string(WindowMode));

    if (WindowMode == 0)
    {
        Render.create(sf::VideoMode(Width,Height, 32U), Title, sf::Style::Close | sf::Style::Titlebar);

        // Set start position 
        if (SaveX < 0)
            SaveX = 0;
        if (SaveY < 0)
            SaveY = 0;
        Render.setPosition(sf::Vector2i(SaveX, SaveY));
    }
    else
    if (WindowMode == 1)
    {
        if (VideoModes[0].width <= sf::VideoMode::getDesktopMode().width)
            NewWidth = Width = VideoModes[0].width;
        else
            NewWidth = Width = sf::VideoMode::getDesktopMode().width;

        if (VideoModes[0].height <= sf::VideoMode::getDesktopMode().height)
            NewHeight = Height = VideoModes[0].height;
        else
            NewHeight = Height = sf::VideoMode::getDesktopMode().height;

        Render.create(sf::VideoMode(NewWidth, NewHeight, 32U), Title, sf::Style::Close | sf::Style::Titlebar);
        
            HWND hwnd = Render.getSystemHandle();
            RECT wrect;
            GetWindowRect( hwnd, &wrect );
            RECT crect;
            GetClientRect( hwnd, &crect );
            POINT lefttop = { crect.left, crect.top }; // Practicaly both are 0
            ClientToScreen( hwnd, &lefttop );
            POINT rightbottom = { crect.right, crect.bottom };
            ClientToScreen( hwnd, &rightbottom );

            LeftMargin  = lefttop.x - wrect.left;
            TopMargin = lefttop.y - wrect.top;
 
        // Set start position 
        Render.setPosition(sf::Vector2i(-LeftMargin, -TopMargin));
    }
    else
    {
        // Render.getSystemHandle().
        //cout << Width << 'x' << Height << endl;
        Render.create(sf::VideoMode(Width, Height, 32U), Title, sf::Style::Fullscreen);
                ::ShowWindow(Render.getSystemHandle(), SW_MAXIMIZE);

        // Set start position 
        Render.setPosition(sf::Vector2i(-8, 0));
    }

    // FramerateLimit 
    Console1->IPrintln("> FramerateLimit: " + to_string(FramerateLimit));
    Render.setFramerateLimit(FramerateLimit);

    // VerticalSync 
    Console1->IPrintln("> VerticalSync: " + to_string(VerticalSync));
    Render.setVerticalSyncEnabled(VerticalSync);

    // Window icon 
    sf::Image Icon;
    if (!Icon.loadFromFile("Data\\Icons\\Icon128x128.png"))
        Error Error1(Console1, ErrorType::IconLoadError, { "Icon file not loaded" }, { "Continue K0E" }, false);
    else
    {
        Console1->IPrintln("> Window icon \"Data\\Icons\\WindowIcon.png\" is loaded.");
        Render.setIcon(128, 128, Icon.getPixelsPtr());
    }

    // Create window UI 
    Console1->SetIndent(0);
    Console1->IPrintln("> K0E.UI load:");
    UI1 = new UI(Width, Height, Version, LanguagePack1, Console1);
    if (MainMenu2Restart == true)
    {
        UIEvent('@', "MainMenu1", false, 0, false);
        UI1->FocusedBlockName = 0;
        FirstMainMenuBack = false;
        MainMenu2Restart = false;
    }

        // Update ComboBoxs current items 
        UI_UpdateComboBoxsCurrentItems("");

    // Mouse 
    Render.setMouseCursorGrabbed(false);
    Render.setMouseCursorVisible(true);

    // ... 
    ImGui::SFML::Init(Render);
    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

    // Create ImGui Window
    ImGui::SetNextWindowSize( ImVec2(float(Render.getSize().x), float(Render.getSize().y)) );
    ImGui::SetNextWindowPos ( ImVec2(0, 0) );
       
        // ... 
        IO = &ImGui::GetIO();

        // ... 
        Style = &ImGui::GetStyle();
        // Align an rounding 
        Style->WindowTitleAlign = ImVec2(0, 0);
        Style->WindowRounding = 0;
        // Border 
        Style->ChildBorderSize  = 0;
        Style->FrameBorderSize  = 0;
        Style->PopupBorderSize  = 0;
        Style->TabBorderSize    = 0;
        Style->WindowBorderSize = 0;
        // Padding 
        Style->FramePadding           = ImVec2(0, 0);
        Style->DisplaySafeAreaPadding = ImVec2(0, 0);
        Style->DisplayWindowPadding   = ImVec2(0, 0);
        Style->TouchExtraPadding      = ImVec2(0, 0);
        Style->WindowPadding          = ImVec2(0, 0);
        // Button 
        Style->Colors[ImGuiCol_Button]        = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
        Style->Colors[ImGuiCol_ButtonHovered] = ImVec4(1.0f, 1.0f, 1.0f, 0.23f);
        Style->Colors[ImGuiCol_ButtonActive]  = ImVec4(1.0f, 1.0f, 1.0f, 0.33f);
        // TextArea and more 
        Style->Colors[ImGuiCol_FrameBg]        = ImVec4(0.5f, 0.5f, 0.5f, 1.0f);
        Style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
        Style->Colors[ImGuiCol_FrameBgActive]  = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
        // Check mark 
        Style->Colors[ImGuiCol_CheckMark] = ImVec4(RGBA_TO_FLOAT(255, 255, 255, 255));

    // If render is open 
    // cout << "$ Now: " << endl;
    Render.setKeyRepeatEnabled(false);
    bool FirstDraw = true;
    while (Render.isOpen()) {
        if (FirstDraw)
        {
            SetWindowFocus();
        }

        // Events 
        while (Render.pollEvent(Event)) {
            ImGui::SFML::ProcessEvent(Event);
            
            // Request for closing the window
            if (Event.type == sf::Event::Closed ||
                (Event.type == sf::Event::KeyPressed && Event.key.code == sf::Keyboard::F4)
                )
            {
                //Audio1->StopMusic();
                // TO:DO ->> all sounds close 
                Render.close();
                exit(0);
            }
            else
            {
                Input();
            }
        }

        // Music 
        if (Audio1->MusicStream->getStatus() == sf::SoundSource::Status::Stopped)
        {
            if (FirstMusic == true)
            {
                Audio1->MusicCount--;
                FirstMusic = false;
            }

            Audio1->NextMusic();
        }

        // Rendering 
        if (Rendering == true)
        {
            if (NewGame == true)
                Render.setView(Camera1->GetView());

            Draw();
        }
        if (FirstDraw)
            FirstDraw = false;
    }

    // Shutdown 
    ImGui::SFML::Shutdown();
}