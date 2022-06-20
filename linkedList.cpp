#include <bits/stdc++.h>
using namespace std;

class linkedList {
    private:
    struct node {
        int data;
        node * next = NULL;
    };
    node * root = NULL;
    public:

    node * returnRoot(){
        return root;
    }
    node * createNode(int data) {
        node * newNode = new node;
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }

    void addNode(int data) {
        if(root == NULL) {
            root = createNode(data);
        }
        else {
            node * ptr = root;
            while(ptr->next != NULL)
                ptr = ptr->next;
            node * newNode = createNode(data);
            ptr->next = newNode;
        }
    }


    void display(node * root){
        node * ptr = root;
        while(ptr != NULL) {
            cout<<ptr->data;
            if(ptr->next != NULL)
                cout<<" -> ";
            ptr = ptr->next;
        }
    }

    int search(int key) {
        int index = 0;
        node* ptr = root;
        while( ptr != NULL ) {
            if(ptr->data == key)
                break;
            index++;
            ptr = ptr->next;
        }

        /*  here the loop istrying to access a memory that is not assigned 
            to it, so the compiler just terminate the program at that pint
        */

        // while(ptr->data != key && ptr != NULL) {
        //     index++;
        //     cout<<index<<" "<<ptr->data<<endl;
        //     ptr = ptr->next;
        // }
        cout<<"element found at index "<<index<<endl;
            return 1;
        if(!ptr) {
            cout<<"element not found !!!"<<endl;
            return -1;
        }
        else {
            cout<<"element found at index "<<index<<endl;
            return 1;
        }
    }
    // bool search(int x) 
    // { 
    //     node* current = root; // Initialize current 
    //     while (current != NULL) 
    //     { 
    //         if (current->data == x) 
    //             return true; 
    //         current = current->next; 
    //     } 
    //     return false; 
    // } 

    bool deleteNodeByValue(int key) {
        node * ptr = root;
        node * tail = NULL;
        while(ptr != NULL) {
            if(ptr->data == key) {
                break;
            }
                tail = ptr;
                ptr = ptr->next;
        }
        if(ptr != NULL){
            if(tail == NULL) {
                root = root->next;
                delete(ptr);
                return true;
            }
            else if (ptr->next == NULL) {
                tail->next = NULL;
                delete(ptr);
                return true;
            }
            else {
                tail->next = ptr->next;
                delete(ptr);
                return true;
            }
        }
        else{
            cout<<"key not found !!";
            return false;
        }
    }

    bool deleteNodeByPosition(int pos) {
        node * ptr = root;
        if(pos == 0) {
            root = root->next;
            delete(ptr);
            return true;
        }
        node * tail;
        while(ptr != NULL) {
            if(pos==0) {
                if(ptr->next == NULL) {
                    tail->next = NULL;
                    delete(ptr);
                    return 1;
                }
                tail->next = ptr->next;
                 delete(ptr);
                 return true;
            }
            tail = ptr;
            ptr = ptr->next;
            pos--;
        }
        return false;
    }
    bool deleteLinkedList(node * root) {
        node * ptr = root;
        while(root != NULL) {
            ptr = root;
            root = root->next;
            delete(ptr);
        }
        return true;
    }

    int nthNodeInLinkedList(int n) {
        node * ptr = root;

        while(ptr != NULL) {
            if(n==1) {
                return ptr->data;
            }        
            n--;
            ptr = ptr->next;
        }

        return false;
    }

    int nthNodeFromEnd(int n) {
        node * ptr = root;
        int num=0;
        while (ptr!=NULL) {
            ptr = ptr->next;
            num++;
        }
        ptr = root;
       
        int node_num = num - n;
        while(ptr != NULL) {
            if(node_num==0) {
                return ptr->data;
            }        
            node_num--;
            ptr = ptr->next;
        }

        return false;
    }

    void middleNode() {
        int totalNode = 0;
        node * ptr = root;
        while(ptr !=NULL) {
            ptr = ptr->next;
            totalNode++;
        }
        int nodeNum = 0;
        
        if(totalNode %2 == 0){
            nodeNum = totalNode/2;
        }
        else {
            nodeNum = totalNode/2+1;
        }
        ptr = root;
        while(ptr != NULL) {
            if(nodeNum == 1) {
                if(totalNode % 2 == 0) {
                    cout<<ptr->data<<" "<<ptr->next->data<<endl;
            
                }
                else {
                    cout<<ptr->data<<endl;
                    
                }
            }
            nodeNum--;
            ptr=ptr->next;
        }
    }

    void freqArray() {
        node * ptr = root;
        int max = INT_MIN;
        while(ptr != NULL) {
            if(ptr->data > max) max = ptr->data;
            ptr=ptr->next;
        }
        int fr[max+1];
        for(int i=0; i<max+1; i++) {
            fr[i] = 0;
        }

        ptr = root;

        while(ptr != NULL) {
            fr[ptr->data]++;
            ptr = ptr -> next;
        }

        for(int i=0 ; i<max+1;i++) {
            if(fr[i] != 0) {
                cout<< i << "  " << fr[i] <<endl;
            }
        }

    }

