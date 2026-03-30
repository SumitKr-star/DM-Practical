#include <iostream>
using namespace std;

int main() {
    int degree;

    cout << "Enter degree of polynomial: ";
    cin >> degree;

    double coeff[20];
    cout << "Enter " << degree + 1 << " coefficients (highest degree first):\n";
    for (int i = 0; i <= degree; i++) {
        cout << "Coefficient of x^" << degree - i << ": ";
        cin >> coeff[i];
    }

    double x;
    char again;

    do {
        cout << "\nEnter value of x to evaluate: ";
        cin >> x;

        // Horner's method: a0*x^n + a1*x^(n-1) + ... = (...((a0*x + a1)*x + a2)*x...)
        double result = coeff[0];
        for (int i = 1; i <= degree; i++)
            result = result * x + coeff[i];

        // Display polynomial
        cout << "f(x) = ";
        for (int i = 0; i <= degree; i++) {
            if (coeff[i] == 0) continue;
            if (i > 0 && coeff[i] > 0) cout << " + ";
            else if (coeff[i] < 0) cout << " - ";
            double c = (coeff[i] < 0) ? -coeff[i] : coeff[i];
            int power = degree - i;
            if (power == 0)       cout << c;
            else if (power == 1)  cout << c << "x";
            else                  cout << c << "x^" << power;
        }
        cout << "\n";
        cout << "f(" << x << ") = " << result << "\n";

        cout << "\nEvaluate for another value? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}