from graph_weighted_graph import WeightedGraph


def Kruskal_mst(graph):
    #list of edges sorted in non-decreasing order of their weight  
    edges = sorted(graph.edges,key = lambda x : x[2])
    for edge in edges:
        print(edge)
    return 0

if __name__ =="__main__":
    graph = WeightedGraph(5) 

    graph.add_edge(0, 1, 10)
    graph.add_edge(0, 4, 20)
    graph.add_edge(1, 2, 30)
    graph.add_edge(2, 4, 40)
    graph.add_edge(2, 3, 60)
    graph.add_edge(3, 4, 70)

    # graph.print_graph()
    Kruskal_mst(graph)