    bool isThereLoop() {
        node * ptr = root;
        node * tail = NULL;
        tail = root;
        ptr=ptr->next;
        while(ptr != NULL && ptr->next == NULL && tail == NULL) {
            
            if(tail == ptr) {
                return true;
            }
            
            tail=tail->next;
            ptr=ptr->next->next;
        }
        return false;
    } 

    int isThereLoop_HashTable() {
        unordered_set <node *> nt;
        node * ptr = root;
        while(ptr != NULL) {
            
            if(nt.find(ptr) == nt.end()) {
                nt.insert(ptr);
            }
            else {
                return 1;
            }
            ptr = ptr -> next;
        }

        return 0;
    }

    int loopLength() {
        node * ptr = root;
        node * tail = root;
        ptr= ptr->next;
        bool flag =false;
        while(ptr != NULL && tail != NULL && ptr->next != NULL) {
            
            if(ptr == tail) {
                flag = true;
                break;
            }
            tail = tail->next;
            ptr =ptr->next->next;
        }
        if(flag == 0) {
            return 0;
        }
        int length = 2;
        ptr = ptr->next; 
        while(ptr != tail) {
            ptr=ptr->next;
            length++;
        }
        return length;
    }

    bool isPalindrome() {
        node * ptr = root;
        stack <int> st;
        if(ptr->next == NULL) return true;
        while(ptr != NULL) {
            st.push(ptr->data);
            ptr = ptr->next;
        }
        ptr = root;
        while(!st.empty()) {
            if(ptr->data != st.top()) {
                return false;
            }
            st.pop();
            ptr = ptr->next;
        }
        return true;
    }

    void removeDuplicateSorted() {
        node * ptr = root;
        node * temp;
        while(ptr != NULL && ptr ->next != NULL) {
            if(ptr->data == ptr->next->data) {
                temp = ptr->next;
                ptr->next = ptr->next->next;
                delete(temp);
            }
            else ptr = ptr->next;
        }
    }

    void removeDuplicateUnsorted() {
        node * ptr = root;
        node * prev = root;
        unordered_set <int> st;
        while(ptr->next != NULL && ptr != NULL) {
            if(st.find(ptr->data) == st.end()) {
                st.insert(ptr->data);
                prev = ptr;
            }
            else {
                prev->next = ptr->next;
            }

            ptr = ptr->next;
        }
    }

    void swap( int x, int y) {
        node * ptr,* tail;
        ptr = root;
        tail = NULL;
        node * n1,* n2, *n1_prev,*n2_prev;
        while(ptr != NULL) {
            if(ptr->data == x) {
                n1 = ptr;
                n1_prev = tail;
            }

            if(ptr->data == y) {
                n2 = ptr;
                n2_prev = tail;
            }

            tail = ptr;
            ptr = ptr->next;
        }
        node * temp = n2->next;
        n1_prev->next = n2;
        n2->next = n1->next;
        n2_prev->next = n1;
        n1->next = temp;
    }

    void pairwiseSwap() {
        node * ptr = root,* tail = NULL;
        
        while( ptr->next->next != NULL) {
            if(tail == NULL) {
                tail = ptr;
                ptr = ptr->next;
                root = ptr;
                tail->next = ptr->next;
                ptr->next = tail;
            }
            else {
                node * temp = tail->next;
                tail->next = ptr;
                temp->next = ptr->next;
                ptr->next = temp;
                tail = tail->next->next;
            }
            
            ptr = ptr->next->next->next;           
        }
    }

    void moveLastToFront() {
        node * ptr = root, * tail = NULL;
        
        while(ptr->next != NULL) {
            tail = ptr;
            ptr = ptr->next;
        }
        
        tail->next = NULL;
        ptr->next = root;
        root = ptr;
    }

    void intesectionOfList(node * r1, node * r2) {
        while (r1 != NULL && r2 != NULL) {
            if(r1->data == r2->data) {
                cout<<r1->data<<" -> ";
                r1 = r1->next;
                r2 = r2->next;
            }
            else if(r1->data > r2->data) {
                r2 = r2->next;                
            }
            else {
                r1 = r1->next;
            }
        }

        while(r1 != NULL) {
            cout<<r1->data<<" -> ";
        }

        while(r2 != NULL) {
            cout<<r2->data<<" -> ";
        }
    }

    // void exchangePointers(node *x,node * y) {
    //     node * temp = x;
    //     x= y;
    //     y = temp;
    // }

    // node * swapNode(node * ptr, node * tail, node * before_ptr, node * before_tail) {
    //     if(!before_tail){
    //         // tail->next = ptr->next;
    //         // ptr->next = tail;
    //         // // change the pointers
    //         // exchangePointers(ptr,tail);

    //         if(before_ptr == tail) {
    //             tail->next = ptr->next;
    //             ptr->next = tail;
                
