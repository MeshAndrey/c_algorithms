#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void enQueue(int);
void deQueue();
void display();

typedef struct queue
{
    int16_t front;
    int16_t rear;
    uint16_t capacity;
    int32_t* data;
} queue;

queue* create_queue(uint16_t capacity)
{
    queue* new_queue = (queue*) malloc (sizeof(queue));

    new_queue->capacity = capacity;
    new_queue->front = -1;
    new_queue->rear = -1;
    new_queue->data = (int32_t*) malloc (new_queue->capacity * sizeof(int32_t));

    return new_queue;
}

bool is_full(queue* queue)
{
    return queue->rear == (queue->capacity - 1);
}

bool is_empty(queue* queue)
{
    return queue->rear == -1;
}

bool enqueue(queue* queue, int32_t item)
{
    if (is_full(queue))
	return false;

    if (queue->front == -1)
	queue->front = 0;

    queue->data[++(queue->rear)] = item;

    return true;
}

int32_t dequeue(queue* queue)
{
    if (is_empty(queue))
	return -1;

    int32_t front_queue = queue->data[queue->front];

    for (uint16_t i = 0; i < queue->rear - 1; i++)
	queue->data[i] = queue->data[i + 1];

    queue->rear--;

    return front_queue;
}

void delete_queue(queue* queue)
{
    free(queue->data);
    free(queue);
}

int main()
{
    queue* queue = create_queue(5);
    
    for (uint16_t i = 0; i < 5; i++)
	enqueue(queue, i);

    for (uint16_t i = 0; i < 5; i++)
	dequeue(queue);

    printf("Is queue empty? %d \n", is_empty(queue));    

    return 0;
}

