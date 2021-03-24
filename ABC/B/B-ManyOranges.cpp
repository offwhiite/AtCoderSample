#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    long long A,B,W; cin >> A >> B >> W;
    W *= 1000;
    long long aC = W/A;
    long long bC = W/B;
    if (W%B !=0) bC++;

    if (aC < bC) {
        cout << "UNSATISFIABLE" << endl;
    } else {
        cout << bC << " " << aC << endl;
    }
    
    return 0;
}