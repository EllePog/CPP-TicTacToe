#pragma once
#include "Game.h"
#include<iostream>
#include<vector>

class TicTacToe : public Game {

private:

	int playerX = 1;
	int playerO = 2;

	mutable bool playerXTurn = true;	
	mutable bool nMML = true; // nMML = No More Moves Left

	mutable int winner = 0;
	mutable int m_board[10];

	int WP[8][3] = { {1, 2, 3}, {1, 5, 9}, {1, 4, 7} ,{2, 5, 8}, {3, 6, 9}, {3, 5, 7}, {4, 5, 6}, {7, 8, 9} };
	// WP = Win Possibilities
	
	mutable char m_display[7][7] = { 
		{' ', ' ', ' ', ' ', ' ', ' ', '\0' },
		{' ', '1', '|', '2', '|', '3', '\0' }, 
		{' ', '-', '-', '-', '-', '-', '\0' }, 
		{' ', '4', '|', '5', '|', '6', '\0' }, 
		{' ', '-', '-', '-', '-', '-', '\0' }, 
		{' ', '7', '|', '8', '|', '9', '\0' },
		{' ', ' ', ' ', ' ', ' ', ' ', '\0' }
	};

public:

	TicTacToe();
	virtual ~TicTacToe() {}

	virtual bool IsGameOver() const;
	virtual void Display() const;
	virtual void TakeTurn();


};

