from graph_adj_list import AdjListGraph,get_graph

def DFSUtil(graph,s,visited):

    visited.add(s)
    print(s,end=" ")

    for v in graph[s]:
        if v not in visited:
            DFSUtil(graph, v, visited)

def DFS(graph,s):
    visited =set()
    DFSUtil(graph, s, visited)
        
def DFS_Unconnected(graph):
    visited =set()

    for v in graph :
        if v not in visited:
            DFSUtil(graph, v, visited)

adjList = get_graph()

adjList.print_graph()

DFS(adjList.graph,0)
print()
DFS_Unconnected(adjList.graph)