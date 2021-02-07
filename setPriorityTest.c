#include "types.h"
#include "stat.h"
#include "user.h"



int main (int argc, char *argv[]){

    int input=atoi(argv[1]);
   // int ppid=getpid();
   // printf(1,"im root %d \n",getpid());
    int priority=getPriority();
    int res=setPriority(input);
    printf(1,"previous priority was %d priority changed to = %d  \n",priority,res);
    
    exit();
}