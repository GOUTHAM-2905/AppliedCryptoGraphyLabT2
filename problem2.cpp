#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

vector<int> buildZn(int n) {
    vector<int> Zn;
    for (int i = 0; i < n; i++)
        Zn.push_back(i);
    return Zn;
}

bool checkClosure(const vector<int>& set, int n) {
    for (int a : set) {
        for (int b : set) {
            int add = (a + b) % n;
            int mul = (a * b) % n;
            if (find(set.begin(), set.end(), add) == set.end()) return false;
            if (find(set.begin(), set.end(), mul) == set.end()) return false;
        }
    }
    return true;
}

bool checkAdditiveInverse(const vector<int>& set, int n) {
    for (int a : set) {
        int inverse = (n - a) % n;
        if (find(set.begin(), set.end(), inverse) == set.end())
            return false;
    }
    return true;
}

bool checkMultiplicativeInverse(const vector<int>& set, int n) {
    for (int a : set) {
        if (a == 0) continue;
        bool found = false;
        for (int b : set) {
            if ((a * b) % n == 1) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

bool checkDistributive(const vector<int>& set, int n) {
    for (int a : set) {
        for (int b : set) {
            for (int c : set) {
                int left = (a * ((b + c) % n)) % n;
                int right = ((a * b) % n + (a * c) % n) % n;
                if (left != right) return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter modulus n: ";
    cin >> n;

    vector<int> Zn = buildZn(n);

    cout << "\nAnalyzing Z_" << n << " = ";
    for (int x : Zn) cout << x << " ";
    cout << endl;

    cout << "\n--- GROUP UNDER ADDITION ---\n";
    cout << "Closure: " << (checkClosure(Zn, n) ? "true" : "false") << endl;
    cout << "Identity exists (0): " << (find(Zn.begin(), Zn.end(), 0) != Zn.end() ? "true" : "false") << endl;
    cout << "Additive inverse: " << (checkAdditiveInverse(Zn, n) ? "true" : "false") << endl;
    cout << "Associativity: TRUE\n";

    cout << "\n--- RING CHECK ---\n";
    cout << "Distributive property: " << (checkDistributive(Zn, n) ? "true" : "false") << endl;

    cout << "\n--- FIELD CHECK ---\n";
    if (isPrime(n) && checkMultiplicativeInverse(Zn, n))
        cout << "Z_n is a FIELD\n";
    else
        cout << "Z_n is NOT a field\n";

    return 0;
}
