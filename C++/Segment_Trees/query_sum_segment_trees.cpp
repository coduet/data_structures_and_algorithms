#include<bits/stdc++.h>

using namespace std;

struct SegmentNode{
    int sum;
    pair<int,int> interval;
    SegmentNode* left;
    SegmentNode* right;
};

void buildSegmentTree(SegmentNode* node,vector<int> arr,int start,int end){
    node->interval = make_pair(start,end);
    if(start==end){
        node->left = NULL; 
        node->right = NULL; 
        node->sum = arr[start];
        return;
    }

    node->left = new SegmentNode;
    node->right = new SegmentNode;

    buildSegmentTree(node->left,arr,start,(start+end)/2);
    buildSegmentTree(node->right,arr,(start+end)/2+1,end);
    
    node->sum = node->left->sum + node->right->sum;
    
    return;
}

int querySum(SegmentNode* root,int start,int end){
    if(!root){
        return 0;
    }
    int nodeStart = root->interval.first;
    int nodeEnd = root->interval.second;

    if(nodeEnd < start || nodeStart > end){
        return 0;
    }

    if(nodeStart >= start && nodeEnd <= end){
        return root->sum;
    }

    int leftSum = querySum(root->left,start,end);
    int rightSum = querySum(root->right,start,end);
    return leftSum + rightSum;
}

void updateTree(SegmentNode* root, int pos,int val){
    if(!root){
        return;
    }

    int rootStart = root->interval.first;
    int rootEnd = root->interval.second;

    if(rootStart == rootEnd && rootStart==pos){
        root->sum = val;
        return;
    }

    if(rootStart<= pos && pos<=(rootStart+rootEnd)/2)
    {
        updateTree(root->left,pos,val);
    }
    else{
        updateTree(root->right,pos,val);
    }
    root->sum = root->left->sum + root->right->sum;
}
int main(){
    // define n and array
    int n = 5;
    vector<int> array (n);
    for(int i=0;i<n;i++){
        array[i]  = rand()%50;
        cout<<array[i] <<" ";
    }
    cout<<endl;
    SegmentNode *root = new SegmentNode();
    buildSegmentTree(root,array, 0, n - 1);

    cout << "The sum in the interval [1, 3] is "
        << querySum(root, 1, 3) << '\n';

    cout << "The sum in the interval [1, 4] is "
        << querySum(root, 1, 4) << '\n';

        updateTree(root,1,29);
        cout << "The sum in the interval [1, 4] is "
        << querySum(root, 1, 3) << '\n';

    return 0;
}