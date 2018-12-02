
#include "Gameboard.hpp"

class Game {

    private:
    bool won;
	bool running;
	char* currentPlayer;
	char player1, player2;
	Gameboard board;
    public:
	Game::Game() 
	{
		won = false;
		running = true;
		board = Gameboard();
	}
    void Restart();
    void Quit();
    void PrintIntro();
	void PrintWin();
	void PrintLose();
    void DoMove();
	void StartGame();
	void PickPlayerSymbol();
	void PrintGameInstructions();
	char* GetNextPlayer();
};