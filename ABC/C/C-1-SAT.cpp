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
    map <string,int> m;
    vector <string> v(N,"0");
    for (int i = 0; i < N; ++i) cin >> v[i];

    for (int i = 0; i < N; ++i) {
        string s = v[i];
        string c;
        m[s] = 1;
        if (s[0] == '!') {
            c = s.erase(0,1);
        } else {
            c = "!" + s;
        }
        if (m[v[i]] == 1 && m[c] == 1) {
            cout << s << endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;
    return 0;
}