#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>


class Tablero
{
	protected:
		int map[8][9];
		bool endGame;
		int playerInTurn;
	public:
		Tablero();
		~Tablero(){};
		bool getEndGame();
		int getPlayer();
		void printTablero();
		bool columnFull(int);
		int searchFila(int);
		void addFicha(int);
		void changePlayer();
		bool searchLine(int,int,int);
		bool win();
		bool space();

};
#endif
