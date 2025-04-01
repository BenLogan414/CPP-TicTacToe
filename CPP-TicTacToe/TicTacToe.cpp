#pragma once

#include "TicTacToe.h"

void TicTacToe::Display() const
{
	// Clear the display.
	system("cls");

	// Display the current state of the game.
	std::cout << "-------\n";
	std::cout << "|" << m_board[0] << "|" << m_board[1] << "|" << m_board[2] << "|\n";
	std::cout << "-------\n";
	std::cout << "|" << m_board[3] << "|" << m_board[4] << "|" << m_board[5] << "|\n";
	std::cout << "-------\n";
	std::cout << "|" << m_board[6] << "|" << m_board[7] << "|" << m_board[8] << "|\n";
	std::cout << "-------\n";
}

void TicTacToe::TakeTurn()
{
	// Local variable to hold the entered position.
	int position;

	// Prompt the current player to enter the position (1-9).
	if (m_currentPlayer == 0)
	{
		std::cout << "Player X, enter the position (1-9) where you want to place your mark: ";
		std::cin >> position;
	}
	else
	{
		std::cout << "Player O, enter the position (1-9) where you want to place your mark: ";
		std::cin >> position;
	}

	// Check for valid inputs. If the position is out of range, or already taken, prompt the player to enter a valid position.
	while (m_board[position - 1] == 'X' || m_board[position - 1] == 'O')
	{
		std::cout << "Position already taken. Enter the position (1-9) where you want to place your mark: ";
		std::cin >> position;
	}
	while (position > 9)
	{
		std::cout << "Position is out of range. Enter the position (1-9) where you want to place your mark: ";
		std::cin >> position;
	}

	// If position is valid, place the designated player's mark in their chosen position, and switch players.
	if (m_currentPlayer == 0)
	{
		m_board[position - 1] = 'X';
		m_currentPlayer = 1;
	}
	else
	{
		m_board[position - 1] = 'O';
		m_currentPlayer = 0;
	}
}

bool TicTacToe::IsGameOver() const
{
	// Char variable to hold the winning player's character (X or O).
	// Because this is before the win condition logic, the current player is technically the loser, which is why this works.
	char winner;
	if (m_currentPlayer == 0)
	{
		winner = 'O';
	}
	else
	{
		winner = 'X';
	}

	// Check each of the 8 possible win conditions.
	// Horizontal win conditions:
	if ((m_board[0] & m_board[1] & m_board[2]) == 'X' || (m_board[0] & m_board[1] & m_board[2]) == 'O')
	{
		std::cout << "Player " << winner << " wins!\n";
		return true;
	}
	else if ((m_board[3] & m_board[4] & m_board[5]) == 'X' || (m_board[3] & m_board[4] & m_board[5]) == 'O')
	{
		std::cout << "Player " << winner << " wins!\n";
		return true;
	}
	else if ((m_board[6] & m_board[7] & m_board[8]) == 'X' || (m_board[6] & m_board[7] & m_board[8]) == 'O')
	{
		std::cout << "Player " << winner << " wins!\n";
		return true;
	}
	// Vertical win conditions:
	else if ((m_board[0] & m_board[3] & m_board[6]) == 'X' || (m_board[0] & m_board[3] & m_board[6]) == 'O')
	{
		std::cout << "Player " << winner << " wins!\n";
		return true;
	}
	else if ((m_board[1] & m_board[4] & m_board[7]) == 'X' || (m_board[1] & m_board[4] & m_board[7]) == 'O')
	{
		std::cout << "Player " << winner << " wins!\n";
		return true;
	}
	else if ((m_board[2] & m_board[5] & m_board[8]) == 'X' || (m_board[2] & m_board[5] & m_board[8]) == 'O')
	{
		std::cout << "Player " << winner << " wins!\n";
		return true;
	}
	// Diagonal win conditions:
	else if ((m_board[0] & m_board[4] & m_board[8]) == 'X' || (m_board[0] & m_board[4] & m_board[8]) == 'O')
	{
		std::cout << "Player " << winner << " wins!\n";
		return true;
	}
	else if ((m_board[2] & m_board[4] & m_board[6]) == 'X' || (m_board[2] & m_board[4] & m_board[6]) == 'O')
	{
		std::cout << "Player " << winner << " wins!\n";
		return true;
	}
	// If every space is NOT empty, and no winner has been determined from the previous else if statements, the game is a tie.
	// Tie condition:
	else if ((m_board[0] != ' ') && (m_board[1] != ' ') && (m_board[2] != ' ') &&
			 (m_board[3] != ' ') && (m_board[4] != ' ') && (m_board[5] != ' ') &&
			 (m_board[6] != ' ') && (m_board[7] != ' ') && (m_board[8] != ' '))
	{
		std::cout << "Game is a tie!\n";
		return true;
	}
	// If no win or tie has been determined, return "false" as the game is still going.
	else
	{
		return false;
	}
}
