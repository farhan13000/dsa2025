// Prefix sum on 2D array
#include <bits/stdc++.h>
using namespace std;

// Constraints: n * m <= 10^5
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> prefix_sum(n, vector<int>(m));
    prefix_sum[0][0] = a[0][0];
    // 1st column sum
    for (int i = 1; i < n; ++i) {
        prefix_sum[i][0] = prefix_sum[i - 1][0] + a[i][0];
    }
    // 1st row sum
    for (int j = 1; j < m; ++j) {
        prefix_sum[0][j] = prefix_sum[0][j - 1] + a[0][j];
    }
    // rest of the sum
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] + a[i][j] - prefix_sum[i - 1][j - 1];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << prefix_sum[i][j] << " ";
        }
        cout << endl;
    }
}