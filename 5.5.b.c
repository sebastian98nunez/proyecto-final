#include <stdio.h>
#include <stdlib.h>

void strcat(char *t, char *s,int n){
    while(*s!='\0') //leva al fin de s
        s++;
    while(n>0&&(*s++=*t++)!='\0')//reemplaza de t a s
        n--;
    *s='\0';
}

int main()
{
    char s[]="abc";
    char t[]="zxc";
    strcat(t,s,1);//se copia de t a s
    printf("%s",s);
}
