#include "types.h"
#include "stat.h"
#include "user.h"
#include "stddef.h"


int CBT=0;
int turnaround=0;
int waiting=0;


int main(){
   
    changePolicy(1);
    int counter=0;
    int parentID=getpid();
    int cbt,turnaroundtime,waitingtime;
    int childID;
    int c[100];
    int t[100];
    int w[100];



     for(int i=0 ; i<10 ;i++){

        if(parentID==getpid())
                    fork();
        
     }
     
    if(parentID==getpid()){

        for(int j=0 ; j<10 ; j++){
            childID=wait(&cbt,&turnaroundtime,&waitingtime);
            printf(1,"childID %d  - CBT = %d - Turnaround time = %d - Waiting time = %d \n",childID,cbt,turnaroundtime,waitingtime);
            CBT+=cbt;
            turnaround+=turnaroundtime;
            waiting+=waitingtime;
            c[counter]=cbt;
            t[counter]=turnaroundtime;
            w[counter]=waitingtime;
            counter++;
        }
        printf(1,"\n\n\n\n");

    }else{


        for(int i=0 ; i<100 ; i++){

         printf(1,"/pID:%d/ : /i:%d/  \n ",getpid(),i);
                
            }
        exit();

    }
    while(wait(NULL,NULL,NULL) != -1) { }
        
      sleep(1);

      for(int i=0; i<counter ; i++){
        
            printf(1,"final results= CBT = %d -  Turnaround time = %d - Waiting time = %d \n",c[i],t[i],w[i]);
        
        }

        printf(1,"\n\n\naverage CBT = %d - average Turnaround time = %d - average Waiting time = %d \n",(CBT/10),(turnaround/10),(waiting/10));


    exit();
}





