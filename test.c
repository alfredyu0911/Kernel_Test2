#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <time.h>
#include <sys/time.h>

#define SYSTEM_CALL_ID 359
#define TOTAL_CALCUATE_NUM 100000000
#define TOTAL_IO_NUM 100000

void do_io()
{
    FILE *out;
    char c;
    int a;

    if ( ( out = fopen("io_bound.data","w") ) != NULL )
    {
        c = 38;
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
}

void do_calc()
{
    int i, a;
    for ( i=1 ; i <= TOTAL_CALCUATE_NUM ; i++ )
        ++a;
}

void main(int argc, char *argv[])
{
    if ( argc != 2 )
        return;
    
    if ( strcmp(argv[1], "-io") == 0 )
        do_io();
    else if ( strcmp(argv[1], "-cpu") == 0 )
        do_calc();
    else
        return;

    /*===========================================================================*/
    /*     prototype of the new system call is as follows                        */
    /*     void get_process_switch_info(struct process_switch_info *)            */
    /*===========================================================================*/

    unsigned int cs_counter;
    struct timeval idle, exist;

    syscall(SYSTEM_CALL_ID, &cs_counter, &idle, &exist);

    printf("The process spent %ld uses in the system after it stated its execution.\n", (exist.tv_sec * 1000000 + exist.tv_usec));

    // temp_ul=(ps_info.time.tv_sec * 1000000 + ps_info.time.tv_usec);
    printf("The process has made %ld process switches\n", cs_counter);
    printf("This process has idle %lu usecs\n", idle.tv_sec * 1000000 + idle.tv_usec); 
}