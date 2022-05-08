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
    }

    void Dijkstra(int src){
        // intitialise single source
        vector<int> dist(V,INT_MAX);
        vector<int> parents(V,-1);
        
    
        priority_queue< pair<int,int>, vector <pair<int,int> > , greater<pair<int,int> > > pq;
        pq.push(make_pair(0,src));
        dist[src]=0;
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();


            vector<pair<int,int> >::iterator itr;
            for(itr = adj[u].begin();itr!=adj[u].end();itr++){
                int v = (*itr).second;
                int d = (*itr).first;
                
                if (dist[v] > dist[u] + d){
                    // Updating distance of v
                    dist[v] = dist[u] + d;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        for (int i=0;i<V;i++){
            cout << i << ":"<<dist[i]<<"\t";
        }
        cout << endl;
    }
        
};
int main()
{
    Graph graph(5);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 5);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 1);
    graph.addEdge(2, 1, 3);
    graph.addEdge(2, 3, 9);
    graph.addEdge(2, 4, 2);
    graph.addEdge(3, 4, 4);
    graph.addEdge(4, 0, 7);
    graph.addEdge(4, 3, 6);
    //printGraph(graph);
    cout << "shortest path from 0 -> ";
    graph.Dijkstra(0);
    cout << "shortest path from 2 -> ";
    graph.Dijkstra(2);

    return 0;
}