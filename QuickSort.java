import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
        int[] arr = {3,1,4,2,5};
        QuickSort Qs=new QuickSort();
        Qs.quicksort(arr,0,arr.length-1);
        for(int i=0;i<arr.length;i++){
            System.out.println(arr[i]);
        }        
	}
}
class QuickSort{
    public int[] quicksort(int arr[],int low, int high){
        if(low<high){
            int pi=partition(arr,low,high);
            quicksort(arr,low,pi-1);
            quicksort(arr,pi+1,high);
        }
        return arr;
    }
    public int partition(int[] arr,int low,int high){
//the below part of code makes quicksort best version by seleccting pivot element randomly
        int randomIndex = low + (int)(Math.random()*(high-low+1));
        int t=arr[randomIndex];
        arr[randomIndex]=arr[high];
        arr[high]=t;
//The part ends, the code will work even without the above mentioned part, but this is the best version
        int pivot=arr[high];
        int i=low-1;
        for(int j=low;j<high;j++){
            if(pivot>=arr[j]){
                i++;
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
        int temp=arr[i+1];
        arr[i+1]=arr[high];
        arr[high]=temp;
        return i+1;
    }
}
