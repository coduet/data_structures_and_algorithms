#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& vec, int x){
    int n = vec.size();

    int low=0,hi=n-1;
    int mid;

    while(hi>=low){
        
        mid = low + (hi-low)/2;
        if(vec[mid]==x){
            return mid;
        }
        else if(vec[mid]>x){
            hi = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    vector<int> vec(10);

    for(int i=0;i<10;i++){
        vec[i]=i*5;
        cout << vec[i] << " ";
    }
    
    cout << "\n" << binarySearch(vec,20);
    cout << binarySearch(vec,7);

    return 0;
}
