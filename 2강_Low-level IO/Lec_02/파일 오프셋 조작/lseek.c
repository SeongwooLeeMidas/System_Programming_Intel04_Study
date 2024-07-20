#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void) {
	int fd, n;
	off_t start, cur;
	char buf[256]; // 255바이트

	fd = open("linux.txt", O_RDONLY);
	if (fd == -1) {
		perror("Open linux.txt");
		exit(1);
	}

	start = lseek(fd, 0, SEEK_CUR);
	n = read(fd, buf, 255);
	buf[n] = '\0';
	printf("Offset start = %d, Read Str = %s, n = %d\n", (int)start, buf, n);
	// 시작위치, 읽은 내용, 몇 개나 읽었는지 출력
	cur = lseek(fd, 0, SEEK_CUR); // 현재 위치 받아옴
	printf("Offset cur = %d\n", (int)cur);

	start = lseek(fd, 6, SEEK_SET); // 파일 오프셋 6바이트 앞으로 이동
	n = read(fd, buf, 255); // 255바이트 읽어서 출력
	buf[n] = '\0';
	printf("Offset start = %d, Read Str = %s", (int)start, buf);
	// 6번째부터 읽으니 Linux 는 날아가고 System Programming만 출력
	close(fd);
		
	return 0;
}
