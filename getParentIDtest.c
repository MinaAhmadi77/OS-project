#include "types.h"
#include "stat.h"
#include "user.h"
#include "stddef.h"




int main (){

    int pid;
    pid=fork();
    
    if(pid == 0){

       printf(1,"This is process %d and the parent id is %d \n",getpid(),getParentID());
       
       if(fork()){
          
           wait(NULL,NULL,NULL);

       }else{

         printf(1,"This is process %d and the parent id is %d \n",getpid(),getParentID());

       }
        
       }
    if(pid>0){
      
        
        wait(NULL,NULL,NULL);
        pid=fork();
        
        if(pid == 0){

          printf(1,"This is process %d and the parent id is %d \n",getpid(),getParentID());
            if(fork()){
            
                wait(NULL,NULL,NULL);

            }else{

                printf(1,"This is process %d and the parent id is %d \n",getpid(),getParentID());

             }
         
         }

        if(pid>0){
            
            wait(NULL,NULL,NULL);
        }
    
       }
      

    exit();
}