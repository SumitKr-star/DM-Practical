#include <iostream>
using namespace std;

class RELATION {
    int matrix[10][10];
    int size;

public:
    // Constructor
    RELATION() {
        size = 0;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                matrix[i][j] = 0;
    }

    // -----------------------------------------------
    // Input the relation matrix
    // -----------------------------------------------
    void inputRelation() {
        cout << "Enter the size of the set (max 10): ";
        cin >> size;
        cout << "Enter the relation matrix row by row (0 or 1):\n";
        for (int i = 0; i < size; i++) {
            cout << "Row " << i + 1 << ": ";
            for (int j = 0; j < size; j++)
                cin >> matrix[i][j];
        }
    }

    // -----------------------------------------------
    // Display the matrix
    // -----------------------------------------------
    void displayMatrix() {
        cout << "\nRelation Matrix:\n";
        cout << "  ";
        for (int i = 1; i <= size; i++) cout << i << " ";
        cout << "\n";
        for (int i = 0; i < size; i++) {
            cout << i + 1 << " ";
            for (int j = 0; j < size; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }
    }

    // -----------------------------------------------
    // a. Reflexive: matrix[i][i] = 1 for all i
    // -----------------------------------------------
    bool isReflexive() {
        for (int i = 0; i < size; i++)
            if (matrix[i][i] != 1)
                return false;
        return true;
    }

    // -----------------------------------------------
    // b. Symmetric: matrix[i][j] = matrix[j][i]
    // -----------------------------------------------
    bool isSymmetric() {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (matrix[i][j] != matrix[j][i])
                    return false;
        return true;
    }

    // -----------------------------------------------
    // c. Anti-Symmetric:
    //    if matrix[i][j]=1 and i!=j, then matrix[j][i]=0
    // -----------------------------------------------
    bool isAntiSymmetric() {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (i != j && matrix[i][j] == 1 && matrix[j][i] == 1)
                    return false;
        return true;
    }

    // -----------------------------------------------
    // d. Transitive:
    //    if matrix[i][j]=1 and matrix[j][k]=1,
    //    then matrix[i][k] must be 1
    // -----------------------------------------------
    bool isTransitive() {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (matrix[i][j] == 1)
                    for (int k = 0; k < size; k++)
                        if (matrix[j][k] == 1 && matrix[i][k] != 1)
                            return false;
        return true;
    }

    // -----------------------------------------------
    // Check type of relation
    // Equivalence    = Reflexive + Symmetric + Transitive
    // Partial Order  = Reflexive + AntiSymmetric + Transitive
    // None           = neither of the above
    // -----------------------------------------------
    void checkRelationType() {
        bool ref  = isReflexive();
        bool sym  = isSymmetric();
        bool anti = isAntiSymmetric();
        bool trans = isTransitive();

        cout << "\n--- Relation Properties ---\n";
        cout << "Reflexive     : " << (ref   ? "YES" : "NO") << "\n";
        cout << "Symmetric     : " << (sym   ? "YES" : "NO") << "\n";
        cout << "Anti-Symmetric: " << (anti  ? "YES" : "NO") << "\n";
        cout << "Transitive    : " << (trans ? "YES" : "NO") << "\n";

        cout << "\n--- Relation Type ---\n";
        if (ref && sym && trans)
            cout << ">> EQUIVALENCE RELATION\n";
        else if (ref && anti && trans)
            cout << ">> PARTIAL ORDER RELATION\n";
        else
            cout << ">> NONE (not Equivalence or Partial Order)\n";
    }
};

// -----------------------------------------------
// MENU DRIVEN MAIN
// -----------------------------------------------
int main() {
    RELATION R;
    int choice;

    R.inputRelation();
    R.displayMatrix();

    do {
        cout << "\n====== RELATION OPERATIONS MENU ======\n";
        cout << "1. Check Reflexive\n";
        cout << "2. Check Symmetric\n";
        cout << "3. Check Anti-Symmetric\n";
        cout << "4. Check Transitive\n";
        cout << "5. Check All Properties\n";
        cout << "6. Determine Relation Type (Equivalence / Partial Order / None)\n";
        cout << "7. Display Matrix\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Reflexive: " << (R.isReflexive() ? "YES" : "NO") << "\n";
                break;
            case 2:
                cout << "Symmetric: " << (R.isSymmetric() ? "YES" : "NO") << "\n";
                break;
            case 3:
                cout << "Anti-Symmetric: " << (R.isAntiSymmetric() ? "YES" : "NO") << "\n";
                break;
            case 4:
                cout << "Transitive: " << (R.isTransitive() ? "YES" : "NO") << "\n";
                break;
            case 5:
                R.checkRelationType();
                break;
            case 6:
                R.checkRelationType();
                break;
            case 7:
                R.displayMatrix();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}