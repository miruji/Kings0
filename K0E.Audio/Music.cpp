#include "Music.h"

// Constructor
Music::Music(string Path)
{
	ifstream File(Path);
	if (!File.is_open())
	{
		// ... 
		cout << "  > Failed to load music file \"" + Path + "\"." << endl;
		cout << "    > Unable to open file." << endl;
		cout << "    > Continue K0E." << endl;
	}
	else
	{
		// Load music 
		Music1 = new sf::Music();
		if (!Music1->openFromFile(Path))
		{
			// ... 
			cout << "  > Failed to load music file \"" + Path + "\"." << endl;
			cout << "    > Unable to open file." << endl;
			cout << "    > Continue K0E." << endl;
		}
		else
		{
			cout << "  > Music \"" + Path + "\" is loaded." << endl;
			Loaded = true;

			// Set volume 
			Music1->setVolume(100);
		}
	}
	File.close();
}

// Get music (link)
sf::Music* Music::GetMusic()
{
	// ... 
	return Music1;
}

// Play
void Music::Play()
{
	// ...
	Music1->play();
}

// Stop
void Music::Stop()
{
	// ... 
	Music1->stop();
}