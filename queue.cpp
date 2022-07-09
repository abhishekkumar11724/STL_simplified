#include <bits/stdc++.h>
using namespace std;

class queue_array {
    int arr[50];
    int start = -1;
    int end = -1;

    public:

    void enqueue(int data) {
        if(end == 0) {
            arr[end++] = data;
        }
        else {
            arr[end++] = data;
        }
    }

    void dequeue() {
        
    }

    void display(){
        
    }
};

int main(){
    queue_array qu;
    qu.enqueue(1);
    qu.enqueue(2);
    qu.enqueue(3);
    qu.enqueue(4);
    qu.enqueue(5);
    qu.enqueue(6);
    qu.enqueue(7);
    


    return 0;
}

