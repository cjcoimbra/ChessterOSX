#include "StdAfx.h"
#include "Piece.h"


Piece::Piece(int gid, int id, sf::RenderWindow * rw, ResourceManager * rm, float factor, float tileSize)
{
    this->following_mouse = false;
    this->wnd_ptr = rw;
    this->general_id = gid;
    this->resource_manager = rm;
    this->sprite_id = id;
	this->backup_sprite_id = id;
	this->tile_size = tileSize;
	this->is_destructing = false;
	this->is_breaking_block = false;
	this->is_capturing_treasure = false;
	this->is_special_spawn = false;
	this->isDroppingDownFromRespawn = false;
	
	piece_spt.Resize(tile_size, tile_size);

    this->tile_size = tile_size * factor;
		if (this->sprite_id == 28) //Special case in which the piece as the block from Puzzle Game Mode
	{
		piece_spt.SetImage(resource_manager->GetImageResource(75));
		isPuzzleMode = true;
	}
	else
	{
		piece_spt.SetImage(resource_manager->GetImageResource(this->sprite_id));
		isPuzzleMode = false;
	}
	
	//setting up some frames for animation
	for (int b = 0; b < 6; b++) //for each kind of piece
	{	
		for (int i = 0; i < 17; i++) // for each frame of it's animation
		{
			int base_id;

			if (b == 3) // bishop
				base_id = 100;
			else if (b == 0) // pawn
				base_id = 200;
			else if (b == 1) //knight
				base_id = 300;
			else if (b == 2) //rook
				base_id = 400;
			else if (b == 4) //king
				base_id = 500;
			else if (b == 5) //queen
				base_id = 600;

			base_id += i;
			this->new_destruction_spt[b][i].SetImage(resource_manager->GetImageResource(base_id));
			this->new_destruction_spt[b][i].Resize((float)this->tile_size * 3,(float) this->tile_size * 3);
		}
	}

    //piece_spt.Scale(factor,factor);
	piece_spt.Resize(this->tile_size,this->tile_size);
    offset_x = (float)wnd_ptr->GetWidth()/2 - 4 * tile_size;
    offset_y = (float)wnd_ptr->GetHeight()/2 - 4 * tile_size;
    this->valid = true;
    //std::cout << "Piece Tile Size: " << tile_size << "\n\n";
    this->fall_down_rate = 200;
    this->is_falling_down = false;
    this->total_fall = 0;
	this->just_respawned = false;
	this->moved = false;
	//this->restTime = 0;
}

Piece::~Piece(void)
{
	//delete this;
}

void Piece::StartBlockDestruction()
{
	for (int i = 0; i < 20; i++)
	{
		this->block_destruction_spt[i].SetPosition( this->piece_spt.GetPosition().x - tile_size, this->piece_spt.GetPosition().y - tile_size);
	}
	this->block_animation_frame = 0;
	this->is_breaking_block = true;
	this->is_capturing_treasure = false;
	this->block_animation_timer.Reset();
}


void Piece::StartSpecialSpawnAnimation()
{
	for (int i = 0; i < 30; i++)
	{
		this->special_spawn_spt[i].SetPosition( this->piece_spt.GetPosition().x - tile_size, this->piece_spt.GetPosition().y - tile_size);
	}
	this->special_spawn_animation_frame = 0;
	this->is_special_spawn = true;
	//this->is_capturing_treasure = false;
	//this->is_breaking_block = false;
	this->special_spawn_animation_timer.Reset();
}



void Piece::AnimateSpecialSpawn()
{
	if (this->special_spawn_animation_timer.GetElapsedTime() >= 0.02f)
	{
		if (this->special_spawn_animation_frame < 29)
			this->special_spawn_animation_frame++;
		else
		{
			//End animation
			this->is_special_spawn = false;
		}
		this->special_spawn_animation_timer.Reset();
	}
}

void Piece::StartTreasureCapture()
{
	for (int i = 0; i < 20; i++)
	{
		this->treasure_capture_spt[i].SetPosition( this->piece_spt.GetPosition().x - tile_size, this->piece_spt.GetPosition().y - tile_size);
	}
	this->treasure_capture_frame = 0;
	this->is_capturing_treasure = true;
	this->is_breaking_block = false;
	this->treasure_animation_timer.Reset();
}


