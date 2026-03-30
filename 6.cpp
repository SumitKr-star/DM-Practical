#include <iostream>
using namespace std;

int main() {
    int v;
    cout << "Enter number of vertices: ";
    cin >> v;

    int matrix[10][10];

    cout << "Enter adjacency matrix (" << v << "x" << v << ") row by row (0 or 1):\n";
    for (int i = 0; i < v; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < v; j++)
            cin >> matrix[i][j];
    }

    // Display matrix
    cout << "\nAdjacency Matrix:\n";
    cout << "  ";
    for (int i = 1; i <= v; i++) cout << i << " ";
    cout << "\n";
    for (int i = 0; i < v; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < v; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }

    // Check complete graph:
    // 1. No self loops: diagonal must be 0
    // 2. Every other pair must be connected: matrix[i][j]=1 for all i!=j
    // 3. Must be symmetric: matrix[i][j] == matrix[j][i]

    bool isComplete = true;

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (i == j) {
                // diagonal must be 0 (no self loop)
                if (matrix[i][j] != 0) {
                    isComplete = false;
                    break;
                }
            } else {
                // every other cell must be 1 and symmetric
                if (matrix[i][j] != 1 || matrix[i][j] != matrix[j][i]) {
                    isComplete = false;
                    break;
                }
            }
        }
        if (!isComplete) break;
    }

    // Degree check: every vertex must have degree = v-1
    cout << "\nVertex Degrees:\n";
    for (int i = 0; i < v; i++) {
        int degree = 0;
        for (int j = 0; j < v; j++)
            degree += matrix[i][j];
        cout << "Vertex " << i + 1 << " : degree = " << degree << "\n";
    }

    cout << "\nResult: ";
    if (isComplete)
        cout << ">> COMPLETE GRAPH (K" << v << ")\n";
    else
        cout << ">> NOT a Complete Graph\n";

    return 0;
}