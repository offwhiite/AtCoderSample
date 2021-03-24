#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    double A, B; cin >> A >> B;
    cout << fixed << setprecision(15) << (A * 100 -B * 100)/A  << endl;
    return 0;
}