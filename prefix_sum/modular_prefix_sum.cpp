// Given an array A[n] and q queries, each query is a range [l, r, k]. For each query, calculate the (sum of (A[i] * k^(i - l + 1))) % m for i in [l, r].
// After simplification ans_q => ((k^-l) * sum_of(A[i] * k^i)) % m for i in [l, r]

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

 // O(log(n))
int bin_power(int a, int b, int m) {
    int res = 1;
    b = abs(b);
    while (b) {
        if (b % 2) {
            res = (res * a) % m;
            b--;
        }
        else {
            a = (a * a) % m;
            b /= 2;
        }
    }
    return res;
}

signed main() {
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] * bin_power(k, i, mod);
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
        // mod inverse of a number p =  p^(m - 2) % m
        double ans = (pref_b[r] - (l > 0 ? pref_b[l - 1] : 0) * 1.0) / bin_power(bin_power(k, mod - 2, mod), l, mod);

        cout << "ans = "<< ans << '\n';
    }

}
