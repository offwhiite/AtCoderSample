#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;
std::vector<bool> IsPrime;

int main() {
    long long N;
    cin >> N;
    long long count = 0;
    map<long long, int> m;
    for (long long i = 2; i * i <= N; ++i) {
        if (m[i]==1) continue;
        for (long long j = 2; powl(i,j) <= N; ++j) {
            // cout << powl(i,j) << endl;
            m[powl(i,j)] = 1;
            count++;
        }
    }
    cout << N - count << endl;
    return 0;
}