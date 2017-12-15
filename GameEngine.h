#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Board.h"
#include "Piece.h"
#include "InterfaceManager.h"
#include "ResourceManager.h"
#include "Combo.h"
#include "GameSession.h"
#include "AnimatedLabel.h"
#include "AnimatedSpike.h"
#include "TutorialView.h"
#include "AudioManager.h"
#include "MouseCursor.h"
#include "LevelCompletedView.h"
#include "LoadingView.h"
#include "PuzzleListView.h"
#include "ScoresView.h"
#include "CreditsView.h"

class GameEngine
{
    public:
		bool has_queen;
		bool CheckForSpecialSpawnsStillAnimating();
		bool CheckPuzzleSolution();
		void SetPuzzleModeFailure();
		void StartPuzzle();
		bool isPuzzleMode;
		void NormalModeUpdate();
		void PuzzleModeUpdate();
		PuzzleListView * puzzle_list_view;
		void ConfigurePuzzleList();
		LoadingView * loading_view;
		bool CheckForSavedGames();
		void ResetSaveFile();
		void ParseSavedGameFile();
		void SaveSessionToFile();
		sf::String in_game_console[5];
		void ConfigureConsole();
		void PushConsoleMessage(std::string);
		void DisplayConsole();
		bool showConsole;
		void ConfigureBackground(int);
		void ReleasePiecesFromMemory();
		sf::Shape move_hint[8][8];
		void DelayedInit();
		bool CheckForBlocksBreaking();
		CreditsView credits_view;
		void LoadRanking();
		void UpdateLocalScore();
		void GetOnlineRanking();
		std::string local_record;
		std::string online_record;
		std::string last_background;
		ScoresView ranking_view;
		int GetValidTreasureSpawnLocation();
		void SpawnTreasure();
		LevelCompletedView level_view;
		MouseCursor cursor;
		AudioManager audio;
		TutorialView *tutorial;
		void StartTutorial();
		int temporary_match_points;
		bool counting;
		AnimatedLabel combo_title;
		AnimatedSpike animated_spikes;
		void CheckSpecialCombos();
		void StartGame(int);
		float max_width;
		float max_height;
		float max_tile_size;
		int FindPieceUniqueId(int,int);
		int blocks_for_removal[8][8];
		int treasures_for_removal[8][8];
		void RemoveAdjacentBlocks(int,int);
		void RemoveAdjacentTreasures(int,int);
		sf::Sprite vertical_spike[8];
		sf::Sprite horizontal_spike[8];
		void CheckNegativeScore(int);
		bool spikes[8];
		int spike_count;
		//sf::Http::Response response;
		bool x_marker[64];
		sf::Clock aux_timer;
		int last_combo_counted;
		void UpdateCounting();
		void CountCombos();
		std::vector<Combo> combo_counter;
		bool ChessterLoading();
		sf::Vector2i LookForQueen();
		sf::Vector2i queens_throne;
		sf::Clock loading_timer;
		bool NeedToDropDown();
		bool checked[8][8];
		std::vector<int> ids_to_remove;
		void RecursiveCheck(int,int,int,int);
		std::vector<int> turn_to_queen;
		int combo_count;
		std::string combo_string;
		int combo_points;
		GameSession * game;
        Piece * game_pieces[64];
		int pieces[8][8];
		int combos[13][8][8];
		sf::Clock combo_by_combo_timer;
		void ComboCheck();
		bool is_still_removing_combos;
		int current_combo_to_remove;
		int last_combo_removed;
		bool matching_loop_just_finished;
		bool is_dropping_down;
		void RemoveCombos();
		std::vector<int> combo_marker;
		void ShowRemovedPieces();
        GameEngine();
		std::string GetMatchLabel(int);
        void Flush();
		void RestorePiecesMovement();
		void DropDown();
        void RandomlyCreatePieces();
        void ProcessInput();
		bool IsDropDownFinished();
        void Update();
        void Run();
		void MatchPieces();
		void FinishLoop();
		void MatchAndDropDownLoop();
		void RespawnDeadPieces();
        void SetGameState(int);
        int GetGameState();
        bool IsRunning();
        sf::RenderWindow *m_window_ptr;
        ResourceManager *resource_manager;
        Board * board;
        InterfaceManager * gui;
        float tile_size_factor;
        int possible_target_piece;
        void ActivateCascadeFall(int, int);
		int pieces_moving;
		int base_demand;
		int move_count;
		int piece_values[6];
		void ReadConfigFile();
    protected:
    private:
		sf::Sprite generic_x_marker;
        bool running;
        int game_state;
        bool some_piece_is_selected;
        int selected_piece_id;
        sf::Vector2i selected_piece_original_position;
};

