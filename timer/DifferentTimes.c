#include<sys/time.h>
#include<sys/times.h>
#include<stdio.h>

void main()
{
    struct timeval *tv;
    struct timezone *tz;
    time_t *tp;
    clock_t tcp = times(NULL);
    int k = gettimeofday(tv,tz);
    // for(int i=0;i<=100;i++)
    // for(int j=0;j<=10000;j++)
    //     printf("0");
    printf("%ld\n",tv->tv_sec);
    printf("%ld\n",tv->tv_usec);
    printf("%ld\n",(tcp/100%3600));
}