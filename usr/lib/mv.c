
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  if(argc < 2){
    printf(2, "Usage: mv files...\n");
    exit();
  }

  int r;
  r = rename(argv[1], argv[2]);
  printf(2, "%d\n",r);
  
  exit();
}



