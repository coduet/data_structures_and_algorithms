# SCC or strongly connected component of a directed 
# graph is a maximal set of vertices,
# such that for every pair of vertices 
# u and v in are reachable from each other
# proof of below algorithm - 
# https://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/GraphAlgor/strongComponent.htm
from graph_adj_list import AdjListGraph,get_graph

def dfs_order_util(graph,v,visited,stack):
    visited[v]=True
    for i in graph.adjList[v]:
        if visited[i]== False:
            dfs_order_util(graph, i, visited, stack)
    stack = stack.append(v)

def dfs_util(graph,v,visited):
    visited[v] = True
    print(v,end =" ")

    for i in graph.adjList[v]:
        if visited[i] == False:
            dfs_util(graph, i, visited)

def printSCC(graph):
    stack = []

    visited = [False] * graph.V

    for i in range(graph.V):
        if visited[i] == False:
            dfs_order_util(graph, i, visited, stack)
    
    transpose = graph.get_transpose()
    
    visited = [False] * graph.V

    while stack:
        i = stack.pop()
        if visited[i] == False:
            dfs_util(transpose, i, visited)
            print()

if __name__ == "__main__":
    g = AdjListGraph(5)
    g.add_edge(1, 0)
    g.add_edge(0, 2)
    g.add_edge(2, 1)
    g.add_edge(0, 3)
    g.add_edge(3, 4)

    printSCC(g)