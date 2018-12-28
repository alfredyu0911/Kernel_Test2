#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/syscalls.h>
#include <linux/linkage.h>
#include <linux/sched.h>
#include <linux/time.h>

asmlinkage void sys_linux_projectII(unsigned int *contextSwitches, time_t *idleTime, time_t *existTime)
{
    struct task_struct *task = pid_task(find_vpid(current->pid), PIDTYPE_PID);
    if ( !task )
    {
        printk("{[(ayumsg)]} task not found !!!\n");
        return -1;
    }

    printk("{[(ayumsg)]} info : [%lu, %lu, %lu]\n", task->switchCounter, task->idleTimes.tv_usec, task->createTime.tv_usec);

    struct timeval currentTime;
    do_gettimeofday(&currentTime);

    *contextSwitches = task->switchCounter;
    *idleTime = task->idleTimes.tv_usec;
    *existTime = currentTime.tv_usec - task->createTime.tv_usec;
}