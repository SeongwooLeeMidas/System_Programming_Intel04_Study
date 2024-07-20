#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
	int rfd, wfd, n;
	char buf[10];

	rfd = open("hello.txt", O_RDONLY);
	if (rfd == -1) {
		perror("Open hello.txt");
		exit(1);
	}

	wfd = open("hello.out", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (wfd == -1) {
		perror("Open hello.bak");
		exit(1);
	}
	
	while ( ( n = read(rfd, buf, 6) ) > 0)
		if (write(wfd, buf, n) != n) perror("Write");

	if (n == -1) perror("Read");

	close(rfd);
	close(wfd);
	return 0;
}
