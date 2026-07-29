#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* myturn(void* arg) {
	for (int i = 0; i < 8; ++i) {
		sleep(1);
		printf("Me me me!\n");
	}

	return NULL;
}

void yourturn() {
	for (int i = 0; i < 3; ++i) {
		sleep(2);
		printf("You you you!\n");
	}
}

int main(void) {
	pthread_t my_thread;
	pthread_create(&my_thread, NULL, myturn, NULL);
	
	yourturn();

	pthread_join(my_thread, NULL);
}
