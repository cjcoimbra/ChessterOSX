#pragma once


#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "GameEngine.h"
#include <vector>

class Piece
{
    public:
		float dropdownTargetOnRespawn;
		bool isDroppingDownFromRespawn;
		void StartDropDownForRespawn();

		bool isPuzzleMode;
		int backup_sprite_id;
		bool IsMoveAllowed(int,int);
		int treasure_id;
		void RespawnPieceAsTreasure(int);
		~Piece(void);
        Piece(int, int, sf::RenderWindow *,ResourceManager *, float, float);
		//Piece();
		void RefreshAnimationFrames();

		sf::Sprite new_destruction_spt[6][17];

        sf::Sprite piece_spt;
		sf::Sprite destruction_spt[17];
		sf::Sprite block_destruction_spt[20];
		sf::Sprite treasure_capture_spt[20];
		
		sf::Sprite special_spawn_spt[30];
		int special_spawn_animation_frame;
		bool is_special_spawn;
		void StartSpecialSpawnAnimation();
		void AnimateSpecialSpawn();
		sf::Clock special_spawn_animation_timer;
		
		int block_animation_frame;
		bool is_breaking_block;
		void StartBlockDestruction();
		void AnimateBlockDestruction();
		sf::Clock block_animation_timer;

		int treasure_capture_frame;
		bool is_capturing_treasure;
		void StartTreasureCapture();
		void AnimateTreasureCapture();
		sf::Clock treasure_animation_timer;

		bool is_destructing;
		int current_frame;
		void UpdateDestructionAnimation();
		sf::Clock destruction_timer;
		void StartDestructionAnimation();
        bool VerifySelection(int, int);
        bool VerifyDeselection();
        bool VerifyLandingSquare(int,int);
        bool IsFocused(int,int);
		void StartDropDown(int);
		float amount_to_fall;
		float original_y;
		void RelocateKilledPiece(sf::Vector2i);
        int px, py;
        int tile_size;
        float offset_x;
        float offset_y;
        void Update();
        int general_id;
        std::vector<sf::Vector2i> allowedMoves;
        void RefreshAllowedMoves();
        bool valid;
        bool is_falling_down;
        float fall_down_rate;
        float total_fall;
        sf::Vector2i original_position;
        void Respawn(int);
		void RespawnOnStart(int);
        int sprite_id;
		bool just_respawned;
		bool moved;
		
    protected:
    private:
        sf::RenderWindow *wnd_ptr;
        ResourceManager * resource_manager;
        bool following_mouse;



};
