#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

class Gameboard
{
public:
	// the max size in width and height of the gameboard
	int board_size;
	// the required number you have to get in a row to win the game
	int win_row_count;
	char* GetCellOnBoard(int , int);
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	bool PlaceOnCell(int, char, char player);
	void PrintGameboard();
	char GetWinner();
	bool CheckIfInARow();
	bool isTied = true;

	Gameboard(int size);
	Gameboard() = default;
	~Gameboard();
private:
	// holds either X or O or '\0' as free slot
	char** board;
	char the_winner = '\0';
};