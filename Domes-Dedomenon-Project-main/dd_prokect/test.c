#include<stdio.h>
#include<stdlib.h>


int main(void){
    char ean[15];
    scanf("%s",ean);
    long long int a=atoll(ean);
    printf("%lld\n",a);
return 0;
}
