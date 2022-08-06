#include <bits/stdc++.h>
#include "./queue.cpp"
using namespace std;

template <typename T>
class binaryTree_array {
    int size = 0; 
    char *arr;
    
    public :
    binaryTree_array(T temp[], int size) {
        this->size = size;
        arr= new T[size];
        for(int i= 0;i<size; i++){
            arr[i] = temp[i];
        }
        
    }  
    T * returnArray() {
        return arr;
    }
    int preOrder(T arr[], int n, int size) {
        if(n>= size) return 0;
        else{
            cout<<arr[n]<<" ";
            preOrder(arr, 2*n, size);
            preOrder(arr, 2*n +1, size);
        }
    }
    int inOrder(T *arr, int n, int size) {
        if(n>= size) return 0;
        else {
            inOrder(arr, 2*n, size);
            cout<<*(arr+n)<<" ";
            inOrder(arr, 2*n +1, size);
        }
    }
    int postOrder(T arr[], int n, int size) {
        if(n >= size) return 0;
        else {
            postOrder(arr, 2*n, size);
            postOrder(arr, 2*n +1, size);
            cout<<arr[n]<<" ";
        }
    };
    
    int LevelOrder(T arr[],int level, int size) {
        
    };
};

class binaryTree_linkedList {
    struct node {
        int data;
        node * lchild = NULL;
        node * rchild = NULL;
    };
    node * root = NULL;
    public:
    
    node * returnRoot(){
        return root;
    }
    
    void inorder(node * p) {
        if(p) {
                postorder(p->lchild);
                postorder(p->rchild);
                cout<<p->data<<" ";
            }
    }
    void preorder(node * p) {
        if(p){
                postorder(p->lchild);
                postorder(p->rchild);
                cout<<p->data<<" ";
            }
    }
    void postorder(node * p) {
        if(p){
                postorder(p->lchild);
                postorder(p->rchild);
                cout<<p->data<<" ";
            }
    }
    node * createLL_rec() {
        //this function using recursion 
        node * newNode;
        newNode = new node;
        int x;
        cin>>x;
        if(x == -1) return 0;
        else {
            newNode->data = x;
            newNode->lchild = createLL_rec();
            newNode->rchild = createLL_rec();
        }
    }
    void create_rec() {
        if(root == NULL) {
            root = createLL_rec();
        }
    }

    void createLL_itr(node * root) {
        // node * p, * t;
        // queue<node *> q;
        // int data;
        // cin>>data;
        // if(data != -1) {
        //     root = new node;
        //     root->data = data;
        //     q.push(root);
        // }
        // while(!q.empty()) {
        //     node * ptr;
        //     ptr = q.front();
        //     q.pop();
        //     cin>>data;
            
        //     if(data != -1) {
        //         node * newNode = new node;
        //         newNode->data = data;
        //         q.push(newNode);
        //         ptr->lchild = newNode;
        //     }
        //     cin>>data;
        //     if(data != -1) {
        //         node * newNode = new node;
        //         newNode->data = data;
        //         q.push(newNode);
        //         ptr->rchild = newNode;
        //     }
        // }

        node * p, *t;
        int x;
        queue_array_type1<node *> q;
        cin>>x;
        root = new node;
        root->data = x;
        root->lchild = root->rchild = NULL;
        q.enqueue(root);
        while(!q.isEmpty()) {
            // p = q.dequeue();
            cin>>x;
            if(x != -1) {
                t = new node;
                t->data = x;
                t->lchild = t->rchild = NULL;
                p->lchild = t;
                q.push(t);
            }
            cin>>x;
            if(x != -1) {
                t = new node;
                t->lchild = t->rchild = NULL;
                t->data = x;
                p->rchild = t;
                q.push(t);
            }
        }
    }
};

int main()
{
    char arr[] = {0,'a','b','c','d','e','f','g','h','i'};
    // binaryTree_array <char> bt(arr, 10);
    // bt.input(arr, 10);
    // bt.inOrder(bt.returnArray(),1, 10);
    // cout<<endl;
    // bt.postOrder(bt.returnArray(),1, 10);
    // cout<<endl;
    // bt.preOrder(bt.returnArray(),1, 10);
    
    // bt.LevelOrder(bt.returnArray(),1,10);
    binaryTree_linkedList bt;
    bt.createLL_itr(bt.returnRoot());
    bt.preorder(bt.returnRoot());
    cout<<endl;
    bt.inorder(bt.returnRoot());
    cout<<endl;
    bt.postorder(bt.returnRoot());

    return 0;
}