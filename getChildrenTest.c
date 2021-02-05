#include "types.h"
#include "stat.h"
#include "user.h"
#include "stddef.h"

void printChildren(){

    int children=getChildren();
    //printf(1,"%d children first=",children);
    while(children/100 != 0){

        printf(1,"%d - ",children%100);
        children/=100;
    }
    printf(1,"%d\n",children);

}



int main (){

    int pid;
    pid=fork();
    
    if(pid == 0){


       printf(1,"This is process %d and children are ",getpid());
       printChildren();
       
        
       }
    if(pid>0){
      
        wait();
        pid=fork();
        
        if(pid == 0){

          printf(1,"This is process %d and children are ",getpid());
          printChildren();
         
         }
        if(pid>0){

            wait();
        }
    
       }
      

    exit();

    

}