#pragma once


#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Piece.h"
#include "InterfaceManager.h"
#include "ResourceManager.h"

class Tile
{
    public:
        sf::Shape tile_square;
        int px, py;
        bool status;
		void Update(int);
		Tile(int,int,int,int,int,sf::Color, sf::RenderWindow *, ResourceManager *);
        sf::Shape mouse_focus;
        sf::Shape mouse_target;
		sf::Sprite selector;
        int size;
    protected:
    private:
        sf::RenderWindow * wnd_ptr;
};
