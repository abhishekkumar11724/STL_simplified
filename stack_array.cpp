#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX 10
using namespace std;
int stack_arr[MAX];
int top = -1;
void push(int item);
int pop();
int peek();
int isEmpty();
int isFull();
void display();

void push(int item) {
    if(isFull()) {
        cout<<"stack overflow !!";
        return;
    }
    top++;
    stack_arr[top] = item;    
}
int pop() {
    if(isEmpty()) {
        cout<<"stack underflow !!";
        return -1;
    }
    top--;
    return stack_arr[top+1];

}
int peek() {
    if(isEmpty()) {
        cout<<"stack underflow !!";
        return -1;
    }
    return stack_arr[top];
}
int isEmpty() {
    if(top == -1) 
        return 1;
    return 0;
}
int isFull() {
    if(top == MAX-1) 
        return 1;
    return 0;
}
void display() {
    int i ;
    if(isEmpty()){
        cout<<"stack underflow !!";
        return;
    }
    for(i = top; i>0; i--) {
        cout<<stack_arr[i]<<" ";
    }
}

int main() {

}