#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

bool isPrime(int X) {
    if (X <= 1) return false;
    for (int i = 2; i * i<= X; ++i) {
        if (X%i == 0) return false;
    }
    return true;
}
int main() {
    int X; cin >> X;
    while(!isPrime(X)) X++;
    cout << X << endl;
    return 0;
}