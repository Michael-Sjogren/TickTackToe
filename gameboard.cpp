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
		if (i >= board_size) break;
		std::cout << " " << (char)toupper(c) << " ";
		i++;
	}
	std::cout << std::endl;
	for (int row = 1; row <=board_size; row++)
	{
		for (int col = 1; col <= board_size; col++)
		{

			if (col % board_size == 0)
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

char Gameboard::GetWinner()
{
	return the_winner;
}

char* Gameboard::GetCellOnBoard(int row, int col)
{
	if (row >= board_size || row < 0) return __nullptr;
	if (col >= board_size || col < 0) return __nullptr;
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
	for (size_t j = 0; j < board_size*board_size; j++)
	{
		int col = j % board_size;
		int row = j / board_size;
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
			while (index <= win_row_count)
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

			if (rowCount >= win_row_count)
			{
				the_winner = *startCell;
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

Gameboard::Gameboard(int size)
{
	board = new char*[size];
	for (size_t i = 0; i < size; i++)
	{
		board[i] = new char[size];
	}
	for (size_t i = 0; i < size*size; i++)
	{
		int col = i % size;
		int row = i / size;
		board[row][col] = '\0';
	}
	board_size = size;
	win_row_count = size;
}

Gameboard::~Gameboard()
{
	for (size_t i = 0; i < Gameboard::board_size; i++)
	{
		delete[] board[i];
	}
	delete[] board;
	std::cout << "cleaning up gameboard array" << std::endl;
}