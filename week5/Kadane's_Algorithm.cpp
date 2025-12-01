// Kadane's Algorithm: find the maximum subarray sum.

#include <iostream>
using namespace std;

#define MAX 10000

int main() {
    int n;
    int a[MAX];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int sum = a[0];
    int best = a[0];

    for (int i = 1; i < n; i++) {
        sum = (sum < 0) ? a[i] : sum + a[i];
        if (sum > best) best = sum;
    }

    cout << best;
    return 0;
}