void Piece::AnimateBlockDestruction()
{
	if (this->block_animation_timer.GetElapsedTime() >= 0.02f)
	{
		if (this->block_animation_frame < 19)
			this->block_animation_frame++;
		else
		{
			//End animation
			this->is_breaking_block = false;
			this->valid = false;

		}
		this->block_animation_timer.Reset();
	}
}

void Piece::AnimateTreasureCapture()
{
	if (this->treasure_animation_timer.GetElapsedTime() >= 0.02f)
	{
		if (this->treasure_capture_frame < 19)
			this->treasure_capture_frame++;
		else
		{
			//End animation
			this->is_capturing_treasure = false;
			this->valid = false;

		}
		this->treasure_animation_timer.Reset();
	}
}

bool Piece::VerifySelection(int abs_x, int abs_y)
{
    //std::cout << "Clicked Position (" << abs_x <<"," << abs_y << ")\n\n";
	if (this->moved)
		return false;

    this->original_position.x = this->piece_spt.GetPosition().x;
    this->original_position.y = this->piece_spt.GetPosition().y;

    //int mx = abs_x/tile_size - offset_x ;
    //int my = abs_y/tile_size - offset_y;

    if (abs_x > this->piece_spt.GetPosition().x && abs_x < this->piece_spt.GetPosition().x + tile_size
        && abs_y > this->piece_spt.GetPosition().y && abs_y < this->piece_spt.GetPosition().y + tile_size
         && this->following_mouse == false)
    {
		this->following_mouse = true;
		//std::cout << "Piece #" << this->general_id << " selected\n\n";
		return true;
    }
    else
        return false;
}

bool Piece::IsFocused(int abs_x, int abs_y)
{
    if (abs_x > this->piece_spt.GetPosition().x && abs_x < this->piece_spt.GetPosition().x + tile_size
        && abs_y > this->piece_spt.GetPosition().y && abs_y < this->piece_spt.GetPosition().y + tile_size
         && this->following_mouse == false)
    {
        return true;
    }
    else
        return false;
}

void Piece::RelocateKilledPiece(sf::Vector2i new_spot)
{
	this->px = new_spot.x;
    this->py = new_spot.y;
	this->piece_spt.SetPosition(this->offset_x + this->tile_size * this->px, this->offset_y + this->tile_size *this->py);
}

bool Piece::IsMoveAllowed(int target_x, int target_y)
{
    unsigned int i;

    for (i = 0; i < this->allowedMoves.size() ; i ++)
    {
        if (target_x == allowedMoves[i].x && target_y == allowedMoves[i].y)
        {
            return true;
        }
    }
    return false;
}

bool Piece::VerifyLandingSquare(int target_x, int target_y)
{
	unsigned int i;

    for (i = 0; i < this->allowedMoves.size() ; i ++)
    {
        if (target_x == allowedMoves[i].x && target_y == allowedMoves[i].y)
        {

            this->px = target_x;
            this->py = target_y;
            this->following_mouse = false;
            this->piece_spt.SetPosition(this->offset_x + this->tile_size * this->px, this->offset_y + this->tile_size *this->py);
            this->RefreshAllowedMoves();
			this->moved = true;
            //std::cout << allowedMoves[i].x << ", " << allowedMoves[i].y << "\n\n";
            return true;
        }
    }
    return false;
}

bool Piece::VerifyDeselection()
{
    if (this->following_mouse)
    {
        this->piece_spt.SetPosition(this->original_position.x, this->original_position.y);

        this->following_mouse = false;
        //std::cout << "Piece #" << this->general_id << " unselected\n\n";
        return true;
    }
    else
        return false;
}

