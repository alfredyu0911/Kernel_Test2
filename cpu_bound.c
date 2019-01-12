#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define SYSTEM_CALL_ID 359
#define TOTAL_CALCUATE_NUM 100000000

main()
{
    int a;
    unsigned int i=0;

    for ( i=1 ; i<= TOTAL_CALCUATE_NUM ; i++ )
        ++a;
        
    unsigned int cs_counter;
    struct timeval idle, exist;

    syscall(SYSTEM_CALL_ID, &cs_counter, &idle, &exist);

    printf("The process spent %ld uses in the system after it stated its execution.\n", (exist.tv_sec * 1000000 + exist.tv_usec));

    printf("The process has made %ld process switches\n", cs_counter);
    printf("This process has idle %lu usecs\n", idle.tv_sec * 1000000 + idle.tv_usec); 
}