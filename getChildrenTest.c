#include "types.h"
#include "stat.h"
#include "user.h"
#include "stddef.h"


int main (){

   
    //int pid,parentID;
    //int lock;
    //struct proc *curproc = myproc();

    for(int i=1 ; i<=5 ; i++){

        ///pid=getpid();

       if(fork()== 0){

           //pid=getpid();
           //parentID=getParentID();
           //acquire(&mylock.lock);
           int * children=NULL;
           int * p=NULL;
           p=children;
           children=getChildren();
           printf(1,"This is process %d ",getpid());
           printf(1," and children are ");
           for(int i=0 ; i<(sizeof(children)/sizeof(int *))-1;i++){

               printf(1,"%d/",*p);
               p+=sizeof(int);
           }
            printf(1,"%d",*p);
            p+=sizeof(int);
           
           //release(&mylock.lock);

       }

    }


    /* wait for all child to terminate */
    while(wait() != -1) { }

    /* give time to parent to reach wait clause */
    sleep(1);

    exit();

    return 0;
}