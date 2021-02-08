#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    double sum = 0;
    vector <int> v(N,0);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        sum+=v[i];
    }
    double checkSum = sum / (4 * M);
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (checkSum <= v[i]) count++;
        if (count == M) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;
    return 0;
}