void Piece::RefreshAllowedMoves()
{
    this->allowedMoves.clear();

    switch (this->sprite_id)
    {
        case 0: // Pawn
            if (this->py > 0)
            {
                this->allowedMoves.push_back(sf::Vector2i(this->px, this->py - 1));
                if (this->px > 0)
                    this->allowedMoves.push_back(sf::Vector2i(this->px-1, this->py - 1));
                if (this->px < 7)
                    this->allowedMoves.push_back(sf::Vector2i(this->px+1, this->py - 1));
            }
            /*
            std::cout << "Piece #" << this->general_id <<" Allowed Moves: " << allowedMoves.size() << "\n\n";
            int i;
            for (i=0; i < this->allowedMoves.size(); i++)
            {
                std::cout << "Valid Move #" << i << " (" << allowedMoves[i].x << "," << allowedMoves[i].y << ")\n\n";
            }
            */
        break;

        case 1: //knight
            if (this->px-1 >= 0 && this->py-2 >= 0)
                this->allowedMoves.push_back(sf::Vector2i(this->px - 1, this->py - 2));
            if (this->px+1 <= 7 && this->py-2 >= 0)
                this->allowedMoves.push_back(sf::Vector2i(this->px + 1, this->py - 2));
            if (this->px-2 >= 0 && this->py-1 >= 0)
                this->allowedMoves.push_back(sf::Vector2i(this->px - 2, this->py - 1));
            if (this->px+2 <= 7 && this->py-1 >= 0)
                this->allowedMoves.push_back(sf::Vector2i(this->px + 2, this->py - 1));
            if (this->px-2 >= 0 && this->py+1 <= 7)
                this->allowedMoves.push_back(sf::Vector2i(this->px - 2, this->py + 1));
            if (this->px-1 >= 0 && this->py+2 <= 7)
                this->allowedMoves.push_back(sf::Vector2i(this->px - 1, this->py + 2));
            if (this->px+1 <= 7 && this->py+2 <= 7)
                this->allowedMoves.push_back(sf::Vector2i(this->px + 1, this->py + 2));
            if (this->px+2 <= 7 && this->py+1 <= 7)
                this->allowedMoves.push_back(sf::Vector2i(this->px + 2, this->py + 1));

            //std::cout << "Piece #" << this->general_id <<" Allowed Moves: " << allowedMoves.size() << "\n\n";
        break;

        case 2: //rook
            int column;
            for (column=this->px-7; column <= this->px+7; column++)
            {
                if (column >= 0 && column <= 7 )
                    this->allowedMoves.push_back(sf::Vector2i(column, this->py));
            }

            int line;
            for (line=this->py-7; line <= this->py+7; line++)
            {
                if (line >= 0 && line <= 7 )
                    this->allowedMoves.push_back(sf::Vector2i(this->px, line));
            }
        break;

        case 3: //bishop
            int i;
            for (i=1;i<=7;i++)
            {
                if (this->px - i >=0 && this->py - i >=0)
                    this->allowedMoves.push_back(sf::Vector2i(this->px - i, this->py - i));
            }
            for (i=1;i<=7;i++)
            {
                if (this->px + i <=7 && this->py + i <=7)
                    this->allowedMoves.push_back(sf::Vector2i(this->px + i, this->py + i));
            }
            for (i=1;i<=7;i++)
            {
                if (this->px - i >=0 && this->py + i <=7)
                    this->allowedMoves.push_back(sf::Vector2i(this->px - i, this->py + i));
            }
            for (i=1;i<=7;i++)
            {
                if (this->px + i <=7 && this->py - i >=0)
                    this->allowedMoves.push_back(sf::Vector2i(this->px + i, this->py - i));
            }

        break;

        case 4: // king
            if (this->px-1 >= 0 && this->py-1 >= 0)
                this->allowedMoves.push_back(sf::Vector2i(this->px-1, this->py-1));
            if (this->py-1 >= 0)
                this->allowedMoves.push_back(sf::Vector2i(this->px, this->py-1));
            if (this->px+1 <= 7 && this->py-1 >= 0)
                this->allowedMoves.push_back(sf::Vector2i(this->px+1, this->py-1));
            if (this->px+1 <= 7)
                this->allowedMoves.push_back(sf::Vector2i(this->px+1, this->py));
            if (this->px+1 <= 7 && this->py+1 <= 7)
                this->allowedMoves.push_back(sf::Vector2i(this->px+1, this->py+1));
            if (this->py+1 <= 7)
                this->allowedMoves.push_back(sf::Vector2i(this->px, this->py+1));
            if (this->px-1 >= 0 && this->py+1 <= 7)
                this->allowedMoves.push_back(sf::Vector2i(this->px-1, this->py+1));
            if (this->px-1 >= 0)
                this->allowedMoves.push_back(sf::Vector2i(this->px-1, this->py));
        break;

        case 5: // le derp queen

            //Rook movement part
            for (column=this->px-7; column <= this->px+7; column++)
            {
                if (column >= 0 && column <= 7 )
                    this->allowedMoves.push_back(sf::Vector2i(column, this->py));
            }

            for (line=this->py-7; line <= this->py+7; line++)
            {
                if (line >= 0 && line <= 7 )
                    this->allowedMoves.push_back(sf::Vector2i(this->px, line));
            }

            //Bishop movement part
            for (i=1;i<=7;i++)
            {
                if (this->px - i >=0 && this->py - i >=0)
                    this->allowedMoves.push_back(sf::Vector2i(this->px - i, this->py - i));
            }
            for (i=1;i<=7;i++)
            {
                if (this->px + i <=7 && this->py + i <=7)
                    this->allowedMoves.push_back(sf::Vector2i(this->px + i, this->py + i));
            }
            for (i=1;i<=7;i++)
            {
                if (this->px - i >=0 && this->py + i <=7)
                    this->allowedMoves.push_back(sf::Vector2i(this->px - i, this->py + i));
            }
            for (i=1;i<=7;i++)
            {
                if (this->px + i <=7 && this->py - i >=0)
                    this->allowedMoves.push_back(sf::Vector2i(this->px + i, this->py - i));
            }
        break;
		case 6:
			//Block - do nothing
			break;
    }
}


