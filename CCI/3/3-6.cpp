#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
#include <stack>
using namespace std;

/**
 * 動物保護施設
 * 考えたこと
 * - 普通に連結リストで繋いでいけば良さそう。
 * - dequeueAny
 * @return int 
 */
class SortQueue {
    private:
        stack<int> keepStack;
        stack<int> tmpStack;
    public:
        int pop() {

        }
        
        void push(int item) {
            if (keepStack.top() > item) {
            　  while(keepStack.size != 0) {
            　      keepStack
            　  }
            } else {
                keepStack.push_back(item);
            }
        }
};
 
int main() {
    cout  << fixed << setprecision(10);
    

    return 0;
}