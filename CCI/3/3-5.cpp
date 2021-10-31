#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
#include <stack>
using namespace std;

/**
 * スタックのソート
 * 考えたこと
 * - 毎回比較して、自分より小さいものがスタックされていればpopし続ける作戦をすれば良さそう
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