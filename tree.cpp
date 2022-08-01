#include <bits/stdc++.h>
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
    void createLL(){
        
    }
};

int main()
{
    char arr[] = {0,'a','b','c','d','e','f','g','h','i'};
    binaryTree_array <char> bt(arr, 10);
    // bt.input(arr, 10);
    // bt.inOrder(bt.returnArray(),1, 10);
    // cout<<endl;
    // bt.postOrder(bt.returnArray(),1, 10);
    // cout<<endl;
    // bt.preOrder(bt.returnArray(),1, 10);
    
    bt.LevelOrder(bt.returnArray(),1,10);

    return 0;
}