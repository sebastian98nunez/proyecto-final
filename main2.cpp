#include <iostream>
#include <fstream>
#include <string>
#include "calculadora.h" //reciclamos la calculadora de inverso modular

#include <queue>
using namespace std;


const int modulo=256; //trabajaremos con modulo 256 (por los 256 caracteres ASCII)


void encriptar(string fuente, int clavePrivada, string destino){//funcion que encripta un texto con la clave privada
	string texto; //texto del archivo fuente
	string textoEncriptado;
	string linea; //variable que va guardando una a una las lineas del texto original
	int clavePublica= inverso(clavePrivada, modulo);//la clave publica es el inverso modular de la clave privada
	int carAscii; //guarda el numero de un caracter ASCII(ej: 97)
	char carLetra; //guarda el caracter ASCII (ej: a)
	ifstream archivo1; //trabaja con el archivo fuente
	ofstream archivo2; //trabaja con el archivo destino
	archivo1.open(fuente.c_str());//abre el archivo fuente
	if(!archivo1.is_open())
	{
		cout << "No se puede abrir el archivo: " << fuente << endl;//excepción:no se puede abrir el archivo
	}
	else
	{
		if(clavePublica==0)
		{
			while(clavePublica==0)// si no existe inverso, solicita otra clave privada
			{
				cout<<"Imposible generar clave publica, pruebe con otra clave privada: ";
				cin>>clavePrivada;
				clavePublica = inverso(clavePrivada, modulo);
			}
		}
		cout<<"Su clave publica es: "<<clavePublica<<endl;
		while(getline(archivo1,linea))//guarda el texto linea a linea
		{
			texto = texto + linea + '\n';
		}
		int largo = texto.size();
		for(int contador=0; contador<largo; contador++)//convierte cada caracter a ASCII y lo encripta
		{
			carAscii = texto[contador];
			carAscii = operar(carAscii, clavePrivada, modulo, 3); //multiplica cada caracter con la clave privada
			carLetra = carAscii;
			textoEncriptado += carLetra;
		}
		archivo2.open(destino.c_str());//abre el archivo destino
		if(!archivo2.is_open())
		{
			cout << "No se puede abrir el archivo: " << destino << endl;
		}
		else
		{
			archivo2 << textoEncriptado; //ingresa el texto encriptado
		}
		archivo2.close();//cierra archivo destino
	}
	archivo1.close();//cierra archivo fuente
}

void desencriptar(string fuente, int clavePublica, string destino)//funcion que encripta un texto con la clave publica
{
	string texto; //texto del archivo fuente(encriptado)
	string textoDesencriptado;
	string linea;
	int carAscii;
	char carLetra;
	ifstream archivo1;
	ofstream archivo2;
	archivo1.open(fuente.c_str());
	if(!archivo1.is_open())
		cout << "No se puede abrir el archivo: " << fuente << endl;
	else{
		while(getline(archivo1,linea)){
			texto = texto + linea;
		}
		int largo = texto.size();
		for(int contador=0; contador<largo; contador++){//traduce cada caracter ASCII y lo desencripta
			carAscii = texto[contador];
			carAscii = operar(carAscii, clavePublica, modulo, 3); //multiplica cada caracter con la clave privada
			carLetra = carAscii;
			textoDesencriptado += carLetra;
		}
		archivo2.open(destino.c_str());
		if(!archivo2.is_open())
			cout << "No se puede abrir el archivo: " << destino << endl;
		else
			archivo2 << textoDesencriptado; //guarda el texto desencriptado en el archivo destino
		archivo2.close();
	}
	archivo1.close();
}

int main()
{
	int clavePrivada;
	int clavePublica;
	string textoPlano;
	string textoCifrado;
	string textoDescifrado;
	cout<<"ENCRIPTADOR DE TEXTO"<<endl;
	cout<<endl;
	cout<<"CIFRADO: "<<endl;
	cout<<"Ingrese el nombre del archivo de texto: ";
	cin>> textoPlano;
	cout<<"Ingrese el nombre del archivo donde guardara el texto cifrado: ";
	cin>> textoCifrado;
	cout<<"Ingrese su clave privada: ";
	cin>> clavePrivada;
	encriptar(textoPlano, clavePrivada, textoCifrado);
	cout<<endl;
	cout<<"DESCIFRADO: "<<endl;
	cout<<"Ingrese el nombre del archivo donde guardar el texto descifrado: ";
	cin>> textoDescifrado;
	cout<<"Ingrese su clave publica: ";
	cin>> clavePublica;
	desencriptar(textoCifrado, clavePublica, textoDescifrado);
}


//
//int main(int argc, char *argv[])
//{
//	int numero1;
//	int numero2;
//	int modulo;
//	int operacion;
//	cout<< "Ingrese el primer numero: ";
//	cin>> numero1;
//	cout<< "Ingrese el segundo numero: ";
//	cin>> numero2;
//	cout<< "Ingrese el modulo de la operacion: ";
//	cin>> modulo;
//	cout<< "1.Suma"<<"\n";
//	cout<< "2.Resta"<<"\n";
//	cout<< "3.Multiplicacion"<<"\n";
//	cout<< "Ingrese el numero de la operacion que desea realizar: ";
//	cin>> operacion;
//	cout<< "\n";
//	cout<< "Resultado: "<< operar(numero1, numero2, modulo, operacion);
//	cout<< "\n";
//	return 0;
//}
