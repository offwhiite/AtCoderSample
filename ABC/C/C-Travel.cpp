#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    long long N, K;
    cin >> N >> K; // 街の数

    // 町iとそこからjに行くまでにかかる移動時間
    vector<vector<long long> > points(N, vector<long long>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> points[i][j];
        }
    }
    
    vector<int> towns(N-1, 0);
    for (int i = 0; i < N-1; ++i) towns[i] = i + 2;

    int count = 0;
    do {
        vector<int> newTowns(N-1, 0);
        copy(towns.begin(), towns.end(), newTowns.begin());

        newTowns.insert(newTowns.begin(), 1);
        newTowns.insert(newTowns.end(), 1);
 
        long long sum = 0;
        for (int i = 0; i  < newTowns.size()-1; ++i) {
            sum += points[newTowns[i]-1][newTowns[i+1]-1];
        }
        if (sum == K) {
            count++;
        }
    } while (next_permutation(towns.begin(), towns.end()));

    cout << count << endl;
    return 0;
} 
