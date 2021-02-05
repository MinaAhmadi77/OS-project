#include "types.h"
#include "stat.h"
#include "user.h"
#include "stddef.h"

void printChildren(){

    int children=getChildren();
    while(children/100 != 0){

        printf(1,"%d - ",children%100);
        children/=100;
    }
    printf(1,"%d\n",children);

}

int main (){

    //int ppid=getpid();
    //printf(1,"im root %d \n",getpid());


    /*    if(fork()){

            if(fork()){

                if(fork()){

                    printf(1,"pid2:This is process %d and children are ",getpid());
                    printChildren();
                }
            }
        }*/





    int pid2;
    int pid=fork();

    if(pid==0){
        sleep(100);
    }
    
    if(pid>0){
        
        pid2=fork();
        
        if(pid2==0){

            sleep(100);
         }

        if(pid2>0){
            
           
            printf(1,"pid2:This is process %d and children are ",getpid());
            int children=getChildren();
            wait();
             while(children/100 != 0){

                printf(1,"%d - ",children%100);
                children/=100;
            }
            printf(1,"%d\n",children);
           
        }
            
       }   

    exit();
}