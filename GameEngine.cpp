#include "StdAfx.h"
#include "GameEngine.h"


GameEngine::GameEngine()
{
	/*
	std::cout << "Supported video modes: \n";
	unsigned int VideoModesCount = sf::VideoMode::GetModesCount();
	for (unsigned int i = 0; i < VideoModesCount; ++i)
	{
		sf::VideoMode mode = sf::VideoMode::GetMode(i);
		std::cout << mode.Width << "x" << mode.Height << ", ";
	}
	*/

	//m_window_ptr = new sf::RenderWindow(sf::VideoMode::VideoMode(320,240), "CHESSTER - 0.93", sf::Style::Titlebar);
	m_window_ptr = new sf::RenderWindow(sf::VideoMode::GetMode(0), "CHESSTER - 0.931", sf::Style::Fullscreen);
    std::cout << "User resolution [" << m_window_ptr->GetWidth() << "," << m_window_ptr->GetHeight() << "]\n\n";

    
    resource_manager = new ResourceManager();

	m_window_ptr->EnableKeyRepeat(false);
    m_window_ptr->SetFramerateLimit(60);

    some_piece_is_selected = false;

    max_width = 1920;
    max_height = 1080;
    max_tile_size = 100;
	
	board = new Board(m_window_ptr, resource_manager, max_tile_size);
    //board->ScaleBackground(m_window_ptr->GetWidth()/max_width, m_window_ptr->GetHeight()/max_height);
    //tile_size_factor = (m_window_ptr->GetWidth()/m_window_ptr->GetHeight()) / (max_width/max_height);
	tile_size_factor = ((m_window_ptr->GetWidth()*100)/max_width)/100;
	std::cout << "Piece scale factor of [" << tile_size_factor << "]\n"; 
    board->ScaleTiles(tile_size_factor);
    board->CreateGameBoard();

    //std::cout << "Tiles are scaled to " << tile_size_factor << " of the max size" << "\n\n";

    gui = new InterfaceManager(m_window_ptr, resource_manager, tile_size_factor, max_tile_size);
    this->ConfigureBackground(0);
	last_background = "start";
	//gui->title_screen_spt.Scale(m_window_ptr->GetWidth()/max_width, m_window_ptr->GetHeight()/max_height);
	
	combo_title.Init(m_window_ptr, resource_manager);
	animated_spikes.Init(m_window_ptr, resource_manager, max_tile_size*tile_size_factor);
	this->tutorial = new TutorialView();
	this->tutorial->Init(m_window_ptr, resource_manager);
	//tutorial.Init(m_window_ptr, resource_manager);
	ranking_view.Init(m_window_ptr, resource_manager);
	credits_view.Init(m_window_ptr, resource_manager);
	
    //RandomlyCreatePieces();
	is_still_removing_combos = false;
	is_dropping_down = false;
	combo_count = 0;
	this->temporary_match_points = 0;
	combo_points = 0;
	counting = false;
	
	m_window_ptr->ShowMouseCursor(false);
	cursor.Init(m_window_ptr, resource_manager);
	level_view.Init(m_window_ptr, resource_manager);
	
	this->ReadConfigFile();

	//GetOnlineRanking();

	game_state = -1;
	loading_timer.Reset();
	generic_x_marker.SetImage(resource_manager->GetImageResource(7));
	generic_x_marker.Resize(max_tile_size, max_tile_size);
	generic_x_marker.Scale(tile_size_factor, tile_size_factor);
	
	spike_count = 0;
		
	for (int i = 0; i < 8; i++)
		this->spikes[i] = false;
	
	
	for (int i = 0; i < 8; i++)
	{
		float spike_v_offset = m_window_ptr->GetWidth()/2 - 4 * tile_size_factor * max_tile_size;
		float spike_h_offset = m_window_ptr->GetHeight()/2 - 4 * tile_size_factor * max_tile_size;
		
		vertical_spike[i].SetImage(resource_manager->GetImageResource(15));
		horizontal_spike[i].SetImage(resource_manager->GetImageResource(16));

		vertical_spike[i].Resize(max_tile_size, max_tile_size * 8);
		horizontal_spike[i].Resize(max_tile_size * 8, max_tile_size);

		vertical_spike[i].Resize(max_tile_size * tile_size_factor, max_tile_size * tile_size_factor * 8);
		horizontal_spike[i].Resize(max_tile_size * tile_size_factor * 8, max_tile_size * tile_size_factor);
		
		vertical_spike[i].SetPosition(spike_v_offset + max_tile_size * tile_size_factor * i, spike_h_offset );
		horizontal_spike[i].SetPosition(spike_v_offset , spike_h_offset + max_tile_size * tile_size_factor * i);
	}

	int tile_size = max_tile_size * tile_size_factor;
	int offx = (m_window_ptr->GetWidth()/2) - 4 * tile_size ;
	int offy = (m_window_ptr->GetHeight()/2) - 4 * tile_size;
	
	for (int i=0;i<8;i++)
    {
        for (int k=0;k<8;k++)
        {
			move_hint[i][k] = sf::Shape::Rectangle(i * tile_size + offx ,
                                        k * tile_size + offy,
                                        i * tile_size + offx + tile_size,
                                        k * tile_size + offy + tile_size,
                                        sf::Color(sf::Color(0,120,0,70)), 0,
                                        sf::Color(sf::Color(0,120,0, 120)));
        }
    }
	
	running = true;
	//this->ConfigureConsole();
	
	this->loading_view = new LoadingView(m_window_ptr, resource_manager);

	this->isPuzzleMode = false;

	this->audio.PlayMusic(0);

}

void GameEngine::DelayedInit()
{
	//running = true;
}

void GameEngine::ReleasePiecesFromMemory()
{
	//Destroy all pieces array pointers
	for (int i = 0; i < 64; i++)
		this->game_pieces[i]->~Piece();
}

void GameEngine::GetOnlineRanking()
{
    /*
	std::cout << "Entered GetOnlineRanking\n";
	//Tests with HTTP requests using SFML network module
	this->online_record = "server is unavailable";
	
	
	sf::Http http;
	http.SetHost("www.spacecatstudio.com");
	sf::Http::Request request;
	request.SetMethod(sf::Http::Request::Get);
	std::string username = "username=Christian";
	std::string score = "score=0";
	std:: string uri = "/wp-content/uploads/2012/02/get_ranking.php?";
	uri =  uri + username;
	uri = uri + "&" + score;
	request.SetURI(uri);
	sf::Http::Response response;
	response = http.SendRequest(request);
	
	//std::cout << "\nPHP Response to Online Highest score is [ " << response.GetBody() << "]\n";
	
	if (response.GetStatus() == sf::Http::Response::Ok)
		this->online_record = response.GetBody();
	else
		this->online_record = "server is unavailable";
	
	
	std::cout << "Finished GetOnlineRanking\n";
     */
}

void GameEngine::ReadConfigFile()
{
	std::string record_lines[2];
	int index2 = 0;
	std::ifstream infile2;
	infile2.open ("Config/config_ext.txt");
        while(!infile2.eof()) 
        {
			std::getline(infile2,record_lines[index2]);
			//std::cout << file_lines[index] << "\n";
			index2++;
        }
	infile2.close();
	local_record = record_lines[0];
	std::cout << "Local Highest Score is [" << local_record << "]\n";

	//Config file
	std::string file_lines[8];
	int index = 0;
	std::ifstream infile;
	infile.open ("Config/config.txt");
        while(!infile.eof()) 
        {
			std::getline(infile,file_lines[index]);
			//std::cout << file_lines[index] << "\n";
			index++;
        }
	infile.close();

	//General config
	int pos;
	std::stringstream ss;

	//Demand
	pos = file_lines[0].find("=");
	pos++;
	ss << file_lines[0].substr(pos); 
	ss >> this->base_demand;
	//std::cout << "Base level demand set to: " << this->base_demand << "\n\n";
	ss.clear();

	//Moves
	pos = file_lines[1].find("=");
	pos++;
	ss << file_lines[1].substr(pos); 
	ss >> this->move_count;
	//std::cout << "Moves per turn amount set to: " << this->move_count << "\n\n";
	ss.clear();

	//Pieces values

	//Pawn
	pos = file_lines[2].find("=");
	pos++;
	ss << file_lines[2].substr(pos); 
	ss >> this->piece_values[0];
	//std::cout << "Pawn value set to: " << this->piece_values[0] << "\n";
	ss.clear();

	//Knight
	pos = file_lines[3].find("=");
	pos++;
	ss << file_lines[3].substr(pos); 
	ss >> this->piece_values[1];
	//std::cout << "Knight value set to: " << this->piece_values[1] << "\n";
	ss.clear();

	//Rook
	pos = file_lines[4].find("=");
	pos++;
	ss << file_lines[4].substr(pos); 
	ss >> this->piece_values[2];
	//std::cout << "Rook value set to: " << this->piece_values[2] << "\n";
	ss.clear();

	//Bishop
	pos = file_lines[5].find("=");
	pos++;
	ss << file_lines[5].substr(pos); 
	ss >> this->piece_values[3];
	//std::cout << "Bishop value set to: " << this->piece_values[3] << "\n";
	ss.clear();

	//King
	pos = file_lines[6].find("=");
	pos++;
	ss << file_lines[6].substr(pos); 
	ss >> this->piece_values[4];
	//std::cout << "King value set to: " << this->piece_values[4] << "\n";
	ss.clear();

	//Queen
	pos = file_lines[7].find("=");
	pos++;
	ss << file_lines[7].substr(pos); 
	ss >> this->piece_values[5];
	//std::cout << "Queen value set to: " << this->piece_values[5] << "\n";
	ss.clear();

	std::cout << "Finished reading configuration file...\n";
}

void GameEngine::RandomlyCreatePieces()
{
    //int amount_of_pieces = 64;
	int snapshot[8][8];
    int i = 0;

    int line, column;
    for (line = 0; line < 8; line++)
    {
        for (column = 0; column < 8; column ++)
        {
            int random_piece_id = sf::Randomizer::Random(0, 5);
			if (random_piece_id == 5)
				random_piece_id = 6;
            game_pieces[i] = new Piece(i, random_piece_id, m_window_ptr, resource_manager, tile_size_factor, max_tile_size);
            game_pieces[i]->px = board->board_tile[line][column]->px;
            game_pieces[i]->py = board->board_tile[line][column]->py;
            game_pieces[i]->piece_spt.SetPosition(game_pieces[i]->offset_x + game_pieces[i]->tile_size * game_pieces[i]->px, game_pieces[i]->offset_y + game_pieces[i]->tile_size * game_pieces[i]->py);
            game_pieces[i]->RefreshAllowedMoves();
            i++;
        }
    }
	
	for (int k = 0; k < 64; k++)
    {
        snapshot[game_pieces[k]->px][game_pieces[k]->py] = k;
    }
	
	int heuristic_coeficient = 10;
	for (int k = 0; k < heuristic_coeficient; k++)
	{
		for (int p = 0; p < 8; p++)
		{
			for (int j = 0; j < 8; j++) 
			{
				if (p < 6)
				{
					if (game_pieces[snapshot[p][j]]->sprite_id == game_pieces[snapshot[p+1][j]]->sprite_id && game_pieces[snapshot[p][j]]->sprite_id == game_pieces[snapshot[p+2][j]]->sprite_id) 
						game_pieces[snapshot[p][j]]->RespawnOnStart(game_pieces[snapshot[p][j]]->sprite_id);
				}
				if (j < 6)
				{
					if (game_pieces[snapshot[p][j]]->sprite_id == game_pieces[snapshot[p][j+1]]->sprite_id && game_pieces[snapshot[p][j]]->sprite_id == game_pieces[snapshot[p][j+2]]->sprite_id)
						game_pieces[snapshot[p][j]]->RespawnOnStart(game_pieces[snapshot[p][j]]->sprite_id);
				}
				if (p > 1)
				{
					if (game_pieces[snapshot[p][j]]->sprite_id == game_pieces[snapshot[p-1][j]]->sprite_id && game_pieces[snapshot[p][j]]->sprite_id == game_pieces[snapshot[p-2][j]]->sprite_id) 
						game_pieces[snapshot[p][j]]->RespawnOnStart(game_pieces[snapshot[p][j]]->sprite_id);
				}
				if (j > 1)
				{
					if (game_pieces[snapshot[p][j]]->sprite_id == game_pieces[snapshot[p][j-1]]->sprite_id && game_pieces[snapshot[p][j]]->sprite_id == game_pieces[snapshot[p][j-2]]->sprite_id)
						game_pieces[snapshot[p][j]]->RespawnOnStart(game_pieces[snapshot[p][j]]->sprite_id);
				}
			}
		}
	}

}

bool GameEngine::IsRunning()
{
    if (running) return true;
    else return false;
}
void GameEngine::Run()
{
    ProcessInput();
    Flush();
    Update();
	//std::cout << "Current Engine's state is [" << this->game_state << "]\n";
}

int GameEngine::GetGameState()
{
    return this->game_state;
}

void GameEngine::CountCombos()
{
	combo_counter.clear();

	for (int i = 0; i < 64; i++)
	{
		bool new_combo_found = true;
		if (pieces[game_pieces[i]->px][game_pieces[i]->py] == -1)
		{
			for (unsigned int x = 0; x < combo_counter.size(); x++)
			{
				if (combos[game_pieces[i]->sprite_id][game_pieces[i]->px][game_pieces[i]->py] == combo_counter[x].combo_id)
				{
					combo_counter[x].amount++;
					combo_counter[x].ids.push_back(i);
					//std::cout << "\nExisting combo " <<  combo_counter[x].combo_id << " incremented to " << combo_counter[x].amount;
					new_combo_found = false;
				}
			}
			if (new_combo_found)
			{
				
				int piece_type;
				int current_combo = combos[game_pieces[i]->sprite_id][game_pieces[i]->px][game_pieces[i]->py];
				if (current_combo >= 400 && current_combo < 500)
					piece_type = 0;
				else if (current_combo >= 500 && current_combo < 600)
					piece_type = 1;
				else if (current_combo >= 600 && current_combo < 700)
					piece_type = 2;
				else if (current_combo >= 700 && current_combo < 800)
					piece_type = 3;
				else if (current_combo >= 800 && current_combo< 900)
					piece_type = 4;
				else if (current_combo >= 900 && current_combo < 1000)
					piece_type = 5;
				else if (current_combo >= 1000 && current_combo < 1100)
					piece_type = 8;
				else if (current_combo >= 1100 && current_combo < 1200)
					piece_type = 9;
				else if (current_combo >= 1200 && current_combo < 1300)
					piece_type = 10;
				else if (current_combo >= 1300 && current_combo < 1400)
					piece_type = 11;
				else if (current_combo >= 1400 && current_combo < 1500)
					piece_type = 12;

				//std::cout << "\nNew combo added: " << current_combo << " / Sprite_id: " << piece_type;
				combo_counter.push_back(Combo(combos[game_pieces[i]->sprite_id][game_pieces[i]->px][game_pieces[i]->py], piece_type, i));
			}
		}
	}

}

sf::Vector2i GameEngine::LookForQueen()
{
	//Queen spawning mechanics
		int piece_count = 0;
		std::vector<sf::Vector2i> pieces_in_combo;
		sf::Vector2i queens_throne = sf::Vector2i(-1,-1);
		for (int i = 0; i < 64; i++)
		{
			if (pieces[game_pieces[i]->px][game_pieces[i]->py] == -1)
			{
				if (combos[game_pieces[i]->sprite_id][game_pieces[i]->px][game_pieces[i]->py] == current_combo_to_remove)
				{
					piece_count++;
					pieces_in_combo.push_back(sf::Vector2i(game_pieces[i]->px, game_pieces[i]->py));
				}
			}
		}
		if (piece_count >= 5)
		{
			//New Queen spawning method - both straight and irregular methods are contemplated
			int random_position = sf::Randomizer::Random(0, pieces_in_combo.size()-1);
			queens_throne.x = pieces_in_combo[random_position].x;
			queens_throne.y = pieces_in_combo[random_position].y;
			has_queen = true;
		}
		return queens_throne;
}

bool GameEngine::ChessterLoading()
{
	if (loading_timer.GetElapsedTime() > 4 )
	{
		return true;
	}
	else
	{
		int percent = (int)((loading_timer.GetElapsedTime() * 100) / 4);
		
		std::stringstream s;
		this->gui->loading_info.SetText("Loading...");
		//std::string new_loading_status =  this->gui->loading_info.GetText();
		
		//new_loading_status += "(";
		
		//std::stringstream out;
		//out << percent;
		//new_loading_status += out.str();
		//new_loading_status += "%)";

		//this->gui->loading_info.SetText(new_loading_status);

		if (percent > 0 && percent % 6 == 0)
			this->loading_view->AddNextSprite();

		return false;
	}
}

void GameEngine::NormalModeUpdate()
{
	m_window_ptr->Draw(board->current_board);
		
	this->gui->ShowNextTreasure();
	
	m_window_ptr->Draw(gui->moves_bluecrest_spt);
	m_window_ptr->Draw(gui->moves_spt);
	m_window_ptr->Draw(gui->turns_bluecrest_spt);
	m_window_ptr->Draw(gui->turns_spt);
	m_window_ptr->Draw(gui->info_frame_spt);

	//m_window_ptr->Draw(gui->moves_label);
	m_window_ptr->Draw(gui->moves_info);

	//m_window_ptr->Draw(gui->turn_label);
	m_window_ptr->Draw(gui->turn_info);

	//m_window_ptr->Draw(gui->turn_points_label);
	m_window_ptr->Draw(gui->turn_points_info);

	//m_window_ptr->Draw(gui->demand_label);
	m_window_ptr->Draw(gui->demand_info);

	//m_window_ptr->Draw(gui->total_points_label);
	m_window_ptr->Draw(gui->total_points_info);
    
	board->Update(this->spike_count);

	if (some_piece_is_selected)
	{
		//Draw allowed moves hint
		for (int a=0;a<8;a++)
		{
			for (int q=0;q<8;q++)
			{
				if (this->game_pieces[selected_piece_id]->IsMoveAllowed(a,q))
				{
					int unique_id = FindPieceUniqueId(a,q);
					if (this->game_pieces[unique_id]->sprite_id != 6 && this->game_pieces[unique_id]->sprite_id != 7 && (this->game_pieces[selected_piece_id]->px != a || this->game_pieces[selected_piece_id]->py != q))
						this->m_window_ptr->Draw(this->move_hint[a][q]);
				}
			}
		}
	}
    
	int i;
    for (i = 0; i < 64; i++)
    {
        game_pieces[i]->Update();
    }

	if (some_piece_is_selected)
	{
		m_window_ptr->Draw( game_pieces[selected_piece_id]->piece_spt );
	}
	
	/*
	for (int j = 0; j < 8; j++)
	{
		if (this->spikes[j])
		{
			m_window_ptr->Draw(horizontal_spike[j]);
			m_window_ptr->Draw(vertical_spike[j]);
		}
	}
	*/
	this->animated_spikes.DrawSpikes();

	m_window_ptr->Draw(this->board->board_frame);

	if(some_piece_is_selected)
		m_window_ptr->Draw(this->gui->deselect_info);

	gui->HandleGameButtons(1);
}

