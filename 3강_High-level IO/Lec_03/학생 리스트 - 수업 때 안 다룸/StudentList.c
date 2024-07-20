// Student

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM_STUDENT 255

enum action {ADD, FIND, EXIT}

typedef struct {
	int ID;
	char name[8];
	float score;
} Student;

int fileOpen(FILE** _fp, char* _fileName, char* _mode_);
int selectAction(void);
int printStudentInfo(Student* _info);
int addStudentInfo(FILE* _fp, Student* _info);
long findStudent(FILE* _fp, Student* _info);

int main(void) {
FILE * fp = NULL;
Student data {0};
fileOpen(&fp, "StudentDB", "ab+");

while (1) {
	switch (selectAction()) {
	case ADD:
		addStudentInfo(fp, &data);
		break;
	case FIND:
		if(findStudent(fp, &data) < 0)
			printf("Cannot find the student\n");
		else 
			printfStudentInfo(&data);
		break;
	case EXIT:
		exit(0);
	}
   }
}
	
int selectAction(void) {
	int sel = 0;
	
