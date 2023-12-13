#include<bits/stdc++.h>
using namespace std;
class doSort{
    public:
        void bubble_sort(int a[], int n){
            cout<<"Bubble Sort: ";
                bool swapped;
            for(int i=0;i<n-1;i++){
                swapped=false;
                for(int j=0;j<n-1-i;j++){
                    if(a[j]>a[j+1]){
                        int temp=a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp;
                        swapped=true;
                    }
                }
                if(swapped==false)
                    break;
            }
            }
        void selection_sort(int a[], int n){
            cout<<"Selection sort: ";
            int min_index;
            for(int i=0;i<n;i++){
                min_index=i;
                for(int j=i+1;j<n;j++){
                    if(a[min_index]>a[j]){
                        min_index=j;
                    }
                }
                int temp=a[i];
                a[i]=a[min_index];
                a[min_index]=temp;
            }
        }
        void insertion_sort(int a[], int n){
            cout<<"Insertion Sort: ";
            int temp,j;
            for(int i=1;i<n;i++){
                temp=a[i];
                j=i-1;
                while(j>=0 && a[j]>temp){
                    a[j+1]=a[j];
                    j--;
                }
                a[j+1]=temp;
            }
        }
};

int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    doSort obj;
    //obj.bubble_sort(a, n);
    obj.selection_sort(a, n);
    //obj.insertion_sort(a, n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
