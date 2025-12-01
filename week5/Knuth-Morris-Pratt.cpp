// KMP string matching: find all occurrences of pattern p in text t.

#include <iostream>
using namespace std;

int main() {
    string t = "ababcabcababc"; // text
    string p = "abc";           // pattern

    int n = t.size();
    int m = p.size();

    // Build LPS (longest prefix suffix) array
    int l[100];
    int a = 0, b = 1;
    l[0] = 0;

    while (b < m) {
        if (p[b] == p[a]) {
            a++;
            l[b] = a;
            b++;
        } else {
            if (a != 0)
                a = l[a - 1];
            else {
                l[b] = 0;
                b++;
            }
        }
    }

    // KMP search
    int i = 0, j = 0;

    while (i < n) {
        if (t[i] == p[j]) {
            i++;
            j++;
        } else {
            if (j != 0)
                j = l[j - 1];
            else
                i++;
        }

        if (j == m) {
            cout << i - j << "\n"; // print match index
            j = l[j - 1];
        }
    }
}
