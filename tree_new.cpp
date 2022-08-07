#include <bits/stdc++.h>
using namespace std;
#define max 10
    struct node {
    /* here I had explicitly assigned the left and right
        child pointer null otherwise we have assign them 
        null every time we make a new node 

    */
        int data;
        node * lchild = NULL;
        node * rchild = NULL;
    };
class binary_tree {
    struct node * Stack[max];
    int top = -1;
    public:
    void preorder_rec(node * ptr) {
        if(ptr == NULL) {
            return;
        }
        else {
            cout<<ptr->data<<" ";
            preorder_rec(ptr->lchild);
            preorder_rec(ptr->rchild);
        }
    }
    void inorder_rec(node * ptr) {
        if(ptr == NULL) {
            return;
        }
        else {
            preorder_rec(ptr->lchild);
            cout<<ptr->data<<" ";
            preorder_rec(ptr->rchild);
        }
    }
    void postorder_rec(node * ptr) {
        if(ptr == NULL) {
            return;
        }
        else {
            preorder_rec(ptr->lchild);
            preorder_rec(ptr->rchild);
            cout<<ptr->data<<" ";
        }
    }
    void push_stack(node * ptr) {
        if(top == max-1) {
            cout<<"stack overflow !!" <<endl;
            return;
        }
        else {
            top++;
            Stack[top] = ptr;
        }
    }
    node * pop_stack() {
        if(top == -1) {
            cout<<"stack underflow !!"<<endl;
        }
        else {
            top--;
            return Stack[top+1];
        }
    }
    bool stack_empty() {
        if( top == -1) {
            return true;
        }
        return false;
    }
    void preorder_itr(node * root){
    /*  here we are pushing the node in the order of 
        print the current, push right, push left 
    */
        if(root == NULL) {
            cout<<"tree is empty !!"<<endl;
            return;
        }
        push_stack(root);
        while(!stack_empty()) {

            node * temp = pop_stack();
            cout<<temp->data;
            if(temp->rchild != NULL)
                push_stack(temp->rchild);
            if(temp->lchild != NULL)
                push_stack(temp->lchild);
        }
    }
    void inorder_itr(node * root) {
    /*  here we are moving along the left side of the tree
        until we reach the left most node and from there 
        we start popping and printing the node while checking 
        if the node have a right node 
        and if it has we again go along the left side of the
        new sub tree.
    */
        // condition to check if the tree is null

        if(!root) {
            cout<<"tree is empty !!"<<endl;
            return;
        }
        node * ptr = root;
        //loop for traversal
        while(true) {
            while(ptr->lchild) {
                push_stack(ptr);
                ptr = ptr->lchild;
            }
            while(!ptr->rchild){
                cout<<ptr->data;
                if(stack_empty()) 
                    return;
                ptr = pop_stack();
            }
            cout<<ptr->data;
            ptr = ptr->rchild;
        }              
    }
    void postorder_itr(node * root) {
/*  here the procedure is almost same as that of the 
    inorder but the difference is that, in this 
    we push both the right and the left sub trees to 
    the stack( in inorder we push only left subtree)
*/
        if(!root) {
            cout<<"tree is empty !!"<<endl;
            return;
        }
        node * ptr = root;
        node * q = root;
        while(true) {
            while(ptr->lchild) {
                push_stack(ptr);
                ptr = ptr->lchild;
            }
            while(!ptr->rchild || ptr->rchild == q) {
                cout<<ptr->data<<" ";
                q = ptr;
                if(stack_empty()){
                    return;
                }
                ptr = pop_stack();
            }
            cout<<ptr->data<<" ";
            ptr = ptr->rchild;
        }
    }

    // code from """""abdul bari""""""  

