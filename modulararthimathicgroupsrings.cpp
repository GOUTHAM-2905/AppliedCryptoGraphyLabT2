#include <iostream>
using namespace std;

int modAdd(int a, int b, int m) {
    return (a + b) % m;
}

int modSub(int a, int b, int m) {
    return ((a - b) % m + m) % m;
}

int modMul(int a, int b, int m) {
    return (a * b) % m;
}

int modExp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

bool isGroup(int n) {
    return n > 0;
}

bool isRing(int n) {
    return n > 1;
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isField(int n) {
    return isPrime(n);
}

int main() {
    cout << "Mod Add: " << modAdd(7, 5, 12) << endl;
    cout << "Mod Exp: " << modExp(5, 3, 13) << endl;
    cout << "Is Field Z_7: " << isField(7) << endl;
    cout << "Is Field Z_8: " << isField(8) << endl;

    return 0;
}
