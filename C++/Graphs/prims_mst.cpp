#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    vector<vector<pair<int,int> > > adj;
    int V;

    Graph(int vertices) : V(vertices)
    {
        adj.resize(V);
    }
    void addEdge(int src, int dest, int weight)
    {
        adj[src].push_back(make_pair(weight,dest));
        adj[dest].push_back(make_pair(weight,src));
    }

    int primsMST(){
        vector<bool> visited(V,false);
        vector<int> weights(V,INT_MAX);
        vector<int> parents(V,-1);

        priority_queue< pair<int,int>, vector <pair<int,int> > , greater<pair<int,int> > > pq;
        pq.push(make_pair(0,0));
        weights[0]=0;

        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();

            if(visited[u]){
                continue;
            }

            visited[u] = true;

            vector<pair<int,int> >::iterator itr;
            for(itr = adj[u].begin();itr!=adj[u].end();itr++){
                int v = (*itr).second;
                int w = (*itr).first;

                if(!visited[v] && weights[v]>w){
                    weights[v] = w;
                    pq.push(make_pair(weights[v],v));
                    parents[v] = u;
                }
            }
        }
        //foreach vertex key and value
        //
        int cost = 0;
        for (int i = 0; i < V; ++i){
            cost+=weights[i];
        }
        return cost;
    }
};
int main()
{
    Graph graph(5);
    graph.addEdge(0, 1, 15);
    graph.addEdge(0, 4, 25);
    graph.addEdge(1, 2, 35);
    graph.addEdge(2, 4, 45);
    graph.addEdge(2, 3, 55);
    graph.addEdge(3, 4, 65);
    //printGraph(graph);
    
    cout << "weight of minimum spanning tree : " << graph.primsMST();

    return 0;
}