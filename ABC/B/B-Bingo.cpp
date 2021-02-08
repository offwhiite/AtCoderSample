#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    vector <vector<int> > v(3,vector<int>(3,0));
    for (int i = 0; i < 3; ++i) 
    for (int j = 0; j < 3; ++j) {
        cin >> v[i][j];
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int b = 0;
        cin >> b;

        for (int i = 0; i < 3; ++i) 
        for (int j = 0; j < 3; ++j) {
            if (v[i][j] == b) v[i][j] = 0;
        }
    } 
    if (v[0][0] + v[0][1] + v[0][2] == 0 ||
        v[1][0] + v[1][1] + v[1][2] == 0 ||
        v[2][0] + v[2][1] + v[2][2] == 0 ||
        v[0][0] + v[1][0] + v[2][0] == 0 ||
        v[0][1] + v[1][1] + v[2][1] == 0 ||
        v[0][2] + v[1][2] + v[2][2] == 0 ||
        v[0][0] + v[1][1] + v[2][2] == 0 ||
        v[0][2] + v[1][1] + v[2][0] == 0 ) {
            cout << "Yes" << endl;
            return 0;
    }   
    cout << "No" << endl;
    return 0;
}