#pragma once

#include <iostream>
#include "Game.h"

class TicTacToe : public Game
{

private:

	// Member variables

	// Hold the marks on the board
	char m_board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

	// Integer to keep track of the current player (0 or 1)
	int m_currentPlayer = 0;

public:

	// Pure virtual functions, from the Game class

	// Return true if the game is over, and return false if the game is still going
	virtual bool IsGameOver() const;

	// Indicate whose turn it is, prompt the player to enter their mark position, ensure valid positions
	virtual void TakeTurn();

	// Displays the current state of the game, with each player's marks
	virtual void Display() const;

};