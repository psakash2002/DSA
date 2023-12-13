#include <bits/stdc++.h>
using namespace std;
    int partition(int a[],int lb,int ub){
        int pivot,start,end;
        pivot=a[lb];
        start=lb;
        end=ub;
        while(start<end){
            while(a[start]<=pivot){
                start++;
            }
            while(a[end]>pivot){
                end--;
            }
            if(start<end){
                int temp=a[start];
                a[start]=a[end];
                a[end]=temp;
            }
        }
        a[lb]=a[end];
        a[end]=pivot;
        return end;
    }
    void quickSort(int a[],int lb,int ub){
        if(lb<ub){
            int end=partition(a,lb,ub);
            quickSort(a,lb,end-1);
            quickSort(a,end+1,ub);
        }
    }
    
int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}