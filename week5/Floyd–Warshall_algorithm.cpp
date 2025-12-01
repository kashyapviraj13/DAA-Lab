// Floyd–Warshall algorithm: find shortest paths between all pairs of vertices.

#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n = 4;
    const int INF = 1000000000;

    int dist[4][4] = {
        {0,   5,   INF, 8},
        {INF, 0,   3,   INF},
        {INF, INF, 0,   7},
        {INF, INF, INF, 0}
    };

    // Update shortest paths
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    int temp = dist[i][k] + dist[k][j];
                    if (temp < dist[i][j]) dist[i][j] = temp;
                }
            }
        }
    }

    // Output result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
