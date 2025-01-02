// Given an array A[n], and q queries, each query is a range [l, r] . For each query, calculate the sum of A[i] * (i - l + 1) for i in [l, r].
// ans_qi =>sum_of(A[i] * i) + (1 - l) * sum_of(A[i])) for i in [l, r]

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] * i;
    }
    // Calculate prefix sum of a
    vector<int> pref_a(n, a[0]);
    for (int i = 1; i < n; ++i) {
        pref_a[i] = pref_a[i - 1] + a[i];
    }
    // Calculate prefix sum of b
    vector<int> pref_b(n, b[0]);
    for (int i = 1; i < n; ++i) {
        pref_b[i] = pref_b[i - 1] + b[i];
    }
    // Answering queries

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        int ans = pref_b[r] - (l > 0 ? pref_b[l - 1] : 0) - (l - 1) * (pref_a[r] - (l > 0 ? pref_a[l - 1] : 0));
        cout << ans << '\n';
    }

}