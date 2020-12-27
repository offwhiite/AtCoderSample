#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;

    long long a = N % K;
    long long ans = min(a,abs(a-K));
    
    cout  << ans << endl;
    return 0;
}