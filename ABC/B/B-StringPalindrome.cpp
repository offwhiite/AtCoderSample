#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    // Sが回文かどうか
    string R = S;
    reverse(R.begin(), R.end());
    if (R != S) {
        cout << "No" << endl;
        return 0;
    }

    // (N-1) / 2文字目チェック
    string s1 = S.substr(0, (N - 1) / 2);
    string r1 = s1;
    reverse(r1.begin(), r1.end());
    if (r1 != s1) {
        cout << "No" << endl;
        return 0;
    }
    string s2 = S.substr((N + 3)/2 - 1, S.size());
    string r2 = s2;
    reverse(r2.begin(), r2.end());
    if (r2 != s2) {
        cout << "No" << endl;
        return 0;
    }
    cout  << "Yes" << endl;
    return 0;
}