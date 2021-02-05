#include "types.h"
#include "stat.h"
#include "user.h"




int main (){

    int pid;
    pid=fork();
    
    if(pid == 0){

       printf(1,"This is process %d and the parent id is %d \n",getpid(),getParentID());
       
        
       }
    if(pid>0){
      
        wait();
        pid=fork();
        if(pid == 0){

          printf(1,"This is process %d and the parent id is %d \n",getpid(),getParentID());
         
         }
        if(pid>0){

            wait();
        }
    
       }
      

    exit();
}