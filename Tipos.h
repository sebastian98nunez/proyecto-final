#ifndef TIPOS_H
#define TIPOS_H
#include <iostream>
#include<vector>
using namespace std;

class Memento {
    private:
        int mapa[8][9];
    public :
        Memento(int m[8][9]);
        void backup(int matriz[8][9]);
};

class Tablero
{
	protected:

		int playerInTurn;
		bool endGame;
	public:
	    int map[8][9]; // la ultima fila se llena de 9
		Tablero();
		~Tablero(){};
		void Memento(int m[8][9]);
        void backup(int matriz[8][9]);
		int getPlayer();
		bool columnFull(int);
		int searchFila(int);
		void addFicha(int);
		void changePlayer();
		bool searchLine(int,int,int);
		bool win();
		bool space();

};

class TableroThree : public Tablero
{
	public:
		bool searchLine(int,int,int);
		bool win();
};

class TableroPop : public Tablero
{
	public:
		void bump(int);
		bool emptyColumn(int);
};

class TableroFive : public Tablero
{
	public:
		TableroFive();
		bool searchLine(int,int,int);
		bool win();
		int searchFila(int);
};


#endif
