#include <stdio.h>
#include <stdlib.h>

//devuelve menor a 0 si es mayor, 0 si son iguales y menor a 0 si es menor

int strncmp(char *s,char *t,int n){
    for(;n!=0 && *s==*t;s++,t++){ //compara  s y t hasta el final
        if(*s=='\0')
            return 0;
        n--;
    }
    return *s-*t; 
}

int main()
{
    char s[]="abc";
    char t[]="abce";
    printf("%d",strncmp(s,t,4));
}
