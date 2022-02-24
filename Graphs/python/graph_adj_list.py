from collections import defaultdict
#adjacency list representation of the node
class AdjNode:
    def __init__(self,data):
        self.vertex = data
        self.next = None

# Class to represent graph
# Graph is list of adjacency lists.
# Size of list is number of vertices "V"
class AdjListGraph:
    def __init__(self,vertices):
        self.V = vertices
        # self.graph = [None] * self.V
        self.adjList = defaultdict(list)
    
    # function to add edge in a directed graph
    def add_edge(self,src,dest):
        # node = AdjNode(dest)
        # node.next = self.graph[src]
        # self.graph[src] = node
        self.adjList[src].append(dest)
    
    def print_graph(self):
        for i in range(self.V):
            print("{}".format(i),end="->")
            print(self.adjList[i])
            
    def get_transpose(self):
        transpose = AdjListGraph(self.V)
  
        # Recur for all the vertices adjacent to this vertex
        for i in self.adjList:
            for j in self.adjList[i]:
                transpose.add_edge(j,i)
        return transpose
    
    def BFS(self,s):

        #visited array
        visited = [False] * self.V

        queue = []
        queue.append(s)
        visited[s] = True

        while queue:
            s = queue.pop(0)
            print(s,end = " ")

            for i in self.adjList[s]:
                if visited[i] == False:
                    queue.append(i)
                    visited[i] = True
        print()
V = 5
graph = AdjListGraph(V)
# graph.print_graph()
graph.add_edge(0, 1)
# graph.add_edge(0, 4)
graph.add_edge(1, 2)
graph.add_edge(1, 3)
# graph.add_edge(1, 4)
graph.add_edge(2, 3)
# graph.add_edge(3, 4)
graph.add_edge(4, 0)
 
# graph.print_graph()

def get_graph():
    return graph
             