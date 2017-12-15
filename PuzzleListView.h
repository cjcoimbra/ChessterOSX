#pragma once

class PuzzleListView
{
public:
	PuzzleListView(int, sf::RenderWindow *);
	void Update(int, int);
	bool PrepareSelectedPuzzleToPlay(int);
	std::string HandleButtons(int, int);
	bool unlocked_puzzle_row[64];
	int selected_puzzle_moves;
	int selected_puzzle_turns;
	std::string selected_puzzle_description;
	sf::String puzzle_description;
	int selected_puzzle_board[64];
	int selected_puzzle_index;
	sf::Sprite puzzle_view_background;
	sf::Sprite puzzle_locks[8][8];
	sf::String puzzle_numbers[8][8];
	sf::Font chesster_font;
	std::vector<int> target_pieces;
	int tile_size;
	std::string last_puzzle_focused;
	sf::RenderWindow *wnd_ptr;
	void Replace(std::string& , const std::string& , const std::string& );
	void SaveUnlockedPuzzlesProgress();
};
