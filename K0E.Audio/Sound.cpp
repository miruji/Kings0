#include "Sound.h"

// Path to name 
void Sound::PathToName(string Path)
{
	// ... 
	vector<string> PathVector;
	string Buffer = "";
	for (size_t i = 0; i < Path.length(); i++)
	{
		if (Path[i] == '\\' || i+1 == Path.length())
		{
			if (i+1 == Path.length())
			{
				Buffer += Path[i];
				PathVector.push_back(Buffer);
				Buffer = "";
			}
			else
			{
				PathVector.push_back(Buffer);
				Buffer = "";
			}
		}
		else
			Buffer += Path[i];
	}
	Name = PathVector[PathVector.size()-1];
	PathVector.clear();
	Buffer = "";
	for (size_t i = 0; i < Name.length(); i++)
	{
		if (Name[i] == '.' || i+1 == Name.length())
		{
			if (i+1 == Name.length())
			{
				Buffer += Path[i];
				PathVector.push_back(Buffer);
				Buffer = "";
			}
			else
			{
				PathVector.push_back(Buffer);
				Buffer = "";
			}
		}
		else
			Buffer += Name[i];
	}
	Name = PathVector[0];
}

// Constructor 
Sound::Sound(string Path)
{
	ifstream File(Path);
	if (!File.is_open())
	{
		// ... 
		cout << "  > Failed to load sound file \"" + Path + "\"." << endl;
		cout << "    > Unable to open file." << endl;
		cout << "    > Continue K0E." << endl;
	}
	else
	{
		// Load sound 
		if (!SoundBuffer.loadFromFile(Path))
		{
			// ... 
			cout << "  > Failed to load sound file \"" + Path + "\"." << endl;
			cout << "    > Unable to open file." << endl;
			cout << "    > Continue K0E." << endl;
		}
		else
		{
			cout << "  > Sound \"" + Path + "\" is loaded." << endl;
			// ... 
			Sound1 = new sf::Sound();
			Sound1->setBuffer(SoundBuffer);
			Loaded = true;
			PathToName(Path);

			// Set volume 
			Sound1->setVolume(100);
		}
	}
	File.close();
}

// Get sound (link)
sf::Sound* Sound::GetSound()
{
	// ... 
	return Sound1;
}

// Play
void Sound::Play()
{
	// ... 
	Sound1->play();
}

// Stop
void Sound::Stop()
{
	// ... 
	Sound1->stop();
}

// Get name (link) 
string& Sound::GetName()
{
	// ... 
	return Name;
}