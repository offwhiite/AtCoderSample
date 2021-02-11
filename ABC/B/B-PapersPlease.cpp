#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int N;cin >> N;
    bool isApprove = true;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        if (a % 2 == 0 && (a % 3 == 0 || a % 5 == 0)) continue;
        else if (a % 2 == 1) continue;
        else isApprove = false;
    } 
    if (isApprove) cout << "APPROVED" << endl;
    else cout << "DENIED" << endl;
    return 0;
}