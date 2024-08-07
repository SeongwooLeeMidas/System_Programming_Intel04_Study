#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void) {
	int fd;
	mode_t mode;

	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // 644

	fd = open("hello.txt", O_CREAT, mode);
	if (fd == -1) {
		perror("Creat"); exit(1);
	}
	close(fd);

	return 0;
}
