#include <iostream>
#include <climits>

using namespace std;

#define SIZE 5 // Renamed the macro to SIZE

void print_mst(int parent[], int graph[][SIZE], int V) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
}

int min_key(int key[], bool mst_set[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; ++v)
        if (mst_set[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void prim_mst(int graph[][SIZE], int V) {
    int parent[V];
    int key[V];
    bool mst_set[V];

    for (int i = 0; i < V; ++i)
        key[i] = INT_MAX, mst_set[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; ++count) {
        int u = min_key(key, mst_set, V);
        mst_set[u] = true;

        for (int v = 0; v < V; ++v)
            if (graph[u][v] && mst_set[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    print_mst(parent, graph, V);
}

int main() {
    int graph[SIZE][SIZE];

    cout << "Enter the adjacency matrix (size " << SIZE << "x" << SIZE << "):\n";
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            cin >> graph[i][j];

    prim_mst(graph, SIZE);

    return 0;
}
