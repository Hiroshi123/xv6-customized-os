
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"

char buf[512];


void
_cat(int fd)
{
  int n;

  while((n = read(fd, buf, sizeof(buf))) > 0) {
    if (write(1, buf, n) != n) {
      printf(1, "cat: write error\n");
      exit();
    }
  }
  if(n < 0){
    printf(1, "cat: read error\n");
    exit();
  }
}

int main(int argc, char *argv[]){

  if(argc > 1){
  int fd;
  char* path = "kk";
  fd = open(path, O_CREATE | O_RDWR);
  write(fd,"abcd0123\n",10);
  printf(1,"fd:%d\n",fd);
  close(fd);
  exit();
  return 0;
  }
  int r;
  r = fcntl();
  printf(2, "%d\n",r);
  exit();
  return 0;
  
}

int
mains_(int argc, char *argv[])
{
  /* if(argc < 2){ */
  /*   printf(2, "Usage: mv files...\n"); */
  /*   exit(); */
  /* } */

  if( argc > 1) {

    int fd;
    if(strcmp(argv[1],"r")==0){
      if(fd = open(argv[2], O_RDWR) > 0)
      {
        _cat(fd);
        close(fd);
        exit();
        return 0;
      }
    }
    
    /* if(fd = open(argv[1], O_RDWR) > 0) { */
      
    /* } */
    if(fd = open(argv[1], O_CREATE|O_RDWR) > 0){
      printf(1,"fd:%d\n",fd);
      // char p[512] = "s";
      /* char *r; */
      /* // strcpy(p,"acds"); */
      /* // printf(1,p); */
      
      /* // printf(1,"strlen%d\n",strlen(p));       */
      /* write(fd,"a",1); */
      /* printf(1,"ss"); */
      /* read(fd,r,4); */
      /* printf(1,r); */
      close(fd);
      exit();
      return 0;
    }
  }
  
  int r;
  r = fcntl();
  printf(2, "%d\n",r);
  
  exit();
}



