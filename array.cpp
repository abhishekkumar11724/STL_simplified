#include<bits/stdc++.h>
using namespace std;
#define For(i,a,n) for(int i=a;i<n;i++)

// swap the two elements
void swap(int *a,int *b)
{
    int temp=*a;
    *a = *b;
    *b = temp;
}
// print the array
void printArray(int a[],int n)
{
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
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

/*   we can use bit wise operations to swap two number (using XOR operation) 
    example :- a = 9 and  b = 12
    a = a^b;        ^  = OR operation
    b = a^b;
    a = a^b;
*/


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
int partition_pivotFirstElement(int a[],int low, int high,int n){
    /* for i, swap(stop) if ele of i is greater than pivot
       for j, swap(stop) if ele of j is smaller than pivot */
       int pivot = a[low];
    int i=low, j=high;
    do{
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);
        if(i<j)
        swap(&a[i],&a[j]);

    }while(i<j);
    swap(&a[low],&a[j]);
    return j;
        
}
void quickSort_pivotFirstElement(int a[],int low, int high,int n){
    int j;
    if(low<high){
        j=partition_pivotFirstElement(a,low,high,n);
        quickSort_pivotFirstElement(a,low,j,n);
        quickSort_pivotFirstElement(a,j+1,high,n);
    }
}
//------------------------------------------------------------------------------
int parttiton_pivotLastElement(int a[],int low, int high, int n){
    int pivot = a[high];
    int i= low-1;
   for(int j = low;j<=high-1;j++){
       if(a[j]<pivot){
            i++;           
           swap(a[i],a[j]);
           
       }
   }
    swap(a[high],a[i+1]);
    return i+1;
}

void quickSort_pivotLastElement(int a[],int low,int high,int n){
    int j;
    if(low<high){
        j = parttiton_pivotLastElement(a,low,high,n);
        quickSort_pivotLastElement(a,low, j-1,n);
        quickSort_pivotLastElement(a,j+1,high,n);
    }
}

//******************************************************************************
void  merge(int a[],int b[],int m,int n){
    int i,j,k;
    i=j=k=0;
    int arr[m+n];
    while(i<n && j<m ){
        if( a[i]<b[j])
            arr[k++]=a[i++];
        else
            arr[k++]=b[j++];
    }
    for(;i<n;i++)
        arr[k++]=a[i];
    for(;j<m;j++)
        arr[k++]=b[j];
    
    // return arr;
}
void mergeSort(int a[],int n){
    
}
void redaxSort(int a[],int n);
void shellSort(int a[],int n);

//******************************************************************************
//******************************************************************************


 
// reverse the array using iteration
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

// reverse the array using recusion
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

// finding the min and max of the array
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

// finding the kth min max of the array
void kthMinMaxArray(int a[],int n,int k)
{
    // method 1 : simply sort the array and print the kth min and max
    sort(a,a+n);
    int kthmin,kthmax;
    kthmax = a[k-1];
    kthmin = a[n-k];
    cout<<"\nthe kth max element in the array : "<<kthmax;
    cout<<"\nthe kth max element in the array : "<<kthmin<<endl;
}

// sort an array containing 0, 1, 2 without any sorting algo
void sort_012(int a[],int n)
{
    int num0=0,num1=0,num2=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0) num0++;
        if(a[i]==1) num1++;
        if(a[i]==2) num2++;
    }
    int new_arr[n];
    for(int i=0;i<num0;i++)
    new_arr[i]=0;
    for(int i=0;i<num1;i++)
    new_arr[num0+i]=1;
    for(int i=0;i<num2;i++)
    new_arr[num0+num1+i]=2;

    printArray(new_arr,n);
}

//move all the negitive element to left side of the array
void moveNegitiveToLeft(int a[],int n)
{
    int i=0;
    for(int k=0;k<n;k++)
    {
        if(a[k]<0)
        {
            swap(&a[k],&a[i++]);
        }
    }
    cout<<"the new array is : ";
    printArray(a,n);
    cout<<endl;
}

