#include <stdio.h>
#include <stdlib.h>
int lower(char letra)
{
  int m = 'A' + letra - 'a' ;
  return m;
}




int main()
{
    char let ;
    printf("Ingrese la minuscula que desea convertir: \n ");
    scanf("%c", &let);
    printf("la letra mayuscula es %c", lower(let));
    return 0;
}
