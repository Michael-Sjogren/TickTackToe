
#include "Gameboard.hpp"

class Game {

    private:
    bool won = false;
	bool running = true;
	char* currentPlayer;
	char player1, player2;
	Gameboard* board;
    public:
		Game(int size);
		~Game();
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