#pragma once

#include <iostream>
#include "InterfaceManager.h"

class GameSession
{
public:
	GameSession(int, InterfaceManager *, int, int, int,int,int,int,int,int, int);
	~GameSession(void);
	void PrepareNextLevel(int, int , int);
	int demand;
	int current_level;
	int current_turn;
	int total_moves;
	int moves_left;
	int total_score;
	int turn_score;
	void CalculatePieceScore(int);
	int GetPiecePoints(int);
	bool turn_active;
	int EndTurn();
	int FakeEndTurn();
	void DecrementMoves();
	int piece_values[6];
	int base_demand;
	std::string ConvertIntToString(int);
	InterfaceManager * gui;
	int treasure_points;
	void ComputeTreasurePoints(int);

	bool GetRemainderSignal();

	bool treasure_chest[4];
	int treasure_layer[4];
	void SetupTreasures(int);
	void UnlockTreasure();
	int GetCurrentTreasureLayer();
	int GetTreasureId();
	bool CheckTreasureUnlock();
};
