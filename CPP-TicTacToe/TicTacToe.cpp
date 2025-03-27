#include "TicTacToe.h"
#include <iostream>
#include <conio.h>

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
		if (m_board[WP[i][0]] != 0 &&
			m_board[WP[i][0]] == m_board[WP[i][1]] &&
			m_board[WP[i][0]] == m_board[WP[i][2]]) {

			winner = m_board[WP[i][0]];
			return true;
		}
	}	
	for (int i = 1; i < 10; i++) {
		if (m_board[i] == 0) {
			nMML = false;
			break;
		}
	}
	if (nMML) {
		winner = 3;
	}
	return nMML;
};

void TicTacToe::Display() const {
	for (int i = 0; i < 7; i++) {
		cout << "\t\t  " << m_display[i] << "\n";
		//Tabs center it for TakeTurn().
	}
	if (!IsGameOver()) {
		cout << "\t\t  " << (playerXTurn ? "X" : "O") << "'s turn" << "\n";
		//Tabs center it for TakeTurn().
	}
	else {
		if (winner == playerX) {
			cout << "\t" << "X's won!" << "\n";
		}
		else if (winner == playerO) {
			cout << "\t" << "O's won!" << "\n";
		}
		else {
			cout << "\t" << "You tied! Bummer." << "\n";
		}
	}
};

void TicTacToe::TakeTurn() {

	int choice;
	char input;
	int player;

	cout << "Please enter the number of the space you want: ";
	cin >> choice;
	while (1 > choice || choice > 10 || m_board[choice] != 0) {
		cout << "Please enter a valid number: ";
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
	case 1:	m_display[1][1] = input; break;
	case 2:	m_display[1][3] = input; break;
	case 3:	m_display[1][5] = input; break;
	case 4:	m_display[3][1] = input; break;
	case 5:	m_display[3][3] = input; break;
	case 6: m_display[3][5] = input; break;
	case 7: m_display[5][1] = input; break;
	case 8: m_display[5][3] = input; break;
	case 9: m_display[5][5] = input; break;
	default: cout << "You have forfeited your turn. Too bad for you.";
	}
	playerXTurn = !playerXTurn;
}


