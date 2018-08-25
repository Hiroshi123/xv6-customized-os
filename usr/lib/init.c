// init: The initial user-level program

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char *argv[] = { "sh", 0 };

int
main(void)
{
  int pid, wpid;

  printf(1, "init: started!!\n");
  
  // open("usr/bin/a", O_CREATE||O_RDWR);
  /* mkdir("proc"); */
  /* mkdir("etc"); */
  
  if(open("console", O_RDWR) < 0){
    mknod("console", 1, 1);
    open("console", O_RDWR);
  }
  
  dup(0);  // stdout
  dup(0);  // stderr

  mkdir("usr");
  mkdir("usr/bin");
  printf(1,"rename start");
  // rename("ls","usr/bin/ls");
  /* rename("ls","pika"); */
  printf(1,"rename end");
  
  for(;;){
    printf(1, "init: starting sh\n");
    pid = fork();
    if(pid < 0){
      printf(1, "init: fork failed\n");
      exit();
    }
    if(pid == 0){
      exec("sh", argv);
      printf(1, "init: exec sh failed\n");
      exit();
    }
    while((wpid=wait()) >= 0 && wpid != pid)
      printf(1, "zombie!\n");
  }
}
