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
    vector <pair<int,string> > v;
    map<string, int> m;
    for (int i = 0; i < N; ++i) {
        string x;
        cin >> x;
        m[x]++;
    }

    for (auto d:m) v.push_back(pair<int, string>(d.second, d.first));
    sort(v.begin(),v.end());

    int max = v[v.size() - 1].first;
    vector<string> d;
    for (int i = v.size() - 1; i >= 0;--i) {
        if(max == v[i].first) {
            d.push_back(v[i].second);
        }
    }

    sort(d.begin(), d.end());

    for (auto s:d) cout << s << endl; 
    return 0;
}