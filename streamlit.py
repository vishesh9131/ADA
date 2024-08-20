import streamlit as st
import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import numpy as np
import pandas as pd

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

def create_animation(graph, path, path_memo):
    fig, ax = plt.subplots()

    G = nx.DiGraph()
    n = len(graph)
    for (city, visited), next_cities in path_memo.items():
        for next_city in next_cities:
            G.add_edge((city, visited), (next_city, visited | (1 << next_city)))

    # Add subset attribute to each node
    for node in G.nodes:
        G.nodes[node]['subset'] = bin(node[1]).count('1')

    # Position nodes in a multipartite layout
    pos = nx.multipartite_layout(G, subset_key='subset')

    # Draw the tree
    nx.draw(G, pos, with_labels=True, node_color='lightblue', ax=ax)
    labels = nx.get_edge_attributes(G, 'weight')
    nx.draw_networkx_edge_labels(G, pos, edge_labels=labels, ax=ax)

    def update(frame):
        ax.clear()
        nx.draw(G, pos, with_labels=True, node_color='lightblue', ax=ax)
        nx.draw_networkx_edge_labels(G, pos, edge_labels=labels, ax=ax)

        if frame < len(path) - 1:
            edges = []
            visited = 1 << path[0]
            for i in range(frame + 1):
                edge = ((path[i], visited), (path[i+1], visited | (1 << path[i+1])))
                if edge[0] in pos and edge[1] in pos:  # Ensure both nodes are in pos
                    edges.append(edge)
                visited |= (1 << path[i+1])
            nx.draw_networkx_edges(G, pos, edgelist=edges, edge_color='red', width=2.5, ax=ax)

    ani = animation.FuncAnimation(fig, update, frames=len(path)-1, interval=1000, repeat=False)
    return ani

# Streamlit app
st.title("Traveling Salesman Problem (TSP) Visualization")

st.write("Enter the distance matrix for the TSP:")

# Input matrix
default_matrix = np.array([[0, 10, 15, 20], [5, 0, 9, 10], [6, 13, 0, 12], [8, 8, 9, 0]])
matrix_df = pd.DataFrame(default_matrix, columns=[f"City {i}" for i in range(default_matrix.shape[1])], index=[f"City {i}" for i in range(default_matrix.shape[0])])
matrix_input = st.data_editor(matrix_df, num_rows="dynamic")

# Ensure start_city is within the valid range
max_city_index = matrix_input.shape[0] - 1
start_city = st.number_input("Start City", min_value=0, max_value=max_city_index, value=0)

if st.button("Solve TSP and Show Animation"):
    try:
        # Parse the input matrix
        matrix = matrix_input.values.tolist()
        
        # Ensure the matrix is square
        if any(len(row) != len(matrix) for row in matrix):
            st.error("The distance matrix must be square.")
        elif len(matrix) == 0 or len(matrix[0]) == 0:
            st.error("The distance matrix cannot be empty.")
        else:
            # Ensure start_city is within the valid range after matrix update
            max_city_index = len(matrix) - 1
            if start_city > max_city_index:
                start_city = max_city_index

            min_cost, path, path_memo = tsp(matrix, start_city)
            st.write(f"Minimum path cost: {min_cost}")
            st.write(f"Path: {path}")

            # Create animation
            ani = create_animation(matrix, path, path_memo)

            # Save animation to a file
            ani.save("tsp_animation.gif", writer='imagemagick')

            # Display animation
            st.image("tsp_animation.gif", caption="TSP Solution Animation")

    except Exception as e:
        st.error(f"An error occurred: {e}")