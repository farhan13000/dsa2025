// 1D prefix sum using Recursion(Pratyavartan)
#include<bits/stdc++.h>
using namespace std;
#define int long long // Deciding factor => [a1 = 10^9, a2 = 10^9, a3, ..., an = 10^9] <= 10^9 and n <= 10^5 =====> 10^14 > 10^9(int) so we will need for long long


void calculate_prefix_sum(int n, vector<int> &a, vector<int> &pref) {
    if (n == 0) {
        pref[n] = a[n];
        return;
    }
    calculate_prefix_sum(n - 1, a, pref);
    pref[n] = pref[n-1] + a[n];
    cout << pref[n] << " ";
}

// n-- => n = n - 1
// n - 1 ;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> pref(n, a[0]);
    calculate_prefix_sum(n - 1, a, pref); // Expectation with this function is to calculate the prefix sum of the array from index [0 ... n-1] and that will be stored in the pref array
    for (auto it : pref) cout << it << " ";
    return 0;
}