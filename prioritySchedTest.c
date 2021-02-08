#include "types.h"
#include "stat.h"
#include "user.h"
#include "stddef.h"


int CBT=0;
int turnaround=0;
int waiting=0;
int counter=0;

int classTimes[3][6];



void printChild(int id){

     for(int i=1 ; i<251 ; i++){

         printf(1,"/ChildNumber=%d/ : /i=%d/  \n ",id,i);
                
      }
}

void do_parent(int childPrio,int c[],int t[],int w[],int cbt, int turnaroundtime,int waitingtime){
            
    
            classTimes[0][childPrio]+=cbt;
            classTimes[1][childPrio]+=turnaround;
            classTimes[2][childPrio]+=waitingtime;

            CBT+=cbt;
            turnaround+=turnaroundtime;
            waiting+=waitingtime;
            
            c[counter]=cbt;
            t[counter]=turnaroundtime;
            w[counter]=waitingtime;
            counter++;


}

int main(){

    changePolicy(2);
    int parentID=getpid();
    int id;
    int cbt,turnaroundtime,waitingtime;
    int childPrio;
    int c[100];
    int t[100];
    int w[100];
    
   
    
    for(int j=1 ; j<=6 ; j++){
        
        for(int i=0 ; i<5 ; i++){
        
            if(parentID==getpid()){
                id=fork();


                if (id == 0){

                   setPriority(7-j);
                  
                   
                    
                }

            }
        }
        
    }

    if(parentID==getpid()){

        for(int j=0 ; j<30 ; j++){
            
            childPrio=wait(&cbt,&turnaroundtime,&waitingtime);
            do_parent(childPrio,c,t,w,cbt,turnaroundtime,waitingtime);
        }
       // printf(1,"\n\n\n\n");


    }else{

        printChild(getpid());
        exit();



    }

     for(int i=0; i<counter ; i++){
        
            printf(1,"final results: CBT = %d -  Turnaround time = %d - Waiting time = %d \n",c[i],t[i],w[i]);
        
        }

        printf(1,"\n\n\naverage CBT = %d - average Turnaround time = %d - average Waiting time = %d \n",(CBT/30),(turnaround/30),(waiting/30));

    for(int i=1;i<6;i++){
        printf(1,"\nclass i=%d average CBT = %d - average Turnaround time = %d - average Waiting time = %d \n",i,(classTimes[0][i]/5),(classTimes[1][i]/5),(classTimes[2][i]/5));

    }
   






    exit();
}