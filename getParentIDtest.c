#include "types.h"
#include "stat.h"
#include "user.h"
#include "spinlock.h"

int main (){

    struct spinlock lk;
    //int pid,parentID;
    //int lock;

    for(int i=1 ; i<=5 ; i++){

        ///pid=getpid();

       if(fork()== 0){

           //pid=getpid();
           //parentID=getParentID();
           //printf(1,"im child \n");
           initlock(&lk, "lk");
           //printf(1,“\n This is process %d and the parent id is %d \n”,pid,parentID);
           acquire(&lk);
           printf(1,"This is process %d ",getpid());
           printf(1,"and the parent id is %d \n",getParentID());
           release(&lk);

       }

    }


    /* wait for all child to terminate */
    while(wait() != -1) { }

    /* give time to parent to reach wait clause */
    sleep(1);

    exit();

    return 0;
}