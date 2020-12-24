#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

/**
 * 8の倍数は下3桁が8で割り切れるかどうか
 */
int main() {
    string N;
    cin >> N;

    if (N.size()==1) {
        if (stoi(N)%8 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    } else if (N.size() == 2) {
        int M = (N[1]-'0') * 10 + (N[0]-'0') ;
        if (stoi(N)%8 == 0) {
            cout << "Yes" << endl;
        } else if (M % 8 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    } 

    vector <int> v(10,0);
    for (int i = 0; i < N.size(); ++i) {
        int p = N[i] - '0';
        v[p]++;
    }
    
    for (int i = 13; i * 8 < 1000; ++i) {
        string n = to_string(i * 8);
        bool isMatch = true;
        vector <int> e(10,0); 
        for (int j = 0; j < n.size(); ++j) {
            int d = n[j] - '0';
            e[d]++;
            if (v[d] < e[d]) {
                isMatch = false;
            }
        }
        if (isMatch) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout  << "No" << endl;
    return 0;
}