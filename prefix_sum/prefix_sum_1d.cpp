#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Now we will calculate the prefix sum of the array
    vector<int> pref(n, a[0]);
    for (int i = 1; i < n; ++i) {
        // pref[i] = a[i];
        // if (i > 0) {
        //     pref[i] += pref[i-1];
        // } ==> Also works and a good technique to remember
        pref[i] = pref[i-1] + a[i];
    }

}

// Array = >      [1, 3, 5, 7, 9]
// Prefid=x_sum = [1, 4, 9, 16, 25]
// Relation Between Prefix Sum and Array
// pref_sum[i] = pref_sum[i-1] + a[i] for all i > 0
// Time Complexity: O(n)
// Space Complexity: O(n)
// Need to explore more results and obersevations*