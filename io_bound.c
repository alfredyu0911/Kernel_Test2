#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define SYSTEM_CALL_ID 359
#define TOTAL_IO_NUM 100000

main()
{
    FILE *out;
    char c;

    if ( ( out=fopen("io_bound.data","w")) != NULL )
    {
        c = 38;
        int a;
        for ( a=0 ; a < TOTAL_IO_NUM ; a++ )
        {
            putc(c,out);
            if ( ++c > 126 )
            c=38;
        }
        fclose(out);
    }
    else
    {
        printf("Cannot open file.\n");
        exit(0);
    }

    unsigned int cs_counter;
    struct timeval idle, exist;

    syscall(SYSTEM_CALL_ID, &cs_counter, &idle, &exist);

    printf("The process spent %ld uses in the system after it stated its execution.\n", (exist.tv_sec * 1000000 + exist.tv_usec));

    printf("The process has made %ld process switches\n", cs_counter);
    printf("This process has idle %lu usecs\n", idle.tv_sec * 1000000 + idle.tv_usec); 
}