#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    long long H,N;
    cin >> H >> N;
    long long total = 0;
    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        total += a;
    }

    if (total >= H) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    
    cout << endl;
    return 0;
}