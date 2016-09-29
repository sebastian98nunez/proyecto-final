#include <stdio.h>
#include <stdlib.h>

void strcat(char *t, char *s){
    while((*s++=*t++)!='\0')
        ;
}

int main()
{
    char s[]="abc";
    char t[]="adefgffdh";
    strcat(t,s);//se copia solo 2 caracteres de t a s
    printf("%s",s);
}

