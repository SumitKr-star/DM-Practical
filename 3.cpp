#include <iostream>
using namespace std;

int digits[10];
int n;
int result[10];
bool used[10];

void permuteWithout(int depth) {
    if (depth == n) {
        for (int i = 0; i < n; i++)
            cout << result[i];
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            result[depth] = digits[i];
            permuteWithout(depth + 1);
            used[i] = false;
        }
    }
}

void permuteWith(int depth) {
    if (depth == n) {
        for (int i = 0; i < n; i++)
            cout << result[i];
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        result[depth] = digits[i];
        permuteWith(depth + 1);
    }
}

int main() {
    int choice;

    cout << "Enter number of digits: ";
    cin >> n;
    cout << "Enter the digits: ";
    for (int i = 0; i < n; i++)
        cin >> digits[i];

    do {
        cout << "\n====== PERMUTATION MENU ======\n";
        cout << "1. Without Repetition\n";
        cout << "2. With Repetition\n";
        cout << "3. Both\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < n; i++) used[i] = false;
                permuteWithout(0);
                break;
            case 2:
                permuteWith(0);
                break;
            case 3:
                for (int i = 0; i < n; i++) used[i] = false;
                permuteWithout(0);
                permuteWith(0);
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