// Simple rolling hash / naive string matching: find all occurrences of pattern p in text t.

#include <bits/stdc++.h>
using namespace std;

int main() {
    string t = "ababcabcababc"; // text
    string p = "abc";           // pattern

    int n = t.size();
    int m = p.size();

    // Compute hash of pattern
    int hp = 0;
    for (int i = 0; i < m; i++)
        hp += (p[i] - 'a' + 1);

    // Check all substrings of length m
    for (int i = 0; i <= n - m; i++) {
        int ht = 0;
        for (int j = 0; j < m; j++)
            ht += (t[i + j] - 'a' + 1);

        // If hash matches, verify characters
        if (ht == hp) {
            int j = 0;
            while (j < m && t[i + j] == p[j]) j++;
            if (j == m) cout << "match at index " << i << "\n";
        }
    }
}
