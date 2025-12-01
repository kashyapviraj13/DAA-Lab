// Solve the system of congruences using the Chinese Remainder Theorem:
// Find x such that:
//     x ≡ 2 (mod 3)
//     x ≡ 3 (mod 5)
//     x ≡ 2 (mod 7)
// Output the smallest non-negative solution.

#include <iostream>
using namespace std;

int main() {
    int a[3] = {2, 3, 2};  // remainders
    int m[3] = {3, 5, 7};  // moduli
    int n = 3;

    // Compute M = product of all moduli
    int M = 1;
    for (int i = 0; i < n; i++) {
        M *= m[i];
    }

    int result = 0;

    // Apply Chinese Remainder Theorem
    for (int i = 0; i < n; i++) {
        int Mi = M / m[i]; // partial product

        // Find modular inverse of Mi modulo m[i]
        int inverse = -1;
        for (int x = 1; x < m[i]; x++) {
            if ((Mi * x) % m[i] == 1) {
                inverse = x;
                break;
            }
        }

        // Add contribution to result
        result += a[i] * Mi * inverse;
    }

    // Final solution modulo M
    result = result % M;

    cout << "x = " << result << endl;

    return 0;
}
