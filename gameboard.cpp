#include "headers/gameboard.hpp"


bool Gameboard::PlaceOnCell(int row, char col, char player)
{
	int column = 0;
	for (;column < alphabet.length(); column++)
	{
		char c = alphabet[column];
		if (c == col) 
		{
			break;
		}
	}
	char c = board[row-1][column];
	if (c == '\0') 
	{
		board[row-1][column] = player;
		// check if win conditon in a row
		return true;
	}
	return false;
}

void Gameboard::PrintGameboard()
{
	int i = 0;
	for (char c : alphabet) 
	{
		if (i >= Gameboard::BOARD_SIZE) break;
		std::cout << " " << (char)toupper(c) << " ";
		i++;
	}
	std::cout << std::endl;
	for (int row = 1; row <= Gameboard::BOARD_SIZE; row++)
	{
		for (int col = 1; col <= Gameboard::BOARD_SIZE; col++)
		{

			if (col % BOARD_SIZE == 0) 
			{
				std::cout << "[" << board[row-1][col-1] << "] " << row << std::endl;
			}
			else 
			{
				std::cout << "[" << board[row-1][col-1] << "]";
			}
		}
	}
}

char * Gameboard::GetWinner()
{
	return the_winner;
}

char* Gameboard::GetCellOnBoard(int row, int col)
{
	if (row >= Gameboard::BOARD_SIZE || row < 0) return __nullptr;
	if (col >= Gameboard::BOARD_SIZE || col < 0) return __nullptr;
	return &board[row][col];
}

/** 
	[-1, 1][0, 1][1, 1]  
	[-1, 0][0, 0][1, 0]
	[-1,-1][0,-1][1,-1]
**/
bool Gameboard::CheckIfInARow()
{
	// there are nine potential directions
	std::string debugString = "";
	bool tied = true;
	for (size_t j = 0; j < BOARD_SIZE*BOARD_SIZE; j++)
	{
		int col = j % BOARD_SIZE;
		int row = j / BOARD_SIZE;
		char* startCell = GetCellOnBoard(row , col);
		if (startCell == nullptr) continue;
		if (*startCell == '\0') 
		{
			tied = false;
			continue;
		}

		for (size_t i = 0; i < 9; i++)
		{
			// we dont want to check or own posistion again , so we skip
			if (i == 4) continue;

			int x_dir = (int)(i % 3) - 1;
			int y_dir = (int)(i / 3) - 1;
			// holds the amount of occurences of the same sumbol in a row
			int index = 1;
			int rowCount = 1;
			// getting the next cell in the current direction 
			while (index <= Gameboard::WIN_ROW_COUNT)
			{
				char* c = GetCellOnBoard(row + (y_dir*index), col + (x_dir * index));
				if (c == nullptr) break;
				index++;
				if (*c == *startCell) 
				{
					rowCount++;
				}
				else if(*c != *startCell)
				{
					break;
				}
				
			}

			if (rowCount >= Gameboard::WIN_ROW_COUNT)
			{
				the_winner = startCell;
				return true;
			}
		}
	}
	if (tied) 
	{
		std::cout << "Game is tied" << std::endl;
		system("pause");
	}

	return false;
}
