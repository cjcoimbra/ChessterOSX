#pragma once

class AudioManager
{
public:
	AudioManager(void);
	~AudioManager(void);

	sf::SoundBuffer combo_label_buffer;
	sf::Sound combo_label_sound;

	sf::SoundBuffer menu_select_buffer;
	sf::Sound menu_select_sound;

	sf::SoundBuffer piece_destruction_buffer;
	sf::Sound piece_destruction_sound;

	sf::SoundBuffer reference_buttons_buffer;
	sf::Sound reference_buttons_sound;

	sf::SoundBuffer spike_buffer;
	sf::Sound spike_sound;

	sf::SoundBuffer treasure_buffer;
	sf::Sound treasure_sound;

	sf::SoundBuffer title_buffer;
	sf::SoundBuffer dungeon_buffer;
	sf::Sound background_sound;

	void PlaySoundEffect(int);
	void PlayMusic(int);
};
