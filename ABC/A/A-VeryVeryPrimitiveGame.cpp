#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int A,B,C;
    cin >> A >> B >> C;

    if (A > B) {
        cout << "Takahashi";
    } else if (A < B) {
        cout << "Aoki";
    } else {
        if (C==0) cout << "Aoki";
        else cout << "Takahashi";
    }
    
    cout << endl;
    return 0;
}