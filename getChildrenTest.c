#include "types.h"
#include "stat.h"
#include "user.h"
#include "stddef.h"

void printChildren(){

    int children=getChildren();
   // printf(1,"children integer= %d ,\n",children);
    while(children/100 != 0){

        printf(1,"%d/",children%100);
        children/=100;
    }
    printf(1,"%d\n",children);

}

int main (){

   // int ppid=getpid();
   // printf(1,"im root %d \n",getpid());
    int pid=fork();

    
    if(pid>0){
        
        pid=fork();

        if(pid>0){
            
            pid=fork();
            
            if(pid>0){
               
                printf(1,"This is process %d and children are ",getpid());
                printChildren();
            }
        }
        
                    
       }  
      while(wait(NULL,NULL,NULL)!=-1){}
      sleep(1);

    exit();
}