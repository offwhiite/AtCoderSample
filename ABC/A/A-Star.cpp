#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int X; cin >> X;
    long long Y = 0;
    while(X >= Y) Y += 100;
    cout << Y - X << endl;
    return 0;
}