#include <stdio.h>
#include <stdlib.h>
int strindex(char s[],char t)
{
    int i = 0;
    int m = 0;
    for( m =0 ; s[m] != '\0'; m++)
    {
         if(s[m] == t)
            i=m;
    }

    if (i ==0)
       return -1;
    else
        return i;
}

int main()
{
    char s[8]={'h', 'o', 'l','o','\0'};
    char t = 'o';
    printf("la posicion de t en s es: %d" , strindex(s,t));
    return 0;
}
