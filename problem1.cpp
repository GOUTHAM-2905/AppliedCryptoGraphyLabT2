#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int eulerPhi(int n) {
    int result = n;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int a, b;

    cout << "Enter first positive integer: ";
    cin >> a;

    cout << "Enter second positive integer: ";
    cin >> b;

    cout << "\n--- PRIME CHECK ---\n";
    cout << a << " is prime? " << (isPrime(a) ? "true" : "false") << endl;
    cout << b << " is prime? " << (isPrime(b) ? "true" : "false") << endl;

    cout << "\n--- GCD ---\n";
    int g = gcd(a, b);
    cout << "GCD: " << g << endl;

    cout << "\n--- CO-PRIME CHECK ---\n";
    bool coprime = (g == 1);
    cout << "Co-prime? " << (coprime ? "true" : "false") << endl;

    if (coprime) {
        cout << "\n--- EULER PHI ---\n";
        cout << "phi(" << a << ") = " << eulerPhi(a) << endl;
        cout << "phi(" << b << ") = " << eulerPhi(b) << endl;
    }

    cout << "\n--- FERMAT'S LITTLE THEOREM ---\n";
    if (isPrime(b)) {
        cout << "a^(b-1) mod b = " << modExp(a, b - 1, b) << endl;
    } else {
        cout << "Cannot verify: second number not prime" << endl;
    }

    cout << "\n--- EULER'S THEOREM ---\n";
    if (coprime) {
        int phi = eulerPhi(b);
        cout << "a^phi(b) mod b = " << modExp(a, phi, b) << endl;
    } else {
        cout << "Cannot verify: numbers not co-prime" << endl;
    }

    cout << "\n--- MODULAR ARITHMETIC ---\n";
    cout << "(a + b) mod b = " << (a + b) % b << endl;
    cout << "(a * b) mod b = " << (a * b) % b << endl;
    cout << "a^b mod b = " << modExp(a, b, b) << endl;

    return 0;
}
