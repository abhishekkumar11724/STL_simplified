#include <bits/stdc++.h>
#include "queue.cpp"
using namespace std;

class stack_array
{
    int arr[50];
    int top = 0;

public:
    void push(int data)
    {
        if (top == 0)
        {
            top++;
            arr[0] = data;
        }
        else
        {
            if (top < 49)
            {
                arr[top] = data;
                top++;
            }
            else
            {
                cout << "stack overflow !";
            }
        }
    }

    int pop()
    {
        if (top == 0)
        {
            return -1;
        }
        else
        {
            top--;
            return arr[top + 1];
        }
    }

    bool isEmpty()
    {
        if (top == 0)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (top == 49)
        {
            return true;
        }
        else
            return false;
    }
    int peek()
    {
        return arr[top];
    }

    void display()
    {
        // cout<<top;
        int i = top - 1;
        while (i > -1)
        {
            cout << arr[i];
            if (i - 1 > -1)
                cout << " -> ";
            i--;
        }
    }
};

class stack_linkedList
{
    struct node
    {
        char data;
        node *next = nullptr;
    };
    node *top = NULL;

public:
    node *createNode(char data)
    {
        node *temp = new node;
        temp->data = data;
        return temp;
    }
    void push(char data)
    {
        if (top == NULL) {
            top = createNode(data);
        }
        else {
            node *temp = createNode(data);
            temp->next = top;
            top = temp;
        }
    }
    void display() {
        node *ptr = top;
        while (ptr != NULL) {
            cout << ptr->data;
            if (ptr->next != NULL)
                cout << " -> ";
            ptr = ptr->next;
        }
    }
    bool pop() {
        node * temp = top;
        if(top == nullptr) 
            return false;
        top = top->next;
        delete temp;
        return true;
    }
    char stackTop() {
        return top->data;
    }
    bool isEmpty() {
        if(top == NULL)
            return true;
        return false;
    }
    bool isFull() {
    node * t = new node;
    return t ? true : false;
    }
    char peek(char pos) {
        // fuction to get the value at any position in stack
        node * ptr = top;
        while( pos != 0 || ptr->next) {
            ptr = ptr->next;
            pos--;
        }
        if(ptr == NULL)
            return -1;
        return ptr->data;
    }

};

class specialStack
{
    stack<int> st;
    stack<int> minSt;

public:
    void push(int data)
    {
        if (st.empty())
        {
            st.push(data);
            minSt.push(data);
        }
        else
        {
            st.push(data);
            if (minSt.top() > data)
            {
                minSt.push(data);
            }
            else
            {
                minSt.push(minSt.top());
            }
        }
    }
    int getMin() { return minSt.top(); }

    int pop()
    {

        st.pop();
        minSt.pop();
    }
};

class twoStack
{
    int arr[50];
    int top1 = -1, top2 = sizeof(arr) / sizeof(int);

public:
    void pushToStack1(int data)
    {
        if (top1 == top2)
            cout << "stack is full !!";
        else
        {
            top1++;
            arr[top1] = data;
        }
    }
    void pushToStack2(int data)
    {
        if (top1 == top2)
            cout << "stack is full !!";
        else
        {
            top2--;
            arr[top2] = data;
        }
    }
    int popStack1()
    {
        if (top1 != -1)
        {
            top1--;
            return arr[top1 + 1];
        }
        else
        {
            cout << "stack is empty";
            return -1;
        }
    }

    int popStack2()
    {
        if (top2 != -1)
        {
            top2++;
            return arr[top2 - 1];
        }
        else
        {
            cout << "stack is empty";
            return -1;
        }
    }

    void display()
    {
        for (int i = 0; i < top1; i++)
            cout << arr[i] << " ";
        cout << endl;
        for (int i = 49; i > top2; i--)
            cout << arr[i] << " ";
    }
};

template<typename T>int findMiddle(T &st)
{
    stack<int> temp;
    vector<int> arr;
    
    while (!st.empty())
    {
        arr.push_back(st.top());
        st.pop();
    }

    cout << arr[arr.size() / 2];
}

// template<typename T>void printStack(T &st)
// {
//     while (st.empty() == false)
//     {
//         int x = st.top();
//         st.pop();
//         cout << x << " ";
//     }
// }

// int main()
// {
//     stack<int> st;

//     st.push(1);
//     st.push(2);
//     st.push(3);
//     st.push(4);
//     st.push(5);
//     // You can initialise your stack here.
//     printStack(st);
// }

void parenthesisMatch(string s){
    /*  41  (, 42  ), 91  [, 93  ], 123 {, 125 }  */

    stack<char> st;
    int i = 0;
    while(s[i]) {
        // char ch = s[i];
        if(s[i] == '(' || s[i] == '['|| s[i] == '{')
            st.push(s[i]);
        else if(s[i] == ')' || s[i] == ']'|| s[i] == '}')
            st.pop();
        i++;
    }   
    if(st.empty()) cout<<"parenthesis is matching !!!!";
    else cout<<"parenthesis is not matching !!!";
}
void infixToPostfix_parenthesized(string s) {
    stack_linkedList ch, op;
   int i = 0;
   while(s[i]) {
    // cout<<s[i]<<endl;
        if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') 
            op.push(s[i]);
        else if(s[i] == ')') {
            // cout<<"\t"<<op.top();
            ch.push(op.stackTop());
            op.pop();
            op.pop();
        }
        else{
            ch.push(s[i]);
        }
        i++;
    }

    vector<char> vec;
    while(!ch.isEmpty()){
        vec.push_back(ch.stackTop());
        ch.pop();
    }
    reverse(vec.begin(), vec.end());
    for(auto i = 0; i <vec.size(); i++) 
        cout<<vec[i];
};
void infixToPostfix(string s) {
    stack_linkedList st, op;
    
    int i = 0;
    while(s[i]) {
    
    }
}
int main()
{
    // parenthesisMatch("(({}{}[[]]))");
    // infixToPostfix_parenthesized("((a+b)-c)");
    infixToPostfix("a+b*c-d/e");
    // stack_linkedList st;

    // specialStack st;
    // st.push(1);
    // st.push(2);
    // st.push(3);
    // st.push(4);
    // st.push(5);
    // st.push(6);
    // st.push(7);
    // findMiddle(st);

    // st.display();    
    // cout<<st.getMin();
    return 0;
}