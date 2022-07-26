#include <bits/stdc++.h>
using namespace std;

class linkedList {
    private:
    struct node {
        int data;
        node * next;
    };
    node * root = NULL;
    public:

    node * returnHead(){
        return root;
    }
    node * createnode(int data) {
        node * newnode = new node;
        newnode->data = data;
        newnode->next = NULL;
        return newnode;
    }

    void push(int data) {
        if(root == NULL) {
            root = createnode(data);
        }
        else {
            node * ptr = root;
            while(ptr->next != NULL)
                ptr = ptr->next;
            node * newnode = createnode(data);
            ptr->next = newnode;
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

        /*  here the loop is trying to access a memory that is not assigned 
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

    bool deletenodeByValue(int key) {
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

    bool deletenodeByPosition(int pos) {
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

    int nthnodeInLinkedList(int n) {
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

    int nthnodeFromEnd(int n) {
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

    void middlenode() {
        int totalnode = 0;
        node * ptr = root;
        while(ptr !=NULL) {
            ptr = ptr->next;
            totalnode++;
        }
        int nodeNum = 0;
        
        if(totalnode %2 == 0){
            nodeNum = totalnode/2;
        }
        else {
            nodeNum = totalnode/2+1;
        }
        ptr = root;
        while(ptr != NULL) {
            if(nodeNum == 1) {
                if(totalnode % 2 == 0) {
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
        // here, we had used && instead of || because with && 
        // the loop will stop if even one condition is false
        // but with or 
        while(ptr && ptr->next && tail) {
            
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

    void intersectionOfList(node * r1, node * r2) {
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

    // node * swapnode(node * ptr, node * tail, node * before_ptr, node * before_tail) {
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
                
    //             swapnode(j,i,b_j,b_i);
    //             b_i = i;
    //             i = i->next;
    //         }
    //         b_j = j;
    //         j = j->next;
    //     }
    //     b_i = i;
    //     i = i->next;
    //     swapnode(pivot, i, returnBeforeEnd( low, high), b_i);
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
        node * next;
    };
    node * head = NULL;
    
    public :
    
    node * returnHead() {
        return head;
    }

    node * createnode(int data){
    node * temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
   }

   void push(int data) {
    if(head == NULL) {
        head = createnode(data);
        head->next = head;
    }
    else {
        node * ptr = head;
        node * temp = createnode(data);
        while(ptr->next != head) {
            ptr = ptr->next;
        }   
        ptr->next = temp;
        temp->next = head;
    }
   }
   void display(node * headPtr) {
        node * ptr = headPtr;
        do{
            cout<<ptr->data;
            if(ptr->next != headPtr) {
                cout<<" -> ";
            }
            ptr = ptr->next;
        } while(ptr != headPtr);
   }

   void splitInHalf() {
    node * ptr = head;
    node * h1, * h2;
    
    node * fast, * slow;
    fast = head;
    slow = head;
    while(fast ->next->next != head && fast ->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    if(fast->next->next == head) {
        fast = fast->next;
    }

    h1 = head;
    if(head->next != head)
        h2 = slow->next;
    
    fast->next = slow->next;
    slow->next = head;

    display(h1);
    cout<<endl;
    display(h2);

   }

   void sortedInsert(int data) {
    node * ptr = head, * prev = NULL;
    node * temp = createnode(data);
    if(ptr->data > data){
        prev = head;
        while(prev->next != head){
            prev = prev->next;
        }
        prev->next = temp;
        temp->next = ptr;
        head = temp;
    }
    else{
        while(ptr->next != head){
            if(ptr->data > data){
                break;
            }
            prev = ptr;
            ptr = ptr->next;
        }
        if(ptr->next == head) {
        ptr->next = temp;
        temp->next = head;
        }
        else{
            prev->next = temp;
            temp->next = ptr;
        }
    }   
   }

   bool isCircular(node * head){
    node * Sptr = head;
    node * Fptr = head;
    bool flag = false;
    while(Sptr && Fptr){

        if(Sptr == Fptr) {
            return true;
        }

        Sptr = Sptr->next;
        Fptr = Fptr->next->next;
    }
    return false;
   }
   
   void deletenodeByData(int data) {
    node * ptr = head, * prev = NULL;
    if(ptr->data == data) {
        prev = head;
        while(prev->next != head)
            prev = prev->next;
        
        prev->next = ptr->next;
        head = head->next;
        delete ptr;
        }
    else{
    while(ptr->next != head){
        if(ptr->data == data)
        break;
        prev = ptr;
        ptr = ptr->next;
    }
    
        prev->next = ptr->next;
        delete ptr;
   }
   }

   void deletenodeByAddress(node * dl){
    node * ptr = head;
    node * prev = NULL;
    if(ptr == dl)
    {
        prev = head;
        while(prev->next != head)
            prev = prev->next;
        
        prev->next = ptr->next;
        head = head->next;
        delete ptr;
    }
    else{
    while(ptr->next != head){
        if(ptr == dl)
        break;
        prev = ptr;
        ptr = ptr->next;
    }
    
        prev->next = ptr->next;
        delete ptr;
   }
   }

   void JosephusCircle(int k) {
    int temp = k-1;
    node * ptr = head;
    
    while(ptr->next != ptr) {
        if(!temp){
            node * tnode = ptr->next;
            deletenodeByAddress(ptr);
            ptr = tnode;
            temp = k-1;
        }
        temp--;
        ptr = ptr->next;
    }
    cout<<ptr->data;
   }
};

class doublyLinkedList{
    struct node {
        int data;
        node * next = NULL;
        node * prev = NULL;
    };
    node * head = NULL;

    public:

    node * createnode(int data){
        node * temp = new node;
        temp->data = data;
        return temp;
    }

    void push(int data) {
        if(head == NULL) {
            head = createnode(data);
        }
        else {
            node * ptr = head;
            node * newnode = createnode(data);
            while(ptr->next != NULL)
            ptr = ptr->next;

            ptr->next = newnode;
            newnode->prev = ptr;
        }
    }

    void display(){
        node * ptr = head;
        while(ptr != NULL){
            cout<<ptr->data<<" -> ";
            ptr = ptr->next;
        }
    }

};

int main() {
    linkedList l1;
    linkedList l2;
    // l2;
    l1.push(2);
    l1.push(4);
    l1.push(3);
    l2.push(5);
    l2.push(6);
    l2.push(4);
    // l1.push(6);
    // l1.push(7);
    
   
    // l2.push(40);
    // l2.push(20);
    // l2.push(60);
    // l2.push(10);
    // l2.push(50);
    // l2.push(30);
    // ll.returnRoot()->next->next->next = ll.returnRoot();
    
    // l1.display();
    cout<<endl;

    // l2.display(l2.returnHead());

    // l1.reverseLinkedList();

    cout<<endl;
    // l1.display(l1.returnHead());

    // cout<<endl;
    // l2.display(l2.returnHead());
    return 0;
}