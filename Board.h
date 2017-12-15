#pragma once


#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "Tile.h"
#include <iostream>

class Board
{
    public:
        Tile * board_tile[8][8];
        Board(sf::RenderWindow *, ResourceManager *, float);
        void ScaleBackground(float,float);
        void CreateGameBoard();
        void Update(int);
        void ScaleTiles(float);
        sf::Sprite current_board;
		sf::Sprite current_gameboard;
		sf::Sprite current_gameboard_alpha;
		sf::Sprite board_frame;
		sf::Sprite piece_selector;
        int offset_x;
        int offset_y;
        float tile_size;
		void ConfigBoard(int);
    protected:
    private:

        sf::RenderWindow *wnd_ptr;
        ResourceManager * resource_manager;
        float tile_size_factor;

};
