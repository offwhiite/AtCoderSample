#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector <int> v(3,-1);
    for (int i = 0; i < M; ++i) {
        int d,n;
        cin >> d >> n;
        d--;
        if(v[d] == -1 || v[d] == n) v[d] = n;
        else {
            cout << "-1" << endl;
            return 0;
        }
    }

    for (int i = 0; i < N; ++i) {
        int c = v[i];
        if (c == -1 && i != 0) c = 0;
        else if (c == -1 && i == 0) {
            if (N==1) c = 0;
            else c = 1;
        }
        else if (N != 1 && i == 0 && c == 0) {
            cout << "-1" << endl;
            return 0;
        } 
        cout << c;
    }
    cout << endl;
    return 0;
}