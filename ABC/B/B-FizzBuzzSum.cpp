#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    long long sum = 0;
    for (int i = 1; i <= N; ++i) {
        if (i%3 != 0 && i%5 != 0) sum += i;
    }
    
    cout  << sum << endl;
    return 0;
}