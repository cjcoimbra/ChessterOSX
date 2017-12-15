#pragma once

class ScoresView
{
public:
	ScoresView(void);
	void Init(sf::RenderWindow *, ResourceManager *);
	~ScoresView(void);
	sf::RenderWindow *wnd_ptr;
	ResourceManager *rm;
	sf::Font chesster_font;
	void ConfigScoresView(std::string, std::string);
	sf::String scores[4];
	sf::String back_message;
	int local_record;
	int online_record;
	void Update();
};
