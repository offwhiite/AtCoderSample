#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
#include <stack>
using namespace std;

/**
 * スタックでキュー
 * 考えたこと
 * - 基本的にはpopのタイミングで片方のStackに移し替えてpopすれば良さそう
 * - 以降はpopのタイミングでpopStackにitemが残っていればそこから、なければstackStackからpopStackに移し替えれば良さそう
 * @return int 
 */
class MyQueue {
    private:
        stack<int> sStack;
        stack<int> popStack;
        void makePopStack() {
            for (int i = 0; i < sStack.size; ++i) {
                popStack.push_back(sStack.pop_back());
            }
        }
    public:
        int pop() {
            if (popStack.size == 0) {
                makePopStack();
            }
            return popStack.pop_back();
        }
        
        void push(int item) {
            sStack.push_back(item);
        }
};
 
int main() {
    cout  << fixed << setprecision(10);
    

    return 0;
}