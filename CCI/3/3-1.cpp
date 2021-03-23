#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

/**
 * １つの配列を使って三つのスタックを作る
 * - 基本的には一配列を三つに分割する考え方で良いと思う
 * - あとは追加、削除、取り出しなどをちゃんとできるのか、ということ
 * - その情報を持ってあげる必要があるだろう
 *  - stackNodeクラスに自分が底か、またその何番目のスタックかを保持しておく
 * - 二次元配列を使えばもっと簡単だ
 *  - [0],[1],[2]でアクセスする
 *  - それを連結リストで表現する
 */
class StackNode {
    int data;
    StackNode *next;

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