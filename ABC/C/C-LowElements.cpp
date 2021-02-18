#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;

    int m = INT32_MAX;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        if (m >= a) {
            count++;
        }
        m = min(m, a);
    }

    cout << count << endl;
    return 0;
}