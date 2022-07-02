#include <bits/stdc++.h>
using namespace std;

class stack_array {
    int arr[50];
    int top = 0;

    public:
    
    void push(int data) {
        if(top == 0) {
            arr[0] = data;
            top++;
        }
        else {
            if(top < 49) {
                arr[top+1] = data;
                top++;
            }
            else {
                cout<<"stack overflow !";
            }
        }
    }

    int pop() {
        if(top == 0){
            return -1;
        }
        else {
            top--;
            return arr[top+1];
        }
    }

    bool isEmpty() {
        if(top == 0) 
            return true;
        else return false;
    }

    bool isFull() {
        if(top == 49) {
            return true;
        }
        else return false;
    }
    int peek() {
        return arr[top];
    }

    void display() {
        int i = 0;
        while (i != top){
            cout<<arr[i];
            if(i+1 != top)
                cout<<" -> ";
            i++;
        }
    }
};

class stack_linkedList {
    struct node {
        int data;
        node * next = NULL;
    };
    node * top = NULL;

    public:
    node * createNode(int data) {
        node * temp = new node;
        temp->data = data;
        return temp;
    }

    void push(int data) {
        if(top == NULL) {
            top = createNode(data);
        }
        else {
            node * temp = createNode(data);
            temp->next = top;
            top = temp;
        }
    }

    void display() {
        node * ptr = top;
        while(ptr != NULL) {
            cout<<ptr->data;
            if(ptr->next != NULL)
                cout<<" -> ";
            ptr= ptr->next;
        }
    }
};

int main()
{
    
    return 0;
}