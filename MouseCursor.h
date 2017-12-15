#pragma once

class MouseCursor
{
public:
	MouseCursor(void);
	void Init(sf::RenderWindow *, ResourceManager *);
	void Update();
	sf::Sprite custom_cursor;
	~MouseCursor(void);
	sf::RenderWindow *wnd_ptr;
	ResourceManager *rm;
};
