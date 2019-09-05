//Using different exec__ : l/v  : p/e ;

#include<stdio.h>
#include<stdlib.h>

extern char **environ;
void main()
{
    char *const arg[] = {"./1","Lucky","hello",NULL};//NULL is necessary
    char *const env[] = {"./1","Lucky","hello",NULL};//NULL is necessary
//    execl("/home/lucky/Documents/Bits ME Sem1/NP/Practice/1","./1","Lucky","Hello",(char *)NULL);
//   execlp("/home/lucky/Documents/Bits ME Sem1/NP/Practice/1",".1/","Lucky","Hello",(char *)NULL);
//   execle("/home/lucky/Documents/Bits ME Sem1/NP/Practice/1",".1/","Lucky","Hello",(char *)NULL,arg);
//    execv("/home/lucky/Documents/Bits ME Sem1/NP/Practice/1",arg);
//   execvp("/home/lucky/Documents/Bits ME Sem1/NP/Practice/1",arg);
  execve("/home/lucky/Documents/Bits ME Sem1/NP/Practice/1",arg,env);
//    errExit("excev");
}