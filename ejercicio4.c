#include <stdio.h>
#include <stdlib.h>
int invertir(char s[],int i)
{
   if (s[i]=='\0')
   {
     return 0;
   }
   else{
       i++;
      invertir (s,i);
      putchar(s[i-1]);
}
}
int main()
{
   char s[9]="holallolololo";
   int i =0;
   invertir(s,i);
   return 0;
}



