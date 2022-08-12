#include "types.h"
#include "stat.h"
#include "user.h"
int
main(int argc, char *argv[])
{

	int n, i ,j;
	if(argc!=2)
	{
		printf(1,"usage : testprog no_of_pages\n");
		exit();
	}
	
	
	printf(1,"initially: \n");
        i = count_virtual_pages();
        j = count_physical_pages();
        printf(1, "Count of virtual pages is %d\n", i);
        printf(1, "Count of physical pages is %d\n\n", j-65536);
        n=atoi(argv[1]);
     
        char* arr = (char*)malloc(4096*n);
  
    printf(1,"after allocating virtual memory:\n");
    i = count_virtual_pages();
    j = count_physical_pages();
    printf(1, "Count of virtual pages is %d\n", i);
    printf(1, "Count of physical pages is %d\n\n", j-65536);
  
    printf(1,"when trying to access one of this virtual page\n");
    arr[5000] = 'a';
    i = count_virtual_pages();
    j = count_physical_pages();
  printf(1, "Count of virtual pages is %d\n", i);
  printf(1, "Count of physical pages is %d\n\n", j-65536);
  arr[10000] = 'a';

    i = count_virtual_pages();
    j = count_physical_pages();
  printf(1, "Count of virtual pages is %d\n", i);
  printf(1, "Count of physical pages is %d\n\n", j-65536);

  exit();
}
