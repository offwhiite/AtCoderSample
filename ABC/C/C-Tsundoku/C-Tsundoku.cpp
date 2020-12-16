#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    long long N,M,K;
    cin >> N >> M >> K;
    vector <long long> a(N,0);
    vector <long long> sa(N + 1,0);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        sa[i+1] = sa[i] + a[i]; 
    }

    vector <long long> b(M,0);
    vector <long long> sb(M + 1,0);
    for (int i = 0; i < M; ++i) { 
        cin >> b[i];
        sb[i+1] = sb[i] + b[i];
    }
    
    long long ans = 0;
    for (int i = 0; i < N + 1; ++i) {
        long long left = -1;
        long long right = (long long)sb.size();
        long sum = K - sa[i];
        if (sum < 0) break; // Nの本単体で制限時間を超えてしまっているのならもう探索しなくて良い
        while(right - left > 1) {
            long long mid = left + (right - left) / 2;
            if(sb[mid] > sum) right = mid;
            else left = mid;
        }
        long long tmp = i + left;
        if(ans < tmp) ans = tmp;
    }
    cout  << ans << endl;
    return 0;
}