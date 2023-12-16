#include <bits/stdc++.h>
using namespace std;
int findMax(int a[], int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(max<a[i]){
            max=a[i];
        }
    }
    return max;
}
void countSort(int a[], int n, int pos){
    int count[10]={0};
    int b[n];
    for(int i=0;i<n;i++){
        ++count[(a[i]/pos) % 10];
    }
    for(int i=1;i<sizeof(count);i++){
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        b[--count[(a[i]/pos)%10]]=a[i];
    }
    for(int i=0;i<n;i++){
        a[i]=b[i];
    }
}

void radixSort(int a[], int n, int max){
    for(int pos=1; max/pos>0;pos*=10){          //remember pos*=10
        countSort(a, n, pos);
    }
}

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int max=findMax(a, n);
    radixSort(a,n,max);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}