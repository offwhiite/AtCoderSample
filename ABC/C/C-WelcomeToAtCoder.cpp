#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> v(N+1,0);
    vector<int> wa(N+1,0);
    int sumAC = 0;
    int sumWA = 0;
    for (int i = 0; i < M; ++i) {
        int a;
        string b;
        cin >> a >> b;
        if (v[a]==0 && b == "WA") {
            wa[a]++;
        } else if(v[a]==0 && b == "AC") {
            v[a]=1;
            sumAC++;
            sumWA += wa[a];
        }
    }

    cout << sumAC << " " << sumWA << endl;
    return 0;
}