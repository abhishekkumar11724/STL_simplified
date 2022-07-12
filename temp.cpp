#include <bits/stdc++.h>
using namespace std;

struct Queue {
    int * arr;
    int front = 0, rear = 0, size = 10;
};

void enqueue(Queue *q,int data) {
    if((q->rear+1)%q->size == q->front ){
        cout<<"queue is full !!!";
    }
    else {
        q->rear = (q->rear+1) % q->size;
        q->arr[q->rear] = data;
    }
}
int dequeue(Queue *q) {
    int x = -1;
    if(q->front == q->rear) {
        cout<<"queue is empty !!!";
    } 
    else {
        q->front = (q->front + 1) % q->size;
        x = q->arr[q->front];
    }
    return x;
} 
void display(Queue q){
    int i = q.front + 1;
    do {
        cout<<q.arr[i];
        i = (i+1)%q.size;
    }while(i != (q.rear+1) % q.size);
}

int main()
{
    Queue q;
    q.arr = new int [q.size];

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
    display(q);
    dequeue(&q);
    cout<<endl;
    display(q);

    // display(q);
    return 0;
}