void GameEngine::SetPuzzleModeFailure()
{
	std::cout << "Failed to solve the puzzle - should return to puzzle list view\n";
	this->isPuzzleMode = false;
	this->game_state = 50;
	this->audio.PlayMusic(0);
}

bool GameEngine::CheckPuzzleSolution()
{
	std::cout << "Checking for Puzzle solution...\n";
	for (unsigned int i = 0; i < this->puzzle_list_view->target_pieces.size(); i++)
	{
		/*
		if (this->game_pieces[this->puzzle_list_view->target_pieces[i]]->valid) // If at least one target piece is active in the board, keep the game going
		{
			std::cout << "Puzzle is not solved yet - the game should continue...\n";
			return false;
		}
		*/
		if ( this->puzzle_list_view->target_pieces[i] != -99)
			return false;
	}
	std::cout << "Puzzle was solved - the game should stop...\n";
	this->puzzle_list_view->SaveUnlockedPuzzlesProgress();
	this->ConfigurePuzzleList();
	this->isPuzzleMode = false;
	return true; //If all target pieces were cleared, the puzzle has ended
	
}

void GameEngine::PuzzleModeUpdate()
{
	m_window_ptr->Draw(board->current_board);
	
	m_window_ptr->Draw(gui->moves_bluecrest_spt);
	m_window_ptr->Draw(gui->moves_spt);
	m_window_ptr->Draw(gui->turns_bluecrest_spt);
	m_window_ptr->Draw(gui->turns_spt);

	//m_window_ptr->Draw(gui->moves_label);
	m_window_ptr->Draw(gui->moves_info);
	m_window_ptr->Draw(gui->turn_info);
  
	if (some_piece_is_selected)
	{
		//Draw allowed moves hint
		for (int a=0;a<8;a++)
		{
			for (int q=0;q<8;q++)
			{
				if (this->game_pieces[selected_piece_id]->IsMoveAllowed(a,q))
				{
					int unique_id = FindPieceUniqueId(a,q);
					if (this->game_pieces[unique_id]->sprite_id != 6 && this->game_pieces[unique_id]->sprite_id != 7 && (this->game_pieces[selected_piece_id]->px != a || this->game_pieces[selected_piece_id]->py != q))
						this->m_window_ptr->Draw(this->move_hint[a][q]);
				}
			}
		}
	}
    
	board->Update(this->spike_count);

	int i;
    for (i = 0; i < 64; i++)
    {
        game_pieces[i]->Update();
    }

	if (some_piece_is_selected)
	{
		m_window_ptr->Draw( game_pieces[selected_piece_id]->piece_spt );
	}

	m_window_ptr->Draw(this->board->board_frame);

	if(some_piece_is_selected)
		m_window_ptr->Draw(this->gui->deselect_info);

	if (!some_piece_is_selected)
	{
		m_window_ptr->Draw(this->puzzle_list_view->puzzle_description);
	}
	//gui->HandleGameButtons(1);
}

