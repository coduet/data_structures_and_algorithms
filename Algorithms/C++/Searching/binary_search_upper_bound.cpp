#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int>& vec, int x){
    int n = vec.size();

    int low=0,hi=n-1;
    int mid;

    while(hi>low){
        
        mid = low + (hi-low)/2;
        if(vec[mid] <= x){
            low = mid+1;
        }
        else{
            hi = mid;
        }
    }

    if(low<n && vec[low]<x){
        low++;
    }
    return low;
}

int main(){
    vector<int> vec(10);

    for(int i=0;i<10;i++){
        vec[i]=(i+1)*5;
        cout << vec[i] << " ";
    }
    
    cout << "\n" << upperBound(vec,20);
    cout << upperBound(vec,12);

    return 0;
}
