#include <bits/stdc++.h>
using namespace std;

class DisjSet
{
private:
    vector<int> root;
    vector<int> rank;

public:
    DisjSet(int size) : root(size), rank(size)
    {
        for (int i = 0; i < size; i++)
        {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x)
    {
        if (x == root[x])
            return x;
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
            {
                root[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY])
            {
                root[rootX] = rootY;
            }
            else
            {
                root[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};
class Graph
{
public:
    vector<vector<int> > adjMatrix;
    vector<vector<int> > edgeList;
    int V;

    Graph(int vertices) : V(vertices)
    {
        adjMatrix.resize(V, vector<int>(V, 0));
    }
    void addEdge(int src, int dest, int weight)
    {
        adjMatrix[src][dest] = weight;
        adjMatrix[dest][src] = weight;
        // edgeList.push_back({ w, x, y });
        vector<int> edge;
        edge.push_back(weight);
        edge.push_back(src);
        edge.push_back(dest);
        edgeList.push_back(edge);
        // push_back(dest);
    }

    int kruskalMST()
    {

        // sort all edges by weight
        sort(edgeList.begin(), edgeList.end());

        DisjSet set(V);
        int mstWeight = 0;
        for (int i = 0; i < edgeList.size(); i++)
        {
            int w = edgeList[i][0];
            int x = edgeList[i][1];
            int y = edgeList[i][2];

            // if two edges are not connected
            if (set.find(x) != set.find(y))
            {
                // union two edges
                set.unionSet(x, y);
                mstWeight+=w;
            }
        }
        return mstWeight;
    }
};
void printGraph(Graph const &graph)
{
    for (int i = 0; i < graph.V; i++)
    {
        cout << "\t" << i;
    }
    cout << endl;

    for (int i = 0; i < graph.V; i++)
    {
        cout << i;
        for (int j = 0; j < graph.V; j++)
        {
            cout << "\t" << graph.adjMatrix[i][j];
        }
        cout << endl;
    }
}
int main()
{
    Graph graph(5);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 4, 20);
    graph.addEdge(1, 2, 30);
    graph.addEdge(2, 4, 60);
    graph.addEdge(2, 3, 40);
    graph.addEdge(3, 4, 70);
    //printGraph(graph);
    
    cout << "weight of minimum spanning tree : " << graph.kruskalMST();

    return 0;
}