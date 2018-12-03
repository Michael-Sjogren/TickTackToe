#include "headers/game.hpp"

Game* currentGame;

void Start();
void Restart();

int main()
{
	Start();
	return 0;
}

void Start()
{
	currentGame = new Game(4);
	currentGame->StartGame();
	if (currentGame->restart)
	{
		Restart();
	} 
	else
	{
		delete currentGame;
		exit(0);
	}
}

void Restart()
{
	delete currentGame;
	Start();
}