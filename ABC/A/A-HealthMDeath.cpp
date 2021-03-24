#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int N,H;cin >> N >> H;
    if (H%N==0) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;
    return 0;
}