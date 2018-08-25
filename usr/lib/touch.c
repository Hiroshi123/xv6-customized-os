
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"

int touch(char* path)
{
  int fd;
  if((fd = open(path, O_CREATE)) < 0)
  {
    return fd;
  }
  return -1;
}

int
main(int argc, char *argv[])
{
  if(argc < 2){
    printf(2, "Usage: touch files...\n");
    exit();
  }

  int i;
  for(i=1; i<argc; i++){
    //int fd;
    touch(argv[i]);
    int xticks;
    xticks = uptime();
    printf(2, "%d\n",xticks);
  }
  
  int r;
  r = rename(".",".");
  printf(2, "%d\n",r);
  
  exit();
}