void GameEngine::Update()
{
	bool finishedDropDown = true;
    //updates according to game state
    switch (game_state)
    {
		case -1: // Loading Screen
            m_window_ptr->Draw(gui->loading_info);
			this->loading_view->ShowLoading();
			if (this->ChessterLoading())
				this->game_state = 0;
        break;

        case 0: // Title Screen
            m_window_ptr->Draw(gui->title_screen_spt);
            m_window_ptr->Draw(gui->temp_info);
			gui->HandleMainMenuButtons(0);
			//std::cout << "Finished Case [0] of Update\n";
        break;

        case 1: //Game Running

			if (isPuzzleMode)
				this->PuzzleModeUpdate();
			else
				this->NormalModeUpdate();
		break;

		case 70:
			if (this->tutorial->showTutorial)
			{
				this->NormalModeUpdate();
				
				m_window_ptr->Draw(this->tutorial->tutorial_sheet);
				if (this->tutorial->current_tutorial_stage == 26 || this->tutorial->current_tutorial_stage == 25 || this->tutorial->current_tutorial_stage == 24 
					|| this->tutorial->current_tutorial_stage == 22 || this->tutorial->current_tutorial_stage == 20 || this->tutorial->current_tutorial_stage == 19 
					|| this->tutorial->current_tutorial_stage == 17 || this->tutorial->current_tutorial_stage == 16 || this->tutorial->current_tutorial_stage == 15 
					|| this->tutorial->current_tutorial_stage == 12 || this->tutorial->current_tutorial_stage == 11 || this->tutorial->current_tutorial_stage == 0 
					|| this->tutorial->current_tutorial_stage == 2
					|| this->tutorial->current_tutorial_stage == 5 || this->tutorial->current_tutorial_stage == 8)
				{
					m_window_ptr->Draw(this->tutorial->next_arrow_button);
				}		
				else if (this->tutorial->current_tutorial_stage == 27 || this->tutorial->current_tutorial_stage == 23 || this->tutorial->current_tutorial_stage == 21
					|| this->tutorial->current_tutorial_stage == 28 || this->tutorial->current_tutorial_stage == 18 
					|| this->tutorial->current_tutorial_stage == 14 || this->tutorial->current_tutorial_stage == 13 || this->tutorial->current_tutorial_stage == 10 
					||this->tutorial->current_tutorial_stage == 9 ||this->tutorial->current_tutorial_stage == 1 || this->tutorial->current_tutorial_stage == 3 
					|| this->tutorial->current_tutorial_stage == 6 
					|| this->tutorial->current_tutorial_stage == 4 || this->tutorial->current_tutorial_stage == 7)
				{
					m_window_ptr->Draw(this->tutorial->close_button);
				}
				m_window_ptr->Draw(this->tutorial->ingame_tutorial_text);
			}

			break;
		
		case 50: //Puzzle List View
			m_window_ptr->Draw(this->puzzle_list_view->puzzle_view_background);

			for (int hh = 0; hh < 8; hh++)
			{
				for (int cc = 0; cc < 8; cc++)
				{
					if (this->puzzle_list_view->puzzle_locks[hh][cc].GetPosition().x == 0)
						m_window_ptr->Draw(this->puzzle_list_view->puzzle_numbers[hh][cc]);
					m_window_ptr->Draw(this->puzzle_list_view->puzzle_locks[hh][cc]);
				}
			}
			this->puzzle_list_view->Update( m_window_ptr->GetInput().GetMouseX(),m_window_ptr->GetInput().GetMouseY());
		break;

		case 55: //Puzzle Solved Animation in Puzzle Mode
			m_window_ptr->Draw(board->current_board);
			m_window_ptr->Draw(gui->moves_bluecrest_spt);
			m_window_ptr->Draw(gui->moves_spt);
			m_window_ptr->Draw(gui->moves_info);
			m_window_ptr->Draw(gui->turns_bluecrest_spt);
			m_window_ptr->Draw(gui->turns_spt);
			m_window_ptr->Draw(gui->turn_info);
			board->Update(this->spike_count);

			int j;
			for (j = 0; j < 64; j++)
			{
				game_pieces[j]->Update();
			}
			m_window_ptr->Draw(this->puzzle_list_view->puzzle_description);
			
			if (this->combo_title.is_animating_puzzle_label)
				this->combo_title.DrawPuzzleLabel();
			else
			{
				if (this->combo_title.mode == "SOLVED")
				{
					//The puzzle has been solved and the animation has ended
					this->game_state = 50;
					this->audio.PlayMusic(0);
				}
				else if (this->combo_title.mode == "FAILED")
				{
					this->SetPuzzleModeFailure();
				}
				else
					this->SetPuzzleModeFailure();
			}
			m_window_ptr->Draw(this->board->board_frame);
			break;

		case 2: //Running Match & Drop Loop
			m_window_ptr->Draw(board->current_board);
			
			if (isPuzzleMode)
			{
				m_window_ptr->Draw(gui->moves_bluecrest_spt);
				m_window_ptr->Draw(gui->moves_spt);
				
				//m_window_ptr->Draw(gui->moves_label);
				m_window_ptr->Draw(gui->moves_info);
				m_window_ptr->Draw(gui->turns_bluecrest_spt);
				m_window_ptr->Draw(gui->turns_spt);
				m_window_ptr->Draw(gui->turn_info);
				board->Update(this->spike_count);

				int j;
				for (j = 0; j < 64; j++)
				{
					game_pieces[j]->Update();
				}
				m_window_ptr->Draw(this->puzzle_list_view->puzzle_description);
			}
			else
			{
				m_window_ptr->Draw(gui->moves_bluecrest_spt);
				m_window_ptr->Draw(gui->moves_spt);
				
				this->gui->ShowNextTreasure();

				m_window_ptr->Draw(gui->turns_bluecrest_spt);
				m_window_ptr->Draw(gui->turns_spt);
				m_window_ptr->Draw(gui->info_frame_spt);

				//m_window_ptr->Draw(gui->turn_label);
				m_window_ptr->Draw(gui->turn_info);

				//m_window_ptr->Draw(gui->moves_label);
				m_window_ptr->Draw(gui->moves_info);

				//m_window_ptr->Draw(gui->turn_points_label);
				m_window_ptr->Draw(gui->turn_points_info);

				//m_window_ptr->Draw(gui->demand_label);
				m_window_ptr->Draw(gui->demand_info);

				//m_window_ptr->Draw(gui->total_points_label);
				m_window_ptr->Draw(gui->total_points_info);

				gui->HandleGameButtons(2);

				if (is_still_removing_combos)
				{
					//m_window_ptr->Draw(gui->match_label);
					if (combo_count >0)
					{
						m_window_ptr->Draw(gui->match_amount_info);
						m_window_ptr->Draw(gui->match_points_info);
						//m_window_ptr->Draw(gui->x_label);
						m_window_ptr->Draw(gui->multiply_spt);
					}
				}
	            
				board->Update(this->spike_count);
	            
				int j;
				for (j = 0; j < 64; j++)
				{
					game_pieces[j]->Update();
				}
				this->animated_spikes.DrawSpikes();
			}
			m_window_ptr->Draw(this->board->board_frame);
			this->MatchAndDropDownLoop();
			
        break;

		case 84: //Running Respawn drop downs
			m_window_ptr->Draw(board->current_board);
			
			if (isPuzzleMode)
			{
				m_window_ptr->Draw(gui->moves_bluecrest_spt);
				m_window_ptr->Draw(gui->moves_spt);
				
				//m_window_ptr->Draw(gui->moves_label);
				m_window_ptr->Draw(gui->moves_info);
				m_window_ptr->Draw(gui->turns_bluecrest_spt);
				m_window_ptr->Draw(gui->turns_spt);
				m_window_ptr->Draw(gui->turn_info);
				board->Update(this->spike_count);

				int j;
				for (j = 0; j < 64; j++)
				{
					game_pieces[j]->Update();
				}
				m_window_ptr->Draw(this->puzzle_list_view->puzzle_description);
			}
			else
			{
				m_window_ptr->Draw(gui->moves_bluecrest_spt);
				m_window_ptr->Draw(gui->moves_spt);
				this->gui->ShowNextTreasure();
				m_window_ptr->Draw(gui->turns_bluecrest_spt);
				m_window_ptr->Draw(gui->turns_spt);
				m_window_ptr->Draw(gui->info_frame_spt);
				m_window_ptr->Draw(gui->turn_info);
				m_window_ptr->Draw(gui->moves_info);
				m_window_ptr->Draw(gui->turn_points_info);
				m_window_ptr->Draw(gui->demand_info);
				m_window_ptr->Draw(gui->total_points_info);
				gui->HandleGameButtons(2);
				board->Update(this->spike_count);
				int j;
				for (j = 0; j < 64; j++)
				{
					game_pieces[j]->Update();
				}
				this->animated_spikes.DrawSpikes();
			}
			m_window_ptr->Draw(this->board->board_frame);
			for (int ii = 0; ii < 64; ii++)
			{
				if (game_pieces[ii]->isDroppingDownFromRespawn)
				{
					finishedDropDown =  false;
					break;
				}
			}
			if (finishedDropDown)
			{
				this->game_state = 2;
				this->MatchPieces();
			}
        break;

		case 30: //Resume Game or New Game Screen
			m_window_ptr->Draw(gui->title_screen_spt);
            m_window_ptr->Draw(gui->temp_info);
			/*
			m_window_ptr->Draw(this->gui->temp_new_game);
			m_window_ptr->Draw(this->gui->temp_resume_game);
			m_window_ptr->Draw(this->gui->temp_cancel);
			*/
			gui->HandleMainMenuButtons(1);
			break;

		case 27: // Taking from the turn score to calculate the final score with spark animation
			
			if (isPuzzleMode)
			{
				this->FinishLoop();
					return;

				if (this->gui->isDecreasingScore || this->gui->isAnimating)
				{
					this->gui->UpdateScore(2);
				}
				else
				{
					this->FinishLoop();
					return;
				}

				m_window_ptr->Draw(board->current_board);
				
				//this->gui->ShowNextTreasure();

				m_window_ptr->Draw(gui->moves_bluecrest_spt);
				m_window_ptr->Draw(gui->moves_spt);
				/*
				m_window_ptr->Draw(gui->turns_bluecrest_spt);
				m_window_ptr->Draw(gui->turns_spt);
				m_window_ptr->Draw(gui->info_frame_spt);

				//m_window_ptr->Draw(gui->turn_label);
				m_window_ptr->Draw(gui->turn_info);
				*/
				//m_window_ptr->Draw(gui->moves_label);
				m_window_ptr->Draw(gui->moves_info);
				m_window_ptr->Draw(gui->turns_bluecrest_spt);
				m_window_ptr->Draw(gui->turns_spt);
				m_window_ptr->Draw(gui->turn_info);
				//m_window_ptr->Draw(gui->turn_points_label);
				//m_window_ptr->Draw(gui->turn_points_info);
				/*
				if (this->gui->isAnimating)
				{
					if (this->gui->hasPositiveRemainder)
						this->m_window_ptr->Draw(this->gui->positive_total_score_animation[this->gui->positive_score_animation_frame]);
					else
						this->m_window_ptr->Draw(this->gui->negative_total_score_animation[this->gui->positive_score_animation_frame]);
				}

				//m_window_ptr->Draw(gui->demand_label);
				m_window_ptr->Draw(gui->demand_info);

				//m_window_ptr->Draw(gui->total_points_label);
				m_window_ptr->Draw(gui->total_points_info);

				//m_window_ptr->Draw(gui->match_label);

				gui->HandleGameButtons(3);
				*/
				board->Update(this->spike_count);
	            
				int kcc;
				for (kcc = 0; kcc < 64; kcc++)
				{
					game_pieces[kcc]->Update();
					if(game_pieces[kcc]->valid && x_marker[kcc] == true)
					{
						generic_x_marker.SetPosition(game_pieces[kcc]->piece_spt.GetPosition());
						m_window_ptr->Draw(generic_x_marker);
					}
				}
				//this->animated_spikes.DrawSpikes();
				m_window_ptr->Draw(this->puzzle_list_view->puzzle_description);
			}
			else
			{
				if (this->gui->isDecreasingScore || this->gui->isAnimating)
				{
					this->gui->UpdateScore(2);
				}
				else
				{
					if (!this->tutorial->first_negative_score && !this->tutorial->first_treasure)
					{
						if (this->game->FakeEndTurn() < 0 && this->game->CheckTreasureUnlock())
						{
							//tesouro e score negativo
							this->game_state = 70;
							this->tutorial->SetTutorialStage(24);
							return;
						}
						else if (this->game->FakeEndTurn() >= 0 && this->game->CheckTreasureUnlock())
						{
							//tesouro
							if (!this->tutorial->first_treasure)
							{
								this->game_state = 70;
								this->tutorial->SetTutorialStage(19);
								return;
							}
						}
						else if (this->game->FakeEndTurn() < 0 && !this->game->CheckTreasureUnlock())
						{
							//score negativo
							if (!this->tutorial->first_negative_score)
							{
								this->game_state = 70;
								this->tutorial->SetTutorialStage(22);
								return;
							}
						}
						else
						{
							this->FinishLoop();
							return;
						}
					}
					else if (!this->tutorial->first_negative_score && this->tutorial->first_treasure)
					{
						//somente score negativo
						if (!this->tutorial->first_negative_score && this->game->FakeEndTurn() < 0)
						{
							this->game_state = 70;
							this->tutorial->SetTutorialStage(22);
							return;
						}
						else
						{
							this->FinishLoop();
							return;
						}
					}
					else if (this->tutorial->first_negative_score && !this->tutorial->first_treasure)
					{
						//somente tesouro
						if (!this->tutorial->first_treasure && this->game->CheckTreasureUnlock())
						{
							this->game_state = 70;
							this->tutorial->SetTutorialStage(19);
							return;
						}
						else
						{
							this->FinishLoop();
							return;
						}
					}
					else
					{
						this->FinishLoop();
						return;
					}
				}

				m_window_ptr->Draw(board->current_board);
				
				this->gui->ShowNextTreasure();

				m_window_ptr->Draw(gui->moves_bluecrest_spt);
				m_window_ptr->Draw(gui->moves_spt);
				m_window_ptr->Draw(gui->turns_bluecrest_spt);
				m_window_ptr->Draw(gui->turns_spt);
				m_window_ptr->Draw(gui->info_frame_spt);

				//m_window_ptr->Draw(gui->turn_label);
				m_window_ptr->Draw(gui->turn_info);

				//m_window_ptr->Draw(gui->moves_label);
				m_window_ptr->Draw(gui->moves_info);

				//m_window_ptr->Draw(gui->turn_points_label);
				m_window_ptr->Draw(gui->turn_points_info);

				if (this->gui->isAnimating)
				{
					if (this->gui->hasPositiveRemainder)
						this->m_window_ptr->Draw(this->gui->positive_total_score_animation[this->gui->positive_score_animation_frame]);
					else
						this->m_window_ptr->Draw(this->gui->negative_total_score_animation[this->gui->positive_score_animation_frame]);
				}

				//m_window_ptr->Draw(gui->demand_label);
				m_window_ptr->Draw(gui->demand_info);

				//m_window_ptr->Draw(gui->total_points_label);
				m_window_ptr->Draw(gui->total_points_info);

				//m_window_ptr->Draw(gui->match_label);

				gui->HandleGameButtons(3);

				board->Update(this->spike_count);
	            
				int kcc;
				for (kcc = 0; kcc < 64; kcc++)
				{
					game_pieces[kcc]->Update();
					if(game_pieces[kcc]->valid && x_marker[kcc] == true)
					{
						generic_x_marker.SetPosition(game_pieces[kcc]->piece_spt.GetPosition());
						m_window_ptr->Draw(generic_x_marker);
					}
				}
				this->animated_spikes.DrawSpikes();
			}
			m_window_ptr->Draw(this->board->board_frame);
			
			break;

		case 26: // Taking demand from the turn score to calculate the final score 
			if (isPuzzleMode)
			{
				this->game_state = 27;
					return;

				if (this->gui->isDecreasingScore || this->gui->isAnimating)
				{
					this->gui->UpdateScore(1);
				}
				else
				{
					//this->FinishLoop();
					if (this->gui->hasEndTimerStarted && this->gui->end_turn_timer.GetElapsedTime() >= 0.6)
					{
						if (!this->isPuzzleMode && !this->tutorial->first_demand_taken)
						{
							this->game_state = 70;
							this->tutorial->SetTutorialStage(14);
							return;
						}
						else
						{
							this->gui->SetupScoreUpdate(0, 2, this->game->GetRemainderSignal());
							this->game_state = 27;
							return;
						}
					}
					else if (!this->gui->hasEndTimerStarted)
					{
						this->gui->hasEndTimerStarted = true;
						this->gui->end_turn_timer.Reset();
					}

				}

				m_window_ptr->Draw(board->current_board);
				
				//this->gui->ShowNextTreasure();

				m_window_ptr->Draw(gui->moves_bluecrest_spt);
				m_window_ptr->Draw(gui->moves_spt);
				//m_window_ptr->Draw(gui->turns_bluecrest_spt);
				//m_window_ptr->Draw(gui->turns_spt);
				//m_window_ptr->Draw(gui->info_frame_spt);
				m_window_ptr->Draw(gui->turns_bluecrest_spt);
				m_window_ptr->Draw(gui->turns_spt);
				m_window_ptr->Draw(gui->turn_info);
				//m_window_ptr->Draw(gui->turn_label);
				//m_window_ptr->Draw(gui->turn_info);

				//m_window_ptr->Draw(gui->moves_label);
				m_window_ptr->Draw(gui->moves_info);

				//m_window_ptr->Draw(gui->turn_points_label);
				//m_window_ptr->Draw(gui->turn_points_info);
				
				/*
				if (this->gui->isAnimating)
				{
					//std::cout << "\n...entered here...\n";
					this->m_window_ptr->Draw(this->gui->demand_animation[this->gui->demand_animation_frame]);
				}

				//m_window_ptr->Draw(gui->demand_label);
				m_window_ptr->Draw(gui->demand_info);

				//m_window_ptr->Draw(gui->total_points_label);
				m_window_ptr->Draw(gui->total_points_info);

				//m_window_ptr->Draw(gui->match_label);

				gui->HandleGameButtons(3);
				*/
				board->Update(this->spike_count);
	            
				int kc;
				for (kc = 0; kc < 64; kc++)
				{
					game_pieces[kc]->Update();
					if(game_pieces[kc]->valid && x_marker[kc] == true)
					{
						generic_x_marker.SetPosition(game_pieces[kc]->piece_spt.GetPosition());
						m_window_ptr->Draw(generic_x_marker);
					}
				}
				//this->animated_spikes.DrawSpikes();
				m_window_ptr->Draw(this->puzzle_list_view->puzzle_description);
			}
			else
			{
				if (this->gui->isDecreasingScore || this->gui->isAnimating)
				{
					this->gui->UpdateScore(1);
				}
				else
				{
					//this->FinishLoop();
					if (this->gui->hasEndTimerStarted && this->gui->end_turn_timer.GetElapsedTime() >= 0.6)
					{
						if (!this->isPuzzleMode && !this->tutorial->first_demand_taken)
						{
							this->game_state = 70;
							this->tutorial->SetTutorialStage(14);
							return;
						}
						else
						{
							this->gui->SetupScoreUpdate(0, 2, this->game->GetRemainderSignal());
							this->game_state = 27;
							return;
						}
					}
					else if (!this->gui->hasEndTimerStarted)
					{
						this->gui->hasEndTimerStarted = true;
						this->gui->end_turn_timer.Reset();
					}

				}

				m_window_ptr->Draw(board->current_board);
				
				this->gui->ShowNextTreasure();

				m_window_ptr->Draw(gui->moves_bluecrest_spt);
				m_window_ptr->Draw(gui->moves_spt);
				m_window_ptr->Draw(gui->turns_bluecrest_spt);
				m_window_ptr->Draw(gui->turns_spt);
				m_window_ptr->Draw(gui->info_frame_spt);

				//m_window_ptr->Draw(gui->turn_label);
				m_window_ptr->Draw(gui->turn_info);

				//m_window_ptr->Draw(gui->moves_label);
				m_window_ptr->Draw(gui->moves_info);

				//m_window_ptr->Draw(gui->turn_points_label);
				m_window_ptr->Draw(gui->turn_points_info);

				if (this->gui->isAnimating)
				{
					//std::cout << "\n...entered here...\n";
					this->m_window_ptr->Draw(this->gui->demand_animation[this->gui->demand_animation_frame]);
				}

				//m_window_ptr->Draw(gui->demand_label);
				m_window_ptr->Draw(gui->demand_info);

				//m_window_ptr->Draw(gui->total_points_label);
				m_window_ptr->Draw(gui->total_points_info);

				//m_window_ptr->Draw(gui->match_label);

				gui->HandleGameButtons(3);

				board->Update(this->spike_count);
	            
				int kc;
				for (kc = 0; kc < 64; kc++)
				{
					game_pieces[kc]->Update();
					if(game_pieces[kc]->valid && x_marker[kc] == true)
					{
						generic_x_marker.SetPosition(game_pieces[kc]->piece_spt.GetPosition());
						m_window_ptr->Draw(generic_x_marker);
					}
				}
				this->animated_spikes.DrawSpikes();
			}
			m_window_ptr->Draw(this->board->board_frame);
			
			break;
		
		case 25: //Increasing the score with animation
			if (isPuzzleMode)
			{
				if (this->gui->isIncreasingScore || this->gui->isAnimating)
				{
					this->gui->UpdateScore(0);
				}
				else
				{
					this->game_state = 2;
					return;
				}

				m_window_ptr->Draw(board->current_board);
				
				//this->gui->ShowNextTreasure();

				m_window_ptr->Draw(gui->moves_bluecrest_spt);
				m_window_ptr->Draw(gui->moves_spt);
				/*
				m_window_ptr->Draw(gui->turns_bluecrest_spt);
				m_window_ptr->Draw(gui->turns_spt);
				m_window_ptr->Draw(gui->info_frame_spt);

				//m_window_ptr->Draw(gui->turn_label);
				m_window_ptr->Draw(gui->turn_info);
				*/
				//m_window_ptr->Draw(gui->moves_label);
				m_window_ptr->Draw(gui->moves_info);
				m_window_ptr->Draw(gui->turns_bluecrest_spt);
				m_window_ptr->Draw(gui->turns_spt);
				m_window_ptr->Draw(gui->turn_info);
				/*
				//m_window_ptr->Draw(gui->turn_points_label);
				m_window_ptr->Draw(gui->turn_points_info);

				//m_window_ptr->Draw(gui->demand_label);
				m_window_ptr->Draw(gui->demand_info);

				//m_window_ptr->Draw(gui->total_points_label);
				m_window_ptr->Draw(gui->total_points_info);
				
				//m_window_ptr->Draw(gui->match_label);
				
				if (this->gui->isAnimating)
				{
					this->m_window_ptr->Draw(this->gui->positive_score_animation[this->gui->positive_score_animation_frame]);
				}
			
				gui->HandleGameButtons(3);
				*/
				board->Update(this->spike_count);
	            
				int k;
				for (k = 0; k < 64; k++)
				{
					game_pieces[k]->Update();
					if(game_pieces[k]->valid && x_marker[k] == true)
					{
						generic_x_marker.SetPosition(game_pieces[k]->piece_spt.GetPosition());
						m_window_ptr->Draw(generic_x_marker);
					}
				}
				//this->animated_spikes.DrawSpikes();
				m_window_ptr->Draw(this->puzzle_list_view->puzzle_description);
			}
			else
			{
				if (this->gui->isIncreasingScore || this->gui->isAnimating)
				{
					this->gui->UpdateScore(0);
				}
				else
				{
					this->game_state = 2;
					return;
				}

				m_window_ptr->Draw(board->current_board);
				
				this->gui->ShowNextTreasure();

				m_window_ptr->Draw(gui->moves_bluecrest_spt);
				m_window_ptr->Draw(gui->moves_spt);
				m_window_ptr->Draw(gui->turns_bluecrest_spt);
				m_window_ptr->Draw(gui->turns_spt);
				m_window_ptr->Draw(gui->info_frame_spt);

				//m_window_ptr->Draw(gui->turn_label);
				m_window_ptr->Draw(gui->turn_info);

				//m_window_ptr->Draw(gui->moves_label);
				m_window_ptr->Draw(gui->moves_info);

				//m_window_ptr->Draw(gui->turn_points_label);
				m_window_ptr->Draw(gui->turn_points_info);

				//m_window_ptr->Draw(gui->demand_label);
				m_window_ptr->Draw(gui->demand_info);

				//m_window_ptr->Draw(gui->total_points_label);
				m_window_ptr->Draw(gui->total_points_info);
				
				//m_window_ptr->Draw(gui->match_label);
				
				if (this->gui->isAnimating)
				{
					this->m_window_ptr->Draw(this->gui->positive_score_animation[this->gui->positive_score_animation_frame]);
				}

				gui->HandleGameButtons(3);

				board->Update(this->spike_count);
	            
				int k;
				for (k = 0; k < 64; k++)
				{
					game_pieces[k]->Update();
					if(game_pieces[k]->valid && x_marker[k] == true)
					{
						generic_x_marker.SetPosition(game_pieces[k]->piece_spt.GetPosition());
						m_window_ptr->Draw(generic_x_marker);
					}
				}
				this->animated_spikes.DrawSpikes();
			}

			m_window_ptr->Draw(this->board->board_frame);

			break;
		
		case 3: //Running points display and piece counting per combo
			if (isPuzzleMode)
			{
				if (CheckForBlocksBreaking())
				{
					this->game_state = 99;
					return;
				}

				this->UpdateCounting();

				m_window_ptr->Draw(board->current_board);
				
				m_window_ptr->Draw(gui->moves_bluecrest_spt);
				m_window_ptr->Draw(gui->moves_spt);
	
				m_window_ptr->Draw(gui->moves_info);
				m_window_ptr->Draw(gui->turns_bluecrest_spt);
				m_window_ptr->Draw(gui->turns_spt);
				m_window_ptr->Draw(gui->turn_info);
				board->Update(this->spike_count);
	            
				int l;
				for (l = 0; l < 64; l++)
				{
					game_pieces[l]->Update();
					if(game_pieces[l]->valid && x_marker[l] == true)
					{
						generic_x_marker.SetPosition(game_pieces[l]->piece_spt.GetPosition());
						m_window_ptr->Draw(generic_x_marker);
					}
				}

				m_window_ptr->Draw(this->board->board_frame);

				if (counting)
				{
					this->combo_title.DrawComboLabel();
				}
				m_window_ptr->Draw(this->puzzle_list_view->puzzle_description);
			}
			else
			{
				if (CheckForBlocksBreaking())
				{
					this->game_state = 99;
					return;
				}

				this->UpdateCounting();

				m_window_ptr->Draw(board->current_board);

				this->gui->ShowNextTreasure();
				
				m_window_ptr->Draw(gui->moves_bluecrest_spt);
				m_window_ptr->Draw(gui->moves_spt);
				m_window_ptr->Draw(gui->turns_bluecrest_spt);
				m_window_ptr->Draw(gui->turns_spt);
				m_window_ptr->Draw(gui->info_frame_spt);

				//m_window_ptr->Draw(gui->turn_label);
				m_window_ptr->Draw(gui->turn_info);

				//m_window_ptr->Draw(gui->moves_label);
				m_window_ptr->Draw(gui->moves_info);

				//m_window_ptr->Draw(gui->turn_points_label);
				m_window_ptr->Draw(gui->turn_points_info);

				//m_window_ptr->Draw(gui->demand_label);
				m_window_ptr->Draw(gui->demand_info);

				//m_window_ptr->Draw(gui->total_points_label);
				m_window_ptr->Draw(gui->total_points_info);

				//m_window_ptr->Draw(gui->match_label);

				gui->HandleGameButtons(3);

				board->Update(this->spike_count);
	            
				int l;
				for (l = 0; l < 64; l++)
				{
					game_pieces[l]->Update();
					if(game_pieces[l]->valid && x_marker[l] == true)
					{
						generic_x_marker.SetPosition(game_pieces[l]->piece_spt.GetPosition());
						m_window_ptr->Draw(generic_x_marker);
					}
				}
				/*
				for (int j = 0; j < 8; j++)
				{
					if (this->spikes[j])
					{
						m_window_ptr->Draw(horizontal_spike[j]);
						m_window_ptr->Draw(vertical_spike[j]);
					}
				}
				*/
				this->animated_spikes.DrawSpikes();

				m_window_ptr->Draw(this->board->board_frame);

				if (counting)
				{
					this->combo_title.DrawComboLabel();
					if (combo_count >0)
					{
						m_window_ptr->Draw(gui->match_amount_info);
						m_window_ptr->Draw(gui->match_points_info);
						//m_window_ptr->Draw(gui->x_label);
						m_window_ptr->Draw(gui->multiply_spt);
					}
				}
			}
        break;

		case 4: //Animating combo label
			if (isPuzzleMode)
			{
				m_window_ptr->Draw(board->current_board);
				m_window_ptr->Draw(gui->moves_bluecrest_spt);
				m_window_ptr->Draw(gui->moves_spt);
				
				//m_window_ptr->Draw(gui->moves_label);
				m_window_ptr->Draw(gui->moves_info);
				m_window_ptr->Draw(gui->turns_bluecrest_spt);
				m_window_ptr->Draw(gui->turns_spt);
				m_window_ptr->Draw(gui->turn_info);
				if (combo_count >0)
				{
					//m_window_ptr->Draw(gui->match_amount_info);
					//m_window_ptr->Draw(gui->match_points_info);
					//m_window_ptr->Draw(gui->x_label);
					//m_window_ptr->Draw(gui->multiply_spt);
				}

				//gui->HandleGameButtons(4);

				board->Update(this->spike_count);
	            
				int v;
				for (v = 0; v < 64; v++)
				{
					game_pieces[v]->Update();
					if(game_pieces[v]->valid && x_marker[v] == true)
					{
						generic_x_marker.SetPosition(game_pieces[v]->piece_spt.GetPosition());
						m_window_ptr->Draw(generic_x_marker);
					}
				}

				//this->animated_spikes.DrawSpikes();

				m_window_ptr->Draw(this->board->board_frame);

				this->combo_title.DrawComboLabel();

				if (!this->combo_title.IsAnimating())
					this->game_state = 3;

				m_window_ptr->Draw(this->puzzle_list_view->puzzle_description);
			}
			else
			{
				m_window_ptr->Draw(board->current_board);
				this->gui->ShowNextTreasure();
				m_window_ptr->Draw(gui->moves_bluecrest_spt);
				m_window_ptr->Draw(gui->moves_spt);
				m_window_ptr->Draw(gui->turns_bluecrest_spt);
				m_window_ptr->Draw(gui->turns_spt);
				m_window_ptr->Draw(gui->info_frame_spt);

				//m_window_ptr->Draw(gui->turn_label);
				m_window_ptr->Draw(gui->turn_info);

				//m_window_ptr->Draw(gui->moves_label);
				m_window_ptr->Draw(gui->moves_info);

				//m_window_ptr->Draw(gui->turn_points_label);
				m_window_ptr->Draw(gui->turn_points_info);

				//m_window_ptr->Draw(gui->demand_label);
				m_window_ptr->Draw(gui->demand_info);

				//m_window_ptr->Draw(gui->total_points_label);
				m_window_ptr->Draw(gui->total_points_info);

				//m_window_ptr->Draw(gui->match_label);
				if (combo_count >0)
				{
					m_window_ptr->Draw(gui->match_amount_info);
					m_window_ptr->Draw(gui->match_points_info);
					//m_window_ptr->Draw(gui->x_label);
					m_window_ptr->Draw(gui->multiply_spt);
				}

				gui->HandleGameButtons(4);

				board->Update(this->spike_count);
	            
				int v;
				for (v = 0; v < 64; v++)
				{
					game_pieces[v]->Update();
					if(game_pieces[v]->valid && x_marker[v] == true)
					{
						generic_x_marker.SetPosition(game_pieces[v]->piece_spt.GetPosition());
						m_window_ptr->Draw(generic_x_marker);
					}
				}
				/*
				for (int j = 0; j < 8; j++)
				{
					if (this->spikes[j])
					{
						m_window_ptr->Draw(horizontal_spike[j]);
						m_window_ptr->Draw(vertical_spike[j]);
					}
				}
				*/
				this->animated_spikes.DrawSpikes();

				m_window_ptr->Draw(this->board->board_frame);

				this->combo_title.DrawComboLabel();

				if (!this->combo_title.IsAnimating())
					this->game_state = 3;
			}
        break;

		case 99: //Breaking the blocks
			if (isPuzzleMode)
			{
				m_window_ptr->Draw(board->current_board);
				m_window_ptr->Draw(gui->moves_bluecrest_spt);
				m_window_ptr->Draw(gui->moves_spt);
			
				m_window_ptr->Draw(gui->moves_info);
				m_window_ptr->Draw(gui->turns_bluecrest_spt);
				m_window_ptr->Draw(gui->turns_spt);
				m_window_ptr->Draw(gui->turn_info);
				board->Update(this->spike_count);
	            
				int y;
				for (y = 0; y < 64; y++)
				{
					game_pieces[y]->Update();
				}

				m_window_ptr->Draw(this->board->board_frame);

				if (!this->CheckForBlocksBreaking())
				{
					this->game_state = 3;
					this->aux_timer.Reset();
				}
				m_window_ptr->Draw(this->puzzle_list_view->puzzle_description);
			}
			else
			{
				m_window_ptr->Draw(board->current_board);
				this->gui->ShowNextTreasure();
				m_window_ptr->Draw(gui->moves_bluecrest_spt);
				m_window_ptr->Draw(gui->moves_spt);
				m_window_ptr->Draw(gui->turns_bluecrest_spt);
				m_window_ptr->Draw(gui->turns_spt);
				m_window_ptr->Draw(gui->info_frame_spt);

				//m_window_ptr->Draw(gui->turn_label);
				m_window_ptr->Draw(gui->turn_info);

				//m_window_ptr->Draw(gui->moves_label);
				m_window_ptr->Draw(gui->moves_info);

				//m_window_ptr->Draw(gui->turn_points_label);
				m_window_ptr->Draw(gui->turn_points_info);

				//m_window_ptr->Draw(gui->demand_label);
				m_window_ptr->Draw(gui->demand_info);

				//m_window_ptr->Draw(gui->total_points_label);
				m_window_ptr->Draw(gui->total_points_info);

				gui->HandleGameButtons(99);
	          
				board->Update(this->spike_count);
	            
				int y;
				for (y = 0; y < 64; y++)
				{
					game_pieces[y]->Update();
				}
				/*
				for (int k = 0; k < 8; k++)
				{
					if (this->spikes[k])
					{
						m_window_ptr->Draw(horizontal_spike[k]);
						m_window_ptr->Draw(vertical_spike[k]);
					}
				}
				*/
				this->animated_spikes.DrawSpikes();

				m_window_ptr->Draw(this->board->board_frame);

				if (!this->CheckForBlocksBreaking())
				{
					this->game_state = 3;
					this->aux_timer.Reset();
				}
			}
        break;

	/*
		case 10:
			m_window_ptr->Draw(gui->title_screen_spt);
			this->tutorial->DrawTutorialView();
			if (this->tutorial->IsTutorialFinished())
				this->game_state = 0;
			break;
			*/
		case 11:
			m_window_ptr->Draw(board->current_board);
			this->level_view.Update();
			break;
		case 12:
			m_window_ptr->Draw(gui->title_screen_spt);
			this->ranking_view.Update();
			break;
		case 14:
			m_window_ptr->Draw(gui->title_screen_spt);
			this->credits_view.Update();
			break;
    }
	
	if (showConsole)
		this->DisplayConsole();

	this->cursor.Update();

    m_window_ptr->Display();
}

