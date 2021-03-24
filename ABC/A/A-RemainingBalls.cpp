#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    string S,T; cin >> S >> T;
    int A,B; cin >> A >> B;
    string U; cin >> U;

    if (U == S) A--;
    else if (U == T) B--;
    
    cout << A << " " << B << endl;
    return 0;
}