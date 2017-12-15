#include "StdAfx.h"
#include "PuzzleListView.h"

PuzzleListView::PuzzleListView(int ts, sf::RenderWindow * w)
{
	this->wnd_ptr = w;
	chesster_font.LoadFromFile("GFX/Font/Deutsch.ttf");
	this->tile_size = ts;
	int external_index = 1;
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			puzzle_numbers[i][j].SetFont(chesster_font);
			
			std::stringstream st;
			st << external_index;
			puzzle_numbers[i][j].SetText(st.str());
			puzzle_numbers[i][j].SetSize(32);
			puzzle_numbers[i][j].SetColor(sf::Color(255,255,255));
			puzzle_numbers[i][j].SetPosition((this->wnd_ptr->GetWidth() * 590)/1920 + (i * tile_size) + (tile_size/2) - puzzle_numbers[i][j].GetRect().GetWidth()/2,(this->wnd_ptr->GetHeight() * 190)/1080 + (j * tile_size) + (tile_size/2) - puzzle_numbers[i][j].GetRect().GetHeight()/2);
			external_index++;
		}
	}
}



void PuzzleListView::SaveUnlockedPuzzlesProgress()
{
	std::string file = "Config/puzzle_selection.txt";
	std::ofstream save_info;
	save_info.open (file.c_str());
	
	for (int i = 0; i < 64; i++)
	{
		if (i <= selected_puzzle_index + 1)
			save_info << "puzzle[" << i << "]=" << 1;
		else
		{
			if (this->unlocked_puzzle_row[i])
				save_info << "puzzle[" << i << "]=" << 1;
			else
				save_info << "puzzle[" << i << "]=" << 0;
		}

		if (i < 63)
		save_info << "\n";
	}
	save_info.close();
}

bool PuzzleListView::PrepareSelectedPuzzleToPlay(int selected_id)
{
	target_pieces.clear();
	this->selected_puzzle_index = selected_id;
	std::string prefix = "Config/Puzzles/puzzle_";
	std::string suffix = ".txt";
	std::string full_path;
	//Saved Game file
	std::cout << "\n\n\nLoading selected puzzle info...\n";
	std::string file_lines[67];
	int index = 0;
	std::ifstream infile;
	if (selected_puzzle_index == 0)
	{
		full_path = prefix + "00" + suffix;
		//infile.open(full_path);
	}
	else if (selected_puzzle_index > 0 && selected_puzzle_index < 10)
	{
		std::stringstream st;
		st << selected_puzzle_index;
		std::string middle = "0" + st.str();
		full_path = prefix + middle + suffix;
		//infile.open(full_path);
	}
	else
	{
		std::stringstream st;
		st << selected_puzzle_index;
		std::string middle =  st.str();
		full_path = prefix + middle + suffix;
		//infile.open(full_path);
	}

	infile.open(full_path.c_str());

	if (!infile.is_open()) //File doesn´t exist
	{
		std::cout << "Error while opening file: " << full_path << "\n";
		return false;
	}

    while(!infile.eof()) 
    {
		std::getline(infile,file_lines[index]);
		index++;
    }
	infile.close();

	//General config
	int pos;
	std::stringstream ss;

	//Description
	pos = file_lines[0].find("=");
	pos++;
	ss << file_lines[0].substr(pos); 
	ss >> this->selected_puzzle_description;
	
	this->Replace(selected_puzzle_description, "+", " ");

	ss.clear();
	std::cout << "Loaded Puzzle description: [" << this->selected_puzzle_description << "]\n";

	//Moves
	pos = file_lines[1].find("=");
	pos++;
	ss << file_lines[1].substr(pos); 
	ss >> this->selected_puzzle_moves;
	ss.clear();
	std::cout << "Loaded Puzzle amount of moves: [" << this->selected_puzzle_moves << "]\n";

	//Turns
	pos = file_lines[2].find("=");
	pos++;
	ss << file_lines[2].substr(pos); 
	ss >> this->selected_puzzle_turns;
	ss.clear();
	std::cout << "Loaded Puzzle amount of turns: [" << this->selected_puzzle_turns << "]\n";

	//Game Board
	int external_index = 0;
	for (int p=3; p<67; p++)
	{
		int temp_value;
		pos = file_lines[p].find("=");
		pos++;
		ss << file_lines[p].substr(pos); 
		ss >> temp_value;
		if (temp_value < 0)//Target Piece
		{
			temp_value = abs(temp_value);
			this->target_pieces.push_back(external_index);
			if (temp_value == 99) //Workaround to deal with pawn sprite_id which is 0 and cannot be cast negative
				temp_value = 0;
			std::cout <<"Puzzle piece [" <<external_index << "] added to the current puzzle's target list\n";
		}
		this->selected_puzzle_board[external_index] = temp_value;
		ss.clear();
		std::cout << "Puzzle piece [" << external_index << "] sprite_id is: [" << this->selected_puzzle_board[external_index] << "]\n";
		external_index++;
	}
	
	puzzle_description.SetFont(chesster_font);
	puzzle_description.SetText(selected_puzzle_description);
	puzzle_description.SetSize(42);
	puzzle_description.SetColor(sf::Color(210,210,0));
	puzzle_description.SetPosition(this->wnd_ptr->GetWidth()/2 - puzzle_description.GetRect().GetWidth()/2 , this->wnd_ptr->GetHeight() - puzzle_description.GetRect().GetHeight() - 20);
	std::cout <<"\nDEBUG: finished parsing the selected puzzle, inside PrepareSelectedPuzzleToPlay()\n";
	return true;
}


void PuzzleListView::Update(int x, int y)
{
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (x > puzzle_numbers[i][j].GetPosition().x && x < puzzle_numbers[i][j].GetPosition().x + tile_size - 10 && y > puzzle_numbers[i][j].GetPosition().y && y < puzzle_numbers[i][j].GetPosition().y + tile_size - 10)
			{
				puzzle_numbers[i][j].SetColor(sf::Color(200,0,0));
				puzzle_numbers[i][j].SetSize(42);
				//last_puzzle_focused = puzzle_numbers[i][j].GetText();
			}
			else
			{
				puzzle_numbers[i][j].SetColor(sf::Color(255,255,255));
				puzzle_numbers[i][j].SetSize(32);
			}
		}
	}
}

void PuzzleListView::Replace(std::string& str, const std::string& oldStr, const std::string& newStr)
{
  size_t pos = 0;
  while((pos = str.find(oldStr, pos)) != std::string::npos)
  {
     str.replace(pos, oldStr.length(), newStr);
     pos += newStr.length();
  }
}

std::string PuzzleListView::HandleButtons(int x, int y)
{
	last_puzzle_focused = "none";
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (x > puzzle_numbers[i][j].GetPosition().x && x < puzzle_numbers[i][j].GetPosition().x + tile_size - 10 && y > puzzle_numbers[i][j].GetPosition().y && y < puzzle_numbers[i][j].GetPosition().y + tile_size - 10)
			{
				if (puzzle_locks[i][j].GetPosition().x == 0) //Check if the clicked puzzle is available
				{
					puzzle_numbers[i][j].SetColor(sf::Color(200,0,0));
					puzzle_numbers[i][j].SetSize(42);
					last_puzzle_focused = puzzle_numbers[i][j].GetText();
					return last_puzzle_focused;
				}
			}
		}
	}
	return last_puzzle_focused;
}
