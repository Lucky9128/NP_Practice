//will print number of agrumnets passed along with arguments:

#include<stdio.h>
#include<stdlib.h>
extern char **environ;

void main(int arg, char *argv[])
{
    int abc =0;
    char **ep=environ;
    while(abc<arg)
    {
        printf("Argument Number : %d -> %s\n",abc++,argv[abc]);
    }
    printf("Environment Variables : \n");
    while(*ep!=NULL)
    {   
        printf("%s\n",*ep++);
    }
}
