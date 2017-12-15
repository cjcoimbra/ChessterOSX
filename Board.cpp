#include "StdAfx.h"
#include "Board.h"


Board::Board(sf::RenderWindow *wnd, ResourceManager *rm, float max_t)
{
    //ctor
    wnd_ptr = wnd;
	resource_manager = rm;
    //current_board.SetImage(rm->GetImageResource(10));
	current_gameboard.SetImage(rm->GetImageResource(13));
	//current_gameboard_alpha.SetImage(rm->GetImageResource(14));
	//board_frame.SetImage(rm->GetImageResource(12));
	//piece_selector.SetImage(rm->GetImageResource(20));
    tile_size = max_t;

}

void Board::ConfigBoard(int level)
{
	current_board.SetImage(resource_manager->OnDemandLoadBackground(level));
	
	this->board_frame.SetImage(resource_manager->OnDemandLoadFrame(level));
	int x_factor = 994;
	int y_factor = 991;
	int offset_correction_x = 0;
	int offset_correction_y = 0;
	if (level == 3)
	{
		x_factor = 1072;
		y_factor = 1088;
		offset_correction_x = 16;
		offset_correction_y = 38;
	}
	this->board_frame.Resize((float)(tile_size_factor * x_factor), (float)(tile_size_factor * y_factor));
	
	this->board_frame.SetPosition((float)offset_x - offset_correction_x - (int)(100* tile_size_factor) , (float)offset_y - offset_correction_y - (int)(100 * tile_size_factor));
	
	this->current_gameboard_alpha.SetImage(resource_manager->OnDemandLoadBoardAlpha(level));
	this->current_gameboard_alpha.Resize((float)this->tile_size * 8, (float)this->tile_size * 8);
	this->current_gameboard_alpha.SetPosition((float)offset_x,(float) offset_y);
}

void Board::ScaleBackground(float x_factor, float y_factor)
{
	this->current_board.Scale(x_factor, y_factor);
	//board_frame.SetImage(rm->GetImageResource(12));
}

void Board::ScaleTiles(float factor)
{
    tile_size_factor = factor;
    this->tile_size = (float) tile_size * factor;
	std::cout << "Size of the tiles [" << this->tile_size << "]\n"; 

    offset_x = wnd_ptr->GetWidth()/2 - 4 * tile_size;
    offset_y = wnd_ptr->GetHeight()/2 - 4 * tile_size;

	//this->board_frame.Resize((int)(factor * 994), (int)(factor * 991));
	//this->board_frame.SetPosition(offset_x - (int)(100* factor) , offset_y - (int)(100 * factor));

	//this->current_gameboard.Resize(960*tile_size_factor, 960*tile_size_factor);
	this->current_gameboard.Resize((float)this->tile_size * 8, (float)this->tile_size * 8);
	
	//this->piece_selector.Resize(this->tile_size, this->tile_size);
	//std::cout << "Size of the piece selector [" << this->piece_selector.GetSize().x << "," << this->piece_selector.GetSize().y << "]\n";
	
	//this->current_gameboard_alpha.Resize(this->tile_size * 8, this->tile_size * 8);
	std::cout << "Size of the gameboard [" << this->current_gameboard.GetSize().x << "x" << this->current_gameboard.GetSize().y << "]\n";
	//this->current_gameboard.Scale(960 * tile_size_factor, 960 * tile_size_factor);
	this->current_gameboard.SetPosition((float)offset_x, (float)offset_y);
	//this->current_gameboard_alpha.SetPosition(offset_x, offset_y);

    //std::cout << "Board Tile Size: " << tile_size << "\n\n";
}

void Board::CreateGameBoard()
{
    int line, column;
    sf::Color square_color;

    for (line = 0; line < 8; line++)
    {
        for (column = 0; column < 8; column ++)
        {
            if (column % 2 == 0 && line % 2 == 0 || (column % 2 != 0 && line % 2 != 0) )
                square_color = sf::Color::White;
            else
                square_color = sf::Color::Black;

			board_tile[line][column] = new Tile(line, column, offset_x, offset_y, tile_size, square_color, wnd_ptr, resource_manager);
        }
    }
}

void Board::Update(int spike_count)
{
    int line, column;
	
	this->wnd_ptr->Draw(current_gameboard_alpha);

	this->wnd_ptr->Draw(current_gameboard);

	//this->wnd_ptr->Draw(board_frame);

	for (line = 0; line < 8; line++)
    {
        for (column = 0; column < 8; column ++)
        {
            //this->wnd_ptr->Draw(board_tile[line][column]->tile_square);
			board_tile[line][column]->Update(spike_count);
        }
    }

    /*
    sf::Shape rect;
    int i,k;
    for (i=0;i<8;i++)
    {
        for (k=0;k<8;k++)
        {
            if (k % 2 == 0 && i % 2 == 0 || (k % 2 != 0 && i % 2 != 0) )
                rect = sf::Shape::Rectangle(i*tile_size+offset_x,
                                            k*tile_size+offset_y,
                                            i*tile_size+offset_x+tile_size,
                                            k*tile_size+offset_y+tile_size,
                                            sf::Color::White, 0,
                                            sf::Color::White);
            else
                rect = sf::Shape::Rectangle(i*tile_size+offset_x,
                                            k*tile_size+offset_y,
                                            i*tile_size+offset_x+tile_size,
                                            k*tile_size+offset_y+tile_size,
                                            sf::Color(sf::Color(0,100,0)), 0,
                                            sf::Color(sf::Color(0,100,0)));
            wnd_ptr->Draw(rect);
        }
    }
    */
}
