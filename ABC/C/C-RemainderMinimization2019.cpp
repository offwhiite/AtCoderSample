#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    long long L,R; cin >> L >> R;
    if (R - L >= 2019) {
        cout << 0 << endl;
        return 0;
    }
    long long res = 2019;
    for (long long i = L; i <= R;++i) {
        for (long long j = i+1; j <= R; ++j) 
            res = min(res, (i * j) % 2019);
    }
    cout << res << endl;
    return 0;
}