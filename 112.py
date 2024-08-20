import itertools
import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.animation as animation

def tsp(graph, start):
    n = len(graph)
    all_visited = (1 << n) - 1
    memo = {}
    path_memo = {}

    def visit(city, visited):
        if visited == all_visited:
            return graph[city][start], [start]
        if (city, visited) in memo:
            return memo[(city, visited)], path_memo[(city, visited)]

        min_cost = float('inf')
        min_path = []
        for next_city in range(n):
            if visited & (1 << next_city) == 0:
                cost, path = visit(next_city, visited | (1 << next_city))
                cost += graph[city][next_city]
                if cost < min_cost:
                    min_cost = cost
                    min_path = [next_city] + path

        memo[(city, visited)] = min_cost
        path_memo[(city, visited)] = min_path
        return min_cost, min_path

    min_cost, path = visit(start, 1 << start)
    path = [start] + path
    return min_cost, path, path_memo

# Example usage
graph = [
    [0, 10, 15, 20],
    [5, 0, 9 , 10],
    [6, 13, 0, 12],
    [8, 8, 9, 0]
]

start_city = 0
min_cost, path, path_memo = tsp(graph, start_city)
print(f"Minimum path cost: {min_cost}")
print(f"Path: {path}")

fig, ax = plt.subplots()

G = nx.DiGraph()
n = len(graph)
for (city, visited), next_cities in path_memo.items():
    for next_city in next_cities:
        G.add_edge(city, next_city)

pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels=True, node_color='lightblue', ax=ax)
labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels, ax=ax)

def update(frame):
    ax.clear()
    nx.draw(G, pos, with_labels=True, node_color='lightblue', ax=ax)
    nx.draw_networkx_edge_labels(G, pos, edge_labels=labels, ax=ax)

    if frame < len(path) - 1:
        edges = [(path[i], path[i+1]) for i in range(frame+1)]
        nx.draw_networkx_edges(G, pos, edgelist=edges, edge_color='red', width=2.5, ax=ax)

ani = animation.FuncAnimation(fig, update, frames=len(path)-1, interval=1000, repeat=False)

plt.show()