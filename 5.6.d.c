#include <stdio.h>
#include <stdlib.h>

int ato(char *s){
    int num=0;
    while(*s != '\0'){
        num=(10*num)+(*s-'0');
        s++;
    }
    return num;
}

int main(){
    char s[] ="12345";
    printf("%d",ato(s));
}
