#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int start, int mid,int end){
    vector<int> temp;

    int i,j;
    i = start;
    j = mid+1;

    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int i=start;i<=end;i++){
        arr[i]=temp[i-start];
    }
}

void mergeSort(vector<int> &arr,int start,int end){    
    if(start>=end)
        return ;

    int mid = start +(end-start)/2;
    mergeSort(arr,start,mid);   
    mergeSort(arr,mid+1,end);   
    merge(arr,start,mid,end);
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
    mergeSort(arr,0,arr.size()-1);
    printArray(arr);
    return 0;
}