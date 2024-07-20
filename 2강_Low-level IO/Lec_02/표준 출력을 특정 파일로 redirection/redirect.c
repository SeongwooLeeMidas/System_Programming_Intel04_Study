#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
	int fd, fd1;
	
	fd = open("tmp.aaa", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1) {
		perror("Create tmp.aaa");
		exit(1);
	}
	close(1); // close stdout

	// duplicate fd, fd1 will get 1 => redirect standard output to the file
	fd1 = dup(fd);

	printf("DUP FD = %d\n", fd1);
	printf("Standard Output Redirection\n");
	close(fd);
	
	return 0;
}
