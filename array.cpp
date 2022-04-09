#include<bits/stdc++.h>
using namespace std;
#define f(a,n) for(int i=a;i<n;i++) 

void printArray(int a[],int n)
{
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void reverseArray(int a[],int n)
{
    int i=0,j=n-1;
    while(i<j)
    {
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
    }
}

void recReverseArray(int a[],int n)
{
    int temp;
    static int i=0,j=n-1;
    if(i<j)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;j--;
        recReverseArray(a,n-1);
    }

}

void maxMinArray(int a[],int n)
{
    int max=a[0],min=a[0];
    for(int i=0;i<n;i++)
    {
        if(max<a[i])
        max=a[i];
        if(min>a[i])
        min=a[i];
    }
    cout<<"max : "<<max<<endl;
    cout<<"min : "<<min<<endl;
}

void kthMinMaxArray(int a[],int n)
{

}

// ************************  sorting algo's ************************************
/*    
        we have total 11 sorting techniques, namely :

        ***comparison based sorting***

    1.    ->  insertion sort          |
    2.    ->  selection sort          |       O( n^2 )
    3.    ->  bubble sort             |
        
    4.    ->  heap sort               |
    5.    ->  merge sort              |       O( n*log(n) )
    6.    ->  quick sort              |  
    7.    ->  tree sort               |

    8.    -> shell sort               |       O( n*3/2 )


        ***index based sorting***

    9.    ->  count sort              |
    10.   ->  bucket/bin sort         |       O(n)
    11.   ->  radix sort              |


*/
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// *****************************************************************************
void insertionSort(int a[],int n){

    /* insertion sort is  adaptive and stable by nature */
   for( int i=1 ; i<n ; i++ ){

       int temp = a[i] , j = i-1;
       while(j>-1 && a[j]>temp){

           a[j+1] = a[j];
           j--;
       }
        a[j+1]= temp;
   }
    cout<<"the sorted array is : \n";
    printArray(a,n);
}

// *****************************************************************************
void bubbleSort(int a[],int n){
    /* flag is used for making algo stable and adaptive */
    /* its kth pass give kth largest element */
    int flag=0;              
   for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
   }

   if(flag == 0){
       cout<<"the array was sorted !!\n";
   }
   else{
       cout<<"the sorted array is : \n";
   }
   printArray(a,n);
}
// *****************************************************************************
void selectionSort(int a[],int n){
    /* selction sort is the only aglo which take minimum number of swaps */
    /* its kth pass gives kth smallest element */
    int j=0,k=0;
    for(int i = 0 ; i<n ; i++){
        j=k=i;
        while(k<n){
            if(a[k]>a[j])
                j=k;
            k++;
        }
        swap(a[i],a[j]);
    }
    cout<<"the sorted array is : \n";
    printArray(a,n);
}
// *****************************************************************************
void partion(int a[],int pivot_index,int low, int high,int n){
    /* for i, swap(stop) if ele of i is greater than pivot
       for j, swap(stop) if ele of j is smaller than pivot */
    int pivot = a[pivot_index];
    int i=low ,j = high , temp = 0;
 do{
     do{i++;} while(a[i]<=pivot);
     do{j--;} while(a[j]>pivot);
     if(a[i]>a[j])
        swap(a[i],a[j]);
 }while(i<j);
 swap(a[low],a[j]);
    printArray(a,n);
        
}
void quickSort(int a[],int pivot_index,int low, int high,int n){
    partion(a,pivot_index,low,high,n);

    
}

void mergeSort(int a[],int n);
void redaxSort(int a[],int n);
void shellSort(int a[],int n);



int main()
{
    // int a[]={9,100,56,73,1,22,39,5,88,99};
    int a[]= {1,3,5,7,9,10,8,6,4,2};
    int pivot_index = 0;
    int n= sizeof(a)/sizeof(int);
    quickSort(a,pivot_index,0,n-1,n);
    cout<<n;
    printArray(a,n);
}