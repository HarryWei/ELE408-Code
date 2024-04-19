#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define GPIO_BASE               0xfe200000	// GPIO controller 
 
#define BLOCK_SIZE 		(4*1024)

#define INP_GPIO(g)   *(gpio.addr + ((g)/10)) &= ~(7<<(((g)%10)*3))
#define OUT_GPIO(g)   *(gpio.addr + ((g)/10)) |=  (1<<(((g)%10)*3))
#define GPIO_SET  *(gpio.addr + 7)    // set bits which are 1, ignore bits which are 0
#define GPIO_CLR  *(gpio.addr + 10)  // clear bits which are 1, ignores bits which are 0

// IO Access
struct bcm2711_peripheral {
    unsigned long addr_p;
    int mem_fd;
    void *map;
    volatile unsigned int *addr;
};


struct bcm2711_peripheral gpio = {GPIO_BASE};


// Exposes the physical address defined in the passed structure using mmap on /dev/mem
int map_peripheral(struct bcm2711_peripheral *p)
{
   // Open /dev/mem
   if ((p->mem_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0) {
      printf("Failed to open /dev/mem, try checking permissions.\n");
      return -1;
   }

   p->map = mmap(
      NULL,
      BLOCK_SIZE,
      PROT_READ|PROT_WRITE,
      MAP_SHARED,
      p->mem_fd,      // File descriptor to physical memory virtual file '/dev/mem'
      p->addr_p       // Address in physical map that we want this memory block to expose
   );
 
   if (p->map == MAP_FAILED) {
        perror("mmap");
        return -1;
   }
 
   p->addr = (volatile unsigned int *)p->map;
 
   return 0;
}
 
void unmap_peripheral(struct bcm2711_peripheral *p) {
 
    munmap(p->map, BLOCK_SIZE);
    close(p->mem_fd);
}


int main()
{
  if(map_peripheral(&gpio) == -1)
  {
    printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
    return -1;
  }

  // Define pin 11 as output
  INP_GPIO(17);
  OUT_GPIO(17);

  while(1)
  {
    // Toggle pin 7 (blink a led!)
    GPIO_SET = 1 << 17;
    sleep(1);

    GPIO_CLR = 1 << 17;
    sleep(1);
  }

  return 0;
}
