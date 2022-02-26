
class WeightedGraph :
    def __init__(self,V):
        self.V = V
        self.adjList = [[] for i in range(V)]
        self.edges = []
    
    def add_edge(self,u,v,wt):
        self.adjList[u].append([v,wt])
        self.adjList[v].append([u,wt])
        self.edges.append([u,v,wt])
    
    def print_graph(self):
        for i in range(self.V):
            print("{}".format(i),end="->")
            for v in self.adjList[i]:
                print(v,end =" ")
            print()
    
    def print_edges(self):
        for edge in self.edges:
            print(edge)

if __name__ == "__main__":
    graph = WeightedGraph(5)

    graph.add_edge(0, 1, 10)
    graph.add_edge(0, 4, 30)
    graph.add_edge(1, 2, 50)
    graph.add_edge(1, 3, 70)
    graph.add_edge(1, 4, 20)
    graph.add_edge(2, 3, 60)
    graph.add_edge(3, 4, 40)

    # graph.print_graph()
    graph.print_edges()