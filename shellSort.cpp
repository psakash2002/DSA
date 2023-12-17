#include<bits/stdc++.h>
using namespace std;
void shellSort(int a[],int n){
    for(int gap=n/2;gap>=1;gap=gap/2){
        for(int j=gap;j<n;j++){
            for(int i=j-gap;i>=0;i=i-gap){
                if(a[i+gap]>a[i]){
                    break;
                }
                else{
                    int temp=a[i+gap];
                    a[i+gap]=a[i];
                    a[i]=temp;
                }
            }
        }
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
    shellSort(a,n);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}