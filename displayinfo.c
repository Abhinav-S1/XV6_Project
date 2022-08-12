#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {
  int pid;
 

  if(argc != 2)
	{
	printf(1,"usage: displayinfo pid \n");
	exit();
	}
	
  pid=atoi(argv[1]);
	display(pid);
	//printf(1,"%d \n",pid);
	
  exit();
}
