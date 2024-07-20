#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *fp; // file pointer
	
	if ((fp = fopen("hello seongwoo.txt", "w")) == NULL) // file open
	{
		perror("fopen : hello seongwoo.txt");
		exit(1);
	}

	fclose(fp); // file close

	return 0;
}
