#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

struct queue{
    int items[SIZE];
    int front;
    int rear;
};

struct queue* createQueue(void);

void enqueue(struct queue *q, int);
int dequeue(struct queue *q);

void display(struct queue *q);
int isEmpty(struct queue *q);
void printQueue(struct queue *q);


struct queue* createQueue(void){
    struct queue *q = malloc(sizeof(struct queue));
    q->front=-1;
    q->rear=-1;
    return q;
}

void enqueue(struct queue *q, int value){
    if(q->rear==SIZE-1){
        printf("Queue is full\n");
    }
    else{
        if(q->front==-1){
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear]=value;
    }
}

int dequeue(struct queue *q){
    int item;
    if(q->front==-1 && q->rear==-1){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        item = q->items[q->front];
        q->front++;
        if(q->front>q->rear){
            q->front=q->rear=-1;
        }
        return item;
    }
}


int main(void){
    struct queue *q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Front: %d\nRear: %d\n", q->front, q->rear);

    printf("Memory address of q: %p\n", q);
    free(q);
    printf("Memory address of q: %p\n", q);


}
