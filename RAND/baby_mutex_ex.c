#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

uint32_t counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* loop(void* arg) {
	for (uint32_t i = 0; i < 11; ++i) {
		pthread_mutex_lock(&lock);
		printf("%d\n", (counter));
		counter++;
		pthread_mutex_unlock(&lock);
	}
}

int main(void) {
	pthread_t res;
	pthread_create(&res, NULL, loop, NULL);

	loop(NULL);

	pthread_join(res, (void *)&res);
	printf("Thread done- v=%d\n", res);
	
	return 0;
}
