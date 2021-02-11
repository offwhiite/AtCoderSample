#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    string S;
    cin >> S;
    vector <int> r;
    vector <int> l;
    vector <int> v(S.length(), 0);
    int p = 0;
    bool isR = true;
    for (int i = 0; i < S.length(); ++i) {
        if (S[i] == 'L' && isR) {
            int dist = i - p;
            v[i] += dist / 2;
            v[i-1]+= dist / 2;
            if (dist >= 1) v[i-1]+= dist % 2;
            p = i + 1;
            isR = false;
        } else if (S[i]=='R') {
            isR = true;
        } else p++;
    }

    p = S.length() - 1;
    bool isL = true;
    for (int i = S.length()-1; i >= 0; --i) {
        if (S[i] == 'R' && isL) {
            int dist = p - i;
            v[i] += dist / 2;
            v[i+1]+= dist / 2;
            if (dist >= 1) v[i+1]+= dist % 2;
            p = i - 1;
            isL = false;
        } else if (S[i] == 'L') isL = true;
        else p--;
    }
    
    for (auto a : v) cout << a << " " ;
    cout << endl;
    return 0;
}