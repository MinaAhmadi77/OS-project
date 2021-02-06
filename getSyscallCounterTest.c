#include "types.h"
#include "stat.h"
#include "user.h"



int main (int argc, char *argv[]){

     int input=atoi(argv[1]);

    getParentID();
    getParentID();
    getParentID();
    getChildren();
    getChildren();
    getChildren();
    printf(1," the syscall counter is %d \n",getSyscallCounter(input));
  
         
     

    exit();
}