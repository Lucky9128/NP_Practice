#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/errno.h>

#define MSGSIZE 30
main ()
{
  int i;
  char *msg = "How are you?";
  char inbuff[MSGSIZE];
int rfd,wfd;

if(mkfifo("fifo",O_CREAT|O_EXCL|0666)<0)
	if(errno=EEXIST)
		perror("fifo");
if(mkfifo("fifo3",O_CREAT|O_EXCL|0666)<0)
	if(errno=EEXIST)
		perror("fifo");


  pid_t ret;
  ret = fork ();
  if (ret > 0)
    {  
     rfd=open("fifo", O_RDONLY);
     wfd=open("fifo3",O_WRONLY);
     long abc = fpathconf(wfd,_PC_PIPE_BUF);
     printf("%ld\n",abc);
  	i = 0;
      char buz[abc];
      for(long int i=0;i<abc+10;i++)
        buz[1];
      while (i < 10)
	{
	  write (wfd, buz, abc);
	  sleep (2);
	  read (rfd, buz,abc);
	  printf ("child: %s\n", inbuff);
	  i++;
	}
    exit(1);
    }
  else
    {
     wfd=open("fifo",O_WRONLY);
     rfd=open("fifo3", O_RDONLY); 
      i = 0;
      char buz[4097];
      while (i < 10)
	{
	  sleep (1);
	  read (rfd, buz, 4096);
	  printf ("parent: %s\n", inbuff);
	  write (wfd, "i am fine", strlen ("i am fine"));
	  i++;
	}
    }
  exit (0);
}