#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N,K;
    cin >> N >> K;
    vector <int> v(N,0);
    for (int i = 0; i < N; ++i) cin >> v[i];

    sort(v.begin(),v.end());

    int ans = 0;
    for (int i = 0;i < K; ++i) ans += v[i];
    
    cout  << ans << endl;
    return 0;
}