#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;


int main() {
    long long N;
    cin >> N;
    long long max = N;
    long long sN = sqrt(N);
    int count = 0;
    if (N==1) {
        cout << count << endl;
        return 0;
    }

    map<int, int> m;
    long long tmp = N;
    for (int i = 2; i <= sN; ++i) {
        while(tmp%i==0) {
            tmp/=i;
            m[i]++;
        }
    }

    if (tmp != 1) m[tmp]++;

    for (auto a:m) {
        long long e = a.second;
        long long tmp = 0, cur = 1;
        while (e >= cur) e -= cur++, ++tmp;
        count += tmp;   
    }
    
    cout << count << endl;
    return 0;
}