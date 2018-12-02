#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

class Gameboard
{
public:
	// the max size in width and height of the gameboard
	static const int BOARD_SIZE = 3;
	// the required number you have to get in a row to win the game
	static const int WIN_ROW_COUNT = 3;
	char* GetCellOnBoard(int , int);
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

	bool PlaceOnCell(int, char, char player);
	void PrintGameboard();
	char* GetWinner();
	bool CheckIfInARow();
private:
	// holds either X or O or '\0' as free slot
	char board[BOARD_SIZE][BOARD_SIZE] = {0};
	char* the_winner = nullptr;
};