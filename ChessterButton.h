#pragma once

class ChessterButton
{
public:

	sf::Sprite normal_texture;
	sf::Sprite mouse_over_texture;
	std::string type;
	sf::Vector2i position;
	int width;
	int height;
	
	ChessterButton();
};
