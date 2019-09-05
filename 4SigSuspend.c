/*
Temporarily  replaces  the signal mask of the calling process with the mask given by mask and then suspends the process until
       delivery of a signal whose action is to invoke a signal handler or to terminate a process.
*/

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>

void sighand(int a)
{

}

int main ()
{
  int i = 0, j = 0; 
  pid_t ret;
  int status;
  ret = fork ();
  signal(SIGUSR1,sighand);
  sigset_t new,old;
  sigemptyset(&old);
  sigaddset(&new,SIGUSR1);
  sigprocmask(SIG_BLOCK,&new,&old);
  if (ret == 0)
    {
      for (i = 0; i < 50; i++)
      {
          printf ("Child: %d\n", i);
          kill(getppid(),SIGUSR1);
          sigsuspend(&old);
      } 
      printf ("Child ends\n");
    }
  else
    {
      for (i = 0; i < 50; i++)
      {
          sigsuspend(&old);
          printf ("Parent: %d\n", i);
          kill(ret,SIGUSR1);
      } 
        printf ("Parent: %d\n", j);
    }
}