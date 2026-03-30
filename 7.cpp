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

    // Out-degree: sum of row i (edges going OUT from vertex i)
    // In-degree:  sum of column i (edges coming IN to vertex i)
    cout << "\nVertex | In-degree | Out-degree\n";
    cout << "-------|-----------|-----------\n";

    int totalIn = 0, totalOut = 0;

    for (int i = 0; i < v; i++) {
        int outDegree = 0, inDegree = 0;

        for (int j = 0; j < v; j++)
            outDegree += matrix[i][j];  // row sum

        for (int j = 0; j < v; j++)
            inDegree += matrix[j][i];   // column sum

        totalIn  += inDegree;
        totalOut += outDegree;

        cout << "  " << i + 1 << "    |     " << inDegree
             << "     |     " << outDegree << "\n";
    }

    cout << "\nSum of all In-degrees  : " << totalIn  << "\n";
    cout << "Sum of all Out-degrees : " << totalOut << "\n";
    cout << "(Both sums must equal total number of edges)\n";

    return 0;
}