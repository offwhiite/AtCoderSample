#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

int main() {
    long long N;
    cin >> N;
    long long most = INT64_MAX;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) most = min(most, i + N/i - 2);
    }
    cout << most << endl; 
    return 0;
}