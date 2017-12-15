#pragma once

class AnimatedSpike
{
public:
	void LoadSavedSpikes(int);
	AnimatedSpike(void);
	void ResetSpikes();
	void Init(sf::RenderWindow *, ResourceManager *, float);
	~AnimatedSpike(void);
	sf::RenderWindow *wnd_ptr;
	ResourceManager *rm;
	sf::Sprite vertical_spike[8][11];
	sf::Sprite horizontal_spike[8][11];
	int current_frame_of_spike[8];
	bool spikes[8];
	int spike_count;
	sf::Clock spike_animation_timer;
	void AddSpike();
	void RemoveSpikes();
	void DrawSpikes();
	void UpdateSpikes();
	bool is_adding_spike;
	bool is_removing_spike;
	float tile_size;
	void ResetAnimationFrames();
};
