#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    long long N;
    cin >> N;
    long long a = N / 500;
    long long b = (N % 500) / 5;
    cout  << a * 1000 + b * 5 << endl;
    return 0;
}