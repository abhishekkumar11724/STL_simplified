#include <bits/stdc++.h>
using namespace std;

// n<500, l<10^5, k<500


int solve(int d[],int a[],int n,int l,int k){
    if (n==1) return (l-d[n-1])*a[n-1];
    if (k>0)
    return min(solve(d,a,n-1,l,k-1), (l-d[n-1])*a[n-1]+solve(d,a,n-1,d[n-1],k));

    else{
        int val = (l-d[n-1])*a[n-1]+solve(d,a,n-1,d[n-1],k);
        return val;
    }
}

int main()
{
    int n = 4,l = 10, k=2;
    // cin>>n>>l>>k;
    int d[] = {0,3,4,8};
    int a[] = {5,8,3,6};
    cout<<endl<<solve(d,a,n,l,k)<<endl;
    return 0;
}