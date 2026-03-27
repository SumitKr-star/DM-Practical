# DM-Practical
# 1. Create a class SET. Create member functions to perform the following SET operations:
## a. check whether an element belongs to the set or not and return
value as true/false.
```
#include <iostream>
#include <set>
using namespace std;

class SET {
private:
    set<int> s;

public:
    void input() {
        int n, x;
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> x;
            s.insert(x);
        }
    }

    bool isMember(int x) {
        if (s.find(x) != s.end())
            return true;
        else
            return false;
    }
};

int main() {
    SET A;
    A.input();

    int val;
    cout << "Enter element to check: ";
    cin >> val;

    if (A.isMember(val))
        cout << "Element is present in the set.\n";
    else
        cout << "Element is NOT present in the set.\n";

    return 0;
}

```

<br>
 
## b.powerset: list all the elements of the power set of a set.

```
#include <iostream>
#include <vector>
using namespace std;

class SET {
private:
    vector<int> s;

public:
    void input() {
        int n, x;
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> x;
            s.push_back(x);
        }
    }

    // Power set function
    void powerSet() {
        int n = s.size();
        int total = 1 << n;  // 2^n subsets

        cout << "Power Set:\n";
        for (int i = 0; i < total; i++) {
            cout << "{ ";
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    cout << s[j] << " ";
                }
            }
            cout << "}\n";
        }
    }
};

int main() {
    SET A;
    A.input();
    A.powerSet();
    return 0;
}

<br>

```
<br>

## C. subset: check whether one set is a subset of the other or not. 
```
#include <iostream>
#include <set>
using namespace std;

class SET {
private:
    set<int> s;

public:
    void input() {
        int n, x;
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> x;
            s.insert(x);
        }
    }

    void display() {
        for (auto x : s)
            cout << x << " ";
        cout << endl;
    }

    // Subset function
    bool isSubset(SET &B) {
        for (auto x : B.s) {
            if (s.find(x) == s.end()) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    SET A, B;

    cout << "Enter Set A:\n";
    A.input();

    cout << "Enter Set B:\n";
    B.input();

    cout << "Set A: "; A.display();
    cout << "Set B: "; B.display();

    if (A.isSubset(B))
        cout << "B is a subset of A\n";
    else
        cout << "B is NOT a subset of A\n";

    return 0;
}
```

<br>

## d. union and intersection of two Sets.
```
#include <iostream>
#include <set>
using namespace std;

class SET {
private:
    set<int> s;

public:
    void input() {
        int n, x;
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> x;
            s.insert(x);
        }
    }

    void display() {
        for (auto x : s)
            cout << x << " ";
        cout << endl;
    }

    // Union of two sets
    SET setUnion(SET &B) {
        SET result;
        result.s = s;

        for (auto x : B.s) {
            result.s.insert(x);
        }
        return result;
    }

    // Intersection of two sets
    SET setIntersection(SET &B) {
        SET result;

        for (auto x : s) {
            if (B.s.find(x) != B.s.end()) {
                result.s.insert(x);
            }
        }
        return result;
    }
};

int main() {
    SET A, B;

    cout << "Enter Set A:\n";
    A.input();

    cout << "Enter Set B:\n";
    B.input();

    cout << "Set A: "; A.display();
    cout << "Set B: "; B.display();

    // Union
    SET U = A.setUnion(B);
    cout << "Union: ";
    U.display();

    // Intersection
    SET I = A.setIntersection(B);
    cout << "Intersection: ";
    I.display();

    return 0;
}
```
<br>

## e. complement: assume universal set as per the input elements from the user. 
```
#include <iostream>
#include <set>
using namespace std;

class SET {
private:
    set<int> s;

public:
    void input() {
        int n, x;
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> x;
            s.insert(x);
        }
    }

    void display() {
        for (auto x : s)
            cout << x << " ";
        cout << endl;
    }

    // Complement function
    SET complement(SET &U) {
        SET result;

        for (auto x : U.s) {
            if (s.find(x) == s.end()) {
                result.s.insert(x);
            }
        }
        return result;
    }
};

int main() {
    SET A, U;

    cout << "Enter Set A:\n";
    A.input();

    cout << "Enter Universal Set U:\n";
    U.input();

    cout << "Set A: "; A.display();
    cout << "Universal Set U: "; U.display();

    SET C = A.complement(U);

    cout << "Complement of A (A'): ";
    C.display();

    return 0;
}

```

<br>

## f. set difference and symmetric difference between two sets. 
```
#include <iostream>
#include <set>
using namespace std;

class SET {
private:
    set<int> s;

public:
    void input() {
        int n, x;
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> x;
            s.insert(x);
        }
    }

    void display() {
        for (auto x : s)
            cout << x << " ";
        cout << endl;
    }

    // Set Difference (A - B)
    SET difference(SET &B) {
        SET result;
        for (auto x : s) {
            if (B.s.find(x) == B.s.end()) {
                result.s.insert(x);
            }
        }
        return result;
    }

    // Symmetric Difference (A Δ B)
    SET symmetricDifference(SET &B) {
        SET result;

        // Elements in A but not in B
        for (auto x : s) {
            if (B.s.find(x) == B.s.end()) {
                result.s.insert(x);
            }
        }

        // Elements in B but not in A
        for (auto x : B.s) {
            if (s.find(x) == s.end()) {
                result.s.insert(x);
            }
        }

        return result;
    }
};

int main() {
    SET A, B;

    cout << "Enter Set A:\n";
    A.input();

    cout << "Enter Set B:\n";
    B.input();

    cout << "Set A: "; A.display();
    cout << "Set B: "; B.display();

    // Difference A - B
    SET D = A.difference(B);
    cout << "A - B: ";
    D.display();

    // Symmetric Difference
    SET SD = A.symmetricDifference(B);
    cout << "Symmetric Difference: ";
    SD.display();

    return 0;
}
```
<br>

## g. cartesian product of sets.
```
#include <iostream>
#include <set>
using namespace std;

class SET {
private:
    set<int> s;

public:
    void input() {
        int n, x;
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> x;
            s.insert(x);
        }
    }

    void display() {
        for (auto x : s)
            cout << x << " ";
        cout << endl;
    }

    // Cartesian Product
    void cartesianProduct(SET &B) {
        cout << "Cartesian Product (A x B):\n";
        for (auto x : s) {
            for (auto y : B.s) {
                cout << "(" << x << ", " << y << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    SET A, B;

    cout << "Enter Set A:\n";
    A.input();

    cout << "Enter Set B:\n";
    B.input();

    cout << "Set A: "; A.display();
    cout << "Set B: "; B.display();

    A.cartesianProduct(B);

    return 0;
}
```

<br>

