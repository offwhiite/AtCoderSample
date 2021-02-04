#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<string,int> m;
    long long count = 0;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        m[s]++;
        count += m[s] - 1;
    }

    cout << count << endl;
    return 0;
}