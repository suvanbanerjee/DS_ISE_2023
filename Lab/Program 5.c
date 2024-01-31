#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue
#define MAX_SIZE 10

// Define the structure for the queue
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize the queue
void initialize(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to insert an element into the queue
void insert(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow! Cannot insert %d.\n", value);
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}

// Function to delete an element from the queue
void delete(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow! Cannot delete from an empty queue.\n");
    } else {
        int deletedValue = queue->items[queue->front];
        if (queue->front == queue->rear) {
            // Last element is being deleted
            initialize(queue);
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        printf("%d deleted from the queue.\n", deletedValue);
    }
}

// Function to display the elements of the queue
void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements:\n");
        int i = queue->front;
        do {
            printf("%d\n", queue->items[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (queue->rear + 1) % MAX_SIZE);
    }
}

int main() {
    // Declare and initialize the queue
    struct Queue queue;
    initialize(&queue);

    // Insert some elements into the queue
    insert(&queue, 10);
    insert(&queue, 20);
    insert(&queue, 30);

    // Display the current state of the queue
    display(&queue);

    // Delete an element from the queue
    delete(&queue);

    // Display the updated state of the queue
    display(&queue);

    return 0;
}
