#pragma once
#include "Game.h"
#include<iostream>
#include<vector>

class TicTacToe : public Game {

private:

	bool won = false;
	mutable bool playerXTurn = true;

	int playerX = 1;
	int playerO = 2;

	int WinPoss[8][3] = { {1, 2, 3}, {1, 5, 9}, {1, 4, 7} ,{2, 5, 8}, {3, 6, 9}, {3, 5, 7}, {4, 5, 6}, {7, 8, 9} };
	mutable int m_board[10];
	mutable char m_display[5][6] = { { '1', '|', '2', '|', '3', '\0' }, { '-', '-', '-', '-', '-', '\0' }, { '4', '|', '5', '|', '6', '\0' }, { '-', '-', '-', '-', '-', '\0' }, { '7', '|', '8', '|', '9', '\0' } };
	mutable int winner = 0;

public:

	TicTacToe();
	virtual ~TicTacToe() {}

	virtual bool IsGameOver() const;
	virtual void Display() const;
	virtual void TakeTurn();


};

