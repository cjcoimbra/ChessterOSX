#include "StdAfx.h"
#include "ResourceManager.h"


ResourceManager::ResourceManager()
{
    
	std::cout << "\nLoading assets......";
	
	this->xmarker_img.LoadFromFile("GFX/Pieces/x_spot.png");

	this->next_arrow_button.LoadFromFile("GFX/Tutorial/arrowbutton.png");
	this->next_arrow_button_over.LoadFromFile("GFX/Tutorial/arrowbutton_down.png");
	this->close_button.LoadFromFile("GFX/Tutorial/closebutton.png");
	this->close_button_over.LoadFromFile("GFX/Tutorial/closebutton_down.png");
	this->tutorial_sheet.LoadFromFile("GFX/Tutorial/SHEET_info.png");
	
	for(int i = 0; i < 11; i++)
	{
		std::string path = "GFX/Spikes/vertical/";
		std::string piece = "spike_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->vertical_spike[i].LoadFromFile(full_string);
		std::cout << "Loading asset [" << full_string << "]\n";
	}

	for(int i = 0; i < 11; i++)
	{
		std::string path = "GFX/Spikes/horizontal/";
		std::string piece = "spike_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->horizontal_spike[i].LoadFromFile(full_string);
		std::cout << "Loading asset [" << full_string << "]\n";
	}

	for(int i = 0; i < 17; i++)
	{
		std::string path = "GFX/Puzzle/solved/";
		std::string piece = "solved_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->puzzle_solved_label[i].LoadFromFile(full_string);
	}

	for(int i = 0; i < 17; i++)
	{
		std::string path = "GFX/Puzzle/failed/";
		std::string piece = "failed_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->puzzle_failure_label[i].LoadFromFile(full_string);
	}

	for(int i = 0; i < 30; i++)
	{
		std::string path = "GFX/Pieces/Spawn/";
		std::string piece = "appear_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->special_spawn[i].LoadFromFile(full_string);
	}
	
	
	for(int i = 0; i < 20; i++)
	{
		std::string path = "GFX/Pieces/Treasure/Get/";
		std::string piece = "treasure get_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->treasure_capture[i].LoadFromFile(full_string);
	}
	

	this->knight_img.LoadFromFile("GFX/Pieces/Knight/knight120final.png");
	for(int i = 0; i < 17; i++)
	{
		std::string path = "GFX/Pieces/Knight/";
		std::string piece = "knight_destruct_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->knight_destruction[i].LoadFromFile(full_string);
	}

    this->pawn_img.LoadFromFile("GFX/Pieces/Pawn/pawn120final.png");
	for(int i = 0; i < 17; i++)
	{
		std::string path = "GFX/Pieces/Pawn/";
		std::string piece = "pawn_destruct_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->pawn_destruction[i].LoadFromFile(full_string);
	}

    this->bishop_img.LoadFromFile("GFX/Pieces/Bishop/bishop120final.png");
	for(int i = 0; i < 17; i++)
	{
		std::string path = "GFX/Pieces/Bishop/";
		std::string bishop = "bishop_destruct_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + bishop + index + extension;
		this->bishop_destruction[i].LoadFromFile(full_string);
	}

    this->rook_img.LoadFromFile("GFX/Pieces/Rook/rook120final.png");
	for(int i = 0; i < 17; i++)
	{
		std::string path = "GFX/Pieces/Rook/";
		std::string piece = "rook_destruct_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->rook_destruction[i].LoadFromFile(full_string);
	}

    this->queen_img.LoadFromFile("GFX/Pieces/Queen/queen120final.png");
	for(int i = 0; i < 17; i++)
	{
		std::string path = "GFX/Pieces/Queen/";
		std::string piece = "queen_destruct_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->queen_destruction[i].LoadFromFile(full_string);
	}

    this->king_img.LoadFromFile("GFX/Pieces/King/king120final.png");
	for(int i = 0; i < 17; i++)
	{
		std::string path = "GFX/Pieces/King/";
		std::string piece = "king_destruct_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->king_destruction[i].LoadFromFile(full_string);
	}
	
	//Pawn Label
	for(int i = 0; i < 17; i++)
	{
		std::string path = "GFX/Labels/Pawn/";
		std::string piece = "pawn_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->pawn_label[i].LoadFromFile(full_string);
		std::cout << "Loading asset [" << full_string << "]\n";
	}

	//knight Label
	for(int i = 0; i < 17; i++)
	{
		std::string path = "GFX/Labels/Knight/";
		std::string piece = "knight_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->knight_label[i].LoadFromFile(full_string);
		std::cout << "Loading asset [" << full_string << "]\n";
	}

	//Bishop Label
	for(int i = 0; i < 17; i++)
	{
		std::string path = "GFX/Labels/Bishop/";
		std::string piece = "bishop_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->bishop_label[i].LoadFromFile(full_string);
		std::cout << "Loading asset [" << full_string << "]\n";
	}

	//Rook Label
	for(int i = 0; i < 17; i++)
	{
		std::string path = "GFX/Labels/Rook/";
		std::string piece = "rook_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->rook_label[i].LoadFromFile(full_string);
		std::cout << "Loading asset [" << full_string << "]\n";
	}

	//king Label
	for(int i = 0; i < 17; i++)
	{
		std::string path = "GFX/Labels/King/";
		std::string piece = "king_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->king_label[i].LoadFromFile(full_string);
		std::cout << "Loading asset [" << full_string << "]\n";
	}

	//Queen Label
	for(int i = 0; i < 17; i++)
	{
		std::string path = "GFX/Labels/Queen/";
		std::string piece = "queen_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->queen_label[i].LoadFromFile(full_string);
		std::cout << "Loading asset [" << full_string << "]\n";
	}

	//Queens Castle Label
	for(int i = 0; i < 17; i++)
	{
		std::string path = "GFX/Labels/Queens_Castle/";
		std::string piece = "queenscastle_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->queens_castle_label[i].LoadFromFile(full_string);
		std::cout << "Loading asset [" << full_string << "]\n";
	}

	//Queens Confession Label
	for(int i = 0; i < 17; i++)
	{
		std::string path = "GFX/Labels/Queens_Confession/";
		std::string piece = "queensconfession_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->queens_confession_label[i].LoadFromFile(full_string);
		std::cout << "Loading asset [" << full_string << "]\n";
	}

	//Queens Coronation Label
	for(int i = 0; i < 17; i++)
	{
		std::string path = "GFX/Labels/Queens_Coronation/";
		std::string piece = "queenscoronation_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->queens_coronation_label[i].LoadFromFile(full_string);
		std::cout << "Loading asset [" << full_string << "]\n";
	}

	//Queens Crusade Label
	for(int i = 0; i < 17; i++)
	{
		std::string path = "GFX/Labels/Queens_Crusade/";
		std::string piece = "queenscrusade_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->queens_crusade_label[i].LoadFromFile(full_string);
		std::cout << "Loading asset [" << full_string << "]\n";
	}

	//Queens Guard Label
	for(int i = 0; i < 17; i++)
	{
		std::string path = "GFX/Labels/Queens_Guard/";
		std::string piece = "queensguard_000";
		std::string index;
		std::string extension = ".png";
		if (i < 10)
		{
			std::stringstream st;
			st << i;
			index = "0" + st.str();
		}
		else
		{
			std::stringstream st;
			st << i;
			index = st.str();
		}
		std::string full_string = path + piece + index + extension;
		this->queens_guard_label[i].LoadFromFile(full_string);
		std::cout << "Loading asset [" << full_string << "]\n";
	}
	


	this->block_c_img.LoadFromFile("GFX/Pieces/Block/block_120.png");
    
	this->game_board_img.LoadFromFile("GFX/Other/dungeon_board_120x8.png");

	//this->game_board_alpha_img.LoadFromFile("GFX/Other/dungeon_alpha_layer.png");
	
	//Test
	//this->title_screen_img.LoadFromFile("GFX/Backgrounds/title.png");
	//this->test_background_img.LoadFromFile("GFX/Backgrounds/Dungeon.png");

	this->moves_img.LoadFromFile("GFX/Other/movebanner.png");

	this->turns_img.LoadFromFile("GFX/Other/turnsbanner.png");

	//this->info_frame_img.LoadFromFile("GFX/Other/info_frame.png");
	this->info_frame_img.LoadFromFile("GFX/Other/scorebox.png");

	this->piece_selector_img.LoadFromFile("GFX/Other/selector.png");
	
	this->bluecrest.LoadFromFile("GFX/Other/bluecrest.png");

	this->puzzle_background.LoadFromFile("GFX/Puzzle/puzzle_background.png");
	
	this->puzzle_list_lock.LoadFromFile("GFX/Puzzle/puzzle_block.png");

	int random_loading_id = sf::Randomizer::Random(0, 5);
	if (random_loading_id == 0)
		this->loading_indicator.LoadFromFile("GFX/Loading/bishopcolor.png");
	else if (random_loading_id == 1)
		this->loading_indicator.LoadFromFile("GFX/Loading/kingcolor.png");
	else if (random_loading_id == 2)
		this->loading_indicator.LoadFromFile("GFX/Loading/knightcolor.png");
	else if (random_loading_id == 3)
		this->loading_indicator.LoadFromFile("GFX/Loading/pawncolor.png");
	else if (random_loading_id == 4)
		this->loading_indicator.LoadFromFile("GFX/Loading/queencolor.png");
	else if (random_loading_id == 5)
		this->loading_indicator.LoadFromFile("GFX/Loading/rookcolor.png");

	this->mouse_cursor.LoadFromFile("GFX/Other/cursor.png");

	//this->board_frame_img.LoadFromFile("GFX/Other/frame.png");

	this->multiply.LoadFromFile("GFX/Other/multiplyX.png");

	this->horizontal_spike_img.LoadFromFile("GFX/Other/hspike.png");
	this->vertical_spike_img.LoadFromFile("GFX/Other/vspike.png");
	this->next_treasure_banner.LoadFromFile("GFX/Other/nexttreasurebanner.png");

	this->play_button_normal.LoadFromFile("GFX/Buttons/playbutton.png");
	this->play_button_focus.LoadFromFile("GFX/Buttons/playbutton_focus.png");
	this->tutorial_button_normal.LoadFromFile("GFX/Buttons/tutorialbutton.png");
	this->tutorial_button_focus.LoadFromFile("GFX/Buttons/tutorialbutton_focus.png");
	this->puzzle_button_normal.LoadFromFile("GFX/Buttons/puzzlebutton.png");
	this->puzzle_button_focus.LoadFromFile("GFX/Buttons/puzzlebutton_focus.png");
	this->scores_button_normal.LoadFromFile("GFX/Buttons/scorebutton.png");
	this->scores_button_focus.LoadFromFile("GFX/Buttons/scorebutton_focus.png");
	this->credits_button_normal.LoadFromFile("GFX/Buttons/creditbutton.png");
	this->credits_button_focus.LoadFromFile("GFX/Buttons/creditbutton_focus.png");

	this->quit_button_focus.LoadFromFile("GFX/Buttons/quitbutton_focus.png");
	this->quit_button_normal.LoadFromFile("GFX/Buttons/quitbutton.png");

	this->new_button_focus.LoadFromFile("GFX/Buttons/newbutton_focus.png");
	this->new_button_normal.LoadFromFile("GFX/Buttons/newbutton.png");

	this->resume_button_focus.LoadFromFile("GFX/Buttons/resumebutton_focus.png");
	this->resume_button_normal.LoadFromFile("GFX/Buttons/resumebutton.png");

	this->back_button_focus.LoadFromFile("GFX/Buttons/backbutton_focus.png");
	this->back_button_normal.LoadFromFile("GFX/Buttons/backbutton.png");


	this->combos_button_off.LoadFromFile("GFX/Buttons/BUTTON_combos.png");
	this->combos_button_on.LoadFromFile("GFX/Buttons/BUTTON_combos_hold.png");
	this->combos_button_focus.LoadFromFile("GFX/Buttons/BUTTON_combos_focus.png");
	

	this->movement_button_off.LoadFromFile("GFX/Buttons/BUTTON_movement.png");
	this->movement_button_on.LoadFromFile("GFX/Buttons/BUTTON_movement_hold.png");
	this->movement_button_focus.LoadFromFile("GFX/Buttons/BUTTON_movement_focus.png");


	this->treasure_button_off.LoadFromFile("GFX/Buttons/BUTTON_treasure.png");
	this->treasure_button_on.LoadFromFile("GFX/Buttons/BUTTON_treasure_hold.png");
	this->treasure_button_focus.LoadFromFile("GFX/Buttons/BUTTON_treasure_focus.png");


	
	this->combos_board.LoadFromFile("GFX/Other/TEXTBOARD_combos.png");
	this->movement_board.LoadFromFile("GFX/Other/TEXTBOARD_movement.png");
	this->treasure_board.LoadFromFile("GFX/Other/TEXTBOARD_treasure.png");


	this->demand_animation[0].LoadFromFile("GFX/Demand/demand swords_00000.png");
	this->demand_animation[1].LoadFromFile("GFX/Demand/demand swords_00001.png");
	this->demand_animation[2].LoadFromFile("GFX/Demand/demand swords_00002.png");
	this->demand_animation[3].LoadFromFile("GFX/Demand/demand swords_00003.png");
	this->demand_animation[4].LoadFromFile("GFX/Demand/demand swords_00004.png");
	this->demand_animation[5].LoadFromFile("GFX/Demand/demand swords_00005.png");
	this->demand_animation[6].LoadFromFile("GFX/Demand/demand swords_00006.png");
	this->demand_animation[7].LoadFromFile("GFX/Demand/demand swords_00007.png");
	this->demand_animation[8].LoadFromFile("GFX/Demand/demand swords_00008.png");
	this->demand_animation[9].LoadFromFile("GFX/Demand/demand swords_00009.png");
	this->demand_animation[10].LoadFromFile("GFX/Demand/demand swords_00010.png");
	this->demand_animation[11].LoadFromFile("GFX/Demand/demand swords_00011.png");
	this->demand_animation[12].LoadFromFile("GFX/Demand/demand swords_00012.png");
	this->demand_animation[13].LoadFromFile("GFX/Demand/demand swords_00013.png");
	this->demand_animation[14].LoadFromFile("GFX/Demand/demand swords_00014.png");
	this->demand_animation[15].LoadFromFile("GFX/Demand/demand swords_00015.png");
	this->demand_animation[16].LoadFromFile("GFX/Demand/demand swords_00016.png");
	this->demand_animation[17].LoadFromFile("GFX/Demand/demand swords_00017.png");
	this->demand_animation[18].LoadFromFile("GFX/Demand/demand swords_00018.png");
	this->demand_animation[19].LoadFromFile("GFX/Demand/demand swords_00019.png");
	this->demand_animation[20].LoadFromFile("GFX/Demand/demand swords_00020.png");
	this->demand_animation[21].LoadFromFile("GFX/Demand/demand swords_00021.png");
	this->demand_animation[22].LoadFromFile("GFX/Demand/demand swords_00022.png");


	this->positive_score_particles[0].LoadFromFile("GFX/ScoreEffects/score positive_00000.png");
	this->positive_score_particles[1].LoadFromFile("GFX/ScoreEffects/score positive_00001.png");
	this->positive_score_particles[2].LoadFromFile("GFX/ScoreEffects/score positive_00002.png");
	this->positive_score_particles[3].LoadFromFile("GFX/ScoreEffects/score positive_00003.png");
	this->positive_score_particles[4].LoadFromFile("GFX/ScoreEffects/score positive_00004.png");
	this->positive_score_particles[5].LoadFromFile("GFX/ScoreEffects/score positive_00005.png");
	this->positive_score_particles[6].LoadFromFile("GFX/ScoreEffects/score positive_00006.png");
	this->positive_score_particles[7].LoadFromFile("GFX/ScoreEffects/score positive_00007.png");
	this->positive_score_particles[8].LoadFromFile("GFX/ScoreEffects/score positive_00008.png");
	this->positive_score_particles[9].LoadFromFile("GFX/ScoreEffects/score positive_00009.png");
	this->positive_score_particles[10].LoadFromFile("GFX/ScoreEffects/score positive_00010.png");
	this->positive_score_particles[11].LoadFromFile("GFX/ScoreEffects/score positive_00011.png");
	this->positive_score_particles[12].LoadFromFile("GFX/ScoreEffects/score positive_00012.png");
	this->positive_score_particles[13].LoadFromFile("GFX/ScoreEffects/score positive_00013.png");
	this->positive_score_particles[14].LoadFromFile("GFX/ScoreEffects/score positive_00014.png");
	this->positive_score_particles[15].LoadFromFile("GFX/ScoreEffects/score positive_00015.png");
	this->positive_score_particles[16].LoadFromFile("GFX/ScoreEffects/score positive_00016.png");
	this->positive_score_particles[17].LoadFromFile("GFX/ScoreEffects/score positive_00017.png");
	this->positive_score_particles[18].LoadFromFile("GFX/ScoreEffects/score positive_00018.png");
	this->positive_score_particles[19].LoadFromFile("GFX/ScoreEffects/score positive_00019.png");
	this->positive_score_particles[20].LoadFromFile("GFX/ScoreEffects/score positive_00020.png");
	this->positive_score_particles[21].LoadFromFile("GFX/ScoreEffects/score positive_00021.png");
	this->positive_score_particles[22].LoadFromFile("GFX/ScoreEffects/score positive_00022.png");
	this->positive_score_particles[23].LoadFromFile("GFX/ScoreEffects/score positive_00023.png");
	this->positive_score_particles[24].LoadFromFile("GFX/ScoreEffects/score positive_00024.png");

	this->negative_score_particles[0].LoadFromFile("GFX/ScoreEffects/score negative_00000.png");
	this->negative_score_particles[1].LoadFromFile("GFX/ScoreEffects/score negative_00001.png");
	this->negative_score_particles[2].LoadFromFile("GFX/ScoreEffects/score negative_00002.png");
	this->negative_score_particles[3].LoadFromFile("GFX/ScoreEffects/score negative_00003.png");
	this->negative_score_particles[4].LoadFromFile("GFX/ScoreEffects/score negative_00004.png");
	this->negative_score_particles[5].LoadFromFile("GFX/ScoreEffects/score negative_00005.png");
	this->negative_score_particles[6].LoadFromFile("GFX/ScoreEffects/score negative_00006.png");
	this->negative_score_particles[7].LoadFromFile("GFX/ScoreEffects/score negative_00007.png");
	this->negative_score_particles[8].LoadFromFile("GFX/ScoreEffects/score negative_00008.png");
	this->negative_score_particles[9].LoadFromFile("GFX/ScoreEffects/score negative_00009.png");
	this->negative_score_particles[10].LoadFromFile("GFX/ScoreEffects/score negative_00010.png");
	this->negative_score_particles[11].LoadFromFile("GFX/ScoreEffects/score negative_00011.png");
	this->negative_score_particles[12].LoadFromFile("GFX/ScoreEffects/score negative_00012.png");
	this->negative_score_particles[13].LoadFromFile("GFX/ScoreEffects/score negative_00013.png");
	this->negative_score_particles[14].LoadFromFile("GFX/ScoreEffects/score negative_00014.png");
	this->negative_score_particles[15].LoadFromFile("GFX/ScoreEffects/score negative_00015.png");
	this->negative_score_particles[16].LoadFromFile("GFX/ScoreEffects/score negative_00016.png");
	this->negative_score_particles[17].LoadFromFile("GFX/ScoreEffects/score negative_00017.png");
	this->negative_score_particles[18].LoadFromFile("GFX/ScoreEffects/score negative_00018.png");
	this->negative_score_particles[19].LoadFromFile("GFX/ScoreEffects/score negative_00019.png");
	this->negative_score_particles[20].LoadFromFile("GFX/ScoreEffects/score negative_00020.png");

	
	std::cout << " done! \n\n";
}

