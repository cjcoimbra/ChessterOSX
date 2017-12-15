#pragma once


#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class ResourceManager
{
    public:
        ResourceManager();
		
		sf::Image next_arrow_button;
		sf::Image next_arrow_button_over;
		sf::Image close_button;
		sf::Image close_button_over;
		sf::Image tutorial_sheet;

		sf::Image bluecrest;
		sf::Image next_treasure_banner;
		sf::Image treasure[4];
		sf::Image treasure_shadow[4];
		
		sf::Image combos_button_off;
		sf::Image combos_button_focus;
		sf::Image combos_button_on;

		sf::Image movement_button_off;
		sf::Image movement_button_focus;
		sf::Image movement_button_on;
		sf::Image multiply;

		sf::Image treasure_button_off;
		sf::Image treasure_button_focus;
		sf::Image treasure_button_on;

		sf::Image combos_board;
		sf::Image movement_board;
		sf::Image treasure_board;

		sf::Image play_button_normal;
		sf::Image tutorial_button_normal;
		sf::Image puzzle_button_normal;
		sf::Image scores_button_normal;
		sf::Image credits_button_normal;
		sf::Image quit_button_normal;

		sf::Image back_button_normal;
		sf::Image new_button_normal;
		sf::Image resume_button_normal;

		sf::Image back_button_focus;
		sf::Image new_button_focus;
		sf::Image resume_button_focus;

		sf::Image quit_button_focus;
		sf::Image play_button_focus;
		sf::Image tutorial_button_focus;
		sf::Image puzzle_button_focus;
		sf::Image scores_button_focus;
		sf::Image credits_button_focus;
		
		sf::Image xmarker_img;
		sf::Image vertical_spike_img;
		sf::Image horizontal_spike_img;
		sf::Image moves_img;
		sf::Image turns_img;
		sf::Image info_frame_img;
		sf::Image piece_selector_img;

        sf::Image knight_img;
		sf::Image knight_destruction[17];
        sf::Image pawn_img;
		sf::Image pawn_destruction[17];
        sf::Image rook_img;
		sf::Image rook_destruction[17];
        sf::Image king_img;
		sf::Image king_destruction[17];
        sf::Image queen_img;
		sf::Image queen_destruction[17];
        sf::Image bishop_img;
		sf::Image bishop_destruction[17];

		sf::Image puzzle_solved_label[17];
		sf::Image puzzle_failure_label[17];
		
		sf::Image block_destruction[13];
		sf::Image special_spawn[30];
		sf::Image treasure_capture[20];

		sf::Image vertical_spike[11];
		sf::Image horizontal_spike[11];
	
		sf::Image knight_label[17];
		sf::Image pawn_label[17];
		sf::Image rook_label[17];
		sf::Image king_label[17];
		sf::Image queen_label[17];
		sf::Image bishop_label[17];
		sf::Image queens_castle_label[17];
		sf::Image queens_confession_label[17];
		sf::Image queens_coronation_label[17];
		sf::Image queens_crusade_label[17];
		sf::Image queens_guard_label[17];

		//sf::Image tutorial_images[10];
		//sf::Image tutorial_memory_saver;

		sf::Image mouse_cursor;

		sf::Image block_c_img;
		
		sf::Image game_board_img;
		sf::Image game_board_alpha_img;

        sf::Image test_background_img;
        sf::Image title_screen_img;
		sf::Image board_frame_img;

		sf::Image loading_indicator;

		sf::Image puzzle_background;
		sf::Image puzzle_list_lock;

        //sf::Image GetImageResource(int);
        const sf::Image& GetImageResource(int);
		//const sf::Image& OnDemandLoadForTutorialView(int);
		const sf::Image& OnDemandLoadForBoards(int);
		
		sf::Image demand_animation[23];
		const sf::Image& LoadDemandAnimation(int);

		sf::Image negative_score_particles[21];
		sf::Image positive_score_particles[25];
		const sf::Image& LoadPositiveScoreAnimation(int);
		const sf::Image& LoadNegativeScoreAnimation(int);

		const sf::Image& OnDemandLoadBackground(int);
		const sf::Image& OnDemandLoadFrame(int);
		const sf::Image& OnDemandLoadBoardAlpha(int);
		const sf::Image& OnDemandLoadTreasures(int);
		void RefreshBlockFrames();
		sf::Image generic_bg;
		int current_level;
		
		void UnloadUnusedAssets(int);
		sf::Image generic_textboard;
		//void LoadResourceOnRunTime(int);
    protected:
    private:
};
