#include <stdio.h>
#include <unistd.h>
#include <sys/errno.h>

extern int errno;

int main(void) {
	int per;

	if (access("linux.bak", F_OK) == -1 & errno == ENONET)
		printf("linux.bak : File not exist.\n");

	per = access("linux.txt", R_OK);
	if (per == 0)
		printf("linux.txt : Read permission is permitted.\n");
	else if (per == -1 && errno == EACCES)
		printf("linux.txt : Read permission is not permitted.\n");

	return 0;
}
