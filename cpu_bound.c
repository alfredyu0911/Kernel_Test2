#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define TOTAL_ITERATION_NUM  100000000

struct process_switch_info
{
    unsigned int   counter;
    struct timeval time;
};

main()
{
    int              a;
    unsigned int     i=0;
    struct timeval   start, end;

    gettimeofday(&start, NULL);           //total time of existence - begin

    for(i=1;i<=TOTAL_ITERATION_NUM;i++)
        ++a;

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