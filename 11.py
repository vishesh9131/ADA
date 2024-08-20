from itertools import permutations
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
    return min_cost, path

# Example usage
graph = [
    [0, 10, 15, 20],
    [5, 0, 9 , 10],
    [6, 13, 0, 12],
    [8, 8, 9,   0]
]

start_city = 0
min_cost, path = tsp(graph, start_city)
print(f"Minimum path cost: {min_cost}")
print(f"Path: {path}")