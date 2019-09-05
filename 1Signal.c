#include<signal.h>
#include<stdio.h>
#include<string.h>

void main()
{
    printf("%d\n",SIGRTMAX);
    printf("%d\n",SIGRTMIN);
    for(int i=0;i<=SIGRTMAX;i++)
        printf("%s\n",strsignal(i));
}