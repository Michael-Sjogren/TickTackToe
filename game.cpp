#include "headers/game.hpp"

void Game::Quit()
{
	Game::running = false;
	return;
}

bool Game::AskToPlay()
{
	std::cout << "Would you like to play a game of TickTackToe?" << std::endl;
	std::cout << "Yes / No: (y/n)" << std::endl;
	if(GetYesNo())
	{
		return true;
	}
	else 
	{
		return false;
	}
}

void Game::PrintWin()
{
	system("cls");
	std::cout << board->GetWinner() << " has won this game!" << std::endl;
}


void Game::DoMove()
{
	system("cls");
	char columnCord = '\0';
	// numbers start at ascii number 48 (0)
	int asciZero = 48;
	int rowCord = 0;
	// if gameboard size i larger than 9 this will cause a bug
	
	while (rowCord < 1 || rowCord > board->board_size)
	{
		system("cls");
		std::cout << "Player: " << *currentPlayer << " ,please enter a row cordinate 1 - " << board->board_size << std::endl;
		board->PrintGameboard();
		std::cout << "Enter row cordinate: ";
		rowCord = (std::cin.get() - asciZero);
		std::cout << std::endl;
	}

	while (board->alphabet.substr(0 , board->board_size).find(columnCord) == std::string::npos)
	{
		system("cls");
		char lastChar = board->alphabet.substr(0, board->board_size).back();
		std::cout << "Player: " << *currentPlayer << " ,please enter a column cordinate A - "<< (char)toupper(lastChar) << std::endl;
		board->PrintGameboard();
		std::cout << "Enter column cordinate: ";
		columnCord = (char)tolower(std::cin.get());
		std::cout << std::endl;
	}
	
	std::cout << "row: " << rowCord << "\t"<< "column: " << columnCord << std::endl;
	if (board->PlaceOnCell(rowCord , columnCord , *currentPlayer)) 
	{
		board->PrintGameboard();
		currentPlayer = GetNextPlayer();
	}
	else 
	{
		std::cout << "cell already occupied" << std::endl;
		DoMove();
	}
}

void Game::StartGame()
{
	if (!AskToPlay()) return;
	currentPlayer = GetNextPlayer();
	PickPlayerSymbol();
	PrintGameInstructions();
	board->PrintGameboard();

	while (Game::running) 
	{
		if (!Game::won) 
		{
			DoMove();
			if (board->CheckIfInARow()) 
			{
				Game::won = true;
				PrintWin();
			}
		}
		// game is won
		else 
		{
			// ask for restart
			std::cout << "Restart game?" << std::endl;
			if (GetYesNo()) 
			{
				Game::restart = true;
				Game::running = false;
				system("cls");
			}
			else 
			{
				// exit loop
				Game::running = false;
			}
		}
	}
}

void Game::PickPlayerSymbol()
{
	std::cout << "Player1 pick your symbol X or O: ";

	char answer = '\0';
	const std::string allowable_answers = "XO";
	while (allowable_answers.find(answer) == std::string::npos)
	{
		answer = (char)toupper(std::cin.get());
	}
	player1 = answer;
	for each (char c in allowable_answers)
	{
		if (player1 != c) player2 = c;
		if (player1 == c) continue;
	}

	std::cout << "Player1 is = " <<  player1 << std::endl;
	std::cout << "Player2 is = " <<  player2 << std::endl;
}

void Game::PrintGameInstructions()
{
	std::cout << "\nInstructions\n----------------" << std::endl;
	std::cout
		<< "To play the game, enter a coordinate.\nFor exaple the 1A coordinate would be in the upper left corner." << std::endl;
	board->PrintGameboard();
	std::cout << "To win you must get " << board->win_row_count << " in a row." << std::endl;
	system("pause");
}

char* Game::GetNextPlayer()
{
	if (currentPlayer == &player1) {
		return &player2;
	}
	else if(currentPlayer == &player2){
		return &player1;
	}
	return &player1;
}

// returns false if no and true if yes
bool Game::GetYesNo()
{
	char answer = '\0';
	bool answering = true;
	while (answering)
	{
		answer = (char)tolower(std::cin.get());
		if (answer == 'y')
		{
			answering = false;
			return true;
		}
		else if (answer == 'n')
		{
			answering = false;
			return false;
		}
		else {
			std::cout << "Yes / No: (y/n)" << std::endl;
		}
	}
	return false;
}

Game::Game(int size)
{
	board = new Gameboard(size);
}

Game::~Game()
{
	std::cout << "cleaning up gameboard class" <<  std::endl;
	delete board;
}

