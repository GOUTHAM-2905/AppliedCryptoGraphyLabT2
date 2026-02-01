#include <iostream>
using namespace std;

int modExp(int base, int exp, int mod) {
    int result = 1;
    base %= mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

struct DiffieHellmanResult {
    int publicAlice;
    int publicBob;
    int sharedSecretAlice;
    int sharedSecretBob;
};

DiffieHellmanResult diffieHellman(int p, int g, int a, int b) {
    DiffieHellmanResult res;

    res.publicAlice = modExp(g, a, p);
    res.publicBob   = modExp(g, b, p);
    res.sharedSecretAlice = modExp(res.publicBob, a, p);
    res.sharedSecretBob   = modExp(res.publicAlice, b, p);

    return res;
}

int main() {
    DiffieHellmanResult result = diffieHellman(23, 5, 6, 15);

    cout << "Alice public: " << result.publicAlice << endl;
    cout << "Bob public: " << result.publicBob << endl;
    cout << "Shared secret (Alice): " << result.sharedSecretAlice << endl;
    cout << "Shared secret (Bob): " << result.sharedSecretBob << endl;

    return 0;
}
