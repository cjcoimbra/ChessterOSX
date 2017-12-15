#pragma once

class CreditsView
{
public:
	CreditsView(void);
	~CreditsView(void);
	void Init(sf::RenderWindow *, ResourceManager *);
	void Update();
	sf::String credits[9];
	sf::RenderWindow *wnd_ptr;
	ResourceManager *rm;
	sf::Font chesster_font;
};
