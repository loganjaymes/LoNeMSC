#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int scall(char path[], int buf_size) {
	// using int fd because kernel level, rahter than an fptr (pass named fds to unix calls ie. read, write, etc.)
	int fd;
	fd = open(path, O_RDWR);

	if (fd == -1) {
		printf("SCALL: Failed to open file"); 
		return errno;
		close(fd);
	}

	char buf[buf_size];
	ssize_t bread;

	bread = read(fd, buf, sizeof(buf));

}

int f_funcs(char path[]) {
	// FILE* fp = fopen(path);
}

int main() {
	// open file
	// read 
	// write to buffer of varying sizes (2 -> 16 -> 64)
	// write from buffer to new file
	//
	// alter for read and fread etc etc
	scall("somefile");
	
}
