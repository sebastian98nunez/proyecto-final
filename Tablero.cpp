#include "Tablero.h"

using namespace std;

//Constructor de Tablero en blanco
Tablero::Tablero()
{
	endGame = false;
	playerInTurn = 1;
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<9; j++)
		{
			if(i==0 || i==7)
			{
				map[i][j]=9;
			}
			else
			{
				if(j==0 || j==8)
				{
					map[i][j]=9;
				}
				else
				{
					map[i][j]=0;
				}
			}
		}
	}
}


//Modificadores de acceso
bool Tablero::getEndGame()
{
	return endGame;
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
	for(int fila=6; fila>0; fila--)
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

//Función auxiliar que busca en todas las direcciones
bool Tablero::searchLine(int direction, int i, int j)
{
	bool endPath = false;
	int counter = 1;
	int posx = i;
	int posy = j;
	List<int> path;
	path.add_head(posx*10+posy);
	while(endPath==false)
	{
		if(direction==1)//En vertical
		{
			posx++;
		}
		else if(direction==2)//En horizontal
		{
			posy++;
		}
		else if(direction==3)//En diagonal derecha
		{
			posx++;
			posy++;
		}
		else if(direction==4)//En diagonal izquierda
		{
			posx++;
			posy--;
		}

		if(map[posx][posy]==playerInTurn)
		{
			path.add_head(posx*10+posy);//Guardamos las posición x,y en un solo número
			counter++;
		}
		else
		{
			endPath = true;
		}
		if(counter==4)
		{
			for(int i=0; i<4; i++)
			{
				int a=path.pop();
				map[a/10][a%10]=3;
			}
			return true;
		}
	}
	return false;
}



//Comprueba si un jugador ha ganado
bool Tablero::win()
{
	for(int i=1; i<7; i++)
	{
		for(int j=1; j<8; j++)
		{
			if(map[i][j]==playerInTurn)
			{
				if(searchLine(1,i,j)==true)//En vertical
				{
					endGame = true;
					return true;
				}
				else if(searchLine(2,i,j)==true)//En horizontal
				{
					endGame = true;
					return true;
				}
				else if(searchLine(3,i,j)==true)//En diagonal derecha
				{
					endGame = true;
					return true;
				}
				else if(searchLine(4,i,j)==true)//En diagonal izquierda
				{
					endGame = true;
					return true;
				}
			}
		}
	}
	return false;
}

//Comprueba si aún hay espacio en el tablero
bool Tablero::space()
{
	bool full = true;
	for(int i=1; i<7; i++)
	{
		for(int j=1; j<8; j++)
		{
			if(map[i][j]==0)
			{
				full = false;
			}
		}
	}
	if(full==true)
	{
		endGame = true;
		return false;
	}
	else
	{
		return true;
	}
}
