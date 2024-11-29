#include "Window.h"

// Constructor 
Window::Window(string Version, string Language, string Title, size_t Width, size_t Height, size_t FramerateLimit, size_t WindowMode, bool VerticalSync, Console* Console2, SteamAPI* SteamAPI1, int Soundtrack, int SoundEffects)
{
    // Console 
    Console1 = Console2;
    // SteamAPI
    this->SteamAPI1 = SteamAPI1;

    // Set init configuration 
    Console1->SetIndent(0);
    Console1->IPrintln("!> Engine init:");
        Console1->SetIndent(1);
        Console1->IPrintln("> Version: \""+Version+"\"");
        Console1->IPrintln("> Language: \""+Language+"\"");
    
    this->Version  = Version;
    //this->Language = Language;

    // Window title and render 
    Console1->SetIndent(0);
    Console1->IPrintln("!> Render window:");
        Console1->SetIndent(1);
        Console1->IPrintln("> Title: \""+ Title +"\"");

    this->Title = Title;

    // Window size 
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
    this->Width = Width;
    this->Height = Height;

    Console1->IPrintln("> Size: "+to_string(Width)+"x"+to_string(Height));

    // Window mode and create window 
    Console1->IPrintln("> Window mode: "+to_string(WindowMode));

    if (WindowMode == 0)
    {
        Render.create(sf::VideoMode(Width,Height, 32U), Title, sf::Style::Close | sf::Style::Titlebar);

        // Set start position 
        Render.setPosition(sf::Vector2i(0, 0));

        if (SaveX < 0)
            SaveX = 0;
        if (SaveY < 0)
            SaveY = 0;
    }
    else
    if (WindowMode == 1)
    {
        if (VideoModes[0].width <= sf::VideoMode::getDesktopMode().width)
            NewWidth = this->Width = Width = VideoModes[0].width;
        else
            NewWidth = this->Width = Width = sf::VideoMode::getDesktopMode().width;

        if (VideoModes[0].height <= sf::VideoMode::getDesktopMode().height)
            NewHeight = this->Height = Height = VideoModes[0].height;
        else
            NewHeight = this->Height = Height = sf::VideoMode::getDesktopMode().height;

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
        Render.create(sf::VideoMode(Width, Height, 32U), Title, sf::Style::Fullscreen);
                ::ShowWindow(Render.getSystemHandle(), SW_MAXIMIZE);

        // Set start position 
        Render.setPosition(sf::Vector2i(-8, 0));
    }

        // FramerateLimit 
        Console1->IPrintln("> FramerateLimit: "+to_string(FramerateLimit));

        this->FramerateLimit = FramerateLimit;
        Render.setFramerateLimit(FramerateLimit);

        // VerticalSync 
        Console1->IPrintln("> VerticalSync: "+to_string(VerticalSync));

        this->VerticalSync = VerticalSync;
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

    ImGui::SFML::Init(Render);

    // Create all languages 
    Console1->SetIndent(0);
    Console1->IPrintln("> K0E.Language generating:");

    this->LanguagePack1 = LoadLanguages();
    LanguagePack1->SetLanguageType(Language);

    // Create window UI 
    Console1->SetIndent(0);
    Console1->IPrintln("> K0E.UI load:");

    this->UI1 = new UI(Width, Height, Version, LanguagePack1, Console1);
    Maps = LoadMaps(); 
    CurrentMapName = Maps[0].Name;
    CurrentMapSize = Maps[0].Size;
    CurrentMapTeams = Maps[0].Teams;
    //MapZoom = 2;

    // Create mouse 
    Mouse1 = new Mouse();
    // Create window cursor 
    Cursor1 = new Cursor(0, 0);
    Cursor1->SetCursorInWindow(Render, "Data\\Textures\\Cursors\\Basic.png", CursorType::Basic);
    Render.setMouseCursorGrabbed(false);
    Render.setMouseCursorVisible(true);
    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

    // Create ImGui Window
    ImGui::SetNextWindowSize( ImVec2(float(Render.getSize().x), float(Render.getSize().y)) );
    ImGui::SetNextWindowPos ( ImVec2(0, 0) );
       
        //
        IO = &ImGui::GetIO();

        //
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
        // Header
		Style->Colors[ImGuiCol_Header]        = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
		Style->Colors[ImGuiCol_HeaderHovered] = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
		Style->Colors[ImGuiCol_HeaderActive]  = ImVec4(1.0f, 1.0f, 1.0f, 0.0f);
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

    // Audio 
    Audio1 = new Audio(Console1);
    Audio1->Soundtrack = Soundtrack;
    Audio1->SoundEffects = SoundEffects;

    // Network 
    Network1 = new Network(Version);

    // If render is open 
    Render.setKeyRepeatEnabled(false);

    sf::Packet packet;
    Network1->New('s', packet);
    //
    bool FirstDraw = true;
    while (Render.isOpen()) {
        if (FirstDraw)
        {
            SetWindowFocus();
        }
        // Network 
        if (Network1->Type == 's')
            Network1->ServerUpdate(packet);
        else
        if (Network1->Type == 'c')
            Network1->ClientUpdate();

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

LanguagePack* Window::LoadLanguages()
{
    //setlocale(LC_ALL, "");

    XMLParser* XMLParser1 = new XMLParser();
    XMLParser1->LoadDocument("Data\\Languages\\Init.xml", Console1);

    vector<string> Languages;
    if (true)
    {
    TiXmlElement* ElData = XMLParser1->GetDataElement();
    TiXmlElement* ElInit = ElData->FirstChildElement("Init");
    while (ElInit != NULL)
	{
        if (ElInit->Attribute("Name"))
            Languages.push_back(ElInit->Attribute("Name"));

        ElInit = ElInit->NextSiblingElement("Init");
	}
    }

	LanguagePack* LanguagePack1 = new LanguagePack();
    Language* Language1;
    vector<string> Names;
    string Path = "";
	for (size_t i = 0; i < Languages.size(); i++)
	{
		XMLParser1->LoadDocument("Data\\Languages\\"+Languages[i]+"\\Main.xml", Console1);
        Language1 = XMLParser1->LoadLanguage(Languages[i]);
        
        File File1("Data\\Languages\\"+Languages[i]+"\\Names");
        Names = File1.FileToVector("");
        Language1->Names = Names;
        // cout << Names.size() << endl;
        LanguagePack1->GetLanguages().push_back(Language1);
    }

	return LanguagePack1;
}

vector<Map> Window::LoadMaps()
{
    //setlocale(LC_ALL, "");

    XMLParser* XMLParser1 = new XMLParser();
    XMLParser1->LoadDocument("Data\\Maps\\Init.xml", Console1);

    vector<Map> Result;
    if (true)
    {
    TiXmlElement* ElData = XMLParser1->GetDataElement();
    TiXmlElement* ElInit = ElData->FirstChildElement("Init");
    while (ElInit != NULL)
	{
        Map Map;
        if (ElInit->Attribute("Name"))
            Map.Name = ElInit->Attribute("Name");
        
        if (ElInit->Attribute("Size"))
            Map.Size = ElInit->Attribute("Size");
        
        if (ElInit->Attribute("Teams"))
            Map.Teams = atoi(ElInit->Attribute("Teams"));

        Result.push_back(Map);
        ElInit = ElInit->NextSiblingElement("Init");
	}
    }

	return Result;
}