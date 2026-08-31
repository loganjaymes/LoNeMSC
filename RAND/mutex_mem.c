#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

uint32_t counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* loop(void* arg) {
	uint32_t* id  = (uint32_t*)arg;

	while (counter < 10) {
		pthread_mutex_lock(&lock);
		if (*id == 17 && counter % 2 == 1) {  // thread = odds, main = evens
			printf("%d [%d]\n", counter, *id);
			counter++;
		} else if (*id == 9 && counter % 2 == 0) {
			printf("%d [%d]\n", counter, *id);
			counter++;
		} else {
			printf("Conditions not met...\n");
		}

		pthread_mutex_unlock(&lock);
	}

	return NULL;
}

int main(void) {
	pthread_t res;
	uint32_t t_id = 17;
	uint32_t m_id = 9;


	pthread_create(&res, NULL, loop, &t_id);

	loop(&m_id);

	pthread_join(res, (void *)&res);
	// printf("Thread done- id=%d\n", res); // leftover code from another example, but would return the id value from the thread function if we did not pass m_id into it (sometimes ret t_id, sometimes m_id)
	
	return 0;
}
