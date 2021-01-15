#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector <int> v(N,0);
    map<int, int> m;
    for (int i = 0; i < N; ++i) cin >> v[i];
    sort(v.begin(),v.end(), greater<int>());
    vector <int> box;
    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            box.push_back(v[i]); 
            continue;
        }
        box.push_back(v[i]); box.push_back(v[i]);
    }

    long long frendly = 0;
    for (int i = 0; i < N-1; ++i) frendly += box[i];
    cout  << frendly << endl;
    return 0;
}