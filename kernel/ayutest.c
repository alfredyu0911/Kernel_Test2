#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/syscalls.h>
#include <linux/linkage.h>
#include <linux/sched.h>
#include <time.h>

asmlinkage void sys_linux_projectII(int pid, unsigned int *contextSwitches, time_t *idleTime, time_t *existTime)
{
    struct task_struct *task = pid_task(find_vpid(pid), PIDTYPE_PID);
    if ( !task )
    {
        printk("{[(ayumsg)]} task not found !!!\n");
        return -1;
    }

    printk("{[(ayumsg)]} info : [%lu, %lu, %lu]\n", task->switchCounter, task->idleTimes, task->createTime);

    *contextSwitches = task->switchCounter;
    *idleTime = task->idleTimes;
    *existTime = time(NULL) - task->createTime;
}