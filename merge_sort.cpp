#include <bits/stdc++.h>
using namespace std;

void doMerge(int a[], int lb, int mid, int ub);
void mergeSort(int a[], int lb, int ub){
    int mid;
    if (lb<ub)
    {
        mid=(lb+ub)/2;
        mergeSort(a,lb,mid);
        mergeSort(a,mid+1,ub);
        doMerge(a,lb,mid,ub);
    }
    
}
void doMerge(int a[],int lb, int mid, int ub){
    int i=lb, j=mid+1, k=lb, b[ub+1];
    while(i<=mid && j<=ub){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for(int k=lb;k<=ub;k++){
        a[k]=b[k];
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
    mergeSort(a,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}
