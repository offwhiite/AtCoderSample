#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector <int> v(N,0);
    for (int i = 0; i < N; ++i) cin >> v[i];

    sort(v.begin(), v.end());

    long long count = 0;
    for (int i = 0; i < N-K; ++i) count+=v[i];
    
    cout << count << endl;
    return 0;
}