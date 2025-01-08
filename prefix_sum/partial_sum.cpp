// Partial Sum in an Array => Given an array[N] and q queries, each query is of the form (l, r, x). For each query, you have to add x to
// all the elements in the range [l, r] 
// and print the final array after all the queries are done.
// Example :        [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] 
//                     +2 +2 +2 +2 
// q_0 : [1,4,2] => [1, 4, 5, 6, 7, 6, 7, 8, 9, 10]
//                        +2 +2 +2 +2
// q_1 : [2,5,2] => [1, 4, 7, 8, 9, 8, 9, 10, 11, 10]
// ...       ...           ....              ...
// Brute Force : For each query, iterate over the range and add x to each element. Time Complexity : O(N*Q)


// Idea for Partial Sum : 
//                   [0, 0, 0, 0, 0, 0, 0, 0, 0]
//q_0 : [1, 4, x] => [0, x, x, x, x, 0, 0, 0, 0]
//q_1 : [2, 5, y] => [0, x, x + y, x + y, x + y, y, 0, 0, 0]


//                          0, 1(l), 2, 3, 4(r), 5, 6, 7, 8
// q_0 : [1(l), 4(r), x] => [0, +x, 0, 0, 0, -x, 0, 0, 0] 
//    => prefix_sum = [0, x, x, x, x, 0, 0, 0, 0]   ========== [0, x, x, x, x, 0, 0, 0, 0] (required after q_0)
// q_1 : [2, 5, y] => [0, x, y, 0, 0, -x, -y, 0, 0]
//    => prefix_sum = [0, x, x + y, x + y, x + y, y, 0, 0, 0]   ========== [0, x, x + y, x + y, x + y, y, 0, 0, 0](required after q_0)
// * NOTE : q_1 is independet of q_0 and vice-verca. So, we can calculate the prefix_sum array after each query and then print the final array after all the queries are done.

#include<bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Original Array : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int q;
    cin >> q;
    vector<int> temp(n, 0);
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        temp[l] += x;
        if (r + 1 < n) {
            temp[r + 1] -= x;
        }
    }
    vector<int> prefix_sum(n, temp[0]);
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + temp[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] += prefix_sum[i];
    }
    cout << "Final Array : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
