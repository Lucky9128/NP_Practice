/*Accessing environment variable ::
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
extern char **environ;

void main()
{
    char **ep;
    for(ep=environ;*ep!=NULL;ep++)
        printf("%s\n",*ep);
    // exit(0);

    printf("Username -> %s\n",getenv("USER"));
    setenv("USER","Swastik",1);
    printf("Modified user name -> %s\n",getenv("USER"));
    unsetenv("USER");
    printf("No user name -> %s\n",getenv("USER"));
    environ=NULL;    
}