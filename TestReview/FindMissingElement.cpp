// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.size() == 0) return 1;
    if(A.size() == 1) if (A[0] == 1) return 2; else return 1;
    sort(A.begin(), A.end());
    for (int i = 1; i < (int)A.size(); ++i) {
        if (A[i-1] + 1 != A[i]) return A[i-1] + 1;
    }

    if ((int)A[0]==1) {
        return A.size() + 1;
    } else return 1;
}

vector<int> createArrayWithMissing(int size) {
    vector<int> m;
    random_device rnd;
    int missingNum = rnd() % size + 1; 
    cout << missingNum << endl;
    for (int i = 1; i < size; ++i) {
        if (i == missingNum) continue;
        m.push_back(i);
    }
    return m;
}

int main() {
    vector<int> v = createArrayWithMissing(100000);
    cout << solution(v) << endl;
}