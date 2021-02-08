#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    long long N;
    cin >> N;
    long long ans = N * (N-1) / 2;
    cout << ans << endl;
    return 0;
}