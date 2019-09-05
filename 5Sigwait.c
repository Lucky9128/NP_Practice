/*sigwaitinfo() suspends execution of the calling thread until one of
       the signals in set is pending (If one of the signals in set is
       already pending for the calling thread, sigwaitinfo() will return
       immediately.)*/
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

void main()
{
    sigset_t sid;
    siginfo_t *si;
    sigfillset(&sid);
    sigprocmask(SIG_SETMASK,&sid,NULL);
    int k = sigwaitinfo(&sid,si);
    printf("\n%d\n",k);
    printf("\n%s\n",strsignal(k));
}