#include <bits/stdc++.h>
using namespace std;
int findMax(int a[], int n){
    int max=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}
void countSort(int a[], int n, int max){
    int count[max+1]={0};  //max+1 (dont forget)
    int b[n];
    for(int i=0;i<n;i++){
        ++count[a[i]];
    }
    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        b[--count[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++){
        a[i]=b[i];
    }
}
int main(){
    cout<<"Enter number of elements: ";
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int max=findMax(a,n);
    countSort(a,n,max);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}