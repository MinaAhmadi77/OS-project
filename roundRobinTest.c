// #include "types.h"
// #include "stat.h"
// #include "user.h"

// int counter=0;
// int CBT=0;
// int turnaround=0;
// int waiting=0;




// // int function(int * ID){

    
// //     int pid;
// //     int id;
// //     int cbt,turnaroundtime,waitingtime;
// //     pid=fork();
    
// //     if(pid == 0){
        
// //         id=getpid();      

// //       for(int i=0 ; i<5 ; i++){

                
// //                 printf(1,"/pID:%d/ : /i:%d/  \n ",id,i);
                
// //             }
       
        
// //        }
// //     if(pid>0){
      
// //         *ID=&wait();
// //          ID++;
        
       
// //         counter++;
// //         if(counter<10){

// //             function(&ID);

// //         }else{
        
// //         printf(1,"J is %d\n",j);
// //          for(int k= 0 ; k<j ; k++){

            
// //             cbt=cpuBurstTime(ID[k]);
// //             turnaroundtime=turnAroundTime(ID[k]);
// //             waitingtime=waitingTime(ID[k]);
// //             printf(1,"index %d ID[k]=pid= %d CBT = %d - Turnaround time = %d - Waiting time = %d \n",k,ID[k],cbt,turnaroundtime,waitingtime);
// //             CBT+=cbt;
// //             turnaround+=turnaroundtime;
// //             waiting+=waitingtime;
// //          }


        
// //          printf(1,"average CBT = %d - average Turnaround time = %d - average Waiting time = %d \n",(CBT/10),(turnaround/10),(waiting/10));
// //          exit();
// //        //}

        
// //     }
      

// //     return 0;





// // }

// int main (){

    
//     int *ID = malloc(10 * sizeof(int));
//     int k=0;
    
//     int cbt,turnaroundtime,waitingtime;
//     changePolicy(1);
//     //function(ID);
//      int pid;
//     pid=fork();
    
//     if(pid == 0){

           

//       for(int i=0 ; i<5 ; i++){

//          printf(1,"/pID:%d/ : /i:%d/  \n ",getpid(),i);
                
//             }
       
        
//        }
//     if(pid>0){
      
//         ID[k]=wait();
//         k++;
//         pid=fork();
        
//         if(pid == 0){
            
//           for(int i=0 ; i<5 ; i++){

//              printf(1,"/pID:%d/ : /i:%d/  \n ",getpid(),i);
                
//             }
         
//          }
//         if(pid>0){

//             ID[k]=&wait();
//             k++;
//             for(int j= 0 ; j<k ; j++){

            
//             cbt=cpuBurstTime(ID[j]);
//             turnaroundtime=turnAroundTime(ID[j]);
//             waitingtime=waitingTime(ID[j]);
//             printf(1,"index %d ID[j]=pid= %d CBT = %d - Turnaround time = %d - Waiting time = %d \n",j,ID[j],cbt,turnaroundtime,waitingtime);
//             CBT+=cbt;
//             turnaround+=turnaroundtime;
//             waiting+=waitingtime;
//          }


        
//          printf(1,"average CBT = %d - average Turnaround time = %d - average Waiting time = %d \n",(CBT/10),(turnaround/10),(waiting/10));
//          exit();





//         }
    
//        }
      

    
   
    
        
//     exit();
// }

