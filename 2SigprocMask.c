/*
sigprocmask()  is  used to fetch and/or change the signal mask of the calling thread.  The signal mask is the set of signals whose delivery
       is currently blocked for the caller (see also signal(7) for more details).

       The behavior of the call is dependent on the value of how, as follows.

       SIG_BLOCK
              The set of blocked signals is the union of the current set and the set argument.

       SIG_UNBLOCK
              The signals in set are removed from the current set of blocked signals.  It is permissible to attempt to unblock a signal  which  is
              not blocked.

       SIG_SETMASK
              The set of blocked signals is set to the argument set.

       If oldset is non-NULL, the previous value of the signal mask is stored in oldset.

       If set is NULL, then the signal mask is unchanged (i.e., how is ignored), but the current value of the signal mask is nevertheless returned
       in oldset (if it is not NULL).


*/
#include	<signal.h>
#include	<stdlib.h>
#include	<stdio.h>

void err_sys(char* str)
{
	perror(str);
	exit(-1);
}

static void	sig_quit(int);

int main(void)
{
	sigset_t newmask, oldmask, pendmask;

	if (signal(SIGQUIT, sig_quit) == SIG_ERR)
		err_sys("can't catch SIGQUIT");

	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);
		/* block SIGQUIT and save current signal mask */
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("SIG_BLOCK error");
	/* critical section starting*/

	sleep(5);		/* SIGQUIT here will remain pending */

	if (sigpending(&pendmask) < 0)
		err_sys("sigpending error");
	if (sigismember(&pendmask, SIGQUIT))
		printf("\nSIGQUIT pending\n");

	/*critical section ending*/

		/* reset signal mask which unblocks SIGQUIT */
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("SIG_SETMASK error");
	printf("SIGQUIT unblocked\n");

	sleep(5);		/* SIGQUIT here will terminate with core file */

	exit(0);
}

static void
sig_quit(int signo)
{
	printf("caught SIGQUIT\n");
	if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
		err_sys("can't reset SIGQUIT");
	return;
}

