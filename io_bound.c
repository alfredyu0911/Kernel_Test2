#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

struct process_switch_info
{
    unsigned int   counter;
    struct timeval time;
};


main()
{
    FILE             *out;
    char             c;
    int              a;
    struct timeval   start, end;

    gettimeofday(&start, NULL);                 //total time of existence - begin

    if((out=fopen("io_bound.data","w"))!=NULL)
    {
        c=38;
        for(a=0; a<100000;a++)
        {
            putc(c,out);
            if(++c>126)
            c=38;
        }
        fclose(out);
    }
    else
    {
        printf("Cannot open file.\n");
        exit(0);
    }

    // /*===========================================================================*/
    // /*     prototype of the new system call is as follows                        */
    // /*     void get_process_switch_info(struct process_switch_info *)            */
    // /*===========================================================================*/
    // get_process_switch_info(&ps_info);    //new system call

    // gettimeofday(&end, NULL);             //total time of existence - end
    // printf("The process spent %ld uses in the system after it stated its execution.\n", 
    // ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));

    // temp_ul=(ps_info.time.tv_sec * 1000000 + ps_info.time.tv_usec);
    // printf("The process has made %ld process switches\n", ps_info.counter);
    // printf("This process has idle %ul usecs\n", temp_ul); 
}