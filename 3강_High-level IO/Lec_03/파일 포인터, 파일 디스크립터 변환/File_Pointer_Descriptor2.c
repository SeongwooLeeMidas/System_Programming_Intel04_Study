// File Pointer <- File Descriptor

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	FILE* fp;
	int fd, n;
	char str[BUFSIZ]'

	fp = fopen("cookbook.txt", "r");
	if (fp == NULL) {
		perror("fopen");
		exit(1);
	}

	fd = fileno(fp);
	printf("fd : %d\n", fd);

	n = read(fd, str, BUFSIZE);
	str[n] = '\0';
	prinf("Read : %s\n", str);
	
	close(fd);
	return 0;
}
