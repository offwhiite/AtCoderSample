#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector <vector <int> > v(N, vector<int>(2,0));
    for (int i = 0; i < N; ++i) cin >> v[i][0] >> v[i][1];
    
    for (int i = 0; i < N - 2; ++i) {
        for (int j = i + 1; j < N - 1; ++j) {
            for (int k = j + 1; k < N; ++k) {
                int x1 = v[i][0] ;
                int y1 = v[i][1] ;

                int x2 = v[j][0] - x1;
                int y2 = v[j][1] - y1;

                int x3 = v[k][0] - x1;
                int y3 = v[k][1] - y1;

                if (y2 * x3 == y3 * x2) {
                    cout << "Yes" << endl;
                    return 0;
                }

            }
        }
    }
    cout  << "No" << endl;
    return 0;
}