#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <deque>
using namespace std;

int main() {
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    bool isReverse = false;
    deque<char> d(S.size());
    for (int i = 0; i < S.size(); ++i) d[i] = S[i];
    for (int i = 0; i < Q; ++i) {
        int t;
        cin >> t;
        if (t==1) {
            if (isReverse) isReverse = false;
            else isReverse = true;
        } else {
            int f;
            cin >> f;
            char C;
            cin >> C;
            if (f==1) {
                if (!isReverse) d.push_front(C);
                else  d.push_back(C);
            } else {
                if (isReverse) d.push_front(C);
                else  d.push_back(C);
            }
        }
    }
    
    if (isReverse) reverse(d.begin(), d.end());
    for (int i = 0; i < d.size(); ++i) cout << d[i]; 
    
    cout << endl;
    return 0;
}