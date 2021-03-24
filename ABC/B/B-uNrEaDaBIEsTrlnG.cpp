#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    string S; cin >> S;
    for (int i = 1; i <= S.length(); ++i) {
        if (i%2!=0 && 'a' <= S[i-1] && 'z' >= S[i-1]) {}
        else if (i%2 == 0 && 'A' <= S[i-1] && 'Z' >= S[i-1]) {}
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    return 0;
}