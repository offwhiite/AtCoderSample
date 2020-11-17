#include <iostream>
#include <vector>
using namespace std;

/**
 * 二分探索
 */
int binary_search(int key, vector<long> v) {
    int left = 0, right = (int)v.size() - 1; // 最小値と最大値
    while (right >= left) {
        int mid = (left +right) / 2; // 区間の真ん中
        if (v[mid] == key) return mid;
        else if (v[mid] > key) right = mid - 1;
        else if (v[mid] < key) left = mid + 1;
    }
    return -1;
}

// int main() {
//     int N;
//     cin >> N;
//     vector<long> s(N,0);
//     for (int i = 0;i < N; ++i) cin >> s[i];
//     int Q;
//     cin >> Q;
//     vector<long> t(Q,0);
//     for (int i = 0;i < Q; ++i) cin >> t[i];
    
//     int count = 0;
//     for (int i = 0;i < Q; ++i) {
//         if (binary_search(t[i], s) != -1) {
//             count++;
//         }
//     }

//     cout << count << endl;
// }