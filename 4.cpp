#include <iostream>
using namespace std;

int n, C;
int x[15];
int count;

void bruteForce(int pos, int remaining) {
    if (pos == n - 1) {
        if (remaining >= 0) {
            x[pos] = remaining;
            for (int i = 0; i < n; i++) {
                cout << "x" << i + 1 << "=" << x[i];
                if (i < n - 1) cout << " + ";
            }
            cout << " = " << C << "\n";
            count++;
        }
        return;
    }
    for (int val = 0; val <= remaining; val++) {
        x[pos] = val;
        bruteForce(pos + 1, remaining - val);
    }
}

int main() {
    cout << "Enter number of variables (n): ";
    cin >> n;
    cout << "Enter constant C (<=10): ";
    cin >> C;

    if (C > 10) {
        cout << "C must be <= 10\n";
        return 0;
    }

    count = 0;
    cout << "\nAll solutions for x1+x2+...+x" << n << " = " << C << ":\n\n";
    bruteForce(0, C);
    cout << "\nTotal solutions: " << count << "\n";

    return 0;
}