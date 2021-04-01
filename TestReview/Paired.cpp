// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    int sameCount = 0;
    int sameNum = 0;
    for (int a: A) {
        if (sameNum != a) {
            if (sameCount % 2 != 0) return sameNum;
            sameNum = a;
            sameCount = 0;
        }

        sameCount++;
    }

    // ここで終わったということは最後の一つだけ余ってしまったということなので、sameを返す
    return sameNum;
}
