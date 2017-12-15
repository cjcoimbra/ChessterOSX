#pragma once

class TutorialView
{
public:
	TutorialView(void);
	void Init(sf::RenderWindow *, ResourceManager *);
	/*
	void NextEvent();
	void BackEvent();
	void EscapeEvent();
	bool IsTutorialFinished();
	bool isTutorialFinished;
	sf::Sprite tutorial_spt[10];
	sf::String tutorial_text[10];
	int current_index;
	void DrawTutorialView();
	sf::String back;
	sf::String next;
	sf::String escape;
	*/
	sf::Font chesster_font;
	sf::Sprite close_button;
	sf::Sprite close_button_over;
	sf::Sprite next_arrow_button;
	sf::Sprite next_arrow_button_over;
	sf::Sprite tutorial_sheet;
	sf::String ingame_tutorial_text;
	void Reset();
	//sf::Shape shade;
	bool showTutorial;
	//std::string GetTextForTutorial(int);
	//void ConfigureSprite(int);
	int current_tutorial_stage;
	sf::RenderWindow *wnd_ptr;
	ResourceManager *rm;
	void SetTutorialStage(int);
	//void HandleTutorialButtonsEffects();
	//tutorial flags
	bool first_invalid_move;
	bool first_valid_move;
	bool piece_already_moved;
	bool second_valid_move;
	bool third_valid_move;
	bool first_turn_score;
	bool first_demand_taken;
	bool first_negative_score;
	bool first_queen;
	bool first_treasure;
	bool should_show_treasure_info;
	bool second_turn;
	~TutorialView(void);
};
