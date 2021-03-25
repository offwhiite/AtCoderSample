#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;
int f(int n) {
    string s = to_string(n);
    string g1s = s;
    sort(g1s.begin(), g1s.end(),greater<char>());

    string g2s = s;
    sort(g2s.begin(), g2s.end());

    int g1=atoi(g1s.c_str()), g2=atoi(g2s.c_str());
    return g1-g2;
}

int main() {
    int n,k; cin >> n >> k;
    for(int i=0;i<k;++i) n=f(n);
    cout << n << endl;
    return 0;
}