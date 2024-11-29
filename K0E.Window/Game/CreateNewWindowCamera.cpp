#include "../Window.h"

void Window::CreateNewWindowCamera()
{
    // Create window camera 
    if (true)
    {
        size_t VideoModeWidth, VideoModeHeight;
        bool VideoModeInit = true;
        for (size_t i = 0; i < VideoModes.size(); i++)
        {
            if (VideoModes[i].width >= 1280 && VideoModes[i].height >= 720)
            {
                VideoModeWidth = VideoModes[i].width;
                VideoModeHeight = VideoModes[i].height;
                VideoModeInit = false;
            }
        }
        if (VideoModeInit == true)
        {
            cout << "  !> Video mode was not detected" << endl;
            VideoModeWidth = 1280;
            VideoModeHeight = 720;
        }

        Camera1 = new Camera( (Game1->Player1->X-(VideoModeWidth/2)), Game1->Player1->Y-(VideoModeHeight/2), float(VideoModeWidth), float(VideoModeHeight) );
    }
    Camera1->GetView().setCenter( sf::Vector2f(Game1->Player1->X+16, Game1->Player1->Y+16) );
    Camera1->SetZoom(MapZoom);
}