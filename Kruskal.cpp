#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
    int src, dest, weight;
};

class Graph {
public:
    int V, E;
    vector<Edge> edges;

    Graph(int v, int e) {
        V = v;
        E = e;
        edges.resize(e);
    }

    void addEdge(int src, int dest, int weight, int index) {
        edges[index] = {src, dest, weight};
    }
};

class DisjointSet {
public:
    int *parent, *rank;
    int n;

    DisjointSet(int n) {
        this->n = n;
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i, rank[i] = 0;
    }

    int find(int u) {
        return u == parent[u] ? u : parent[u] = find(parent[u]);
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            if (rank[x] > rank[y]) swap(x, y);
            parent[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
        }
    }
};

void kruskalMST(Graph &graph) {
    sort(graph.edges.begin(), graph.edges.end(), [](Edge &a, Edge &b) {
        return a.weight < b.weight;
    });

    DisjointSet ds(graph.V);
    vector<Edge> result;

    for (Edge &edge : graph.edges) {
        int x = ds.find(edge.src);
        int y = ds.find(edge.dest);
        if (x != y) {
            result.push_back(edge);
            ds.merge(x, y);
        }
    }

    cout << "Edges in the MST:\n";
    for (Edge &edge : result)
        cout << edge.src << " - " << edge.dest << " \t " << edge.weight << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Graph graph(V, E);

    cout << "Enter the source, destination, and weight for each edge:\n";
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph.addEdge(src, dest, weight, i);
    }

    kruskalMST(graph);

    return 0;
}
