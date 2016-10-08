from collections import defaultdict
from heapq import heappush, heappop

infinity = 10**6
unvisited = -1

class Graph(object):
    def __init__(self):
        self.graph = defaultdict(lambda: defaultdict(lambda: infinity))
    
    def set_edge(self, u, v, weight):
        self.graph[u][v]=self.graph[v][u]=min(self.graph[u][v],weight)
    
    def dijkstra(self, source):
        priority_q = []
        visited = defaultdict(lambda: unvisited)
        heappush(priority_q,(0,source))
        while len(priority_q):
            distance, current_node = heappop(priority_q)
            if visited[current_node]!=unvisited:
                continue
            visited[current_node] = distance
            for vertex, edge_weight in self.graph[current_node].items():
                if visited[vertex] == unvisited:
                    current_path_distance = distance + edge_weight
                    heappush(priority_q,(current_path_distance , vertex))
        return visited