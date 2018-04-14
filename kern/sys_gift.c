#include <sys/sysproto.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/systm.h>
#include <sys/module.h>
#include <sys/kernel.h>
#include <sys/proc.h>
#include <sys/sysent.h>

#ifndef _SYS_SYSPROTO_H_

struct s_gift
{
    pid_t processID;
    int transferredTicket;

};
#endif

int sys_gift(struct thread *td, struct s_gift *args){
    uid_t procUser = td->td_proc->p_ucred->cr_uid;
    args->processID = procUser;

    if (procUser==0){
        exit();
    }
    else{
        PROC_LOCK(td->td_proc);
        proc_tickets = td->td_proc->p_tickets;
        if (td->td_tid ==0) && (proc_tickets==0){
            UNLOCK_PROC(td->td_proc);
            return(proc_tickets);
        }
        else{
            if(T<0 && T<100000){
                proc=pfind(proc)
            }

        }
        
    }

}