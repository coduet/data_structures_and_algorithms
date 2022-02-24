# Topoogiocal sort is linear ordering of vertices of a graph.
# if G contains an edge G(u,v) then u appears before v in the ordering
# Topologocal sort can be applied only on DAG or directed acyclic graphs
 
from graph_adj_list import AdjListGraph,get_graph


def topological_sort_util(graph,s,visited,stack):

    visited[s]=True

    for v in graph.adjList[s]:
        if visited[v] == False:
            topological_sort_util(graph, v, visited,stack)
    stack.insert(0, s)

    
def topological_sort(graph):

    visited = [False] * graph.V
    stack = []
    
    for v in range(graph.V) :
        if visited[v] == False:
            topological_sort_util(graph, v, visited,stack)
    print(stack)

#create graph
g = AdjListGraph(6)
g.add_edge(5, 2)
g.add_edge(5, 0)
g.add_edge(4, 0)
g.add_edge(2, 4)
g.add_edge(3, 1)

# call topological
topological_sort(g)