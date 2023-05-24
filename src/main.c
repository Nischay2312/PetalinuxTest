#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/mman.h>


#define leds_addr 0x41200000
static volatile uint32_t *leds;

void map_gpios(void){
	int fd;
	if(fd = open("/dev/mem", O_RDWR|O_SYNC) < 0)
		if(fd < 0){
			perror("/dev/mem");
			exit(-1);
		}
	if ((leds = mmap(0, getpagesize(), PROT_READ|PROT_WRITE, MAP_SHARED, fd, leds_addr))
	      == MAP_FAILED) {
	    perror("leds did not get pointer from mmap");
	    exit(-1);
	  }
	}


	const int leds_mode = 5;
	const int exit_mode = 0;

	static int select_mode(void)
	{
	  int mode;
	  printf("Select one of the following modes:\r\n");

	  printf("%0d) Enter a value to write to the GPIO LEDs.\r\n",leds_mode);
	  printf("%0d) Exit the demo.\r\n",exit_mode);
	  scanf("%d",&mode);
	  return mode;
	}

	static void run_leds_mode(void)
	{
	  int val;
	  printf("Enter a value to set the IO LEDs to: led = %x\r\n",*leds);

	  scanf("%d",&val);
	  *leds = val;
	}

	int main(int argc, char *argv[])
	{
	  int mode;

	    printf("Hello, PetaLinux World LED!\n");
	    printf("cmdline args:\n");
	    while(argc--)
	        printf("%s\n",*argv++);

	    printf("gpi_custiom inside main:\r\n");

	  map_gpios();


	  do {
	    mode = select_mode();
	    if (mode == leds_mode)
	      run_leds_mode();
	  } while (mode != exit_mode);

	  return 0;
	}


