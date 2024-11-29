#include "Audio.h"

// Constructor
Audio::Audio(Console* Console1) {
	// Open XML file
	XMLParser1 = new XMLParser();
	//XMLParser1->LoadFile("Data\\Audios\\Audio.xml");
	XMLParser1->LoadDocument("Data\\Audios\\Audio.xml", Console1);

	// NewGame.xml
	//ElAudio = XMLParser1->Document->FirstChildElement("Audio");
	ElAudio = XMLParser1->GetDataElement();

	ParseSoundtrack(ElAudio);
	ParseSound(ElAudio);

	MusicStream = Musics[MusicCount]->GetMusic();
}

// Parse XML soundtrack
void Audio::ParseSoundtrack(TiXmlElement* MainBlock)
{
	//
	TiXmlElement* Element = MainBlock->FirstChildElement("Soundtrack");

	while (Element != NULL)
	{
		//
		Musics.push_back( new Music(Element->Attribute("Source")) );
		if (Musics[Musics.size()-1]->Loaded == false)
			Musics.erase(Musics.end(), Musics.end());

		// Next
		Element = Element->NextSiblingElement("Soundtrack");
	}
}

// Parse XML sound
void Audio::ParseSound(TiXmlElement* MainBlock)
{
	//
	TiXmlElement* Element = MainBlock->FirstChildElement("Sound");

	while (Element != NULL)
	{
		//
		Sounds.push_back( new Sound(Element->Attribute("Source")) );
		if (Sounds[Sounds.size()-1]->Loaded == false)
			Sounds.erase(Sounds.end(), Sounds.end());

		// Next
		Element = Element->NextSiblingElement("Sound");
	}
}

// Play music
void Audio::PlayMusic() 
{
	MusicStream = Musics[MusicCount]->GetMusic();
	MusicStream->setVolume(float(Soundtrack));

	MusicStream->play();
}

// Stop music
void Audio::StopMusic()
{
	MusicStream->stop();
}

// Next music
void Audio::NextMusic()
{
	//
	if (MusicStream->getStatus() != sf::SoundSource::Stopped)
		StopMusic();

	if (RepeatMusicType == false)
	{
		if (RandomMusicType == false)
		{
			MusicCount++;
			if (MusicCount > Musics.size()-1)
				MusicCount = 0;
		}
		else
			RandomMusic();
	}

	PlayMusic();
}

// Back music
void Audio::BackMusic()
{
	//
	if (MusicStream->getStatus() != sf::SoundSource::Stopped)
		StopMusic();

	if (RepeatMusicType == false)
	{
		if (RandomMusicType == false)
		{
			MusicCount--;
			if (MusicCount < 0)
				MusicCount = 0;
		}
		else
			RandomMusic();
	}

	PlayMusic();
}


// Random music
void Audio::RandomMusic()
{
	//StopMusic();
	int MusicCountSave = MusicCount;
	while (MusicCount == MusicCountSave)
		MusicCount = GetRandomNumber(0, Musics.size()-1);

	//PlayMusic();
}

// Play sound
void Audio::PlaySound1(size_t Count)
{
	Sounds[Count]->GetSound()->setVolume(SoundEffects);
	Sounds[Count]->Play();
}

// Play sound (by Name) 
void Audio::PlaySound1(string Name)
{
	for (size_t i = 0; i < Sounds.size(); i++)
	{
		if (Sounds[i]->GetName() == Name)
		{
			Sounds[i]->GetSound()->setVolume(SoundEffects);
			Sounds[i]->Play();
		}
	}
}

// Stop sound
void Audio::StopSound1(size_t Count)
{
	Sounds[Count]->Stop();
}