void ResourceManager::UnloadUnusedAssets(int sceneId)
{
	if (sceneId == 1)
	{
		this->play_button_normal.LoadFromFile("GFX/Other/eraser.png");
		this->play_button_focus.LoadFromFile("GFX/Other/eraser.png");
		this->tutorial_button_normal.LoadFromFile("GFX/Other/eraser.png");
		this->tutorial_button_focus.LoadFromFile("GFX/Other/eraser.png");
		this->puzzle_button_normal.LoadFromFile("GFX/Other/eraser.png");
		this->puzzle_button_focus.LoadFromFile("GFX/Other/eraser.png");
		this->scores_button_normal.LoadFromFile("GFX/Other/eraser.png");
		this->scores_button_focus.LoadFromFile("GFX/Other/eraser.png");
		this->credits_button_normal.LoadFromFile("GFX/Other/eraser.png");
		this->credits_button_focus.LoadFromFile("GFX/Other/eraser.png");

		this->quit_button_focus.LoadFromFile("GFX/Other/eraser.png");
		this->quit_button_normal.LoadFromFile("GFX/Other/eraser.png");

		this->new_button_focus.LoadFromFile("GFX/Other/eraser.png");
		this->new_button_normal.LoadFromFile("GFX/Other/eraser.png");

		this->resume_button_focus.LoadFromFile("GFX/Other/eraser.png");
		this->resume_button_normal.LoadFromFile("GFX/Other/eraser.png");

		this->back_button_focus.LoadFromFile("GFX/Other/eraser.png");
		this->back_button_normal.LoadFromFile("GFX/Other/eraser.png");

		for(int i = 0; i < 17; i++)
		{
			this->puzzle_failure_label[i].LoadFromFile("GFX/Other/eraser.png");
			this->puzzle_solved_label[i].LoadFromFile("GFX/Other/eraser.png");
		}

	}
}

