#pragma once
#include "Game.h"

class Something {

public:
	char m_board[9] = {};

	char m_Row1[6] = { ' ', '|', ' ', '|', ' ', '\0' };
	char m_Divide1[6] = { '-', '-', '-', '-', '-', '\0' };
	char m_Row2[6] = { ' ', '|', ' ', '|', ' ', '\0' };
	char m_Divide2[6] = { '-', '-', '-', '-', '-', '\0' };
	char m_Row3[6] = { ' ', '|', ' ', '|', ' ', '\0' };


	virtual void Display() const { std::cout << m_Row1 << "\n" << m_Divide1 << "\n" << m_Row2 << "\n" << m_Divide2 << "\n" << m_Row3; }


};