void GameEngine::DisplayConsole()
{
	for (int i = 0; i < 5; i++)
	{
		 m_window_ptr->Draw(in_game_console[i]);
	}
}

void GameEngine::ConfigureBackground(int level)
{
	switch(level)
	{
		case 0: //Title
			gui->title_screen_spt.SetImage(resource_manager->OnDemandLoadBackground(0));
			if (last_background != "gameboard")
			{
				last_background = "menu";
				gui->title_screen_spt.Scale(m_window_ptr->GetWidth()/max_width, m_window_ptr->GetHeight()/max_height);
			}
			break;

		case 1: //Dungeon
			board->ConfigBoard(1);
			if (last_background == "start")
			{
				last_background = "gameboard";
				board->ScaleBackground(m_window_ptr->GetWidth()/max_width, m_window_ptr->GetHeight()/max_height);
			}
			break;

		case 2: //Castle Walls
			board->ConfigBoard(2);
			if (last_background == "start")
			{
				last_background = "gameboard";
				board->ScaleBackground(m_window_ptr->GetWidth()/max_width, m_window_ptr->GetHeight()/max_height);
			}
			break;

		case 3: //Courtyard
			board->ConfigBoard(3);
			if (last_background == "start")
			{
				last_background = "gameboard";
				board->ScaleBackground(m_window_ptr->GetWidth()/max_width, m_window_ptr->GetHeight()/max_height);
			}
			break;

		case 10: //Puzzle Game Mode
			board->ConfigBoard(10);
			if (last_background == "start")
			{
				last_background = "gameboard";
				board->ScaleBackground(m_window_ptr->GetWidth()/max_width, m_window_ptr->GetHeight()/max_height);
			}
			break;
	}
}

void GameEngine::SetGameState(int gs)
{
    this->game_state = gs;
}

void GameEngine::Flush()
{
    m_window_ptr->Clear( sf::Color::Black );
}

void GameEngine::RestorePiecesMovement()
{
	for (int i = 0; i < 64; i++)
	{
		game_pieces[i]->moved = false;
	}
}

bool GameEngine::CheckForSavedGames()
{
	//Saved Game file validation
	std::cout << "\nChecking for a valid saved game info...\n";
	this->PushConsoleMessage("Checking for a valid saved game info...");
	std::string file_lines[3];
	int index = 0;
	std::ifstream infile;
	infile.open ("Config/save.txt");
        while(!infile.eof()) 
        {
			std::getline(infile,file_lines[index]);
			index++;
        }
	infile.close();
	int pos;
	std::stringstream ss;
	int saved;
	pos = file_lines[0].find("=");
	pos++;
	ss << file_lines[0].substr(pos); 
	ss >> saved;
	ss.clear();
	std::cout << "Does save file exist: [" << saved << "]\n";
	if (saved == 1)
	{
		this->PushConsoleMessage("Valid saved game found");
		return true;
	}
	else
	{
		this->PushConsoleMessage("There is no saved game to load");
		return false;
	}
	return false;
}

void GameEngine::ParseSavedGameFile()
{
	//Saved Game file
	std::cout << "\n\n\nLoading saved game info...\n";
	std::string file_lines[3];
	int index = 0;
	std::ifstream infile;
	infile.open ("Config/save.txt");
        while(!infile.eof()) 
        {
			std::getline(infile,file_lines[index]);
			index++;
        }
	infile.close();
	//General config
	int pos;
	std::stringstream ss;
	//Validation
	int saved;
	pos = file_lines[0].find("=");
	pos++;
	ss << file_lines[0].substr(pos); 
	ss >> saved;
	ss.clear();
	//Level
	int level_to_load;
	pos = file_lines[1].find("=");
	pos++;
	ss << file_lines[1].substr(pos); 
	ss >> level_to_load;
	ss.clear();
	std::cout << "Level to load: [" << level_to_load << "]\n";
	//Total Score so far
	int total_score_so_far;
	pos = file_lines[2].find("=");
	pos++;
	ss << file_lines[2].substr(pos); 
	ss >> total_score_so_far;
	ss.clear();
	std::cout << "Total score so far: [" << total_score_so_far << "]\n";

	this->ConfigureBackground(level_to_load);
	this->game = new GameSession(level_to_load, gui, base_demand, move_count, piece_values[0],piece_values[1],piece_values[2],piece_values[3],piece_values[4],piece_values[5], total_score_so_far);
	this->resource_manager->current_level = level_to_load;
	this->resource_manager->RefreshBlockFrames();
	this->RandomlyCreatePieces();
	spike_count = 0;
	for (int i = 0; i < 8; i++)
		this->spikes[i] = false;
	this->audio.PlayMusic(1);
	this->level_view.SetupIntroView(level_to_load, this->gui->demand_info.GetText());
	this->game_state = 11;
	this->gui->ResetTreasures();
	this->gui->ResetSlidingConditions();

	/*
	//Saved Game file
	std::cout << "\n\n\nLoading saved game info...\n";
	std::string file_lines[72];
	int index = 0;
	std::ifstream infile;
	infile.open ("saved_game.txt");
        while(!infile.eof()) 
        {
			std::getline(infile,file_lines[index]);
			index++;
        }
	infile.close();

	//General config
	int pos;
	std::stringstream ss;

	//Level
	int level_to_load;
	pos = file_lines[0].find("=");
	pos++;
	ss << file_lines[0].substr(pos); 
	ss >> level_to_load;
	ss.clear();
	std::cout << "Level to load: [" << level_to_load << "]\n";

	//Turn
	int turn_to_start;
	pos = file_lines[1].find("=");
	pos++;
	ss << file_lines[1].substr(pos); 
	ss >> turn_to_start;
	ss.clear();
	std::cout << "Turn to start: [" << turn_to_start << "]\n";

	//Total Score so far
	int total_score_so_far;
	pos = file_lines[2].find("=");
	pos++;
	ss << file_lines[2].substr(pos); 
	ss >> total_score_so_far;
	ss.clear();
	std::cout << "Total score so far: [" << total_score_so_far << "]\n";

	//Treasure 1
	int treasure1;
	pos = file_lines[3].find("=");
	pos++;
	ss << file_lines[3].substr(pos); 
	ss >> treasure1;
	ss.clear();
	std::cout << "Treasure 1: [" << treasure1 << "]\n";
	//Treasure 2
	int treasure2;
	pos = file_lines[4].find("=");
	pos++;
	ss << file_lines[4].substr(pos); 
	ss >> treasure2;
	ss.clear();
	std::cout << "Treasure 2: [" << treasure2 << "]\n";
	//Treasure 3
	int treasure3;
	pos = file_lines[5].find("=");
	pos++;
	ss << file_lines[5].substr(pos); 
	ss >> treasure3;
	ss.clear();
	std::cout << "Treasure 3: [" << treasure3 << "]\n";
	//Treasure 4
	int treasure4;
	pos = file_lines[6].find("=");
	pos++;
	ss << file_lines[6].substr(pos); 
	ss >> treasure4;
	ss.clear();
	std::cout << "Treasure 4: [" << treasure4 << "]\n";

	//Game Board

	int saved_pieces[64];
	int external_index = 0;
	for (int p=7; p<71; p++)
	{
		pos = file_lines[p].find("=");
		pos++;
		ss << file_lines[p].substr(pos); 
		ss >> saved_pieces[external_index];
		ss.clear();
		std::cout << "Saved piece [" << external_index << "] sprite_id is: [" << saved_pieces[external_index] << "]\n";
		external_index++;
	}

	//Spikes
	int loaded_spike_count;
	pos = file_lines[71].find("=");
	pos++;
	ss << file_lines[71].substr(pos); 
	ss >> loaded_spike_count;
	ss.clear();
	std::cout << "Spike count: [" << loaded_spike_count << "]\n";

	//Play Part
	this->ConfigureBackground(level_to_load);
	this->game = new GameSession(level_to_load, gui, base_demand, move_count, piece_values[0],piece_values[1],piece_values[2],piece_values[3],piece_values[4],piece_values[5], total_score_so_far);
	
	this->resource_manager->current_level = level_to_load;
	this->resource_manager->RefreshBlockFrames();
	
	//RECREATE SAVED PIECES
	int i = 0;
    int line, column;
    for (line = 0; line < 8; line++)
    {
        for (column = 0; column < 8; column ++)
        {
            game_pieces[i] = new Piece(i, saved_pieces[i], m_window_ptr, resource_manager, tile_size_factor, max_tile_size);
            game_pieces[i]->px = board->board_tile[line][column]->px;
            game_pieces[i]->py = board->board_tile[line][column]->py;
            game_pieces[i]->piece_spt.SetPosition(game_pieces[i]->offset_x + game_pieces[i]->tile_size * game_pieces[i]->px, game_pieces[i]->offset_y + game_pieces[i]->tile_size * game_pieces[i]->py);
            game_pieces[i]->RefreshAllowedMoves();
            i++;
        }
    }
	
	//TODO SPIKES
	spike_count = 0;
	spike_count = loaded_spike_count;
	this->animated_spikes.LoadSavedSpikes(loaded_spike_count);
	

	this->audio.PlayMusic(1);
	this->level_view.SetupIntroView(level_to_load, this->gui->demand_info.GetText());
	this->game_state = 11;

	//TODO TREASURES
	this->gui->ResetTreasures();
	this->gui->LoadSavedTreasures(treasure1, treasure2, treasure3, treasure4);
	
	this->gui->ResetSlidingConditions();

	this->game->current_turn = turn_to_start;
	this->gui->turn_info.SetText(this->game->ConvertIntToString(this->game->current_turn));
	*/
}

void GameEngine::ResetSaveFile()
{
	std::ofstream save_info;
	save_info.open ("Config/save.txt");
	save_info << "save=" << 0 << "\n";
	save_info << "level=" << 1 << "\n";
	save_info << "total_points=" << 0;
	save_info.close();

}

void GameEngine::SaveSessionToFile()
{
	std::ofstream save_info;
	save_info.open ("Config/save.txt");
	save_info << "save=" << 1 << "\n";
	save_info << "level=" << this->game->current_level << "\n";
	save_info << "total_points=" << this->game->total_score;
	save_info.close();
}

void GameEngine::StartGame(int level_id)
{
	has_queen = false;
	spike_count = 0;
	this->animated_spikes.spike_count = 0;
	for (int i = 0; i < 8; i++)
		this->spikes[i] = false;
	this->animated_spikes.RemoveSpikes();
	this->animated_spikes.ResetAnimationFrames();
	int total = 0;
	switch (level_id)
	{
		case 1:
			this->ConfigureBackground(1);
			this->game = new GameSession(1, gui, base_demand, move_count, piece_values[0],piece_values[1],piece_values[2],piece_values[3],piece_values[4],piece_values[5], total);
			this->PushConsoleMessage("Finished loading session");
			this->resource_manager->current_level = 1;
			this->resource_manager->RefreshBlockFrames();
			this->RandomlyCreatePieces();
			spike_count = 0;
			for (int i = 0; i < 8; i++)
				this->spikes[i] = false;
			this->audio.PlayMusic(1);
			this->level_view.SetupIntroView(1, this->gui->demand_info.GetText());
			this->PushConsoleMessage("Finished loading intro view");
			this->game_state = 11;
			this->gui->ResetTreasures();
			this->PushConsoleMessage("Finished loading treasures");
			this->gui->ResetSlidingConditions();
		break;

		case 2:
			this->ConfigureBackground(2);
			//this->game->PrepareNextLevel(2, base_demand, move_count);
			total = this->game->total_score;
			this->game  = new GameSession(2, gui, base_demand, move_count, piece_values[0],piece_values[1],piece_values[2],piece_values[3],piece_values[4],piece_values[5], total);
			this->PushConsoleMessage("Finished loading session");
			this->resource_manager->current_level = 2;
			this->resource_manager->RefreshBlockFrames();
			this->RandomlyCreatePieces();
			spike_count = 0;
			for (int i = 0; i < 8; i++)
				this->spikes[i] = false;
			this->audio.PlayMusic(1);
			this->level_view.SetupIntroView(2, this->gui->demand_info.GetText());
			this->PushConsoleMessage("Finished loading intro view");
			this->game_state = 11;
			this->gui->ResetTreasures();
			this->PushConsoleMessage("Finished loading treasures");
			this->gui->ResetSlidingConditions();
		break;

		case 3:
			this->ConfigureBackground(3);
			//this->game->PrepareNextLevel(3, base_demand, move_count);
			total = this->game->total_score;
			this->game = new GameSession(3, gui, base_demand, move_count, piece_values[0],piece_values[1],piece_values[2],piece_values[3],piece_values[4],piece_values[5], total);
			this->PushConsoleMessage("Finished loading ssssion");
			this->resource_manager->current_level = 3;
			this->resource_manager->RefreshBlockFrames();
			this->RandomlyCreatePieces();
			spike_count = 0;
			for (int i = 0; i < 8; i++)
				this->spikes[i] = false;
			this->audio.PlayMusic(1);
			this->level_view.SetupIntroView(3, this->gui->demand_info.GetText());
			this->PushConsoleMessage("Finished loading intro view");
			this->game_state = 11;
			this->gui->ResetTreasures();
			this->PushConsoleMessage("Finished loading treasures");
			this->gui->ResetSlidingConditions();
		break;
	}
	//this->resource_manager->UnloadUnusedAssets(1);
}

void GameEngine::ConfigureConsole()
{
	int init_y = 10;
	for (int i = 0; i < 5; i++)
	{
		in_game_console[i].SetText(" ");
		in_game_console[i].SetSize(14);
		in_game_console[i].SetColor(sf::Color(0,180,0));
		in_game_console[i].SetPosition((float)m_window_ptr->GetWidth()- 400, (float)init_y + i*25);
	}
	in_game_console[0].SetText("In-Game Console started sucefully...");
	showConsole = true;
}

void GameEngine::PushConsoleMessage(std::string new_message)
{
	//Deprecated
	//in_game_console[4].SetText(in_game_console[3].GetText());
	//in_game_console[3].SetText(in_game_console[2].GetText());
	//in_game_console[2].SetText(in_game_console[1].GetText());
	//in_game_console[1].SetText(in_game_console[0].GetText());
	//in_game_console[0].SetText(new_message);
}

void GameEngine::ConfigurePuzzleList()
{
	this->puzzle_list_view = new PuzzleListView((float)max_tile_size * this->tile_size_factor,this->m_window_ptr);
	this->puzzle_list_view->puzzle_view_background.SetImage(this->resource_manager->GetImageResource(74));
	this->puzzle_list_view->puzzle_view_background.Resize((float)(1920 * (float)m_window_ptr->GetWidth())/1920, (float)(1080 * (float)m_window_ptr->GetHeight())/1080);
	std::cout << "\n\n\nLoading Puzzle View info...\n";
	std::string file_lines[64];
	int index = 0;
	std::ifstream infile;
	infile.open ("Config/puzzle_selection.txt");
        while(!infile.eof()) 
        {
			std::getline(infile,file_lines[index]);
			index++;
        }
	infile.close();
	int pos;
	std::stringstream ss;
	for (int i = 0; i < 64; i++)
	{
		int puzzle_row;
		pos = file_lines[i].find("=");
		pos++;
		ss << file_lines[i].substr(pos); 
		ss >> puzzle_row;
		ss.clear();
		if (puzzle_row == 0)
		{
			this->puzzle_list_view->unlocked_puzzle_row[i] = false;
			//std::cout << "Puzzle row: [" << i<< "] is LOCKED\n";
		}
		else if (puzzle_row == 1)
		{
			this->puzzle_list_view->unlocked_puzzle_row[i] = true;
			//std::cout << "Puzzle row: [" << i<< "] is UNLOCKED\n";
		}
	}
	int index_puzzle = 0;
	for (int i = 0; i < 8; i++)
	{
		for(int j = 0 ; j < 8; j++)
		{
			if (this->puzzle_list_view->unlocked_puzzle_row[index_puzzle] == false)
			{
				this->puzzle_list_view->puzzle_locks[j][i].SetImage(this->resource_manager->GetImageResource(75));
				this->puzzle_list_view->puzzle_locks[j][i].Resize((100 * (float)m_window_ptr->GetWidth())/1920, (100 * (float)m_window_ptr->GetHeight())/1080);
				this->puzzle_list_view->puzzle_locks[j][i].SetPosition((this->m_window_ptr->GetWidth() * 590)/1920 + (j*this->puzzle_list_view->puzzle_locks[j][i].GetSize().x), (this->m_window_ptr->GetHeight() * 194)/1080 + (i*this->puzzle_list_view->puzzle_locks[j][i].GetSize().y));
			}
			index_puzzle++;
		}
	}
	

	this->game_state = 50;
	
}

