#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
  int N;
  long K;
  cin >> N;
  cin >> K;

  vector<vector<long> > t(N,vector<long>(N,0));
  
  for(int i = 0;i < N; ++i) {
      for (int j = 0;j < N; ++j) {
          cin >> t[i][j];
      }
  }

  vector<int> city(N-1,0);
  for (int i=0; i < N-1;++i) city[i] = i+1;

  long long ans = 0;
  do {
      vector<int> cityTmp(N+1,0);
      copy(city.begin(), city.end(), cityTmp.begin()+1);
      cityTmp[0] = 0;
      cityTmp[N] = 0;

      long long tmp = 0;
      for (int i = 0;i < N; ++i) {
          tmp += t[cityTmp[i]][cityTmp[i+1]];
      }

      if (tmp == K) ans++;
  } while(next_permutation(city.begin(), city.end()));

  cout << ans << endl;
  return 0;
}