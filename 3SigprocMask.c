#include	<signal.h>
#include	<stdlib.h>
#include	<stdio.h>
#include <string.h>

void err_sys(char* str)
{
	perror(str);
	exit(-1);
}

static void	sig_quit(int);

void display(sigset_t n1,sigset_t n2);
int
main(void)
{
	sigset_t	newmask, oldmask, pendmask;

	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);
    sigprocmask(SIG_BLOCK,&newmask,&oldmask);
    display(newmask,oldmask);
    sigprocmask(SIG_UNBLOCK,&newmask,&oldmask);
    display(newmask,oldmask);
    sigaddset(&newmask,SIGUSR1);
    sigprocmask(SIG_SETMASK,&newmask,&oldmask);
    display(newmask,oldmask);
	exit(0);
}

void display(sigset_t n1,sigset_t n2)
{
    printf("Oldmask\n");
    for(int i=1;i<_NSIG;i++)
        if(sigismember(&n2,i))
            printf("%s\n",strsignal(i));
    printf("NewMask:\n");
    for(int i=1;i<_NSIG;i++)
        if(sigismember(&n1,i))
            printf("%s\n",strsignal(i));
}
static void
sig_quit(int signo)
{
	printf("caught SIGQUIT\n");

	if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
		err_sys("can't reset SIGQUIT");
	return;
}

