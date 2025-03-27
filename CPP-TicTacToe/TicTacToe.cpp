#include "TicTacToe.h"
#include <iostream>
#include <conio.h>

//Define the Constructors to setup the empty board and initialize the player.

using namespace std;

TicTacToe::TicTacToe() {
	playerXTurn = true;

	for (int i = 0; i < 10; i++) {
		m_board[i] = 0;

	}
}
bool TicTacToe::IsGameOver() const {
	winner = 0;

	for (int i = 0; i < 8; i++) {
		if (m_board[WinPoss[i][0]] != 0 &&
			m_board[WinPoss[i][0]] == m_board[WinPoss[i][1]] &&
			m_board[WinPoss[i][1]] == m_board[WinPoss[i][2]]) {


			winner = m_board[WinPoss[i][0]];
			return true;
		}
	}

	bool boardFull = true;
	for (int i = 1; i < 10; i++) {
		if (m_board[i] == 0) {
			boardFull = false;
			break;
		}
	}

	if (boardFull) {
		winner = 3;
	}

	return boardFull;
};

void TicTacToe::Display() const {
	cout << endl;
	for (int i = 0; i < 5; i++) {
		cout << m_display[i] << endl;
	}
	cout << endl;

	if (!IsGameOver()) {
		cout << "Player " << (playerXTurn ? "X" : "O") << "'s turn" << endl;
	}
	else {
		if (winner == playerX) {
			cout << "Player X wins!" << endl;
		}
		else if (winner == playerO) {
			cout << "Player O wins!" << endl;
		}
		else {
			cout << "Game ended in a draw!" << endl;
		}
	}
};

void TicTacToe::TakeTurn() {

	int choice;
	char input;
	int player;

	cout << "Please enter the number of your space: ";
	cin >> choice;
	while (0 > choice > 10 || m_board[choice] != 0) {
		cout << "Please enter a valid number choice: ";
		cin >> choice;
	}
	if (playerXTurn) {
		player = 1;
		input = 'X';
	}
	else {
		player = 2;
		input = 'O';
	}

	m_board[choice] = player;

	switch (choice) {
	case 1:	m_display[0][0] = input; break;
	case 2:	m_display[0][2] = input; break;
	case 3:	m_display[0][4] = input; break;
	case 4:	m_display[2][0] = input; break;
	case 5:	m_display[2][2] = input; break;
	case 6: m_display[2][4] = input; break;
	case 7: m_display[4][0] = input; break;
	case 8: m_display[4][2] = input; break;
	case 9: m_display[4][4] = input; break;
	default: cout << "Unexpected error.";
	}

	playerXTurn = !playerXTurn;
}


