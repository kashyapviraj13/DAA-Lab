// Activity Selection Problem: find max number of non-overlapping activities.

#include <iostream>
using namespace std;

int main() {
    int n = 6;

    int start[6]  = {5, 1, 3, 0, 5, 8};
    int finish[6] = {9, 2, 4, 6, 7, 9};

    // Sort by finish time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (finish[j] > finish[j + 1]) {
                int tempS = start[j];
                int tempF = finish[j];
                start[j]  = start[j + 1];
                finish[j] = finish[j + 1];
                start[j + 1]  = tempS;
                finish[j + 1] = tempF;
            }
        }
    }

    int count = 1;       // choose first activity
    int last = finish[0];

    // Choose compatible activities
    for (int i = 1; i < n; i++) {
        if (start[i] >= last) {
            count++;
            last = finish[i];
        }
    }

    cout << count;
    return 0;
}
