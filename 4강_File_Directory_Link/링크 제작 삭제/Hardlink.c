#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
	struct stat buf;

	stat("linux.txt", &buf);
	printf("Before link count = %d\n", (int)buf.st_nlink);

	link("linux.txt", "linux.ln");

	stat("linux.txt", &buf);
	printf("After link count = %d\n", (int)buf.st_nlink);

	return 0;
}
