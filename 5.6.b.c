#include <stdio.h>
#include <stdlib.h>

void reverse(char s[]){
    char temp,*p,*t;
    p=&s[0];
    t=&s[0];
    while(*p!='\0')
        p++;
    p--;
    while(t<p){
        temp=*t;
        *t=*p;
        *p=temp;
        t++;
        p--;
    }
}

int main()
{
    char s[]="abcde";
    reverse(s);
    printf("%s",s);
}

