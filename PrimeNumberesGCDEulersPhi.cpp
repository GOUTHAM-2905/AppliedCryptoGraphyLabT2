#include <iostream>
#include <vector>
using namespace std;

// Check if a number is prime
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Generate primes up to a given limit
vector<int> generatePrimes(int limit) {
    vector<int> primes;

    for (int i = 2; i <= limit; i++) {
        if (isPrime(i))
            primes.push_back(i);
    }
    return primes;
}

// GCD using Euclidean Algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Euler's Totient Function
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

int main() {
    // Primes up to 50
    vector<int> primes = generatePrimes(50);
    cout << "Primes up to 50: ";
    for (int p : primes)
        cout << p << " ";
    cout << endl;

    // GCD
    cout << "GCD(48, 18): " << gcd(48, 18) << endl;

    // Euler Phi
    cout << "Phi(36): " << eulerPhi(36) << endl;

    return 0;
}
