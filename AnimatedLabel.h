#pragma once

class AnimatedLabel
{
public:
	AnimatedLabel(void);
	void Init(sf::RenderWindow *, ResourceManager *);
	~AnimatedLabel(void);
	sf::RenderWindow *wnd_ptr;
	ResourceManager *rm;
	sf::Sprite combo_labels[13][17];
	sf::Sprite puzzle_solved[17];
	sf::Sprite puzzle_failed[17];

	void SetupPuzzleLabel(std::string);
	bool is_animating_puzzle_label;
	void DrawPuzzleLabel();
	void UpdatePuzzleLabel();
	std::string mode;

	bool is_animating;
	bool IsAnimating();
	void SetupNewLabel(int);
	int current_frame;
	int current_label_id;
	sf::Clock animation_timer;
	void DrawComboLabel();
	void UpdateLabel();
	bool is_visible;
	int GetSpriteIdByComboId(int);
};
