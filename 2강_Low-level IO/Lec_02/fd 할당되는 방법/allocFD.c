#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int openFile(void) {
	int fd = open("hello.txt", O_RDWR);
	if (fd == -1) {
		perror("File Open");
		exit(1);
	}
	return fd;
}

int main(void) {
	int fd = 0;

	fd = openFile();
	printf("fd = %d\n", fd);
	close(fd);
	
	close(0);

	fd = openFile();
	printf("fd = %d\n", fd);

	return 0;
}
