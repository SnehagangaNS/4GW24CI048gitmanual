 PROGRAM 3-----------
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define BUFFER_SIZE 5
#define MAX_ITEMS 5
int buffer[BUFFER_SIZE], in = 0, out = 0;
int produced = 0, consumed = 0;
pthread_mutex_t mutex;
pthread_cond_t full, empty;
void* producer(void* arg)
{
    int item = 1;
    while(produced < MAX_ITEMS)
    {
        pthread_mutex_lock(&mutex);
        while((in + 1) % BUFFER_SIZE == out)
            pthread_cond_wait(&empty, &mutex);
        buffer[in] = item;
        printf("Produced: %d\n", item++);
        in = (in + 1) % BUFFER_SIZE;
        produced++;
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
void* consumer(void* arg)
{
    while(consumed < MAX_ITEMS)
    {
        pthread_mutex_lock(&mutex);
        while(in == out)
            pthread_cond_wait(&full, &mutex);
        printf("Consumed: %d\n", buffer[out]);
        out = (out + 1) % BUFFER_SIZE;
        consumed++;
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
int main()
{
    pthread_t p, c;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&full, NULL);
    pthread_cond_init(&empty, NULL);
    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);
    pthread_join(p, NULL);
    pthread_join(c, NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&full);
    pthread_cond_destroy(&empty);
    return 0;
}