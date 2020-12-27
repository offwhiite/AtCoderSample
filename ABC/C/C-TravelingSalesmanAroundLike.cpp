#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    long long N, K;
    cin >> K >> N;
    vector <long long> v(N,0);
    for (int i = 0; i < N; ++i) cin >> v[i];
    vector <long long> dis(N,0);
    dis[0] = K - v[N-1] + v[0];
    for (int i = 1; i < N; ++i) {
        dis[i] = v[i] - v[i-1]; 
    }

    long long sum = 0;
    long long m = 0;
    for (int i = 0; i < N; ++i) {
        sum += dis[i];
        m = max(m, dis[i]);
    }

    cout  << sum - m << endl;
    return 0;
}