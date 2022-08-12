#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {
  int pid;
  int k, n,t;
  float x, z;
  

  if(argc < 2)
	n = 1; //Default
  else
	n = atoi(argv[1]);
  if (n < 0 ||n > 20)
	n = 2;
  x = 0;
  pid = 0;

  for ( k = 0; k < n; k++ ) {
    pid = fork ();
    if ( pid < 0 ) {
      printf(1, "%d failed in fork!\n", getpid());
    } else if (pid > 0) {
      // parent
      printf(1, "Parent %d creating child %d\n",getpid(), pid);
      wait();
      }
      else{
      char *arr=malloc(4096*25);
      arr[1]='a';
	printf(1,"Child %d created\n",getpid());
	for(t = 0; t < 25; t++)
	    {
	    arr[t*4096+1]='a';
	    for(z = 0; z < 70000000; z+=1)
	    x = x + 3.14*89.64; //Useless calculation to consume CPU Time
	   }	    
	break;
      }
  }
  exit();
}
