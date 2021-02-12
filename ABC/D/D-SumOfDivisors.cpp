#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> v(N+1,0);
    // v にカウントする
    long long sum = 0;
    for (long long i = 1; i <= N; ++i) {
        for (long long j = i; j <= N; j+=i) {
            v[j]+=1;
        }
        sum += i * v[i];
    }
    cout << sum << endl;
    return 0;
}