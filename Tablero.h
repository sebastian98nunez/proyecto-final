#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>


class Tablero
{
	protected:
		int map[6][7];
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
		bool win(int);
		bool space();

};
#endif
    




/*#include <iostream>
#include <Tablero.h>
#include <stdlib.h>
using namespace std;

int main()
{
    Tablero Tab;
    Tab.printTablero();
    int posx, posy;
    posx=posy=0;
    while(!Tab.win(posx)){
        cout<<"ingrese la posicion x ";
        cin>>posx;
        cout <<endl;
        Tab.addFicha(posx);
        //system("cls");
        Tab.printTablero();
    }
    if(Tab.win(posx))
        cout<<"Gano el jugador "<<Tab.getPlayer();
}*/
