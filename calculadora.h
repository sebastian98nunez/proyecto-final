#ifndef CALCULADORA_H
#define CALCULADORA_H
#include <queue>
#include <iostream>
using namespace std;

int adaptar (int numero, int modulo) //Convierte un numero en base 10 al modulo indicado
{
	int residuo = numero % modulo; //Transformamos el numero en su equivalente modular mas pequeño
	if(residuo >= 0)
		return residuo;
	else //Si el numero es negativo, se resta al modulo
		return modulo + residuo;

}

int operar (int numero1, int numero2, int modulo, int operacion) //Realiza la operacion indicada por el usuario
{
	numero1 = adaptar(numero1, modulo); //Se transforma los numeros al modulo indicado
	numero2 = adaptar(numero2, modulo);
	switch(operacion){
	case 1: //Elige entre suma, resta o multiplicacion
		return adaptar(numero1 + numero2, modulo);
	case 2:
		return adaptar(numero1 - numero2, modulo);
	case 3:
		return adaptar(numero1 * numero2, modulo);
    }
}

int inverso(int numero, int modulo)//funcion que halla el inverso modular
{
	int resultado = 0; //variable que guarda el resultado
	int dividendo= modulo;
	int divisor= numero;
	bool continuar = true; //control del bucle
	queue<int> cociente; //cola de cocientes
	int residuo = 0;
	bool existe = false; //existe o no existe inverso modular
	int k = -1; //variable k, de la formula P(k+2)
	int pn = 0; //variable Pn
	int pn_1 = 1; //variable P(n-1)
	int pn_2 = 0; //variable P(n-2)

	while(continuar==true)
	{
		k +=1;//K aumenta su valor progresivamente
		cociente.push(dividendo / divisor); //Se añaden los cocientes a la cola
		residuo = dividendo % divisor; //Se halla el residuo
		if(residuo==1)//Cuando se halle el residuo 1...
		{
			existe=true; //sí existe inverso modular
			continuar=false; //se detiene el bucle
		}
		else if(residuo==0)//Si no se halla residuo 1...
		{
			continuar=false;//el bucle se detiene al llegar a residuo 0
		}
		dividendo = divisor; //rotacion
		divisor = residuo;
	}

	if(existe==true)//si existe el inverso modular...
	{
		for(int contador=2; contador<=k+2; contador++)// el inverso se halla en P(k+2)
		{// empezamos hallando P(2), pues P(1)=1 y P(0)=0
			pn= operar(pn_2, operar(pn_1, cociente.front(), modulo, 3), modulo, 2);//pn = pn_2 -pn_1 * cociente
			cociente.pop();// retiro el cociente usado de la cola
			pn_2 = pn_1;// rotacion
			pn_1 = pn;
		}
	}
	resultado = pn;
	return resultado;
}

#endif