void Piece::Update()
{
    if (this->valid)
    {
		if (this->following_mouse)
			this->piece_spt.SetPosition((float)wnd_ptr->GetInput().GetMouseX() - this->tile_size/2, (float)wnd_ptr->GetInput().GetMouseY() - this->tile_size/2);
		//Normal drop down
		if (this->is_falling_down && this->total_fall < this->amount_to_fall)
		{	
			float frame_fall = this->fall_down_rate * this->wnd_ptr->GetFrameTime();
			//this->total_fall += this->fall_down_rate * this->wnd_ptr->GetFrameTime();
			this->total_fall += frame_fall;
			if (!this->just_respawned)
				this->piece_spt.SetPosition(this->piece_spt.GetPosition().x, this->piece_spt.GetPosition().y + frame_fall);	
		}
		else if (this->is_falling_down && this-> total_fall >= this->amount_to_fall)
		{
			if (!this->just_respawned)
			{
				//Drop down has finished
				this->piece_spt.SetPosition(this->piece_spt.GetPosition().x, original_y + amount_to_fall);	
				this->total_fall = 0;
				this->is_falling_down = false;
				
			}
			else 
				this->just_respawned = false;
		}
		//Drop down on respawn
		if (this->isDroppingDownFromRespawn && this->total_fall < this->amount_to_fall)
		{	
			float frame_fall = this->fall_down_rate * this->wnd_ptr->GetFrameTime();
			this->total_fall += frame_fall;
			this->piece_spt.SetPosition(this->piece_spt.GetPosition().x, this->piece_spt.GetPosition().y + frame_fall);	
		}
		else if (this->isDroppingDownFromRespawn && this-> total_fall >= this->amount_to_fall)
		{
			//Drop down has finished
			//this->piece_spt.SetPosition(this->piece_spt.GetPosition().x, original_y);	
			this->piece_spt.SetPosition(this->offset_x + this->tile_size * this->px, this->offset_y + this->tile_size *this->py);
			this->total_fall = 0;
			this->isDroppingDownFromRespawn = false;
		}

		if (this->is_destructing)
		{
			
			if (this->sprite_id >= 0 && this->sprite_id < 6)
			{
				this->new_destruction_spt[this->sprite_id][this->current_frame].SetPosition((float)this->piece_spt.GetPosition().x - this->tile_size,(float) this->piece_spt.GetPosition().y - this->tile_size);
				this->new_destruction_spt[this->sprite_id][this->current_frame].Resize((float)this->tile_size * 3,(float) this->tile_size * 3);
				wnd_ptr->Draw(this->new_destruction_spt[this->sprite_id][this->current_frame]);
			}
			else
			{
				this->new_destruction_spt[this->backup_sprite_id][this->current_frame].SetPosition((float)this->piece_spt.GetPosition().x - this->tile_size,(float) this->piece_spt.GetPosition().y - this->tile_size);
				this->new_destruction_spt[this->backup_sprite_id][this->current_frame].Resize((float)this->tile_size * 3,(float) this->tile_size * 3);
				wnd_ptr->Draw(this->new_destruction_spt[this->backup_sprite_id][this->current_frame]);
			}
			this->UpdateDestructionAnimation();
		}
		else
			wnd_ptr->Draw(this->piece_spt);
    }
	else
	{
		if (this->is_breaking_block)
		{
			wnd_ptr->Draw(this->block_destruction_spt[block_animation_frame]);
			this->AnimateBlockDestruction();
		}
		else if (this->is_capturing_treasure)
		{
			wnd_ptr->Draw(this->treasure_capture_spt[treasure_capture_frame]);
			this->AnimateTreasureCapture();
		}
	}
	if (this->is_special_spawn)
	{
		wnd_ptr->Draw(this->special_spawn_spt[special_spawn_animation_frame]);
			this->AnimateSpecialSpawn();
	}
}


