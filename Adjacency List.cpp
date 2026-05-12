// Write a Program to check if a given graph is a complete graph. Represent the graph using the Adjacency List representation.

#include <iostream>
using namespace std;

int main() {

    int v, e;

    cout << "Enter number of vertices: ";
    cin >> v;

    cout << "Enter number of edges: ";
    cin >> e;

    int adj[10][10];
    int degree[10];

    for (int i = 0; i < v; i++) {
        degree[i] = 0;
        for (int j = 0; j < v; j++)
            adj[i][j] = -1;
    }

    cout << "Enter edges (u v) 0-indexed:\n";

    for (int i = 0; i < e; i++) {

        int u, v2;
        cin >> u >> v2;

        adj[u][degree[u]++] = v2;
        adj[v2][degree[v2]++] = u;
    }

    cout << "\nAdjacency List:\n";

    for (int i = 0; i < v; i++) {

        cout << i << " -> ";

        for (int j = 0; j < degree[i]; j++)
            cout << adj[i][j] << " ";

        cout << endl;
    }

    bool isComplete = true;

    for (int i = 0; i < v; i++) {

        if (degree[i] != v - 1) {
            isComplete = false;
            break;
        }

        for (int j = 0; j < v; j++) {

            if (i == j) continue;

            bool found = false;

            for (int k = 0; k < degree[i]; k++) {

                if (adj[i][k] == j) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                isComplete = false;
                break;
            }
        }

        if (!isComplete) break;
    }

    cout << "\nThe graph is " << (isComplete ? "" : "not ") << "a Complete Graph";

    return 0;
}
