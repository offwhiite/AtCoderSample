#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int V,T,S,D;
    cin >> V >> T >> S >> D;

    if (V * T <= D && V * S >= D) {
        cout << "No";
    } else {
        cout << "Yes";
    }
    cout << endl;
    return 0;
}