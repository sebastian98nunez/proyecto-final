#include <stdio.h>
#include <stdlib.h>

void strcat(char *t, char *s){//puntero a cadenas
    while(*s!='\0')//leva al final de la segunda cadena
        s++;
    while((*s++=*t++)!='\0')//iguala el elemento de la primera a la segunda hasta fin de cadena
        ;
}

int main()
{
    char s[]="hola ";
    char t[]="mundo";
    strcat(t,s);//del primero al segundo
    printf("%s",s);
}
