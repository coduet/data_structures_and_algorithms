#include<bits/stdc++.h>
using namespace std;

class QuickUnionDisjointSet{
    public:
    QuickUnionDisjointSet(int size):root(size){
        for(int i=0;i<size;i++){
            root[i]=i;
        }
    }

    int find(int x){
        while (x != root[x]) {
            x = root[x];
        }
        return x;
    }

    void Union(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            root[rootY] = rootX;
        }
    }

    bool connected(int x,int y){
        return find(x)==find(y);
    }
    private:
        vector<int> root;
};

int main(){
    cout << boolalpha;
    QuickUnionDisjointSet disjSet(10);
    // 1-2-5-6-7 3-8-9 4
    disjSet.Union(1, 2);
    disjSet.Union(2, 5);
    disjSet.Union(5, 6);
    disjSet.Union(6, 7);
    disjSet.Union(3, 8);
    disjSet.Union(8, 9);
    cout << disjSet.connected(1, 5) << endl;  // true
    cout << disjSet.connected(5, 7) << endl;  // true
    cout << disjSet.connected(4, 9) << endl;  // false
    // 1-2-5-6-7 3-8-9-4
    disjSet.Union(9, 4);
    cout << disjSet.connected(4, 9) << endl;  // true


    return 0;
}
