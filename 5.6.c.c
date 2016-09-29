#include <stdio.h>
#include <stdlib.h>

int getline(char *s){
    int cont=0;
    while(*s++!='\0')
        cont++;
    return cont;
}

int main()
{
    char s[]="abc";
    printf("%d",getline(s));
}


