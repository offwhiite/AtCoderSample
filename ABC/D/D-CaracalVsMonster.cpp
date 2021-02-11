#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    long long H;
    cin >> H;
    long long count = 2;
    while(count <= H) count *= 2;
    cout << fixed << count - 1 << endl;
    return 0;
}