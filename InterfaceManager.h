#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"

class InterfaceManager
{
    public:
		void LoadSavedTreasures(int, int, int, int);
		bool hasPositiveRemainder;
		sf::Sprite negative_total_score_animation[25];
		sf::Sprite positive_total_score_animation[25];
		sf::Sprite positive_score_animation[25];
		int positive_score_animation_frame;
		sf::Clock positive_score_animation_timer;

		sf::Sprite demand_animation[23];
		int demand_animation_frame;
		sf::Clock demand_animation_timer;

		sf::Clock end_turn_timer;
		bool hasEndTimerStarted;
		
		bool isAnimating;

		void ShowNextTreasure();
		bool isIncreasingScore;
		bool isDecreasingScore;
		int targetScore;
		int currentScore;
		void SetupScoreUpdate(int, int, bool);
		void UpdateScore(int);
		sf::Clock scoreUpdateTimer;
		int currentTotalScore;

		int original_font_size;
		void ResetFontSize();
		void RetifyTextPositions();
		void IncreaseFontSize();
        InterfaceManager(sf::RenderWindow *, ResourceManager *, float, float);
		void HandleMainMenuButtons(int);
		void HandleGameButtons(int);
		std::string ButtonInput(int,int,int);
        sf::Sprite title_screen_spt;
        ResourceManager * resource_manager;
        sf::RenderWindow * wptr;
        sf::String temp_info;
        sf::Font chesster_font;
		
		sf::String deselect_info;
		sf::String next_treasure_info[4];

		sf::Sprite multiply_spt;
		
		sf::String loading_info;
		sf::Sprite moves_spt;
		sf::Sprite turns_spt;
		sf::Sprite moves_bluecrest_spt;
		sf::Sprite turns_bluecrest_spt;
		sf::Sprite info_frame_spt; 

		sf::Sprite play_button_normal;
		sf::Sprite tutorial_button_normal;
		sf::Sprite puzzle_button_normal;
		sf::Sprite scores_button_normal;
		sf::Sprite credits_button_normal;
		sf::Sprite quit_button_normal;

		sf::Sprite new_button_normal;
		sf::Sprite new_button_focus;
		sf::Sprite resume_button_normal;
		sf::Sprite resume_button_focus;
		sf::Sprite back_button_normal;
		sf::Sprite back_button_focus;

		sf::Sprite quit_button_focus;
		sf::Sprite play_button_focus;
		sf::Sprite tutorial_button_focus;
		sf::Sprite puzzle_button_focus;
		sf::Sprite scores_button_focus;
		sf::Sprite credits_button_focus;

		sf::Sprite combos_button_off;
		sf::Sprite combos_button_focus;
		sf::Sprite combos_button_on;
		std::string combos_button_state;

		sf::Sprite movement_button_off;
		sf::Sprite movement_button_focus;
		sf::Sprite movement_button_on;
		std::string movement_button_state;

		sf::Sprite treasure_button_off;
		sf::Sprite treasure_button_focus;
		sf::Sprite treasure_button_on;
		std::string treasure_button_state;

		sf::Sprite combos_board;
		std::string combos_board_state;
		sf::Sprite movement_board;
		std::string movement_board_state;
		sf::Sprite treasure_board;
		std::string treasure_board_state;

		sf::String moves_label;
		sf::String moves_info;
		sf::String turn_points_label;
		sf::String turn_points_info;
		sf::String demand_label;
		sf::String demand_info;
		sf::String total_points_label;
		sf::String total_points_info;
		sf::String turn_label;
		sf::String turn_info;

		sf::String temp_resume_game;
		sf::String temp_new_game;
		sf::String temp_cancel;
		
		sf::String match_label;
		sf::String match_amount_info;
		sf::String match_points_info;
		sf::String x_label;
		
		sf::Sprite next_treasure_banner;

		sf::Sprite treasure[4];
		sf::Sprite next_treasure[4];
		sf::Sprite treasure_shadow[4];
		bool unlocked_treasures[4];
		void UnlockTreasure(int);
		void ResetTreasures();

		void ReloadBoard(int);

		bool is_sliding_out;
		std::string textboard_to_show;
		std::string textboard_to_hide;
		float treasuresboard_x;
		float combosboard_x;
		float movesboard_x;
		float moving_textboard_target_x;
		void PerformTextboardSlide();
		void SetupTextboardTransition(std::string, std::string);
		float slide_speed;
		void ResetSlidingConditions();
		void SetupTreasureImagesForNewLevel();

    protected:
    private:
};

