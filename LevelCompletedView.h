#pragma once

class LevelCompletedView
{
public:
	LevelCompletedView(void);
	sf::String level_name;
	sf::String total_score;
	sf::String message;
	sf::String exit_message;
	sf::String demo_string;
	sf::String facebook_string;
	sf::String indiedb_string;

	std::string current_view;
	
	void Init(sf::RenderWindow *, ResourceManager *);
	sf::RenderWindow *wnd_ptr;
	ResourceManager *rm;
	sf::Font chesster_font;
	void SetupVictoryView(int, std::string);
	void SetupDefeatView(int, std::string);
	void SetupIntroView(int, std::string);
	void Update();
	~LevelCompletedView(void);
};
