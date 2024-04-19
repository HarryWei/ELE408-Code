#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(void) {
  int pfds[2], retval;
  char buf[30];

  pipe(pfds);
  if (!fork()) { /* child writes data into pipe */
    while(fgets(buf, 30, stdin) != NULL) {
      buf[strlen(buf)-1]=0;
      write(pfds[1], buf, strlen(buf)+1);
    }
    printf("CHILD: exiting\n");
  } else { /* parent reads data from pipe */
    close(pfds[1]); /* why closing it will explain later */
    while (1) {
      retval=read(pfds[0], buf, sizeof(buf));
      if (retval==0) break;
      else printf("PARENT: read \"%s\"\n", buf);
    }
    wait(NULL);
  }
}

