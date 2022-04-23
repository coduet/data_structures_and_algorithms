#include <bits/stdc++.h>
using namespace std;

class UnionByRank{
    private:
        vector<int> root;
        vector<int> rank;
    public:
        UnionByRank(int size):root(size),rank(size){
            for(int i=0;i<size;i++){
                rank[i] = 1;
                root[i] = i;
            }
        }

        //path compression
        int find(int x){
            if(x == root[x])
                return x;
            
            return root[x] = find(root[x]);
        }

        //union by rank
        void Union(int x,int y){
            int rootX = find(x);
            int rootY = find(y);

            if(rootX!=rootY){
                if(rank[rootX]<rank[rootY]){
                    root[rootX] = rootY;
                }
                else if(rank[rootX]>rank[rootY]){
                    root[rootY] = rootX;
                }
                else{
                    root[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        }

        bool connected(int x,int y){
            return find(x)==find(y);
        }
};
int main(){
    cout << boolalpha;
    UnionByRank disjSet(10);
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