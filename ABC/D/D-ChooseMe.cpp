#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;

bool comparison(const pair<long long, long long>& node1, const pair<long long, long long>& node2)
{
    long long x = node1.first + node1.first + node1.second;
    long long y = node2.first + node2.first + node2.second;

    if (x > y) return true;

    return false;
}
int main() {
    int N;
    cin >> N;
      // 追加２, 以降 cin の入力元が 'input.txt' になる
    // std::ifstream in("test.text");
    // std::cin.rdbuf(in.rdbuf());
    vector <pair<long long, long long> > p(N,pair<long long, long long>(0,0));
    long long aSum = 0;
    long long bSum = 0;
    for (int i = 0; i < N; ++i) {
        long long a,b;
        cin >> a >> b;
        aSum += a;
        p[i] = pair<long long, long long> (a,b);
    }

    sort(p.begin(), p.end(), comparison);

    for (int i = 0; i < N; ++i) {
        aSum -= p[i].first;
        bSum += p[i].first + p[i].second;
        if (aSum < bSum) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    
    return 0;
}