//find the intersection and union of two array
void intersectionUnion(int a[],int n,int b[],int m)
{
    // union algo
    int unionArray[n+m];
    int i=0,j=0,k=0;
    while(i<n && j<m)
    {
        if(a[i]==b[j])
        {
            if(a[i]==a[i+1])  i++;
            if(b[j]==b[j+1])  j++;
            unionArray[k] = a[i];
            j++,i++,k++;
        }
        else
        {
            if(a[i]<b[j] )
            {
                if(a[i]==a[i+1])  i++;
                unionArray[k] = a[i];
                k++,i++;
            }
            else if(a[i]>b[j])
            {
                if(b[j]==b[j+1])  j++;
                unionArray[k] = b[j];
                k++,j++;
            }
        }
        
    }

    for(;i<n;i++)
        unionArray[k++]=a[i];

    for(;j<m;j++)
        unionArray[k++]=b[j];

    cout<<"\nthe union of the arrays is : ";
    printArray(unionArray,k);
    cout<<endl;

    // intersection algo
    int intscArray[n+m];
    i=0,j=0,k=0;
    while(i<n && j<m)
    {
        if(a[i]==b[j])
        {
                intscArray[k++] = b[j++];
                i++;
        }
        else if(a[i]>b[j])
        {
           if(b[j+1]==a[i]) j=j+2,i++;
           else if( b[j+1] <a[i]) j++;
           else if(b[j+1] > a[i]) j++,i++;
        }
           else if(a[i]<b[j])
        {
           if(a[j+1]==b[i]) i=i+2,j++;
           else if( a[j+1] <b[i]) i++;
           else if(a[j+1] > b[i]) i++,j++;
        }
    }
    cout<<"the intersection of the arrays is : ";
    printArray(intscArray,k);
    cout<<endl;
}
// function to cycliaclly rotate the array
void rotateArray(int a[],int n)
{
    int temp = a[n-1];
    for(int i=n-1;i>0;i--)
    {
        a[i] = a[i-1];
    }
    a[0] = temp;
    cout<<"the array after rotation by one :";
    printArray(a,n);
}

// find the largest sum contiguous sub array
void largestSumContiguousSubarray(int a[],int n)
{
    int temp_sum = 0;
    int new_sum = 0;
    int t=0;
    int sum_array[n];
    sum_array[0] = a[0];
    for(int i=1;i<n;i++)
    {
        sum_array[i] =sum_array[i-1]+ a[i];
    }

    int max = sum_array[0];

    For(i,0,n)
    {
        if(max<sum_array[i])
        { max = sum_array[i]; t=i;}
    }
    
    temp_sum = a[t];
    new_sum = a[t];
    while(t>0)
    {
        temp_sum +=a[t-1];
        if(new_sum<temp_sum)    new_sum = temp_sum;
        t--;
        
    }

    cout<<"the largest sum contiguous sub array is : "<<new_sum;

    // gfg code

//    long long maxSubarraySum(int a[], int n){
        
//         // Your code here
//         int max_till_now = 0;
//     int max_result = INT_MIN;
//     for(int i=0;i<n;i++)
//     {
//         max_till_now = max_till_now+a[i];
//         if(max_till_now>max_result)
//         max_result = max_till_now;

//         if(max_till_now < 0)
//         max_till_now = 0;
//     }

//     return max_result;
//     }

}

// minimise the maximum difference between the hights
int minimiseMaxDifferHight(int a[],int n, int k)
{
    int maxi,mini,diff;
    sort(a,a+n);
    for(int i=1;i<n;i++){
        maxi = max(a[n-1] - k,a[i-1] + k);
        mini = min(a[0] + k, a[i] -k);
        diff = min(diff, maxi - mini);
    }

    return diff;

    //gfg 
    
}

int main()
{
    // int a[]={9,100,56,73,1,22,39,5,88,99};
    // int b[]={19,10,56,73,1,2,39,51,88,9};
    // int a[]={0,1,2,0,0,0,2,1,2,1,1,2};
    int a[]= {-1,3,-5,7,-9,10,8,-6,4,2};
    // int a[]= {-5,7,-9,10,8,-6};
    // int a[] = {2,4,5,7,9};
    int b[] = {2,3,6,7,10};
    int pivot = 5;
    int n= sizeof(a)/sizeof(int);
    int m= sizeof(b)/sizeof(int);
    // cout<<n<<"  "<<m;
    minimiseMaxDifferHight(a,n,6);
    // cout<<n;
    // printArray(a,n);
}