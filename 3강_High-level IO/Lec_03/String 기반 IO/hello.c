#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* rfp, *wfp;
	int c;

	if ((rfp = fopen("hello seongwoo.txt", "r")) == NULL) {
		perror("fopen : hello seongwoo.txt");
		exit(1);
	}

	if ((wfp = fopen("hello seongwoo.out", "w")) == NULL) {
		perror("fopen : hello seongwoo.out");
		exit(1);
	}
	
	while ((c = fgetc(rfp)) != EOF) {
		fputc(c, wfp);
	}

	fclose(rfp);
	fclose(wfp);

	return 0;
}