void GameEngine::StartPuzzle()
{
	this->ConfigureBackground(10);
	this->game = new GameSession(1, gui, base_demand, this->puzzle_list_view->selected_puzzle_moves, piece_values[0],piece_values[1],piece_values[2],piece_values[3],piece_values[4],piece_values[5], 0);
	this->resource_manager->current_level = 1;
	this->game->turn_score = 0;
	this->game->current_turn = this->puzzle_list_view->selected_puzzle_turns;
	this->game->gui->turn_info.SetText(this->game->ConvertIntToString(this->puzzle_list_view->selected_puzzle_turns));
	this->resource_manager->RefreshBlockFrames();
	int i = 0;
    int line, column;
    for (line = 0; line < 8; line++)
    {
        for (column = 0; column < 8; column ++)
        {
            game_pieces[i] = new Piece(i, this->puzzle_list_view->selected_puzzle_board[i], m_window_ptr, resource_manager, tile_size_factor, max_tile_size);
            game_pieces[i]->px = board->board_tile[line][column]->px;
            game_pieces[i]->py = board->board_tile[line][column]->py;
            game_pieces[i]->piece_spt.SetPosition(game_pieces[i]->offset_x + game_pieces[i]->tile_size * game_pieces[i]->px, game_pieces[i]->offset_y + game_pieces[i]->tile_size * game_pieces[i]->py);
			game_pieces[i]->RefreshAllowedMoves();
            i++;
        }
    }
	spike_count = 0;
	this->animated_spikes.spike_count = 0;
	for (int i = 0; i < 8; i++)
		this->spikes[i] = false;
	this->animated_spikes.RemoveSpikes();
	this->animated_spikes.ResetAnimationFrames();
	this->audio.PlayMusic(1);
	this->gui->ResetTreasures();
	this->gui->ResetSlidingConditions();
	this->isPuzzleMode = true;
}

void GameEngine::ProcessInput()
{
    sf::Event m_event_handler;
    m_window_ptr->GetEvent( m_event_handler );
	
	if( m_event_handler.Type == sf::Event::KeyPressed && m_event_handler.Key.Code == sf::Key::P)
	{
		//DEBUG - PRINT ALL PIECES INFO
		for (int i = 0; i < 64; i++)
			std::cout << "Piece [" << game_pieces[i]->px << "," <<  game_pieces[i]->py << "] - screen position [" << game_pieces[i]->piece_spt.GetPosition().x << "," << game_pieces[i]->piece_spt.GetPosition().y << "] - original y = " <<game_pieces[i]->original_y << "\n" ;
	}

    switch (this->game_state)
    {
		case 30: //PLAY sub-menu
			if (m_event_handler.Type == sf::Event::MouseButtonPressed && m_event_handler.MouseButton.Button == sf::Mouse::Left)
			{
				std::string response; 
				this->audio.PlaySoundEffect(3);	
				response = this->gui->ButtonInput(this->game_state, m_window_ptr->GetInput().GetMouseX(),m_window_ptr->GetInput().GetMouseY());
				if (response == "New")
				{
					//NEW GAME
					this->ResetSaveFile();
					this->StartGame(1);
				}
				else if (response == "Resume")
				{
					//RESUME GAME
					this->ParseSavedGameFile();
				}
				else if (response == "Back")
				{
					//GO BACK TO MAIN MENU
					this->game_state = 0;
				}
				std::cout << "Main Menu Event -> Button [" << response << "] was clicked\n";
			}
			if( m_event_handler.Type == sf::Event::KeyPressed && m_event_handler.Key.Code == sf::Key::Escape )
			{
				//GO BACK TO MAIN MENU
				this->game_state = 0;
			}
		break;

		case 70:
			if (m_event_handler.Type == sf::Event::MouseButtonPressed && m_event_handler.MouseButton.Button == sf::Mouse::Left)
			{
				if (this->tutorial->current_tutorial_stage == 0)
					this->tutorial->SetTutorialStage(1);
				else if (this->tutorial->current_tutorial_stage == 2)
					this->tutorial->SetTutorialStage(3);
				else if ( this->tutorial->current_tutorial_stage == 28 || this->tutorial->current_tutorial_stage == 9 || this->tutorial->current_tutorial_stage == 7 
					|| this->tutorial->current_tutorial_stage == 1 || this->tutorial->current_tutorial_stage == 3 || this->tutorial->current_tutorial_stage == 4
					|| this->tutorial->current_tutorial_stage == 6)
				{
					this->game_state = 1;
				}
				else if (this->tutorial->current_tutorial_stage == 5)
					this->tutorial->SetTutorialStage(6);
				else if (this->tutorial->current_tutorial_stage == 8)
					this->tutorial->SetTutorialStage(9);
				else if (this->tutorial->current_tutorial_stage == 10)
				{
					this->game->turn_active = false;
					this->game_state = 2;
					this->MatchPieces();
				}
				else if (this->tutorial->current_tutorial_stage == 11)
					this->tutorial->SetTutorialStage(12);
				else if (this->tutorial->current_tutorial_stage == 12)
					this->tutorial->SetTutorialStage(13);
				else if (this->tutorial->current_tutorial_stage == 13)
				{
					this->game_state = 26;
					this->gui->SetupScoreUpdate(-100, 1, true);
				}
				else if (this->tutorial->current_tutorial_stage == 14)
				{
					this->gui->SetupScoreUpdate(0, 2, this->game->GetRemainderSignal());
					this->game_state = 27;
				}
				else if (this->tutorial->current_tutorial_stage == 15)
					this->tutorial->SetTutorialStage(16);
				else if (this->tutorial->current_tutorial_stage == 16)
					this->tutorial->SetTutorialStage(17);
				else if (this->tutorial->current_tutorial_stage == 17)
					this->tutorial->SetTutorialStage(18);
				else if (this->tutorial->current_tutorial_stage == 18)
				{
					this->game_state = 2;
					this->DropDown();
				}
				else if (this->tutorial->current_tutorial_stage == 19)
					this->tutorial->SetTutorialStage(20);
				else if (this->tutorial->current_tutorial_stage == 20)
					this->tutorial->SetTutorialStage(21);
				else if (this->tutorial->current_tutorial_stage == 21)
				{
					this->game_state = 27;
					this->FinishLoop();
				}
				else if (this->tutorial->current_tutorial_stage == 22)
					this->tutorial->SetTutorialStage(23);
				else if (this->tutorial->current_tutorial_stage == 23)
				{
					this->game_state = 27;
					this->FinishLoop();
				}
				else if (this->tutorial->current_tutorial_stage == 24)
					this->tutorial->SetTutorialStage(25);
				else if (this->tutorial->current_tutorial_stage == 25)
					this->tutorial->SetTutorialStage(26);
				else if (this->tutorial->current_tutorial_stage == 26)
					this->tutorial->SetTutorialStage(27);
				else if (this->tutorial->current_tutorial_stage == 27)
				{
					this->game_state = 27;
					this->FinishLoop();
				}
			}
		break;

		case 50: //Puzzle Selection sub-menu
			if( m_event_handler.Type == sf::Event::KeyPressed && m_event_handler.Key.Code == sf::Key::Escape )
			{
				//GO BACK TO MAIN MENU
				this->game_state = 0;
			}
			/*
			else if( m_event_handler.Type == sf::Event::KeyPressed && m_event_handler.Key.Code == sf::Key::Space )
			{
				//load Test Puzzle 
				if (this->puzzle_list_view->PrepareSelectedPuzzleToPlay(0))
				{
					//Switch to puzzle board
					this->StartPuzzle();
					this->game_state = 1;
				}
				else
				{
					//Something went wrong - return to main menu;
					this->game_state = 0;
					std::cout << "Error loading puzzle - returning to main menu\n";
				}
			}
			*/
			if (m_event_handler.Type == sf::Event::MouseButtonPressed && m_event_handler.MouseButton.Button == sf::Mouse::Left)
			{
				std::string response = this->puzzle_list_view->HandleButtons(m_window_ptr->GetInput().GetMouseX(),m_window_ptr->GetInput().GetMouseY());
				if (response != "none")
				{
					std::istringstream buffer(response);
					int puzzle_index;
					buffer >> puzzle_index;
					puzzle_index--;
					//std::cout << "\nPuzzle selected: " << response << ", after parse [" << puzzle_index << "]";
					//load Test Puzzle 
					if (this->puzzle_list_view->PrepareSelectedPuzzleToPlay(puzzle_index))
					{
						//std::cout <<"\nDEBUG: finished parsing the selected puzzle, outside PrepareSelectedPuzzleToPlay()\n";
						//Switch to puzzle board
						this->StartPuzzle();
						this->game_state = 1;
					}
					else
					{
						this->audio.PlayMusic(0);
						//Something went wrong - return to main menu;
						this->game_state = 0;
						//std::cout << "Error loading puzzle - returning to main menu\n";
					}
				}

			}

		break;

        case 0: // Title / Main Menu Screen
			/*           
			if( m_event_handler.Type == sf::Event::Closed )
			{
				std::cout <<"Closing Chesster context window...\n";
                m_window_ptr->Close();
			}
            */

			if( m_event_handler.Type == sf::Event::KeyPressed && m_event_handler.Key.Code == sf::Key::Escape )
			{
				this->running = false;
				this->audio.background_sound.Stop();
                m_window_ptr->Close();
			}
            /*
			if( m_event_handler.Type == sf::Event::KeyPressed && m_event_handler.Key.Code == sf::Key::Return )
			{
				this->game = new GameSession(1, gui, base_demand, move_count, piece_values[0],piece_values[1],piece_values[2],piece_values[3],piece_values[4],piece_values[5]);
				this->RandomlyCreatePieces();
		
				spike_count = 0;
		
				for (int i = 0; i < 8; i++)
					this->spikes[i] = false;

				this->game_state = 1;
			}
			*/
			if (m_event_handler.Type == sf::Event::MouseButtonPressed && m_event_handler.MouseButton.Button == sf::Mouse::Left)
			{
				std::string response; 

				this->audio.PlaySoundEffect(3);
				
				response = this->gui->ButtonInput(this->game_state, m_window_ptr->GetInput().GetMouseX(),m_window_ptr->GetInput().GetMouseY());
				
				if (response == "Play")
				{
					//this->PushConsoleMessage("Starting game...");
					if (this->CheckForSavedGames())
						this->game_state = 30; //If there is a valid saved game - offer to load it or to start a brand new one
					else
						this->StartGame(1); //If there isn큧 a valid saved game - start a brand new one

				}
				else if (response == "Tutorial")
				{
					this->PushConsoleMessage("Loading tutorial view");
					this->StartTutorial();
				}
				else if (response == "Puzzle")
				{
					this->ConfigurePuzzleList();
				}
				else if (response == "Scores")
				{
					this->PushConsoleMessage("Loading scores view");
					this->LoadRanking();
				}
				else if (response == "Credits")
				{
					this->PushConsoleMessage("Loading credits view");
					this->game_state = 14;
				}
				else if (response == "Quit")
				{
					this->PushConsoleMessage("Goodbye!");
					this->running = false;
					this->audio.background_sound.Stop();
					m_window_ptr->Close();
				}
				std::cout << "Main Menu Event -> Button [" << response << "] was clicked\n";
			}
        break;
		/*
		case 10: // Tutorial
			if( m_event_handler.Type == sf::Event::KeyPressed && m_event_handler.Key.Code == sf::Key::Escape )
			{
                this->tutorial->EscapeEvent();
				//this->tutorial->~TutorialView();
			}
			else if( m_event_handler.Type == sf::Event::KeyPressed && m_event_handler.Key.Code == sf::Key::Left )
                this->tutorial->BackEvent();
			else if( m_event_handler.Type == sf::Event::KeyPressed && m_event_handler.Key.Code == sf::Key::Right )
                this->tutorial->NextEvent();
			break;
        */
		case 11:
			if( m_event_handler.Type == sf::Event::KeyPressed )
			{
				
				//UpdateLocalScore();
				
				if (this->level_view.current_view == "defeat")
				{
					this->ConfigureBackground(0);
					this->game_state = 0;
					this->audio.PlayMusic(0);
					this->ReleasePiecesFromMemory();
				}
				else if (this->level_view.current_view == "victory")
				{
					if (this->game->current_level < 3) // Last level = 3 for the Enhanced Demo Version
					{
						this->StartGame(this->game->current_level + 1);
						//Save to game at the beginning of level
						this->SaveSessionToFile();
					}
					else //Reset to first level and set game to title screen
					{
						this->ResetSaveFile();
						this->ConfigureBackground(0);
						this->game_state = 0;
						this->audio.PlayMusic(0);
						this->ReleasePiecesFromMemory();
						UpdateLocalScore();
					}
				}
				else if (this->level_view.current_view == "intro")
				{
					//this->game_state = 1;
					this->tutorial->SetTutorialStage(0);
					this->game_state = 70;
				}

			}
			break;

		case 12:
			if( m_event_handler.Type == sf::Event::KeyPressed )
			{
				this->game_state = 0;
			}
			break;

		case 14:
			if( m_event_handler.Type == sf::Event::KeyPressed )
			{
				this->game_state = 0;
			}
			break;

		case 1: //Game Running
            if( m_event_handler.Type == sf::Event::KeyPressed && m_event_handler.Key.Code == sf::Key::Escape )
			{
				//this->running = false;
				if (this->isPuzzleMode)
					this->isPuzzleMode = false;
				this->ConfigureBackground(0);
				this->animated_spikes.RemoveSpikes();
                this->game_state = 0;
				this->audio.PlayMusic(0);
				this->ReleasePiecesFromMemory();
				game_pieces[selected_piece_id]->VerifyDeselection();
                some_piece_is_selected = false;
			}
			//Piece selection
			else if (some_piece_is_selected == false && m_event_handler.Type == sf::Event::MouseButtonPressed && m_event_handler.MouseButton.Button == sf::Mouse::Left)
            {
				this->gui->ButtonInput(this->game_state, m_window_ptr->GetInput().GetMouseX(),m_window_ptr->GetInput().GetMouseY());
				
				if (this->game->turn_active) // Check if player select pieces
				{
					int i;
					for (i=0;i<64;i++)
					{
						//if (game_pieces[i]->valid == false || game_pieces[i]->moved == true || game_pieces[i]->sprite_id == 28  || game_pieces[i]->sprite_id == 7 || game_pieces[i]->sprite_id == 6 || game_pieces[i]->px < animated_spikes.spike_count || game_pieces[i]->py < animated_spikes.spike_count) 
						if (game_pieces[i]->valid == false || game_pieces[i]->moved || game_pieces[i]->sprite_id == 28  || game_pieces[i]->sprite_id == 7 || game_pieces[i]->sprite_id == 6 || game_pieces[i]->px < animated_spikes.spike_count || game_pieces[i]->py < animated_spikes.spike_count) 
						{
							//Piece already moved or it큦 a blocked piece or any other selection blocking condition
							if(game_pieces[i]->moved && !this->isPuzzleMode && !this->tutorial->piece_already_moved && 
								game_pieces[i]->IsFocused(m_window_ptr->GetInput().GetMouseX(), m_window_ptr->GetInput().GetMouseY()))
							{
								//std::cout << "piece_already_moved=" << this->tutorial->piece_already_moved << "  piece moved=" << game_pieces[i]->moved << "\n";
								this->tutorial->SetTutorialStage(7);
								this->game_state = 70;
							}
						}
						else 
						{
							if (game_pieces[i]->VerifySelection(m_window_ptr->GetInput().GetMouseX(), m_window_ptr->GetInput().GetMouseY()))
							{
								some_piece_is_selected =  true;
								selected_piece_id = i;
								return;
							}
						}
					}
				}
            }
			/*
			//Cancel piece selection
            else if (some_piece_is_selected && m_event_handler.Type == sf::Event::MouseButtonPressed && m_event_handler.MouseButton.Button == sf::Mouse::Right)
            {
                game_pieces[selected_piece_id]->VerifyDeselection();
                some_piece_is_selected = false;
            }
			*/
			//Piece killing piece
			else if (some_piece_is_selected && game_pieces[possible_target_piece]->sprite_id != 6 
				&& game_pieces[possible_target_piece]->sprite_id != 7 
				&& possible_target_piece != -1 && m_event_handler.Type == sf::Event::MouseButtonReleased 
				&& m_event_handler.MouseButton.Button == sf::Mouse::Left)
            {
                this->selected_piece_original_position = sf::Vector2i(game_pieces[selected_piece_id]->px, game_pieces[selected_piece_id]->py);
                //if ( game_pieces[selected_piece_id]->VerifyLandingSquare(game_pieces[possible_target_piece]->px, game_pieces[possible_target_piece]->py) && game_pieces[possible_target_piece]->valid)
				if ( game_pieces[selected_piece_id]->VerifyLandingSquare(game_pieces[possible_target_piece]->px, game_pieces[possible_target_piece]->py))
                {

					some_piece_is_selected = false;      
					game_pieces[possible_target_piece]->RelocateKilledPiece(this->selected_piece_original_position);
					game_pieces[possible_target_piece]->valid = false;
					if (this->isPuzzleMode)
					{
						for (unsigned int j = 0; j < this->puzzle_list_view->target_pieces.size(); j++)
						{
							if (possible_target_piece == this->puzzle_list_view->target_pieces[j])
							{
								this->puzzle_list_view->target_pieces[j] = -99;
								break;
							}
						}
					}
					if (this->game->moves_left > 0)//decrement player moves
					{
						this->game->DecrementMoves();
						if (!this->isPuzzleMode && this->tutorial->first_invalid_move && !this->tutorial->first_valid_move)
						{
							this->game_state = 70;
							this->tutorial->SetTutorialStage(4);
						}
						else if (!this->isPuzzleMode && !this->tutorial->first_invalid_move && !this->tutorial->first_valid_move)
						{
							this->game_state = 70;
							this->tutorial->SetTutorialStage(5);
						}
						if (!this->isPuzzleMode && !this->tutorial->second_valid_move && this->game->moves_left == 1)
						{
							this->game_state = 70;
							this->tutorial->SetTutorialStage(8);
						}
					}
					if (this->game->moves_left <= 0) 
					{
						if (!this->isPuzzleMode && !this->tutorial->third_valid_move)
						{
							this->game_state = 70;
							this->tutorial->SetTutorialStage(10);
						}
						else
						{
							this->game->turn_active = false;
							this->game_state = 2;
							this->MatchPieces();
						}
					}
                }
                else
                {
                    game_pieces[selected_piece_id]->VerifyDeselection();
                    some_piece_is_selected = false;
					if (!this->isPuzzleMode && !this->tutorial->first_invalid_move)
					{
						this->game_state = 70;
						this->tutorial->SetTutorialStage(2);
					}
                }
            }
			//Piece focusing
            else if (m_event_handler.Type == sf::Event::MouseMoved && some_piece_is_selected)
            {
                int i;
                for (i=0;i<64;i++)
                {
                    if (game_pieces[i]->IsFocused(m_window_ptr->GetInput().GetMouseX(), m_window_ptr->GetInput().GetMouseY()))
                    {
                        possible_target_piece = i;
						if (game_pieces[i]->px < animated_spikes.spike_count || game_pieces[i]->py < animated_spikes.spike_count)
						{
							possible_target_piece = -1;
						}
                        break;
                    }
					if (i == 63)
					{
						possible_target_piece = -1;
					}
                }
            }

        break;

		case 2:
			if( m_event_handler.Type == sf::Event::KeyPressed && m_event_handler.Key.Code == sf::Key::Escape )
                m_window_ptr->Close();

			break;
    }
}

