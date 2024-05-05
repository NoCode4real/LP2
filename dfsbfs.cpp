#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph {
    unordered_map<int, vector<int>> adjList;

public:
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfsUtil(int v, unordered_set<int>& visited) {
        visited.insert(v);
        cout << v << " ";

        for (int neighbor : adjList[v]) {
            if (visited.find(neighbor) == visited.end()) {
                dfsUtil(neighbor, visited);
            }
        }
    }

    void dfs(int start) {
        unordered_set<int> visited;
        dfsUtil(start, visited);
    }

    void bfs(int start) {
        unordered_set<int> visited;
        queue<int> q;

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int neighbor : adjList[v]) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
    }
};

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    Graph g;

    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    cout << "Depth First Search: ";
    g.dfs(startVertex);
    cout << endl;

    cout << "Breadth First Search: ";
    g.bfs(startVertex);
    cout << endl;

    return 0;
}
