#include <bits/stdc++.h>
using namespace std;
#define int long long

void calculate_2d_prefix_sum(int i, int j, vector<vector<int>> &a, vector<vector<int>> &prefix_sum) {
    // one element
    if (i == 0 && j == 0) {
        prefix_sum[i][j] = a[i][j];
        return;
    }
    // 1st column
    if (j == 0) {
        calculate_2d_prefix_sum(i - 1, j, a, prefix_sum);
        prefix_sum[i][j] = prefix_sum[i - 1][j] + a[i][j];
        return;
    }
    // 1st row
    if (i == 0) {
        calculate_2d_prefix_sum(i, j - 1, a, prefix_sum);
        prefix_sum[i][j] = prefix_sum[i][j - 1] + a[i][j];
        return;
    }
    // rest of the elements
    if (prefix_sum[i][j] == -1) {
        calculate_2d_prefix_sum(i - 1, j, a, prefix_sum);
        calculate_2d_prefix_sum(i, j - 1, a, prefix_sum);
        calculate_2d_prefix_sum(i - 1, j - 1, a, prefix_sum);
        prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] + a[i][j] - prefix_sum[i - 1][j - 1];
    }
}
signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> prefix_sum(n, vector<int>(m, -1));
    calculate_2d_prefix_sum(n - 1, m - 1, a, prefix_sum);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << prefix_sum[i][j] << " ";
        }
        cout << endl;
    }
}