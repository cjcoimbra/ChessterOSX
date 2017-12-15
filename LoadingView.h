#pragma once

class LoadingView
{
public:
	LoadingView(sf::RenderWindow *, ResourceManager *);
	sf::RenderWindow *wnd_ptr;
	ResourceManager *rm;
	sf::Sprite loading_spt[17];
	int last_sprite_index;
	void AddNextSprite();
	void ShowLoading();

};