void GameEngine::LoadRanking()
{
	this->GetOnlineRanking();
	//std::cout << "\n\n\nPreparing to configure scores view\n\n\n";
	this->ranking_view.ConfigScoresView(this->local_record, this->online_record);
	//std::cout << "\n\n\nSetting game state to 12\n\n\n";
	this->game_state = 12;
}

void GameEngine::UpdateLocalScore()
{
	std::stringstream ss;

	ss << this->local_record;
	int local_record_to_int;
	ss >> local_record_to_int;
	ss.clear();

	if (local_record_to_int < this->game->total_score)
	{
		this->local_record = this->game->ConvertIntToString(this->game->total_score);
		std::ofstream myfile;
		myfile.open ("Config/config_ext.txt");
		myfile << this->local_record;
		myfile.close();
        /*
		sf::Http http;
		http.SetHost("www.spacecatstudio.com");
		sf::Http::Request request;
		request.SetMethod(sf::Http::Request::Get);
		std::string username = "username=Christian";
		std::string score = "score=";
		score = score + this->local_record;
		std:: string uri = "/wp-content/uploads/2012/02/send_ranking.php?";
		uri =  uri + username;
		uri = uri + "&" + score;
		request.SetURI(uri);
		http.SendRequest(request);
         */
	}
}

void GameEngine::StartTutorial()
{
	this->tutorial->Reset();
	//this->game_state = 10;
}

void GameEngine::ActivateCascadeFall(int falling_column, int limit_row)
{
    int id;
    for (id = 0; id < 64; id++)
    {
        if (game_pieces[id]->valid && game_pieces[id]->px == falling_column && game_pieces[id]->py < limit_row)
        {
            game_pieces[id]->is_falling_down = true;
        }

    }
}


void GameEngine::MatchAndDropDownLoop()
{
		if (is_still_removing_combos)
		{
			this->RemoveCombos();
		}
		else if (is_dropping_down)
		{
			this->IsDropDownFinished();
		}
		/*
		else if (is_still_removing_combos == false)
		{
			this->MatchPieces();
		}
		*/
}

void GameEngine::CheckNegativeScore(int score)
{
	if (this->isPuzzleMode)
		return;

	if (score < 0)
	{
		this->animated_spikes.AddSpike();
		this->audio.PlaySoundEffect(1);
	}
	else
	{
		this->animated_spikes.RemoveSpikes();
	}
}

int GameEngine::GetValidTreasureSpawnLocation()
{
	int random_id = sf::Randomizer::Random(0, 64);
	/*
	for (int i = 0; i < 64; i++)
    {
		if (game_pieces[i]->valid == false)
		{
			return i;
		}
	}
	*/
	return random_id;
}


void GameEngine::SpawnTreasure()
{
	int treasure_id = this->game->GetTreasureId();
	//Do something to spawn a treasure
	this->game->UnlockTreasure();
	std::cout << "Treasure spawn on [" << this->game->treasure_layer[treasure_id] << "] points\n";
	int piece_to_become_treasure = this->GetValidTreasureSpawnLocation();
	this->game_pieces[piece_to_become_treasure]->RespawnPieceAsTreasure(treasure_id);
	this->game_pieces[piece_to_become_treasure]->StartSpecialSpawnAnimation();
}

void GameEngine::FinishLoop()
{
	this->RestorePiecesMovement();

	if (this->game->CheckTreasureUnlock() && !this->isPuzzleMode)
		this->SpawnTreasure();
	
	this->CheckNegativeScore(this->game->EndTurn());
	
	this->gui->turn_info.SetText(this->game->ConvertIntToString(this->game->current_turn));
	
	if (this->animated_spikes.spike_count <= 4)
	{
		if (this->game->current_turn > 0)
		{
			if (this->game->current_turn == 9 && !this->tutorial->second_turn && !this->isPuzzleMode)
			{
				this->game_state = 70;
				this->tutorial->SetTutorialStage(28);
			}
			else
				this->game_state = 1;
		}
		else
		{
			if (this->isPuzzleMode)
			{
				std::cout << "Finished the available turns in Puzzle mode\n";
				if (this->CheckPuzzleSolution())
				{
					this->combo_title.SetupPuzzleLabel("SOLVED");
					this->game_state = 55;
				}
				else
				{
					this->combo_title.SetupPuzzleLabel("FAILED");
					this->game_state = 55;
				}
			}
			else
			{
				//level completed with victory case
				this->animated_spikes.ResetSpikes();
				//this->game_state = 0;
				level_view.SetupVictoryView(this->game->current_level, this->gui->total_points_info.GetText());
				this->game_state = 11;
			}
		}
	}
	else
	{
		if (!this->isPuzzleMode)
		{
			//level completed with defeat case
			this->animated_spikes.ResetSpikes();
			level_view.SetupDefeatView(this->game->current_level, this->gui->total_points_info.GetText());
			//this->game_state = 0;
			this->game_state = 11;
		}
	}

	this->gui->RetifyTextPositions();
	this->gui->currentScore = 0;
	this->gui->turn_points_info.SetText("0");
}

bool GameEngine::IsDropDownFinished()
{
	for (int i = 0; i < 64; i++)
    {
		if (game_pieces[i]->is_falling_down)
		{
			return false;
		}
	}
	
	is_dropping_down = false;
	//if (!this->isPuzzleMode)
		this->RespawnDeadPieces();
	/*
	else
	{
		if (this->CheckPuzzleSolution())
		{
			//The puzzle has been solved
			//this->audio.PlayMusic(0);
			//this->game_state = 50;
			this->combo_title.SetupPuzzleLabel("SOLVED");
			this->game_state = 55;
		}
		else
		{
			this->MatchPieces();
		}
	}
	*/
	return true;
}

void GameEngine::RespawnDeadPieces()
{
	int snapshot[8][8];

	for (int i = 0; i < 64; i++)
    {
		if (game_pieces[i]->valid == false)
		{
			if (this->isPuzzleMode)
				game_pieces[i]->Respawn(-28);
			else
				game_pieces[i]->Respawn(-1);
			snapshot[game_pieces[i]->px][game_pieces[i]->py] = i;
		}
		else
		{
			snapshot[game_pieces[i]->px][game_pieces[i]->py] = -1;
		}
	}
	
	if (!this->isPuzzleMode)
	{
		int temp_pieces[8][8];
		for (int i = 0; i < 64; i++)
		{
			//The 99 code is to mark invalid pieces...
			if (game_pieces[i]->valid)
				temp_pieces[game_pieces[i]->px][game_pieces[i]->py] = game_pieces[i]->sprite_id;
			else
				temp_pieces[game_pieces[i]->px][game_pieces[i]->py] = 99;
		}
		//init vertical parse vector all to 0
		int vertical_parse[8][8];
		//init horizontal parse vector all to 0
		int horizontal_parse[8][8];

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
			   vertical_parse[i][j] = 0;
			   horizontal_parse[i][j] = 0;
			}
		}

		//Horizontal Scan
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (i >= 1)
				{
					if (temp_pieces[i - 1][j] == temp_pieces[i][j])
						horizontal_parse[i][j] += 1;
				}
				if (i <= 6)
				{
					if (temp_pieces[i + 1][j] == temp_pieces[i][j])
						horizontal_parse[i][j] += 1;
				}

				 if (j >= 1)
				{
					if (temp_pieces[i][j-1] == temp_pieces[i][j])
						vertical_parse[i][j] += 1;
				}
				if (j <= 6)
				{
					if (temp_pieces[i][j+1] == temp_pieces[i][j])
						vertical_parse[i][j] += 1;
				}
			}
		}
		
		//Match the pieces
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (horizontal_parse[i][j] == 2)
				{
					if (snapshot[i][j] != -1)
					{
						game_pieces[snapshot[i][j]]->Respawn(game_pieces[snapshot[i][j]]->sprite_id);
						break;
					}

					if(i>=1)
					{
						if (snapshot[i-1][j] != -1)
						{
							game_pieces[snapshot[i-1][j]]->Respawn(game_pieces[snapshot[i-1][j]]->sprite_id);
							break;
						}
					}
					if(i<=6)
					{
						if (snapshot[i+1][j] != -1)
						{
							game_pieces[snapshot[i+1][j]]->Respawn(game_pieces[snapshot[i+1][j]]->sprite_id);
							break;
						}
					}
					
				}

				if (vertical_parse[i][j] == 2)
				{
					if (snapshot[i][j] != -1)
					{
						game_pieces[snapshot[i][j]]->Respawn(game_pieces[snapshot[i][j]]->sprite_id);
						break;
					}

					if(j<=6)
					{
						if (snapshot[i][j+1] != -1)
						{
							game_pieces[snapshot[i][j+1]]->Respawn(game_pieces[snapshot[i][j+1]]->sprite_id);
							break;
						}					
					}
					if(j>=1)
					{
						if (snapshot[i][j-1] != -1)
						{
							game_pieces[snapshot[i][j-1]]->Respawn(game_pieces[snapshot[i][j-1]]->sprite_id);
							break;
						}
					}
				}
			}
		}
	}
	
	this->game_state = 84;
	return;
	//this->MatchPieces();
}

bool GameEngine::NeedToDropDown()
{
	/*
	if (!this->isPuzzleMode)
	{
		for (int i = 0; i < 64; i++)
		{
			if (game_pieces[i]->valid == false)
				return true;
		}

		return false;
	}
	else
	{	
		return false;
	}
	*/
	for (int i = 0; i < 64; i++)
		{
			if (game_pieces[i]->valid == false)
				return true;
		}

		return false;
}


void GameEngine::DropDown()
{
	is_dropping_down = true;
	this->pieces_moving = 0;
	int mirror[8][8];
	int dropdowns[8][8];
	for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++) 
        {
			dropdowns[i][j] = 0;
		}
	}
	//Read all pieces into 8x8 2D array according the the board tile positions px and py
	for (int i = 0; i < 64; i++)
    {
		mirror[game_pieces[i]->px][game_pieces[i]->py] = i;
    }

	for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++) 
        {
			if (game_pieces[mirror[i][j]]->valid)
			{
			    //Check how many invalid pieces are below the current valid piece
				if ( j < 7 ) // Ignores the last row
				{
					for (int k = j + 1; k < 8; k ++)
					{
						if (game_pieces[mirror[i][k]]->valid == false)
						{
							dropdowns[i][j] += 1;
						}
					}
				}
			}
			else
			{
				//Check how many valid pieces are above the current invalid piece
				if (j > 0)
				{
					for (int k = j - 1; k >= 0; k --)
					{
						if (game_pieces[mirror[i][k]]->valid)
						{
							dropdowns[i][j] -= 1;
						}
					}
				}
			}
        }
    }
	
	//Report to each piece what to do when drop down takes place 
	for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++) 
        {
			if (dropdowns[i][j] != 0)
			{
				game_pieces[mirror[i][j]]->StartDropDown(dropdowns[i][j]);
			}
		}
	}
}

