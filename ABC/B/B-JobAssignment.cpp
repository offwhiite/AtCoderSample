#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int N; cin >> N;
    vector <pair<int, int> > A(N,pair<int, int>());
    vector <pair<int, int> > B(N,pair<int, int>());

    for (int i = 0; i < N; ++i) {
        int Ai, Bi;
        cin >> Ai >> Bi;
        A[i] = pair<int, int>(Ai, i);
        B[i] = pair<int, int>(Bi, i);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ans = INT32_MAX;
    if(A[0].second == B[0].second) {
        int a = max(A[1].first, B[0].first);
        int b = max(A[0].first, B[1].first);
        int c = A[0].first + B[0].first;
        ans = min(c, min(a, b));
    } else {
        ans = max(A[0].first, B[0].first);
    }
    
    cout  << ans << endl;
    return 0;
}