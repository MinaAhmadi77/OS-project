#include "types.h"
#include "stat.h"
#include "user.h"
#include "stddef.h"


int CBT=0;
int turnaround=0;
int waiting=0;
int counter=0;

int layerTimes[3][4];



void printChild(int id){

     for(int i=1 ; i<251 ; i++){

         printf(1,"/ChildNumber=%d/ : /i=%d/  \n ",id,i);
                
      }
}

void do_parent(int childQnumber,int c[],int t[],int w[],int cbt, int turnaroundtime,int waitingtime){
            



            layerTimes[0][childQnumber]+=cbt;
            layerTimes[1][childQnumber]+=turnaround;
            layerTimes[2][childQnumber]+=waitingtime;

            CBT+=cbt;
            turnaround+=turnaroundtime;
            waiting+=waitingtime;
            
            c[counter]=cbt;
            t[counter]=turnaroundtime;
            w[counter]=waitingtime;
            counter++;


}

int main(){

    
    int parentID=getpid();
    int id;
    int cbt,turnaroundtime,waitingtime;
    int childQnumber;
    int c[100];
    int t[100];
    int w[100];
    
   
    
    for(int j=1 ; j<=4 ; j++){
        
        for(int i=0 ; i<10 ; i++){
        
            if(parentID==getpid()){
                id=fork();


                if (id == 0){

                   setPriority(10-i);
                   setQueqeNumber(j);
                  
                   
                    
                }

            }
        }
        
    }

    if(parentID==getpid()){

        for(int j=0 ; j<40 ; j++){
            
            childQnumber=wait(&cbt,&turnaroundtime,&waitingtime);
            do_parent(childQnumber,c,t,w,cbt,turnaroundtime,waitingtime);
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

    for(int i=1;i<=4;i++){
        printf(1,"\nQUEQE i=%d average CBT = %d - average Turnaround time = %d - average Waiting time = %d \n",i,(layerTimes[0][i]/10),(layerTimes[1][i]/10),(layerTimes[2][i]/10));

    }
   






    exit();
}