void ResourceManager::RefreshBlockFrames()
{
	switch (this->current_level)
	{
		case 1:
			for(int i = 0; i < 20; i++)
			{
				std::string path = "GFX/Pieces/Block/Level_01/";
				std::string piece = "block_destruct_000";
				std::string index;
				std::string extension = ".png";
				if (i < 10)
				{
					std::stringstream st;
					st << i;
					index = "0" + st.str();
				}
				else
				{
					std::stringstream st;
					st << i;
					index = st.str();
				}
				std::string full_string = path + piece + index + extension;
				this->block_destruction[i].LoadFromFile(full_string);
			}
			break;

		case 2:
			for(int i = 0; i < 20; i++)
			{
				std::string path = "GFX/Pieces/Block/Level_02/";
				std::string piece = "castlewalls_blockbust_000";
				std::string index;
				std::string extension = ".png";
				if (i < 10)
				{
					std::stringstream st;
					st << i;
					index = "0" + st.str();
				}
				else
				{
					std::stringstream st;
					st << i;
					index = st.str();
				}
				std::string full_string = path + piece + index + extension;
				this->block_destruction[i].LoadFromFile(full_string);
			}
			break;
		
		case 3:
			for(int i = 0; i < 20; i++)
			{
				std::string path = "GFX/Pieces/Block/Level_03/";
				std::string piece = "courtyard_blockbust_000";
				std::string index;
				std::string extension = ".png";
				if (i < 10)
				{
					std::stringstream st;
					st << i;
					index = "0" + st.str();
				}
				else
				{
					std::stringstream st;
					st << i;
					index = st.str();
				}
				std::string full_string = path + piece + index + extension;
				this->block_destruction[i].LoadFromFile(full_string);
			}
			break;
	}
}

const sf::Image& ResourceManager::LoadDemandAnimation(int resourceId)
{
	return this->demand_animation[resourceId];
}

const sf::Image& ResourceManager::LoadPositiveScoreAnimation(int resourceId)
{
	return this->positive_score_particles[resourceId];
}

const sf::Image& ResourceManager::LoadNegativeScoreAnimation(int resourceId)
{
	return this->negative_score_particles[resourceId];
}

