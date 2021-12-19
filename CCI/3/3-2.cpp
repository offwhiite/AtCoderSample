#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

/**
 * １つの配列を使って三つのスタックを作る
 * - minを常に持っておくのが良さそう。
 * - 今一番小さい値を持つNodeを保持しておき、それを返せばO(1)で実施できそう
 * - ただし、その場合普通にStackしている情報を削除しないといけないので、双方向リストにしたい
 */
class StackNode {
    int data;
    StackNode *next;
    StackNode *back;

    void push(int nodeData) {
        int tmp = data;
        StackNode tmpNode = *next;

        StackNode newNode;
        newNode.data = data;
        newNode.next = next;
        data = nodeData;
        next = &newNode;
    }

    int pop() {
        int tmp = data;
        data = next->data;
        next = next->next;
        return tmp;
    }
};
int main() {
    int N;
    cin >> N;
    vector <int> v(N,0);
    for (int i = 0; i < N; ++i) cin >> v[i];
    
    cout  << fixed << setprecision(10);
    return 0;
}