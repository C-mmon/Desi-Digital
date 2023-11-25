#include <stdio.h>
#include

sem_t semaphore;

int sharedResources=0;

void *higherPriorityTask(void *arg);
void *lowerPriorityTask(void *arg);

int main()
{
    // Create threads for higher and lower priority tasks
    pthread_t higherPriorityThread, lowerPriorityThread;

    pthread_create(&higherPriorityThread, NULL, higherPriorityTask, NULL);
    pthread_create(&lowerPriorityThread, NULL, lowerPriorityTask, NULL);

    // Wait for threads to finish
    pthread_join(higherPriorityThread, NULL);
    pthread_join(lowerPriorityThread, NULL);

    // Destroy the semaphore
    sem_destroy(&semaphore);

    return 0;
}

void *higherPriorityTask(void *arg) {
    while (1) {
        printf("Higher priority task waiting for the semaphore.\n");

        // Wait for the semaphore
        sem_wait(&semaphore);

        // Access the shared resource
        printf("Higher priority task accessing the shared resource.\n");
        sharedResource++;
        printf("Shared resource value: %d\n", sharedResource);

        // Release the semaphore
        sem_post(&semaphore);

        // Simulate some processing
        usleep(500000);
    }

    pthread_exit(NULL);
}

void *lowerPriorityTask(void *arg) {
    while (1) {
        printf("Lower priority task waiting for the semaphore.\n");

        // Wait for the semaphore
        sem_wait(&semaphore);

        // Access the shared resource
        printf("Lower priority task accessing the shared resource.\n");
        sharedResource--;
        printf("Shared resource value: %d\n", sharedResource);

        // Release the semaphore
        sem_post(&semaphore);

        // Simulate some processing
        usleep(1000000);
    }

    pthread_exit(NULL);
}