void Piece::UpdateDestructionAnimation()
{
	if (this->destruction_timer.GetElapsedTime() >= 0.02f)
	{
		if (this->current_frame < 16)
			this->current_frame++;

		this->destruction_timer.Reset();
	}
}

void Piece::StartDestructionAnimation()
{
	this->current_frame = 0;
	this->destruction_timer.Reset();
	this->is_destructing = true;
}

void Piece::StartDropDown(int dropdown_coeficient)
{
	if(dropdown_coeficient > 0)
	{
		this->fall_down_rate = 160;
		//This is for the staggered falldown effect
		if (dropdown_coeficient == 1)
			this->fall_down_rate = 160;
			//this->fall_down_rate = 240;
		else if (dropdown_coeficient == 2)
			this->fall_down_rate = 170;
			//this->fall_down_rate = 250;
		else if (dropdown_coeficient == 3)
			this->fall_down_rate = 180;
			//this->fall_down_rate = 260;
		else if (dropdown_coeficient == 4)
			this->fall_down_rate = 190;
			//this->fall_down_rate = 270;
		else if (dropdown_coeficient == 5)
			this->fall_down_rate = 200;
			//this->fall_down_rate = 280;
		else if (dropdown_coeficient == 6)
			this->fall_down_rate = 210;
			//this->fall_down_rate = 290;

		if (this->py == 6)
			//this->fall_down_rate += 256;
			this->fall_down_rate += 256;
		else if (this->py == 5)
			//this->fall_down_rate += 128;
			this->fall_down_rate += 242;
		else if (this->py == 4)
			//this->fall_down_rate += 64;
			this->fall_down_rate += 230;
		else if (this->py == 3)
			//this->fall_down_rate += 32;
			this->fall_down_rate += 206;
		else if (this->py == 2)
			//this->fall_down_rate += 16;
			this->fall_down_rate += 160;
		else if (this->py == 1)
			//this->fall_down_rate += 8;
			this->fall_down_rate += 124;
		else if (this->py == 0)
			//this->fall_down_rate += 4;
			this->fall_down_rate += 100;

		this->is_falling_down = true;
		this->total_fall = 0;
		this->amount_to_fall = dropdown_coeficient * this->tile_size;
		this->original_y = piece_spt.GetPosition().y;
		this->py += dropdown_coeficient;
		this->RefreshAllowedMoves();
		
	}
	else if (dropdown_coeficient < 0)
	{
		this->py += dropdown_coeficient;
		this->piece_spt.SetPosition(this->offset_x + this->tile_size * this->px, this->offset_y + this->tile_size *this->py);
	}
}

void Piece::StartDropDownForRespawn()
{
	this->fall_down_rate = 300;
	
	if (this->py == 6)
		//this->fall_down_rate += 256;
		this->fall_down_rate += 256;
	else if (this->py == 5)
		//this->fall_down_rate += 128;
		this->fall_down_rate += 242;
	else if (this->py == 4)
		//this->fall_down_rate += 64;
		this->fall_down_rate += 230;
	else if (this->py == 3)
		//this->fall_down_rate += 32;
		this->fall_down_rate += 206;
	else if (this->py == 2)
		//this->fall_down_rate += 16;
		this->fall_down_rate += 160;
	else if (this->py == 1)
		//this->fall_down_rate += 8;
		this->fall_down_rate += 124;
	else if (this->py == 0)
		//this->fall_down_rate += 4;
		this->fall_down_rate += 100;

	//this->is_falling_down = true;
	this->original_y = 0;
	this->total_fall = 0;
	this->amount_to_fall = this->tile_size + this->offset_y + (2*(this->py * tile_size));
	this->original_y = piece_spt.GetPosition().y;

	this->piece_spt.SetPosition(sf::Vector2f(this->piece_spt.GetPosition().x ,0 - tile_size - (this->tile_size * this->py)));
	this->isDroppingDownFromRespawn = true;
}

