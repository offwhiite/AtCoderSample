#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

vector<vector<long long> > fact(int n, int r) {
  vector<vector<long long> > v(n + 1,vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}

int main() {
    long long L;
    cin >> L;
    const int tw = 12;
    long long r = L - tw;
    cout << fact(tw + r - 1, r)[tw+r-1][r] << endl;
    return 0;
}