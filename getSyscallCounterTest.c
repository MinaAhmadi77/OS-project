#include "types.h"
#include "stat.h"
#include "user.h"




int main (){

   getSyscallCounter(6);

    printf(1," the syscall counter is %d \n",getSyscallCounter(6));
         
     

    exit();
}