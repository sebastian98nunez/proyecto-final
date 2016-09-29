#include <stdio.h>
#include <stdlib.h>

void strncat(char *t, char *s, int n){
    while(*s!='\0') //leva al fin de cadena
        s++;
    while(n!=0&&(*s++=*t++)!='\0')// reemplaza caracteres de t a s hasta fin de caddena
        n--;
    *s='\0';
}

int main()
{
    char s[]="abc";
    char t[]="defgffdh";
    strncat(t,s,1);
    printf("%s",s);
}