void Piece::RespawnPieceAsTreasure(int t_id)
{
	this->sprite_id = 7;
	this->treasure_id = t_id;

	piece_spt.Resize(this->tile_size,this->tile_size);

	if (treasure_id == 0)
		this->piece_spt.SetImage(resource_manager->GetImageResource(61));
	else if (treasure_id == 1)
		this->piece_spt.SetImage(resource_manager->GetImageResource(62));
	else if (treasure_id == 2)
		this->piece_spt.SetImage(resource_manager->GetImageResource(63));
	else if (treasure_id == 3)
		this->piece_spt.SetImage(resource_manager->GetImageResource(64));
	

	piece_spt.Resize(this->tile_size,this->tile_size);

	//this->RefreshAllowedMoves();
	//this->RefreshAnimationFrames();
	this->valid = true;
	this->is_destructing = false;
}

void Piece::Respawn(int sprite)
{
	int random_piece_id;
	if (isPuzzleMode)//Puzzle mode only spawns those silver blocks
	{
		random_piece_id = 28;
	}
	else //Regular game mode
		{
		if (sprite == -1)
		{
			//Spawn any piece
			random_piece_id = sf::Randomizer::Random(0, 5);
			if(random_piece_id == 5)
				random_piece_id = 6;
		}
		else if (sprite == -2)
		{
			//Spawn a queen piece
			random_piece_id = 5;
		}
		else if (sprite == -28) //Puzzle Block
		{
			random_piece_id = 28;
		}
		else
		{
			//Spawn any piece but the one forbidden by the sprite_id used as parameter
			int total_tries = 0;
			do 
			{
				total_tries++;
				random_piece_id = sf::Randomizer::Random(0, 4);
			}
			while (random_piece_id == sprite && total_tries < 6);
		}
	}
	this->sprite_id = random_piece_id;
	if (this->sprite_id == 28) //Special case in which the piece as the block from Puzzle Game Mode
		this->piece_spt.SetImage(resource_manager->GetImageResource(75));
	else
		this->piece_spt.SetImage(resource_manager->GetImageResource(this->sprite_id));
	this->RefreshAllowedMoves();
	this->RefreshAnimationFrames();
	this->valid = true;
	this->is_destructing = false;
	this->StartDropDownForRespawn();
}

void Piece::RespawnOnStart(int sprite)
{
	int random_piece_id;
	if (isPuzzleMode)//Puzzle mode only spawns those silver blocks
	{
		random_piece_id = 28;
	}
	else //Regular game mode
		{
		if (sprite == -1)
		{
			//Spawn any piece
			random_piece_id = sf::Randomizer::Random(0, 5);
			if(random_piece_id == 5)
				random_piece_id = 6;
		}
		else if (sprite == -2)
		{
			//Spawn a queen piece
			random_piece_id = 5;
		}
		else if (sprite == -28) //Puzzle Block
		{
			random_piece_id = 28;
		}
		else
		{
			//Spawn any piece but the one forbidden by the sprite_id used as parameter
			int total_tries = 0;
			do 
			{
				total_tries++;
				random_piece_id = sf::Randomizer::Random(0, 4);
			}
			while (random_piece_id == sprite && total_tries < 11);
		}
	}
	this->sprite_id = random_piece_id;
	if (this->sprite_id == 28) //Special case in which the piece as the block from Puzzle Game Mode
		this->piece_spt.SetImage(resource_manager->GetImageResource(75));
	else
		this->piece_spt.SetImage(resource_manager->GetImageResource(this->sprite_id));
	this->RefreshAllowedMoves();
	this->RefreshAnimationFrames();
	this->valid = true;
	this->is_destructing = false;
}