const sf::Image& ResourceManager::OnDemandLoadBackground(int resourceId)
{
	switch (resourceId)
	{
		case 0:
			this->generic_bg.LoadFromFile("GFX/Backgrounds/title.png");
			return this->generic_bg; 
        break;

		case 1:
			this->generic_bg.LoadFromFile("GFX/Backgrounds/Dungeon.png");
			return this->generic_bg;  
        break;

		case 2:
			this->generic_bg.LoadFromFile("GFX/Backgrounds/Castlewalls.png");
			return this->generic_bg;  
        break;

		case 3:
			this->generic_bg.LoadFromFile("GFX/Backgrounds/Courtyard.png");
			return this->generic_bg;  
        break;

		case 10: // Puzzle Mode
			return puzzle_background;
		break;
	}
}

const sf::Image& ResourceManager::OnDemandLoadFrame(int resourceId)
{
	switch (resourceId)
	{
		case 1:
			this->board_frame_img.LoadFromFile("GFX/Other/Level1/frame.png");
			return this->board_frame_img;  
        break;

		case 2:
			this->board_frame_img.LoadFromFile("GFX/Other/Level2/frame.png");
			return this->board_frame_img;  
        break;

		case 3:
			this->board_frame_img.LoadFromFile("GFX/Other/Level3/frame.png");
			return this->board_frame_img;  
        break;

		case 10://Puzzle Mode
			this->board_frame_img.LoadFromFile("GFX/Other/Level1/frame.png");
			return this->board_frame_img;  
        break;
	}
}

const sf::Image& ResourceManager::OnDemandLoadBoardAlpha(int resourceId)
{
	switch (resourceId)
	{
		case 1:
			this->game_board_alpha_img.LoadFromFile("GFX/Other/Level1/dungeon_alpha_layer.png");
			return this->game_board_alpha_img;  
        break;

		case 2:
			this->game_board_alpha_img.LoadFromFile("GFX/Other/Level2/castlewalls_alpha_layer.png");
			return this->game_board_alpha_img;  
        break;

		case 3:
			this->game_board_alpha_img.LoadFromFile("GFX/Other/Level3/courtyard_alpha_layer.png");
			return this->game_board_alpha_img;  
        break;

		case 10: //Puzzle Game Mode
			this->game_board_alpha_img.LoadFromFile("GFX/Other/Level1/dungeon_alpha_layer.png");
			return this->game_board_alpha_img;  
        break;
	}
}

const sf::Image& ResourceManager::OnDemandLoadForBoards(int resourceId)
{
	switch (resourceId)
	{
		case 0:
			this->generic_textboard.LoadFromFile("GFX/Other/TEXTBOARD_movement.png");
			return this->generic_textboard; 
        break;

		case 1:
			this->generic_textboard.LoadFromFile("GFX/Other/TEXTBOARD_combos.png");
			return this->generic_textboard;  
        break;

		case 2:
			this->generic_textboard.LoadFromFile("GFX/Other/TEXTBOARD_treasure.png");
			return this->generic_textboard;  
        break;
	}
}