void GameEngine::CheckSpecialCombos()
{
	std::vector<int> queens;
	for (int i = 0; i < 64; i++)
    {
		if (game_pieces[i]->valid && game_pieces[i]->sprite_id == 5)
		{
			queens.push_back(i);
		}
	}

	for (unsigned int j = 0; j < queens.size(); j++)
	{
		//Looking for Queen큦 Castle - horizontal
		if (game_pieces[queens[j]]->px >= 2 && game_pieces[queens[j]]->px <= 5)
		{
			int x_minus_1 = this->FindPieceUniqueId(game_pieces[queens[j]]->px - 1,game_pieces[queens[j]]->py);
			int x_minus_2 = this->FindPieceUniqueId(game_pieces[queens[j]]->px - 2,game_pieces[queens[j]]->py); 
			int x_plus_1 = this->FindPieceUniqueId(game_pieces[queens[j]]->px + 1,game_pieces[queens[j]]->py);
			int x_plus_2 = this->FindPieceUniqueId(game_pieces[queens[j]]->px + 2,game_pieces[queens[j]]->py); 


			if (game_pieces[x_minus_1]->sprite_id == 2 && game_pieces[x_minus_2]->sprite_id == 2 && game_pieces[x_plus_1]->sprite_id == 2 && game_pieces[x_plus_2]->sprite_id == 2)
			{
				game_pieces[x_minus_1]->backup_sprite_id = game_pieces[x_minus_1]->sprite_id;
				game_pieces[x_minus_2]->backup_sprite_id = game_pieces[x_minus_2]->sprite_id;
				game_pieces[x_plus_1]->backup_sprite_id = game_pieces[x_plus_1]->sprite_id;
				game_pieces[x_plus_2]->backup_sprite_id = game_pieces[x_plus_2]->sprite_id;
				game_pieces[queens[j]]->backup_sprite_id = game_pieces[queens[j]]->sprite_id;

				game_pieces[x_minus_1]->sprite_id = 8;
				game_pieces[x_minus_2]->sprite_id = 8;
				game_pieces[x_plus_1]->sprite_id = 8;
				game_pieces[x_plus_2]->sprite_id = 8;
				game_pieces[queens[j]]->sprite_id = 8;
				std::cout << "Special combo found : [Queens Castle]\n";
			}
		}
		//Looking for Queen큦 Castle - vertical
		if (game_pieces[queens[j]]->py >= 2 && game_pieces[queens[j]]->py <= 5)
		{
			int y_minus_1 = this->FindPieceUniqueId(game_pieces[queens[j]]->px, game_pieces[queens[j]]->py - 1);
			int y_minus_2 = this->FindPieceUniqueId(game_pieces[queens[j]]->px, game_pieces[queens[j]]->py - 2); 
			int y_plus_1 = this->FindPieceUniqueId(game_pieces[queens[j]]->px, game_pieces[queens[j]]->py + 1);
			int y_plus_2 = this->FindPieceUniqueId(game_pieces[queens[j]]->px, game_pieces[queens[j]]->py + 2); 


			if (game_pieces[y_minus_1]->sprite_id == 2 && game_pieces[y_minus_2]->sprite_id == 2 && game_pieces[y_plus_1]->sprite_id == 2 && game_pieces[y_plus_2]->sprite_id == 2)
			{
				game_pieces[y_minus_1]->backup_sprite_id = game_pieces[y_minus_1]->sprite_id;
				game_pieces[y_minus_2]->backup_sprite_id = game_pieces[y_minus_2]->sprite_id;
				game_pieces[y_plus_1]->backup_sprite_id = game_pieces[y_plus_1]->sprite_id;
				game_pieces[y_plus_2]->backup_sprite_id = game_pieces[y_plus_2]->sprite_id;
				game_pieces[queens[j]]->backup_sprite_id = game_pieces[queens[j]]->sprite_id;

				game_pieces[y_minus_1]->sprite_id = 8;
				game_pieces[y_minus_2]->sprite_id = 8;
				game_pieces[y_plus_1]->sprite_id = 8;
				game_pieces[y_plus_2]->sprite_id = 8;
				game_pieces[queens[j]]->sprite_id = 8;
				std::cout << "Special combo found : [Queens Castle]\n";
			}
		}
		//Looking for Queen큦 Guard - horizontal
		if (game_pieces[queens[j]]->px >= 2 && game_pieces[queens[j]]->px <= 5)
		{
			int x_minus_1 = this->FindPieceUniqueId(game_pieces[queens[j]]->px - 1,game_pieces[queens[j]]->py);
			int x_minus_2 = this->FindPieceUniqueId(game_pieces[queens[j]]->px - 2,game_pieces[queens[j]]->py); 
			int x_plus_1 = this->FindPieceUniqueId(game_pieces[queens[j]]->px + 1,game_pieces[queens[j]]->py);
			int x_plus_2 = this->FindPieceUniqueId(game_pieces[queens[j]]->px + 2,game_pieces[queens[j]]->py); 


			if (game_pieces[x_minus_1]->sprite_id == 0 && game_pieces[x_minus_2]->sprite_id == 0 && game_pieces[x_plus_1]->sprite_id == 0 && game_pieces[x_plus_2]->sprite_id == 0)
			{
				game_pieces[x_minus_1]->backup_sprite_id = game_pieces[x_minus_1]->sprite_id;
				game_pieces[x_minus_2]->backup_sprite_id = game_pieces[x_minus_2]->sprite_id;
				game_pieces[x_plus_1]->backup_sprite_id = game_pieces[x_plus_1]->sprite_id;
				game_pieces[x_plus_2]->backup_sprite_id = game_pieces[x_plus_2]->sprite_id;
				game_pieces[queens[j]]->backup_sprite_id = game_pieces[queens[j]]->sprite_id;

				game_pieces[x_minus_1]->sprite_id = 9;
				game_pieces[x_minus_2]->sprite_id = 9;
				game_pieces[x_plus_1]->sprite_id = 9;
				game_pieces[x_plus_2]->sprite_id = 9;
				game_pieces[queens[j]]->sprite_id = 9;
				std::cout << "Special combo found : [Queen's Guard]\n";
			}
		}
		//Looking for Queen큦 Guard - vertical
		if (game_pieces[queens[j]]->py >= 2 && game_pieces[queens[j]]->py <= 5)
		{
			int y_minus_1 = this->FindPieceUniqueId(game_pieces[queens[j]]->px, game_pieces[queens[j]]->py - 1);
			int y_minus_2 = this->FindPieceUniqueId(game_pieces[queens[j]]->px, game_pieces[queens[j]]->py - 2); 
			int y_plus_1 = this->FindPieceUniqueId(game_pieces[queens[j]]->px, game_pieces[queens[j]]->py + 1);
			int y_plus_2 = this->FindPieceUniqueId(game_pieces[queens[j]]->px, game_pieces[queens[j]]->py + 2); 


			if (game_pieces[y_minus_1]->sprite_id == 0 && game_pieces[y_minus_2]->sprite_id == 0 && game_pieces[y_plus_1]->sprite_id == 0 && game_pieces[y_plus_2]->sprite_id == 0)
			{
				game_pieces[y_minus_1]->backup_sprite_id = game_pieces[y_minus_1]->sprite_id;
				game_pieces[y_minus_2]->backup_sprite_id = game_pieces[y_minus_2]->sprite_id;
				game_pieces[y_plus_1]->backup_sprite_id = game_pieces[y_plus_1]->sprite_id;
				game_pieces[y_plus_2]->backup_sprite_id = game_pieces[y_plus_2]->sprite_id;
				game_pieces[queens[j]]->backup_sprite_id = game_pieces[queens[j]]->sprite_id;

				game_pieces[y_minus_1]->sprite_id = 9;
				game_pieces[y_minus_2]->sprite_id = 9;
				game_pieces[y_plus_1]->sprite_id = 9;
				game_pieces[y_plus_2]->sprite_id = 9;
				game_pieces[queens[j]]->sprite_id = 9;
				std::cout << "Special combo found : [Queen's Guard]\n";
			}
		}
		//Looking for Queen큦 Crusade
		if (game_pieces[queens[j]]->py >= 1 && game_pieces[queens[j]]->py >= 1 && game_pieces[queens[j]]->py <= 6 && game_pieces[queens[j]]->py <= 6)
		{
			int y_minus_1 = this->FindPieceUniqueId(game_pieces[queens[j]]->px, game_pieces[queens[j]]->py - 1);
			int x_minus_1 = this->FindPieceUniqueId(game_pieces[queens[j]]->px - 1, game_pieces[queens[j]]->py); 
			int y_plus_1 = this->FindPieceUniqueId(game_pieces[queens[j]]->px, game_pieces[queens[j]]->py + 1);
			int x_plus_1 = this->FindPieceUniqueId(game_pieces[queens[j]]->px + 1, game_pieces[queens[j]]->py);

			if (game_pieces[y_minus_1]->sprite_id == 1 && game_pieces[x_minus_1]->sprite_id == 1 && game_pieces[y_plus_1]->sprite_id == 1 && game_pieces[x_plus_1]->sprite_id == 1)
			{
				game_pieces[y_minus_1]->backup_sprite_id = game_pieces[y_minus_1]->sprite_id;
				game_pieces[x_minus_1]->backup_sprite_id = game_pieces[x_minus_1]->sprite_id;
				game_pieces[y_plus_1]->backup_sprite_id = game_pieces[y_plus_1]->sprite_id;
				game_pieces[x_plus_1]->backup_sprite_id = game_pieces[x_plus_1]->sprite_id;
				game_pieces[queens[j]]->backup_sprite_id = game_pieces[queens[j]]->sprite_id;

				game_pieces[y_minus_1]->sprite_id = 10;
				game_pieces[x_minus_1]->sprite_id = 10;
				game_pieces[y_plus_1]->sprite_id = 10;
				game_pieces[x_plus_1]->sprite_id = 10;
				game_pieces[queens[j]]->sprite_id = 10;
				std::cout << "Special combo found : [Queen's Crusade]\n";
			}
		}

		//Looking for Queen큦 Confession - horizontal
		if (game_pieces[queens[j]]->px >= 1 && game_pieces[queens[j]]->px <= 5)
		{
			int x_minus_1 = this->FindPieceUniqueId(game_pieces[queens[j]]->px - 1, game_pieces[queens[j]]->py);
			int x_plus_1 = this->FindPieceUniqueId(game_pieces[queens[j]]->px + 1, game_pieces[queens[j]]->py); 
			int x_plus_2 = this->FindPieceUniqueId(game_pieces[queens[j]]->px + 2, game_pieces[queens[j]]->py);

			if (game_pieces[x_minus_1]->sprite_id == 3 && game_pieces[x_plus_1]->sprite_id == 5 && game_pieces[x_plus_2]->sprite_id == 3)
			{
				game_pieces[x_minus_1]->backup_sprite_id = game_pieces[x_minus_1]->sprite_id;
				game_pieces[x_plus_1]->backup_sprite_id = game_pieces[x_plus_1]->sprite_id;
				game_pieces[x_plus_2]->backup_sprite_id = game_pieces[x_plus_2]->sprite_id;
				game_pieces[queens[j]]->backup_sprite_id = game_pieces[queens[j]]->sprite_id;

				game_pieces[x_minus_1]->sprite_id = 11;
				game_pieces[x_plus_1]->sprite_id = 11;
				game_pieces[x_plus_2]->sprite_id = 11;
				game_pieces[queens[j]]->sprite_id = 11;
				std::cout << "Special combo found : [Queen's Confession]\n";
			}
		}

		//Looking for Queen큦 Confession - vertical
		if (game_pieces[queens[j]]->py >= 1 && game_pieces[queens[j]]->py <= 5)
		{
			int y_minus_1 = this->FindPieceUniqueId(game_pieces[queens[j]]->px, game_pieces[queens[j]]->py - 1);
			int y_plus_1 = this->FindPieceUniqueId(game_pieces[queens[j]]->px, game_pieces[queens[j]]->py + 1); 
			int y_plus_2 = this->FindPieceUniqueId(game_pieces[queens[j]]->px, game_pieces[queens[j]]->py + 2);

			if (game_pieces[y_minus_1]->sprite_id == 3 && game_pieces[y_plus_1]->sprite_id == 5 && game_pieces[y_plus_2]->sprite_id == 3)
			{
				game_pieces[y_minus_1]->backup_sprite_id = game_pieces[y_minus_1]->sprite_id;
				game_pieces[y_plus_1]->backup_sprite_id = game_pieces[y_plus_1]->sprite_id;
				game_pieces[y_plus_2]->backup_sprite_id = game_pieces[y_plus_2]->sprite_id;
				game_pieces[queens[j]]->backup_sprite_id = game_pieces[queens[j]]->sprite_id;

				game_pieces[y_minus_1]->sprite_id = 11;
				game_pieces[y_plus_1]->sprite_id = 11;
				game_pieces[y_plus_2]->sprite_id = 11;
				game_pieces[queens[j]]->sprite_id = 11;
				std::cout << "Special combo found : [Queen's Confession]\n";
			}
		}


		//Looking for Queen큦 Coronation - horizontal
		if (game_pieces[queens[j]]->px >= 1 && game_pieces[queens[j]]->px <= 5)
		{
			int x_minus_1 = this->FindPieceUniqueId(game_pieces[queens[j]]->px - 1, game_pieces[queens[j]]->py);
			int x_plus_1 = this->FindPieceUniqueId(game_pieces[queens[j]]->px + 1, game_pieces[queens[j]]->py); 
			int x_plus_2 = this->FindPieceUniqueId(game_pieces[queens[j]]->px + 2, game_pieces[queens[j]]->py);

			if (game_pieces[x_minus_1]->sprite_id == 4 && game_pieces[x_plus_1]->sprite_id == 5 && game_pieces[x_plus_2]->sprite_id == 4)
			{
				game_pieces[x_minus_1]->backup_sprite_id = game_pieces[x_minus_1]->sprite_id;
				game_pieces[x_plus_1]->backup_sprite_id = game_pieces[x_plus_1]->sprite_id;
				game_pieces[x_plus_2]->backup_sprite_id = game_pieces[x_plus_2]->sprite_id;
				game_pieces[queens[j]]->backup_sprite_id =game_pieces[queens[j]]->sprite_id;

				game_pieces[x_minus_1]->sprite_id = 12;
				game_pieces[x_plus_1]->sprite_id = 12;
				game_pieces[x_plus_2]->sprite_id = 12;
				game_pieces[queens[j]]->sprite_id = 12;
				std::cout << "Special combo found : [Queen's Coronation]\n";
			}
		}

		//Looking for Queen큦 Coronation - vertical
		if (game_pieces[queens[j]]->py >= 1 && game_pieces[queens[j]]->py <= 5)
		{
			int y_minus_1 = this->FindPieceUniqueId(game_pieces[queens[j]]->px, game_pieces[queens[j]]->py - 1);
			int y_plus_1 = this->FindPieceUniqueId(game_pieces[queens[j]]->px, game_pieces[queens[j]]->py + 1); 
			int y_plus_2 = this->FindPieceUniqueId(game_pieces[queens[j]]->px, game_pieces[queens[j]]->py + 2);

			if (game_pieces[y_minus_1]->sprite_id == 4 && game_pieces[y_plus_1]->sprite_id == 5 && game_pieces[y_plus_2]->sprite_id == 4)
			{
				game_pieces[y_minus_1]->backup_sprite_id = game_pieces[y_minus_1]->sprite_id;
				game_pieces[y_plus_1]->backup_sprite_id = game_pieces[y_plus_1]->sprite_id;
				game_pieces[y_plus_2]->backup_sprite_id = game_pieces[y_plus_2]->sprite_id;
				game_pieces[queens[j]]->backup_sprite_id = game_pieces[queens[j]]->sprite_id;

				game_pieces[y_minus_1]->sprite_id = 12;
				game_pieces[y_plus_1]->sprite_id = 12;
				game_pieces[y_plus_2]->sprite_id = 12;
				game_pieces[queens[j]]->sprite_id = 12;
				std::cout << "Special combo found : [Queen's Coronation]\n";
			}
		}

	}
}

void GameEngine::MatchPieces()
{
	this->CheckSpecialCombos();
    //read all pieces
    //int pieces[8][8];
    for (int i = 0; i < 64; i++)
    {
		//The 99 code is to mark invalid pieces
		if (game_pieces[i]->valid)
			pieces[game_pieces[i]->px][game_pieces[i]->py] = game_pieces[i]->sprite_id;
		else
			pieces[game_pieces[i]->px][game_pieces[i]->py] = 99;
		
		if (game_pieces[i]->sprite_id == 6)
		{
			//std::cout << "Block piece at [" << game_pieces[i]->px << "," << game_pieces[i]->py << "]\n";
			blocks_for_removal[game_pieces[i]->px][game_pieces[i]->py] = 1;
		}
		else if (game_pieces[i]->sprite_id == 7)
		{
			//std::cout << "Treasure piece at [" << game_pieces[i]->px << "," << game_pieces[i]->py << "]\n";
			treasures_for_removal[game_pieces[i]->px][game_pieces[i]->py] = 1;
		}
		else
		{
			blocks_for_removal[game_pieces[i]->px][game_pieces[i]->py] = 0;
			treasures_for_removal[game_pieces[i]->px][game_pieces[i]->py] = 0;
		}

		x_marker[i] = false;
    }
    //init vertical parse vector all to 0
    int vertical_parse[8][8];
	//init horizontal parse vector all to 0
	int horizontal_parse[8][8];

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
           vertical_parse[i][j] = 0;
		   horizontal_parse[i][j] = 0;
		   combos[0][i][j] = 0;
		   combos[1][i][j] = 0;
		   combos[2][i][j] = 0;
		   combos[3][i][j] = 0;
		   combos[4][i][j] = 0;
		   combos[5][i][j] = 0;
		   //Special combo
		   combos[6][i][j] = 0;
		   combos[7][i][j] = 0;
		   combos[8][i][j] = 0;
		   combos[9][i][j] = 0;
		   combos[10][i][j] = 0;
		   combos[11][i][j] = 0;
		   combos[12][i][j] = 0;
        }
    }

	//Horizontal Scan
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
			
				if (pieces[i][j] == 6 || pieces[i][j] == 7 || pieces[i][j] == 28)
				{
					//This is a block or treasure - do nothing
				}
				else
				{
					if (i >= 1)
					{
						if (pieces[i - 1][j] == pieces[i][j])
							horizontal_parse[i][j] += 1;
					}
					if (i <= 6)
					{
						if (pieces[i + 1][j] == pieces[i][j])
							horizontal_parse[i][j] += 1;
					}
				}
			
        }
    }
	
    //Vertical Scan
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
			
				if (pieces[i][j] == 6 || pieces[i][j] == 7 || pieces[i][j] == 28)
				{
					//This is a block - do nothing
				}
				else
				{
					if (j >= 1)
					{
						if (pieces[i][j-1] == pieces[i][j])
							vertical_parse[i][j] += 1;
					}
					if (j <= 6)
					{
						if (pieces[i][j+1] == pieces[i][j])
							vertical_parse[i][j] += 1;
					}
				}
			
        }
    }
	
    bool found_new_matches = false;
    //Match the pieces
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
			/*
			if (horizontal_parse[i][j] >= 2)
			{

				if(i>=1)
				{
					if (pieces[i-1][j] == pieces[i][j])
					{
						combos[pieces[i-1][j]][i-1][j] = -1;
						pieces[i-1][j] = -1;
					}
				}
                if(i<=6)
				{
					if (pieces[i+1][j] == pieces[i][j])
					{
						combos[pieces[i+1][j]][i+1][j] = -1;
						pieces[i+1][j] = -1;
					}
				}
				if(j<=6)
				{
					if (pieces[i][j+1] == pieces[i][j])
					{
						combos[pieces[i][j+1]][i][j+1] = -1;
						pieces[i][j+1] = -1;			
					}
				}
                if(j>=1)
				{
					if (pieces[i][j-1] == pieces[i][j])
					{
						combos[pieces[i][j-1]][i][j-1] = -1;
						pieces[i][j-1] = -1;
					}
				}
				combos[pieces[i][j]][i][j] = -1;
				pieces[i][j] = -1;
			}
			*/
			
            if (horizontal_parse[i][j] == 2)
            {
				found_new_matches = true;
                if(i>=1)
				{
					combos[pieces[i-1][j]][i-1][j] = -1;
                    pieces[i-1][j] = -1;
				}
                if(i<=6)
				{
					combos[pieces[i+1][j]][i+1][j] = -1;
                    pieces[i+1][j] = -1;
				}
				combos[pieces[i][j]][i][j] = -1;
				pieces[i][j] = -1;
            }

            if (vertical_parse[i][j] == 2)
            {
				found_new_matches = true;
                if(j<=6)
				{
					combos[pieces[i][j+1]][i][j+1] = -1;
                    pieces[i][j+1] = -1;					
				}
                if(j>=1)
				{
					combos[pieces[i][j-1]][i][j-1] = -1;
                    pieces[i][j-1] = -1;
				}
				combos[pieces[i][j]][i][j] = -1;
				pieces[i][j] = -1;
            }
			
        }
    }
	if (found_new_matches == false)
	{
		std::cout<<"Didn't found new matchs to combine\n";

		if (this->NeedToDropDown())
		{
			this->DropDown();
		}
		
		else
		{
			//Calc score
			if (!this->tutorial->first_turn_score && !this->isPuzzleMode)
			{
				this->game_state = 70;
				this->tutorial->SetTutorialStage(11);
			}
			else
			{
				this->game_state = 26;
				this->gui->SetupScoreUpdate(-100, 1, true);
				return;
			}
		}
	}

	//Food fill part
	//Special combo
	for (int piece_type = 0; piece_type < 13; piece_type++)
	{
		if(piece_type == 6 || piece_type == 7 || piece_type == 28)
			continue;

		bool snapshot[8][8];
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				snapshot[i][j] = false;
			}
		}

		for (int i = 0; i < 64; i++)
		{
			if (game_pieces[i]->sprite_id == piece_type && game_pieces[i]->valid)
				snapshot[game_pieces[i]->px][game_pieces[i]->py] = true;
		}
		//Repeat the boundary check 7 times to guarantee 100% matching precision
		for (int p =0; p<7; p++)
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					
						if (pieces[i][j] == -1 && snapshot[i][j] == true)
						{
							//Check this piece boundaries
							if (i>0)
							{
								if (pieces[i-1][j] != -1 && snapshot[i-1][j] == true)
								{
									combos[pieces[i-1][j]][i-1][j] = -1;
									pieces[i-1][j] = -1;
								}
							}
							if (i<7)
							{
								if (pieces[i+1][j] != -1 && snapshot[i+1][j] == true)
								{
									combos[pieces[i+1][j]][i+1][j] = -1;
									pieces[i+1][j] = -1;
								}
							}
							if (j>0)
							{
								if (pieces[i][j-1] != -1 && snapshot[i][j-1] == true)
								{
									combos[pieces[i][j-1]][i][j-1] = -1;
									pieces[i][j-1] = -1;
								}
							}
							if (j<7)
							{
								if (pieces[i][j+1] != -1 && snapshot[i][j+1] == true)
								{
									combos[pieces[i][j+1]][i][j+1] = -1;
									pieces[i][j+1] = -1;
								}
							}
						}
					
				}
			}
		}
	}

	ComboCheck();
	/*
	//Remove all combos in one pass
	bool still_matching_pieces = false;
	for (int i = 0; i < 64; i++)
	{
		if (pieces[game_pieces[i]->px][game_pieces[i]->py] == -1)
		{
			for (int current_marker = 0; current_marker < combo_marker.size(); current_marker++)
			{
				if (combos[game_pieces[i]->sprite_id][game_pieces[i]->px][game_pieces[i]->py] == combo_marker[current_marker])
				{
					game_pieces[i]->valid = false;
					this->game->CalculatePieceScore(game_pieces[i]->sprite_id);
					still_matching_pieces = true;
					break;
				}
			}
		}
	}

	if (still_matching_pieces == false) //Match & Drop Loop has ended
	{
		this->FinishLoop();
	}
	*/
}

int GameEngine::FindPieceUniqueId(int x, int y)
{
	for (int i = 0; i < 64; i++)
	{
		if (game_pieces[i]->px == x && game_pieces[i]->py == y)
		{
			return i;
		}
	}
}


bool GameEngine::CheckForBlocksBreaking()
{
	for (int i = 0; i < 64; i++)
	{
		if (game_pieces[i]->is_breaking_block || game_pieces[i]->is_capturing_treasure)
		{
			return true;
		}
	}

	return false;
}

