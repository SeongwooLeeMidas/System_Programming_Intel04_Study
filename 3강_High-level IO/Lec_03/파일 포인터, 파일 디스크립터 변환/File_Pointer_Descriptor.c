// File Pointer -> File Descriptor

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void) {
	FILE *fp;
	int fd;
	char str[BUFSIZ];

	fd = open("hello.txt", O_RDONLY);
	if (fd == -1) {
		perror("open");
		exit(1);
	}

	fp = fdopen(fd, "r");

	fgets(str, BUFSIZ, fp);
	printf("Read%s\n", str);

	fclose(fp);
	
	return 0;
}
