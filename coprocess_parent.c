#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/signal.h>

#define MAXSIZE 100

main ()
{

  int p1[2], p2[2];
  int ret;
  char line[MAXSIZE], result[MAXSIZE];

  pipe (p1);
  pipe (p2);  


  ret = fork ();
  if (ret == 0)
    {
      close (p1[1]);
      close (p2[0]);

      dup2 (p1[0], 0);
      dup2 (p2[1], 1);
      execl ("./V", "V", (char *) 0);

    }
  else
    {
      close (p1[0]);
      close (p2[1]);

       FILE *fpi, *fpo;
      fpi = fopen ("emails.txt", "r");
      fpo = fopen ("emails_validation.txt", "w");

      while (fgets (line, MAXSIZE, fpi) != NULL)
      {
        write (p1[1], line, strlen (line));
        read (p2[0], result, MAXSIZE);
        // printf("%s\n",result);
        fprintf (fpo, "%s,%d\n", line, atoi (result));
       
      }

      fclose(fpi);
      fclose(fpo);

    }

}
