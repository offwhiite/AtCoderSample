#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int A,B; cin >> A >> B;
    int kokei = A + B;

    if (kokei >= 15 && B >= 8) cout << 1;
    else if (kokei >= 10 && B>=3) cout << 2;
    else if (kokei >= 3) cout << 3;
    else cout << 4;

    cout << endl;
    return 0;
}