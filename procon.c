#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>
#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int count = 0; // Number of items in the buffer
sem_t empty, full, mutex;
void *producer(void *arg)
{
    int item;
    for (int i = 0; i < 10; i++)
    {
        item = rand() % 100; // Generating a random item (0 to 99)
        sem_wait(&empty);
        sem_wait(&mutex);
        // Critical Section (Produce)

        buffer[count] = item;
        count++;
        printf("Produced: %d\n", item);
        sem_post(&mutex);
        sem_post(&full);
        sleep(1);
    }
    pthread_exit(NULL);
}
void *consumer(void *arg)
{
    int item;
    for (int i = 0; i < 10; i++)
    {
        sem_wait(&full);
        sem_wait(&mutex);
        // Critical Section (Consume)
        item = buffer[count - 1];
        count--;
        printf("Consumed: %d\n", item);
        sem_post(&mutex);
        sem_post(&empty);
        sleep(1);
    }
    pthread_exit(NULL);
}
int main()
{
    pthread_t producer_thread, consumer_thread;
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);
    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    // Wait for threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}