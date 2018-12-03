#include "Gameboard.hpp"
class Game {

    private:
    bool won = false;
	bool running = true;
	char* currentPlayer;
	char player1, player2;
	Gameboard* board;
    public:
	bool restart = false;
		Game(int size);
		~Game();
    void Quit();
	void PrintWin();
    void DoMove();
	void StartGame();
	void PickPlayerSymbol();
	void PrintGameInstructions();
	char* GetNextPlayer();
	bool AskToPlay();
	bool GetYesNo();
};