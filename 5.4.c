#include <stdio.h>
int strend(char *b, char *c){
	int i = 0;
	int j=0;
	while((*(b+i)!= '\0'))
         i++;
    while(*(c+j) != '\0')
        j++;
    if (j>i)
        return 0;
	while( i>=0 && j>=0 ){
        if(*(b + i) != *(c + j))
            return 0;
        i--;
        j--;
    }
    return 1;
}

int main(){
    char b[] = "Hola";
	char c[]= "Hila";
	printf("%i",strend(b,c));
}
