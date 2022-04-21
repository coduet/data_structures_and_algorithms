#adjacency list representation of the node
class AdjNode:
    def __init__(self,data):
        self.vertex = data
        self.next = None

# Class to represent graph
# Graph is represented as matrix .
# Size of list is number of vertices "V"
class AdjMatrixGraph:
    def __init__(self,vertices):
        self.adjMatrix = []
        for i in range(vertices):
            self.adjMatrix.append([0 for i in range(vertices)])
        self.V = vertices
    
    # function to add edge in an directed graph
    def add_edge(self,src,dest):
        self.adjMatrix[src][dest] = 1
    
    def print_graph(self):
        for row in self.adjMatrix:
            for val in row:
                print("{}".format(val),end=" ")
            print("")
    
    def BFS(self,s):

        #visited array
        visited = [False] * graph.V

        queue = []
        queue.append(s)
        visited[s] = True

        while queue:
            s = queue.pop(0)
            print(s,end = " ")

            for i in range(len(self.adjMatrix[s])):
                if visited[i] == False and self.adjMatrix[s][i] == 1:
                    queue.append(i)
                    visited[i] = True
        print()

V = 5
graph = AdjMatrixGraph(V)
# graph.print_graph()
graph.add_edge(0, 1)
graph.add_edge(0, 4)
graph.add_edge(1, 2)
graph.add_edge(1, 3)
graph.add_edge(1, 4)
graph.add_edge(2, 3)
graph.add_edge(3, 4)
graph.add_edge(4, 0)
 
# graph.print_graph()

def get_graph():
    return graph
             