    //             node * temp = tail;
    //             tail = ptr;
    //             ptr = temp;
    //             return 0;
    //         }
    //         if(before_tail)
    //             before_tail->next = ptr;
    //         node * t_next = tail->next;
    //         tail->next = ptr->next;
    //         ptr->next = t_next;
    //         before_ptr->next = tail;
    //         //change ptrs
    //         node * temp = tail;
    //         tail = ptr;
    //         ptr = temp;
    //         return 0;
    //     }
    //     if(before_ptr == tail) {
    //         before_tail->next = ptr;
    //         tail->next = ptr->next;
    //         ptr->next = tail;
    //         // change the pointers
    //         node * temp = tail;
    //         tail = ptr;
    //         ptr = temp;
    //         return 0;
    //     }
    //     // if(!ptr->next){
    //     //     before_tail->next = ptr;
    //     //     ptr->next = tail;
    //     //     tail->next = NULL;
    //     //     // change the pointers
    //     //     exchangePointers(ptr,tail);
    //     //     return 0;
    //     // }

    //         before_tail->next = ptr;
    //         tail->next = ptr->next;
    //         ptr->next = tail->next;
    //         before_ptr->next = tail;
    //         // change the pointers
    //         node * temp = tail;
    //         tail = ptr;
    //         ptr = temp;
    //         return 0;
        
    // }

    node * returnBeforeEnd(node * head, node * end){
        while(head != NULL && head->next->next != NULL && head->next != end) {
            head = head->next;
        }
        return head;
    }

    node * returnEnd(node * start) {
        while(start->next && start) {
            start = start->next;
        }
        return start;
    }

    // node * quickSortPartition(node * low, node * high){
    //     node * pivot  =  high;
    //     node * i = NULL;
    //     node * j =  low;
    //     node * b_j = NULL;
    //     node * b_i = NULL;
    //     while(j !=  high && j) {
    //         if(j->data <= pivot->data) {
    //             if(i == NULL) i =  low;
                
    //             swapNode(j,i,b_j,b_i);
    //             b_i = i;
    //             i = i->next;
    //         }
    //         b_j = j;
    //         j = j->next;
    //     }
    //     b_i = i;
    //     i = i->next;
    //     swapNode(pivot, i, returnBeforeEnd( low, high), b_i);
    //     return i;
    // }
    // void quickSortOnList( node * low, node * high) {
        
    //     if(low != high && low && high) {
    //         node * pivot = quickSortPartition(low, high);
    //         quickSortOnList(low, returnBeforeEnd(low,pivot));
    //         quickSortOnList(pivot->next, high);
    //     }
    // }

//******************************************************************************************************
//******************************************************************************************************
    node * partition(node * head, node * end, node ** newHead, node ** newEnd) {
        node * prev = NULL;
        node * cur = head;
        node * tail = end;
        node * pivot = end;
        while (cur != pivot) {
            if(cur->data < pivot->data) {
                prev = cur;
                cur = cur->next;
            }
            else {
                node * temp = cur->next;
                if(prev) prev->next = cur->next;
                tail->next = cur;
                cur->next = NULL;
                tail = cur;
                head = temp;
                *newHead = temp;
                
            }
        }
        if (*newHead == NULL)
		(*newHead) = pivot;
        *newEnd = tail;
        return pivot;
    }

    void quickSort(node * head, node * end) {
        node * newHead = NULL;
        node * newEnd = NULL;
        if(head != end) {
            node * pivot = partition(head, end, &newHead, &newEnd);
            root = newHead;

            quickSort(newHead,returnBeforeEnd(newHead,pivot));
            quickSort(pivot->next,newEnd);    
        }
    }

//*****************************************************************************************************
//*****************************************************************************************************

    void reverseLinkedList() {
        node * ptr = root;
        node * next_ptr = ptr->next;
        node * temp = next_ptr->next;;
        while(temp) {
            if(ptr == root) 
                ptr->next = NULL;
            next_ptr->next = ptr;
            // prev_ptr = ptr;
            ptr = next_ptr;
            next_ptr = temp;
            temp=temp->next;
        }
        next_ptr->next = ptr;
        root = next_ptr;
    }
};

/*#####################################################################################################
#####################################################################################################*/

class CircularLinkedList {
    struct node {
        int data;
        node * next = NULL;
        node * prev = NULL;
    };

    public :
    
};

int main()
{
    linkedList l1,l2;
    l1.addNode(7);
    l1.addNode(3);
    l1.addNode(6);
    l1.addNode(5);
    l1.addNode(1);
    l1.addNode(2);
    l1.addNode(4);
    

    l2.addNode(40);
    l2.addNode(20);
    l2.addNode(60);
    l2.addNode(10);
    l2.addNode(50);
    l2.addNode(30);
    // ll.returnRoot()->next->next->next = ll.returnRoot();
    // l1.display(l1.returnRoot());
    // cout<<endl;
    l2.display(l2.returnRoot());

    cout<<endl;
    
    l2.reverseLinkedList();

    // cout<<endl;
    // l2.display(l1.returnRoot());
    cout<<endl;
    l2.display(l2.returnRoot());
    return 0;
}