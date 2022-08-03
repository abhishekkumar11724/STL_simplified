#include <bits/stdc++.h>
using namespace std;

template <typename T>
class queue_array_type1 {
    // queue where, if the rear pointer reaches the max size
    // the queue will be full, i.e., not a circular queue
    T arr[10], front = -1, rear = -1, size = 9;

    public:
    void createQueue(int size){
        // arr = new int [size];
        front = rear = -1;
    }
    void enqueue(node * data){
        // if(arr == nullptr) createQueue(size);
        
        if(rear == size -1 || front >= size) {
            cout<<" queue is full !!!"<<endl;
        }
        else {
            front++;
            arr[front] = data;
        }
    }
    int dequeue(){
        int x = -1;
        if(front == rear) {
            cout<<"queue is empty !!!";
        }
        else {
            x = arr[rear++];
        }
        return x;
    }

    void display() {
        int i = rear+1;
        cout<<endl;
        while(i <= front) {
            cout<<arr[i];
            if(i != front)  cout<<" -> ";
            i++;
        }
    }
    bool isEmpty(){

    }
};

template <typename T>
class queue_array_type2 {
    // this queue of circular nature 
    T * arr = nullptr, front, rear, size = 10;
    public:
    void createQueue(int size){
        arr = new T [size];
        front = rear = 0;
    }
    void enqueue(T data) {
        if(arr == nullptr) {
            createQueue(size);
            // rear++;
        }
        if(rear == (front+1) % size ){ 
            cout<<"queue is full"<<endl;
        }
        // else if(rear == -1 && ((front+1) % size ) == 0){
        //     cout<<"queue is full"<<endl;
        // }
        else {
            front++;
            if(front > rear) {
                if(front <= size-1) // add element
                {
                    arr[front] = data;
                }
                else if(front > size -1) {
                    front = front % size;
                    //add element
                    arr[front] = data;
                }
            }
            else if(front < rear ){
                //add element
                arr[front] = data;
            }
        }
    }
    void dequeue(){

    }
    void display(){
        int i = rear+1;
        while(i <= front){
            if(i > size) i = i%size;
            cout<<arr[i]<<" -> ";
            i++;
        }
    }
    void array(){
        cout<<endl;
        for(int i =0; i< 10;i++)cout<<arr[i]<<" -> ";
    }
    bool isEmpty() {
        if(front <= rear) {
            return true;
        }
        return false;
    }
};

class queue_array_type2_extended{
    int  front = 0, rear = 0, size = 10, arr[10];

    public :
    void enqueue(int data) {
        if((rear+1) % size == front)  cout<<"Queue is full !!!"<<endl;
        else {
            rear = (rear + 1) % size;
            arr[rear] = data;
        }
    }
    int dequeue() {
        int x = -1;
        if((front + 1) % size == rear) cout<<"queue is empty"<<endl;
        else {
            x = arr[front];
            front = (front + 1) % size;
        }
    }
    void display() {
        int i = front+1;
        cout<<endl;
        while(i !=( rear + 1) % size){
            cout<<arr[i]<<" -> ";
            i = (i+1)%size;
        }
    }
     void array(){
        cout<<endl;
        for(int i =0; i< 10;i++)cout<<arr[i]<<" -> ";
    }
};
// template <typename T> 
// class queue_linkedList {
//     struct node {
//         T data;
//         node * next;
//     }
// }
// int main()
// {
//     queue_array_type2_extended q;
//     q.enqueue(1);
//     q.enqueue(2);
//     q.enqueue(3);
//     q.enqueue(4);
//     q.enqueue(5);
//     q.enqueue(6);
//     q.enqueue(7);
//     q.enqueue(8);
//     q.enqueue(9);
//     q.enqueue(10);
//     q.enqueue(11);
//     q.enqueue(12);
//     q.enqueue(13);
    
//     q.display();
//     q.array();

//  q.dequeue();
//  q.dequeue();

//  q.display();
//  q.array();
//     return 0;
// }