const sf::Image& ResourceManager::OnDemandLoadTreasures(int index)
{
	/*
	this->treasure[0].LoadFromFile("GFX/Pieces/Treasure/PIECE_dungeoncoin.png");
	this->treasure[1].LoadFromFile("GFX/Pieces/Treasure/PIECE_dungeonring.png");
	this->treasure[2].LoadFromFile("GFX/Pieces/Treasure/PIECE_dungeonemerald.png");
	this->treasure[3].LoadFromFile("GFX/Pieces/Treasure/PIECE_dungeonkey.png");

	this->treasure_shadow[0].LoadFromFile("GFX/Other/PIECE_dungeoncoin_shadow.png");
	this->treasure_shadow[1].LoadFromFile("GFX/Other/PIECE_dungeonring_shadow.png");
	this->treasure_shadow[2].LoadFromFile("GFX/Other/PIECE_dungeonemerald_shadow.png");
	this->treasure_shadow[3].LoadFromFile("GFX/Other/PIECE_dungeonkey_shadow.png");
	*/
	switch (this->current_level)
	{
		case 1:
			if (index == 0)
			{
				this->treasure[0].LoadFromFile("GFX/Pieces/Treasure/PIECE_dungeoncoin.png");
				return  this->treasure[0];
			}
			else if (index == 1)
			{
				this->treasure[1].LoadFromFile("GFX/Pieces/Treasure/PIECE_dungeonring.png");
				return  this->treasure[1];
			}
			else if (index == 2)
			{
				this->treasure[2].LoadFromFile("GFX/Pieces/Treasure/PIECE_dungeonemerald.png");
				return  this->treasure[2];
			}
			else if (index == 3)
			{
				this->treasure[3].LoadFromFile("GFX/Pieces/Treasure/PIECE_dungeonkey.png");
				return  this->treasure[3];
			}
			else if (index == 4)
			{
				this->treasure_shadow[0].LoadFromFile("GFX/Other/PIECE_dungeoncoin_shadow.png");
				return  this->treasure_shadow[0];
			}
			else if (index == 5)
			{
				this->treasure_shadow[1].LoadFromFile("GFX/Other/PIECE_dungeonring_shadow.png");
				return  this->treasure_shadow[1];
			}
			else if (index == 6)
			{
				this->treasure_shadow[2].LoadFromFile("GFX/Other/PIECE_dungeonemerald_shadow.png");
				return  this->treasure_shadow[2];
			}
			else if (index == 7)
			{
				this->treasure_shadow[3].LoadFromFile("GFX/Other/PIECE_dungeonkey_shadow.png");
				return  this->treasure_shadow[3];
			}

        break;

		case 2:
			if (index == 0)
			{
				this->treasure[0].LoadFromFile("GFX/Other/Level2/treasure0.png");
				return  this->treasure[0];
			}
			else if (index == 1)
			{
				this->treasure[1].LoadFromFile("GFX/Other/Level2/treasure1.png");
				return  this->treasure[1];
			}
			else if (index == 2)
			{
				this->treasure[2].LoadFromFile("GFX/Other/Level2/treasure2.png");
				return  this->treasure[2];
			}
			else if (index == 3)
			{
				this->treasure[3].LoadFromFile("GFX/Other/Level2/treasure3.png");
				return  this->treasure[3];
			}
			else if (index == 4)
			{
				this->treasure_shadow[0].LoadFromFile("GFX/Other/Level2/shadow0.png");
				return  this->treasure_shadow[0];
			}
			else if (index == 5)
			{
				this->treasure_shadow[1].LoadFromFile("GFX/Other/Level2/shadow1.png");
				return  this->treasure_shadow[1];
			}
			else if (index == 6)
			{
				this->treasure_shadow[2].LoadFromFile("GFX/Other/Level2/shadow2.png");
				return  this->treasure_shadow[2];
			}
			else if (index == 7)
			{
				this->treasure_shadow[3].LoadFromFile("GFX/Other/Level2/shadow3.png");
				return  this->treasure_shadow[3];
			}

        break;
			
		case 3:
			if (index == 0)
			{
				this->treasure[0].LoadFromFile("GFX/Other/Level3/treasure0.png");
				return  this->treasure[0];
			}
			else if (index == 1)
			{
				this->treasure[1].LoadFromFile("GFX/Other/Level3/treasure1.png");
				return  this->treasure[1];
			}
			else if (index == 2)
			{
				this->treasure[2].LoadFromFile("GFX/Other/Level3/treasure2.png");
				return  this->treasure[2];
			}
			else if (index == 3)
			{
				this->treasure[3].LoadFromFile("GFX/Other/Level3/treasure3.png");
				return  this->treasure[3];
			}
			else if (index == 4)
			{
				this->treasure_shadow[0].LoadFromFile("GFX/Other/Level3/shadow0.png");
				return  this->treasure_shadow[0];
			}
			else if (index == 5)
			{
				this->treasure_shadow[1].LoadFromFile("GFX/Other/Level3/shadow1.png");
				return  this->treasure_shadow[1];
			}
			else if (index == 6)
			{
				this->treasure_shadow[2].LoadFromFile("GFX/Other/Level3/shadow2.png");
				return  this->treasure_shadow[2];
			}
			else if (index == 7)
			{
				this->treasure_shadow[3].LoadFromFile("GFX/Other/Level3/shadow3.png");
				return  this->treasure_shadow[3];
			}   
        break;
	}
}
/*
const sf::Image& ResourceManager::OnDemandLoadForTutorialView(int resourceId)
{
	//this->tutorial_memory_saver.LoadFromFile("GFX/null.png");

	switch (resourceId)
	{
		case 0:
			this->tutorial_memory_saver.LoadFromFile("GFX/Tutorial/tutorial_frame01.png");
			return this->tutorial_memory_saver; 
        break;
		case 1:
			this->tutorial_memory_saver.LoadFromFile("GFX/Tutorial/tutorial_frame02.png");
			return this->tutorial_memory_saver;  
        break;
		case 2:
			this->tutorial_memory_saver.LoadFromFile("GFX/Tutorial/tutorial_frame03.png");
			return this->tutorial_memory_saver;  
        break;
		case 3:
			this->tutorial_memory_saver.LoadFromFile("GFX/Tutorial/tutorial_frame04.png");
			return this->tutorial_memory_saver;  
        break;
		case 4:
			this->tutorial_memory_saver.LoadFromFile("GFX/Tutorial/tutorial_frame05.png");
			return this->tutorial_memory_saver; 
        break;
		case 5:
			this->tutorial_memory_saver.LoadFromFile("GFX/Tutorial/tutorial_frame06.png");
			return this->tutorial_memory_saver;  
        break;
		case 6:
			this->tutorial_memory_saver.LoadFromFile("GFX/Tutorial/tutorial_frame07.png");
			return this->tutorial_memory_saver;  
        break;
		case 7:
			this->tutorial_memory_saver.LoadFromFile("GFX/Tutorial/tutorial_frame08.png");
			return this->tutorial_memory_saver;  
        break;
		case 8:
			this->tutorial_memory_saver.LoadFromFile("GFX/Tutorial/tutorial_frame09.png");
			return this->tutorial_memory_saver;  
        break;
		case 9:
			this->tutorial_memory_saver.LoadFromFile("GFX/Tutorial/tutorial_frame10.png");
			return this->tutorial_memory_saver;  
        break;
	}
}
*/
const sf::Image& ResourceManager::GetImageResource(int resourceId)
{
	//int bk;

    switch(resourceId)
    {
        case 0:
			return pawn_img;
        break;

		case 1:
			return knight_img;
        break;

		case 2:
			return rook_img;
        break;

		case 3:
            return bishop_img;
        break;

        case 4:
			return king_img;
        break;

        case 5:
				return queen_img;
		break;

		//Block loading switches accordingly to the current level
		case 6:

			if (this->current_level == 1)
				block_c_img.LoadFromFile("GFX/Other/Level1/block_120.png");
			else if (this->current_level == 2)
				block_c_img.LoadFromFile("GFX/Other/Level2/block_120.png");
			else if (this->current_level == 3)
				block_c_img.LoadFromFile("GFX/Other/Level3/block_120.png");
			return block_c_img;
        
		break;
		
		case 7:
			return xmarker_img;
        break;

        case 10: //test background
			//title_screen_img.LoadFromFile("GFX/Backgrounds/dungeon.png");
			//return title_screen_img;
            return test_background_img;
        break;
        
		case 11: // Title screen

            return title_screen_img;
		break;
		
		case 12:
			return board_frame_img;
			break;

		case 13: //Dungeon Game Board
			return game_board_img;
			break;

		case 14: //Dungeon Game Board Alpha layer
			return game_board_alpha_img;
			break;
			
		case 15:
			return vertical_spike_img; 
        break;

		case 16:
			return horizontal_spike_img; 
        break;

		case 17:
			return moves_img; 
        break;

		case 18:
			return info_frame_img; 
        break;

		case 19:
			return turns_img; 
        break;

		case 20:
			return piece_selector_img; 
        break;

		case 21:
			return play_button_normal; 
        break;

		case 22:
			return play_button_focus; 
        break;

		case 23:
			return tutorial_button_normal; 
        break;

		case 24:
			return tutorial_button_focus; 
        break;

		case 25:
			return puzzle_button_normal; 
        break;

		case 26:
			return puzzle_button_focus; 
        break;

		case 27:
			return scores_button_normal; 
        break;

		case 28:
			return scores_button_focus; 
        break;

		case 29:
			return credits_button_normal; 
        break;

		case 30:
			return credits_button_focus; 
        break;

		case 31:
			return combos_button_off; 
        break;

		case 32:
			return combos_button_on; 
        break;

		case 33:
			return combos_button_focus; 
        break;

		case 34:
			return movement_button_off; 
        break;

		case 35:
			return movement_button_on; 
        break;

		case 36:
			return movement_button_focus; 
        break;

		case 37:
			return treasure_button_off; 
        break;
		
		case 38:
			return treasure_button_on; 
        break;

		case 39:
			return treasure_button_focus; 
        break;

		case 40:
			return combos_board; 
        break;

		case 41:
			return movement_board; 
        break;

		case 42:
			return treasure_board; 
        break;

		case 43:
			return bluecrest; 
        break;
		/*
		case 50:
			return tutorial_images[0]; 
        break;
		case 51:
			return tutorial_images[1]; 
        break;
		case 52:
			return tutorial_images[2]; 
        break;
		case 53:
			return tutorial_images[3]; 
        break;
		case 54:
			return tutorial_images[4]; 
        break;
		case 55:
			return tutorial_images[5]; 
        break;
		case 56:
			return tutorial_images[6]; 
        break;
		case 57:
			return tutorial_images[7]; 
        break;
		case 58:
			return tutorial_images[8]; 
        break;
		case 59:
			return tutorial_images[9]; 
        break;
		*/
		case 60:
			return mouse_cursor; 
        break;
		
		case 61:
			return treasure[0]; 
        break;

		case 62:
			return treasure[1]; 
        break;

		case 63:
			return treasure[2]; 
        break;

		case 64:
			return treasure[3]; 
        break;

		case 65:
			return treasure_shadow[0]; 
        break;

		case 66:
			return treasure_shadow[1]; 
        break;

		case 67:
			return treasure_shadow[2]; 
        break;

		case 68:
			return treasure_shadow[3]; 
        break;

		case 69:
			return quit_button_normal; 
        break;

		case 70:
			return quit_button_focus; 
        break;

		case 71:
			return multiply; 
        break;

		case 72:
			return next_treasure_banner;
		break;

		case 73:
			return loading_indicator;
		break;

		case 74:
			return puzzle_background;
		break;

		case 75:
			return puzzle_list_lock;
		break;

		case 76:
			return new_button_normal;
		break;
		case 77:
			return new_button_focus;
		break;

		case 78:
			return resume_button_normal;
		break;
		case 79:
			return resume_button_focus;
		break;

		case 80:
			return back_button_normal;
		break;
		case 81:
			return back_button_focus;
		break;

		case 82:
			return close_button;
		break;

		case 83:
			return close_button_over;
		break;

		case 84:
			return next_arrow_button;
		break;

		case 85:
			return next_arrow_button_over;
		break;

		case 86:
			return tutorial_sheet;
		break;

		
		//Bishop Animation
		case 100:
			return bishop_destruction[0]; 
        break;
		case 101:
			return bishop_destruction[1]; 
        break;
		case 102:
			return bishop_destruction[2]; 
        break;
		case 103:
			return bishop_destruction[3]; 
        break;
		case 104:
			return bishop_destruction[4]; 
        break;
		case 105:
			return bishop_destruction[5]; 
        break;
		case 106:
			return bishop_destruction[6]; 
        break;
		case 107:
			return bishop_destruction[7]; 
        break;
		case 108:
			return bishop_destruction[8]; 
        break;
		case 109:
			return bishop_destruction[9]; 
        break;
		case 110:
			return bishop_destruction[10]; 
        break;
		case 111:
			return bishop_destruction[11]; 
        break;
		case 112:
			return bishop_destruction[12]; 
        break;
		case 113:
			return bishop_destruction[13]; 
        break;
		case 114:
			return bishop_destruction[14]; 
        break;
		case 115:
			return bishop_destruction[15]; 
        break;
		case 116:
			return bishop_destruction[16]; 
        break;

		//Pawn animation
		case 200:
			return pawn_destruction[0]; 
        break;
		case 201:
			return pawn_destruction[1]; 
        break;
		case 202:
			return pawn_destruction[2]; 
        break;
		case 203:
			return pawn_destruction[3]; 
        break;
		case 204:
			return pawn_destruction[4]; 
        break;
		case 205:
			return pawn_destruction[5]; 
        break;
		case 206:
			return pawn_destruction[6]; 
        break;
		case 207:
			return pawn_destruction[7]; 
        break;
		case 208:
			return pawn_destruction[8]; 
        break;
		case 209:
			return pawn_destruction[9]; 
        break;
		case 210:
			return pawn_destruction[10]; 
        break;
		case 211:
			return pawn_destruction[11]; 
        break;
		case 212:
			return pawn_destruction[12]; 
        break;
		case 213:
			return pawn_destruction[13]; 
        break;
		case 214:
			return pawn_destruction[14]; 
        break;
		case 215:
			return pawn_destruction[15]; 
        break;
		case 216:
			return pawn_destruction[16]; 
        break;

		//Knight
		case 300:
			return knight_destruction[0]; 
        break;
		case 301:
			return knight_destruction[1]; 
        break;
		case 302:
			return knight_destruction[2]; 
        break;
		case 303:
			return knight_destruction[3]; 
        break;
		case 304:
			return knight_destruction[4]; 
        break;
		case 305:
			return knight_destruction[5]; 
        break;
		case 306:
			return knight_destruction[6]; 
        break;
		case 307:
			return knight_destruction[7]; 
        break;
		case 308:
			return knight_destruction[8]; 
        break;
		case 309:
			return knight_destruction[9]; 
        break;
		case 310:
			return knight_destruction[10]; 
        break;
		case 311:
			return knight_destruction[11]; 
        break;
		case 312:
			return knight_destruction[12]; 
        break;
		case 313:
			return knight_destruction[13]; 
        break;
		case 314:
			return knight_destruction[14]; 
        break;
		case 315:
			return knight_destruction[15]; 
        break;
		case 316:
			return knight_destruction[16]; 
        break;

		//Rook
		case 400:
			return rook_destruction[0]; 
        break;
		case 401:
			return rook_destruction[1]; 
        break;
		case 402:
			return rook_destruction[2]; 
        break;
		case 403:
			return rook_destruction[3]; 
        break;
		case 404:
			return rook_destruction[4]; 
        break;
		case 405:
			return rook_destruction[5]; 
        break;
		case 406:
			return rook_destruction[6]; 
        break;
		case 407:
			return rook_destruction[7]; 
        break;
		case 408:
			return rook_destruction[8]; 
        break;
		case 409:
			return rook_destruction[9]; 
        break;
		case 410:
			return rook_destruction[10]; 
        break;
		case 411:
			return rook_destruction[11]; 
        break;
		case 412:
			return rook_destruction[12]; 
        break;
		case 413:
			return rook_destruction[13]; 
        break;
		case 414:
			return rook_destruction[14]; 
        break;
		case 415:
			return rook_destruction[15]; 
        break;
		case 416:
			return rook_destruction[16]; 
        break;
		
		//King
		case 500:
			return king_destruction[0]; 
        break;
		case 501:
			return king_destruction[1]; 
        break;
		case 502:
			return king_destruction[2]; 
        break;
		case 503:
			return king_destruction[3]; 
        break;
		case 504:
			return king_destruction[4]; 
        break;
		case 505:
			return king_destruction[5]; 
        break;
		case 506:
			return king_destruction[6]; 
        break;
		case 507:
			return king_destruction[7]; 
        break;
		case 508:
			return king_destruction[8]; 
        break;
		case 509:
			return king_destruction[9]; 
        break;
		case 510:
			return king_destruction[10]; 
        break;
		case 511:
			return king_destruction[11]; 
        break;
		case 512:
			return king_destruction[12]; 
        break;
		case 513:
			return king_destruction[13]; 
        break;
		case 514:
			return king_destruction[14]; 
        break;
		case 515:
			return king_destruction[15]; 
        break;
		case 516:
			return king_destruction[16]; 
        break;

		//Queen
		case 600:
			return queen_destruction[0]; 
        break;
		case 601:
			return queen_destruction[1]; 
        break;
		case 602:
			return queen_destruction[2]; 
        break;
		case 603:
			return queen_destruction[3]; 
        break;
		case 604:
			return queen_destruction[4]; 
        break;
		case 605:
			return queen_destruction[5]; 
        break;
		case 606:
			return queen_destruction[6]; 
        break;
		case 607:
			return queen_destruction[7]; 
        break;
		case 608:
			return queen_destruction[8]; 
        break;
		case 609:
			return queen_destruction[9]; 
        break;
		case 610:
			return queen_destruction[10]; 
        break;
		case 611:
			return queen_destruction[11]; 
        break;
		case 612:
			return queen_destruction[12]; 
        break;
		case 613:
			return queen_destruction[13]; 
        break;
		case 614:
			return queen_destruction[14]; 
        break;
		case 615:
			return queen_destruction[15]; 
        break;
		case 616:
			return queen_destruction[16]; 
        break;


		//BLOCK
		case 700:
			return block_destruction[0]; 
        break;
		case 701:
			return block_destruction[1]; 
        break;
		case 702:
			return block_destruction[2]; 
        break;
		case 703:
			return block_destruction[3]; 
        break;
		case 704:
			return block_destruction[4]; 
        break;
		case 705:
			return block_destruction[5]; 
        break;
		case 706:
			return block_destruction[6]; 
        break;
		case 707:
			return block_destruction[7]; 
        break;
		case 708:
			return block_destruction[8]; 
        break;
		case 709:
			return block_destruction[9]; 
        break;
		case 710:
			return block_destruction[10]; 
        break;
		case 711:
			return block_destruction[11]; 
        break;
		case 712:
			return block_destruction[12];
		break;
		case 713:
			return block_destruction[13];
		break;
		case 714:
			return block_destruction[14];
		break;
		case 715:
			return block_destruction[15];
		break;
		case 716:
			return block_destruction[16];
		break;
		case 717:
			return block_destruction[17];
		break;
		case 718:
			return block_destruction[18];
		break;
		case 719:
			return block_destruction[19];
		break;

		//Treasure
		case 800:
			return treasure_capture[0]; 
        break;
		case 801:
			return treasure_capture[1]; 
        break;
		case 802:
			return treasure_capture[2]; 
        break;
		case 803:
			return treasure_capture[3]; 
        break;
		case 804:
			return treasure_capture[4]; 
        break;
		case 805:
			return treasure_capture[5]; 
        break;
		case 806:
			return treasure_capture[6]; 
        break;
		case 807:
			return treasure_capture[7]; 
        break;
		case 808:
			return treasure_capture[8]; 
        break;
		case 809:
			return treasure_capture[9]; 
        break;
		case 810:
			return treasure_capture[10]; 
        break;
		case 811:
			return treasure_capture[11]; 
        break;
		case 812:
			return treasure_capture[12];
		break;
		case 813:
			return treasure_capture[13];
		break;
		case 814:
			return treasure_capture[14];
		break;
		case 815:
			return treasure_capture[15];
		break;
		case 816:
			return treasure_capture[16];
		break;
		case 817:
			return treasure_capture[17];
		break;
		case 818:
			return treasure_capture[18];
		break;
		case 819:
			return treasure_capture[19];
		break;


		//Special Spawn
		case 900:
			return special_spawn[0]; 
        break;
		case 901:
			return special_spawn[1]; 
        break;
		case 902:
			return special_spawn[2]; 
        break;
		case 903:
			return special_spawn[3]; 
        break;
		case 904:
			return special_spawn[4]; 
        break;
		case 905:
			return special_spawn[5]; 
        break;
		case 906:
			return special_spawn[6]; 
        break;
		case 907:
			return special_spawn[7]; 
        break;
		case 908:
			return special_spawn[8]; 
        break;
		case 909:
			return special_spawn[9]; 
        break;
		case 910:
			return special_spawn[10]; 
        break;
		case 911:
			return special_spawn[11]; 
        break;
		case 912:
			return special_spawn[12];
		break;
		case 913:
			return special_spawn[13];
		break;
		case 914:
			return special_spawn[14];
		break;
		case 915:
			return special_spawn[15];
		break;
		case 916:
			return special_spawn[16];
		break;
		case 917:
			return special_spawn[17];
		break;
		case 918:
			return special_spawn[18];
		break;
		case 919:
			return special_spawn[19];
		break;
		case 920:
			return special_spawn[20];
		break;
		case 921:
			return special_spawn[21];
		break;
		case 922:
			return special_spawn[22];
		break;
		case 923:
			return special_spawn[23];
		break;
		case 924:
			return special_spawn[24];
		break;
		case 925:
			return special_spawn[25];
		break;
		case 926:
			return special_spawn[26];
		break;
		case 927:
			return special_spawn[27];
		break;
		case 928:
			return special_spawn[28];
		break;
		case 929:
			return special_spawn[29];
		break;


		//Pawn Label
		case 1000:
			return pawn_label[0]; 
        break;
		case 1001:
			return pawn_label[1]; 
        break;
		case 1002:
			return pawn_label[2]; 
        break;
		case 1003:
			return pawn_label[3]; 
        break;
		case 1004:
			return pawn_label[4]; 
        break;
		case 1005:
			return pawn_label[5]; 
        break;
		case 1006:
			return pawn_label[6]; 
        break;
		case 1007:
			return pawn_label[7]; 
        break;
		case 1008:
			return pawn_label[8]; 
        break;
		case 1009:
			return pawn_label[9]; 
        break;
		case 1010:
			return pawn_label[10]; 
        break;
		case 1011:
			return pawn_label[11]; 
        break;
		case 1012:
			return pawn_label[12]; 
        break;
		case 1013:
			return pawn_label[13]; 
        break;
		case 1014:
			return pawn_label[14]; 
        break;
		case 1015:
			return pawn_label[15]; 
        break;
		case 1016:
			return pawn_label[16]; 
        break;

		//Knight Label
		case 1100:
			return knight_label[0]; 
        break;
		case 1101:
			return knight_label[1]; 
        break;
		case 1102:
			return knight_label[2]; 
        break;
		case 1103:
			return knight_label[3]; 
        break;
		case 1104:
			return knight_label[4]; 
        break;
		case 1105:
			return knight_label[5]; 
        break;
		case 1106:
			return knight_label[6]; 
        break;
		case 1107:
			return knight_label[7]; 
        break;
		case 1108:
			return knight_label[8]; 
        break;
		case 1109:
			return knight_label[9]; 
        break;
		case 1110:
			return knight_label[10]; 
        break;
		case 1111:
			return knight_label[11]; 
        break;
		case 1112:
			return knight_label[12]; 
        break;
		case 1113:
			return knight_label[13]; 
        break;
		case 1114:
			return knight_label[14]; 
        break;
		case 1115:
			return knight_label[15]; 
        break;
		case 1116:
			return knight_label[16]; 
        break;

		//Rook Label
		case 1200:
			return rook_label[0]; 
        break;
		case 1201:
			return rook_label[1]; 
        break;
		case 1202:
			return rook_label[2]; 
        break;
		case 1203:
			return rook_label[3]; 
        break;
		case 1204:
			return rook_label[4]; 
        break;
		case 1205:
			return rook_label[5]; 
        break;
		case 1206:
			return rook_label[6]; 
        break;
		case 1207:
			return rook_label[7]; 
        break;
		case 1208:
			return rook_label[8]; 
        break;
		case 1209:
			return rook_label[9]; 
        break;
		case 1210:
			return rook_label[10]; 
        break;
		case 1211:
			return rook_label[11]; 
        break;
		case 1212:
			return rook_label[12]; 
        break;
		case 1213:
			return rook_label[13]; 
        break;
		case 1214:
			return rook_label[14]; 
        break;
		case 1215:
			return rook_label[15]; 
        break;
		case 1216:
			return rook_label[16]; 
        break;

		//Bishop Label
		case 1300:
			return bishop_label[0]; 
        break;
		case 1301:
			return bishop_label[1]; 
        break;
		case 1302:
			return bishop_label[2]; 
        break;
		case 1303:
			return bishop_label[3]; 
        break;
		case 1304:
			return bishop_label[4]; 
        break;
		case 1305:
			return bishop_label[5]; 
        break;
		case 1306:
			return bishop_label[6]; 
        break;
		case 1307:
			return bishop_label[7]; 
        break;
		case 1308:
			return bishop_label[8]; 
        break;
		case 1309:
			return bishop_label[9]; 
        break;
		case 1310:
			return bishop_label[10]; 
        break;
		case 1311:
			return bishop_label[11]; 
        break;
		case 1312:
			return bishop_label[12]; 
        break;
		case 1313:
			return bishop_label[13]; 
        break;
		case 1314:
			return bishop_label[14]; 
        break;
		case 1315:
			return bishop_label[15]; 
        break;
		case 1316:
			return bishop_label[16]; 
        break;

		//King Label
		case 1400:
			return king_label[0]; 
        break;
		case 1401:
			return king_label[1]; 
        break;
		case 1402:
			return king_label[2]; 
        break;
		case 1403:
			return king_label[3]; 
        break;
		case 1404:
			return king_label[4]; 
        break;
		case 1405:
			return king_label[5]; 
        break;
		case 1406:
			return king_label[6]; 
        break;
		case 1407:
			return king_label[7]; 
        break;
		case 1408:
			return king_label[8]; 
        break;
		case 1409:
			return king_label[9]; 
        break;
		case 1410:
			return king_label[10]; 
        break;
		case 1411:
			return king_label[11]; 
        break;
		case 1412:
			return king_label[12]; 
        break;
		case 1413:
			return king_label[13]; 
        break;
		case 1414:
			return king_label[14]; 
        break;
		case 1415:
			return king_label[15]; 
        break;
		case 1416:
			return king_label[16]; 
        break;

		//Queen Label
		case 1500:
			return queen_label[0]; 
        break;
		case 1501:
			return queen_label[1]; 
        break;
		case 1502:
			return queen_label[2]; 
        break;
		case 1503:
			return queen_label[3]; 
        break;
		case 1504:
			return queen_label[4]; 
        break;
		case 1505:
			return queen_label[5]; 
        break;
		case 1506:
			return queen_label[6]; 
        break;
		case 1507:
			return queen_label[7]; 
        break;
		case 1508:
			return queen_label[8]; 
        break;
		case 1509:
			return queen_label[9]; 
        break;
		case 1510:
			return queen_label[10]; 
        break;
		case 1511:
			return queen_label[11]; 
        break;
		case 1512:
			return queen_label[12]; 
        break;
		case 1513:
			return queen_label[13]; 
        break;
		case 1514:
			return queen_label[14]; 
        break;
		case 1515:
			return queen_label[15]; 
        break;
		case 1516:
			return queen_label[16]; 
        break;

		//Queens Castle Label
		case 1800:
			return queens_castle_label[0]; 
        break;
		case 1801:
			return queens_castle_label[1]; 
        break;
		case 1802:
			return queens_castle_label[2]; 
        break;
		case 1803:
			return queens_castle_label[3]; 
        break;
		case 1804:
			return queens_castle_label[4]; 
        break;
		case 1805:
			return queens_castle_label[5]; 
        break;
		case 1806:
			return queens_castle_label[6]; 
        break;
		case 1807:
			return queens_castle_label[7]; 
        break;
		case 1808:
			return queens_castle_label[8]; 
        break;
		case 1809:
			return queens_castle_label[9]; 
        break;
		case 1810:
			return queens_castle_label[10]; 
        break;
		case 1811:
			return queens_castle_label[11]; 
        break;
		case 1812:
			return queens_castle_label[12]; 
        break;
		case 1813:
			return queens_castle_label[13]; 
        break;
		case 1814:
			return queens_castle_label[14]; 
        break;
		case 1815:
			return queens_castle_label[15]; 
        break;
		case 1816:
			return queens_castle_label[16]; 
        break;

		//Queens Guard Label
		case 1900:
			return queens_guard_label[0]; 
        break;
		case 1901:
			return queens_guard_label[1]; 
        break;
		case 1902:
			return queens_guard_label[2]; 
        break;
		case 1903:
			return queens_guard_label[3]; 
        break;
		case 1904:
			return queens_guard_label[4]; 
        break;
		case 1905:
			return queens_guard_label[5]; 
        break;
		case 1906:
			return queens_guard_label[6]; 
        break;
		case 1907:
			return queens_guard_label[7]; 
        break;
		case 1908:
			return queens_guard_label[8]; 
        break;
		case 1909:
			return queens_guard_label[9]; 
        break;
		case 1910:
			return queens_guard_label[10]; 
        break;
		case 1911:
			return queens_guard_label[11]; 
        break;
		case 1912:
			return queens_guard_label[12]; 
        break;
		case 1913:
			return queens_guard_label[13]; 
        break;
		case 1914:
			return queens_guard_label[14]; 
        break;
		case 1915:
			return queens_guard_label[15]; 
        break;
		case 1916:
			return queens_guard_label[16]; 
        break;

		//Queens Crusade Label
		case 2000:
			return queens_crusade_label[0]; 
        break;
		case 2001:
			return queens_crusade_label[1]; 
        break;
		case 2002:
			return queens_crusade_label[2]; 
        break;
		case 2003:
			return queens_crusade_label[3]; 
        break;
		case 2004:
			return queens_crusade_label[4]; 
        break;
		case 2005:
			return queens_crusade_label[5]; 
        break;
		case 2006:
			return queens_crusade_label[6]; 
        break;
		case 2007:
			return queens_crusade_label[7]; 
        break;
		case 2008:
			return queens_crusade_label[8]; 
        break;
		case 2009:
			return queens_crusade_label[9]; 
        break;
		case 2010:
			return queens_crusade_label[10]; 
        break;
		case 2011:
			return queens_crusade_label[11]; 
        break;
		case 2012:
			return queens_crusade_label[12]; 
        break;
		case 2013:
			return queens_crusade_label[13]; 
        break;
		case 2014:
			return queens_crusade_label[14]; 
        break;
		case 2015:
			return queens_crusade_label[15]; 
        break;
		case 2016:
			return queens_crusade_label[16]; 
        break;

		//Queens Confession Label
		case 2100:
			return queens_confession_label[0]; 
        break;
		case 2101:
			return queens_confession_label[1]; 
        break;
		case 2102:
			return queens_confession_label[2]; 
        break;
		case 2103:
			return queens_confession_label[3]; 
        break;
		case 2104:
			return queens_confession_label[4]; 
        break;
		case 2105:
			return queens_confession_label[5]; 
        break;
		case 2106:
			return queens_confession_label[6]; 
        break;
		case 2107:
			return queens_confession_label[7]; 
        break;
		case 2108:
			return queens_confession_label[8]; 
        break;
		case 2109:
			return queens_confession_label[9]; 
        break;
		case 2110:
			return queens_confession_label[10]; 
        break;
		case 2111:
			return queens_confession_label[11]; 
        break;
		case 2112:
			return queens_confession_label[12]; 
        break;
		case 2113:
			return queens_confession_label[13]; 
        break;
		case 2114:
			return queens_confession_label[14]; 
        break;
		case 2115:
			return queens_confession_label[15]; 
        break;
		case 2116:
			return queens_confession_label[16]; 
        break;

		//Queens Coronation Label
		case 2200:
			return queens_coronation_label[0]; 
        break;
		case 2201:
			return queens_coronation_label[1]; 
        break;
		case 2202:
			return queens_coronation_label[2]; 
        break;
		case 2203:
			return queens_coronation_label[3]; 
        break;
		case 2204:
			return queens_coronation_label[4]; 
        break;
		case 2205:
			return queens_coronation_label[5]; 
        break;
		case 2206:
			return queens_coronation_label[6]; 
        break;
		case 2207:
			return queens_coronation_label[7]; 
        break;
		case 2208:
			return queens_coronation_label[8]; 
        break;
		case 2209:
			return queens_coronation_label[9]; 
        break;
		case 2210:
			return queens_coronation_label[10]; 
        break;
		case 2211:
			return queens_coronation_label[11]; 
        break;
		case 2212:
			return queens_coronation_label[12]; 
        break;
		case 2213:
			return queens_coronation_label[13]; 
        break;
		case 2214:
			return queens_coronation_label[14]; 
        break;
		case 2215:
			return queens_coronation_label[15]; 
        break;
		case 2216:
			return queens_coronation_label[16]; 
        break;

		case 10000:
			return vertical_spike[0]; 
        break;
		case 10001:
			return vertical_spike[1]; 
        break;
		case 10002:
			return vertical_spike[2]; 
        break;
		case 10003:
			return vertical_spike[3]; 
        break;
		case 10004:
			return vertical_spike[4]; 
        break;
		case 10005:
			return vertical_spike[5]; 
        break;
		case 10006:
			return vertical_spike[6]; 
        break;
		case 10007:
			return vertical_spike[7]; 
        break;
		case 10008:
			return vertical_spike[8]; 
        break;
		case 10009:
			return vertical_spike[9]; 
        break;
		case 10010:
			return vertical_spike[10]; 
        break;

		case 11000:
			return horizontal_spike[0]; 
        break;
		case 11001:
			return horizontal_spike[1]; 
        break;
		case 11002:
			return horizontal_spike[2]; 
        break;
		case 11003:
			return horizontal_spike[3]; 
        break;
		case 11004:
			return horizontal_spike[4]; 
        break;
		case 11005:
			return horizontal_spike[5]; 
        break;
		case 11006:
			return horizontal_spike[6]; 
        break;
		case 11007:
			return horizontal_spike[7]; 
        break;
		case 11008:
			return horizontal_spike[8]; 
        break;
		case 11009:
			return horizontal_spike[9]; 
        break;
		case 11010:
			return horizontal_spike[10]; 
        break;


		case 20000:
			return puzzle_solved_label[0]; 
        break;
		case 20001:
			return puzzle_solved_label[1]; 
        break;
		case 20002:
			return puzzle_solved_label[2]; 
        break;
		case 20003:
			return puzzle_solved_label[3]; 
        break;
		case 20004:
			return puzzle_solved_label[4]; 
        break;
		case 20005:
			return puzzle_solved_label[5]; 
        break;
		case 20006:
			return puzzle_solved_label[6]; 
        break;
		case 20007:
			return puzzle_solved_label[7]; 
        break;
		case 20008:
			return puzzle_solved_label[8]; 
        break;
		case 20009:
			return puzzle_solved_label[9]; 
        break;
		case 20010:
			return puzzle_solved_label[10]; 
        break;
		case 20011:
			return puzzle_solved_label[11]; 
        break;
		case 20012:
			return puzzle_solved_label[12]; 
        break;
		case 20013:
			return puzzle_solved_label[13]; 
        break;
		case 20014:
			return puzzle_solved_label[14]; 
        break;
		case 20015:
			return puzzle_solved_label[15]; 
        break;
		case 20016:
			return puzzle_solved_label[16]; 
        break;

		case 20100:
			return puzzle_failure_label[0]; 
        break;
		case 20101:
			return puzzle_failure_label[1]; 
        break;
		case 20102:
			return puzzle_failure_label[2]; 
        break;
		case 20103:
			return puzzle_failure_label[3]; 
        break;
		case 20104:
			return puzzle_failure_label[4]; 
        break;
		case 20105:
			return puzzle_failure_label[5]; 
        break;
		case 20106:
			return puzzle_failure_label[6]; 
        break;
		case 20107:
			return puzzle_failure_label[7]; 
        break;
		case 20108:
			return puzzle_failure_label[8]; 
        break;
		case 20109:
			return puzzle_failure_label[9]; 
        break;
		case 20110:
			return puzzle_failure_label[10]; 
        break;
		case 20111:
			return puzzle_failure_label[11]; 
        break;
		case 20112:
			return puzzle_failure_label[12]; 
        break;
		case 20113:
			return puzzle_failure_label[13]; 
        break;
		case 20114:
			return puzzle_failure_label[14]; 
        break;
		case 20115:
			return puzzle_failure_label[15]; 
        break;
		case 20116:
			return puzzle_failure_label[16]; 
        break;

		default:
			std::cout << "\nError while retrieving asset [" << resourceId << "]\n";
			return xmarker_img;
			break;
    }
}
