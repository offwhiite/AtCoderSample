#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N,K,R,S,P;
    cin >> N >> K >> R >> S >> P;
    string T;
    cin >> T;
    long long p = 0;
    vector <int> v(N,0);
    for (int i = 0; i < T.size(); ++i) {
        if (T[i] == 'r') {
            if (i < K) p += P;
            else if (T[i-K] != 'r') p += P;
            else if (v[i-K] == 1) p += P;
            else v[i] = 1;
        } else if (T[i] == 's') {
            if (i < K) p += R;
            else if (T[i-K] != 's') p += R;
            else if (v[i-K] == 1) p += R;
            else v[i] = 1;
        } else {
            if (i < K) p += S;
            else if (T[i-K] != 'p') p += S;
            else if (v[i-K] == 1) p += S;
            else v[i] = 1;
        }
    }
    
    cout << p << endl;
    return 0;
}