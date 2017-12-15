#include "StdAfx.h"
#include "AudioManager.h"

AudioManager::AudioManager(void)
{
	if (!this->combo_label_buffer.LoadFromFile("SFX/combo_text_animation.ogg"))
	{
		// Error...
		std::cout << "Failed to load SFX\n";
	}
	this->combo_label_sound.SetBuffer(this->combo_label_buffer);

	if (!this->menu_select_buffer.LoadFromFile("SFX/menu_select_text.ogg"))
	{
		// Error...
		std::cout << "Failed to load SFX\n";
	}
	this->menu_select_sound.SetBuffer(this->menu_select_buffer);

	if (!this->piece_destruction_buffer.LoadFromFile("SFX/piece_destruct.ogg"))
	{
		// Error...
		std::cout << "Failed to load SFX\n";
	}
	this->piece_destruction_sound.SetBuffer(this->piece_destruction_buffer);

	if (!this->reference_buttons_buffer.LoadFromFile("SFX/reference_buttons.ogg"))
	{
		// Error...
		std::cout << "Failed to load SFX\n";
	}
	this->reference_buttons_sound.SetBuffer(this->reference_buttons_buffer);

	if (!this->spike_buffer.LoadFromFile("SFX/shutdown_spike.ogg"))
	{
		// Error...
		std::cout << "Failed to load SFX\n";
	}
	this->spike_sound.SetBuffer(this->spike_buffer);

	if (!this->treasure_buffer.LoadFromFile("SFX/treasure_destruct.ogg"))
	{
		// Error...
		std::cout << "Failed to load SFX\n";
	}
	this->treasure_sound.SetBuffer(this->treasure_buffer);

	if (!this->title_buffer.LoadFromFile("Music/title_placeholder.ogg"))
	{
		// Error...
		std::cout << "Failed to load Music\n";
	}

	if (!this->dungeon_buffer.LoadFromFile("Music/dungeon_placeholder.ogg"))
	{
		// Error...
		std::cout << "Failed to load Music\n";
	}
}

AudioManager::~AudioManager(void)
{
}

void AudioManager::PlayMusic(int music)
{
	switch(music)
	{
		case 0:
			this->background_sound.Stop();
			this->background_sound.SetBuffer(this->title_buffer);
			this->background_sound.SetLoop(true);
			//this->background_sound.SetVolume(0.7f);
			this->background_sound.Play();
			break;
		case 1:
			this->background_sound.Stop();
			this->background_sound.SetBuffer(this->dungeon_buffer);
			this->background_sound.SetLoop(true);
			//this->background_sound.SetVolume(0.7f);
			this->background_sound.Play();
			break;
	}
}

void AudioManager::PlaySoundEffect(int sfx)
{
	switch (sfx)
	{
		case 1:
			this->spike_sound.Play();
			break;
		case 2:
			this->piece_destruction_sound.Play();
			break;
		case 3:
			this->menu_select_sound.Play();
			break;
		case 4:
			this->spike_sound.Play();
			break;
		case 5:
			this->combo_label_sound.Play();
			break;
		case 6:
			this->treasure_sound.Play();
			break;
	}
}
