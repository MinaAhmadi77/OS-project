#include "types.h"
#include "stat.h"
#include "user.h"

int counter=0;
int CBT=0;
int turnaround=0;
int waiting=0;

int function(){

    
    int pid;
    int id,cbt,turnaroundtime,waitingtime;

    pid=fork();
    
    if(pid == 0){

      for(int i=0 ; i<5 ; i++){

                
                id=getpid();
                cbt=cpuBurstTime();
                turnaroundtime=turnAroundTime();
                waitingtime=waitingTime();
                printf(1,"/pID:%d/ : /i:%d/  \n ",id,i);
                printf(1,"CBT = %d - Turnaround time = %d - Waiting time = %d \n",cbt,turnaroundtime,waitingtime);
                CBT+=cbt;
                turnaround+=turnaroundtime;
                waiting+=waitingtime;


            }
       
        
       }
    if(pid>0){
      
        wait();
        counter++;
        if(counter<10){

            function();

        }else{
         printf(1,"average CBT = %d - average Turnaround time = %d - average Waiting time = %d \n",CBT/10,turnaround/10,waiting/10);
         exit();
        }

        
    }
      

    return 0;





}

int main (){


    changePolicy(1);
    function();
    
        
    exit();
}