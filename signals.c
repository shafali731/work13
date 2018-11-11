#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <string.h>

static void sighandler(int signo){
	if (signo == SIGINT){
		int fd = open("sig.txt", O_WRONLY| O_CREAT, 0666);

		if (fd< 0){
			printf("Error: %s\n", strerror(errno));
			exit(0);
		}
    char error_mess[] = "Program exited due to SIGINT \n" ;
		write(fd, error_mess, sizeof(error_mess));
		close(fd);
		exit(0);
	}

	if (signo == SIGUSR1){
		printf("Parent PID: %d\n", getppid());
	}
}


int main(){
  signal(SIGINT,sighandler);
  signal(SIGUSR1,sighandler);
  
  while(1){
    printf("PID: %d\n", getpid() );
    sleep(1);
  }


  return 0;

}
