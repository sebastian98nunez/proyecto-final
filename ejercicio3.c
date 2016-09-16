#include <stdio.h>

int convertir(char a[])
{
    int i,num,num2,value=0;
    for (i=0;a[i]!='\0';i++){
        if(a[i]!='e'&&value==0)
            num= 10*num +(a[i]-'0');
        else{
            if (a[i]=='e'||a[i]=='-'){
                value+=1;
                continue;}
            else{
                num2= 10*num2 +(a[i]-'0');
            }
        }
    }
    while (num2!=0&&value==2){
        num=num/10;
        num2--;
    }
    while (num2!=0&&value==1){
        num=num*10;
        num2--;
    }
    return num;
}

int main()
{
    char a[] = "1234e-5" ;
    printf("%d",convertir(a));
    return 0;
}

