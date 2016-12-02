#include "Tipos.h"
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#define LIMITE 10

using namespace std;
////////////////////////////////////////////////TABLERO CLASICO
//Constructor de Tablero en blanco


Memento::Memento(int m[8][9]) {
    for (int i=0; i<8; i++)
        for(int j=0;j<9; j++)
               mapa[i][j]=m[i][j];
}
void Memento::backup(int m[8][9])
{
    for (int i=0; i<8; i++)
        for(int j=0;j<9; j++)
               m[i][j]=mapa[i][j];
}



Tablero::Tablero()
{
	playerInTurn = 1;
    for (int i =0; i<9;i++)
        map[0][i]=8;
	for(int i=1; i<7; i++){
		for(int j=0; j<9; j++){
            map[i][j]=0;
		}
    for (int i =0; i<9;i++)
        map[7][i]=9;
    }
}



int Tablero::getPlayer()
{
	return playerInTurn;
}

//Revisa si queda espacio en la columna
bool Tablero::columnFull(int columna)
{
    if(map[1][columna]!=0)
        return true;
    return false;

}

//Buscar el primer espacio disponible
int Tablero::searchFila(int columna)
{
	for(int fila=6; fila>=0; fila--)
	{
		if(map[fila][columna]==0)
			return fila;
	}
	return 0;
}


//Insertar la ficha del jugador
void Tablero::addFicha(int columna)
{
    map[searchFila(columna)][columna]= playerInTurn;
}


//Es el turno del otro jugador
void Tablero::changePlayer()
{
	if(playerInTurn==1)
		playerInTurn=2;
	else
		playerInTurn=1;
}


bool Tablero::searchLine(int direction, int i, int j){
	bool endPath = false;
	int counter = 1;
	int posx = i;
	int posy = j;
	queue <int> path;
	path.push(posx*10+posy);
	while(endPath==false)
	{
		if(direction==1)//En vertical
			posy++;
		else if(direction==2)//En horizontal
			posx++;
		else if(direction==3){//En diagonal derecha
			posx++;
			posy++;
		}
		else if(direction==4){//En diagonal izquierda
			posy++;
			posx--;
		}
		if(map[posx][posy]==playerInTurn){
			path.push(posx*10+posy);//Guardamos las posición x,y en un solo número
			counter++;
		}
		else
			endPath = true;
		if(counter==4){
			for(int i=0; i<4; i++){
				int a= path.front();
				map[a/10][a%10]=3;
				path.pop();
			}
			return true;
		}
	}
	return false;
}


bool Tablero::win(){
   for(int i=0; i<7; i++){
		for(int j=0; j<8; j++){
			if(map[i][j]==playerInTurn){
				if(searchLine(1,i,j)==true)//En vertical
					return true;
				else if(searchLine(2,i,j)==true)//En horizontal
					return true;
				else if(searchLine(3,i,j)==true)//En diagonal derecha
					return true;
				else if(searchLine(4,i,j)==true)//En diagonal izquierda
					return true;
				}
			}
		}
	return false;
}

bool Tablero::space(){
	for(int i=1; i<5; i++){
		for(int j=0; j<=6; j++){
			if(map[i][j]==0)
                return false;
		}
	}
    return true;
}

///////////////////////////////////////////////TABLERO CONECTA 5
TableroFive::TableroFive()
{
    for (int i =0; i<9;i++)
        map[0][i]=8;
	playerInTurn = 1;
	for(int i=1; i<7; i++){
		for(int j=1; j<9; j++){
            map[i][j]=0;
		}
    }
    for (int i =0; i<9;i++)
        map[7][i]=9;
}


bool TableroFive::searchLine(int direction, int i, int j){
	bool endPath = false;
	int counter = 1;
	int posx = i;
	int posy = j;
	queue <int> path;
	path.push(posx*10+posy);
	while(endPath==false)
	{
		if(direction==1)//En vertical
			posy++;
		else if(direction==2)//En horizontal
			posx++;
		else if(direction==3){//En diagonal derecha
			posx++;
			posy++;
		}
		else if(direction==4){//En diagonal izquierda
			posy++;
			posx--;
		}
		if(map[posx][posy]==playerInTurn){
			path.push(posx*10+posy);//Guardamos las posición x,y en un solo número
			counter++;
		}
		else
			endPath = true;
		if(counter==5){
			for(int i=0; i<5; i++){
				int a=path.front();
				map[a/10][a%10]=3;
				path.pop();
			}
			return true;
		}
	}
	return false;
}

bool TableroFive::win(){
   for(int i=0; i<7; i++){
		for(int j=0; j<8; j++){
			if(map[i][j]==playerInTurn){
				if(searchLine(1,i,j)==true)//En vertical
					return true;
				else if(searchLine(2,i,j)==true)//En horizontal
					return true;
				else if(searchLine(3,i,j)==true)//En diagonal derecha
					return true;
				else if(searchLine(4,i,j)==true)//En diagonal izquierda
					return true;
				}
			}
		}
	return false;
}


int TableroFive::searchFila(int columna)
{
	for(int fila=6; fila>=0; fila--)
	{
		if(map[fila][columna]==0)
			return fila;
	}
	return 0;
}



////////////////////////////////////////////////////////CONECTA 3
//Sobrecarga de la función de búsqueda
bool TableroThree::searchLine(int direction, int i, int j){
	bool endPath = false;
	int counter = 1;
	int posx = i;
	int posy = j;
	int path[3];
	path[0]= posx*10+posy;
	while(endPath==false){
		if(direction==1)//En vertical
			posy++;
		else if(direction==2)//En horizontal
			posx++;
		else if(direction==3){//En diagonal derecha
			posx++;
			posy++;
		}
		else if(direction==4){//En diagonal izquierda
			posy++;
			posx--;
		}
		if(map[posx][posy]==playerInTurn){
			path[counter]=posx*10+posy;//Guardamos las posición x,y en un solo número
			counter++;
		}
		else
			endPath = true;
		if(counter==3){
			for(int i=0; i<3; i++){
				int a=path[i];
				map[a/10][a%10]=3;
			}
			return true;
		}
	}
	return false;
}


//Sobrecarga: Determinar ganador
bool TableroThree::win(){
   for(int i=1; i<7; i++){
		for(int j=1; j<8; j++){
			if(map[i][j]==playerInTurn){
				if(searchLine(1,i,j)==true)//En vertical
					return true;
				else if(searchLine(2,i,j)==true)//En horizontal
					return true;
				else if(searchLine(3,i,j)==true)//En diagonal derecha
					return true;
				else if(searchLine(4,i,j)==true)//En diagonal izquierda
					return true;
				}
			}
		}
	return false;
}

///////////////////////////////////////////////////TABLERO POP/////////////////////////////////////////////////

//Revisa si la columna está vacía
bool TableroPop::emptyColumn(int column){
	if(map[7][column]==0)
		return true;
    return false;
}

//Reacomoda las fichas tras haber quitado una
void TableroPop::bump(int columna)	{
    int i = 7;
    bool end = false;
    while(!end){
        map[i][columna]=map[i-1][columna];
        i--;
        if(map[i][columna]==0 || i==1 )
            end=true;
        if(end)
            map[i][columna]=0;
    }
    map[i][columna] = 0;
}