void GameEngine::RemoveAdjacentBlocks(int x, int y)
{

	if (x < 7)
	{
		if (blocks_for_removal[x+1][y] == 1)
		{
			//std::cout << "Block piece [" << x+1 << "," << y << "] was marked for removal by adjacency\n";
			game_pieces[FindPieceUniqueId(x+1,y)]->valid = false;
			game_pieces[FindPieceUniqueId(x+1,y)]->StartBlockDestruction();
			blocks_for_removal[x+1][y] = 0;
		}
	}
	if (x > 0)
	{
		if (blocks_for_removal[x-1][y] == 1)
		{
			//std::cout << "Block piece [" << x-1 << "," << y << "] was marked for removal by adjacency\n";
			game_pieces[FindPieceUniqueId(x-1,y)]->valid = false;
			game_pieces[FindPieceUniqueId(x-1,y)]->StartBlockDestruction();
			blocks_for_removal[x-1][y] = 0;
		}
	}
	
	if (y > 0)
	{
		if (blocks_for_removal[x][y-1] == 1)
		{
			//std::cout << "Block piece [" << x << "," << y-1 << "] was marked for removal by adjacency\n";
			game_pieces[FindPieceUniqueId(x,y-1)]->valid = false;
			game_pieces[FindPieceUniqueId(x,y-1)]->StartBlockDestruction();
			blocks_for_removal[x][y-1] = 0;
		}
	}
	if (y < 7)
	{
		if (blocks_for_removal[x][y+1] == 1)
		{
			//std::cout << "Block piece [" << x << "," << y+1 << "] was marked for removal by adjacency\n";
			game_pieces[FindPieceUniqueId(x,y+1)]->valid = false;
			game_pieces[FindPieceUniqueId(x,y+1)]->StartBlockDestruction();
			blocks_for_removal[x][y+1] = 0;
		}
	}
}

void GameEngine::RemoveAdjacentTreasures(int x, int y)
{
	if (x < 7)
	{
		if (treasures_for_removal[x+1][y] == 1)
		{
			//std::cout << "Block piece [" << x+1 << "," << y << "] was marked for removal by adjacency\n";
			int id = FindPieceUniqueId(x+1,y);
			game_pieces[id]->valid = false;
			game_pieces[id]->StartTreasureCapture();
			this->game->ComputeTreasurePoints(game_pieces[id]->treasure_id);
			this->gui->UnlockTreasure(game_pieces[id]->treasure_id);
			treasures_for_removal[x+1][y] = 0;

		}
	}
	if (x > 0)
	{
		if (treasures_for_removal[x-1][y] == 1)
		{
			//std::cout << "Block piece [" << x-1 << "," << y << "] was marked for removal by adjacency\n";
			int id = FindPieceUniqueId(x-1,y);
			game_pieces[id]->valid = false;
			game_pieces[id]->StartTreasureCapture();
			this->game->ComputeTreasurePoints(game_pieces[id]->treasure_id);
			this->gui->UnlockTreasure(game_pieces[id]->treasure_id);
			treasures_for_removal[x-1][y] = 0;
		}
	}
	
	if (y > 0)
	{
		if (treasures_for_removal[x][y-1] == 1)
		{
			//std::cout << "Block piece [" << x << "," << y-1 << "] was marked for removal by adjacency\n";
			int id = FindPieceUniqueId(x,y-1);
			game_pieces[id]->valid = false;
			game_pieces[id]->StartTreasureCapture();
			this->game->ComputeTreasurePoints(game_pieces[id]->treasure_id);
			this->gui->UnlockTreasure(game_pieces[id]->treasure_id);
			treasures_for_removal[x][y-1] = 0;
		}
	}
	if (y < 7)
	{
		if (treasures_for_removal[x][y+1] == 1)
		{
			//std::cout << "Block piece [" << x << "," << y+1 << "] was marked for removal by adjacency\n";
			int id = FindPieceUniqueId(x,y+1);
			game_pieces[id]->valid = false;
			game_pieces[id]->StartTreasureCapture();
			this->game->ComputeTreasurePoints(game_pieces[id]->treasure_id);
			this->gui->UnlockTreasure(game_pieces[id]->treasure_id);
			treasures_for_removal[x][y+1] = 0;
		}
	}
}

void GameEngine::RemoveCombos()
{
	if (current_combo_to_remove % 100 == 0)
	{
		goto override_timer;
	}

	if (combo_by_combo_timer.GetElapsedTime() > 0.25)
	{

override_timer:
		
		//Check if we need to spawn any Queen pieces
		queens_throne = sf::Vector2i(-1,-1);
		if(!this->isPuzzleMode)
			queens_throne = this->LookForQueen();

		//Remove
		//bool still_matching_pieces = false;
		for (int i = 0; i < 64; i++)
		{
			//Remove just the current combo
			if (pieces[game_pieces[i]->px][game_pieces[i]->py] == -1)
			{
				if (combos[game_pieces[i]->sprite_id][game_pieces[i]->px][game_pieces[i]->py] == current_combo_to_remove)
				{
					if (last_combo_counted == current_combo_to_remove)
					{
						RemoveAdjacentBlocks(game_pieces[i]->px,game_pieces[i]->py);
						RemoveAdjacentTreasures(game_pieces[i]->px,game_pieces[i]->py);
						last_combo_removed = current_combo_to_remove;
						game_pieces[i]->valid = false;
						if (this->isPuzzleMode)
						{
							for (unsigned int j = 0; j < this->puzzle_list_view->target_pieces.size(); j++)
							{
								if (i == this->puzzle_list_view->target_pieces[j])
								{
									this->puzzle_list_view->target_pieces[j] = -99;
									break;
								}
							}
						}
						if (game_pieces[i]->px == queens_throne.x && game_pieces[i]->py == queens_throne.y)
						{
							//Spawn a queen piece except if the combos was already made of queens
							if (game_pieces[i]->sprite_id >= 0 && game_pieces[i]->sprite_id < 5)
							{
								game_pieces[i]->RespawnOnStart(-2);
								game_pieces[i]->StartSpecialSpawnAnimation();
								x_marker[i] = false;
							}
						}				
					}
					else
					{
						this->gui->ResetFontSize();
						this->game_state = 3;
						aux_timer.Reset();
						return;
					}
				}	
			}
		}
		//Remove the reference for the already removed combos
		for (unsigned int v = 0; v < combo_marker.size(); v++)
		{
			if (combo_marker[v] == current_combo_to_remove)
			{
				int backup;
				backup = combo_marker[combo_marker.size()-1];
				combo_marker[combo_marker.size()-1] = combo_marker[v];
				combo_marker[v] = backup;
				combo_marker.pop_back();
				break;
			}
		}
		//Check if there are no more combos to remove in the combo marker list
		if (combo_marker.size() == 0)
		{
			combo_count = 0;
			combo_points = 0;
			gui->match_points_info.SetText("");
			gui->match_amount_info.SetText("");
			gui->match_label.SetText("");
			gui->x_label.SetText("");
			is_still_removing_combos = false;
			//matching_loop_just_finished = true;
			if (this->CheckForSpecialSpawnsStillAnimating())
			{
				is_still_removing_combos = true;
				return;
			}
			else
			{
				//std::cout << "\nFinished removing the combos... game_state = " << this->game_state << "\n";;
				//this->DropDown();
				if (!this->tutorial->first_queen && !this->isPuzzleMode && has_queen)
				{
					has_queen = false;
					this->game_state = 70;
					this->tutorial->SetTutorialStage(15);
					return;
				}
				else
					this->DropDown();
			}
		}
		else
		{
			if (last_combo_removed != current_combo_to_remove)
			{
				combo_count = 0;
				combo_points = 0;
			}
			is_still_removing_combos = true;
			current_combo_to_remove = combo_marker[0];
			combo_by_combo_timer.Reset();
			return;
		}
	}
}

bool GameEngine::CheckForSpecialSpawnsStillAnimating()
{
	for (int i = 0; i< 64; i++)
	{
		if (this->game_pieces[i]->is_special_spawn)
			return true;
	}
	return false;
}


std::string GameEngine::GetMatchLabel(int sprite)
{
	switch (sprite)
	{
		case 0:
			return "Pawns";
			break;
		case 1:
			return "Knights";
			break;
		case 2:
			return "Rooks";
			break;
		case 3:
			return "Bishops";
			break;
		case 4:
			return "Kings";
			break;
		case 5:
			return "Queens";
		case 8:
			return "Queen's Castle";
			break;
		case 9:
			return "Queen's Guard";
			break;
		case 10:
			return "Queen's Crusade";
			break;
		case 11:
			return "Queen's Confession";
			break;
		case 12:
			return "Queen's Coronation";
			break;
	}
}
void GameEngine::ComboCheck()
{
	last_combo_counted = -99;

	combo_marker.clear();

	std::vector<int> special_marker;
	
	//Special combos
	for (int piece_type = 0; piece_type < 13; piece_type++)
	{
		//Ignore blocks and treasures
		if (piece_type == 6 || piece_type == 7 || piece_type == 28)
			continue;

		//Initialize the special marker for individual combos
		special_marker.clear();	

		switch (piece_type)
		{
			case 0:
				special_marker.push_back(400);
			break;
			case 1:
				special_marker.push_back(500);
			break;
			case 2:
				special_marker.push_back(600);
			break;
			case 3:
				special_marker.push_back(700);
			break;
			case 4:
				special_marker.push_back(800);
			break;
			case 5:
				special_marker.push_back(900);
			break;
			case 8: //Queens Castle
				special_marker.push_back(1000);
			break;
			case 9:
				special_marker.push_back(1100);
			break;
			case 10:
				special_marker.push_back(1200);
			break;
			case 11:
				special_marker.push_back(1300);
			break;
			case 12:
				special_marker.push_back(1400);
			break;
		}
		for( int heuristic_amount = 0; heuristic_amount < 7; heuristic_amount++)
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					
					if (combos[piece_type][i][j] == -1)
					{
						bool not_found_any = true;
						//Loop thru the existant markers to see if the piece is contained in one of the combos
						for (unsigned int current_marker = special_marker[0]; current_marker < special_marker[0] + special_marker.size(); current_marker++)
						{
							if (i>0)
							{
								if (combos[piece_type][i-1][j] == current_marker)
									combos[piece_type][i][j] = current_marker;
							}
							
							if (j>0)
							{
								if (combos[piece_type][i][j-1] == current_marker)
									combos[piece_type][i][j] = current_marker;
							}
							
							if (i<7)
							{
								if (combos[piece_type][i+1][j] == current_marker)
									combos[piece_type][i][j] = current_marker;
							}
							
							if (j<7)
							{
								if (combos[piece_type][i][j+1] == current_marker)
									combos[piece_type][i][j] = current_marker;
							}
							
							//this piece was identified as one of the existant combos - break
							if (combos[piece_type][i][j] == current_marker)
							{
								//std::cout << "Match already exists: " <<  current_marker << "\n\n";
								not_found_any = false;
								break;
							}
						}
						//this piece is part of a unindentified combo - add a new marker
						if(not_found_any)
						{
							combos[piece_type][i][j] = special_marker[special_marker.size()-1] + 1;
							special_marker.push_back(combos[piece_type][i][j]);
							//std::cout << "New match found: " <<  combos[piece_type][i][j] << "\n\n";
							break;
						}
					}
					
				}
			}
		}

		//Done marking the pieces as individual combos - time to organize them.
		for (unsigned int u = 0; u < special_marker.size(); u++)
		{
			//std::cout << "Combo id: " << special_marker[u] << "\n\n";
			combo_marker.push_back(special_marker[u]);
			//std::cout << special_marker[u] << ", ";
		}
	}
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			checked[i][j] = false;
		}
	}

	ids_to_remove.clear();

	//This will unite combos into one chunk to better track special combos 
    for (unsigned int g = 0; g < combo_marker.size(); g++)
    {
        int piece_type;
        if (combo_marker[g] >= 400 && combo_marker[g] < 500)
            piece_type = 0;
        else if (combo_marker[g] >= 500 && combo_marker[g] < 600)
            piece_type = 1;
        else if (combo_marker[g] >= 600 && combo_marker[g] < 700)
            piece_type = 2;
        else if (combo_marker[g] >= 700 && combo_marker[g] < 800)
            piece_type = 3;
        else if (combo_marker[g] >= 800 && combo_marker[g] < 900)
            piece_type = 4;
        else if (combo_marker[g] >= 900 && combo_marker[g] < 1000)
            piece_type = 5;
		else if (combo_marker[g] >= 1000 && combo_marker[g] < 1100)
            piece_type = 8; // Queens Castle
		else if (combo_marker[g] >= 1100 && combo_marker[g] < 1200)
            piece_type = 9;
		else if (combo_marker[g] >= 1200 && combo_marker[g] < 1300)
            piece_type = 10;
		else if (combo_marker[g] >= 1300 && combo_marker[g] < 1400)
            piece_type = 11;
		else if (combo_marker[g] >= 1400 && combo_marker[g] < 1500)
            piece_type = 12;

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (combos[piece_type][i][j] == combo_marker[g])
				{
					checked[i][j] = true;
					this->RecursiveCheck(piece_type, i, j, combo_marker[g]);
				}
				
			}
		}
    }

	//Check initial markers to remove
	//ids_to_remove.push_back(400);
	//ids_to_remove.push_back(500);
	//ids_to_remove.push_back(600);
	//ids_to_remove.push_back(700);
	//ids_to_remove.push_back(800);
	//ids_to_remove.push_back(900);
	
	//Remove the blank combo markers
    for ( unsigned int b = 0; b < ids_to_remove.size(); b++)
    {
        for (unsigned int c = 0; c < combo_marker.size(); c++)
        {
            if (ids_to_remove[b] == combo_marker[c])
            {
                int backup;
                backup = combo_marker[combo_marker.size()-1];
                combo_marker[combo_marker.size()-1] = combo_marker[c];
                combo_marker[c] = backup;
                combo_marker.pop_back();
                break;
            }
        }
    }
	

	CountCombos();

	current_combo_to_remove = combo_marker[0];
	is_still_removing_combos = true;
	combo_by_combo_timer.Reset();
}

void GameEngine::UpdateCounting()
{
	if (aux_timer.GetElapsedTime() > 0.25) //Wait for the animation FPS timer
	{
		for (unsigned int i = 0; i < combo_counter.size(); i ++) //Loop through all combos  
		{
			if (combo_counter[i].combo_id == current_combo_to_remove) //Double check the combo type to avoid same sprite_id combos confusion
			{
				if (combo_counter[i].amount > 0 )
				{
					int piece_type = combo_counter[i].sprite_id;

					if (!counting)
					{
						this->combo_title.SetupNewLabel(piece_type);
						counting = true;
						this->game_state = 4;
						this->audio.PlaySoundEffect(5);
						return;
					}
					gui->x_label.SetText("x");
					combo_string = GetMatchLabel(piece_type);
					gui->match_label.SetText(combo_string);					
					gui->match_points_info.SetText(this->game->ConvertIntToString(combo_points));
					gui->match_amount_info.SetText(this->game->ConvertIntToString(combo_count));

					if (piece_type <= 5) //Combos composed of normal chess pieces
					{
						combo_count++;
						gui->match_amount_info.SetText(this->game->ConvertIntToString(combo_count));
						this->temporary_match_points += this->game->GetPiecePoints(piece_type);
						combo_points += this->game->GetPiecePoints(piece_type);
						//gui->match_points_info.SetText(this->game->ConvertIntToString(combo_points));
						gui->match_points_info.SetText(this->game->ConvertIntToString(this->temporary_match_points));
						
						std::string temp;
						std::string one = gui->match_points_info.GetText();
						std::string two = " pts";
						temp = one + two;
						gui->match_points_info.SetText(temp);

						this->game->CalculatePieceScore(piece_type);

						this->gui->IncreaseFontSize();
					}
					else //Special combos of Chesster
					{
						//std::cout << "\nFound special combo of Id [" << piece_type << "]\n\n";
						if (combo_count == 0)
						{
							combo_count++;
							gui->match_amount_info.SetText(this->game->ConvertIntToString(combo_count));
							this->temporary_match_points += this->game->GetPiecePoints(piece_type);
							combo_points += this->game->GetPiecePoints(piece_type);
							//gui->match_points_info.SetText(this->game->ConvertIntToString(combo_points));
							gui->match_points_info.SetText(this->game->ConvertIntToString(this->temporary_match_points));

							std::string temp;
							std::string one = gui->match_points_info.GetText();
							std::string two = " pts";
							temp = one + two;
							gui->match_points_info.SetText(temp);

							this->game->CalculatePieceScore(piece_type);
							
							this->gui->IncreaseFontSize();
						}
					}
					combo_counter[i].amount--;
					//x_marker[combo_counter[i].ids[combo_counter[i].ids.size()-1]] = true;
					game_pieces[combo_counter[i].ids[combo_counter[i].ids.size()-1]]->StartDestructionAnimation();
					this->audio.PlaySoundEffect(2);
					
					this->gui->RetifyTextPositions();

					combo_counter[i].ids.pop_back();
					aux_timer.Reset();
				}
				else // Finished to count a single combo
				{
					this->temporary_match_points = 0;
					combo_count = 0;
					
					//this->game_state = 2;
					this->gui->SetupScoreUpdate(combo_points, 0, true);
					
					this->game_state = 25;
					last_combo_counted = current_combo_to_remove;
					combo_by_combo_timer.Reset();
					counting = false;
					return;
				}
			}
		}
	}
}

void GameEngine::RecursiveCheck(int piece_type, int i, int j, int marker)
{
	//Caution: Hardcore C++ ahead
	if (i<7)
	{
		if (combos[piece_type][i+1][j] != 0 &&  checked[i+1][j] == false )
		{
			checked[i+1][j] = true;
			if (combos[piece_type][i+1][j] != marker)
				ids_to_remove.push_back(combos[piece_type][i+1][j]);
			combos[piece_type][i+1][j] = marker;
			RecursiveCheck(piece_type, i+1, j, marker);
		}
	}
	if (i>0)
	{
		if (combos[piece_type][i-1][j] != 0 &&  checked[i-1][j] == false)
		{
			checked[i-1][j] = true;
			if (combos[piece_type][i-1][j] != marker)
				ids_to_remove.push_back(combos[piece_type][i-1][j]);
			combos[piece_type][i-1][j] = marker;
			RecursiveCheck(piece_type, i-1, j, marker);
		}
	}
	if (j>0)
	{
		if (combos[piece_type][i][j-1] != 0 &&  checked[i][j-1] == false)
		{
			checked[i][j-1] = true;
			if (combos[piece_type][i][j-1] != marker)
				ids_to_remove.push_back(combos[piece_type][i][j-1]);
			combos[piece_type][i][j-1] = marker;
			RecursiveCheck(piece_type, i, j-1, marker);
		}
	}
	if (j<7)
	{
		if (combos[piece_type][i][j+1] != 0  && checked[i][j+1] == false)
		{
			checked[i][j+1] = true;
			if (combos[piece_type][i][j+1] != marker)
				ids_to_remove.push_back(combos[piece_type][i][j+1]);
			combos[piece_type][i][j+1] = marker;
			RecursiveCheck(piece_type, i, j+1, marker);
		}
	}
}

void GameEngine::ShowRemovedPieces()
{
	for (int i = 0; i < 64; i++)
    {
        if (pieces[game_pieces[i]->px][game_pieces[i]->py] == -1)
        {
            game_pieces[i]->valid = true;
        }
    }
}