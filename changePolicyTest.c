#include "types.h"
#include "stat.h"
#include "user.h"



int main (int argc, char *argv[]){

    int input=atoi(argv[1]);
   // int ppid=getpid();
   // printf(1,"im root %d \n",getpid());
   
    int res=changePolicy(input);
    printf(1,"policy changed to = %d  \n",res);
    
    exit();
}