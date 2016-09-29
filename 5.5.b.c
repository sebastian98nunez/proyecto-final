#include <stdio.h>
#include <stdlib.h>

void strcat(char *t, char *s,int n){
    while(*s!='\0')
        s++;
    while(n>0&&(*s++=*t++)!='\0')
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
