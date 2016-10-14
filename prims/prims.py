from collections import defaultdict
from heapq import heappush, heappop

infinity = 10**6

class Graph(object):
    def __init__(self, n):
        self.total_nodes = n
        self.graph = defaultdict(lambda:defaultdict(lambda:infinity))
    
    def set_edge(self, x, y, r):
        self.graph[x][y]=self.graph[y][x]= min(r, self.graph[x][y])
    
    def prims(self, source):
        visited = defaultdict(bool)
        edge_total = 0
        node_added = 0
        pq = []
        heappush(pq,(0,source))
        while node_added!=self.total_nodes:
            edge_weight, node = heappop(pq)
            if not visited[node]:
                edge_total+=edge_weight
                node_added+=1
                visited[node]=True
                for adjascent, weight in self.graph[node].items():
                    heappush(pq, (weight,adjascent))
        return edge_total