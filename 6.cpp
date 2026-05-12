// Write a Program to check if a given graph is a complete graph. Represent the graph using the Adjacency Matrix representation.
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
                
                if (matrix[i][j] != 1 || matrix[i][j] != matrix[j][i]) {
                    isComplete = false;
                    break;
                }
            }
        }
        if (!isComplete) break;
    }

    
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
