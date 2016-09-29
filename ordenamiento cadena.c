#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenar(char *d){
    char **p =&*d; char **s=&*(d+1);
    char temp[]="";
    while ( *(d +1) != '/0' ){
        if ( **p -'a' >=  **s - 'a'){
            p++;
            s++;
        }
        else{
            strcpy (temp, *d);
            strcpy(*d , *(d+1));
            strcpy(*(d+1),temp);
        }
        d++;
}
}


int main(){
    char *b[]={"abd","abc","aba"};
    ordenar(b);
    return 0;
}
