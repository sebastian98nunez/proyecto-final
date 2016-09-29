#include <stdio.h>

char stridex(char *a){
	char *p;
	p = &a;
	*p -=('a'-'A');
	return *p;
}
int main()
{
    char let ;
    printf("Ingrese la minuscula que desea convertir: \n ");
    scanf("%c", &let);
    printf("la letra mayuscula es %c", stridex(let));
    return 0;
}
