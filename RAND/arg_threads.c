#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* myturn(void* arg) {
	int* iptr = (int*)malloc(sizeof(int));
	*iptr = 5;

	for (int i = 0; i < 8; ++i) {
		sleep(1);
		printf("Me me me! %d\n", *iptr);
		(*iptr)++;
	}

	return iptr;
}

void yourturn() {
	for (int i = 0; i < 3; ++i) {
		sleep(2);
		printf("You you you!\n");
	}
}

int main(void) {
	pthread_t my_thread;
	int* res;

	// if using int declared in main, we'd just pass (int res) {res} into the 2nd NULL, and ignore the malloc in myturn
	pthread_create(&my_thread, NULL, myturn, NULL);
	
	yourturn();

	pthread_join(my_thread, (void *)&res);
	printf("Thread done- v=%d\n", *res);

	free(res);
}
