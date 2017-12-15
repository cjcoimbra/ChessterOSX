#include "StdAfx.h"
#include "GameSession.h"

GameSession::GameSession(int cl, InterfaceManager * g, int dem, int mvs, int pawn, int knight, int rook, int bishop, int king, int queen, int total)
{
	gui = g;
	current_level = cl;
	current_turn = 10;
	base_demand = dem;
	demand = current_level * dem;
	
	piece_values[0] = pawn;
	piece_values[1] = knight;
	piece_values[2] = rook;
	piece_values[3] = bishop;
	piece_values[4] =  king;
	piece_values[5] = queen; 

	gui->demand_info.SetText(ConvertIntToString(this->demand));
	
	//if (current_level == 1)
	//	total_score = 0;
	total_score = total;
	
	turn_score = 0;
	total_moves = mvs;
	moves_left = total_moves;
	turn_active = true;
	gui->moves_info.SetText(ConvertIntToString(this->moves_left));
	gui->total_points_info.SetText(ConvertIntToString(this->total_score));
	gui->turn_points_info.SetText(ConvertIntToString(this->turn_score));
	gui->turn_info.SetText("10");

	gui->RetifyTextPositions();

	SetupTreasures(current_level);

	treasure_points = 0;
}

bool GameSession::GetRemainderSignal()
{
	if (turn_score - demand >= 0)
		return true;
	else
		return false;
}

void GameSession::PrepareNextLevel(int cl, int dem, int mvs)
{
	current_level = cl;
	current_turn = 10;
	base_demand = dem;
	demand = current_level * dem;
	
	gui->demand_info.SetText(ConvertIntToString(this->demand));
	if (current_level == 1)
		total_score = 0;
	turn_score = 0;
	total_moves = mvs;
	moves_left = total_moves;
	turn_active = true;
	gui->moves_info.SetText(ConvertIntToString(this->moves_left));
	gui->total_points_info.SetText(ConvertIntToString(this->total_score));
	gui->turn_points_info.SetText(ConvertIntToString(this->turn_score));
	gui->turn_info.SetText("10");

	gui->RetifyTextPositions();

	SetupTreasures(current_level);

	treasure_points = 0;
}

GameSession::~GameSession(void)
{
}

void GameSession::SetupTreasures(int level)
{
	this->treasure_chest[0] = false;
	this->treasure_chest[1] = false;
	this->treasure_chest[2] = false;
	this->treasure_chest[3] = false;

	if (level == 1 || level == 2 || level == 3) //demo levels are all the same
	{
		this->treasure_layer[0] = 200;
		this->treasure_layer[1] = 300;
		this->treasure_layer[2] = 400;
		this->treasure_layer[3] = 500;
	}
	//TODO - insert other levels
}

void GameSession::UnlockTreasure()
{
	for (int i=0; i<4; i++)
	{
		if (this->treasure_chest[i] == false)
		{
			this->treasure_chest[i] = true;
			return;
		}
	}
}

bool GameSession::CheckTreasureUnlock()
{
	if (this->treasure_chest[3] == false)
	{
		if (this->turn_score >= this->GetCurrentTreasureLayer())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	return false;
}

int GameSession::GetTreasureId()
{
	for (int i=0; i < 4; i++)
	{
		if (this->treasure_chest[i] == false)
		{
			return i;
		}
	}
}

int GameSession::GetCurrentTreasureLayer()
{
	for (int i=0; i < 4; i++)
	{
		if (this->treasure_chest[i] == false)
		{
			return this->treasure_layer[i];
		}
	}
}


void GameSession::DecrementMoves()
{
	this->moves_left--;
	this->gui->moves_info.SetText(ConvertIntToString(this->moves_left));
}

void GameSession::CalculatePieceScore(int piece_id)
{
	/*
	Pawn:50
	Rook:100
	Bishop:100
	Knight:200
	King:300
	Queen:500
	*/
	/*
	int inc = 0;
	switch (piece_id)
	{
		case 0: // pawn
			inc = 0;
			break;
		case 1: //knight
			inc =  20;
			break;
		case 2: // rook
			inc =  10;
			break;
		case 3: //bishop
			inc =  10;
			break;
		case 4: //king
			inc =  30;
			break;
		case 5: //queen
			inc =  50;
			break;
	}
	*/
	
	//this->turn_score += inc;
	if (piece_id <= 5)
		this->turn_score += piece_values[piece_id];
	else
	{
		switch (piece_id)
		{
			case 8:
				//Queens Castle
				this->turn_score += 125;
				break;
			case 9:
				//Queens Guard
				this->turn_score += 100;
				break;
			case 10:
				//Queens Crusade
				this->turn_score += 150;
				break;
			case 11:
				//Queens Confession
				this->turn_score += 175;
				break;
			case 12:
				//Queens Coronation
				this->turn_score += 200;
				break;
		}
	}

	//this->gui->turn_points_info.SetText(ConvertIntToString(this->turn_score));
}

int GameSession::GetPiecePoints(int piece_id)
{
	/*
	int inc;
	switch (piece_id)
	{
		case 0: // pawn
			inc = 5;
			break;
		case 1: //knight
			inc =  20;
			break;
		case 2: // rook
			inc =  10;
			break;
		case 3: //bishop
			inc =  10;
			break;
		case 4: //king
			inc =  30;
			break;
		case 5: //queen
			inc =  50;
			break;
	}
	
	return inc;
	*/
	if (piece_id <= 5) 
		return piece_values[piece_id];
	else 
	{
		//Queen큦 Castle
		if (piece_id == 8)
			return 175;
		//Queen큦 Guard
		else if (piece_id == 9)
			return 125;
		//Queen큦 Crusade
		else if (piece_id == 10)
			return 225;
		//Queen큦 Confession
		else if (piece_id == 11)
			return 200;
		//Queen큦 Coronation
		else if (piece_id == 12)
			return 275;

	}
}

std::string GameSession::ConvertIntToString(int value)
{
	std::stringstream out;
	out << value;
	return out.str();
}

void GameSession::ComputeTreasurePoints(int id)
{
	//treasure_points  += treasure_layer[id];
	treasure_points += 300;
}

int GameSession::EndTurn()
{
	moves_left = total_moves;
	this->gui->moves_info.SetText(ConvertIntToString(this->moves_left));
	
	turn_score = turn_score + treasure_points;

	turn_score = turn_score - demand;
	total_score = total_score + turn_score;
	this->gui->total_points_info.SetText(ConvertIntToString(this->total_score));
	turn_score = 0;
	treasure_points = 0;
	this->gui->turn_points_info.SetText(ConvertIntToString(this->turn_score));
	current_turn--;
	turn_active = true;
	
	return total_score;
}

int GameSession::FakeEndTurn()
{
	int fake_turn_score = turn_score;
	int fake_treasure_points = treasure_points;
	int fake_total_score = total_score;
	fake_turn_score = fake_turn_score + fake_treasure_points;
	fake_turn_score = fake_turn_score - demand;
	fake_total_score = fake_total_score + fake_turn_score;
	return fake_total_score;
}