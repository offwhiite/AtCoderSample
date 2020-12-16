#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 何個の祭壇を作れるか返却する
 */
long getTypesSunuke(vector<int> A, vector<int> B, vector<int> C) {
    // sortする(昇順)
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    long count = 0;
    for (int i = 0; i < (int)B.size(); ++i) {
        vector<int>::iterator a = lower_bound(A.begin(), A.end(), B[i]);
        vector<int>::iterator c = upper_bound(C.begin(), C.end(), B[i]);

        long j = a - A.begin();
        long k = C.end() - c;
        count += j * k;
    }
    return count;
}


int main() {
    int N;
    cin >> N;
    vector <int> a(N,0);
    for (int i=0; i<N; ++i) cin >> a[i];
    vector <int> b(N,0);
    for (int i=0; i<N; ++i) cin >> b[i];
    vector <int> c(N,0);
    for (int i=0; i<N; ++i) cin >> c[i];

    cout << getTypesSunuke(a, b, c) << endl;
    return 0;
}