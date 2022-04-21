#include <bits/stdc++.h>

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(vector<int> &arr, int start,int end){

    int pivot = arr[end];

    int i = start-1;

    for( int j= start;j<=end-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }

    }
    swap(&arr[i+1],&arr[end]);
    return i+1;
}

void quickSort(vector<int> &arr,int start,int end){

    if(start>=end)
        return;
    
    int pivot = partition(arr,start,end);    
    quickSort(arr,start,pivot-1);
    quickSort(arr,pivot+1,end);

}

void printArray(vector<int> arr){

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<' ';
    }
    cout<<"\n";
}

int main(){
    vector<int> arr;

    for(int i=0;i<10;i++){
        arr.push_back(rand()%100);
    }

    printArray(arr);
    quickSort(arr,0,arr.size()-1);
    printArray(arr);
    return 0;
}