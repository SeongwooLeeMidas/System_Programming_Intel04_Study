#include <stdio.h>

typedef struct {
	int ID;
	char name[8];
	float score;
} Student;

int fileOpen(FILE** _fp, char* _fileName, char* _mode_) {
	*_fp = fopen(_fileName, _mode_);
	if (!*_fp) {
		printf("Fail to open - %s\n", _fileName);
		return -1;
	}
	return 0;
}
