// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
using namespace std;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    if (K == 0) return A;
    vector<int> v(A.size(), 0);
    for (int i = 0; i < (int)A.size(); ++i) {
        int shiftNum = i + (K % A.size());
        while (shiftNum >= (int)A.size()) shiftNum -= A.size();
        v[shiftNum] = A[i];
    }

    return v;
}