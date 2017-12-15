#include "StdAfx.h"
#include "Tile.h"


Tile::Tile(int py,int px,int offset_x, int offset_y, int size, sf::Color square_color, sf::RenderWindow * wptr, ResourceManager * rm)
{
    //ctor
    this->wnd_ptr = wptr;
    this->px = px;
    this->py = py;
    this->size = size;
    this->tile_square = sf::Shape::Rectangle((float)px*size + offset_x,
                                          (float)py*size + offset_y,
                                            (float)px*size + offset_x + size,
                                            (float)py*size + offset_y + size,
                                             square_color, 0,
                                             square_color);
    this->mouse_target.SetPosition((float)px*size + offset_x,(float) py*size + offset_y);
	this->selector.SetImage(rm->GetImageResource(20));
	this->selector.Resize((float)size,(float)size);
	this->selector.SetPosition((float)px*size + offset_x, (float)py*size + offset_y);
}

void Tile::Update(int spike_count)
{
    if (wnd_ptr->GetInput().GetMouseX() > this->mouse_target.GetPosition().x
        && wnd_ptr->GetInput().GetMouseX() < this->mouse_target.GetPosition().x + this->size
        && wnd_ptr->GetInput().GetMouseY() > this->mouse_target.GetPosition().y
        && wnd_ptr->GetInput().GetMouseY() < this->mouse_target.GetPosition().y +this->size
        )
    {
		if(this->px < spike_count || this->py < spike_count)
		{
			//std::cout << "tile is under mouse focus\n\n";

			this->mouse_focus = sf::Shape::Rectangle(this->mouse_target.GetPosition().x,
												 this->mouse_target.GetPosition().y,
												 this->mouse_target.GetPosition().x + this->size,
												 this->mouse_target.GetPosition().y + this->size,
												 sf::Color(255,0,0,100), 0,
												 sf::Color(255,0,0,100));
		}
		else
		{
			//std::cout << "tile is under mouse focus\n\n";

			this->mouse_focus = sf::Shape::Rectangle(this->mouse_target.GetPosition().x,
												 this->mouse_target.GetPosition().y,
												 this->mouse_target.GetPosition().x + this->size,
												 this->mouse_target.GetPosition().y + this->size,
												 sf::Color(0,255,0,100), 0,
												 sf::Color(0,255,0,100));
		}
        //wnd_ptr->Draw(mouse_focus);
		wnd_ptr->Draw(this->selector);
		
    }
	
}
