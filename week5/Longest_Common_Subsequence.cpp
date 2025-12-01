// Longest Common Subsequence (LCS): print length and one LCS string.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Build DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << "Length of LCS = " << dp[n][m] << "\n";

    // Reconstruct LCS
    int i = n, j = m;
    char temp[10000];
    int idx = 0;

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            temp[idx++] = s1[i - 1];
            i--, j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    temp[idx] = '\0';

    // Reverse
    for (int a = 0; a < idx / 2; a++) {
        char t = temp[a];
        temp[a] = temp[idx - 1 - a];
        temp[idx - 1 - a] = t;
    }

    cout << "One LCS = " << temp << "\n";

    return 0;
}
