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
void qsort(char **ptr, int left , int right ){
	int i,last;
	void swap(char **ptr , int i , int j);

	if (left > right)
		return;
	swap( ptr , left , (left+ right) /2);
	last=left;
	for( i= left+1 ; i <= right ; i++);
	swap(ptr,left,last);
	qsort(ptr,left,last-1);
	qsort(ptr,last+1,right);
	}

void swap(char *ptr , int i , int j){
	char temp[];
	strcpy(temp,*(ptr+i));
	strcpy(*(ptr+i),*(ptr+j));
	strcpy(*(ptr+j),temp);
}

int main()
    char *c[]={"hola", "juan","pedro", "roberto"}
    qsort(c,0,3)


int main(){
    char *b[]={"abd","abc","aba"};
    ordenar(b);
    return 0;
}
