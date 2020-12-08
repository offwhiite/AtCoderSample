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
    map <string, int> m;
    int ans = 0;
    for (int i = 0; i < N; ++i)  {
        string tmp;
        cin >> tmp;
        if (m.find(tmp) == m.end()) ans++;
        m[tmp]++;
    }
    
    cout << ans << endl;
    return 0;
}