    void preOrder(node * t) {
        
        stack<node * > st;
        while(t != NULL || !st.empty()) {
            if(t != NULL) {
                cout<<t->data<<" ";
                st.push(t);
                t = t->lchild;
            }
            else {
                t = st.top();
                st.pop();
                t = t->rchild;
            }
        }
    }
    void inOrder(node * t) {
        stack<node * > st;
        while(t != NULL || !st.empty()) {
            if(t!= NULL) {
                st.push(t);
                t =t->lchild;
            }
            else {
                cout<<t->data;
                t = st.top();
                st.pop();
                t = t->rchild;
            }
        }
    }
    void postOrder(node * t) {
        long int temp;
        stack<node *> st;
        while(t != NULL || !st.empty()) {
            if(t != NULL) {
                st.push(t);
                t = t->lchild;
            }
            else {
                temp = (int)st.top();
                st.pop();
                if(temp > 0) {
                    st.push((node *)-temp);
                    t = ((node *)temp)->rchild;
                }
                else {
                    cout<<((node *) temp) ->data;
                    t = NULL;
                }
            }
        }
    }
    void levelOrder(node * p) {
/*  here the procedure is that we use a queue as an extra DS to store the 
    node address and the steps are like :
    1. push the root node
    2. pop from queue and read and push the left and right child.
*/
        queue<node *> q;
        q.push(p);
        cout<<p->data<<" ";
        while(!q.empty()) {
            p = q.front();
            q.pop();
            if(p->lchild) {
                cout<<p->lchild->data<<" ";
                q.push(p->lchild);
            }
            if(p->rchild) {
                cout<<p->rchild->data<<" ";
                q.push(p->rchild);
            }
        }
    }
    int count(node * root) {
        int x, y;
        if(root) {
            x = count(root->lchild);
            y = count(root->rchild);
            return x+y+1;
        }
        else {
            return 0;
        }
    }
    int count_with_degree2(node * root) {
        int x, y;
        if(root) {
            x = count_with_degree2(root->lchild);
            y = count_with_degree2(root->rchild);
            if(root->rchild && root->lchild)
                return x+y+1;
            else    return x+y;
        }
        else return 0;
    }
    int add_all_nodes(node * root) {
        int x, y;
        if(root) {
            x = add_all_nodes(root->lchild);
            y = add_all_nodes(root->rchild);
            return x +y + root->data;
        }
        else return 0;
    }
    int tree_height(node * root) {
        int x, y ;
        if(root) {
            x = tree_height(root->lchild);
            y = tree_height(root->rchild);
            
        }
    }



    // bool search_left_preorder(node * inorder[], node * index, node * target) {
    //     for(int i = 0; inorder[i] != index; i++) {
    //         if(inorder[i] == target)
    //             return true;
    //     }
    //     return false;
    // }
    // bool search_right_preorder(node * inorder[], node * index, node * target) {
    //     int size = sizeof(inorder)/4;
    //     int idx = 0;
    //     for(int i = 0; i< size; i++){
    //         if(inorder[i] == index) {
    //             idx = i;
    //             break;
    //         }
    //     }
    //     for(int i = idx; i< size; i++){
    //         if(inorder[i] == target) 
    //             return true;
    //     }
    //     return false;
    // }
    // node * tree_from_inorder_preorder (node * inorder[], node * preorder[]) {
    //     node * root = preorder[0];
    //     int size = sizeof(preorder)/4;
    //     int i = 1;
    //     node * ptr = root;
    //     stack <node *> st;
    //     st.push(root);
    //     while(i>size) {
    //         node * temp = preorder[i];
    //         if(!st.empty())
    //         if(search_left_preorder(inorder, ptr, temp)) {
    //             ptr->lchild = temp;
    //             ptr = temp;
    //             st.push(ptr);
    //         }
    //         else {
    //             ptr = st.top();
    //             st.pop();
    //             ptr->rchild = temp;
    //         }
    //         if(st.empty() && temp) {
    //             ptr = ptr->rchild;
    //             st.push(ptr);
    //             ptr->lchild = temp;
    //         }
    //         i++;
    //     }
    //     return root;
    // }
};
class TreeFormation {
    struct ListNode{
        int data;
        ListNode * next;
    };
    struct TreeNode {
        int data;
        TreeNode * lchild;
        TreeNode * rchild;
    };
    public:
    TreeNode * construct_pre_in(ListNode * inPtr, ListNode * prePtr, int num) {

    }
};
int main()
{
    binary_tree bt;

    node * root = new node;
    root->data = 1;
    root->lchild = new node;
    root->rchild = new node;
    root->lchild->data = 2;
    root->rchild->data = 3;

    int pre[] = {1,2,3};
    int in[] = {2,1,3};
    // bt.preorder_itr(root);
    cout<<endl;
    // bt.inorder_itr(bt.tree_from_inorder_preorder(pre, in));
    // cout<<endl;
    // bt.inorder_itr(root);
    // bt.levelOrder(root);
    cout<<bt.add_all_nodes(root);

    return 0;
}