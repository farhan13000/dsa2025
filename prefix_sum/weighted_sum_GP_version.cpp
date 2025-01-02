// Given an array A[n] and q queries, each query is a range [l, r, k]. For each query, calculate the sum of (A[i] * k^(i - l + 1)) for i in [l, r].
// After simplification ans_q => (k^-l) * sum_of(A[i] * k^i) for i in [l, r]

#include <bits/stdc++.h>
using namespace std;
#define int long long

 // O(log(n))
double bin_power(int a, int b) {
    double res = 1.0;
    bool isNegative = b < 0;
    b = abs(b);
    while (b) {
        if (b % 2) {
            res = res * a;
            b--;
        }
        else {
            a = a * a;
            b /= 2;
        }
    }
    return isNegative ? 1.0 / res : res;

}

signed main() {
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] * bin_power(k, i);
    }

    cout << "pref_b array : " ;
    for (auto it : b) {
        cout << it << " ";
    }
    cout << endl;
    // Calculate prefix sum of a
    vector<int> pref_b(n, b[0]);
    for (int i = 1; i < n; ++i) {
        pref_b[i] = pref_b[i - 1] + b[i];
    }
    // Answering queries
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        double ans = bin_power(k, -l) * (pref_b[r] - (l > 0 ? pref_b[l - 1] : 0));
        cout << "ans = "<< ans << '\n';
    }

}
