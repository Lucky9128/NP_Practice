#include<signal.h>
#include<stdio.h>
#include<string.h>

void main()
{
    printf("%d\n",NSIG);
    for(int i=0;i<=65;i++)
        printf("%s\n",strsignal(i));
}