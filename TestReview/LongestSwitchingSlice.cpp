#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

class Solution {
    public:
        int solution(int A[], int N) {
            if (N == 1) return 1;
            int sliseSize = 2;
            int nEven = A[0];
            int nOdd = A[1];
            int ans = 0;
            for (int i = 2;i < N; ++i) {
                if(i % 2 == 0) {
                    if(A[i] == nEven) sliseSize++;
                    else {
                        ans = max(ans, sliseSize);
                        nEven = A[i]; 
                        sliseSize = 2;
                    }
                } else {
                    if (A[i] == nOdd) sliseSize++;
                    else {
                        nOdd = A[i];
                        sliseSize = 2;
                    }
                }
                ans = max(ans, sliseSize);
            }
            return ans;
        }
};

int main() {
    // int list[] = {3,2,3,2,3};
    // int list[] = {7,4,-2,4,-2,9};
    // int list[] = {7,-5,-5,-5,7.-1,7};
    int list[] = {1};
    Solution s = Solution();
    cout << s.solution(list, 1) << endl;
    return 0;
}