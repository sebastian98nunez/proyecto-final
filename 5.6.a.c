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
    strcat(t,s);//compara 2 cadenas
    printf("%s",s);
}

